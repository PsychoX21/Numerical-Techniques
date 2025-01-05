#include <iostream>
#include <fstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>

using namespace std;

void rho_default(vector<vector<double>> &rho, int n);
void rho_radial(vector<vector<double>> &rho, int n);
void rho_gaussian(vector<vector<double>> &rho, int n);
void rho_sinusoidal(vector<vector<double>> &rho, int n);
void rho_chess(vector<vector<double>> &rho, int n);
void rho_spiral(vector<vector<double>> &rho, int n);
void rho_starburst(vector<vector<double>> &rho, int n);

void flatten(const vector<vector<double>> &grid, vector<double> &flat);
void gridden(const vector<double> &flat, vector<vector<double>> &grid, int n);

void exportgrid(const vector<vector<double>> &grid, const string &filename);

vector<vector<double>> laplace(int n);

void gauss_seidel(const vector<vector<double>> &A, const vector<double> &b, vector<double> &x, int iterations, double tolerance);

int main()
{
    int n = 101;
    vector<vector<double>> U(n, vector<double>(n, 0.0));
    vector<vector<vector<double>>> rhos(7, vector<vector<double>>(n, vector<double>(n, 0.0)));

    rho_default(rhos[0], n);
    rho_radial(rhos[1], n);
    rho_gaussian(rhos[2], n);
    rho_sinusoidal(rhos[3], n);
    rho_chess(rhos[4], n);
    rho_spiral(rhos[5], n);
    rho_starburst(rhos[6], n);

    vector<vector<double>> L = laplace(n);

    for (int i = 4; i < 7; ++i)
    {
        vector<double> rho_flat(n * n, 0.0);
        vector<double> U_flat(n * n, 0.0);

        flatten(rhos[i], rho_flat);

        gauss_seidel(L, rho_flat, U_flat, 10000, 1e-6);
        gridden(U_flat, U, n);

        exportgrid(U, "poisson" + to_string(i) + ".txt");
    }
}

// Functions

vector<vector<double>> laplace(int n)
{
    vector<vector<double>> A(n * n, vector<double>(n * n, 0.0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int k = i * n + j;
            A[k][k] = -4.0;

            if (i > 0)
                A[k][k - n] = 1.0;
            if (i < n - 1)
                A[k][k + n] = 1.0;
            if (j > 0)
                A[k][k - 1] = 1.0;
            if (j < n - 1)
                A[k][k + 1] = 1.0;
        }
    }
    return A;
}

void gauss_seidel(const vector<vector<double>> &A, const vector<double> &b, vector<double> &x, int iterations, double tolerance)
{
    int m = x.size();
    vector<double> oldx{x};

    cout << fixed << setprecision(8);

    for (int iteration{1}; iteration <= iterations; iteration++)
    {
        for (int i{0}; i < m; i++)
        {
            double sum{0};
            for (int j{0}; j < m; j++)
            {
                if (j != i)
                    sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        if (iteration % 10 == 0)
        {
            double diff = 0.0;
            for (int i = 0; i < m; i++)
            {
                diff += (x[i] - oldx[i]) * (x[i] - oldx[i]);
            }

            if (diff < tolerance * tolerance)
            {
                cout << "\nConverged in " << iteration << " iterations." << endl;
                cout << "Error: " << sqrt(diff) << endl;
                return;
            }

            if (iteration % 100 == 0)
            {
                cout << "Iteration " << iteration << " : " << sqrt(diff) << endl;
            }
        }

        oldx = x;
    }
}

void rho_default(vector<vector<double>> &rho, int n)
{
    rho[n / 2 + 10][n / 2] = 1.0;
    rho[n / 2 - 10][n / 2] = -1.0;

    for (int j = 0; j < n; ++j)
    {
        rho[0][j] = 1.0;
        rho[n - 1][j] = -1.0;
    }
}

void rho_radial(vector<vector<double>> &rho, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rho[i][j] = sqrt((i - n / 2) * (i - n / 2) + (j - n / 2) * (j - n / 2));
        }
    }
}

void rho_gaussian(vector<vector<double>> &rho, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rho[i][j] = exp(-(i - n / 2) * (i - n / 2) - (j - n / 2) * (j - n / 2));
        }
    }
}

void rho_sinusoidal(vector<vector<double>> &rho, int n)
{
    double amplitude = 10.0;
    double frequency = 0.25;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rho[i][j] = amplitude * sin(frequency * i) * cos(frequency * j);
        }
    }
}

void rho_chess(vector<vector<double>> &rho, int n)
{
    int square_size = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int block_row = i / square_size;
            int block_col = j / square_size;
            rho[i][j] = ((block_row + block_col) % 2 == 0) ? 1000.0 : -1000.0;
        }
    }
}

void rho_spiral(vector<vector<double>> &rho, int n)
{
    int center = n / 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double dx = i - center;
            double dy = j - center;
            double r = sqrt(dx * dx + dy * dy);
            double theta = atan2(dy, dx);
            if (fmod(theta + 0.1 * r, 2 * M_PI) < M_PI)
            {
                rho[i][j] = 10.0;
            }
            else
            {
                rho[i][j] = -10.0;
            }
        }
    }
}

void rho_starburst(vector<vector<double>> &rho, int n)
{
    int center = n / 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double angle = atan2(j - center, i - center);
            int spoke_index = int(8 * angle / (2 * M_PI)) % 8;
            rho[i][j] = (spoke_index % 2 == 0) ? 10.0 : -10.0;
        }
    }
}

void flatten(const vector<vector<double>> &grid, vector<double> &flat)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            flat[i * grid[0].size() + j] = grid[i][j];
        }
    }
}

void gridden(const vector<double> &flat, vector<vector<double>> &grid, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            grid[i][j] = flat[i * n + j];
        }
    }
}

void exportgrid(const vector<vector<double>> &grid, const string &filename)
{
    ofstream file(filename);
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            file << grid[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}
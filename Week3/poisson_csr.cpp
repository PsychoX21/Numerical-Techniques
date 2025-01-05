#include <iostream>
#include <fstream>
#include <iomanip>

#include "initializors.h"

using namespace std;

class CSRMatrix
{
public:
    vector<double> values; // Non-zero values
    vector<int> columns;   // Column indices of the non-zero values
    vector<int> row_ptr;   // Index of row is the row number and value is the index of the first non-zero element

    CSRMatrix(int n)
    {
        row_ptr.resize(n + 1, 0);
    }

    void add_entry(int row, int col, double value)
    {
        values.push_back(value);
        columns.push_back(col);
        for (int i = row + 1; i < row_ptr.size(); i++)
        {
            row_ptr[i]++;
        }
    }
};

CSRMatrix laplace_csr(int n)
{
    CSRMatrix A(n * n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int idx = i * n + j;
            A.add_entry(idx, idx, -4.0); // Note that first the diagonal element is added here

            if (i > 0)
                A.add_entry(idx, idx - n, 1.0);
            if (i < n - 1)
                A.add_entry(idx, idx + n, 1.0);
            if (j > 0)
                A.add_entry(idx, idx - 1, 1.0);
            if (j < n - 1)
                A.add_entry(idx, idx + 1, 1.0);
        }
    }

    return A;
}

void gauss_seidel_csr(const CSRMatrix &A, const vector<double> &b, vector<double> &x, int iterations, double tolerance)
{
    int m = x.size();
    vector<double> oldx(x);

    cout << fixed << setprecision(8);

    for (int iteration = 1; iteration <= iterations; iteration++)
    {
        for (int i = 0; i < m; i++)
        {
            double sum = 0;
            int start_idx = A.row_ptr[i];
            int end_idx = A.row_ptr[i + 1];

            for (int k = start_idx; k < end_idx; k++)
            {
                int j = A.columns[k];
                if (j != i)
                {
                    sum += A.values[k] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A.values[start_idx];
        }

        if (iteration % 100 == 0)
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

            if (iteration % 1000 == 0)
            {
                cout << "Iteration " << iteration << " : " << sqrt(diff) << endl;
            }
        }

        oldx = x;
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


int main()
{
    int n = 201;
    vector<vector<double>> U(n, vector<double>(n, 0.0));
    vector<vector<vector<double>>> rhos(7, vector<vector<double>>(n, vector<double>(n, 0.0)));

    rho_default(rhos[0], n);
    rho_gaussian(rhos[1], n);
    rho_chess(rhos[2], n);
    rho_spiral(rhos[3], n);
    rho_magnetic_dipole(rhos[4], n);
    rho_vortex(rhos[5], n);
    rho_sinusoidal_ripple(rhos[6], n);

    CSRMatrix L = laplace_csr(n);

    for (int i = 0; i < 7; ++i)
    {
        vector<double> rho_flat(n * n, 0.0);
        vector<double> U_flat(n * n, 0.0);

        flatten(rhos[i], rho_flat);

        gauss_seidel_csr(L, rho_flat, U_flat, 100000, 1e-6);
        gridden(U_flat, U, n);

        exportgrid(U, "poisson" + to_string(i) + ".txt");
    }
}
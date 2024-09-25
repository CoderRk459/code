#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n;

void swap_rows(int row1, int row2)
{
    for (int k = 1; k <= n + 1; k++)
    {
        swap(a[row1][k], a[row2][k]);
    }
}

void gauss_elimination()
{
    for (int j = 1; j < n; j++)
    {
        // Check if pivot is zero
        if (a[j][j] == 0)
        {
            // Find a row below the current one with a non-zero pivot
            for (int i = j + 1; i <= n; i++)
            {
                if (a[i][j] != 0)
                {
                    swap_rows(j, i);
                    break;
                }
            }
        }
        // Continue with the elimination process
        for (int i = n; i > j; i--)
        {
            if (a[i][j] == 0)
                continue;
            int lcm = a[j][j] * a[i][j] / __gcd(a[j][j], a[i][j]);
            int up = lcm / a[j][j], nic = lcm / a[i][j];
            for (int k = 1; k <= n + 1; k++)
                a[i][k] = up * a[j][k] - nic * a[i][k];
        }
    }
}

void Jordan_elimination()
{
    for (int j = n; j > 1; j--)
    {
        for (int i = 1; i < j; i++)
        {
            if (a[i][j] == 0)
            {
                continue;
            }
            int lcm = a[j][j] * a[i][j] / __gcd(a[j][j], a[i][j]);
            int nic = lcm / a[j][j], up = lcm / a[i][j];
            for (int k = 1; k <= n + 1; k++)
            {
                a[i][k] = nic * a[j][k] - up * a[i][k];
            }
        }
    }
}

void row_echelon()
{
    for (int i = 1; i <= n; i++)
    {
        a[i][n + 1] /= a[i][i];
        a[i][i] = 1;
    }
}

int main()
{
    n = 4;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];

    gauss_elimination();
    Jordan_elimination();
    row_echelon();

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

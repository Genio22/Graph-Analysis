/* comment */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n_ar[] = {
        1000,
        2000,
        3000,
        4000,
        5000,
    };

    srand(time(0)); // random every time

    int size = sizeof(n_ar) / sizeof(n_ar[0]);

    for (int i = 0; i < size; i++)
    {

        int n = n_ar[i]; // Current value of n (e.g., 1000, 2000, etc.)
        //int matrix[n][n];
        int edge_count = 0, edge;
        int degree[n];
        for (int i = 0; i < n; i++)
        {
            degree[i] = 0;
        }

        // Start measuring time
        clock_t start_time = clock();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++) // upper triangle only count kortechi for edge
            {
                edge = rand()%2;
                if (edge)
                {
                    edge_count++;
                    degree[i]++; // ami i direct accsess korte parte che so para nai
                    degree[j]++;
                }
            }
        }

        int sum_degree = 0;
        for (int i = 0; i < n; i++)
        {
            sum_degree += degree[i];
        }

        // End measuring time
        clock_t end_time = clock();
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; // Time in milliseconds

        // Print results
        printf("n = %d:\n", n);
        printf("  Number of edges = %d\n", edge_count);
        printf("  Sum of degrees = %d\n", sum_degree);
        printf("  Handshaking lemma holds: %s\n", (sum_degree == 2 * edge_count) ? "Yes" : "No");
        printf("  Time taken = %.2f ms\n\n", time_taken);

        // print matrix
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         printf("%d ", matrix[i][j]);
        //     }
        //     printf("\n");
        // }

        // print degree
        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d ", degree[j]);
        // }

        // Genarate matrix value and assign it
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == j)
        //         {
        //             matrix[i][j] = 0; // self lopping bade
        //         }
        //         else
        //         {
        //             matrix[i][j] = matrix[j][i] = rand() % 2; // 0 holo edge nai , 1 hoile ache
        //         }
        //     }
        // }
    }

    return 0;
}




// By Team Scorpion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_logo() {
    printf(" _____                       __                      _             \n");
    printf("/__   \\___  __ _ _ __ ___   / _\\ ___ ___  _ __ _ __ (_) ___  _ __  \n");
    printf("  / /\\/ _ \\/ _` | '_ ` _ \\  \\ \\ / __/ _ \\| '__| '_ \\| |/ _ \\| '_ \\ \n");
    printf(" / / |  __/ (_| | | | | | | _\\ \\ (_| (_) | |  | |_) | | (_) | | | |\n");
    printf(" \\/   \\___|\\__,_|_| |_| |_| \\__/\\___\\___/|_|  | .__/|_|\\___/|_| |_|\n");
    printf("                                              |_|                 \n");
}

void print_details() {
    printf("\nPresented by:                       |    Presented to:\n");
    printf("Group 4                             |                      \n");
    printf("Tuhin - (2024-3-60-441)             |    Dr. Mohammad Salah Uddin\n");
    printf("Sakib - (2024-3-60-442)             |    Associate Professor\n");
    printf("Al Amin - (2024-3-60-448)           |    Department of Computer Science & Engineering\n");
    printf("Ahnaf - (2024-3-60-449)             |    East West University\n\n");


    printf("                   ***********************************\n");
    printf("                   *                                 *\n");
    printf("                   *  Undirected Graph Analysis      *\n");
    printf("                   *                                 *\n");
    printf("                   ***********************************\n\n");
}


int main()
{

    print_logo();
    print_details();
    srand(time(0)); // random every time



    for (int i = 0; i != -1; i++)
    {

        int n;
        printf("Enter the vertex number: ");
        scanf("%d", &n);
        long edge_count = 0, edge, sum_degree = 0;
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
                edge = rand() % 2;
                if (edge)
                {
                    edge_count++;
                    degree[i]++; // ami i direct accsess korte parte che so para nai
                    degree[j]++;
                }
            }
        }

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
        printf("  Handshaking theorem : %s\n", (sum_degree == 2 * edge_count) ? "Yes" : "No");
        printf("  Time taken = %.2f ms\n\n", time_taken);



        // Genarate matrix value and assign it
        //int matrix[n][n];
        //for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == j)
        //         {
        //             matrix[i][j] = 0; // self lopping bade
        //         }
        //        else
        //         {
        //             matrix[i][j] = matrix[j][i] = rand() % 2; // 0 holo edge nai , 1 hoile ache
        //       }
        //     }
        // }

        // for (int i = 0; i < n; i++)
        //{
        //   for (int j = 0; j < n; j++)
        //   {
        //        printf("%d ", matrix[i][j]);
        //    }
        //    printf("\n");
        // }

        // print degree
        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d ", degree[j]);
        // }


        printf("Do you want to exit.(Yes -> 1| No -> 0) ");
        scanf("%d", &i);
        getchar();
        if (i)
            break;
    }

    return 0;
}

// By Team Scorpion

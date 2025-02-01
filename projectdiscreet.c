#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_logo()
{
    printf(" _____                       __                      _             \n");
    printf("/__   \\___  __ _ _ __ ___   / _\\ ___ ___  _ __ _ __ (_) ___  _ __  \n");
    printf("  / /\\/ _ \\/ _` | '_ ` _ \\  \\ \\ / __/ _ \\| '__| '_ \\| |/ _ \\| '_ \\ \n");
    printf(" / / |  __/ (_| | | | | | | _\\ \\ (_| (_) | |  | |_) | | (_) | | | |\n");
    printf(" \\/   \\___|\\__,_|_| |_| |_| \\__/\\___\\___/|_|  | .__/|_|\\___/|_| |_|\n");
    printf("                                              |_|                 \n");
}

void print_details()
{
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
    srand(time(0)); // Random seed for different outputs

    while (1)
    {
        int n;
        printf("Enter the vertex number: ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("Invalid input! Number of vertices should be positive.\n");
            continue;
        }

        long edge_count = 0, sum_degree = 0;
        int *degree = (int *)calloc(n, sizeof(int)); // Allocate memory for degree array

        // Dynamically allocate adjacency matrix
        int **matrix = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
            matrix[i] = (int *)malloc(n * sizeof(int));

        clock_t start_time = clock();

        // Generate adjacency matrix (upper triangle only)
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 0; // No self-loops
                }
                else
                {
                    matrix[i][j] = matrix[j][i] = rand() % 2; // Random edges
                }
            }
        }

        // Print adjacency matrix if small
        if (n < 100)
        {
            printf("\nAdjacency Matrix:\n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("\nMatrix is too large to print.\n");
        }

        // Count edges and degree of each vertex
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++) // Count only upper triangle
            {
                if (matrix[i][j] == 1)
                {
                    edge_count++;
                    degree[i]++;
                    degree[j]++;
                }
            }
        }

        // Calculate sum of degrees
        for (int i = 0; i < n; i++)
            sum_degree += degree[i];

        clock_t end_time = clock();
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; // Time in milliseconds

        // Print results
        printf("\nn = %d:\n", n);
        printf("  Number of edges = %ld\n", edge_count);
        printf("  Sum of degrees = %ld\n", sum_degree);
        printf("  Handshaking theorem : %s\n", (sum_degree == 2 * edge_count) ? "Yes" : "No");
        printf("  Time taken = %.2f ms\n\n", time_taken);

        // Free dynamically allocated memory
        for (int i = 0; i < n; i++)
            free(matrix[i]);
        free(matrix);
        free(degree);

        // Exit or continue
        int exit_choice;
        printf("Do you want to exit? (Yes -> 1 | No -> 0): ");
        scanf("%d", &exit_choice);
        getchar();
        if (exit_choice)
            break;
    }

    return 0;
}

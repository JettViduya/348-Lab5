/*Author: Jett Viduya
  KUID: 3115988
  Date: 10/11/24
  Lab: 5
  Purpose: Given 12 monthly sales figures in an input file, generate monthly sales report, sales summary report, six-month moving average report, sales report(highest to lowest)*/
#include <stdio.h>
#include <string.h>

#define MONTHS 12

// Function prototypes
void monthly_sales_report(const float sales[], const char months[][10]);
void sales_summary_report(const float sales[], const char months[][10]);
void six_month_moving_average(const float sales[]);
void sales_report_highest_to_lowest(float sales[], const char months[][10]);

int main() {
    float sales[MONTHS];
    char months[MONTHS][10] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    // Input sales data from a file
    FILE *file = fopen("sales.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }

    fclose(file);

    // Generate the reports
    printf("Monthly Sales Report for 2024\n");
    monthly_sales_report(sales, months);

    printf("\nSales Summary Report:\n");
    sales_summary_report(sales, months);

    printf("\nSix-Month Moving Average Report:\n");
    six_month_moving_average(sales);

    printf("\nSales Report (Highest to Lowest):\n");
    sales_report_highest_to_lowest(sales, months);

    return 0;
}

// Display month and corresponding sales
void monthly_sales_report(const float sales[], const char months[][10]) {
    printf("Month        Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s  $%.2f\n", months[i], sales[i]);
    }
}

// Show minimum, maximum, and average sales
void sales_summary_report(const float sales[], const char months[][10]) {
    float min_sales = sales[0], max_sales = sales[0], total_sales = 0.0;
    int min_index = 0, max_index = 0;

    // Loop through sales to find min, max, and calculate total
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_index = i;
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_index = i;
        }
        total_sales += sales[i];
    }

    float avg_sales = total_sales / MONTHS;

    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[min_index]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[max_index]);
    printf("Average sales: $%.2f\n", avg_sales);
}

// Calculate and display six-month moving average
void six_month_moving_average(const float sales[]) {
    for (int i = 0; i <= MONTHS - 6; i++) {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float avg = sum / 6;
        printf("%s-%s  $%.2f\n", i == 0 ? "January" : i == 1 ? "February" : 
               i == 2 ? "March" : i == 3 ? "April" : i == 4 ? "May" : "June", 
               i == 0 ? "June" : i == 1 ? "July" : 
               i == 2 ? "August" : i == 3 ? "September" : i == 4 ? "October" : "December", avg);
    }
}

// Sort sales in descending order and display with corresponding months
void sales_report_highest_to_lowest(float sales[], const char months[][10]) {
    // Copy sales and months arrays for sorting
    float sorted_sales[MONTHS];
    char sorted_months[MONTHS][10];

    for (int i = 0; i < MONTHS; i++) {
        sorted_sales[i] = sales[i];
        strcpy(sorted_months[i], months[i]);
    }

    // Sort the sales in descending order using bubble sort
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - 1 - i; j++) {
            if (sorted_sales[j] < sorted_sales[j + 1]) {
                // Swap sales values
                float temp_sales = sorted_sales[j];
                sorted_sales[j] = sorted_sales[j + 1];
                sorted_sales[j + 1] = temp_sales;

                // Swap corresponding months
                char temp_month[10];
                strcpy(temp_month, sorted_months[j]);
                strcpy(sorted_months[j], sorted_months[j + 1]);
                strcpy(sorted_months[j + 1], temp_month);
            }
        }
    }

    // Display sorted sales with corresponding months
    printf("Month        Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s  $%.2f\n", sorted_months[i], sorted_sales[i]);
    }
}

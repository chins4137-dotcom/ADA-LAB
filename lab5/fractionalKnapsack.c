#include <stdio.h>

// Structure for an item
struct Item {
    int profit;
    int weight;
    float ratio;
};

// Function to sort items by ratio (descending)
void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalProfit = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].profit * ((float)capacity / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input profits and weights
    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].profit,&items[i].weight);

        // Calculate ratio
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items
    sortItems(items, n);

    // Apply greedy method
    float maxProfit = fractionalKnapsack(items, n, capacity);

    // Output result
    printf("\nMaximum Profit = %.2f\n", maxProfit);

    return 0;
}

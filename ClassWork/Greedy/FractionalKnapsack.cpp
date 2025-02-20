#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int weight;
    int profit;
} Item;

int cmp (const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double r1 = (double)itemA->profit / itemA->weight;
    double r2 = (double)itemB->profit / itemB->weight;
    if (r1 > r2) return -1;
    else if (r1 < r2) return 1;
    else return 0;
}

double fractionalKnapsack(Item items[], int n, int W) {
    
    qsort(items, n, sizeof(Item), cmp);
    double ans = 0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            ans += items[i].profit;
            W -= items[i].weight;
        } else {
            ans += (items[i].profit*1.0 / items[i].weight*1.0) * W;
            break;
        }
    }

    return ans;
}

int main () {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;

    printf("Maximum profit: %lf\n", fractionalKnapsack(items, n, W));

    return 0;
}
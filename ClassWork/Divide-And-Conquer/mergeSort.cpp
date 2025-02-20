#include <iostream>
using namespace std;
int Count = 0;

void merge(int a[], int n1, int b[], int n2, int v[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            v[k++] = a[i++];
        else
            v[k++] = b[j++];
    }

    while (i < n1)
        v[k++] = a[i++];

    while (j < n2)
        v[k++] = b[j++];
}

void mergeSort(int v[], int n) {
    if (n == 1) return;

    else {
        Count += 2;

        int n1 = n / 2, n2 = n - n1;
        int a[n1], b[n2];

        for (int i = 0; i < n1; i++)
            a[i] = v[i];
        for (int i = 0; i < n2; i++)
            b[i] = v[i + n1];

        mergeSort(a, n1);
        mergeSort(b, n2);

        merge(a, n1, b, n2, v);
    }
}

int main() {
    int v[] = {5, 2, 9, 1, 5, 6, 7, 8};
    int n = sizeof(v) / sizeof(v[0]);

    mergeSort(v, n);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    cout<<"Count: "<<Count<<endl;
    return 0;
}

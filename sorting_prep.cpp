#include "iostream"
using namespace std;
// buuble , quick , insertion , merge ,selection ,

void merge(int *a, int f, int mid, int l)
{

    int i = f, j = mid + 1, c[10], k = 0;
    while (i <= mid && j <= l)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k++] = a[i++];
    }
    while (j <= l)
    {
        c[k++] = a[j++];
    }
    for (i = f, j = 0; j < k; i++, j++)
    {
        a[i] = c[j];
    }
}
void merge_sort(int *a, int f, int l)
{
    int mid;
    if (f < l)
    {
        mid = (f + l) / 2;
        merge_sort(a, f, mid);
        merge_sort(a, mid + 1, l);
        merge(a, f, mid, l);
    }
}

void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int prev = i - 1;
        while (prev >= 0 && a[prev] > current)
        {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = current;
    }
}
void selection_sort(int *a, int n)
{
    for (int pos = 0; pos < n - 1; pos++)
    {
        int current = a[pos];
        int min_pos = pos;
        for (int j = pos; j < n; j++)
        {
            if (a[j] < a[min_pos])
                min_pos = j;
        }
        swap(a[min_pos], a[pos]);
    }
}

int main()
{
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int b[10] = {0, 2, 77, 8, 1, 2, 1, 0, 99, 2};
    // bubble_sort(a, 10);
    // quick_sort(a, 0, 9);
    // insertion_sort(a, 10);
    selection_sort(a, 10);
    // merge_sort(a, 0, 9);
    for (int x : a)
    {
        cout << " " << x;
    }
    cout << endl;
    // insertion_sort(b, 10);
    selection_sort(b, 10);
    // merge_sort(b, 0, 9);
    // quick_sort(b, 0, 9);
    for (int x : b)
    {
        cout << " " << x;
    }
    cout << endl;
    return 0;
}

// void bubble_sort(int *a, int n)
// {

//     bool swap1;
//     for (int i = 0; i < n - 1; i++)
//     {
//         swap1 = false;
//         for (int j = 0; j < n - 1; j++)
//         {
//             if (a[j + 1] < a[j])
//             {
//                 swap(a[j + 1], a[j]);
//                 swap1 = true;
//             }
//         }
//         if (!swap1)
//         {
//             break;
//         }
//     }
// }

int partiton(int *a, int x, int y)
{
    int start = x;
    int end = y;
    int pivot = a[x];
    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
            swap(a[start], a[end]);
    }
    swap(a[x], a[end]);

    return end;
}

void quick_sort(int *a, int lb, int ub)
{
    if (lb < ub)
    {
        int k = partiton(a, lb, ub);
        quick_sort(a, lb, k - 1);
        quick_sort(a, k + 1, ub);
    }
}

// void merge(int *a, int f, int mid, int l)
// {
//     int i, j, k = 0;
//     int c[10];
//     i = f, j = mid + 1;
//     while (i <= mid && j <= l)
//     {
//         if (a[i] < a[j])
//         {
//             c[k] = a[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             c[k] = a[j];
//             k++;
//             j++;
//         }
//     }

//     while (i <= mid)
//     {
//         c[k] = a[i];
//         i++;
//         k++;
//     }
//     while (j <= l)
//     {
//         c[k] = a[j];
//         j++;
//         k++;
//     }

//     for (i = f, j = 0; j < k; i++, j++)
//     {
//         a[i] = c[j];
//     }
// }

// void merge_sort(int *a, int f, int l)
// {
//     int mid;
//     if (f < l)
//     {
//         mid = (f + l)/ 2;
//         merge_sort(a, f, mid);
//         merge_sort(a, mid + 1, l);
//         merge(a, f, mid, l);
//     }
// }
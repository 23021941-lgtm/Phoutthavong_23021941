// Ham phan hoach (Partition)
int partition(int arr[], int low, int high) 
{
    // Chon phan tu chot (pivot) la phan tu cuoi cung
    int pivot = arr[high];
    int i = low - 1; // Chi so cua phan tu nho hon pivot

    for (int j = low; j < high; j++) 
    {
        // Neu phan tu hien tai nho hon hoac bang pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Dua phan tu chot (pivot) ve dung vi tri
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Ham Sap xep nhanh (Quick Sort)
void quickSort(int arr[], int low, int high) 
{
    if (low < high) {
        // pi la chi so noi pivot da dung vi tri
        int pi = partition(arr, low, high);

        // Sap xep de quy 2 phan hai ben pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
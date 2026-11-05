void selectionSort(int arr[], int n)
{

for (int i = 0; i < n -1; i++){
// Danh đau ví tri min
int min index = i;

// Tim vi tri min
for (int j= i + 1; j < n; j++){

if (arr[j] < arr[min_index])
min index = j;
}
// Hoan doi vi tri min voi vi tri hien tai
if (min_index != i)
swap(arr[min_index], arr[i]);
    }
}
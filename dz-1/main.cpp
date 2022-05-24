#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <windows.h>


using namespace std;
//template <typename type_arr>
void buble_sort(int *arr, int size){
    for(int i = 1; i < size; ++i)
    {
        for(int r = 0; r < size-i; r++)
        {
            if(arr[r] < arr[r+1])
            {
                int temp = arr[r];
                arr[r] = arr[r+1];
                arr[r+1] = temp;
            }
        }
    }
}
void insert_sort(int* arr,int n){
    int counter=0;
    for(int i=1;i<n;i++){
        for(int j=i; j>0 && arr[j-1]>arr[j];j--){
            counter++;
            int tmp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=tmp;
        }
    }
}
void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }
}
void qsortRecursive(int *mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];
    do {
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {

        qsortRecursive(&mas[i], size - i);
    }
}
void merge_sort(int *a, int n)
{
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int *c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++; k++;
                }
                else {
                    c[k] = a[j];
                    j++; k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = a[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j<n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = a[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i<n; i++)
            a[i] = c[i];
    }
}
void shell_sort(int *array, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}
void GnomeSort(int* arr, int Size){
    Size++;
    int i = 0;
    while (i < Size)
    {
        if (i == 0 || arr[i - 1] <= arr[i])
            ++i;
        else
        {
            int tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            --i;
        }
    }
}
void randomFill(int* arr, int _size) {
    for (int i = 0; i < _size; i++){
        arr[i] = rand()%100;
    }
}

int main() {

    ofstream f_selectSort;
    ofstream f_bublSort;
    ofstream f_qSort;
    ofstream f_insertSort;
    ofstream f_mergeSort;
    ofstream f_shellSort;
    ofstream f_gnomeSort;

    f_selectSort.open("selectSort.txt");
    f_bublSort.open("bublSort.txt");
    f_qSort.open("qSort.txt");
    f_insertSort.open("insertSort.txt");
    f_mergeSort.open("mergeSort");
    f_shellSort.open("shellSort");
    f_gnomeSort.open("gnomeSort");
    int* my_arr;
    cout << "start" << endl;
    for (int size = 100; size < 10000;) { //сортировка выбором
        my_arr = new int [size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        selection_sort(my_arr, size);
        time = GetTickCount() - time;
        f_selectSort << size  << "\t" << time <<  "\n";
        size += 100;
    }
    f_selectSort.close();
    cout << "1 sort end" << endl;
    for (int size = 100; size < 6000;) { // сортировка пузырьком
        my_arr = new int[size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        time = GetTickCount();
        buble_sort(my_arr, size);
        time = GetTickCount() - time;
        f_bublSort << size  << "\t" << time << "\n";
        size += 100;
    }
    f_bublSort.close();
    cout << "2 sort end" << endl;

    for (int size = 100; size < 100000;) { // сортировка быстрая
        my_arr = new int[size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        time = GetTickCount();
        qsortRecursive(my_arr, size);
        time = GetTickCount() - time;
        f_qSort << size << "\t" << time << "\n";
        size += 500;
    }
    f_qSort.close();
    cout << "3 sort end" << endl;

    for (int size = 100; size < 12000;) { // сортировка вставками
        my_arr = new int[size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        time = GetTickCount();
        insert_sort(my_arr, size);
        time = GetTickCount() - time;
        f_insertSort << size << "\t" << time << "\n";
        size += 100;
    }
    f_insertSort.close();
    cout << "4 sort end" << endl;

    for (int size = 100; size < 12000;) { // сортировка слиянием
        my_arr = new int[size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        time = GetTickCount();
        merge_sort(my_arr, size);
        time = GetTickCount() - time;
        f_mergeSort << size << "\t" << time << "\n";
        size += 500;
    }
    f_mergeSort.close();
    cout << "5 sort end" << endl;

    for (int size = 100; size < 18000;) { // сортировка Шелла
        my_arr = new int[size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        time = GetTickCount();
        shell_sort(my_arr, size);
        time = GetTickCount() - time;
        f_shellSort << size << "\t" << time << "\n";
        size += 500;
    }
    f_shellSort.close();
    cout << "6 sort end" << endl;

    for (int size = 100; size < 8000;) { // сортировка Гномом
        my_arr = new int[size];
        long int time = GetTickCount();
        randomFill(my_arr, size);
        time = GetTickCount();
        GnomeSort(my_arr, size);
        time = GetTickCount() - time;
        f_gnomeSort << size << "\t" << time << "\n";
        size += 100;
    }
    f_gnomeSort.close();
    cout << "7 sort end" << endl;

    delete [] my_arr;
    system ("pause");
    return 0;

}

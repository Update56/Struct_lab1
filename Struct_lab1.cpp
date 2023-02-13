#include <iostream>
#include <vector>
#include <chrono>
#define SIZE 4096

using namespace std;
using namespace std::chrono;

void Rand_array(vector<char>* arr) //заполнение массива
{
    arr->clear();
    for (int i = 0; i < SIZE; i++)
        arr->push_back(32 + rand() % (128 - 32));
    for (int i = 0; i < SIZE; i++)
        cout << arr->at(i) << "";
    cout << endl;
}

void BubleSort(vector<char>* arr) // сортировка пузьком
{
    auto start = high_resolution_clock::now();

    for (int i = 0; i < arr->size(); i++) // i - номер прохода
    {
        for (int j = arr->size() - 1; j > i; j--)  // внутренний цикл прохода
        {
            if ((int)arr->at(j - 1) > (int)arr->at(j))
                swap(arr->at(j - 1), arr->at(j));
        }
    }

    auto end = high_resolution_clock::now();

    for (int i = 0; i < arr->size(); i++)
        cout << arr->at(i) << "";
    cout << "\nBubble sort time for array of " << SIZE << " elements: " << duration_cast<milliseconds>(end - start).count() << " msec";
    return;
}

void Quick_sort(vector<char>* arr, int left, int right) //быстрая сортировка
{

    int l = left; //левый "указатель"
    int r = right; //правый "указатель"
    char mid = arr->at((l + r + 1) / 2); //опорный элемент

    do {
        while (arr->at(l) < mid) //сдвигаем указатели
            l++;
        while (arr->at(r) > mid)
            r--;
        if (l <= r)
        {
            swap(arr->at(l), arr->at(r));
            l++;
            r--;
        }
    } while (l <= r);

    if (left < r)
        Quick_sort(arr, left, r);
    if (l < right)
        Quick_sort(arr, l, right);

}

void Binary_search(vector<char> arr, char key) //бинарный поиск
{
    auto start = high_resolution_clock::now();

    int left = 0;
    int right = arr.size() - 1;
    bool flag = 0;
    int mid;

    while ((left <= right) && (flag != 1))
    {
        mid = (left + right) / 2;

        if ((int)arr.at(mid) == (int)key)
            flag = 1;

        if ((int)arr.at(mid) > (int)key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (flag)
        cout << "Item is in array\n";
    else
        cout << "Item isn't in array\n";
    auto end = high_resolution_clock::now();
    cout << "\nBinary search time for array of "<< SIZE << " elements: " << duration_cast<milliseconds>(end - start).count() << " msec";
}

int main()
{
    vector<char> main_array;
    Rand_array(&main_array);
    int choise;
    bool sorted = false;
    do
    {
        cout << "\nSelect Array Sort\n";
        cout << "1. Simple sort(Bubble)\n2. Improved sort(Quick)\n3. Binary search(only sort array)\n4. New array\n5. Exit\n";
        cin >> choise;

        switch (choise)
        {
        case 1:
        {
            BubleSort(&main_array);
            sorted = true;
            break;
        }
        case 2:
        {
            auto start = high_resolution_clock::now();
            Quick_sort(&main_array, 0, main_array.size() - 1);
            auto end = high_resolution_clock::now();

            for (int i = 0; i < main_array.size(); i++)
                cout << main_array.at(i) << "";
            cout << "\nQuick sort time for array of " << SIZE << " elements: " << duration_cast<milliseconds>(end - start).count() << " msec";
            sorted = true;
            break;
        }
        case 3:
        {
            if (sorted)
            {
                char key;
                cout << "Input char: ";
                cin >> key;
                Binary_search(main_array, key);
            }
            else
                cout << "Array not sorted\n";
            break;
        }
        case 4:
        {
            Rand_array(&main_array);
            sorted = false;
            break;
        }
        case 5:
            return 0;
            break;

        default:
            cout << "Invalid menu item\n";
            break;
        };
    } while (choise != 5);
    
}
 

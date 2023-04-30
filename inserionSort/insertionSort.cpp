#include <iostream>

using namespace std;
#define endl '\n'



void insertionSort(long long heights[], int nameID[], long n)
{
    int i, j;
    long long key;
    int  key2;
    for (i = 1; i < n; i++)
    {
        key = heights[i];

        key2 = nameID[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && heights[j] > key)
        {
            heights[j + 1] = heights[j];
            nameID[j+1] = nameID[j];

            j = j - 1;
        }
        heights[j + 1] = key;
        nameID[j+1] = key2;

    }
}

long long powerOfTwo(long long n) {
    if (n > 0) {
        while (n % 2 == 0) {
            n /= 2;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 0 || n != 1) {
            return 0;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int m;
    long long n;
    long long height;
    string name;

    //перевірка чи проходить всі варунки
    cin >> m;
    while(m!=0){

        cin >> n;
        string names[n];
        int nameID[n];
        long long heights[n];

            for(int i = 0; i < n; i++){

                cin >> name >> height;

                names[i] = name;
                nameID[i] = i;
                heights[i] = height;

            }

            //сортуємо
            long long nn = sizeof(heights) / sizeof(heights[0]);
            insertionSort(heights,nameID, nn);

            //перевіряємо чи степінь двойкі і виводимо спершу його
            for (long long i = 0; i < n; i++) {
                if (powerOfTwo(heights[i])) {

                    cout << names[nameID[i]] << "-" << heights[i] << " ";

                }
            }

            for (long long i = 0; i < n; i++) {
                if (!powerOfTwo(heights[i])) {

                    cout << names[nameID[i]] << "-" << heights[i] << " ";

                }
            }

            cout << endl;






            m--;
        }


    return 0;
}
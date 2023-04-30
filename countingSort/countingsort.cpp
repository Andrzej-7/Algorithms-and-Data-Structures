#include<iostream>

using namespace std;

struct Hunters{
    char name[21];
    short crabs;
    short traps;
};



void countingSort(Hunters *hunters, int n) {
    short maxVal = hunters[0].crabs; //initialize maxVal to the number of crabs caught by the first hunter

    // find the max value
    for (int i = 1; i < n; i++) {
        if (hunters[i].crabs > maxVal) {
            maxVal = hunters[i].crabs;
        }
    }

    //2D array to sort the occurrences of each value
    string sort[maxVal + 1][10];
    for (int i = 0; i < n; i++) {
        string space = " " + (string)hunters[i].name; //variable to add a space before the name of the hunter
        if (sort[hunters[i].crabs][hunters[i].traps].size() == 0) //if  empty
            sort[hunters[i].crabs][hunters[i].traps]=hunters[i].name; //add  hunter name in the array
        else {
            sort[hunters[i].crabs][hunters[i].traps]+=space; //if  is not empty, add a space and the current hunter's name
        }
    }

    //sortujemo po spadaniu i wywodymo
    for (int i = maxVal; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (sort[i][j].size() > 0) { //if t not empty
                cout << sort[i][j] << ' ';
            }
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    Hunters hunters[n];


    for (int i = 0; i < n; i++) {
        cin >> hunters[i].name >> hunters[i].crabs >> hunters[i].traps;
    }

    countingSort(hunters,n);

    return 0;
}
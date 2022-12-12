#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> &vect, int size){
    size = vect.size();

    for(int i = 0; i < size-1; i++) {
        int min = i;
        for(int j = i+1; j < size; j++) {
            if(vect[j] < vect[min]){
                min = j;
            }
        }
        swap(&vect[min], &vect[i]);
    }
}

int main(){
    vector<int> vect;

    vect.push_back(21);
    vect.push_back(1);
    vect.push_back(18);
    vect.push_back(9);
    vect.push_back(45);
    vect.push_back(34);
    vect.push_back(0);

    selectionSort(vect, vect.size());

    for(int i = 0; i < vect.size(); i++) {
        cout << vect[i] <<" ";
    }

    return 0;
}

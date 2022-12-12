#include <vector>
#include <iostream>
using namespace std;

void BubbleSort(vector<int> &vect, int size){
    size = vect.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if(vect[j] > vect[j+1]){
                int temp = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = temp;
            }
        }
    }
}

int main(){
    vector<int> vect;

    vect.push_back(6);
    vect.push_back(4);
    vect.push_back(3);
    vect.push_back(19);
    vect.push_back(8);
    vect.push_back(5);

    BubbleSort(vect, vect.size());

    for(int i = 0; i < vect.size(); i++){
        cout<<vect[i];
    }

    return 0;
}
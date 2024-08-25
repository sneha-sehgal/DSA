#include<iostream>
using namespace std;

void Hanoi(int NumDisc, int start, int end){
    if (NumDisc == 0)
        return;
    int other = 6-(start + end);
    Hanoi(NumDisc-1, start, other);
    cout << start << "->" << end << endl;
    Hanoi(NumDisc-1, other, end);
    
}
int main(){
    int NumDisk = 4;//number of discs
    Hanoi(3, 1, 3);
}
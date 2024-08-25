#include<iostream>
using namespace std;

bool IsValid(int Dimension, int row, int col, int **Board){
    if(row >= 0 && row < Dimension && col >= 0 && col < Dimension && Board[row][col] == -1){
        return true;
    }
    
    return false;
}

bool KnightsTour(int **Board, int Dimension, int row, int col, int StepCount, int XMove[], int YMove[]){

    

    if(StepCount == Dimension*Dimension)
        return true;
    int i;
    for(i = 0; i < Dimension; i++){

        int NextRow = row + XMove[i];
        int NextCol = col + YMove[i];
        
        if(IsValid(Dimension, NextRow, NextCol, Board))
        {
            Board[NextRow][NextCol] = StepCount;
            if(KnightsTour(Board, Dimension, NextRow, NextCol, StepCount+1, XMove, YMove)){
                return true;
            }
            Board[row + XMove[i]][col + YMove[i]] = -1;
        }
    }
    return false;

}

int main(){
    int Dimension;
    cout << "Enter the Dimension : ";
    cin >> Dimension;

    int **Board = new int*[Dimension];
    for(int i = 0; i < Dimension; i++)
        Board[i] = new int [Dimension];
    
    for(int i = 0; i < Dimension; i++){
        for(int j = 0; j < Dimension; j++)
            Board[i][j] = -1;
    }

    //Set the moves a knight can move on the x and y axis
    int XMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int YMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Set knight at the first position in the Board
    Board[0][0] = 0;
    KnightsTour(Board, Dimension, 0, 0, 1, XMove, YMove);

    for(int i = 0; i < Dimension; i++){
        for(int j = 0; j < Dimension; j++){
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// 
// A Sodku Solver Using Backtracking Anav Mehta (c)
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isUsed(int matrix[9][9], int x, int y, int val)
{
    // in rows
    for(int i=0;i<9;i++){
        if(matrix[x][i] == val) return true;
    }
    // in cols
    for(int i=0;i<9;i++){
        if(matrix[i][y] == val) return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //cout << i+x-x%3 << " " << j+y-y%3 << endl;
            if(matrix[i+x-x%3][j+y-y%3] == val) return true;
        }
    }
    return false;
}

void printSoduku(int matrix[9][9]){
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool findLoc(int matrix[9][9], int &x, int &y)
{
    for(x=0;x<9;x++){
        for(y=0;y<9;y++){
            if(matrix[x][y] == 0) return true;
        }
    }
    return false;
}

bool soduku(int matrix[9][9]){
    int x, y;
    if(!findLoc(matrix, x, y)){
        return true;
    }

    for(int i=1;i<=9;i++){
        if(!isUsed(matrix, x, y, i)) {
            matrix[x][y] = i;
            if(soduku(matrix)) return true;
            matrix[x][y] = 0;
        }
    }
    return false;
}



int main(){
    int a[9][9];

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> a[i][j];
        }
    }
    if(soduku(a)) printSoduku(a);
    else cout << "NO SOLUTION" << endl;
}

#include<iostream>
using namespace std;

int main(){
   int arr [4][4][4];
    //this is initializing 3 arrays 
   for(int i = 0; i < 4; i++){
        for(int j = 0; j <4; j++){
            for(int k = 0; k<4; k++){
                arr[i][j][k] = i + j + k;
        }
    }
   }
    //printing the initialized array
    for(int i = 0; i < 4; i++){
        cout<<i<<"st Layer"<<endl;
        for(int j = 0; j <4; j++){
            for(int k = 0; k<4; k++)       
                cout<<arr[i][j][k]<<" ";
                cout<<endl;

        }
            cout<<endl;
    }

}
#include<iostream>
using namespace std;

int main(){
    //got array from the user
    int arr1[] = {1,2,3,4};
    int arr2[] = {5,6,7,8};
    
    //Checking the length from the array which was given by the user
    int len1 = sizeof (arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);

    //initializing an array to store the merged elements
    int mergeString[len1 + len2];

    //iterating a for loop for traversing and copying the elements of arr1 into the mergestring
    for (int i = 0; i < len1; i++)
    {
        mergeString[i] = arr1[i];
    }

    //iterating a for loop for traversing and copying the elements of arr2 into the mergestring
    for (int i = 0; i < len2; i++)
    {
        mergeString[len1 + i] = arr2[i];//here we are giving the address of the merge string to copy in that 
                                        //from one index after the len1
    }
    
    cout<<"The concatenated string is: ";
    for (int i = 0; i < len1 + len2; i++)
    {
        cout<<mergeString[i]<<" ";
    }
    cout<<endl;
    
    
    
}
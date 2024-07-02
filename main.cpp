#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    // Iterating and printing the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


void quadraticProbing(int table[], int tableSize, int arr[], int secondHash)
{
    // For loop to iterate through an array
    for (int i = 0; i < secondHash; i++) {
        // Computing the hash value
        int hash = arr[i] % tableSize;

        //Insert if empty slot found
        if (table[hash] == -1)
            table[hash] = arr[i];
        else {
            //for loop to set up quadratic probing
            for (int j = 0; j < tableSize; j++) {
                // formula for quadratic probing
                int quadProb = (hash + j * j) % tableSize;
                if (table[quadProb] == -1) {
                    table[quadProb] = arr[i];
                    break;
                }
            }
        }
    }
    printArray(table, secondHash);
}

int main()
{
    //Array of numbers
    int arr[] =  {8,6,10,1,10,5,10};
    int N = 7;

    // Size of the hash table
    int Len = 7;
    int hash_table[7];

    // Initializing the hash table
    for (int i = 0; i < Len; i++) {
        hash_table[i] = -1;
    }
    cout << "Empty hash table: " << endl;
    printArray(hash_table, 7);
    cout << endl;

    //Quadradic probinb applied to hash table.
    cout << "Hash table after quadratic probing: " << endl;
    quadraticProbing(hash_table, Len, arr, N);


    return 0;
}
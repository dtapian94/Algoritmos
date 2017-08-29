//
//  main.cpp
//  Tarea2Algoritmos
//
//  Created by Daniel Esteban Tapia Nava on 28/08/17.
//  Copyright © 2017 Daniel Esteban Tapia Nava. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
using namespace chrono;




void bucketSort(int sarray[], int array_size) {
    const int max = array_size;
    // use bucket[x][max] to hold the current count
    int bucket[10][max+1];
    // init bucket counters
    for(int x=0;x<10;x++){
        bucket[x][max] = 0;
    }
    // main loop for each digit position
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        // array to bucket
        for(int i = 0; i < max; i++) {
            // get the digit 0-9
            int dig = (sarray[i] / digit) % 10;
            // add to bucket and increment count
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        // bucket to array
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            // reset the internal bucket counters
            bucket[x][max] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    {
        int array[1000000], n, c, d, swap,temp,min,loc;
        
        
        
        cout << "Enter number of elements\n" ;
        cin >> n;
        //n = d;
        
        cout << "The " << n << " integers will be generated automatically" << endl;
        cout << endl;
        
        
        for (c = 0; c < n; c++)
            
            //scanf("%d", &array[c]);           // This line, made you mannually input each number
            
            array[c] = (rand()%1000) ;           // randomize the elements in the array ****
        
        
        // FUNCTION
        
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        
        
        
        bucketSort(array,n);
        
        
        
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        
        
        // END OF FUNCTION
        
        cout << "Sorted list in ascending order:\n";
        
        for ( c = 0 ; c < n ; c++ )
            printf("%d\n", array[c]);
        
        auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
        
        cout << "Duracion fue de " << duration << " milisegundos" << endl ;
        
        return 0;
    }
}
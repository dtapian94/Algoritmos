
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
using namespace chrono;


void countingSort(int arr[], int sz) {
    int i, j, k;
    int idx = 0;
    int min, max;
    
    min = max = arr[0];
    for(i = 1; i < sz; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }
    
    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;
    
    for(i = 0; i < sz; i++) B[arr[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) arr[idx++] = i;
    
    
    delete [] B;
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
            
         array[c] = (rand()%1000);           // randomize the elements in the array ****
        
        
        
        
        // FUNCTION
        
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        
        
        countingSort(array, n);
        
     
       
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


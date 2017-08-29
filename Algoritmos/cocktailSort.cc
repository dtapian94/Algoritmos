#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
using namespace chrono;


void cocktailSort(int a[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n-1;
    
    while (swapped){
        swapped = false;
        
        for (int i = start; i < end; ++i){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
        
        swapped = false;
        
        --end;
        
        for (int i = end - 1; i >= start; --i){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        ++start;
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
            
         array[c] = (rand()%1000);           // randomize the elements in the array ****
        
        
        
        
        // FUNCTION
        
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        
        
        cocktailSort(array, n);
        
     
       
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        
        
        // END OF FUNCTION
        
        cout << "Sorted list in ascending order:\n";
        
        for ( c = 0 ; c < n ; c++ )
            printf("%d\n", array[c]);
        
        auto duration = duration_cast<seconds>( t2 - t1 ).count();
        
        cout << "Duracion fue de " << duration << " milisegundos" << endl ;
        
        return 0;
    }
}

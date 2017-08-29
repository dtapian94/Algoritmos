#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
using namespace chrono;



void shell_sort( int array[], int n )
{
    static constexpr int gap_sequence[] = { 13, 9, 5, 2, 1 } ;
    
    // for (gap = n/2; gap > 0; gap /= 2)
    for( int gap : gap_sequence ) if( gap < n )
    {
        // for (i = gap; i < n; i++)
        for( int i = gap ; i < n; ++i )
            
            // for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            for ( int j = i-gap ; j >= 0 && array[j] > array[j+gap] ; j -= gap )
            /*
             temp = v[j];
             v[j] = v[j+gap];
             v[j+gap] = temp;
             */
                std::swap( array[j], array[j+gap] ) ;
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
        
        
       shell_sort( array, n ) ;

        
       
       
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
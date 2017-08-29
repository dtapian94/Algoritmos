#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
using namespace chrono;





void shellSort(int arr[], int n)
{
    int gap, i, j, temp; //g es el gap a implementar inicialmente
    
    for(gap = n/2; gap > 0; gap = gap/2)
    {
        for(i = gap; i < n; i++)
        {
            for(j = i-gap; j >= 0; j = j-gap)
            {
                if(arr[j+gap] >= arr[j])
                    break; //Si el valor en una posición arriba de k es mayor al de la posición k en el arreglo, se rompe el ciclo
                else
                {			//
                    temp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = temp;
                }
            }
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
        
        
       
        shellSort(array,n);
        
       
       
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

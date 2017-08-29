#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
using namespace chrono;


int divide(int *array, int lo, int hi) {
    int i,j;
    int v;
    int temp;
    
    v = array[lo];
    i = lo;
    j = hi;
    
    // Mientras no se cruzen los índices
    while (i < j) {
        while ((i < j) && (array[i] <= v)) {
            i++;
        }
        
        while (array[j] > v) {
            j--;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[j];
    array[j] = array[lo];
    array[lo] = temp;
    // La nueva posición del pivot
    return j;
}


// Función recursiva para hacer el ordenamiento
void quickSort(int *array, int lo, int hi)
{
    
    int pivot;
    
    if (lo < hi) {
        pivot = divide(array, lo, hi);
        
        // Ordeno la lista de los menores
        quickSort(array, lo, pivot - 1);
        
        // Ordeno la lista de los mayores
        quickSort(array, pivot + 1, hi);
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
        
        
        quickSort(array, 0, n-1);
        
     
       
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

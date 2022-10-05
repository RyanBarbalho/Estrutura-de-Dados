#include<stdio.h>
#include<math.h>


void swap(int array[],int x, int y)
{
        int aux = array[y];
        array[y] = array[x];
        array[x] = aux;
        
}

void metadeSort(int array[], int size)
{
    int div = size/2
    

    for (int d = ceil(div); d > 0 ; d--){
        for ( int i = 1; i+d < size ; i++){
            if (array[i] > array[i+d]){
                swap(array, i, i+d);
            }

        }
    }


}

void print(int vector[],int size)
{
    for (int i =0; i<size ; i++){
        printf("%d", vector[i])
    }
    return;
}

int main()
{
    int array[8]= {5,8,7,3,1,7,2,4};
    
    printf("\n");
    print(array,8);
    selectSort(array,8);
    print(array,8);
    printf("\n");


    
    return 0;
}
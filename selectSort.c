#include<stdio.h>


void swap(int array[],int x, int y)
{
        int aux1 = array[y];
        array[y] = array[x];
        array[x] = aux1;
        
}
void selectSort(int array[], int size)
{
    for(int i=1; i<size ; i++){
        
        for(int j= i; j>0 ; j--){
            if( array[j]<array[j-1]){
                swap( array, j, j-1);
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

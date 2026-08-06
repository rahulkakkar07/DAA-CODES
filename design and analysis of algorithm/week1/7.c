#include<stdio.h>
int main(){
    int n,k,i,j,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("enter the number of rotations: ");
    scanf("%d",&k);

    k=k%n; // to handle cases where k is greater than n

    // Rotate the array

    for(i=0;i<k;i++){
        temp = a[n-1];//store the last element
        for(j=n-1;j>0;j--){
            a[j] = a[j-1];//shifting elements to the right
        }
        a[0] = temp;//place the last element at the beginning
    }
    printf("Array after %d rotations: ",k);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
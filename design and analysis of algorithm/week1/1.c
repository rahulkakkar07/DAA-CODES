#include<stdio.h>
int main()
{
    int n,i;
    int a[100];
    printf("enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int max=a[0];
    for(i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }

    int secondMax=-1;
    for(i=0;i<n;i++){
        if(a[i]!=max &&a[i]>secondMax){
            secondMax=a[i];
        }
    }
    if(secondMax==-1){
        printf("There is no second largest element in the array.\n");
    }
    else{
        printf("The second largest element in the array is: %d\n",secondMax);
    }
    return 0;
    

}
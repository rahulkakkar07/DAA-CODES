#include<stdio.h>
int main()
{
    int n,i,count=0;
    int a[100];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<10;i++){
        if(a[i]==0){
            count++;

        }
    }
    if(count>1){
        printf("the frequency of zero is %d\n",count);
    }
    for(i=0;i<10;i++){
        if(a[i]!=0){
            count=1;
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    count++;
                    a[j]=0;
                }
            }
        }
    printf("the frequency of %d=%d\n",a[i],count);
      
    }
    return 0;

}
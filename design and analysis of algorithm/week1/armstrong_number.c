#include<stdio.h>
#include<math.h>
int main(){
    int num,originalNum,remainder,digits=0;
    float result=0.0;
    printf("enter a no.");
    scanf("%d",&num);
    originalNum=num;
    while(originalNum!=0){
        originalNum/=10;
        digits++;
    }
    originalNum=num;
    while(originalNum!=0){
        remainder=originalNum%10;
        result+=pow(remainder,digits);
        originalNum/=10;
    }
    if(result==num){
        printf("%d is an Armstrong number.",num);
    }
    else{
        printf("%d is not an Armstrong number.",num);
    }
}
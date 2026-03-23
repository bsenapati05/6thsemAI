#include<stdio.h>
int main(){
int arr1[100],arr2[100],n1,n2,i,n;
printf("enter the element of array 1:");
scanf("%d",&n1);
printf("enter the element of array 1:\n");
for(i=0;i<n1;i++){
   scanf("%d",&arr1[i]);
}
printf("enter the element of array 2:");
scanf("%d",&n2);
for(i=0;i<n2;i++){
   scanf("%d",&arr2[i]);
}
//append array
n=n1+n2;
for(i=0;i<n2;i++){
  arr1[n1+i]= arr2[i];
}
printf("array after append is:\n");
for(i=0;i<n;i++){
printf("%d",arr1[i]);
}
return 0;
}

#include <stdio.h>
#include <math.h>

float simpson(float(*f)(float),float a,float b,int n){
    int k;
    float s,s1,s2 = 0;
    float h = (b-a)/n;
    s1 = (*f)(a+h/2);
    for(k = 1;k<=n-1;k++){
        s1 += (*f)(a+k*h+h/2);
        s2 += (*f)(a+k*h);
    }
    s = h/6 * ((*f)(a) + 4*s1 + 2*s2 + (*f)(b));
    return s;
}
float f(float x){
    return 1/sqrt(1+x*x*x);
}
int main(){
    int i,n=2;
    float s;
    for(i=0;i<=4;i++){
        s = simpson(f,0,1,n);
        printf("s(%d) = %f\n",n,s);
        n *= 2;
    }
}
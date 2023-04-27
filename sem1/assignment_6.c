#include <stdio.h>
#include <math.h>

const float PI = 3.14;

// prob 1
float cube(float n){
  return pow(n,3);
}

// prob 2
float smplInt(float p, float r, int t){
  return (p*r*t)/100;
}

// prob 3
float diameter(float r){
  return 2*r;
}
float circumference(float r){
  return 2*PI*r;
}
float area(float r){
  return PI*r*r;
}

// prob 4
long long int decimalToBinary(int n){
  long long int binaryNum = 0;
  int power=0;
  while(n>0){
    int rem = n%2;
    long long int tens = pow(10,power);
    binaryNum+=rem*tens;
    n=n/2;
    power++;
  }
  return binaryNum;
}

//prob 5
int factorial(int n){
  if(n==0 || n==1){
    return 1;
  }
  return n*factorial(n-1);
}

//prob 6
int power(int n, int x){
  if(x==0){
    return 1;
  }
  if(x==1){
    return n;
  }
  return n*power(n,x-1);
}

//prob 7
int pingalaSeries(int n){
  if(n==1){
    return 0;
  }
  if(n==2){
    return 1;
  }
  return pingalaSeries(n-1)+pingalaSeries(n-2);
}

//prob 8
int GCD(int n1, int n2){
  int gcd = 1;
  for(int i = 1; i<=n1 && i<=n2; i++){
    if(n1%i == 0 && n2%i == 0)
       gcd=i;
    }
  return gcd;
}

//prob 9
int combination(int n, int r){
  int ans = factorial(n)/(factorial(r)*factorial(n-r));
  return ans;
}

int main() {
  // float p, r;
  int t;
  scanf("%d", &t);
  printf("%d", combination(t,3));
  return 0;
}

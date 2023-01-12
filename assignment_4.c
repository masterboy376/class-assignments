#include <stdio.h>
#include <math.h>

const double e = 2.7182;

// problem 2
void prob2_1(){
    int n;
    printf("Kindly Enter input(s) below\n");
    scanf("%d", &n);
    float ans = 0;
    for(int i = 1 ; i<n+1;i++){
        ans += 1.0/i;
    }
    printf("ANSWER: %.2f\n", ans);
}

void prob2_2(){
    int n;
    printf("Kindly Enter input(s) below\n");
    scanf("%d", &n);
    float ans = 0;
    for(int i = 1 ; i<n+1;i++){
        if(!(i&1) || i==1)
            ans+=1.0/i;
        else    
            ans-=1.0/i;
    }
    printf("ANSWER: %.2f\n", ans);
}

void prob2_3(){
    int n;
    printf("Kindly Enter input(s) below\n");
    scanf("%d", &n);
    float ans = 0;
    for(int i = 1 ; i<n+1;i++){
        ans += 1.0/(i*i);
    }
    printf("ANSWER: %.2f\n", ans);
}

void prob2_4(){
    int n;
    printf("Kindly Enter input(s) below\n");
    scanf("%d", &n);
    int dp[n];
    dp[0] = 1;
    for(int  i = 1 ; i<n+1; i++){
        dp[i] = i*dp[i-1];
    }
    float ans = 0;
    for(int i = n ; i>=1;i--){
        ans += 1.0/dp[i];
    }
    printf("ANSWER: %.2f\n", ans);
}

// problem 3
void prob3_1(){
    int n;
    float x;
    printf("Kindly Enter input(s) below\n");
    scanf("%f %d", &x, &n);

    int dp[n];
    dp[0] = 1;
    for(int  i = 1 ; i<n+1; i++){
        dp[i] = i*dp[i-1];
    }
    float ans = 0 ;
    for(int i = 0 ; i< n+1; i++){
        ans+=pow(x,i)/dp[i];
    }
    printf("ANSWER: %.2f\n", ans);
}

void prob3_2(){
    int n;
    float x, ans, t;
    printf("Kindly Enter input(s) below\n");
    scanf("%f %d", &x, &n);

    x=x*3.14159/180;
    t=x;
    ans = x;
    for(int i = 1 ; i< n+1; i++){
        t = (t*(-1)*x*x)/(2*i*(2*i+1));
        ans = ans+t;
    }
    printf("ANSWER: %.2f\n", ans);
}

void prob3_3(){
    int n;
    float x, ans=1, t=1;
    printf("Kindly Enter input(s) below\n");
    scanf("%f %d", &x, &n);

    x=x*3.14159/180;
    for(int i = 1 ; i< n+1; i++){
        t = (t*(-1)*x*x)/(2*i*(2*i-1));
        ans = ans+t;
    }
    printf("ANSWER: %.2f\n", ans);
}

int main()
{
    prob3_3();
    return 0;
}

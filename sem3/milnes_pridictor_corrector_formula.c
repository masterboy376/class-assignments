#include <stdio.h>
#include <stdlib.h>

#define MAX         15

float dybydx(float x, float y);
void milnep(float x[], float y[], float delx, int n, float ydash[]);
void milnec(float x[], float y[], float delx, float ydash[], int n);

int main()
{
   int          i = 0, n;
   float        x[MAX], y[MAX], ydash[MAX];
   float        delx;

   printf("Enter the first four consecutive values: \n");
   while (i < 4)
   {
      printf("Enter the value of x%d: ", i);
      scanf("%f", &x[i]);
      printf("Enter the value of y%d: ", i);
      scanf("%f", &y[i]);
      printf("\n");
      i++;
   }

   printf("Enter the value of Δx: ");
   scanf("%f", &delx);

   printf("Upto how many values consecutive points should be computed: ");
   scanf("%d", &n);

   milnep(x, y, delx, n+4, ydash);
   milnec(x, y, delx, ydash, n+4);
   exit(0);
}

void milnep(float x[], float y[], float delx, int n, float ydash[])
{
   int        i = 4, j;

   for (j = 0; j < 4; j++)
   {
      ydash[j] = dybydx(x[j], y[j]);
   }

   while (i < n)
   {
      y[i] = y[i-4] + (4*delx*(2*ydash[i-3]-ydash[i-2]+2*ydash[i-1]))/3;
      x[i] = x[i-1] + delx;
      ydash[i] = dybydx(x[i], y[i]);
      printf("x%d = %f and y%d = %f\n", i, x[i], i, y[i]);
      i++;
   }

   return ;
}

void milnec(float x[], float y[], float delx, float ydash[], int n)
{
   int        i = 4;
   float      ycheck;

   printf("\nBy corrector's method: \n");
   while (i < n)
   {
      ycheck = y[i-2] + delx*(ydash[i-2]+4*ydash[i-1]+ydash[i])/3;
      printf("y%d = %f\n", i, ycheck);
      i++;
   }

   return ;
}

float dybydx(float x, float y)
{
   float        fx;

   fx = y+3*x-x*x;
   return fx;
}

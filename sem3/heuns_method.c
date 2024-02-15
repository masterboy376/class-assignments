#include <stdio.h>

float dydx(float x, float y) { return (x*x + y - 2); }

float heuns(float x0, float y0, float x, float h)
{
  int n = (int)((x - x0) / h);

  float k1, k2;

  float y = y0;
  for (int i = 1; i <= n; i++) {
    k1 = h * dydx(x0, y);
    k2 = h * dydx(x0 + h, y + k1);

    y = y + (k1 + k2)/2;

    x0 = x0 + h;
  }

  return y;
}

int main()
{
  float x0, y0, x, h;
  printf("Enter initial values of x0, y0, x, h:\n");
  scanf("%f %f %f %f", &x0, &y0, &x, &h);

  printf("y(x) = %f", heuns(x0, y0, x, h));
  return 0;
}

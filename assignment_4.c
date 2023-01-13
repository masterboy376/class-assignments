#include <math.h>
#include <stdio.h>

const double e = 2.7182;

// problem 1
void prob1_1(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (i > abs(n - j)) {
        printf("%d ", 2 * (i - abs(j - n)) - 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void prob1_2(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (i > abs(n - j)) {
        printf("%d ", 2 * (i - abs(j - n)));
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void prob1_3(int n) {
  for (int i = n; i >= 1; i--) {
    for (int j = i; j >= 1; j--) {
      printf("%d ", 2 * (n - j + 1) - 1);
    }
    printf("\n");
  }
}

void prob1_4(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      if (j <= i) {
        printf("%d ", j);
      } else if (j >= 2 * n - i + 1) {
        printf("%d ", (2 * n - j) + 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void prob1_5(int n) {
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (i > abs(n - j)) {
        printf("%d ", i - abs(j - n));
      }
    }
    printf("\n");
  }
  for (int j = 1; j <= 2 * n - 1; j++) {
    if (n > abs(n - j)) {
      printf("%d ", n - abs(j - n));
    }
  }
  printf("\n");
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (i > abs(n - j)) {
        printf("%d ", i - abs(j - n));
      }
    }
    printf("\n");
  }
}

void prob1_6(int n) {
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (i > abs(n - j)) {
        printf("%d ", cnt * cnt);
        cnt++;
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void Print_BinCoeff(int x) {
  int temp = x;
  int answer = x;
  int c = 2;
  for (int i = 0; i <= x; i++) {
    if (i == 0 || i == x) {
      printf("%-4d", 1);
    } else {
      printf("%-4d", answer);
      answer = answer * (temp - 1);
      answer = answer / c;
      temp--;
      c++;
    }
  }
  printf("\n");
}
void prob1_7(int n) {
  for (int i = 0; i < n; i++) {
    for (int k = n - i - 1; k > 0; k--) {
      printf("  ");
    }
    Print_BinCoeff(i);
  }
}

// problem 2
void prob2_1() {
  int n;
  printf("Kindly Enter input(s) below\n");
  scanf("%d", &n);
  float ans = 0;
  for (int i = 1; i < n + 1; i++) {
    ans += 1.0 / i;
  }
  printf("ANSWER: %.2f\n", ans);
}

void prob2_2() {
  int n;
  printf("Kindly Enter input(s) below\n");
  scanf("%d", &n);
  float ans = 0;
  for (int i = 1; i < n + 1; i++) {
    if (!(i & 1) || i == 1)
      ans += 1.0 / i;
    else
      ans -= 1.0 / i;
  }
  printf("ANSWER: %.2f\n", ans);
}

void prob2_3() {
  int n;
  printf("Kindly Enter input(s) below\n");
  scanf("%d", &n);
  float ans = 0;
  for (int i = 1; i < n + 1; i++) {
    ans += 1.0 / (i * i);
  }
  printf("ANSWER: %.2f\n", ans);
}

void prob2_4() {
  int n;
  printf("Kindly Enter input(s) below\n");
  scanf("%d", &n);
  float dp[n+1];
  dp[0] = 1.0;
  for (int i = 1; i < n + 1; i++) {
    dp[i] = i * dp[i - 1];
  }
  float ans = 0;
  for (int i = n; i >= 1; i--) {
    ans += 1 / dp[i-1];
    
  }
  printf("ANSWER: %.2f\n", ans);
}

// problem 3
void prob3_1() {
  int n;
  float x;
  printf("Kindly Enter input(s) below\n");
  scanf("%f %d", &x, &n);

  int dp[n];
  dp[0] = 1;
  for (int i = 1; i < n + 1; i++) {
    dp[i] = i * dp[i - 1];
  }
  double ans = 0;
  for (int i = 0; i < n + 1; i++) {
    ans += pow(x, i) / dp[i];
  }
  printf("ANSWER: %.2f\n", ans);
}

void prob3_2() {
  int n;
  float x, ans, t;
  printf("Kindly Enter input(s) below\n");
  scanf("%f %d", &x, &n);

  x = x * 3.14159 / 180;
  t = x;
  ans = x;
  for (int i = 1; i < n + 1; i++) {
    t = (t * (-1) * x * x) / (2 * i * (2 * i + 1));
    ans = ans + t;
  }
  printf("ANSWER: %.2f\n", ans);
}

void prob3_3() {
  int n;
  float x, ans = 1, t = 1;
  printf("Kindly Enter input(s) below\n");
  scanf("%f %d", &x, &n);

  x = x * 3.14159 / 180;
  for (int i = 1; i < n + 1; i++) {
    t = (t * (-1) * x * x) / (2 * i * (2 * i - 1));
    ans = ans + t;
  }
  printf("ANSWER: %.2f\n", ans);
}

int main() {
  prob1_6(5);
  return 0;
}

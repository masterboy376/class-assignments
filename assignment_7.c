#include <stdio.h>

// helper functions


// problem 1
void prob1()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%d %f", sum, (float)sum / n);
}

// problem 2
void prob2()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int mx = -999999999, mn = 999999999;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > mx)
            mx = a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    printf("%d %d", mx, mn);
}

// problem 3
void prob3()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] & 1)
            odds++;
        else
            evens++;
    }
    printf("%d %d", odds, evens);
}

// problem 4
void prob4()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int at[n][m];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            at[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", at[i][j]);
        }
        printf("\n");
    }
}

// problem 5
// int** matSum(int m1, int n1, int m2, int n2,int a1[m1][n1], int a2[m2][n2]){
//   int m,n;
//   if(m1!=m2 || n1!=n2){
//     int res[1][1] = {{-1}};
//     return res;
//   }
// }
// void prob5(){
//   int m1,n1;
//   scanf("%d %d",&m1, &n1);
//   int a1[m1][n1];
//   for(int i =0;i<m1;i++){
//     for(int j = 0 ;j<n1;j++){
//       scanf("%d", &a1[i][j]);
//     }
//   }
//   int m2,n2;
//   scanf("%d %d",&m2, &n2);
//   int a2[m2][n2];
//   for(int i =0;i<m2;i++){
//     for(int j = 0 ;j<n2;j++){
//       scanf("%d", &a2[i][j]);
//     }
//   }
//   int **sumRes = matSum(m1,n1,m2,n2,a1,a2);
// }

// problem 6
void prob6()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l += a[i][i];
        r += a[i][n - 1 - i];
    }
    printf("%d %d", l, r);
}

// problem 7
void prob7()
{
    int n = 3;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l += a[i][i];
        r += a[i][n - 1 - i];
    }
    printf("%d %d", l, r);
}

// problem 8
void prob8()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]==x){
            ans=i;
            break;
        }
    }
    if(ans!=-1) printf("%d", ans);
    else printf("not found");
}

// problem 9
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void prob9()
{
    int n, x = -1;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
	printf("Sorted array: \n");
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

// problem 10
void prob10()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum+= a[i][j];
        }
    }
    printf("%d\n", sum);
}

int main()
{
    prob8();

    return 0;
}

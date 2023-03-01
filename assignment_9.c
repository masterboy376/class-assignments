#include <stdio.h>
#include <math.h>

// problem 1
void prob1()
{
    struct student
    {
        char name[20];
        int age;
        float marks;
    } s[10];
    for (int i = 0; i < 10; i++)
    {
        printf("enter student %d details: \n", i + 1);
        printf("name: ");
        scanf("%s", &s[i].name);
        printf("age: ");
        scanf("%d", &s[i].age);
        printf("marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("student %d details are as follows: \n", i + 1);
        printf("name: %s\n", s[i].name);
        printf("age: %d\n", s[i].age);
        printf("age: %f\n", s[i].marks);
    }
}

// problem 2
void prob2()
{
    struct distance
    {
        float inch;
        float feet;
    } d1, d2, ans;
    printf("enter 1st distance in inch: \n");
    scanf("%f", &d1.inch);
    d1.feet = d1.inch / 12;
    printf("enter 2nd distance in inch: \n");
    scanf("%f", &d2.inch);
    d2.feet = d2.inch / 12;

    ans.inch = d1.inch + d2.inch;
    ans.feet = d1.feet + d2.feet;

    printf("answer(inch): %f , answer(feet): %f\n", ans.inch,ans.feet);
}

// problem 3
struct complexNum
    {
        int r;
        int c;
    };
void complexSum(struct complexNum* c1, struct complexNum* c2, struct complexNum* ans){
    ans->r = c1->r+c2->r;
    ans->c = c1->c+c2->c;
}

void prob3()
{
    struct complexNum c1, c2, ans;
    printf("enter 1st complex num(real part followed by space and complex part): \n");
    scanf("%d %d", &c1.r, &c1.c);
    printf("enter 2nd complex num(real part followed by space and complex part): \n");
    scanf("%d %d", &c2.r, &c2.c);

    complexSum(&c1,&c2, &ans);

    printf("%d + i%d\n", ans.r,ans.c);
}

// problem 5
struct point
    {
        int x;
        int y;
    };
float pointDis(struct point* p1, struct point* p2){
    float ans;
    ans = sqrt( pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) );
    return ans;
}

void prob5()
{
    struct point p1, p2;
    printf("enter 1st point(x followed by space and y): \n");
    scanf("%d %d", &p1.x, &p1.y);
    printf("enter 2nd point(x followed by space and y): \n");
    scanf("%d %d", &p2.x, &p2.y);

    printf("%f\n", pointDis(&p1,&p2));
}

// problem 6
// struct point
//     {
//         int x;
//         int y;
//     };
float areaOfTriangle(struct point* p1, struct point* p2,  struct point* p3){
    float ans;
    ans = 0.5*abs(p1->x*(p2->y-p3->y) + p2->x*(p3->y-p1->y) + p3->x*(p1->y-p2->y));
    return ans;
}

void prob6()
{
    struct point p1, p2, p3;
    printf("enter 1st point(x followed by space and y): \n");
    scanf("%d %d", &p1.x, &p1.y);
    printf("enter 2nd point(x followed by space and y): \n");
    scanf("%d %d", &p2.x, &p2.y);
    printf("enter 3rd point(x followed by space and y): \n");
    scanf("%d %d", &p3.x, &p3.y);

    float area = areaOfTriangle(&p1,&p2,&p3);
    
    if(area==0) printf("not a triangle\n");
    else printf("a triangle\n");
}

int main()
{
    prob6();
    return 0;
}

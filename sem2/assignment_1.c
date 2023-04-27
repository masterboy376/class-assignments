#include<stdio.h>
#include<math.h>

//------------------------------------------------------------------------------------

// problem 1: c program to convert decimal number into binary number 
long tobinary(int);
void prob1(){
   long bn;
   int dn;
   printf(" Enter any decimal number: ");
   scanf("%d",&dn);
   bn = tobinary(dn);
   printf("The Binary value is: %ld\n",bn);
}
long tobinary(int dn){
   long bn=0,rem,f=1;
   while(dn != 0){
      rem = dn % 2;
      bn = bn + rem * f;
      f = f * 10;
      dn = dn / 2;
   }
   return bn;;
}

//------------------------------------------------------------------------------------

// problem 2: c program to convert binary number into decimal number 
long todecimal(long);
void prob2(){
   long bn;
   long dn;
   printf(" Enter any binary number: ");
   scanf("%ld",&bn);
   dn = todecimal(bn);
   printf("The decimal value is: %ld\n",dn);
}
long todecimal(long bn){
   long dn=0,rem,i=0;
   while(bn != 0){
      rem = bn % 10;
      dn = dn + rem * pow(2,i);
      i++;
      bn = bn / 10;
   }
   return dn;;
}

//------------------------------------------------------------------------------------

// problem 3: c program to find 1's complement of n-bit number 
void prob3()
{
    int n;
    printf("Enter no. of bits in the number: ");
    scanf("%d", &n);
    char binary[n + 1], onesComp[n + 1];
    printf("Enter %d bit binary value: ", n);
    scanf("%s", &binary);
    int i, error=0;
    for(i=0; i<n; i++)
    {
        if(binary[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if(binary[i] == '0')
        {
            onesComp[i] = '1';
        }
        else
        {
            printf("Invalid Input");
            error = 1;
            break;
        }
    }
    onesComp[n] = '\0';
    if(error == 0)
    {
        printf("Ones complement = %s\n", onesComp);
    }
}

//------------------------------------------------------------------------------------

// problem 4: c program to find 2's complement of n-bit number
void prob4()  
{  
    int n; 
    printf("Enter no. of bits in the number: ");
    scanf("%d",&n);  
    char binary[n+1], onescomplement[n+1], twoscomplement[n+1];  
    int carry=1;  
    printf("Enter %d bit binary number: ", n);  
    scanf("%s", binary);
    // Finding onescomplement  
    for(int i=0;i<n;i++)  
    {  
        if(binary[i]=='0')  
        onescomplement[i]='1';  
        else if(binary[i]=='1')  
        onescomplement[i]='0';  
    }  
    onescomplement[n]='\0';  
    // Finding twoscomplement in C  
    for(int i=n-1; i>=0; i--)  
        {  
            if(onescomplement[i] == '1' && carry == 1) twoscomplement[i] = '0';
            else if(onescomplement[i] == '0' && carry == 1)  
            {  
                twoscomplement[i] = '1';  
                carry = 0;  
            }  
            else twoscomplement[i] = onescomplement[i];  
        }  
    twoscomplement[n]='\0';
    printf("Twos complement = %s\n", twoscomplement); 
}  

//------------------------------------------------------------------------------------

int main(){

   printf("----------------------------------------------------------------\n");
   printf("Problem 1: \n");
   prob1();
   printf("----------------------------------------------------------------\n");
   printf("Problem 2: \n");
   prob2();
   printf("----------------------------------------------------------------\n");
   printf("Problem 3: \n");
   prob3();
   printf("----------------------------------------------------------------\n");
   printf("Problem 4: \n");
   prob4();
   printf("----------------------------------------------------------------\n");

   return 0;
}

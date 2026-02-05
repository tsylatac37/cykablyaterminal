#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double SI(double P, double R, double T){
    double amt = P + (P*R*T)/100.0;
    return amt;
}

double CI(double P, double R, double T){
    double amt = P * pow(1 + (R/100.0), T);
    return amt;
}

void cbi(){
   int l;
   while((l = getchar()) != '\n' && l != EOF);
}
int dv(const char *p, double *v){
   int r;
   printf("%s", p);
   while((r = scanf("%lf", v)) != 1){
      printf("Invalid input please enter a valid NUMBER: \n");
      cbi();
   }
   cbi();
   return 1;
}
int main(){
    
    double P, R, T;
    char x;

    printf("Hello. This is an interest calculator, press Enter to continue: \n");
    getchar();

    printf("\n");

          
     do{
      dv("Enter Principal amount: \n", &P);
      if(P<=0){
         printf("Invalid input please try again: \n");
      }
     }while(P<=0);


          
     do{
      dv("Enter Rate of interest: \n", &R);
      if(R<=0){
         printf("Invalid input please try again: \n");
      }
     }while(R<=0);
     
          
     do{
      dv("Enter Time(in years): \n", &T);
      if(T<=0){
         printf("Invalid input please try again: \n");
      }
     }while(T<=0);

     

     char c;
     printf("Do you want to compare the Returns?(Y/N): \n");
     scanf(" %c", &c);

     while(c != 'Y' && c != 'N' && c != 'y' && c != 'n'){
      printf("Invalid choice, please try again: ");
      scanf(" %c", &c);
     }

     if(c == 'N' || c == 'n'){

      printf("Enter C to calculate Compound Interest or S to calculate Simple Interst: \n");
     scanf(" %c", &x);
     
     while(x != 'C' && x != 'c' && x != 'S' && x != 's'){
        printf("Invalid choice, please choose C or S:\n\n");
        scanf(" %c", &x);
     }

      if(x == 's' || x == 'S'){
        double amt = SI(P,R,T);
        printf("---Simple Interest---\n");
        printf("Amount after recieving interest: %.2lf\n", amt);
        printf("Interest recieved: %.2lf\n", amt-P);
     }else if(x == 'c' || x == 'C'){
        double amt = CI(P,R,T);
        printf("---Compound Interest---");
        printf("\nAmount atfer recieving interest: %.2lf\n", amt);
        printf("Interest recieved: %.2lf\n", amt-P);
     }
     }else if(c == 'Y' || c == 'y'){
      printf("\n---Comparisions---\n\n");

      double samt = SI(P,R,T);
      double sint = samt - P;
      
      printf("---Simple Interest---");
      printf("\nAmount returns in Simple Interest: %.2lf\n", samt);
      printf("Simple Interest recieved: %.2lf\n", sint);
      
      double camt = CI(P,R,T);
      double cint = camt - P;  
      printf("\n---Compound Interest---\n");    
      printf("\nAmount return in Compound Interest: %.2lf\n", camt);
      printf("Compounded Interest recieved: %.2lf\n", cint);
      double diff = cint - sint;
      printf("\nDifference in returns: %.2lf\n", fabs(diff));
     }
    return 0;
}
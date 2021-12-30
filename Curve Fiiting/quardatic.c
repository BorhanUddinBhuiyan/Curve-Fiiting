#include<stdio.h>
#include<math.h>
// ...........FUNCTION PROTOTYPE....................
void covertUpperTriangle(float a[3][4],int n);
void applyBackSubstitution(float a[3][4],float value[],int n);
int main(int argc, char const *argv[])
{
    int n;
    float sumX=0,sumX2=0, sumX3=0,sumX4=0,sumY=0,sumXY=0,sumX2Y=0, value[3];
    // ..........INPUT...........................
    printf("Enter number of data observation: ");
    scanf("%d",&n);
    float x[n],y[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter X[%d] for %d observation:  ",i+1,i+1);
        scanf("%f",&x[i]);
        printf("Enter y[%d] for %d observation:  ",i+1,i+1);
        scanf("%f",&y[i]);
    }
    //.............COMPUTATION....................
    for (int i = 0; i < n; i++)
    {
        sumX+=x[i];
        sumX2+=pow(x[i],2);
        sumX3+=pow(x[i],3);
        sumX4+=pow(x[i],4);
        sumY+=y[i];
        sumXY+=x[i]*y[i];
        sumX2Y+=x[i]*x[i]*y[i];
    }
    printf("\nSummation values:");
    printf("\nsumx=%.2f\nsumy=%.f\nsumxy=%.2f\nsumX2=%.2f\nsumX3=%.2f\nsumX4=%.2f\nsumX2Y=%.2f\n",sumX,sumY,sumXY,sumX2, sumX3,sumX4,sumX2Y);
     // ...................CREATE AUGMENTED MATRIX .................
    float Agu_matrix[3][4]={n,sumX,sumX2,sumY,
                            sumX,sumX2,sumX3,sumXY,
                            sumX2,sumX3,sumX4,sumX2Y};
    printf("\nAugmented Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%.2f ",Agu_matrix[i][j]);
        printf("\n");
    }  
    printf("\n");
    // APPLYING GUASS ELIMINATION METHOD TO FIND 'a','b' AND 'c'
     covertUpperTriangle(Agu_matrix,n);
     applyBackSubstitution(Agu_matrix, value, n);  
     printf("a=%.2f\nb=%.2f\nc=%.2f\n",value[0],value[1],value[2]);
    // ............OUTPUT...................................
    printf("So The Quadratic Equation: Y = %.2f + %.2fX +%.2fX^2",value[0],value[1],value[2]);
    return 0;
}
//Converts the Augmented matrix to Upper Triangular Matrix form
 void covertUpperTriangle(float a[3][4],int n){
     for (int i = 0; i < n; i++) //This loop is for reference row or common row
     {
         for (int j = 0; j < n; j++) //this loop is to find substracted row
         {   
             float ratio=0;
             if(j>i){
                 ratio=a[j][i]/a[i][i];
                 for (int k = 0; k < n+1; k++)
                 {
                     a[j][k]-=ratio*a[i][k];
                 }
                 printf("Intermediate forms:\n");
                 for(int x=0;x<n;x++)
                 {
                 for(int y=0;y<n+1;y++)
                     printf("%.2f ",a[x][y]);
                 printf("\n");   
                 }
                 printf("\n");   
             }
         }      
     }  
 }
 //Performs Back Substitution to find values of Unknowns
 void applyBackSubstitution(float a[3][4],float value[],int n){
     float sum=0;
     value[2]=a[2][3]/a[1][2];
     for (int i = n-2; i >= 0; i--)
     {
         sum=0;
         for (int j = i+1; j < n; j++)
         {
             sum+=a[i][j]*value[j];
             value[i]=(a[i][n]-sum)/a[i][i];
         }      
     }  
 }
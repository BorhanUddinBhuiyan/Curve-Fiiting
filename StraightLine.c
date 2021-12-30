#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    float sum_X=0, sum_Y=0, sum_XY=0, sum_X2=0,a,b;
    // Input .............................
    printf("Enter number of obersevations: ");
    scanf("%d", &n);
    float x[n],y[n];
    for (int i = 0; i < n; i++){
        printf("Enter of X[%d] for observation %d: ",i+1,i+1);
        scanf("%f",&x[i]);
        printf("Enter of Y[%d] for observation %d: ",i+1,i+1);
        scanf("%f",&y[i]);
    }
    // Calculating Required Sum...........
    for (int i = 0; i < n; i++)
    {
        sum_X=sum_X + x[i];
        sum_Y=sum_Y + y[i];
        sum_XY=sum_XY + x[i]*y[i];
        sum_X2=sum_X2+x[i]*x[i];
    }   
    //    Form normal equations:
    //    ∑y = na + b ∑x ---------------------(1)
    //    ∑xy = a∑x + b∑x2--------------------(2)

    // Here (1)*∑x - (2)*n
    //    b = (n * sumXY - sumX * sumY)/(n*sumX2 - sumX * sumX)
    //    a = (sumY - b*sumX)/n
    b=(n*sum_XY-sum_X*sum_Y)/(n*sum_X2-sum_X*sum_X);
    a=(sum_Y-b*sum_X)/n;
    
     // Displaying value of a and b 
    printf("Values are: a=%0.2f and b = %0.2f",a,b);
    printf("\nEquation of linear curve is: Y = %0.2f + %0.2fX",a,b);
    return 0;
}

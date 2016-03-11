#include <stdio.h>

double a,b,c,d,wert=0;

double berechnen(double a, double b, double c, double d){

    double masche [2][2] = {{a,b},{c,d}};
    double knoten [2][2] = {{a,b},{c,d}};



    for (int i=0;i<2;i++)
        {
        for (int j=0;j<5;j++)
            {
                printf("%d,%d,%f\n",i,j,wert);
                wert = wert + masche [i][j];
            }
        }
    return wert;
    }

int main(void)
{

    printf("%f\n",berechnen(1,2,3,4));


    return 0;
}


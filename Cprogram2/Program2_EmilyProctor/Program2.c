#include <stdio.h>

static int Ways2PayNCents(int n)
{   
    printf("Possible Combinations of Scoring Plays:\n");
    int num_ways = 0;
    int TD, FG, safety, TD_2pt, TD_FG;
    for (TD_2pt = 0; TD_2pt <= n/8; TD_2pt++)
    {
        for (TD_FG = 0; TD_FG <= n/7; TD_FG++)
        {
            for (TD = 0; TD <= n/6; TD++)
            {
                for (FG = 0; FG <= n/3; FG++)
                {
                    for (safety = 0; safety <= n/2; safety++) 
                    {
                        int total = TD_2pt * 8 + TD_FG * 7 + TD * 6 + FG * 3 + safety * 2;
                        if (total == n) {
                            num_ways += 1;
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", TD_2pt, TD_FG, TD, FG, safety);
                        } else if (total > n){
                            break;
                        }  
                    }
                }                
            }
        }
    }
    return num_ways;            
}

int main ()
{
    int value;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &value);
    while (value != 0 && value != 1) {
        Ways2PayNCents(value);
        printf("\nEnter the NFL score: ");
        scanf("%d", &value);
    }
    return 0;
}

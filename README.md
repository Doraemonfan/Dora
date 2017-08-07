#include <stdio.h>

int main(void)
{
    int n[6][2];
    for(int i = 0; i < 6; i++)
    {
        scanf("%d %d", &n[i][0], &n[i][1]);
        if(n[i][0] < n[i][1])
        {
            int temp = n[i][0];
            n[i][0] = n[i][1];
            n[i][1] = temp;
        }
    }
    for(int i = 0; i < 5; i++)
        for(int j = i; j < 6; j++)
        {
            if(n[i][0] < n[j][0] ||
               (n[i][0] == n[j][0] && n[i][1] < n[j][1]))
            {
                int temp1 = n[i][0], temp2 = n[i][1];
                n[i][0] = n[j][0]; n[i][1] = n[j][1];
                n[j][0] = temp1; n[j][1] = temp2;
            }
        }
    if(n[0][0] == n[1][0] && n[0][0] == n[2][0] &&
       n[0][0] == n[3][0] && n[5][1] == n[4][1] &&
       n[5][1] == n[3][1] && n[5][1] == n[2][1] &&
       n[0][1] == n[1][1] && n[0][1] == n[4][0] &&
       n[0][1] == n[5][0]) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");

    return 0;
}

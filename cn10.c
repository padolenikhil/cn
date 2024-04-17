#include<stdio.h>
int dist[50][50], temp[50][50], n, i, j, k, x;

void dvr() {
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    temp[i][j] = k;
                }

    for(i=0; i<n; i++) {
        printf("\n\n State value for router %d is \n", i+1);
        for(j=0; j<n; j++)
            printf("\t\n node %d via %d distance %d", j+1, temp[i][j]+1, dist[i][j]);
    }
    printf("\n\n");
}

int main() {
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the distance matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            scanf("%d",&dist[i][j]);
            temp[i][j]=j;
        }

    dvr();

    printf("Enter value of i & j:");
    scanf("%d",&i);
    scanf("%d",&j);
    printf("Enter the new cost");
    scanf("%d",&x);
    dist[i][j]=x;

    printf("After update\n\n");
    dvr();

    return 0;
}

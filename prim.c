#include <stdio.h>
// #include "prim.h"

int i,j,n,cost[10][10],temp,sum;

int prim(){
  int lowest_cost = 100,two_points_lowest_cost[10]={0};
  int visited[10] = {0};
  
  //  two_points_lowest_cost[0] = 100;
  for(i=1;i<n;i++){
    two_points_lowest_cost[i] = cost[0][i];
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(!visited[j] && i!=j && two_points_lowest_cost[i] > cost[i][j]){
        two_points_lowest_cost[i] = cost[i][j];
      }
    }
    visited[j]=1;
    sum += two_points_lowest_cost[i];
    
    if(!visited[j] && two_points_lowest_cost[j] > cost[i][j]){
      two_points_lowest_cost[j] = cost[i][j];
    }
  }

  printf("The lowest cost is : %d \n", sum);
  for(i=0;i<n;i++){
    printf("%d, ",two_points_lowest_cost[i]);
  }
  printf("\n");
    
  return 0;
}

int main(){
  
  int i, j;
  printf("Enter the number of vertex : ");
  scanf("%d",&n);    // n is not allowed. 
  
  printf("Enter the cost of edges in Matrix form : ");
  
  for(i=0;i<n;i++){
    for(j=1+i;j<n;j++){
      scanf("%d",&cost[i][j]);
      cost[j][i] = cost[i][j];
    }
  }

  printf("The matrix is : \n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%10d",cost[i][j]);
    }
    printf("\n");
  }
  
  prim();
  return 0;
}


// Since the Matrix is symmetry, and main diagonal are zeros, so you just need to 
// provide the value of all the entries above the main diagonal

/* Enter the number of vertex : 5 */
/* Enter the cost of edges in Matrix form : 1 10 7 4 2 5 3 7 2 8 */
/* The matrix is :  */
/*          0         1        10         7         4 */
/*          1         0         2         5         3 */
/*         10         2         0         7         2 */
/*          7         5         7         0         8 */
/*          4         3         2         8         0 */
/* The lowest cost is : 10  */
/* 0, 1, 2, 5, 2,  */

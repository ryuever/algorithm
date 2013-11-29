#include <stdio.h>
#include <stdlib.h>   // malloc method.
#include "preference.h"
#include <string.h>

static node *event;
static path *recommendation_path;

// should initialize node first.
void init_node(){
  int sz;
  sz = (MAX_NODE+1)*sizeof(node);
  event = (node*)malloc(sz);
}

void recommendation(int time_divisions, int numbers){
  int temp,temp2;
  int value[20] = {0};

  int path[20][10];
  memset(path,0,sizeof path);
  
  int i,j,k;
  int time_end = time_divisions+2;
  // compute the maximum sum of preference when you come to time i;
  // i is started from 1;
  for(i=2;i<= time_end;i++){
    
    // iterate over all of the events.
    for(j=0;j< numbers;j++){
      // if an event is ending up to time i; then we will try to update value[i]
      if(event[j].end == i){
        temp2 = (&event[j])->previous;
        temp = event[j].preference + value[event[j].previous];
        
        if(temp > value[i]){
          // copy the starting and ending node from temp2 to current i;

          for(k=0;k<10;k++){
            if(!path[temp2][k]){
              path[i][k++] = temp2;
              path[i][k] = i;          // should include yourself.
              break;
            }
            path[i][k] = path[temp2][k];
          }
          value[i] = temp;
        }
      }
    }

    // comparing the value of current time i with this of previous time. make sure 
    // the value is always not less than the previous one.
    if(value[i] < value[i-1]){
      value[i] = value[i-1];
      for(k=0;k<10;k++)
        path[i][k] = path[i-1][k];
    }
  }
  
  // because we have time_divisions numbers of time segment, and also it is started 
  // from 1, so the last one will be time_divisions + 2;
  printf("value[time_end] : %d \n", value[time_end]);
  printf("The recommendation path is : \n");
  for (i = 0; i < 10; ++i){
    if(!path[time_end][i])
      break;
    if(i%2){
      printf("%2d \n" , path[time_end][i]);
    }else
      printf("%2d -> " , path[time_end][i]);
  }
  printf("\n");
}

int main(){

  init_node();
  int numbers,i=0,time_divisions;
  
  printf("Enter the number of time division : ");
  scanf("%d", &time_divisions);

  printf("Enter the numbers of event : ");
  scanf("%d", &numbers);

  for(i=0;i<numbers;i++){
    scanf("%d %d %d", &event[i].previous,&event[i].end,&event[i].preference);
  }

  for(i=0;i<numbers;i++){
    // don't write to event[i]->previous.
    printf("E[%d] : %5d %5d %5d \n", i ,event[i].previous, event[i].end ,event[i].preference); 
  }
  
  recommendation(time_divisions,numbers);
}




// test
/* Enter the number of time division : 8 */
/* Enter the numbers of event : 10 */
/* 1 3 2 */
/* 2 5 4 */
/* 3 4 2 */
/* 3 6 5 */
/* 4 6 2 */
/* 5 7 1 */
/* 5 8 4 */
/* 6 8 3 */
/* 6 9 4 */
/* 7 9 3 */

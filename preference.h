#ifndef _PREFERENCE_H
#define _PREFERENCE_H

#define MAX_NODE 10
#define MAX_PATH 9

typedef int bool;
#define true 1
#define false 0


typedef struct node{
  int previous;
  int end;
  int preference;
} node;

typedef struct path{
  int previous[10];
  int end;
}path;

#endif

#include <stdio.h>
#include <stdlib.h>
int main()
{ int Numof_Nodes,Numof_Edges,i,j,n1,n2,w;
  int Arr_Nodes[1000000];
   int Arr_Edges[1000000]={0};
    scanf("%d" "%d",&Numof_Nodes,&Numof_Edges);
    for(i=0;i<Numof_Edges*2;i=i+2){
        scanf("%d" "%d" "%d",&n1,&n2,&w);
        Arr_Nodes[i]=n1;
        Arr_Nodes[i+1]=n2;
        Arr_Edges[n2]=Arr_Edges[n2]+1;
        Arr_Edges[n1]=Arr_Edges[n1]+1;
    }
for(i=0;i<Numof_Nodes;i++){
    printf("%d\n",Arr_Edges[i]);
}
}

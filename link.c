#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void main(){
    printf("Enter the size of each block\n");
    int block_size;
    scanf("%d",&block_size);
    int file[100][100],file_size[100];
    int n=0;
    int blocks_req[100];
    int i,j;
    int ch;
    int temp;
    int vis[500];
    srand(time(0));
    for(i=0;i<500;i++)
	{vis[i]=0; }
     while (1){
        printf("Enter choice-\n1.New file\n2.Display files\n3.Exit\n");
        scanf("%d",&ch);
        if (ch==1){
            printf("Enter file size\n");
            scanf("%d",&file_size[n]);
            blocks_req[n]=ceil((double)file_size[n]/(double)block_size);
            printf("Number of blocks required are %d\n",blocks_req[n]);
            //printf("Enter the %d blocks where the file should be stored\n",blocks_req[n]);
            for (i=0;i<blocks_req[n];i++){
                
                file[n][i]=rand()%500;
                
            }
            n++;
            printf("File allocated\n");
        }
        else if (ch==2){
            printf("File number\tFile size\tFile blocks allocated\n");
            for (i=0;i<n;i++){
                printf("%d\t\t%d\t\t",i+1,file_size[i]);
                for (j=0;j<blocks_req[i];j++){
                    if (j!=blocks_req[i]-1){
                        printf("%d->",file[i][j]);

                    }
                    else
                    {
                        printf("%d\n",file[i][j]);
                    }
                    
                    
                }
            }
        }
        else if (ch==3){
            printf("\nExited successfully\n");
            return;
        }
     }
}

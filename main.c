/*EMRE ERÝNÇ*/
/*1306150016*/
/*Date: .05.2017*/
/*Development Environment : CodeBlocks 16.01*/

#include <stdio.h>
#include <stdlib.h>

int eat(char habitat[10][10],int i,int j,char bakteriaToEat1,char bakteriaToEat2){
    int count;
    char bakterias[4]={'A','B','C','D'};

    if(bakteriaToEat1==' '){
        for(count=0;count<4;count++){
            if(habitat[i][j]==bakterias[count]){
                if((habitat[i+1][j]=='-' || habitat[i+1][j]==bakteriaToEat1) && (i+1)<10){
                        habitat[i+1][j]=bakterias[count];
                }
                if((habitat[i][j+1]=='-' || habitat[i][j+1]==bakteriaToEat1) && (j+1)<10){
                        habitat[i][j+1]=bakterias[count];
                }
                if((habitat[i-1][j]=='-' || habitat[i-1][j]==bakteriaToEat1) && (i-1)>=0){
                    habitat[i-1][j]=bakterias[count];
                }
                if((habitat[i][j-1]=='-' || habitat[i][j-1]==bakteriaToEat1) && (j-1)>=0){
                    habitat[i][j-1]=bakterias[count];
                }
            }
        }
    }
    else{
        for(count=0;count<4;count++){
            if(habitat[i][j]==bakterias[count]){
                if((habitat[i+1][j]=='-' || habitat[i+1][j]==bakteriaToEat1 || habitat[i+1][j]==bakteriaToEat2) && (i+1)<10){
                        habitat[i+1][j]=bakterias[count];
                }
                if((habitat[i][j+1]=='-' || habitat[i][j+1]==bakteriaToEat1 || habitat[i][j+1]==bakteriaToEat2) && (j+1)<10){
                    habitat[i][j+1]=bakterias[count];
                }
                if((habitat[i-1][j]=='-' || habitat[i-1][j]==bakteriaToEat1 || habitat[i-1][j]==bakteriaToEat2) && (i-1)>=0){
                    habitat[i-1][j]=bakterias[count];
                }
                if((habitat[i][j-1]=='-' || habitat[i][j-1]==bakteriaToEat1 || habitat[i][j-1]==bakteriaToEat2) && (j-1)>=0){
                    habitat[i][j-1]=bakterias[count];
                }
            }
        }
    }
    return habitat[10][10];
}

int main()
{
    FILE *dataFile;
    int count,i,j,m,turn,A_Count=0,B_Count=0,C_Count=0,D_Count=0;
    char bakteria;
    char habitat[10][10]={{'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-','-'}};
    int A_Coordinates[100][2]={{'-','-'}};
    int B_Coordinates[100][2]={{'-','-'}};
    int C_Coordinates[100][2]={{'-','-'}};
    int D_Coordinates[100][2]={{'-','-'}};

    if((dataFile = fopen("data.dat","r+"))==NULL){
        printf("File could not opened..\n");
    }
    else{
        /*read habitat coordinates from file*/
        for(count=0;count<10;count++){
            fscanf(dataFile,"%c%d%d\n",&bakteria,&i,&j);
            habitat[i][j]=bakteria;
        }
    }
    printf("Please enter what you want to turn habitat : ");
    scanf("%d",&turn);
    /*Write original habitat*/
    printf("\tStarting with\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c  ",habitat[i][j]);
        }
        printf("\n");
    }

    for(count=0;count<turn;count++){
        /*Read bakterias coordinates*/
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(habitat[i][j]=='A'){
                    A_Coordinates[A_Count][0]=i;
                    A_Coordinates[A_Count][1]=j;
                    A_Count++;
                }
                if(habitat[i][j]=='B'){
                    B_Coordinates[B_Count][0]=i;
                    B_Coordinates[B_Count][1]=j;
                    B_Count++;
                }
                if(habitat[i][j]=='C'){
                    C_Coordinates[C_Count][0]=i;
                    C_Coordinates[C_Count][1]=j;
                    C_Count++;
                }
                if(habitat[i][j]=='D'){
                    D_Coordinates[D_Count][0]=i;
                    D_Coordinates[D_Count][1]=j;
                    D_Count++;
                }
            }
        }
        A_Count=0;B_Count=0;C_Count=0;D_Count=0;
        /*Read coordinates from A_Coordinates write to habitat*/
        for(m=0;m<100;m++){
            if(A_Coordinates[m][0]!=45){
                i=A_Coordinates[m][0];
                j=A_Coordinates[m][1];
                eat(habitat,i,j,'B','C');
            }
        }
        /*Read coordinates from B_Coordinates write to habitat*/
        for(m=0;m<100;m++){
            if(B_Coordinates[m][0]!=45){
                i=B_Coordinates[m][0];
                j=B_Coordinates[m][1];
                eat(habitat,i,j,'C','D');
            }
        }
        /*Read coordinates from C_Coordinates write to habitat*/
        for(m=0;m<100;m++){
            if(C_Coordinates[m][0]!=45){
                i=C_Coordinates[m][0];
                j=C_Coordinates[m][1];
                eat(habitat,i,j,'D',' ');
            }
        }
        /*Read coordinates from D_Coordinates write to habitat*/
        for(m=0;m<100;m++){
            if(D_Coordinates[m][0]!=45){
                i=D_Coordinates[m][0];
                j=D_Coordinates[m][1];
                eat(habitat,i,j,'A',' ');
            }
        }
        /*Write to screen*/
        printf("\n\n\t%d. Turn\n",count+1);
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                printf("%c  ",habitat[i][j]);
            }
            printf("\n");
        }
    }
    fclose(dataFile);
    return 0;
}

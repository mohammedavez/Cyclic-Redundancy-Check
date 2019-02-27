#include<stdio.h>
#include<conio.h>
int *remainder1(int dataword[],int DW_length,int G_length,int generator[]);
int main(){
    int DW_length,G_length,i,j,k,crc,zetobaddf,zetobaddl,value=0,check,error_pos,dup[100],count=0;
    int *last;
    int *rem;
 static int dataword[100],generator[100];
    clrscr();
    printf("Enter the length of the data\n");
    scanf("%d",&DW_length);
    printf("Enter the dataword\n");
    for(i=0;i<DW_length;i++){
	scanf("%d",&dataword[i]);
    }
    printf("Enter the length of the generator\n");
    scanf("%d",&G_length);
    printf("Enter the generator\n");
    for(i=0;i<G_length;i++){
	scanf("%d",&generator[i]);
    }
    printf("Enter CRC 12/16\n");
    scanf("%d",&crc);
	zetobaddf=(crc+1)-DW_length;
	zetobaddl=G_length-1;
	for(i=0;i<zetobaddf;i++){
	    for (j= DW_length - 1; j >= (i+1)- 1; j--)
		     dataword[j+1] = dataword[j];

		    dataword[i] = value;
		    DW_length++;

		}

    for(i=0;i<zetobaddl;i++){
	DW_length++;
	dataword[DW_length]=value;
	   }
    printf("\nDataword:");
    for(i=0;i<DW_length;i++){
	printf("%d",dataword[i]);
    }
    for(i=0;i<DW_length;i++){
	dup[i]=dataword[i];
    }
   last=remainder1(dup,DW_length,G_length,generator);
   printf("\nTransmitted Data:\n");
   k=0;
   for(i=DW_length-(G_length-1);i<=DW_length-1;i++){
       dataword[i]=last[k];
       k++;
   }

   for(i=0;i<DW_length;i++){
       printf("%d",dataword[i]);
   }

    printf("\nIf any Error in Data Transmission(Enter '1' for Yes or '0' for No)?:");
    scanf("%d",&check);
    if(check==1){
	printf("Error generated in which bit position in data?:");
	scanf("%d",&error_pos);
	if(dataword[error_pos-1]==0){
	    dataword[error_pos-1]=1;
	}
	else{
	    dataword[error_pos-1]=0;
	}
	printf("Received Data:");
	for(i=0;i<DW_length;i++){
	    printf("%d",dataword[i]);
	}

      rem =  remainder1(dataword,DW_length,G_length,generator);
      printf("\nRemainder:");
	for(i=0;i<G_length-1;i++){
	    printf("%d",rem[i]);
	}
      for(i=0;i<G_length-1;i++){
	  if(rem[i]==0){
	      count++;
	  }
      }
      if(count==(G_length-1)){
	  printf("\nResult:No Error in data");
      }else{
	  printf("\nResult:Data received with error");
      }
    }
    else{
	 for(i=0;i<DW_length;i++){
	dup[i]=dataword[i];
    }
	 printf("\nReceived Data:");
	 for(i=0;i<DW_length;i++){
	    printf("%d",dataword[i]);
	}
      rem=remainder1(dup,DW_length,G_length,generator);
      printf("\nRemainder:");
      for(i=0;i<G_length-1;i++){
	    printf("%d",rem[i]);
	}
      for(i=0;i<G_length-1;i++){
	  if(rem[i]==0){
	      count++;
	  }
      }
      if(count==(G_length-1)){
	  printf("\nResult:No Error in data");
      }else{
	  printf("\nResult:Data received with error");
      }
    }
    getch();
    return 0;
}
int *remainder1(int dataword2[],int DW_length2,int G_length2,int generator2[]){

    int i,j,k,z;
    static int pass[100];
    z=(DW_length2-G_length2)+1;
    for(i=0;i<z;i++){
	if(dataword2[i]==0){
	    continue;
	}else{
	    for(j=0,k=i;j<G_length2;j++,k++){
		if(dataword2[k]==1 && generator2[j]==1 ){
		    dataword2[k]=0;
		}
		else if(dataword2[k]==0 && generator2[j]==0 ){
		    dataword2[k]=0;
		}
		else if(dataword2[k]==1 && generator2[j]==0 ){
		    dataword2[k]=1;
		}
		else if(dataword2[k]==0 && generator2[j]==1 ){
		    dataword2[k]=1;
		}
	    }
	}
    }

    k=0;
	    for(i=DW_length2-(G_length2-1);i<=DW_length2-1;i++){
		    pass[k]=dataword2[i];
		    k++;
		}
    return pass;
}

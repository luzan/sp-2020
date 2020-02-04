#include<stdio.h>
#include<conio.h>
#include<string.h>
 
void main()
{
  int i,j,k,pgmaddr,csaddr,cslth=0,z,addr1,l1;
  char line[50],name[10],len[10],la[10],addr[10];
  FILE *fp1;
 
  printf("Enter the starting address\n");
  scanf("%d",&pgmaddr);
  csaddr=pgmaddr;
  for(k=0;k<2;k++)
  {
    if(k==0)
     fp1=fopen("linkin.txt","r");
	if(k==1)
     fp1=fopen("linkin1.txt","r");
	do
	{
		fscanf(fp1,"%s",line);
		if(line[0]=='H')
		{
		  for(i=2,j=0;i<8,j<6;i++,j++)
		  	name[j]=line[i];
		  	
			name[j]='\0';
		
			for(i=16,j=0;i<20,j<5;i++,j++)
		 		len[j]=line[i];
		 		
			len[j]='\0';
			cslth=atoi(len);
			printf("%s\t\t%d\t%s\n",name,csaddr,len);
		}
		else if(line[0]=='D')
		{
		  	i=2;
		 	j=0;
			do{
				do{
					la[j++]=line[i++];
				}while(line[i]!='^');
				
				la[j]='\0';
				j=0;i++;
				do{
					addr[j++]=line[i++];
				} while(line[i]!='^');
				
				i++;
				addr[j]='\0';
				addr1=atoi(addr)+csaddr;
				j=0;
				printf("%s\t\t%d\n",la,addr1);
			} while(line[i]!='\0');
		}
		else if(line[0]=='R'||'T')
			z=0;
		else if(line[0]=='E')
			fclose(fp1);
	}while(!feof(fp1));
	
	csaddr=csaddr+cslth;
	}
	getch();
}

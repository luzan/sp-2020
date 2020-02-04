#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  	FILE *f1,*f2,*f3;
 	int csaddr,progaddr,execaddr,cslen,i,j,k=0,staddr1,staddr2,addr2;
	int modadr,val1,adr2,outadr1,esadr;
  	char outadr[10],adr1[10],name[20],val[10],pname[10],symname[10],adr[10];
  	char l[10],line[80],len[10],staddr[10],addr[10],addr1[10];
	f3=fopen("estab.txt","r");
	f2=fopen("dupout.txt","w");
	

	printf("Enter the starting address\n");
	scanf("%d",&progaddr);
	csaddr=progaddr;
	execaddr=progaddr;
	do
	{
		if(k==0)
			f1=fopen("link2in.txt","r");
		if(k==1)
			f1=fopen("linking2.txt","r");
		do{
		 fscanf(f1,"%s",line);
		if(line[0]=='H'){
			  for(i=9,j=0;i<15,j<6;i++,j++)
			  	addr[j]=line[i];
			  addr[j]='\0';
			  for(i=16,j=0;i<20,j<5;i++,j++)
			  	len[j]=line[i];
			  len[j]='\0';
			  cslen=atoi(len);
		}
		else if(line[0]!='E')
		{
		  do
		    {
		      	fscanf(f1,"%s",line);
		      	if(line[0]=='T')
		      	{
			    	for(i=2,j=0;i<8,j<6;i++,j++)
			       	 staddr[j]=line[i];
			        staddr[j]='\0';
			  		staddr1=atoi(staddr);
			 		staddr2=staddr1+progaddr;
			  		i=12;
					while(line[i]!='$')
					  {
					    if(line[i]!='^')
					    {
					      printf("00%d\t%c%c\n",staddr2,line[i],line[i+1]);
					      fprintf(f2,"00%d\t%c%c\n",staddr2,line[i],line[i+1]);
					      staddr2++;
					      i=i+2;
					     }
					    else
					    i++;
					}
				    fclose(f2);
				}
				else if(line[0]=='M')
				{
				  for(i=13,j=0;line[i]!='$',j<5;i++,j++)
				  name[j]=line[i];
				  name[j]='\0';
				  do
				  {
				    fscanf(f3,"%s%s%s%s",pname,symname,adr,l);
				  	if(strcmp(name,symname)==0)
				  	{
					    for(i=2,j=0;i<8,j<6;i++,j++)
					    	adr1[j]=line[i];
					    adr1[j]='\0';
					  	adr2=atoi(adr1);
					  	adr2=adr2+progaddr;
						f2=fopen("dupout.txt","r");
						fscanf(f2,"%s%s",outadr,val);
						printf("The address after modification\n");
						do
						{
							outadr1=atoi(outadr);
							if(adr2==outadr1)
							{
								val1=atoi(val);
								esadr=atoi(adr);
								modadr=val1+esadr;
								printf("%s\t\t%d\n",outadr,modadr);
							}
							fscanf(f2,"%s%s",outadr,val);
						}while(!feof(f2));
				  	}
				 
				   }while(!feof(f3));
				}
			}while(line[0]!='E');
		}
		else
		{
		  	for(i=2,j=0;i<8,j<6;i++,j++)
		  		addr1[j]=line[i];
		  	addr1[j]='\0';
		 	if(strcmp(addr,addr1)==0)
			{
		 		addr2=atoi(addr1);
				execaddr=csaddr+cslen;
			}
			else
				csaddr=csaddr+cslen;
		}
		fscanf(f1,"%s",line);
		}while(!feof(f1));
		k++;
	}while(k<=2);
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	printf("The exec addr is %d",execaddr);
	getch();
}

#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 char opcode[10],operand[10],label[10],code[10][10],ch; 
 char mnemonic[10][10]={"START","LDA","STA","LDCH","STCH","END"};
 int locctr,start,len,i=0,j=0;
 FILE *fp1,*fp2,*fp3;
 
 fp1=fopen("INPUT.TXT","r");
 fp2=fopen("SYMTAB.TXT","w");
 fp3=fopen("INTERMED.TXT","w");
 fscanf(fp1,"%s%s%s",label,opcode,operand);
 
 if(strcmp(opcode,"START")==0)
  {
   start=atoi(operand);
   locctr=start;
   fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
 else
  locctr=0;
  
 while(strcmp(opcode,"END")!=0)
  {
   fprintf(fp3,"%d",locctr);
   
   if(strcmp(label,"**")!=0)
     fprintf(fp2,"%s\t%d\n",label,locctr);
     
   strcpy(code[i],mnemonic[j]);
   while(strcmp(mnemonic[j],"END")!=0)
    {
     if(strcmp(opcode,mnemonic[j])==0)
     {
      locctr+=3;
      break;
     }
     strcpy(code[i],mnemonic[j]);
     j++;
    }
    
   if(strcmp(opcode,"WORD")==0)
    locctr+=3;
   else if(strcmp(opcode,"RESW")==0)
    locctr+=(3*(atoi(operand)));
   else if(strcmp(opcode,"RESB")==0)
    locctr+=(atoi(operand));
   else if(strcmp(opcode,"BYTE")==0)
    ++locctr;
    
   fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
  
  fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
  
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  
  // SHOWING OUTPUT ON CONSOLE
  printf("\n\nThe contents of Input Table :\n\n");
  fp1=fopen("INPUT.TXT","r");
  ch=fgetc(fp1);
  
  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp1);
   }
   
  printf("\n\nThe contents of Output Table :\n\n\t");
  fp3=fopen("INTERMED.TXT","r");
  ch=fgetc(fp3);
  
  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp3);
   }
   
  len=locctr-start;
  printf("\nThe length of the program is %d.\n\n",len);
  printf("\n\nThe contents of Symbol Table :\n\n");
  fp2=fopen("SYMTAB.TXT","r");
  
  ch=fgetc(fp2);
  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp2);
   }
   
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  getch();
}


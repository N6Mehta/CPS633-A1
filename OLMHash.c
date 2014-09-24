#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void checkuseridlength(char *userid)
 {
	 
	   
	   while(  fgets(userid,32,stdin))
	   { 
	            printf("\n");
	 	
			 if(strlen(userid)  < 4 ) 
		   	{
			printf("userid is not long enough\n");
				int i =0;
				memset(userid,'\0',32);	
		   	}
		   	if(strlen(userid) > 32)
		   	{
			printf("userid is too long\n");
				memset(userid,'\0',32);	
		   	
		  	 }
		  	 else if(strlen(userid) >= 4 && strlen(userid) <= 32)
		  	 {
				break;
		  	 }
	    }
}
		void E(char *in, char *out)
		{
			out[0]=(in[0]&0x80)^(((in[0]>>1)&0x7F)^((in[0])&0x7F));
			out[1]=((in[1]&0x80)^((in[0]<<7)&0x80))^(((in[1]>>1)&0x7F)^((in[1])&0x7F));
			out[2]=((in[2]&0x80)^((in[1]<<7)&0x80))^(((in[2]>>1)&0x7F)^((in[2])&0x7F));
			out[3]=((in[3]&0x80)^((in[2]<<7)&0x80))^(((in[3]>>1)&0x7F)^((in[3])&0x7F));
		}

int main()
{
  	FILE *file;
  	FILE *fileout;
 	 file = fopen("server","r");
	 file = fopen("lol","w");
	 if(file == NULL)
	 {
	    printf("Error opening file");
	    exit(1);
	 }
	 else
	 {
		  printf("Please enter userid:\t");
		  char userid[32];
		  char useridfile[32];
		  char password[12];
		  char fileoutpass[12];
		  int n = 3;//the max attempts allowed
		  int x = 0;
		   
		  checkuseridlength(userid);
		  fgets(useridfile,32,file);
	          
		  if(strcmp(userid,useridfile) == 0)
		  {
		     printf("Your userid is recognized. Please enter current password:\t");
		     fgets(password,12,stdin);
		  }
		  else
		  {
		     printf("Your userid is  not recognized. Please enter new password:\t");
		     fgets(password,12,stdin);
		     
				if( (strlen(password)%4) == 0 )
				{
					
					char pass[4];
					char out[4];
					int i;
					
					for(i=0; i < 4 ; i++)
					{
						pass[i] = password[i];
					}
					printf("\n");
					
					
					E(pass,out);
					memset(pass,'\0',4);
					for(i=0; i < 4 ; i++)
					{
						pass[i] = out[i];
					}
					printf("%s",pass);
				        
				}
		     
		     
		   }
	 }
	
   }
  
   


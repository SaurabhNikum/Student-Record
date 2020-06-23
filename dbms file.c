#include<stdio.h>
#include<conio.h>

void main()
{
 FILE *f,*fp;
 int id,i,fid,idc=0;
 char name[20],city[10],clas[20],ch,grd;
 int b,a,d,v,g,c;


 whil(1){
 {
   printf("\n 1)Add ");
   printf("\n 2)Display ");
   printf("\n 3)Edit ");
   printf("\n 4)Delete");
   printf("\n 5)Search");
   printf("\n 6)Exit ");
   printf("\n\n Enter Your Choice: ");
   scanf("%d",&c);
  }
	switch(c)
	{
	  cas 1: {

		   idc=0;
		   f = fopen("datafile.txt","a+");
		   printf("\n Enter Student roll no. : ");
		   scanf("%d",&id);

		   while((ch= fgetc(f))!=EOF)
		   {
		     fscanf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",&fid ,name,clas, city, &b , &a , &v, &d , &g,&grd);
		     if(fid == id)
		     {
		       idc=1;
		       printf("\n id already exist.Data cannot  be added");
		       getch();
		     }
		   }


		   if(idc != 1)
		   {
		   printf("\n Enter Student name : ");
		   scanf("%s",name);

		   printf("\n Enter Student branch : ");
		   scanf("%s",city);


		   printf("\n Enter Student class : ");
		   scanf("%s",clas);

		   printf("\n Enter marks1 : ");
		   scanf("%d",&b);

		   printf("\n Enter marks2 : ");
		   scanf("%d",&a);

		   printf("\n Enter marks3 : ");
		   scanf("%d",&v);

		   d = (a+b+v);
		   g = ((a+b+v)/3);
		   if(g>90)
		   grd='A';
		   else if(g>=75&&g<=90)
		   grd='B';
		   else if(g>=60&&g<=74)
		   grd='C';
		   else if(g>40&&g<=59)
		   grd='D';
		   else
		   grd='F';
		   if(f == NULL)
		   {
		    printf("\nerror");
		   }
		   else
		   {
		    fprintf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",id ,name,clas, city, b , a , v, d ,g,grd);
		   }
		    printf("\n\nData is Added");
		    getch();

		     fclose(f);
		   }}
		   break;
	 cas 2 :{

		   printf("\nStudent Record are : \n");
		   printf("\nid\tname\tclass\tbranch\tmarks 1\tmarks2\tmarks3\ttotal\tperc\tgrade");
		   f = fopen("datafile.txt","r");
		   if(f == NULL){
			printf("error");
			getch();
			return;
			}
		   else{
			while((ch = fgetc(f))!=EOF)
				printf("%c",ch);
		   }
		   getch();
		   fclose(f);
		 }break;

	 cas 3 :{

		   idc = 0;
		   f = fopen("datafile.txt","a+");
		   fp = fopen("temp.txt","w+");
		   printf("\nEnter roll no. of the student to edit : ");
		   scanf("%d",&i);

		   while((ch = fgetc(f))!=EOF)
		   {
		     fscanf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",&fid ,name,clas, city, &b , &a , &v, &d ,&g,&grd);
		     if(fid == i)
			idc =1;
		   }
		   fclose(f);
		   f = fopen("datafile.txt","r");



		   if((f == NULL) || (fp ==NULL))
		   {
			printf("error");
			getch();
			return;

		   }//if
		   else{
			while((ch= fgetc(f))!=EOF)
			{
			  fscanf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",&id ,name,clas, city, &b , &a , &v, &d ,&g,&grd);
			  if(id == i)
			  {
		   printf("\n Enter Student name : ");
		   scanf("%s",name);

		   printf("\n Enter Student branch: ");
		   scanf("%s",city);

		   printf("\n Enter Student class: ");
		   scanf("%s",clas);


		   printf("\n Enter marks1 : ");
		   scanf("%d",&b);

		   printf("\n Enter marks2 : ");
		   scanf("%d",&a);

		   printf("\n Enter marks3 : ");
		   scanf("%d",&v);

		   d = (a+b+v);
		   g = ((a+b+v)/3);

		   if(g>90)
		   grd='A';
		   else if(g>=75&&g<=90)
		   grd='B';
		   else if(g>=60&&g<=74)
		   grd='C';
		   else if(g>40&&g<=59)
		   grd='D';
		   else
		   grd='F';


			  }//if
			  fprintf(fp,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",id ,name,clas, city, b , a , v, d ,g,grd);

			}//while

		   }//else
			fclose(f);
			fclose(fp);

			remove("datafile.txt");
			rename("temp.txt","datafile.txt");

			if(idc ==1)
			printf("\n\nData is Updated");
			else
			printf("\n\nData does not exist.");
			getch();


		 }break;
	 cas 4 :{

		   idc = 0;
		   f = fopen("datafile.txt","r");
		   fp = fopen("temp.txt","w+");
		   printf("\nEnter roll no of the student to delete : ");
		   scanf("%d",&i);

		   while((ch = fgetc(f))!=EOF)
		   {
		     fscanf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",&fid ,name,clas, city, &b , &a , &v, &d ,&g,&grd);
		     if(fid == i)
			idc =1;
		   }
		    fclose(f);
		   f = fopen("datafile.txt","r");

		   if((f == NULL) || (fp ==NULL))
		   {
			printf("error");
			getch();
			return;

		   }//if
		   else{
			while((ch= fgetc(f))!=EOF)
			{
			  fscanf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",&id ,name,clas, city, &b , &a , &v, &d ,&g,&grd);
			  if(id != i)
			  {
			      fprintf(fp,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d",id ,name,clas, city, b , a , v, d ,g,grd);

			  }//if

			}//while

		   }//else

		   if(idc == 0)
			printf("\n Data does not exist.");
		   else
			printf("\n\nData is deleted");

		   fclose(f);
		   fclose(fp);
		   remove("datafile.txt");
		   rename("temp.txt","datafile.txt");



		   getch();


		 }break;
	 cas 5 : {

			printf("\nStudent Record is : \n");

			idc=0;
			f=fopen("datafile.txt","r+");
			if(f==NULL)
			{
			printf("*** file Error ***");
			getch();

			}
			printf("\nEnter the student roll no:");
			scanf("%d",&i);

			printf("\nid\tname\tclass\tbranch\tmarks 1\tmarks2\tmarks3\ttotal\tperc\tgrade");
			while((ch=fgetc(f))!=EOF)
			{
			  fscanf(f,"\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",&id ,name,clas, city, &b , &a , &v, &d ,&g,&grd);
			  if(i == id)
			  {
			      printf("\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c",id ,name,clas, city, b , a , v, d ,g,grd);
			      idc=1;
			  }//if
			}
			if(idc==0)
			{
				printf("\nData does not exist..");
			}
		   fclose(f);
		   fclose(fp);
		   getch();
		  }break;
	 cas 6 : exit(0);

	}//s
	}//l






}

//Application: EMPLOYEE SYSTEM
//PREPARED BY: Divya Patadiya
//--------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
typedef struct employee{
    int empno;
    char ename[20];
    int bsal;
    int da;
    int hra;
    int ta;
    int pf;
    int loan;
    int gs;
    int ns;
}employee;
//---------------------------------------------------------------------------------------------------------------------------------------------------
void create()
{
    FILE *fp;
    fp=fopen("employee.txt","w+");
    employee *e;
    int n,i;
    printf("Enter How many employees you want:");
    scanf("%d",&n);
    e=(employee*)calloc(n,sizeof(employee));
    for(i=0;i<n;i++)
    {
        printf("Enter Empno:");
        scanf("%d",&e[i].empno);
        printf("Enter Ename:");
        scanf("%s",e[i].ename);
        printf("Enter Basic Salary:");
        scanf("%d",&e[i].bsal);

        e[i].da=e[i].bsal*1.2;
        e[i].hra=e[i].bsal*0.2;
        e[i].ta=e[i].bsal*0.1;
        e[i].gs=e[i].da+e[i].ta+e[i].hra;
        e[i].pf=e[i].gs*0.1;
        e[i].loan=e[i].gs*0.1;
        e[i].ns=e[i].gs-e[i].pf-e[i].loan;
         fwrite(&e[i],sizeof(employee),1,fp);
    }

    fclose(fp);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void display()
{
    employee e;
    FILE *fp;
    fp=fopen("employee.txt","r");
    printf("\n...............................................................................\n");
    printf("\n%-5s%15s%9s%9s%9s%9s%9s%9s","EmpNo","EmpName","BSal","DA","HRA","TA","GS","NSal");
    printf("\n...............................................................................\n");
    while(fread(&e,sizeof(e),1,fp))
    {
        printf("\n%-5d%15s%10d%9d%9d%9d%9d%9d",e.empno,e.ename,e.bsal,e.da,e.hra,e.ta,e.gs,e.ns);
    }
    fclose(fp);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void append()
{
    FILE *fp;
    fp=fopen("employee.txt","a");
    employee *e;
    int n,i;
    printf("Enter How many employees you want:");
    scanf("%d",&n);
    e=(employee*)calloc(n,sizeof(employee));
    for(i=0;i<n;i++)
    {
        printf("Enter Empno:");
        scanf("%d",&e[i].empno);
        printf("Enter Ename:");
        scanf("%s",e[i].ename);
        printf("Enter Basic Salary:");
        scanf("%d",&e[i].bsal);

        e[i].da=e[i].bsal*1.2;
        e[i].hra=e[i].bsal*0.2;
        e[i].ta=e[i].bsal*0.1;
        e[i].gs=e[i].da+e[i].ta+e[i].hra;
        e[i].pf=e[i].gs*0.1;
        e[i].loan=e[i].gs*0.1;
        e[i].ns=e[i].gs-e[i].pf-e[i].loan;
         fwrite(&e[i],sizeof(employee),1,fp);
    }

    fclose(fp);
}
//----------------------------------------------------------------------------------------------------------------------------------------------
void count()
{
    FILE *fp;
    employee e;
    int n;
    fp=fopen("employee.txt","r");
    fseek(fp,1,SEEK_END);
    n=ftell(fp)/sizeof(employee);
    printf("No of Records are = %d",n);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void search()
{
    FILE *fp;
    fp=fopen("employee.txt","r");
    int no,found=0;
    employee e;
    printf("Enter Empno to search:");
    scanf("%d",&no);
    while(fread(&e,sizeof(e),1,fp))
    {
        if(e.empno==no)
        {
            found=1;
            printf("\n...............................................................................\n");
            printf("\n%-5s%15s%9s%9s%9s%9s%9s%9s","EmpNo","EmpName","BSal","DA","HRA","TA","GS","NSal");
            printf("\n...............................................................................\n");
            printf("\n%-5d%15s%10d%9d%9d%9d%9d%9d",e.empno,e.ename,e.bsal,e.da,e.hra,e.ta,e.gs,e.ns);

        }

    }
     if(!found)
            printf("Enter proper empno to search !!!");
    fclose(fp);
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void update()
{
    FILE *fp,*fp1;
    fp=fopen("employee.txt","r");
    fp1=fopen("tmp.txt","w");
    employee e;
    int no,found=0;
    printf("Enter empno to Update:");
    scanf("%d",&no);

    while(fread(&e,sizeof(e),1,fp))
    {
        if(e.empno==no)
        {
            printf("Enter New Ename:");
            scanf("%s",e.ename);
            printf("Enter New Basic Salary:");
            scanf("%d",&e.bsal);

            e.da=e.bsal*1.2;
            e.hra=e.bsal*0.2;
            e.ta=e.bsal*0.1;
            e.gs=e.da+e.ta+e.hra;
            e.pf=e.gs*0.1;
            e.loan=e.gs*0.1;
            e.ns=e.gs-e.pf-e.loan;
            found=1;
        }
        fwrite(&e,sizeof(e),1,fp1);
    }
     fclose(fp1);
     fclose(fp);
    if(found)
    {
        fp=fopen("employee.txt","w");
        fp1=fopen("tmp.txt","r");

        while(fread(&e,sizeof(e),1,fp1))
             fwrite(&e,sizeof(e),1,fp);
                fclose(fp);
                fclose(fp1);
    }
    else
        printf("Records are not Found !!!");

}
//------------------------------------------------------------------------------------------------------------
void del()
{
     FILE *fp,*fp1;
    fp=fopen("employee.txt","r");
    fp1=fopen("tmp.txt","w");
    employee e;
    int no,found=0;
    printf("Enter empno to Delete:");
    scanf("%d",&no);

    while(fread(&e,sizeof(e),1,fp))
    {
        if(e.empno==no)
        {
            found=1;
        }
        else
            fwrite(&e,sizeof(e),1,fp1);
    }
     fclose(fp1);
     fclose(fp);
    if(found)
    {
        fp=fopen("employee.txt","w");
        fp1=fopen("tmp.txt","r");

        while(fread(&e,sizeof(e),1,fp1))
             fwrite(&e,sizeof(e),1,fp);
                fclose(fp);
                fclose(fp1);
    }
    else
        printf("Records are not Found !!!");

}
//--------------------------------------------------------------------------------------------------------------------------------------
void sort_sal_desc_scr()
{
    employee *e,e1;
    FILE *fp;
    int i,j;
    fp=fopen("employee.txt","r");
    fseek(fp,1,SEEK_END);
    int n=ftell(fp)/sizeof(employee);
    e=(employee *)calloc(n,sizeof(employee));
    rewind(fp);
    for(i=0;i<n;i++)
    {
        fread(&e[i],sizeof(e[i]),1,fp);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(e[i].ns<e[j].ns)
            {
                e1=e[i];
                e[i]=e[j];
                e[j]=e1;
            }
        }
    }
    printf("\n%-5s%15s%9s%9s%9s%9s%9s%9s","EmpNo","EmpName","BSal","DA","HRA","TA","GS","NSal");
    printf("\n...............................................................................\n");
    for(i=0;i<n;i++){

            printf("\n%-5d%15s%10d%9d%9d%9d%9d%9d",e[i].empno,e[i].ename,e[i].bsal,e[i].da,e[i].hra,e[i].ta,e[i].gs,e[i].ns);
    }
    fclose(fp);

}


int main()
{
    printf("--------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("%65s","* EMPLOYEE SYSTEM *\n\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("* Before using the application read all the instructions carefully. :\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n\n");

    int ch;
    do{
        printf("\n________________________________________________________________________________________________________________________\n\n");
        printf("* MENU *");
        printf("\n________________________________________________________________________________________________________________________\n\n");
        printf("\n1.CREATE:");
        printf("\n2.DISPLAY:");
        printf("\n3.APPEND:");
        printf("\n4.COUNT:");
        printf("\n5.SEARCH:");
        printf("\n6.UPDATE:");
        printf("\n7.DELETE:");
        printf("\n8.SORT BY SALARY DESC ON SCREEN:");
        printf("\n0.EXIT:");
        printf("\n\n________________________________________________________________________________________________________________________\n\n");

        printf("\n\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: create();break;
            case 2: display();break;
            case 3: append();break;
            case 4: count();break;
            case 5: search();break;
            case 6: update();break;
            case 7: del();break;
            case 8: sort_sal_desc_scr();break;
            case 0: printf("\nThank you for visiting...Good Bye!!!\n");break;
        }

    }while(ch!=0);
    printf("\n----------------         EXIT       -----------------------\n");
    return 0;
}

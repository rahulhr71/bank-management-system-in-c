#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>
int i,j,length=0;
char cr_state[10]="credit";
char de_state[10]="debit";
int main_exit;
void menu();
struct date{
    int month,day,year;

    };

struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char aadhar[12];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date trans;
    struct date withdraw;
    char de_state[20];
    char cr_state[20];
    char remark[8];

    }add,upd,check,rem,transaction,mini;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void match(){
system("cls");
system("color 2");
        printf("\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\t\t\t\t\xB2 PASSWORD MATCH ! \xB2");
     //   printf("\n\t\t\t\t\xB2                  \xB2");
        printf("\n\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
        fordelay(100000000);
}
void mismatch(){
system("cls");
system("color 4");
        printf("\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\t\t\t\t\xB2 WRONG PASSWORD ! \xB2");
     //   printf("\n\t\t\t\t\xB2                  \xB2");
        printf("\n\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");

}
void balance(){
 FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BALANCE INQUIRY  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\nEnter account number:");
    scanf("%d",&check.acc_no);

    while (fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
      {


           if(check.acc_no==add.acc_no){

           printf("\n\t\taccount number: %d",add.acc_no);
           printf("\n\t\tname: %s",add.name);
           printf("\n\t\ttotal balance: %f",add.amt);
           test++;
           }
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");
            }

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void trans(){

    FILE *view,*fp;
    view=fopen("statement.dat","r");
    fp=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MINI STATEMENT  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n Enter account number of customer:");
    scanf("%d",&check.acc_no);


printf("\nACC. NO. \tAMOUNT   \tDATE     \tSTATUS   \tREMARK\n");
    while(fscanf(view,"%d %f %d/%d/%d %s %s",&add.acc_no,&transaction.amt,&mini.trans.day,&mini.trans.month,&mini.trans.year,cr_state,add.remark)!=EOF)
       {   if(check.acc_no==add.acc_no){

           printf("\n%d  \t\t%f   \t%d/%d/%d   \t%s    \t%s",add.acc_no,transaction.amt,mini.trans.day,mini.trans.month,mini.trans.year,cr_state,add.remark);
           test++;
         }
       }
       while (fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
      {

           if(check.acc_no==add.acc_no)
           printf("\n\n\ttotal balance: %f",add.amt);

       }

    fclose(view);
    fclose(fp);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }



}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");


    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\xB1\xB1 Enter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    //printf("\nEnter the account number:");
    //scanf("%d",&check.acc_no);
    check.acc_no=63940;
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
           check.acc_no=add.acc_no+1;

    }
    add.acc_no=check.acc_no;
    printf("\n\xB1\xB1 Enter the name:");
    scanf("%s",add.name);
    printf("\n\xB1\xB1 Enter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
     input:
    printf("\n\xB1\xB1 Enter the age:");
    scanf("%d",&add.age);
    if(add.age<18){
        printf("\nminimum age is 18 years");
         inp:
        printf("\npress 1 for re-enter or 0 for main menu");
        scanf("%d",&main_exit);
        if(main_exit==1)
            goto input;
        else if(main_exit==0)
            menu();
        else{
            printf("\nwrong input ! please enter valid input!");
            getch();
            goto inp;
        }
    }

    printf("\n\xB1\xB1 Enter the address:");
    scanf("%s",add.address);
    inpu:
    printf("\n\xB1\xB1 Enter the aadhar number:");
    scanf("%s",add.aadhar);
     if(strlen(add.aadhar)!=12){
        printf("\ninvalid aadhar number");
        getch();
        goto inpu;

        }
     pho:
    printf("\n\xB1\xB1 Enter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\n\xB1\xB1 Enter the amount to deposit:Rupees ");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);


    fclose(ptr);
    printf("\n\xB1\xB1 Account created successfully! \n account number: %d\n IFSC CODE : BACK6394",add.acc_no);
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL CUSTOMERS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec,*ministatement;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    ministatement=fopen("statement.dat","a+");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TRANSACTION  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\nEnter today date:");
    scanf("%d/%d/%d",&mini.trans.day,&mini.trans.month,&mini.trans.year);


        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                 inpr:
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to depositRupees: ");
                    scanf("%f",&transaction.amt);
                    printf("\n remark:");
                    scanf("%s",mini.remark);

                    add.amt+=transaction.amt;

                    fprintf(ministatement,"%d %f %d/%d/%d %s %s\n",transaction.acc_no,transaction.amt,mini.trans.day,mini.trans.month,mini.trans.year,cr_state,mini.remark);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                    printf("\n\nDeposited successfully! \n available balance is : %f",add.amt);

                }
                else if(choice==2){
                    amount:
                    printf("Enter the amount you want to withdraw: ");
                    scanf("%f",&transaction.amt);
                     if(transaction.amt>add.amt){
                        printf("\n insufficient balance !");
                         mas:
                        printf("\npress 1 for re-enter amount of 0 for main menu");
                        scanf("%d",&main_exit);
                        if (main_exit==1){
                            goto amount;
                        }
                        else if (main_exit==0){
                            menu();
                        }
                        else{
                            printf("invalid input ! ");
                            getch();
                            goto mas;
                        }
                     }
                     printf("\n remark:");
                    scanf("%s",mini.remark);
                    add.amt-=transaction.amt;
                    fprintf(ministatement,"%d %f %d/%d/%d %s %s\n",transaction.acc_no,transaction.amt,mini.trans.day,mini.trans.month,mini.trans.year,de_state,mini.remark);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                    printf("\n\nwithdrowal successfully! \n available balance is : %f",add.amt);

                }
                else{
                    printf("\n\t wrong input ! ");
                    getch();
                    goto inpr;
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   fclose(ministatement);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE CUSTOMER ACCOUNT  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\nEnter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUTOMER DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\nDo you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                 printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUTOMER DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                printf("\n\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \naadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rupees %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {
        printf("\n\nEnter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                 printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUTOMER DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                printf("\n\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \naadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rupees%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rupees.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void close(void)
{
    printf("\n\n\n\n\t\xB2\xB2 This C Mini Project is developed by rahul and saras \xB3\xB2");
    getch();
    }


void menu(void)
{   int choice;
    system("cls");
    system("color 9");
    time_t t;
    time(&t);
     chois:
    printf("\n\t\t\tDATE AND TIME : %s", ctime(&t));
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
     printf("\n\t\t\t\xB2------------------------------------------\xB2");
     printf("\n\t\t\t\xB2    WELCOME TO BANK MANAGEMENT SYSTEM     \xB2");
     printf("\n\t\t\t\xB2------------------------------------------\xB2");
     printf("\n\t\t\t| 1.Create new account                     |");
     printf("\n\t\t\t| 2.For Transactions                       |");
     printf("\n\t\t\t| 3.Balance inquiry                        |");
     printf("\n\t\t\t| 4.Show details of existing customer      |");
     printf("\n\t\t\t| 5.Delete existing customer               |");
     printf("\n\t\t\t| 6.List all customers                     |");
     printf("\n\t\t\t| 7.Mini Statement                         |");
     printf("\n\t\t\t\xB2 8.Exit                                   \xB2");
     printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
     printf("\n\n\t\t\t Enter your Choice:");
     scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:transact();
        break;
        case 3:balance();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:trans();
        break;
        case 8:close();
        break;
        default:
            printf("\n\n\n\t\t\t\tinvalid input");
            getch();
            menu();



    }



}
int main()
{
   char ch[9],c1='R',c2='a',c3='h',c4='u',c5='l',c6='@',c7='1',c8='2',c9='3';
    char user1[10]="admin",user2[10];
    int i,count=0,flag;
    re:
        system("cls");

    printf("\n\n\n\t\t\t----------------------------");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANK LOGIN \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t----------------------------");
    printf("\n\t\t\tUSERNAME :");
    fflush(stdin);
    gets(user2);
    if(strcmp(user1,user2)==0 && count<=3)
        {

        }
        else{
            printf("\n\t\t\t user not available ! please wait ");
            for(i=0;i<=3;i++){
            fordelay(100000000);
            printf(".");
            }
            count ++;
            if(count>=3)
            {
                system("color 4");
                printf("\n\t\t\tplease wait for 30 seconds:");
                for(i=0;i<=30;i++){
                fordelay(100000000);
                system("cls");
                printf("\n\t\t\t\twait : %d",i);
                 }
                 count=1;
             }

        goto re;
        }
    printf("\n\t\t\tPASSWORD :");
   for(i=0;i<9;i++){
    ch[i]=getch();
    printf("*");
   }

    if(ch[0]=='R' && ch[1]=='a' && ch[2]=='h' && ch[3]=='u' && ch[4]=='l' && ch[5]=='@' && ch[6]=='1' && ch[7]=='2'&& ch[8]=='3'){

          match();
          system("cls");
        menu();
        }
    else{
         mismatch();
        printf("\n");
        printf("\n\t\t enter 1 to re-enter password,0 to exit:");
        scanf("%d",&flag);
        if(flag==1)
            main();

        else if(flag==0)
            exit(0);

        else
            printf("\n wrong input");


    }
}

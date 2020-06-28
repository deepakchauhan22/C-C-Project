#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int i,j;
struct emp {
  char username[50];
  char password[50];
}manager, staff;
FILE * fp, * ptr;;
  int c = 0, x,f;
  char usern[50], a[100];
  char passwr[50];
  int option;
static int account_no;
struct date{
    int month,day,year;

    };
   
struct {

    char name[60];
    char password[60];
    int acc_no,age;
    char address[60];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    char mini_statement[1000];
   
   
}add,upd,check,rem,transaction;
void mini_st()
{
    char Buff[1000];
    int acc,i,c=0,x,f;
       fp=fopen("details.txt","r");
       printf("\n\t\tEnter account no.:");
       scanf("%d",&acc);
        if(fp!=NULL)
        {
            while(fscanf(fp,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
            {
                if(acc==add.acc_no)
                {
                    printf("\n\t\tDetails of last transactions are: \n");
                    strcpy(Buff,add.mini_statement);
                    break;
                }
            }
        }
        i=0;
        f=0;
        while(Buff[i])
        {
            if(Buff[i]==';')
            {
                c++;
            }
            i++;
        }
        x=0,i=0;
        if(c>5)
        {
             while(Buff[i])
             {
                 if(Buff[i]==';')
                 {
                     x++;
                     if(c-5==x)
                     {
                         i++;
                         break;
                     }
                     
                 }
                 i++;
             }
             while(Buff[i])
                 {
                     if(Buff[i]==';')
                     printf("\n");
                     else
                     printf("%c",Buff[i]);
                     i++;
                 }
        }
        else
        {
            while(Buff[i])
            {
            if(Buff[i]==';')
             printf("\n");
             else
             printf("%c",Buff[i]);
             i++;
            }
        }
       
       
       fclose(fp);
}
void new_acc()

{
    int choice;
    char buf[20];
    char d1[10];
    int c1=0;
    int ddmmyy=0;
     char d2[10];
      char d3[10];
    ptr=fopen("details.txt","a+");
    account_no:
    printf("\n\t\t\t ----- Add Details ------ \n");
    printf("\n\t\tEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    //findind current date
	int dayy, monthh, yyear;
	// time_t is arithmetic time type
	time_t now;
	// time() returns the current time of the system as a time_t value
	time(&now);
	struct tm *local = localtime(&now);
    dayy = local->tm_mday;        	
    monthh = local->tm_mon + 1;   
    yyear = local->tm_year + 1900;	
	
   // current date
   
    if(add.deposit.month== monthh && add.deposit.day== dayy &&add.deposit.year == yyear)
    {
     ddmmyy =1;
    }
    else{
        printf("\n\t\tPlease enter valid date:");
    }
    if(ddmmyy ==1)
    {
    add.acc_no=account_no;
    printf("\n\t\tEnter the username:");
    scanf("%s",add.name);
    printf("\n\t\tEnter the password:");
    scanf("%s",add.password);
    printf("\n\t\tEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\n\t\tEnter the age:");
    scanf("%d",&add.age);
    printf("\n\t\tEnter the address:");
    scanf("%s",add.address);
    printf("\n\t\tEnter the phone number: ");
    scanf("%lf",&add.phone);
   
    if(add.phone>999999999 && add.phone<9999999999)
    c1=1;
    else
    {
    printf("\n\t\tPlease enter valid phone no.");
    }
    if(c1==1){
    printf("\n\t\tEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    gcvt(add.amt,10,buf);
   // sprintf(add.mini_statement,"%f",add.amt);
   strcpy(add.mini_statement,"");
   snprintf (d1, sizeof(d1), "%d",add.deposit.day);
   snprintf (d2, sizeof(d2), "%d",add.deposit.month);
   snprintf (d3, sizeof(d3), "%d",add.deposit.year);
   strcat(add.mini_statement,d1);
   strcat(add.mini_statement,"/");
   strcat(add.mini_statement,d2);
   strcat(add.mini_statement,"/");
   strcat(add.mini_statement,d3);
   strcat(add.mini_statement,"-");
   strcat(add.mini_statement,buf);
   strcat(add.mini_statement,"-CREDITED;");
    fprintf(ptr,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    printf("\n\t\t Customer Added successfully!");
    }
 }
   fclose(ptr);
}

 void add_account() {
        fp=fopen("details.txt","r");
        if(fp!=NULL)
        {
        while(fscanf(fp,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            account_no=add.acc_no;
        }
        account_no++;}
        else{
            account_no=100000;
        }
  printf("\n\t\tAccount number generated successfully! :%d\n", account_no);
}
void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("details.txt","r");
    newrec=fopen("new.txt","w");

    printf("\n\t\tEnter the Account no. for details Updation:");
    scanf("%d",&upd.acc_no);
   while(fscanf(old,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {  
            printf("\n\t\tWhich information do you want to change?\n\t\t1.Address\n\t\t2.Phone\n\n\t\tEnter your choice: [1 for address and 2 for phone]: ");
            scanf("%d",&choice);
           
            if(choice==1)
            {  
                printf("\n\t\tEnter the new address:");
                scanf("%s",upd.address);
              fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
   
                printf("\n\t\tChanges saved! \n");
            }
            else if(choice==2)
                {
                    printf("\n\t\tEnter the new phone number:");
                scanf("%lf",&upd.phone);
              fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,upd.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
   
                printf("\n\t\tChanges saved!");
                }

        }
        else
        {
            fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
      }
       
    }
     
    fclose(old);
    fclose(newrec);
    remove("details.txt");
    rename("new.txt","details.txt");

}

void staff_login()
{
        if ((fp = fopen("staff.txt", "r")) == NULL) {
          if ((fp = fopen("staff.txt", "w")) == NULL) {
            printf("\n\t\tCould not open file\n");
          } else {
              printf("\n\t\t========== ===================== ========== \n\n");
            printf("\n\t\tPlease Sign Up First!\n");
            printf("\t\tEnter UserName:");
            scanf("%s", & staff.username);
            printf("\t\tEnter password:");
            scanf("%s", & staff.password);
            fwrite( & staff, sizeof(staff), 1, fp);
          }
        }
        printf("\n\t\t========== ===================== ========== \n");
        printf("\n\t\tEnter login credentials:\n");
         printf("\t\tEnter UserName:");
        scanf("%s", & usern);
        printf("\t\tEnter password:");
        scanf("%s", & passwr);
        fread( & staff, sizeof(staff), 1, fp);
        if (strcmp(usern, staff.username) == 0 && strcmp(passwr, staff.password) == 0) {
          printf("\n\t\t --------- Welcome %s [Staff] --------- \n",staff.username);
         
          do {
              printf("\n\t\t1. Add new account ");
            printf("\n\t\t2. Create new customer ");
            printf("\n\t\t3. Edit Customer details");
            printf("\n\t\t4. Cash withdrawl and Deposit ");
            printf("\n\t\t5. Fund Transfer");
            printf("\n\t\t6. Balance Enquiry ");
            printf("\n\t\t7. change password ");
            printf("\n\t\t8. mini Statement \n");
            printf("\n\t\t Enter your choice:");
         
            scanf("%d", & option);
            switch (option)

            {
            case 1:
                    add_account();
                    break;
            case 2:
                    new_acc();
                    break;
            case 3:
                edit();
                 break;
            case 4:
                withdraw_deposit();
                break;
            case 5:
                fund_transfer();
                break;
            case 6:
                balance_enquiry();
                break;
            case 7:
                change_password();
                break;
            case 8:
            mini_st();
            break;
            default:
                printf("\n\t\tEnter a valid input\n");
                break;
               
            }
            printf("\n\t\t Type 1 to continue as Staff. Else press any other key: ");
            scanf("%d", & x);
          } while (x == 1);
        } else {
          printf("\n\t\tInvalid credentials");
        }

      }

void manager_login()
{
        if ((fp = fopen("manager.txt", "r")) == NULL) {
          if ((fp = fopen("manager.txt", "w")) == NULL) {
            printf("Could not open file\n");
          } else {
            printf("\n\t\t========== ===================== ========== \n\n");  
            printf("\n\t\tPlease Sign Up First!\n");
            printf("\t\tEnter UserName:");
            scanf("%s", & manager.username);
            printf("\t\tEnter password:");
            scanf("%s", & manager.password);
            fwrite( & manager, sizeof(manager), 1, fp);
          }
        }
        printf("\n\t\t========== ===================== ========== \n");
        printf("\n\t\tEnter login credentials:\n");
        printf("\t\tEnter UserName:");
        scanf("%s", & usern);
        printf("\t\tEnter password:");
        scanf("%s", & passwr);
        fread( & manager, sizeof(manager), 1, fp);
        if (strcmp(usern, manager.username) == 0 && strcmp(passwr, manager.password) == 0) {
          printf("\n\t\t ---------- Welcome %s [Manager]---------- \n", manager.username);
          do {
            printf("\n\t\t1. Add new account");
            printf("\n\t\t2. Cash withdrawl/ Deposit");
            printf("\n\t\t3. Fund Transfer ");
            printf("\n\t\t4. Balance Enquiry ");
            printf("\n\t\t5. change password ");
            printf("\n\t\t6. mini Statement ");
            printf("\n\t\t7. Delete customer ");
            printf("\n\t\t8. Edit customer");
            printf("\n\t\t9. Logout \n");
            printf("\n\t\t Enter your choice:");
         
            scanf("%d", & option);
            switch (option)

            {
            case 1:
                    add_account();
                    break;
           
           
            case 2:
                withdraw_deposit();
                break;
            case 3:
                fund_transfer();
                break;
            case 4:
                balance_enquiry();
                break;
            case 5:
                change_password();
                break;
            case 6:
                mini_st();
                break;
            case 7:
                 delete_customer();
                 break;
            case 8:
                edit();
                break;
            case 9:
                Logout();
                break;
            default:
                printf("\n\t\tEnter a valid input\n");
                break;
               
            }
           
            printf("\n\t\tType 1 to continue as manager. Else press any other key: ");
            scanf("%d", & x);
          } while (x == 1);
        } else {
          printf("\n\t\tNOt valid credentials");
        }

      }
void delete_customer()
{
   
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("details.txt","r");
    newrec=fopen("new.txt","w");

    printf("\n\t\tEnter the account no. of the customer whose account is to be deleted!");
    scanf("%d",&upd.acc_no);
   while(fscanf(old,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {  
               continue;
             

        }
        else
        {
            fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
      }
       
    }
     
    fclose(old);
    fclose(newrec);
    remove("details.txt");
    rename("new.txt","details.txt");
}
void balance_enquiry()
{
    int account;
    printf("\n\t\t========== ===================== ========== \n");
    printf("\n\t\tEnter Account Number to Check Balance: ");
    scanf("%d",&account);
     ptr=fopen("details.txt","r");
            while(fscanf(ptr,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
            {
                if(add.acc_no==account)
                {
                    printf("\t\tAccount holder name: %s \n",add.name);
                    printf("\t\tAccount balance is: %f \n",add.amt);
                    printf("\n\t\t========== ===================== ========== \n");
                    break;
                }
            }
}

void fund_transfer()
{
    char d1[10];
     char d2[10];
      char d3[10];
      int ac1=0,ac2=0;
    char buf[10];
    float fund;
    int account,account2;
    FILE *old,*newrec;
    old=fopen("details.txt","r");
    newrec=fopen("new.txt","a");
    printf("\n\t\tEnter the amount you want to transfer:");
    scanf("%f",&fund);
    printf("\n\t\tEnter the account number from where you want to transfer:");
    scanf("%d",&account);
    printf("\n\t\tEnter the account number to where you want to transfer:");
    scanf("%d",&account2);
   while(fscanf(old,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (account==add.acc_no && add.amt>=fund)
        {  
            snprintf (d1, sizeof(d1), "%d",add.deposit.day);
           snprintf (d2, sizeof(d2), "%d",add.deposit.month);
           snprintf (d3, sizeof(d3), "%d",add.deposit.year);
           strcat(add.mini_statement,d1);
           strcat(add.mini_statement,"/");
           strcat(add.mini_statement,d2);
           strcat(add.mini_statement,"/");
           strcat(add.mini_statement,d3);
           strcat(add.mini_statement,"---------");
             gcvt(fund,10,buf);
            strcat(add.mini_statement,buf);
            strcat(add.mini_statement,"---------DEBITED;");
          fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt-fund,add.deposit.month,add.deposit.day,add.deposit.year);
           ac1=1;
        }
         else if(account2==add.acc_no )
        {
             snprintf (d1, sizeof(d1), "%d",add.deposit.day);
           snprintf (d2, sizeof(d2), "%d",add.deposit.month);
           snprintf (d3, sizeof(d3), "%d",add.deposit.year);
           strcat(add.mini_statement,d1);
           strcat(add.mini_statement,"/");
           strcat(add.mini_statement,d2);
           strcat(add.mini_statement,"/");
           strcat(add.mini_statement,d3);
           strcat(add.mini_statement,"---------");
             gcvt(fund,10,buf);
            strcat(add.mini_statement,buf);
            strcat(add.mini_statement,"---------CREDITED;");
          fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt+fund,add.deposit.month,add.deposit.day,add.deposit.year);
           ac2=1;
        }
        else
        {
            fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    if(ac1!=1)
    {
        printf("\n\t\tAccount no %d doesn't exist",account);
    }
    if(ac2!=1)
    {
        printf("\n\t\tAccount no %d doesn't exist",account2);
    }
    fclose(old);
    fclose(newrec);

    remove("details.txt");
    rename("new.txt","details.txt");


}

// void fund_transfer()
// {
//     char d1[10];
//      char d2[10];
//       char d3[10];
//     char buf[10];
//     float fund, account;
//     FILE *old,*newrec;
//     old=fopen("details.txt","r");
//     newrec=fopen("new.txt","a");
//     printf("\n\t\tEnter the amount you want to transfer:");
//     scanf("%f",&fund);
//     printf("\n\t\tEnter the account number to which you want to transfer:");
//     scanf("%f",&account);
//   while(fscanf(old,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
//     {
//         if (account==add.acc_no && add.amt>=fund)
//         {  
//             snprintf (d1, sizeof(d1), "%d",add.deposit.day);
//   snprintf (d2, sizeof(d2), "%d",add.deposit.month);
//   snprintf (d3, sizeof(d3), "%d",add.deposit.year);

//   strcat(add.mini_statement,d1);
//   strcat(add.mini_statement,"/");
//   strcat(add.mini_statement,d2);
//   strcat(add.mini_statement,"/");
//   strcat(add.mini_statement,d3);
//   strcat(add.mini_statement,"-");
//              gcvt(fund,10,buf);
//             strcat(add.mini_statement,buf);
//             strcat(add.mini_statement,"-DEBITED;");
//           fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt-fund,add.deposit.month,add.deposit.day,add.deposit.year);
   
//         }

//         else
//         {
//             fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
//         }
//     }
//     fclose(old);
//     fclose(newrec);
//     remove("details.txt");
//     rename("new.txt","details.txt");


// }
void change_password()
{
   
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("details.txt","r");
    newrec=fopen("new.txt","w");

    printf("\n\t\tEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
   while(fscanf(old,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {  
                printf("\n\t\tEnter the new password:");
                scanf("%s",&upd.password);
              fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,upd.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
   
                printf("\n\t\tChanges saved!!!");
             

        }
        else
        {
            fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
       
    }
     
    fclose(old);
    fclose(newrec);
    remove("details.txt");
    rename("new.txt","details.txt");

}
void withdraw_deposit()
{
    char b1[10];
    char b2[10];
      char b3[10];
    char buf[10];
    int account;
    float amount;
    char c;
    FILE *old,*newrec;
    printf("\n\t\t========== ===================== ========== \n");
    printf("\n\t\tEnter W to withdraw and D to Deposit:");
    getchar();
    scanf("%c",&c);
    printf("\n\t\tEnter the Account Number:");
    scanf("%d",&account);
     printf("\t\tEnter the amount:");
    scanf("%f",&amount);
   
      old=fopen("details.txt","r");
    newrec=fopen("new.txt","a");
   
   while(fscanf(old,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(account==add.acc_no)
        {
            if (c=='D')
            {  
               
               snprintf (b1, sizeof(b1), "%d",add.deposit.day);
               snprintf (b2, sizeof(b2), "%d",add.deposit.month);
               snprintf (b3, sizeof(b3), "%d",add.deposit.year);
               strcat(add.mini_statement,b1);
               strcat(add.mini_statement,"/");
               strcat(add.mini_statement,b2);
               strcat(add.mini_statement,"/");
               strcat(add.mini_statement,b3);
               strcat(add.mini_statement,"-");
                gcvt(amount,10,buf);
                strcat(add.mini_statement,buf);
                strcat(add.mini_statement,"-CREDITED;");
               fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt+amount,add.deposit.month,add.deposit.day,add.deposit.year);
           
            }

            else if(c=='W' && add.amt>=amount)
            {
                snprintf (b1, sizeof(b1), "%d",add.deposit.day);
           snprintf (b2, sizeof(b2), "%d",add.deposit.month);
           snprintf (b3, sizeof(b3), "%d",add.deposit.year);
       
           strcat(add.mini_statement,b1);
           strcat(add.mini_statement,"/");
           strcat(add.mini_statement,b2);
           strcat(add.mini_statement,"/");
           strcat(add.mini_statement,b3);
           strcat(add.mini_statement,"-");
           gcvt(amount,10,buf);
            strcat(add.mini_statement,buf);
            strcat(add.mini_statement,"-DEBITED;");
                fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt-amount,add.deposit.month,add.deposit.day,add.deposit.year);
            }
            else
            {
                printf("\n\t\t Invalid input\n");
                break;
            }
        }
        else{
         fprintf(newrec,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.mini_statement,add.password,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }  
    }
    fclose(old);
    fclose(newrec);
    remove("details.txt");
    rename("new.txt","details.txt");


}

void customer_login()
{
int amot;
int p=0;

char new_password[50];
        if ((fp = fopen("details.txt", "r")) == NULL)
        {
           printf("\n\t\tCurrently database is empty\n");
        }
        else
        {     printf("\n\t\t========== ===================== ========== \n");
              printf("\n\t\tEnter Your credentials to login: \n");
              printf("\t\tEnter UserName:");
               scanf("%s", & usern);
               printf("\t\tEnter password:");
               scanf("%s", & passwr);
             while(fscanf(fp,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
                {
                    if (strcmp(usern, add.name) == 0 && strcmp(passwr, add.password) == 0)
                    {
                      printf("\n\t\t --------- Welcome %s [Customer]-------- \n ", add.name);
                      p=1;
                      fclose(fp);
                      break;
                    }
                    else
                    {
                     continue;
                    }
                  }
            if(p!=1){
            printf("\n\t\tIncorrect Credentials");
               
            }
            else
            {
            do {
                  printf("\n\t\t1. Fund Transfer ");
                    printf("\n\t\t2. Balance enquiry ");
                    printf("\n\t\t3. Change Password ");
                    printf("\n\t\t4. Mini Statement ");
                    printf("\n\t\t5. Customer details \n");
                    printf("\n\t\t Enter your choice:");
                    scanf("%d", & option);
            switch (option)
            {
            case 1:
                    fund_transfer();
                     break;
            case 2:
                balance_enquiry();
                break;
            case 3:
            change_password();
            break;
              case 4:
                    mini_st();
                    break;
            case 5:
                view_list();
                break;

              default:
                      printf("\n\t\tWrong choice");
                      break;
          }
 printf("\n\t\t Type 1 to continue as CUSTOMER. Else pres any other key: ");
            scanf("%d", & f);
}while (f == 1);
}
}}
void view_list()
{
    FILE *fp2;
    fp2=fopen("details.txt","r");
    int flag=0;
    printf("\n\t\t========== ===================== ========== \n");
    printf("\n\t\tACC. NO.\tNAME\t\tADDRESS\t\tPHONE\n");

    while(fscanf(fp2,"%d %s %s %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,add.mini_statement,add.password,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
           printf("\n\t\t%6d\t%10s\t\t%10s\t%.0lf \n",add.acc_no,add.name,add.address,add.phone);
           printf("\n\t\t========== ===================== ========== \n");
           flag++;
       }

    fclose(fp2);
    if (flag==0)
        {  
            printf("\n\t\tBlank record as no records found!!\n");}

   
}
void Logout(){
   
    printf("Logged out from session");
}

int main()
{
   
 

  do {
    printf("\033[1;34m");
    printf("\n\n\t\t========== Welcome to INFY Bank ========== \n\n");
    printf("\n\t\t---- Welcome to the Main Menu----\n");
    printf("\n\t\t [1]  Manager Login");
    printf("\n\t\t [2]  Staff Login");
    printf("\n\t\t [3]  Customer Login");
    printf("\n\t\t [4]  Exit \n");
    printf("\n\t\tEnter your choice: ");
   
    scanf("%d", & option);
    switch (option) {
    case 1: manager_login();
            break;
    case 2: staff_login();
             break;
    case 3: customer_login();
             break;
    case 4:
            Logout();
            break;
    default: printf("\n\t\tEntered Wrong Choice");
            break;
    }

    printf("\n\t\tType 1 for main menu.Else press any other key to Log out: ");
    scanf("%d", & c);
    } while (c == 1);

   
        return 0;
}

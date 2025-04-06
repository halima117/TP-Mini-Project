#include <stdio.h>
#include <stdlib.h>

int main();
  //Structure for an account
  typedef struct
  {
 char name[50];
  int account_number;
  char password[20];
  float balance;


   } Account;
 //Array to store accounts
   Account accounts = [MAX_ACCOUNTS];
   //Counter for accounts
   int account_count = 0;
   //Function prototypes
   void create_account();
   void login();
   void deposit_money(int index);
   void transfer_money(int index);
   void check_balance(int index);
   void delete_empty_account();
   void save_to_file();
   void load_from_file();
   }int main()
   int choice;
   //Load existing accounts from file
   load_from_file();
   }while(1)
   printf("\n----------Welcome to Our Bank----------\n");
   printf("1. Create Account\n2.Login to Account\n3. Quit\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);
}switch (choice)
 case 1:
     create_account() ;
     break;
 case 2:
    login();
    break;
 case 3:
    save_to_file();
    ptrintf("Thank your for using our bank system!\n");
    exit(0);
    printf("Invalid choice! Please try again. \n");
    {
        {

          {
   //Function to create an account
   }void create_account()
  } if (account_count >= MAX_ACCOUNTS)
  printf("Bank database is full!\n");
  return;
  {
      printf("Enter Name: ");
      scanf("%s", accounts[account_count].name);
      printf("Enter Account Number: ");
      scanf("%d",&accounts[account_count].account_number);
      printf("Set Password: ")
      scanf("%s", accounts[account_count].password);
      accounts[account_count].balance = 0;
      printf("Account successfully created!\n");
      ++account_count
      save_to_file();
      {
          //Function to login
         } void login()
       int acc_num, i;
       char pass[20];
       printf("\n---Welcome to the Login Page ---\n");
       printf("Enter Account Number: ");
       scanf("%d", &acc_num);
       printf("Enter Password: ");
       scanf("%s" ,pass);
       for(i = 0; i < account_count; i++);}
       if (accounts[i].account_number == acc_num &&)
       strcmp(accounts[i].password, pass) == 0)}
       printf("Login successful!\n");
       int choice;
       while(1)}
       printf("\n1. Deposit Money\n2. Transfer Money\n3. Check Balance\n4. Logout\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
       }switch (choice);
 case 1:
    deposit_money(i);
    break;
 case 2:
    transfer_money(i);
    break;
 case 3:
    check_balance(i);
    break;
 case 4:
    save_to_file();
    return;
    printf("Invalid Account Number or Password!\n");
    {
        //Function to deposit money
        } void deposit_money(int index)
        float amount;
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        }if(amount > 0);
        accounts[index].balance += amount;
        printf("Deposit successful!New balance: %.2f\n",accounts[index].balance)
        }else{
            printf("Invalid amount!\n");
            {
            //Function to transfer money
            }void transfer_money(int index)
            int acc_num, i;
            float amount;
            printf("Enter recipient Account Number: ");
            scanf("&d", &acc_num);
            {for(i = 0; i < account_count; i++)
            if(accounts[i].account_number == acc_num)
            printf("Enter amount to transfer: ");
            scanf("%f", &amount)
            if(amount > 0 &&  accounts[index].balance >= amount)}
            accounts[index].balance -= amount accounts[i].balance += amount;
            printf("Transfer successful! Your new balance:%.2f\n", accounts[index].balance);
            } else {
                printf("Insufficient balance or invalid amount!\n")
                {
                    return;
                        {
                       {
   printf("Recipient account not found!\n");
   {
       //Function to check balance
       }void check_balance(int index)
       printf("Your current balance: %.2f\n" , accounts[index].balance)
       {
      // Function to deleter empty accounts
      }void delete_empty_account()
      for(int i = 0; i < account_count; i++)
    } if (accounts[i].balance == 0)
     }
     for (int j = i; j < account_ count - 1; j++)
        accounts[j] = accounts[j + 1];
     {
         --account_count;
         printf("Deleted empty account successfully.\n");
         //Adjust index
         i--;
         {
             {
          save_to_file();
         {
          //Function to save data to file
          }void save_to_file()
          FILE *file = fopen("accounts.txt", "w");
          } if (!file)
          printf("Error saving data! \n");
          return;
          {
    for(int i = 0; i < account_count; i++)}
    fprintf(file, "%s %d %s %.2f\n", accounts[i].name,accounts[i].account_number,accounts[i].password,accounts[i].balance)
    {
      fclose(file);
      {
      //Function to load data from file
     } void load_from_file()
     FILE *file = fopen("accounts.txt" , "r")
     if(!file)return;
     while(scanf(file, "%s %d %s %f", accounts[account_count].name,&accounts[account_count].account_number, accounts[account_count].password,&accounts[account_count].balance) != EOF)}
     ++account_count;
     {
      fclose(file);
     }



















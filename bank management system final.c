#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct account{
	int accn;
	char name[20];
	char fname[20];
	int age;
	char gender[10];
	char occupation[30];
	int phn1,phn2;
	int cnic1,cnic2,cnic3;
	char acctype[20];
	char dob[20];
	char address[50];
	char email[30];
	char time[30];
	char lastlogin[30];
	char lcredit[30];
	char lwithdraw[30];
	char ltransfer[30];
	int credit;
}a;
int printrandom();
void create_id();
void login();
int avlaccno(int acc);
void details(int acn);
void main_layout();
void lastlogin(int no);
void ilogin();
void credit_time(int ct);
void withdraw_time(int wt);
void transfer_time(int tt);
void clogin(int can);
void delete_account();
int avlname(char s[]);
void credit(int c);
void update(int r);
void trans_history(int th);
void transaction(int n);
void withdraw(int w);
void transfer(int j);
void avlcnicno(int c1,int c2,int c3);
void main()
{
	fflush(stdin);
	main_layout();
	getch();
}
void main_layout()
{
	int choice,cn1,cn2,cn3;
	system("cls");
	fflush(stdin);
	printf("*************************WELCOME TO BANK MANAGEMENT SYSTEM**********************");
	printf("\n\n\n\nPLEASE SELECT FROM THE FOLLOWING OPTIONS");
	printf("\n\n1 : LOGIN");
	printf("\n\n2 : CREATE ID");
	printf("\n\n3 : DELETE ID");
	printf("\n\n4 : REPORT");
	printf("\n\n5 : QUIT");
	printf("\n\n\n\n\n\n\n\nPLEASE INPUT YOUR CHOICE: ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:
		    login();
		    break; 
		case 2:
			create_id();
			break;
		case 3:
			delete_account();
			break;
		case 4:
			system("cls");
			printf("\n\nENTER CNIC NUMBER xxxxx-xxxxxxx-x: ");
			scanf("%d-%d-%d",&cn1,&cn2,&cn3);
			avlcnicno(cn1,cn2,cn3);
			break;	
		case 5:
		    printf("\n\n\n................THANK YOU FOR USING JBH BANKING SYSTEM....................");
			exit(1);
			break;		
	}
}
void create_id()
{
	int m,n,count1,count2;
	int cchoice;
	fflush(stdin);
	system("cls");
	FILE*fp1;
	fp1=fopen("account.txt","a");
	a.accn=printrandom();
	printf("PLEASE INPUT YOUR DETAILS_ _ _ _ _ _ _ _ _ _ _");
	printf("\n\n\nENTER YOUR NAME: ");
	gets(a.name);
	printf("\n\nENTER YOUR FATHER NAME: ");
	gets(a.fname);
	printf("\n\nENTER YOUR GENDER: ");
	gets(a.gender);
	do{
	    printf("\n\nENTER YOUR AGE: ");
	    scanf("%d",&a.age);
	    if(a.age<1){
	    	printf("\nPLEASE ENTER VALID AGE");
		}
	}while(a.age<1);
	printf("\n\nENTER YOUR PHONE NUMBER xxxx-xxxxxxx: ");
    scanf("%d-%d",&a.phn1,&a.phn2);
	printf("\n\nENTER YOUR CNIC NUMBER xxxxx-xxxxxxx-x: ");
	scanf("%d-%d-%d",&a.cnic1,&a.cnic2,&a.cnic3);
	fflush(stdin);
	printf("\n\nENTER ACCOUNT TYPE <savings/current>: ");
	gets(a.acctype);
	printf("\n\nENTER YOUR OCCUPATION: ");
	gets(a.occupation);
	printf("\n\nENTER DATE OF BIRTH <dd/mm/yyyy>: ");
	gets(a.dob);
	printf("\n\n\nENTER YOUR ADDRESS: ");
	gets(a.address);
	printf("\n\nENTER YOUR EMAIL ADDRESS: ");
	gets(a.email);
	do{
	    printf("\n\nCREDIT: ");
	    scanf("%d",&a.credit);
	    if(a.credit<0){
	    	printf("\nPLEASE ENTER VALID AMOUNT");
		}
	}while(a.credit<0);
	fflush(stdin);
	printf("\n\n\n\n\n\n\n\n******************CONGRATULATIONS YOU HAVE SUCCESSFULLY SIGNED UP***************");
	printf("\nYOUR ACCOUNT NUMBER IS : ***%d*** ",a.accn);
    fwrite(&a,sizeof(struct account),1,fp1);
    fclose(fp1);
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&cchoice);
    fflush(stdin);
    if(cchoice==1){
    	clogin(a.accn);
	}
}
void details(int acn)
{
	FILE*fp;
	int s,dchoice;
	fp=fopen("account.txt","r");
    while (fread(&a, sizeof(struct account), 1, fp))
        {
        s = a.accn;
        if (s == acn){
        	system("cls");
            printf("\nACCOUNT NUMBER: %d",a.accn);
            printf("\n\n\nNAME: ");
            puts(a.name);
            printf("\n\nFATHER NAME: ");
            puts(a.fname);
            printf("\nCREDIT: %d",a.credit);
            printf("\n\nGENDER: ");
            puts(a.gender);
            printf("\n\nAGE: %d",a.age);
            printf("\n\nPHONE NUMBER: 0%d-%d",a.phn1,a.phn2);
            printf("\n\nCNIC NUMBER: %d-%d-%d",a.cnic1,a.cnic2,a.cnic3);
            printf("\n\nACCOUNT TYPE: ");
            puts(a.acctype);
            printf("\n\nOCCUPATION: ");
            puts(a.occupation);
            printf("\nDATE OF BIRTH: ");
            puts(a.dob);
            printf("\nADDRESS: ");
            puts(a.address);
            printf("\nEMAIL ADDRESS: ");
            puts(a.email);
            printf("\n\nLAST LOGIN TIME: ");
            puts(a.lastlogin);
            fclose(fp);
        }
    }
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&dchoice);
    fflush(stdin);
    if(dchoice==1){
    	clogin(acn);
	}
}
void login()
{
	fflush(stdin);
	int an,avl,lchoice,schoice,avln;
    char aname[20];
    system("cls");
	printf("\nPLEASE ENTER ACCOUNT HOLDER'S NAME: ");
	gets(aname);
	printf("\nPLEASE ENTER ACCOUNT NUMBER: ");
	scanf("%d",&an);
	avln=avlname(aname);
	avl=avlaccno(an);
	if(avl==0 || avln==0){
		ilogin();
	}else{
		clogin(an);
    }
}
int printrandom() 
{ 
    srand(time(0)); 
	int i,upper=99999,lower=10000,count=1,num; 
    for (i = 0; i < count; i++) { 
        num = (rand() % (upper - lower + 1)) + lower; 
        return num; 
    } 
} 
int avlaccno(int acc)
{
	FILE*fp;
	fp=fopen("account.txt","r");
	while(!feof(fp)){
		fread(&a,sizeof(struct account),1,fp);
		if(acc==a.accn){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}
void ilogin()
{
	int lchoice;
	system("cls");
	    printf("\n\n------INCORRECT ACCOUNT NUMBER OR NAME--------- ");
		printf("\n\n\n1 : CREATE ID");
		printf("\n\n2 : QUIT");
		printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
		scanf("%d",&lchoice);
		fflush(stdin);
		switch(lchoice){
		    case 1: 
		    create_id();
	        break;
   	        case 2:
		    main_layout();
	        break;
        }
}
void clogin(int can)
{
	int schoice;
	system("cls");
	printf("\n\n\n1 : VIEW DETAILS");
    printf("\n\n\n2 : UPDATE PROFILE");
    printf("\n\n\n3 : MONEY TRANSACTION");
    printf("\n\n\n4 : TRANSACTION HISTORY");
    printf("\n\n\n5 : LOGOUT");
    printf("\n\n\n\n\n\nPLEASE SELECT DESIRED OPTION: ");
    scanf("%d",&schoice);
    fflush(stdin);
    switch(schoice){
        case 1:
            details(can);
            break;
        case 2:
		    update(can);
            break;
        case 3:
		    transaction(can);
		    break;
        case 4:
        	trans_history(can);
        	break;
		case 5:
			lastlogin(can);
        	printf("\n\n\n\n***********LOGOUT SUCCESSFUL*************");
        	getch();
            main_layout();
            break;
        }
}
void delete_account()
{
	FILE*fp;
    FILE*fpt;
    int no, s,dchoice;
    system("cls");
    printf("\n\nENTER ACCOUNT NUMBER YOU WANT TO DELETE: ");
    scanf("%d", &no);
    if (avlaccno(no) == 0){
        printf("\n\nACCOUNT IS NOT PRESENT");
        getch();
        main_layout();
	}else{
		printf("\n\nARE YOU SURE YOU WANT TO DELETE THIS ACCOUNT");
		printf("\n\n\n\n\n1: YES\t\t\t\t2: NO");
		scanf("%d",&dchoice);
		fflush(stdin);
		switch(dchoice){
			case 1:               	
                fp = fopen("account.txt", "r");
                fpt = fopen("tempfile", "w");
                while (fread(&a, sizeof(struct account), 1, fp)){
                    s = a.accn;
                    if (s != no){
                        fwrite(&a, sizeof(struct account), 1, fpt);
                    }
                    fclose(fp);
                    fclose(fpt);
                    fp = fopen("account.txt", "w");
                    fpt = fopen("tempfile", "r");
                    while (fread(&a, sizeof(struct account), 1, fpt)){
                        fwrite(&a, sizeof(struct account), 1, fp);
                    }
                    fclose(fp);
                    fclose(fpt);
					system("cls");
					printf("\n\n\n\t\tACCOUNT DELETED\n");
                    getch();
                    main_layout();
                    
                }
                break;
            case 2:
            	main_layout();
            	break;
        }
    }
}
int avlname(char s[])
{
	int result;
	FILE*fp;
	fp=fopen("account.txt","r");
	while(!feof(fp)){
		fread(&a,sizeof(struct account),1,fp);
		result=strcmp(s,a.name);
		if(result==0){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}
void transaction(int n)
{
	int tchoice;
	system("cls");
	printf("\n\nWHAT TYPE OF TRANSACTION DO YOU WANT TO MAKE");
	printf("\n\n1 : WITHDRAW");
	printf("\n\n2 : CREDIT");
	printf("\n\n3 : MONEY TRANSFER");
	printf("\n\n4 : BACK");
	printf("\n\nPLEASE ENTER YOUR CHOICE: ");
	scanf("%d",&tchoice);
	fflush(stdin);
	switch(tchoice){
		case 1:
			withdraw(n);
			break;
		case 2:
			credit(n);
			break;
		case 3:
			transfer(n);
			break;
		case 4:
		    clogin(n);
			break;	
	}
}
void update(int r)
{
	FILE *fpt;
    FILE *fp;
    int s,uchoice,uc;
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        s = a.accn;
        if (s != r){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{
        	system("cls");
            printf("\n\n1 : UPDATE NAME");
	        printf("\n\n2 : UPDATE PHONE NUMBER");
	        printf("\n\n3 : UPDATE CNIC NUMBER");
	        printf("\n\n4 : UPDATE ADDRESS");
            printf("\n\n5 : UPDATE EMAIL ADDRESS");
            printf("\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
            scanf("%d",&uchoice);
            fflush(stdin);
            switch(uchoice){
    	        case 1:
    		        printf("\nENTER NAME: ");
    		        gets(a.name);
    		        break;
    	        case 2:
				    printf("\nENTER PHONE NUMBER xxxx-xxxxxxx: ");
                    scanf("%d-%d",&a.phn1,&a.phn2);
                    break;
	            case 3:    
			        printf("\nENTER CNIC NUMBER xxxxx-xxxxxxx-x: ");
	                scanf("%d-%d-%d",&a.cnic1,&a.cnic2,&a.cnic3);
	                break;
	            case 4:
	                printf("\nENTER ADDRESS: ");
					gets(a.address); 
					break;
				case 5:
				    printf("\nENTER EMAIL ADDRESS: ");
					gets(a.email);
					break;	
	            }
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
    printf("\n\n\n\n\nACCOUNT DETAILS UPDATED SUCCESSFULLY UPDATED");
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&uc);
    if(uc==1){
    	clogin(r);
	}    
}
void lastlogin(int no)
{
	FILE *fpt;
    FILE *fp;
    int t;
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != no){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            struct tm* local; 
            time_t t = time(NULL);
            local = localtime(&t);  
            strcpy(a.lastlogin,asctime(local));
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
}
void credit(int c)
{
	FILE *fpt;
    FILE *fp;
    int t,amount;
    system("cls");
    printf("\n\nENTER AMOUNT YOU WANT TO CREDIT: ");
    scanf("%d",&amount);
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != c){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            a.credit=a.credit+amount;
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
    fflush(stdin);
    credit_time(c);
    printf("\n\n\nAMOUNT CREDITED SUCCESSFULLY");
    printf("\n\nBALANCE: %d",a.credit);
	getch();  
	transaction(c);  
}
void withdraw(int w)
{
	FILE *fpt;
    FILE *fp;
    int t,amount;
    system("cls");
    printf("\n\nENTER AMOUNT YOU WANT TO WITHDRAW: ");
    scanf("%d",&amount);
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != w){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            if(amount>a.credit){
            	printf("\n\nCREDIT PRESENT IN ACCOUNT IS NOT SUFFICIENT");
            	getch();
            	transaction(w);
			}else{
                a.credit=a.credit-amount;
                fwrite(&a, sizeof(struct account), 1, fpt);
            }
		} 
    }
        fclose(fp);
        fclose(fpt);
        fp = fopen("account.txt", "w");
        fpt = fopen("tempFile", "r");
        while (fread(&a, sizeof(struct account), 1, fpt)){
            fwrite(&a, sizeof(struct account), 1, fp);
        }
    fclose(fp);
    fclose(fpt);
    fflush(stdin);
    withdraw_time(w);
    printf("\n\n\nAMOUNT WITHDRAWN SUCCESSFULLY");
	printf("\n\nBALANCE: %d",a.credit);
	getch();  
	transaction(w);  
}
void transfer(int j)
{
	FILE *fpt;
    FILE *fp;
    int t,p,amount,q;
    system("cls");
    printf("\n\nENTER AMOUNT YOU WANT TO TRANSFER: ");
    scanf("%d",&amount);
    printf("\n\nENTER ACCOUNT NUMBER IN WHICH YOU WANT TO TRANSFER MONEY: ");
    scanf("%d",&q);
    if (avlaccno(q) == 0){
        printf("\n\nACCOUNT IS NOT PRESENT");
        getch();
        transaction(j);
	}else{
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != j){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            if(amount>a.credit){
            	printf("\n\nCREDIT PRESENT IN ACCOUNT IS NOT SUFFICIENT");
            	getch();
            	transaction(j);
			}else{
                a.credit=a.credit-amount;
                fwrite(&a, sizeof(struct account), 1, fpt);
            }
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        p = a.accn;
        if (p != q){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            a.credit=a.credit+amount;
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
        fclose(fp);
        fclose(fpt);
        fp = fopen("account.txt", "w");
        fpt = fopen("tempFile", "r");
        while (fread(&a, sizeof(struct account), 1, fpt)){
            fwrite(&a, sizeof(struct account), 1, fp);
        }
    fclose(fp);
    fclose(fpt);
    fflush(stdin);
    transfer_time(q);
    transfer_time(j);
    printf("\n\n\nAMOUNT TRANSFERED TO ACCOUNT %d SUCCESSFULLY",q);
	printf("\n\nBALANCE: %d",a.credit);
    }
	getch();  
	transaction(j);  
}
void credit_time(int ct)
{
	FILE *fpt;
    FILE *fp;
    int t;
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != ct){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            struct tm* local; 
            time_t t = time(NULL);
            local = localtime(&t);  
            strcpy(a.lcredit,asctime(local));
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
}
void withdraw_time(int wt)
{
	FILE *fpt;
    FILE *fp;
    int t;
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != wt){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            struct tm* local; 
            time_t t = time(NULL);
            local = localtime(&t);  
            strcpy(a.lwithdraw,asctime(local));
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
}
void transfer_time(int tt)
{
	FILE *fpt;
    FILE *fp;
    int t;
    fp = fopen("account.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&a, sizeof(struct account), 1, fp)){
        t = a.accn;
        if (t != tt){
            fwrite(&a, sizeof(struct account), 1, fpt);
        }else{ 
            struct tm* local; 
            time_t t = time(NULL);
            local = localtime(&t);  
            strcpy(a.ltransfer,asctime(local));
            fwrite(&a, sizeof(struct account), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("account.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&a, sizeof(struct account), 1, fpt)){
        fwrite(&a, sizeof(struct account), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
}
void trans_history(int th)
{
	int b;
   	system("cls");
   	printf("\n\n\t\t\tTRANSACTION HISTORY");
   	printf("\n\nLAST CREDITED DATE AND TIME: ");
   	puts(a.lcredit);
   	printf("\n\nLAST WITHDRAW DATE AND TIME: ");
   	puts(a.lwithdraw);
	printf("\n\nLAST TRANSFER DATE AND TIME: ");
   	puts(a.ltransfer);
   	printf("\n\n\t\t\t1 : BACK ");
   	scanf("%d",&b);
   	fflush(stdin);
	if(b==1){
    	clogin(th);
	}
}
void avlcnicno(int c1,int c2,int c3)
{
	int s1,s2,s3,uc;
	FILE*fp;
	fp=fopen("account.txt","r");
	while(!feof(fp)){
		while (fread(&a, sizeof(struct account), 1, fp))
        {
        s1 = a.cnic1 ,s2 = a.cnic2, s3 = a.cnic3;
		if(s1==c1 && s2==c2 && s3==c3){
			printf("\nACCOUNT NUMBER: %d",a.accn);
            printf("\n\nCREDIT: %d",a.credit);
            printf("\n\nACCOUNT TYPE: ");
            puts(a.acctype);
		}
	}
    }   
	fclose(fp);
	printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&uc);
    if(uc==1){
    	main_layout();
	}  
}

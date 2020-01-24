
//Hotel Room Reservation
#include <stdio.h>
#include <string.h>
#define size 12

//SingelRoom Client Information struct
struct hotelsystems
{
    char name[size][35];
    char nidnumba[size][15];
    char residential_adres[size][20];
    char rphone[size][12];
    char rdate[size][12];
       };
struct hotelsystems guest;

//Double Room Client Information struct
struct hotelsystemd
{
    char name[size][30];
    char nidnumba[size][20];
    char residential_adres[size][20];
    char rphone[size][12];
    char rdate[size][12];
       };
struct hotelsystemd guest1;

//singelroom array
int singleroom[size];
//doubleroom array
int doubleroom[size];

// File Pointer
FILE *f;

//Working Finction
void welcome(void); //1F
void mainmenu(void);//2F
void clientmenu(void);//3F
void adminmenu(void);//4F
void adminlogin(void);//5F
void viewroom(void);//6F
void bookroom(void);//7F
void checkout(void);//8F
void updateroom(void);//9F
void viewentarnal(void);//10F
void exitout(void);//11F
void signout(void);//12F

//main function
int main()
{
    system("COLOR 2F");
    welcome();
    mainmenu();
    return 0;
}

//1F
void welcome(void){

    f=fopen("welcome.txt","r");
    char c;
    while((c=getc(f))!=EOF)
    putchar(c);
    fclose(f);

    return;
}

//2F
void mainmenu(void){
    printf("\n\n\t\t\t\tA. Client Portal \n");
    printf("\n\n\t\t\t\tB. Admin Portal \n");
    printf("\n\n\t\t\t\tC. Exit \n");
    char opt;
    opt=getch();
    switch(opt){
        case 'A' :
        case 'a' :
        printf("\n\n\t\t\t\tClient Menu\n");
        clientmenu();
        break;
        case 'b' :
        case 'B' :
        printf("\n\n\t\t\t\tAdmin Portal\n");
        printf("\n\n\t\t\t\tLog in:\n");
        adminlogin();
        break;
        case 'c' :
        case 'C' :
        exitout();
        break;
        default:
        printf("\n\n\t\t\t\tWrong Choice!!! Retry: ");
        mainmenu();
        break;
    }
    return;
}

//3F
void clientmenu(void)
{
        char n;
        printf("\n\n\t\t\t\tClient Menu ");
        printf("\n\n\t\t\t\t> PRESS A FOR View Room\n\n\t\t\t\t> PRESS B FOR Reserve Room\n\n\t\t\t\t> PRESS C FOR Checkout\n\n\t\t\t\t");
        n=getch();
        switch(n)
          {
            case 'a':
            case 'A':
                viewroom();
                break;
            case 'b':
            case 'B':
                bookroom();
                break;
            case 'c':
            case 'C':
                checkout();
                break;
            default:
                printf("\n\n\n\t\t\t\t\tWrong Choice");
                clientmenu();
          }
    return;
}
//4F
void adminlogin(void)
{
    int p,un,c;
    char username[]={"admin3"};
    char password[]={"1234"};
    char inputname[50];
    char inputpass[20];
    printf("\n\n\t\t\t\tUsername:");
    gets(inputname);
    printf("\n\n\t\t\t\tPassword:");

    int i = 0;

    while((c = getch()) != 13){
        if(i< 0)
            i = 0;
        if(c == 8){
            putch('\b');
            putch('\b');
            i--;
        continue;
        }
        inputpass[i++] = c;
        putch('*');
    }
    inputpass[i] = '\0';
    un=strcmp(username,inputname);
    p=strcmp(password,inputpass);
    if(un==0&&p==0){
        printf("\n\n\t\t\t\tLogin Successful:");
        adminmenu();
    }
    else{
        printf("\n\n\t\t\t\tUsername or Password Incorrect");
    }
    adminlogin();
    return;
}
//5F
void adminmenu(void)
{
    char n;
    printf("\n\n\t\t\t\t Admin Menu ");
    printf("\n\n\t\t\t\t> PRESS A FOR View Enternal\n\n\t\t\t\t> PRESS B FOR Update Room\n\n\t\t\t\t> PRESS C FOR Sign Out\n\n\t\t\t\t");
    n=getch();
    switch(n)
        {
        case 'a':
        case 'A':
            viewentarnal();
            break;
        case 'b':
        case 'B':
            updateroom();
            break;
        case 'c':
        case 'C':
            signout();
            break;
        default:
            printf("\n\n\n\t\t\t\t\tWrong Choice");
            adminmenu();
          }
    return ;
}
//6F
void viewroom(void){
    f=fopen("roomDetails.txt","r");
    char c;
    while((c=getc(f))!=EOF)
    putchar(c);
    fclose(f);
    clientmenu();
    return ;
}

//7F
void bookroom(void)
{
    printf("\n\n\t\t\t\tENTER [S] FOR SINGLE ROOM OR [D] FOR DOUBLE ROOM\n\n\t\t\t\t");
    char sel;
    int i;
    sel=getch();
    switch(sel)
        {
        case 'S':
        case 's':
            for(i=1;i<size;i++)
            if(singleroom[i]==0)
                {
                singleroom[i]=1;
                f=fopen("single.txt","a+");
                printf("\n\n\t\t\t\t\tROOM No :%d IS AVAILABLE FOR RESERVATION",i);
                printf("\n\n\t\t\t\t\tENTER NAME\n\t\t\t\t");
                gets(guest.name[i]);
                printf("\n\n\n\t\t\t\t\tENTER NID NUMBER\n\t\t\t\t");
                gets(guest.nidnumba[i]);
                printf("\n\n\n\t\t\t\t\tENTER ADRESS\n\t\t\t\t");
                gets(guest.residential_adres[i]);
                printf("\n\n\n\t\t\t\t\tENTER PHONE NUMBER\n\t\t\t\t");
                gets(guest.rphone[i]);
                printf("\n\n\n\t\t\t\t\tENTER CHECK IN DATE\n");
                gets(guest.rdate[i]);
                fprintf(f,"\n%d\t%s\t\t%s\t%s\t%s\t%s",i,guest.name[i],guest.nidnumba[i],guest.residential_adres[i],guest.rphone[i],guest.rdate[i]);
                fclose(f);
                printf("\n\n\n\t\t\t\t\tSuccessfull\n\n\t\t\t\t");
                getch();
                mainmenu();
                }
            break;
        case 'D':
        case 'd':
            for(i=1;i<size;i++)
            if(doubleroom[i]==0)
                {
                doubleroom[i]=1;
                f=fopen("double.txt","a+");
                printf("\n\n\t\t\t\tROOM No : %d IS AVAILABLE FOR RESERVATION",i);
                printf("\n\n\t\t\t\tENTER NAME\n\t\t\t\t");
                gets(guest1.name[i]);
                printf("\n\n\t\t\t\tENTER NID NUMBER\n\t\t\t\t");
                gets(guest1.nidnumba[i]);
                printf("\n\n\t\t\t\tENTER ADRESS\n\t\t\t\t");
                gets(guest1.residential_adres[i]);
                printf("\n\n\t\t\t\tENTER MOBILE PHONE NUMBER\n\t\t\t\t");
                gets(guest1.rphone[i]);
                printf("\n\n\t\t\t\tENTER CHECK IN DATE\n\t\t\t\t");
                gets(guest1.rdate[i]);
                fprintf(f,"\n%d\t%s\t\t%s\t%s\t%s\t%s",i,guest1.name[i],guest1.nidnumba[i],guest1.residential_adres[i],guest1.rphone[i],guest1.rdate[i]);
                fclose(f);
                getch();
                mainmenu();
                }

            break;
        }

    return;
}
//8F
void checkout(void)
{
    int days;
    int rate=10000;
    int advanced=0;
    int bill;
    int rno;
    char rc;
    char temp[10];
    printf("\n\n\t\t\t\tENTER ROOM NUMBER CHECKING OUT\n\n\t\t\t\t");
    gets(temp);
    rno=atoi(temp);
    if(rno<1 || rno >30)
        {
        printf("\n\n\t\t\t\tINVALID ROOM NUMBER\n\n\t\t\t\t");
        checkout();
        }
    else
        {
        printf("\n\n\t\t\t\tENTER [S] FOR SINGLE ROOM or [D] FOR DOUBLE ROOM\n\n\t\t\t\t");
        rc=getch();
        switch(rc)
            {
            case 'S':
            case 's':
                if(singleroom[rno]==1)
                {
                    printf("\n\n\t\t\t\tSINGLE ROOM NUMBER No %d IS NOW CHECKING OUT",rno);
                    printf("\n\n\t\t\t\tGUEST NAME : %s \n\n\t\t\t\tGUEST NID NUMBER : %s \n\n\t\t\t\tRESIDENTIAL ADRESS : %s\n\n\t\t\t\tMOBILE PHONE NUMBER : %s\n\n\t\t\t\tCHECK IN DATE : %s \n\n",guest.name[rno],guest.nidnumba[rno],guest.residential_adres[rno],guest.rphone[rno],guest.rdate[rno]);
                    printf("\n\n\t\t\t\tENTER NUMBER OF DAYS STAYED\n");
                    scanf("%f",&days);
                    printf("\n\n\t\t\t\tTHE Rate 10,000Tk Per Day For SIngel Room\n");
                    if(days<1 && days >90)
                        {
                        printf("\n\n\t\t\t\tINVALID ENTRY OF DAYS || CHARGE\a\a\a");
                        printf("\n\n\t\t\t\t>>>HIT ANY KEY TO RETRY<<<\n\n\t\t\t\t ");
                        getch();
                        checkout();
                        }
                    else
                    {
                        bill=(days*rate)-advanced;
                    }
                    printf("\n\n\t\t\t\tTOTAL CHARGES ARE BDT %d",bill);
                    printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<\n\n\t\t\t\t ");
                    singleroom[rno]=0;
                    getch();
                    mainmenu();
                }
                else{
                    printf("\n\n\t\t\t\tSINGLE ROOM No %d IS VACANT CANNOT CHECK OUT",rno);
                    printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<\n\n\t\t\t\t ");
                    getch();
                    mainmenu();
                }
                break;

            case 'D':
            case 'd':
                if(doubleroom[rno]==1)
                    {
                    printf("\n\n\t\t\t\tDOUBLE ROOM No %d IS NOW CHECKING OUT",rno);
                    printf("\n\n\t\t\t\tNAME : %s \n\n\t\t\t\tGUEST NID NUMBER : %s \n\n\t\t\t\tRESIDENTIAL ADRESS: %s\n\n\t\t\t\tMOBILE PHONE NUMBER : %s\n\n\t\t\t\tCHECK IN DATE: %s \n\n",guest1.name[rno],guest1.nidnumba[rno],guest1.residential_adres[rno],guest1.rphone[rno],guest1.rdate[rno]);
                    printf("\n\n\t\t\t\tENTER NUMBER OF DAYS STAYED\n\n\t\t\t\t");
                    scanf("%f",&days);
                    printf("\n\n\t\t\t\tTHE Rate 15,000Tk Per Day For Singel Room\n");
                    if(days<1||days>60)
                        {
                        printf("\n\n\t\t\t\tINVALID ENTRY OF DAYS");
                        printf("\n\n\t\t\t\t>>>HIT ANY KEY TO RETRY<<< \n\n\t\t\t\t");
                        getch();
                        checkout();
                        }
                    else
                        {
                        bill=(days*rate*1.5)-advanced;
                    }
                    printf("\n\n\t\t\t\tTOTAL CHARGES ARE BDT %d",bill);
                    doubleroom[rno]=0;
                    printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< \n\n\t\t\t\t");
                    getch();
                    mainmenu();
                    }
                else{
                    printf("\n\n\t\t\t\tSINGLE ROOM No %d IS VACANT CANNOT CHECK OUT",rno);
                    printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< ");
                    getch();
                    mainmenu();
                    }
                break;
            default:{
                printf("\n\n\t\t\t\tWrong Choice\n\t\t\t\tTry Again\n");
                checkout();
                }
            }
        }
    return;
}
//9F
void updateroom(void)
{
    int rno;
    char rc;
    char temp[10];
    printf("\n\n\t\t\t\tENTER ROOM NUMBER TO VACATE\n");
    gets(temp);
    rno=atoi(temp);
    // Room Number Limit Check
    if(rno<1||rno>18)
    {
    printf("\n\n\t\t\t\tINVALID ROOM NUMBER");
    updateroom();
    }
    else
    {
    printf("\n\n\t\t\t\tSINGLE Or DOUBLE ROOM? [S / D]\n\n\t\t\t\t");
    rc=getch();
    switch(rc)
        {
        case 'S':
        case 's':
            singleroom[rno]=0;
            printf("\n\n\t\t\t\tROOM VACATED");
            printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE ADMIN MENU<<<\n\n\t\t\t\t");
            getch();
            adminmenu();
            break;
        case 'D':
        case 'd':
            doubleroom[rno]=0;
            printf("\n\n\t\t\t\tROOM VACATED");
            printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE ADMIN MENU<<<\n\n\t\t\t\t");
            getch();
            adminmenu();
            break;
        default:
            printf("\n\n\t\t\t\tWrong Choice\n\t\t\t\tTry Again\n");
            updateroom();
            break;
        }
    }
    return;
}
//10F
void viewentarnal(void)
{
    char sel;
    char c;
    int i;
    printf("\n\n\t\t\t\tENTER [S] FOR SINGLE ROOM GUEST LIST or [D] FOR DOUBLE ROOM GUEST LIST...\n\n\t\t\t\t");
    sel=getch();
    switch(sel) // Rselection Switch Begin
        {
        case 'S' :
        case 's' :
            printf("R.No.\tNAME\t\tNID NUMBER\tADRESS\tPHONE No\tCHECK In\n");
            f=fopen("single.txt","r");
            while((c=getc(f))!=EOF)
            putchar(c);
            fclose(f);
            printf("\n\n\t\t\t\t>>>HIT ANY KEY TO EXIT TO THE ADMIN MENU<<<");
            getch();
            adminmenu();
            break;
        case 'D' :
        case 'd' :
            f=fopen("double.txt","r");
            printf("R.No.\tNAME\t\t\tNID No\t\tADRESS\t\t\tPHONE No\t\tCHECK In\n");
            while((c=getc(f))!=EOF)
            putchar(c);
            fclose(f);
            printf("\n\n\t\t>>>HIT ANY KEY TO EXIT TO THE ADMIN MENU<<< ");
            getch();
            adminmenu();
        default :
            printf("\n\n\t\t\t\tWrong Choice\n\n\t\t\t\tTry Again\n");
            viewentarnal();
            break;
        }
    return;
}
//11F
void exitout(void){
    printf("\n\n\t\t\t\tThis Software Is Devolped By Saif, Rifat & Kabbo");
    return;
}
//12F
void signout(void)
{
    mainmenu();
}

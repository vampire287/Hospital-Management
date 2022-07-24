#include <bits/stdc++.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define MAX 30
struct Patient_Details
{
    int Patient_ID;
    string Name;
    string Dept;
    int Date_Of_Admission[MAX];
    int Date_Of_Release[MAX];
    string Investigating_Doctor_name;
    string Disease;
    string Gaurdian_name;
    char Emergency_contact_no[MAX];
    int Fee_due;
    int Age;
    char blood[MAX];
    char PhNo[MAX];
    char available;
    struct Patient_Details *prev;
    struct Patient_Details *next;
};
typedef struct Patient_Details *NODE;
#define MALLOC(p, s, t)                  
    p = (t)malloc(s);                    
    if (p == NULL)                       
    {                                    
        printf("Insufficient Memory\n"); 
        exit;                            
    }

int patient_ID = 0;
int age;
char blood[MAX];
string name;
string Dept;
int DOA[MAX];
int DOR[MAX];
string investigating_Doctor_name;
string disease;
string gaurdian_name;
char emergency_contact_no[MAX];
long long fee_due;
char phNo[MAX];

void display_individual(NODE t)
{
    int i;
    printf("Patient_ID                           = %d\n", t->Patient_ID);
    cout<<"Name                                 "<<t->Name<<endl;
    printf("Age                                  = %d\n", t->Age);
    cout<<"Department                            "<<t->Dept<<endl;
    for (i = 0; i < 3; i++)
        printf("Date Of Admission                    = %d\n", t->Date_Of_Admission[i]);
    for (i = 0; i < 3; i++)
        printf("Date Of Release                      = %d\n", t->Date_Of_Release[i]);
    cout<<"Investigating Doctor Name            = "<<t->Investigating_Doctor_name<<endl;
    cout<<"Disease Name                         = "<<t->Disease<<endl;
    printf("Blood Group                          = %s\n", t->blood);
    cout<<"Gaurdian Name                        = "<<t->Gaurdian_name<<endl;
    printf("Emergency Contact Number             = %s\n", t->Emergency_contact_no);
    printf("Phone Number                         = %s\n", t->PhNo);
    printf("Patient Available in Hospital or Not = %c\n", t->available);
    cout << "amount to be paid:\t" << t->Fee_due << endl;
}

void search(NODE first)
{
    int choice;
    NODE temp;
    int c = 0;
    printf("Enter your preference to Search a  Patient in the Hospital\n");
    printf("1.Name\t 2.Department \t 3.Date of Admission \t 4.Date of Release \n");
    printf("Enter your choice \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("Enter Name \n");
            scanf("%s", name);
            while (temp != first)
            {
                if (name==temp->Name)
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (name==temp->Name)
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients admitted with that name! \n");
        break;
    case 2:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("Enter Department\n");
            cin>>Dept;
            while (temp != first)
            {
                if (Dept==temp->Dept)
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (Dept==temp->Dept)
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients admitted in that Department!\n");
        break;
    case 3:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("Enter Patient Date of Admission\n");
            scanf("%d", &DOA[0]);
            printf("Enter Patient Month of Admission\n");
            scanf("%d", &DOA[1]);
            printf("Enter Patient Year of Admission\n");
            scanf("%d", &DOA[2]);
            while (temp != first)
            {
                if (DOA[0] == temp->Date_Of_Admission[0] && DOA[1] == temp->Date_Of_Admission[1] && DOA[2] == temp->Date_Of_Admission[2])
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (DOA[0] == temp->Date_Of_Admission[0] && DOA[1] == temp->Date_Of_Admission[1] && DOA[2] == temp->Date_Of_Admission[2])
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients admitted on that date!\n");
        break;
    case 4:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("Enter Patient Date of Release\n");
            scanf("%d", &DOR[0]);
            printf("Enter Patient Month of Release\n");
            scanf("%d", &DOR[1]);
            printf("Enter Patient Year of Release\n");
            scanf("%d", &DOR[2]);
            while (temp != first)
            {
                if (DOR[0] == temp->Date_Of_Release[0] && DOR[1] == temp->Date_Of_Release[1] && DOR[2] == temp->Date_Of_Release[2])
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (DOR[0] == temp->Date_Of_Release[0] && DOR[1] == temp->Date_Of_Release[1] && DOR[2] == temp->Date_Of_Release[2])
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients released on that date!\n");
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
}

void Display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("No Patients Admitted!");
    }
    else
    {
        temp = first;
        while (temp->next != first)
        {
            if (temp->available == 'Y')
                display_individual(temp);
            temp = temp->next;
        }
        if (temp->available == 'Y')
            display_individual(temp);
    }
}

int days_admitted()
{
    int i, diff = 0, flag = 0;
    if (DOA[2] % 100)
    {
        if (DOA[2] % 4 == 0)
            flag = 1;
    }
    else
    {
        if (DOA[2] % 400 == 0)
            flag = 1;
    }
    if (DOA[1] == DOR[1])
    {
        return (DOR[0] - DOA[0]);
    }
    else
    {
        if (DOA[1] == 1 || DOA[1] == 3 || DOA[1] == 5 || DOA[1] == 7 || DOA[1] == 8 || DOA[1] == 10 || DOA[1] == 12)
            diff += 31 - DOA[0];
        else if (DOA[1] == 2 && flag == 1)
            diff += 29 - DOA[0];
        else if (DOA[1] == 2 && flag == 0)
            diff += 28 - DOA[0];
        else
            diff += 30 - DOA[0];
        for (i = DOA[1] + 1; i < DOR[1]; i++)
        {
            if (i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                diff += 31;
            else if (i == 2 && flag == 1)
                diff += 29;
            else if (i == 2 && flag == 0)
                diff += 28;
            else
                diff += 30;
        }
        diff += DOR[0];
    }
    return (diff + 1);
}

//      Code By Divyansh
void bill(NODE first, int days) // days=no. of days stayed in hospital
{
    int medicine_charge, bed_charge, total_charge, tax, pid, flag;
    float age_discount;
    float charge, fcharge;
    int consul_charge = 100;

    NODE x = first;
    printf("Search by Patient ID :\n");
    scanf("%d", &pid);

    if (x == NULL)
    {
        printf("No Patient Entry\n");
    }
    else if (x->next == first)
        if (x->Patient_ID == pid)
            display_individual(x);
        else
            printf("Patient with given patient ID does not exist ! \n");

    if (x->Patient_ID == pid)
        display_individual(x);
    else
        x = x->next;
    while (x != first)
    {
        if (x->Patient_ID == pid)
        {
            display_individual(x);
            break;
        }
        x = x->next;
    }

    if ((flag == 0) && (x == first))
    {
        printf("Patient with given patient ID does not exist ! \n");
    }
    else if (x->Dept=="AND")
    {
        charge = 2000;
        medicine_charge = 1000;
    }
    else if (x->Dept=="AYU")
    {
        charge = 500;
        medicine_charge = 300;
    }
    else if (x->Dept=="CAR" )
    {
        charge = 40000;
        medicine_charge = 5000;
    }
    else if (x->Dept=="DEN")
    {
        charge = 1200;
        medicine_charge = 300;
    }
    else if (x->Dept=="DIA")
    {
        charge = 1300;
        medicine_charge = 500;
    }
    else if (x->Dept=="NEP")
    {
        charge = 15000;
        medicine_charge = 4000;
    }
    else if (x->Dept=="NEU")
    {
        charge = 60000;
        medicine_charge = 9000;
    }
    else if (x->Dept=="ONC")
    {
        charge = 700;
        medicine_charge = 200;
    }

    bed_charge = 1500 * days;
    total_charge = charge + medicine_charge + bed_charge;

    if (x->Age > 60 || x->Age < 18)
    {
        age_discount = ((total_charge * 10) / 100);
        total_charge = total_charge - age_discount;
    }
    tax = total_charge + ((total_charge * 3) / 100);
    fcharge = total_charge + tax;
    cout<<x->Name<<endl;
    printf("charge = %f \n medicine charge= %d \n bed charge= %d \t \t \t age discount= %f \n tax= %d \n fcharge= %f \n ",
            charge, medicine_charge, bed_charge, age_discount, tax, fcharge);
    x->available = 'N';
    x->Fee_due = fcharge;
}
void update(int key, NODE first)
{
    NODE cur;
    int choice, i;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        cur = first;
        while (cur->next != first)
        {
            if (key == cur->Patient_ID)
            {
                printf("1.Name \n 2.Age \n 3.Department \n 4.Date of Admission \n 5.Date of Release \n 6.Investigating Doctor \n 7.Disease \n 8.Guardian Name \n 9.Emergency contact no \n  10.Phone Number \n");
                printf("Enter the entry which you want to update\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter the New Name\n");
                    cin>>name;
                    cur->Name=name;
                    break;
                case 2:
                    printf("Enter the Correct Age\n");
                    scanf("%d", &age);
                    cur->Age = age;
                    break;
                case 3:
                    printf("Enter the New Department\n");
                    printf("Enter Deparment code :\n 1.AND - ANDROLOGY \n2. AYU - AYURVEDIC  \n3.CAR - CARDIOLOGY \n4.DEN  - DENTAL \n5.DIA - DIABETES \n6.NEP - NEPHROLOGY\n7.NEU - NEUROLOGY \n8.ONC - ONCOLOGY\n");
                    cin>>Dept;
                    first->Dept=Dept;
                    break;
                case 4:
                    printf("Enter Patient Date of Admission\n");
                    scanf("%d", &DOA[0]);
                    printf("Enter Patient Month of Admission\n");
                    scanf("%d", &DOA[1]);
                    printf("Enter Patient Year of Admission\n");
                    scanf("%d", &DOA[2]);
                    for (i = 0; i < 3; i++)
                        cur->Date_Of_Admission[i] = DOA[i];
                    break;

                case 5:
                    printf("Enter Patient Date of Release\n");
                    scanf("%d", &DOR[0]);
                    printf("Enter Patient Month of Release\n");
                    scanf("%d", &DOR[1]);
                    printf("Enter Patient Year of Release\n");
                    scanf("%d", &DOR[2]);
                    for (i = 0; i < 3; i++)
                        cur->Date_Of_Release[i] = DOR[i];
                    break;

                case 6:
                    printf("Enter the New Investigating Doctor\n");
                    cin>>investigating_Doctor_name;
                    cur->Investigating_Doctor_name=investigating_Doctor_name;
                    break;
                case 7:
                    printf("Enter the New Disease Name\n");
                    cin>>disease;
                    cur->Disease=disease;
                    break;
                case 8:
                    printf("Enter the New Guardian Name\n");
                    cin>>gaurdian_name;
                    cur->Gaurdian_name=gaurdian_name;
                    break;
                case 9:
                    printf("Enter the New Emergency Contact Number \n");
                    scanf("%s", emergency_contact_no);
                    strcpy(cur->Emergency_contact_no, emergency_contact_no);
                    break;
                case 10:
                    printf("Enter the New Phone Number \n");
                    scanf("%s", phNo);
                    strcpy(cur->PhNo, phNo);
                    break;
                default:
                    printf("INVALID CHOICE\n");
                }
                break;
            }
            cur = cur->next;
        }
        if (key == cur->Patient_ID)
        {
            printf("1.Name \n 2.Age \n 3.Department \n 4.Date of Admission \n 5.Date of Release \n 6.Investigating Doctor \n 7.Disease \n 8.Guardian Name \n 9.Emergency Contact Number \n 10.Phone Number \n");
            printf("Enter the Entry which you want to update\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the New Name\n");
                cin>>name;
                cur->Name=name;
                break;
            case 2:
                printf("enter the New Age\n");
                scanf("%d", &age);
                cur->Age = age;
                break;
            case 3:
                printf("Enter the New Department\n");
                printf("Enter Deparment Code :\n 1.AND - ANDROLOGY \n 2. AYU - AYURVEDIC  \n 3.CAR - CARDIOLOGY \n 4.DEN  - DENTAL \n 5.DIA - DIABETES \n 6.NEP - NEPHROLOGY \n 7.NEU - NEUROLOGY \n 8.ONC - ONCOLOGY \n ");
                cin>>Dept;
                cur->Dept=Dept;
                break;
            case 4:
                printf("Enter Patient Date of Admission\n");
                scanf("%d", &DOA[0]);
                printf("Enter Patient Month of Admission\n");
                scanf("%d", &DOA[1]);
                printf("Enter Patient Year of Admission\n");
                scanf("%d", &DOA[2]);
                for (i = 0; i < 3; i++)
                    cur->Date_Of_Admission[i] = DOA[i];
                break;

            case 5:
                printf("Enter Patient Date of Release\n");
                scanf("%d", &DOR[0]);
                printf("Enter Patient Month of Release\n");
                scanf("%d", &DOR[1]);
                printf("Enter Patient Year of Release\n");
                scanf("%d", &DOR[2]);
                for (i = 0; i < 3; i++)
                    cur->Date_Of_Release[i] = DOR[i];
                break;

            case 6:
                printf("Enter the New Investigating Doctor\n");
                cin>>investigating_Doctor_name;
                cur->Investigating_Doctor_name=investigating_Doctor_name;
                break;
            case 7:
                printf("Enter the New Disease Name\n");
                cin>>disease;
                cur->Disease=disease;
                break;
            case 8:
                printf("Enter the New Guardian Name\n");
                cin>>gaurdian_name;
                cur->Gaurdian_name=gaurdian_name;
                break;
            case 9:
                printf("Enter the New Emergency Contact Number \n");
                scanf("%s", emergency_contact_no);
                strcpy(cur->Emergency_contact_no, emergency_contact_no);
                break;
            case 10:
                printf("Enter the New Phone Number \n");
                scanf("%s", phNo);
                strcpy(cur->PhNo, phNo);
                break;
            default:
                printf("INVALID CHOICE\n");
            }
        }
    }
}

//  Code by Himank

void ReadData()
{
    printf("Enter Patient Name\n");
    cin>>name;
    printf("Enter Patient Age\n");
    scanf("%d", &age);
    printf("Enter Patient Blood Group\n");
    scanf("%s", blood);

    printf("Enter Patient Date of Admission\n");
    scanf("%d", &DOA[0]);
    printf("Enter Patient Month of Admission\n");
    scanf("%d", &DOA[1]);
    printf("Enter Patient Year of Admission\n");
    scanf("%d", &DOA[2]);

    printf("Enter Patient Date of Release\n");
    scanf("%d", &DOR[0]);
    printf("Enter Patient Month of Release\n");
    scanf("%d", &DOR[1]);
    printf("Enter Patient Year of Release\n");
    scanf("%d", &DOR[2]);

    printf("Enter Deparment Code :\n 1.AND - ANDROLOGY \n 2. AYU - AYURVEDIC  \n 3.CAR - CARDIOLOGY \n 4.DEN  - DENTAL \n 5.DIA - DIABETES \n 6.NEP - NEPHROLOGY \n 7.NEU - NEUROLOGY \n 8.ONC - ONCOLOGY \n");
    cin>>Dept;

    printf("Enter Disease Name\n");
    cin>>disease;
    printf("Guardian Name\n");
    cin>>gaurdian_name;
    printf("Enter Patient Phone Number\n");
    scanf("%s", phNo);
    printf("Enter Patient Emergency Contact Number\n");
    scanf("%s", emergency_contact_no);
    printf("Enter Investigating  Doctor Name\n");
    cin>>investigating_Doctor_name;
}

NODE insert(NODE first)
{
    NODE q, last;
    int i;
    MALLOC(q, sizeof(struct Patient_Details), NODE);
    patient_ID = patient_ID + 1;
    q->Patient_ID = patient_ID;
    q->Age = age;
    q->Dept=Dept;
    q->Name=name;
    for (i = 0; i < 3; i++)
        q->Date_Of_Admission[i] = DOA[i];
    for (i = 0; i < 3; i++)
        q->Date_Of_Release[i] = DOR[i];
    strcpy(q->blood, blood);
    q->Disease=disease;
    strcpy(q->PhNo, phNo);
    q->Gaurdian_name=gaurdian_name;
    strcpy(q->Emergency_contact_no, emergency_contact_no);
    q->Investigating_Doctor_name=investigating_Doctor_name;
    q->available = 'Y';
    if (first == NULL)
    {
        q->next = q;
        q->prev = q;
        return q;
    }
    else
    {
        last = first->prev;
        last->next = q;
        q->prev = last;
        first->prev = q;
        q->next = first;
        return first;
    }
}

int main()
{
    NODE first = NULL;
    int done = 0, done1 = 0, p_id, days, choice;
    while (!done)
    {

        printf("\n ___HOSPITAL___NAME___ \n Select an option :\n 1.EMERGENCY \t 2.OPD \t 3.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("EMERGENCY WARD - BASE charge = 10,000/- \n Other formalties and procedures will be carried out later\n");
            break;
        case 2:
            while (!done1)
            {
                printf("\n In OPD : \n Enter your choice: \n 1.New Entry \t 2.Edit/Update \t 3.Search \t 4.Display \t 5.Generate Bill \t 6.Exit\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("___NEW___PATIENT__\n");
                    ReadData();
                    first = insert(first);
                    break;
                case 2:
                    printf("UPDATING PATIENT INFO: \n");
                    printf("Kindly enter Patient ID : \n");
                    scanf("%d", &p_id);
                    update(p_id, first);
                    break;
                case 3:
                    printf("SEARCHING PATIENT : \n");
                    search(first);
                    break;
                case 4:
                    printf("DISPLAY : \n");
                    Display(first);
                    break;
                case 5:
                    printf("GENERAING BILL and deleting patient entry : \n");
                    printf("Enter Patient Unique ID\n");
                    scanf("%d", &patient_ID);
                    days = days_admitted();
                    bill(first, days);
                    break;
                case 6:
                    done1 = 1;
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            break;
        case 3:
            done = 1;
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}

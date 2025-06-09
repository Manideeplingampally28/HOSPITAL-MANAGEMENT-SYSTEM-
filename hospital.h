#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<unistd.h>
struct patient{
	int id;
	char Name[100];
	char phoneno[11];
	char gender;
	char disease[100];
	int age;
	char address[200];
	char DateOfAdmit[20];
	int doc_id;
	char doctorName[100];
};
int counter=1;
struct patient p;
int num_Patients=0;
void sortPatientsByDate();
void sortPatientsByName();
void sortPatientsByAge();
void sortPatientsByDisease();
void sortPatientsByDocId();
void count();
void addpatient();
void print_patient();
void SearchPatientsByName();
void searchpatientbyID();
void searchpatientbyPhoneNumber();
void searchpatientbydocID();
void sortPatientsByDoctorName();
void DiplayDoctorByPatientAge();
void menu();
int login();
int signin();
char uname[20],pwd[20];
void menu()
{ 
	int opt;
	printf("\n\n========WELCOME TO VISION HOSPITAL============");
	while(1){
	printf("\n\nPlease select your prefered operation");
	printf("\n\n1.to add patient:");
	printf("\n2.Searching patient by name");
	printf("\n3.Searching patient via ID: ");
	printf("\n4.Searching patient via Age:");
	printf("\n5.Searching patient via doctor id:");
	printf("\n6.Display Patients: ");
	printf("\n7.Count Patients: ");
	printf("\n8.sortPatientsByDifferent Ways:");
	printf("\n9.Exit\n");
	printf("\n Your choice:\t");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:addpatient();
		break;
		case 2:SearchPatientsByName();
		break;
		case 3:searchpatientbyID();
		break;
	case 4:
		DiplayDoctorByPatientAge();
break;
case 5:searchpatientbydocID();
	break;
	
case 6:	print_patient();
		break;		
case 7: count();
break;
case 8:printf("\nSort Beneficiaries");
            printf("\n1. Sort by Name");
            printf("\n2. Sort by Age");
            printf("\n3. Sort by Date ");
            printf("\n4. Sort by Disease ");
            printf("\n5. Sort by DocId ");
            printf("\n6. Sort by DoctorName ");
            printf("\nEnter your choice: ");
            int sortChoice;
            scanf("%d", &sortChoice);
            switch (sortChoice) {
                    case 1:
                        sortPatientsByName();
                        break;
                    case 2:
                        sortPatientsByAge();
                        break;
                    case 3:
                        sortPatientsByDate();
                        break;
                    case 4:sortPatientsByDisease();
                        break;
                    case 5:sortPatientsByDocId();
                        break;
                    case 6:sortPatientsByDoctorName();
                    break;
                    }
break;
case 9:exit(0);	
break;	
default:printf("\n you entered wrong choice");	
		break;
	}
}
}

void addpatient()
{
	printf("\n enter the patient ID :");
	scanf("%d",&p.id);
	printf("\n enter the Doctor ID :");
	scanf("%d",&p.doc_id);
	printf("\n enter the patient name:");
	scanf("%s",p.Name);
	printf("\n enter the patient age :");
	scanf("%d",&p.age);
	printf("\n enter the patient disease :");
	scanf("%s",&p.disease);
	printf("\n enter the patient gender(M/F/OTHER):");
	scanf("%c",&p.gender);scanf("%c",&p.gender);
	printf("\n Enter the phone number of patient's 10 digit number:");
	scanf("%s",p.phoneno);
	printf("\n Enter the patient address:");
	scanf("%s",p.address);
	 printf("\n enter the patient date of admission (dd-mm-yyyy): ");
    scanf("%s", p.DateOfAdmit);
    printf("\n enter the doctor name :");
    scanf("%s",p.doctorName);


	printf("\n patient name %s with age %d %c gender admitted  \n:",p.Name,p.age,p.gender );
	FILE *fp;
	fp=fopen("patients.dat","a");
	fwrite(&p,sizeof(struct patient),1,fp);
	fclose(fp); 
}
//void addpatient();
//void searchpatientbyname();
void searchpatientbyID()
{
	FILE *fp;
	int id;
	fp = fopen("patients.dat", "r");

	printf("\nEnter Patient ID:");
	scanf("%d", &id);
	printf("\n<<<PATIENT DETAILS>>>\n");
	printf("ID    PatientName    Gender    Age    Disease    DocID     DateOfAdmit\n-----------------------------------------------------------------------------");
	int found = 0; 

	while (fread(&p, sizeof(struct patient), 1, fp) > 0) {
		if (p.id == id) {
			printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %d     %s", p.id, p.Name, p.gender, p.age, p.disease, p.doc_id, p.DateOfAdmit);
			found = 1; 
			break; 
		}
	}

	if (found!=1) {
		printf("\nNo patient found with the given ID.");
	}

	fclose(fp);
}
void print_patient()
{
FILE*fp;


	fp=fopen("patients.dat","r");
	
	printf("\n<<<PATIENT DETAILS>>>\n");
	printf("ID    PatientName    Gender    Age    PhoneNumber    diease	doc_id    Address\n--------------------------------------------------");
	while(fread(&p,sizeof(struct patient),1,fp)>0){
	
	printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %s	%d    %-3s	%-3s",p.id,p.Name,p.gender,p.age,p.phoneno,p.disease,p.doc_id,p.address,p.DateOfAdmit);
}
	fclose(fp);
		
}
void count()
{
	int count=0;
	FILE*fp;

	fp=fopen("patients.dat","r");
	if(fp==NULL){
		printf("Failed to open the file .\n");
		
	}
	while(fread(&p,sizeof(struct patient),1,fp)==1)
	{
		count++;
		
	}
	printf("%d patients",count);
	fclose(fp);
	
}
 void searchpatientbydocID()
{
		FILE *fp;
	int docId;
	int found = 0; // Flag to indicate if a patient is found
	fp = fopen("patients.dat", "r");

	printf("\nEnter doc id:");
	scanf("%d", &docId);
	printf("\n<<<PATIENT DETAILS>>>\n");
	printf("ID    PatientName    Gender    Age    PhoneNumber   disease    doc_id   DateOfAdmit\n-------------------------------------------------------------------------------------------------------");
	while (fread(&p, sizeof(struct patient), 1, fp) > 0) {
		if (p.doc_id == docId) {
			printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %s    %d    %s", p.id, p.Name, p.gender, p.age, p.phoneno, p.disease, p.doc_id, p.DateOfAdmit);
			found = 1;
		}
	}

	if (found!=1) {
		printf("\nNo patients found with the given doc id.");
	}

	fclose(fp);
}


void SearchPatientsByName()
{
    FILE *fp;
    char name[100];
    fp = fopen("patients.dat", "r");

    printf("\nEnter Patient Name: ");
    scanf("%s", name);

    printf("\n<<<PATIENT DETAILS>>>\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber   Disease     DoctorID    Address\n--------------------------------------------------");

    while (fread(&p, sizeof(struct patient), 1, fp) > 0)
    {
        if (strcmp(p.Name, name) == 0)
        {
            printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %d    %s", p.id, p.Name, p.gender, p.age, p.phoneno, p.disease, p.doc_id, p.address);
        }
    }

    fclose(fp);
}
void sortPatientsByAge()
{
    FILE *fp;
    int count = 0;
    fp = fopen("patients.dat", "r");

    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // Count the number of patients
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        count++;
    }

    rewind(fp);

    struct patient patients[count];
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        patients[i] = p;
        i++;
    }

    // Sort the array of patients by age using bubble sort
    int j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (patients[j].age > patients[j + 1].age)
            {
                // Swap patients
                struct patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Sorted Patients by Age:\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber    Disease    DoctorID    Address\n--------------------------------------------------");

    // Display sorted patients
    for (i = 0; i < count; i++)
    {
        printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %d    %s", patients[i].id, patients[i].Name, patients[i].gender, patients[i].age, patients[i].phoneno, patients[i].disease, patients[i].doc_id, patients[i].address);
    }

    fclose(fp);
}
void sortPatientsByName()
{
    FILE *fp;
    int count = 0;
    fp = fopen("patients.dat", "r");

    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // Count the number of patients
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        count++;
    }

    rewind(fp);

    // Read patients into an array
    struct patient patients[count];
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        patients[i] = p;
        i++;
    }

    // Sort the array of patients by name using bubble sort
    int j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (strcmp(patients[j].Name, patients[j + 1].Name) > 0)
            {
                // Swap patients
                struct patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Sorted Patients by Name:\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber    Disease    DoctorID    Address\n--------------------------------------------------");

    // Display sorted patients
    for (i = 0; i < count; i++)
    {
        printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %d    %s", patients[i].id, patients[i].Name, patients[i].gender, patients[i].age, patients[i].phoneno, patients[i].disease, patients[i].doc_id, patients[i].address);
    }

    fclose(fp);
}
void sortPatientsByDate()
{
    FILE *fp;
    int count = 0;
    fp = fopen("patients.dat", "r");

    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // Count the number of patients
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        count++;
    }

    rewind(fp);

    // Read patients into an array
    struct patient patients[count];
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        patients[i] = p;
        i++;
    }

    // Sort the array of patients by date of admission using bubble sort
    int j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            // Convert date strings to integer values for comparison
            int day1, month1, year1, day2, month2, year2;
            sscanf(patients[j].DateOfAdmit, "%d-%d-%d", &day1, &month1, &year1);
            sscanf(patients[j + 1].DateOfAdmit, "%d-%d-%d", &day2, &month2, &year2);

            // Compare the dates
            if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2))
            {
                // Swap patients
                struct patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Sorted Patients by Date of Admission:\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber    Disease    DoctorID    Address    DateOfAdmit\n--------------------------------------------------");

    // Display sorted patients
    for (i = 0; i < count; i++)
    {
        printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %d    %-3s    %s", patients[i].id, patients[i].Name, patients[i].gender, patients[i].age, patients[i].phoneno, patients[i].disease, patients[i].doc_id, patients[i].address, patients[i].DateOfAdmit);
    }

    fclose(fp);
}
void sortPatientsByDisease()
{
    FILE *fp;
    int count = 0;
    fp = fopen("patients.dat", "r");

    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // Count the number of patients
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        count++;
    }

    rewind(fp);

    // Read patients into an array
    struct patient patients[count];
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        patients[i] = p;
        i++;
    }

    // Sort the array of patients by disease using bubble sort
    int j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            // Compare the diseases
            if (strcmp(patients[j].disease, patients[j + 1].disease) > 0)
            {
                // Swap patients
                struct patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Sorted Patients by Disease:\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber    Disease    DoctorID    Address    DateOfAdmit\n--------------------------------------------------");

    // Display sorted patients
    for(i=0;i<count;i++)
    {
        printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %d    %-3s    %s", patients[i].id, patients[i].Name, patients[i].gender, patients[i].age, patients[i].phoneno, patients[i].disease, patients[i].doc_id, patients[i].address, patients[i].DateOfAdmit);
    }

    fclose(fp);
}
void sortPatientsByDoctorName()
{
    FILE *fp;
    int count = 0;
    fp = fopen("patients.dat", "r");

    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // Count the number of patients
    while(fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        count++;
    }

    rewind(fp);

    // Read patients into an array
    struct patient patients[count];
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        patients[i] = p;
        i++;
    }

    // Sort the array of patients by doctor's name using bubble sort
    int j;
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            // Compare the doctor's names
            if (strcmp(patients[j].doctorName, patients[j + 1].doctorName) > 0)
            {
                // Swap patients
                struct patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Sorted Patients by Doctor's Name:\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber    Disease    DoctorName    Address    DateOfAdmit\n--------------------------------------------------");

    // Display sorted patients
    for(i=0;i < count;i++)
    {
        printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %-12s    %-3s    %s", patients[i].id, patients[i].Name, patients[i].gender, patients[i].age, patients[i].phoneno, patients[i].disease, patients[i].doctorName, patients[i].address, patients[i].DateOfAdmit);
    }

    fclose(fp);
}
void sortPatientsByDocId()
{
    FILE *fp;
    int count = 0;
    fp = fopen("patients.dat", "r");

    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // Count the number of patients
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        count++;
    }

    rewind(fp);

    // Read patients into an array
    struct patient patients[count];
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        patients[i] = p;
        i++;
    }

    // Sort the array of patients by Doctor ID using bubble sort
    int j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (patients[j].doc_id > patients[j + 1].doc_id)
            {
                // Swap patients
                struct patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Sorted Patients by Doctor ID:\n");
    printf("ID    PatientName    Gender    Age    PhoneNumber    Disease    DoctorID    Address    DateOfAdmit\n--------------------------------------------------");

    // Display sorted patients
    for (i = 0; i < count; i++)
    {
        printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %-10s    %d    %-3s    %s", patients[i].id, patients[i].Name, patients[i].gender, patients[i].age, patients[i].phoneno, patients[i].disease, patients[i].doc_id, patients[i].address, patients[i].DateOfAdmit);
    }

    fclose(fp);
}
void DiplayDoctorByPatientAge()
{
	FILE *fp;
	int age;
	int found = 0; 
	fp=fopen("patients.dat","r");
	
	printf("\nEnter Patient Age:");
	scanf("%d",&age);
	printf("\n<<<PATIENT DETAILS>>>\n");
	printf("ID    PatientName    Gender    Age    PhoneNumber   diease	doc_id    Address\n------------------------------------------------------------------------------------------------------");
	while(fread(&p,sizeof(struct patient),1,fp)>0)
	{
		if(p.age==age)
		{
		
		printf("\n%-4d  %-11s    %-6c    %-3d    %-10s    %s	%d    %s",p.id,p.Name,p.gender,p.age,p.phoneno,p.disease,p.doc_id,p.address);
	}
	found = 1;
	
	}
		if (found!=1){printf("\n there is no patient with the %d age person",age);
		}
	fclose(fp);
		
}
int login()
{ 
	char luname[2][20]={"hospital","7777"},ch;
  	int c,u,p,f; 
 login:      	
f=0; 
do 
{ 
printf("\n\n Login Form.....");
printf("\n\n Enter User Name : ");
scanf("%s",uname);
printf("\n \nEnter Password : ");  
	while((ch=getch())!='\r') 
{ 
   pwd[f++]=ch;
  ch='*';
  printf("%c",ch); 
 	} 
 pwd[f]='\0';
  u=strcmp(uname,luname[0]);
  p=strcmp(pwd,luname[1]); 
 printf("\n\n Please wait Credential Verification is in Process...."); 
 Sleep(5000); 
 system("cls"); 
if(u==0&&p==0) 
{ 
printf("\n HOSPITAL PATIENTS LIST::..................SCR.................\n"); 
 	 	menu();
  	 	return(0); 
} 
 else 
 	{ 
printf("\n\n Credentials are wrong.....please try again....."); 
c++; 
printf("\n\n Left %d attempts",3-c); 
 	} 	 
}while(c<3); 
} 
//REGISTRATION 
int signin(){  
char rname[30],runame[30],profile[2][30],pass[20],repass[20],ch1,ch2,loginpro[2][30],ch;	
int a,c,u,p,f;
FILE *fptr;  
	fptr=fopen("vision.txt","w+");
printf("\n ------------WELCOME TO REGISTRATION (VISION HOSPITAL)---------------"); 
printf("\n NAME \t\t:"); 
scanf("%s",rname);
printf("\n USER NAME(no special characters allowed):"); 
scanf("%s",runame);
strcpy(profile[0],runame);
pw: 
printf("\n PASS WORD \t:");  	
while((ch1=getch())!='\r') 
{ 
pass[f++]=ch1;  	     
ch1='*';  	    
printf("%c",ch1); 
} 
pass[f]='\0';  	
strcpy(profile[1],pass); 
printf("\n PASS WORD (re enter as above)"); 
while((ch2=getch())!='\r') 
{ 
repass[f++]=ch2;  	     
ch2='*';  	     
printf("%c",ch2); 
 	} 
repass[f]='\0';
u=strcmp(pass,repass);  	
if(u!=0) 
{ 
printf("\n\n storing the details...........");  	 	 	
printf("\n\n REGISTRATION DONE SUCCESSFULL........."); 
for(a=0;a<5;a++) 
{ 
	strcpy(profile[f],loginpro[f]); 
} 
fprintf(fptr,"NAME=%s \n USER NAME=%d ,\n PASSWORD=%d",rname,runame,pass);// to not to understand the data by the others in .txt file i have stored my data in integer format   fclose(fptr); 
int f=0; 
system("cls");
 do 
{ 
printf("\n\n Login Form....."); 	  	
printf("\n\n Enter User Name : "); 
scanf("%s",uname);
printf("\n \nEnter Password : ");
while((ch=getch())!='\r') 
{ 
pwd[f++]=ch;  	    
 ch='*';  	    
printf("%c",ch); 
 	} 
 pwd[f]='\0'; 
u=strcmp(uname,profile[0]);
p=strcmp(pwd,profile[1]);
 printf("\n\n Please wait Credential Verification is in Process...."); 
 	Sleep(3);
  	system("cls");
  	if(u==0&&p==0) 
 	{ 
printf("\n *VISION* PATIENTS DATA::...................................\n"); 
 	 	menu();
  	 	return(0); 
 	} 
 	else 
 	{ 
  printf("\n\n Credentials are wrong.....please try again....."); 
 	 	c++; 
 	 	printf("\n\n Left %d attempts",3-c); 
 	} 	 
}while(c<3); 
 	 	 	return(0); 
	 	} 
else 
	 	{ 
 	 	printf("\n enter the valid password "); 
 	 	goto pw;  	 
 	 	} 
} 


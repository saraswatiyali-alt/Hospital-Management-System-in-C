
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[15];
    char phone[20];
    char disease[50];
};

struct Doctor
{
    int id;
    char name[50];
    char specialization[50];
    float fees;
};

struct Appointment
{
    int patientId;
    int doctorId;
    char date[20];
    char time[20];
};

struct MedicalRecord
{
    int patientId;
    char diagnosis[100];
    char medicine[100];
    char instructions[150];
};

struct Patient patients[MAX];
struct Doctor doctors[MAX];
struct Appointment appointments[MAX];
struct MedicalRecord records[MAX];

int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;
int recordCount = 0;

// Register Patient
void registerPatient()
{
    if(patientCount >= MAX)
    {
        printf("\nPatient limit reached!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &patients[patientCount].id);

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].id == patients[patientCount].id)
        {
            printf("\nPatient ID already exists!\n");
            return;
        }
    }

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", patients[patientCount].name);

    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);

    if(patients[patientCount].age < 0 ||
       patients[patientCount].age > 130)
    {
        printf("Invalid age!\n");
        return;
    }

    printf("Enter Gender: ");
    scanf("%14s", patients[patientCount].gender);

    printf("Enter Phone Number: ");
    scanf("%19s", patients[patientCount].phone);

    printf("Enter Disease: ");
    scanf(" %49[^\n]", patients[patientCount].disease);

    patientCount++;

    printf("\nPatient Registered Successfully!\n");
}

// Display Patients
void displayPatients()
{
    if(patientCount == 0)
    {
        printf("\nNo Patient Records Available!\n");
        return;
    }

    printf("\n========== PATIENT DETAILS ==========\n");

    for(int i = 0; i < patientCount; i++)
    {
        printf("\nPatient ID: %d", patients[i].id);
        printf("\nName: %s", patients[i].name);
        printf("\nAge: %d", patients[i].age);
        printf("\nGender: %s", patients[i].gender);
        printf("\nPhone: %s", patients[i].phone);
        printf("\nDisease: %s\n", patients[i].disease);
    }
}

// Search Patient
void searchPatient()
{
    int id, found = 0;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].id == id)
        {
            printf("\nPatient Found!\n");
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            printf("Phone: %s\n", patients[i].phone);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nPatient Not Found!\n");
}

// Add Doctor
void addDoctor()
{
    if(doctorCount >= MAX)
    {
        printf("\nDoctor limit reached!\n");
        return;
    }

    printf("\nEnter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].id);

    for(int i = 0; i < doctorCount; i++)
    {
        if(doctors[i].id == doctors[doctorCount].id)
        {
            printf("Doctor ID already exists!\n");
            return;
        }
    }

    printf("Enter Doctor Name: ");
    scanf(" %49[^\n]", doctors[doctorCount].name);

    printf("Enter Specialization: ");
    scanf(" %49[^\n]", doctors[doctorCount].specialization);

    printf("Enter Consultation Fees: ");
    scanf("%f", &doctors[doctorCount].fees);

    if(doctors[doctorCount].fees < 0)
    {
        printf("Invalid fees!\n");
        return;
    }

    doctorCount++;

    printf("\nDoctor Added Successfully!\n");
}

// Display Doctors
void displayDoctors()
{
    if(doctorCount == 0)
    {
        printf("\nNo Doctors Available!\n");
        return;
    }

    printf("\n========== DOCTOR DETAILS ==========\n");

    for(int i = 0; i < doctorCount; i++)
    {
        printf("\nDoctor ID: %d", doctors[i].id);
        printf("\nName: %s", doctors[i].name);
        printf("\nSpecialization: %s",
               doctors[i].specialization);
        printf("\nConsultation Fees: %.2f\n",
               doctors[i].fees);
    }
}

// Book Appointment
void bookAppointment()
{
    int pid, did;
    int patientFound = 0;
    int doctorFound = 0;

    if(appointmentCount >= MAX)
    {
        printf("\nAppointment limit reached!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &pid);

    printf("Enter Doctor ID: ");
    scanf("%d", &did);

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].id == pid)
            patientFound = 1;
    }

    for(int i = 0; i < doctorCount; i++)
    {
        if(doctors[i].id == did)
            doctorFound = 1;
    }

    if(!patientFound || !doctorFound)
    {
        printf("\nInvalid Patient or Doctor ID!\n");
        return;
    }

    appointments[appointmentCount].patientId = pid;
    appointments[appointmentCount].doctorId = did;

    printf("Enter Appointment Date (DD/MM/YYYY): ");
    scanf("%19s", appointments[appointmentCount].date);

    printf("Enter Appointment Time: ");
    scanf("%19s", appointments[appointmentCount].time);

    appointmentCount++;

    printf("\nAppointment Booked Successfully!\n");
}

// Display Appointments
void displayAppointments()
{
    if(appointmentCount == 0)
    {
        printf("\nNo Appointments Found!\n");
        return;
    }

    printf("\n========== APPOINTMENT DETAILS ==========\n");

    for(int i = 0; i < appointmentCount; i++)
    {
        printf("\nPatient ID: %d",
               appointments[i].patientId);

        printf("\nDoctor ID: %d",
               appointments[i].doctorId);

        printf("\nDate: %s",
               appointments[i].date);

        printf("\nTime: %s\n",
               appointments[i].time);
    }
}

// Add Medical Record
void addMedicalRecord()
{
    int id, found = 0;

    if(recordCount >= MAX)
    {
        printf("\nRecord limit reached!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].id == id)
        {
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nPatient Not Found!\n");
        return;
    }

    records[recordCount].patientId = id;

    printf("Enter Diagnosis: ");
    scanf(" %99[^\n]", records[recordCount].diagnosis);

    printf("Enter Prescription: ");
    scanf(" %99[^\n]", records[recordCount].medicine);

    printf("Enter Medical Instructions: ");
    scanf(" %149[^\n]", records[recordCount].instructions);

    recordCount++;

    printf("\nMedical Record Saved Successfully!\n");
}

// Display Medical Records
void displayMedicalRecords()
{
    int id, found = 0;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].patientId == id)
        {
            printf("\n========== MEDICAL REPORT ==========\n");

            printf("Patient ID: %d\n",
                   records[i].patientId);

            printf("Diagnosis: %s\n",
                   records[i].diagnosis);

            printf("Prescription: %s\n",
                   records[i].medicine);

            printf("Instructions: %s\n",
                   records[i].instructions);

            found = 1;
        }
    }

    if(!found)
        printf("\nNo Medical Records Found!\n");
}

// Generate Bill
void generateBill()
{
    int id, found = 0;
    float consultation, medicine, room, total;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].id == id)
        {
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nPatient Not Found!\n");
        return;
    }

    printf("\nEnter Consultation Charges: ");
    scanf("%f", &consultation);

    printf("Enter Medicine Charges: ");
    scanf("%f", &medicine);

    printf("Enter Room Charges: ");
    scanf("%f", &room);

    if(consultation < 0 || medicine < 0 || room < 0)
    {
        printf("\nInvalid charges!\n");
        return;
    }

    total = consultation + medicine + room;

    printf("\n========== HOSPITAL BILL ==========\n");

    printf("Patient ID: %d\n", id);
    printf("Patient Name: ");

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].id == id)
            printf("%s\n", patients[i].name);
    }

    printf("----------------------------------\n");
    printf("Consultation: Rs. %.2f\n", consultation);
    printf("Medicine: Rs. %.2f\n", medicine);
    printf("Room Charges: Rs. %.2f\n", room);
    printf("----------------------------------\n");
    printf("Total Bill: Rs. %.2f\n", total);
    printf("==================================\n");
}

// Main Menu
int main()
{
    int choice;

    do
    {
        printf("\n\n");
        printf("====================================\n");
        printf("       HOSPITAL MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Register Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Add Doctor\n");
        printf("5. Display Doctors\n");
        printf("6. Book Appointment\n");
        printf("7. Display Appointments\n");
        printf("8. Add Medical Record\n");
        printf("9. Display Medical Records\n");
        printf("10. Generate Hospital Bill\n");
        printf("11. Exit\n");

        printf("====================================\n");
        printf("Enter Your Choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("\nInvalid Input!\n");
            break;
        }

        switch(choice)
        {
            case 1:
                registerPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                addDoctor();
                break;

            case 5:
                displayDoctors();
                break;

            case 6:
                bookAppointment();
                break;

            case 7:
                displayAppointments();
                break;

            case 8:
                addMedicalRecord();
                break;

            case 9:
                displayMedicalRecords();
                break;

            case 10:
                generateBill();
                break;

            case 11:
                printf("\nThank You for Using Hospital System!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while(choice != 11);

    return 0;
}

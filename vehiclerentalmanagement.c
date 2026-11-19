#include <stdio.h>
#include <string.h>

#define MAX 100

enum VehicleType
{
    CAR = 1,
    BIKE = 2
};

enum RentalStatus
{
    AVAILABLE = 1,
    RENTED = 2
};

union VehicleDetails
{
    int seats;
    int engineCapacity;
};

struct Vehicle
{
    int id;
    char name[30];
    char brand[30];
    enum VehicleType type;
    enum RentalStatus status;
    union VehicleDetails details;
};

struct Vehicle v[MAX];
int count = 0;

int searchVehicle(int id)
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(v[i].id == id)
            return i;
    }

    return -1;
}

void addVehicle()
{
    int id, choice;

    if(count >= MAX)
    {
        printf("\nVehicle limit reached!");
        return;
    }

    printf("\nEnter Vehicle ID: ");
    scanf("%d", &id);

    if(searchVehicle(id) != -1)
    {
        printf("\nVehicle ID already exists!");
        return;
    }

    v[count].id = id;

    printf("Enter Vehicle Name: ");
    scanf("%s", v[count].name);

    printf("Enter Brand: ");
    scanf("%s", v[count].brand);

    printf("\nSelect Vehicle Type:");
    printf("\n1. Car");
    printf("\n2. Bike");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        v[count].type = CAR;

        printf("Enter Number of Seats: ");
        scanf("%d", &v[count].details.seats);
    }
    else if(choice == 2)
    {
        v[count].type = BIKE;

        printf("Enter Engine Capacity: ");
        scanf("%d", &v[count].details.engineCapacity);
    }
    else
    {
        printf("\nInvalid Vehicle Type!");
        return;
    }

    v[count].status = AVAILABLE;
    count++;

    printf("\nVehicle Added Successfully!");
}

void displayAll()
{
    int i;

    if(count == 0)
    {
        printf("\nNo Vehicles Found!");
        return;
    }

    for(i = 0; i < count; i++)
    {
        printf("\n\nVehicle ID: %d", v[i].id);
        printf("\nVehicle Name: %s", v[i].name);
        printf("\nBrand: %s", v[i].brand);

        if(v[i].type == CAR)
        {
            printf("\nType: Car");
            printf("\nNumber of Seats: %d",
                   v[i].details.seats);
        }
        else
        {
            printf("\nType: Bike");
            printf("\nEngine Capacity: %d CC",
                   v[i].details.engineCapacity);
        }

        if(v[i].status == AVAILABLE)
            printf("\nStatus: Available");
        else
            printf("\nStatus: Rented");
    }
}

void searchVehicleDetails()
{
    int id, pos;

    printf("\nEnter Vehicle ID to Search: ");
    scanf("%d", &id);

    pos = searchVehicle(id);

    if(pos == -1)
    {
        printf("\nVehicle Not Found!");
    }
    else
    {
        printf("\nVehicle Found!");
        printf("\nID: %d", v[pos].id);
        printf("\nName: %s", v[pos].name);
        printf("\nBrand: %s", v[pos].brand);

        if(v[pos].type == CAR)
        {
            printf("\nType: Car");
            printf("\nSeats: %d",
                   v[pos].details.seats);
        }
        else
        {
            printf("\nType: Bike");
            printf("\nEngine Capacity: %d CC",
                   v[pos].details.engineCapacity);
        }

        if(v[pos].status == AVAILABLE)
            printf("\nStatus: Available");
        else
            printf("\nStatus: Rented");
    }
}

void rentVehicle()
{
    int id, pos;

    printf("\nEnter Vehicle ID to Rent: ");
    scanf("%d", &id);

    pos = searchVehicle(id);

    if(pos == -1)
    {
        printf("\nVehicle Not Found!");
    }
    else if(v[pos].status == RENTED)
    {
        printf("\nVehicle is Already Rented!");
    }
    else
    {
        v[pos].status = RENTED;
        printf("\nVehicle Rented Successfully!");
    }
}

void returnVehicle()
{
    int id, pos;

    printf("\nEnter Vehicle ID to Return: ");
    scanf("%d", &id);

    pos = searchVehicle(id);

    if(pos == -1)
    {
        printf("\nVehicle Not Found!");
    }
    else if(v[pos].status == AVAILABLE)
    {
        printf("\nVehicle is Already Available!");
    }
    else
    {
        v[pos].status = AVAILABLE;
        printf("\nVehicle Returned Successfully!");
    }
}

void displayAvailable()
{
    int i, found = 0;

    printf("\n\nAvailable Vehicles:");

    for(i = 0; i < count; i++)
    {
        if(v[i].status == AVAILABLE)
        {
            printf("\nID: %d", v[i].id);
            printf("\nName: %s", v[i].name);
            printf("\nBrand: %s", v[i].brand);
            found = 1;
        }
    }

    if(found == 0)
        printf("\nNo Available Vehicles!");
}

int main(void)
{
    int choice;

    do
    {
        printf("\n\n===== VEHICLE RENTAL MANAGEMENT SYSTEM =====");

        printf("\n1. Add Vehicle");
        printf("\n2. Display All Vehicles");
        printf("\n3. Search Vehicle");
        printf("\n4. Rent Vehicle");
        printf("\n5. Return Vehicle");
        printf("\n6. Display Available Vehicles");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addVehicle();
                break;

            case 2:
                displayAll();
                break;

            case 3:
                searchVehicleDetails();
                break;

            case 4:
                rentVehicle();
                break;

            case 5:
                returnVehicle();
                break;

            case 6:
                displayAvailable();
                break;

            case 7:
                printf("\nThank You!");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while(choice != 7);

    return 0;
}
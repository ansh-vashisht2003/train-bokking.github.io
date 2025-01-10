#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib> // for rand()
#include <limits>  // for input validation
#include <vector>
#include <algorithm>

using namespace std;

const string ADMIN_PASSWORD = "PASSWORD"; // Hard-coded admin password for simplicity

class Train
{
private:
    int trainno, nofafseat, nofasseat, noffsseat, nofacseat, nofssseat;
    char trainname[60], startingpoint[60], destination[60];

public:
    Train()
    {
        trainno = 0;
        nofafseat = nofasseat = noffsseat = nofacseat = nofssseat = 0;
        strcpy(trainname, "");
        strcpy(startingpoint, "");
        strcpy(destination, "");
    }
    int getAvailableSeats(const string& seatType) const {
    if (seatType == "A/C First Class") return nofafseat;
    else if (seatType == "A/C Second Class") return nofasseat;
    else if (seatType == "First Class Sleeper") return noffsseat;
    else if (seatType == "A/C Chair Car") return nofacseat;
    else if (seatType == "Second Class Sleeper") return nofssseat;
    return 0; // For invalid seat type
    }

    bool bookSeats(const char* classType, int numSeats) {
    if (strcmp(classType, "A/C First Class") == 0 && nofafseat >= numSeats) {
        nofafseat -= numSeats;
        return true;
    } else if (strcmp(classType, "A/C Second Class") == 0 && nofasseat >= numSeats) {
        nofasseat -= numSeats;
        return true;
    } else if (strcmp(classType, "First Class Sleeper") == 0 && noffsseat >= numSeats) {
        noffsseat -= numSeats;
        return true;
    } else if (strcmp(classType, "A/C Chair Car") == 0 && nofacseat >= numSeats) {
        nofacseat -= numSeats;
        return true;
    } else if (strcmp(classType, "Second Class Sleeper") == 0 && nofssseat >= numSeats) {
        nofssseat -= numSeats;
        return true;
    }
    return false; // If no match or insufficient seats
}


    bool bookSeats(const string& seatType, int numSeats) {
    if (seatType == "A/C First Class" && nofafseat >= numSeats) {
        nofafseat -= numSeats;
        return true;
    } else if (seatType == "A/C Second Class" && nofasseat >= numSeats) {
        nofasseat -= numSeats;
        return true;
    } else if (seatType == "First Class Sleeper" && noffsseat >= numSeats) {
        noffsseat -= numSeats;
        return true;
    } else if (seatType == "A/C Chair Car" && nofacseat >= numSeats) {
        nofacseat -= numSeats;
        return true;
    } else if (seatType == "Second Class Sleeper" && nofssseat >= numSeats) {
        nofssseat -= numSeats;
        return true;
    }
    return false; // Not enough seats or invalid seat type
}


    void input();
    void display() const;
    int returnTrainNo() const { return trainno; }
    void updateSeats(int af, int as, int fs, int ac, int ss);

    // Add a getter function to access the trainname
    const char* getTrainName() const { return trainname; }
};

void Train::input()
{
    cout << "Enter Train Number: ";
    cin >> trainno;
    cout << "Enter Train Name: ";
    cin.ignore();
    cin.getline(trainname, 60);
    cout << "Enter Starting Point: ";
    cin.getline(startingpoint, 60);
    cout << "Enter Destination: ";
    cin.getline(destination, 60);
    cout << "Enter Number of A/C First Class Seats: ";
    cin >> nofafseat;
    cout << "Enter Number of A/C Second Class Seats: ";
    cin >> nofasseat;
    cout << "Enter Number of First Class Sleeper Seats: ";
    cin >> noffsseat;
    cout << "Enter Number of A/C Chair Car Seats: ";
    cin >> nofacseat;
    cout << "Enter Number of Second Class Sleeper Seats: ";
    cin >> nofssseat;
}

void Train::display() const
{
    cout << "Train Number: " << trainno << endl;
    cout << "Train Name: " << trainname << endl;
    cout << "Starting Point: " << startingpoint << endl;
    cout << "Destination: " << destination << endl;
    cout << "Available A/C First Class Seats: " << nofafseat << endl;
    cout << "Available A/C Second Class Seats: " << nofasseat << endl;
    cout << "Available First Class Sleeper Seats: " << noffsseat << endl;
    cout << "Available A/C Chair Car Seats: " << nofacseat << endl;
    cout << "Available Second Class Sleeper Seats: " << nofssseat << endl;
}

void Train::updateSeats(int af, int as, int fs, int ac, int ss)
{
    nofafseat -= af;
    nofasseat -= as;
    noffsseat -= fs;
    nofacseat -= ac;
    nofssseat -= ss;
}


class Ticket
{
private:
    int resNo, trainNo, age;
    char passengerName[60], status[40], classType[20];

public:
    Ticket() : resNo(0), trainNo(0), age(0)
    {
        strcpy(passengerName, "");
        strcpy(status, "Booked");
        strcpy(classType, "");
    }
    const char* getClassType() const { return classType; }

    void bookTicket(int tNo);
    void display() const;
    int getReservationNo() const { return resNo; }
};

void Ticket::bookTicket(int tNo)
{
    resNo = rand() % 10000 + 1000;
    trainNo = tNo;
    cout << "Enter Passenger Name: ";
    cin.ignore();
    cin.getline(passengerName, 60);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Class Type (A/C First Class, A/C Second Class, Sleeper, Chair Car, Second Class Sleeper): ";
    cin.ignore();
    cin.getline(classType, 20);
    strcpy(status, "Booked");
    cout << "Ticket booked successfully! Your reservation number is " << resNo << endl;
}

void Ticket::display() const
{
    cout << "Reservation Number: " << resNo << endl;
    cout << "Passenger Name: " << passengerName << endl;
    cout << "Age: " << age << endl;
    cout << "Train Number: " << trainNo << endl;
    cout << "Class Type: " << classType << endl;
    cout << "Status: " << status << endl;
}

class User
{
private:
    char username[60];
    char password[60];

public:
    void deleteUser();
    void signup();
    bool login();
    void changePassword();
    bool isUsernameExists(const char *uname);
};

bool User::isUsernameExists(const char *uname)
{
    ifstream userFile("users.dat", ios::binary);
    User user;
    while (userFile.read(reinterpret_cast<char *>(&user), sizeof(User)))
    {
        if (strcmp(user.username, uname) == 0)
        {
            userFile.close();
            return true;
        }
    }
    userFile.close();
    return false;
}

void User::signup()
{
    cout << "Enter a username: ";
    cin.ignore();
    cin.getline(username, 60);

    // Check if the username is empty
    if (strlen(username) == 0)
    {
        cout << "Username cannot be empty. Please try again.\n";
        cout << "Press Enter to return to the main menu.";
        cin.get();
        return;
    }

    if (isUsernameExists(username))
    {
        cout << "Username already exists. Please choose a different username.\n";
        cout << "Press Enter to return to the main menu.";
        cin.get();
        return;
    }

    cout << "Enter a password: ";
    cin.getline(password, 60);

    // Check if the password is empty
    if (strlen(password) == 0)
    {
        cout << "Password cannot be empty. Please try again.\n";
        cout << "Press Enter to return to the main menu.";
        cin.get();
        return;
    }

    ofstream userFile("users.dat", ios::binary | ios::app);
    userFile.write(reinterpret_cast<char *>(this), sizeof(User));
    userFile.close();
    cout << "Signup successful! You can now log in.\n";
    cout << "Press Enter to return to the main menu.";
    cin.get();
}

bool User::login()
{
    char inputUsername[60], inputPassword[60];
    cout << "Enter your username: ";
    cin.ignore();
    cin.getline(inputUsername, 60);
    cout << "Enter your password: ";
    cin.getline(inputPassword, 60);

    ifstream userFile("users.dat", ios::binary);
    User user;
    while (userFile.read(reinterpret_cast<char *>(&user), sizeof(User)))
    {
        if (strcmp(user.username, inputUsername) == 0 && strcmp(user.password, inputPassword) == 0)
        {
            cout << "Login successful!\n";
            return true;
        }
    }
    userFile.close();
    cout << "Invalid credentials. Returning to the main menu.\n";
    cout << "Press Enter to return to the main menu.";
    cin.get();
    return false;
}

void User::deleteUser()
{
    char inputUsername[60], inputPassword[60];
    cout << "Enter the username of the account to delete: ";
    cin.ignore();
    cin.getline(inputUsername, 60);
    cout << "Enter the password: ";
    cin.getline(inputPassword, 60);

    ifstream userFile("users.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    bool userDeleted = false;
    User user;

    while (userFile.read(reinterpret_cast<char *>(&user), sizeof(User)))
    {
        if (strcmp(user.username, inputUsername) == 0 && strcmp(user.password, inputPassword) == 0)
        {
            userDeleted = true; // Mark that the user has been found and deleted
            cout << "User account deleted successfully!\n";
        }
        else
        {
            tempFile.write(reinterpret_cast<char *>(&user), sizeof(User)); // Write other users to the temp file
        }
    }

    userFile.close();
    tempFile.close();

    // Replace the original file with the updated file
    remove("users.dat");
    rename("temp.dat", "users.dat");

    if (!userDeleted)
    {
        cout << "Username or password is incorrect. No account deleted.\n";
    }
}

void User::changePassword()
{
    char inputUsername[60], oldPassword[60], newPassword[60];
    cout << "Enter your username: ";
    cin.ignore();
    cin.getline(inputUsername, 60);
    cout << "Enter your current password: ";
    cin.getline(oldPassword, 60);

    fstream userFile("users.dat", ios::binary | ios::in | ios::out);
    User user;
    bool found = false;
    int pos;
    while (userFile.read(reinterpret_cast<char *>(&user), sizeof(User)))
    {
        pos = userFile.tellg();
        if (strcmp(user.username, inputUsername) == 0 && strcmp(user.password, oldPassword) == 0)
        {
            found = true;
            cout << "Enter your new password: ";
            cin.getline(newPassword, 60);

            // Check if new password is the same as the old one
            if (strcmp(oldPassword, newPassword) == 0)
            {
                cout << "New password cannot be the same as the old password.\n";
                break;
            }

            strcpy(user.password, newPassword);
            userFile.seekp(pos - sizeof(User));
            userFile.write(reinterpret_cast<char *>(&user), sizeof(User));
            cout << "Password changed successfully!\n";
            break;
        }
    }
    if (!found)
    {
        cout << "Username or current password is incorrect.\n";
    }
    userFile.close();
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void addTrain()
{
    Train newTrain;
    newTrain.input();

    // Open the file to check for existing trains
    ifstream inFile("trains.dat", ios::binary);
    if (!inFile)
    {
        cout << "Train file is empty or doesn't exist. Proceeding to add train...\n";
    }

    Train existingTrain;
    bool trainExists = false;

    while (inFile.read(reinterpret_cast<char*>(&existingTrain), sizeof(existingTrain)))
    {
        // Check if either the train number or name already exists
        if (existingTrain.returnTrainNo() == newTrain.returnTrainNo() ||
            strcmp(existingTrain.getTrainName(), newTrain.getTrainName()) == 0)
        {
            trainExists = true;
            break;
        }
    }
    inFile.close();

    // If a duplicate train number or name is found, display an error message
    if (trainExists)
    {
        cout << "A train with the same number " << newTrain.returnTrainNo() << " or name '" 
             << newTrain.getTrainName() << "' already exists.\n";
    }
    else
    {
        // Otherwise, add the new train
        ofstream outFile("trains.dat", ios::binary | ios::app);
        outFile.write(reinterpret_cast<char*>(&newTrain), sizeof(newTrain));
        outFile.close();
        cout << "Train added successfully!\n";
    }

    cout << "Press Enter to return to the admin menu.";
    cin.ignore();
    cin.get();  // Wait for Enter to return
}




void showTrains()
{
    Train tr;
    ifstream file("trains.dat", ios::binary);
    if (!file)
    {
        cout << "No trains found!\n";
        return;
    }
    while (file.read(reinterpret_cast<char *>(&tr), sizeof(tr)))
    {
        tr.display();
        cout << "-----------------------------\n";
    }
    file.close();

    cout << "Press Enter to return to the admin menu.";
    cin.ignore();
    cin.get();
}

void bookTicket() {
    int trainNo;
    cout << "Enter Train Number for Booking: ";
    cin >> trainNo;

    ifstream file("trains.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary); // Temporary file for updates
    Train tr;
    bool found = false;
    bool booked = false;

    while (file.read(reinterpret_cast<char*>(&tr), sizeof(tr))) {
        if (tr.returnTrainNo() == trainNo) {
            found = true;
            
            Ticket ticket;
            ticket.bookTicket(trainNo); // Book ticket and get class type
            
            // Attempt to book seats in the desired class
            if (tr.bookSeats(ticket.getClassType(), 1)) { // Assume 1 seat per ticket
                booked = true;
            } else {
                cout << "Insufficient seats available in the requested class.\n";
            }
        }
        
        tempFile.write(reinterpret_cast<char*>(&tr), sizeof(tr)); // Save updated or original record
    }

    file.close();
    tempFile.close();

    // Replace trains.dat with updated file if booking was successful
    if (booked) {
        remove("trains.dat");
        rename("temp.dat", "trains.dat");
        cout << "Ticket booked successfully.\n";
    } else if (!found) {
        cout << "Train not found.\n";
    } else {
        cout << "Ticket booking failed.\n";
    }
}

void bookSeats(int trainNumber, const string& seatType, int requestedSeats) {
    ifstream inFile("trains.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary | ios::app);
    bool found = false;
    bool bookingSuccess = false;

    Train train;
    while (inFile.read(reinterpret_cast<char*>(&train), sizeof(train))) {
        if (train.returnTrainNo() == trainNumber) {
            found = true;
            if (train.getAvailableSeats(seatType) >= requestedSeats) {
                // Enough seats available; proceed with booking
                if (train.bookSeats(seatType, requestedSeats)) {
                    bookingSuccess = true;
                    cout << "Booking successful! " << requestedSeats << " seats booked.\n";
                }
            } else {
                cout << "Error: Only " << train.getAvailableSeats(seatType) << " seats are available.\n";
            }
        }
        outFile.write(reinterpret_cast<char*>(&train), sizeof(train));
    }
    inFile.close();
    outFile.close();

    if (!found) {
        cout << "Train not found.\n";
    }

    remove("trains.dat");
    rename("temp.dat", "trains.dat");
}



void deleteTrain()
{
    int trainNo;
    cout << "Enter Train Number to Delete: ";
    cin >> trainNo;

    ifstream file("trains.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    bool found = false;
    Train tr;

    while (file.read(reinterpret_cast<char*>(&tr), sizeof(tr)))
    {
        if (tr.returnTrainNo() == trainNo)
        {
            found = true;  // Mark that we've found the train to delete
            cout << "Train with number " << trainNo << " deleted successfully.\n";
        }
        else
        {
            tempFile.write(reinterpret_cast<char*>(&tr), sizeof(tr));  // Write other trains to temp file
        }
    }

    file.close();
    tempFile.close();

    // Replace original file with updated file
    remove("trains.dat");
    rename("temp.dat", "trains.dat");

    if (!found)
    {
        cout << "Train not found.\n";
    }

    cout << "Press Enter to return to the admin menu.";
    cin.ignore();
    cin.get();  // Wait for Enter to return
}


void viewTicket()
{
    int resNo;
    cout << "Enter Reservation Number: ";
    cin >> resNo;

    Ticket ticket;
    ifstream file("tickets.dat", ios::binary);
    bool found = false;
    while (file.read(reinterpret_cast<char *>(&ticket), sizeof(ticket)))
    {
        if (ticket.getReservationNo() == resNo)
        {
            ticket.display();
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
    {
        cout << "Ticket not found!\n";
    }
}

int main()
{
    int choice;
    do
    {
        // clearScreen();
        cout << "TRAIN RESERVATION SYSTEM\n";
        cout << "1. Admin Login\n";
        cout << "2. Passenger Signup\n";
        cout << "3. Passenger Login\n";
        cout << "4. Delete Passenger\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string password;
            cout << "Enter Admin Password: ";
            cin >> password;
            if (password == ADMIN_PASSWORD)
            {
                int adminChoice;
                do
                {
                    clearScreen();
                    cout << "ADMIN MENU\n";
                    cout << "1. Add Train\n";
                    cout << "2. View All Trains\n";
                    cout << "3. Delete a train\n";
                    cout << "4. Back\n";
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    switch (adminChoice)
                    {
                    case 1:
                        addTrain();
                        break;
                    case 2:
                        showTrains();
                        break;
                    case 3:  // Assuming this is the third option for admin
                        deleteTrain();
                        break;

                    case 4:
                        break;
                    default:
                        cout << "Invalid choice.\n";
                    }
                } while (adminChoice != 4);
            }
            else
            {
                cout << "Incorrect password.\n";
            }
            break;
        }
        case 2:
        {
            User user;
            user.signup();
            break;
        }
        case 3:
        {
            User user;
            if (user.login())
            {
                int userChoice;
                do
                {
                    // clearScreen();
                    cout << "PASSENGER MENU\n";
                    cout << "1. Book Ticket\n";
                    cout << "2. View Ticket\n";
                    cout << "3. Change Password\n";
                    cout << "4. Back\n";
                    cout << "Enter your choice: ";
                    cin >> userChoice;

                    switch (userChoice)
                    {
                    case 1:
                        bookTicket();
                        break;
                    case 2:
                        viewTicket();
                        break;
                    case 3:
                        user.changePassword();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Invalid choice.\n";
                    }
                } while (userChoice != 4);
            }
            break;
        }
        case 4:{
            User user;
            user.deleteUser();
            break;
        }
        case 5:
            cout << "Thank you for using the Train Reservation System.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

# Train Reservation System

Welcome to the **Train Reservation System** project. This C++ command-line application allows passengers to book train tickets, manage their accounts, and view their reservations. Administrators can manage trains, add or remove them, and monitor the system.

## Features

### Admin Features
- **Admin Login**: Admins can log in using a hardcoded password.
- **Add Train**: Admins can add a new train with details such as train number, name, starting point, destination, and seat availability.
- **View All Trains**: Admins can view all available trains and their seat availability.
- **Delete Train**: Admins can delete a train by its train number.

### Passenger Features
- **Passenger Signup**: New passengers can create an account with a unique username and password.
- **Passenger Login**: Passengers can log in to the system.
- **Book Ticket**: Passengers can book tickets for various classes (A/C First Class, A/C Second Class, Sleeper, etc.).
- **View Ticket**: Passengers can view their ticket details by providing their reservation number.
- **Change Password**: Passengers can change their password after logging in.

### User Management
- **Delete Account**: Passengers can delete their account from the system by entering their username and password.
- **Change Password**: Passengers can change their password after verifying their old one.


## Files Used
- **`users.dat`**: Stores user data (username, password).
- **`trains.dat`**: Stores train details (train number, name, seats availability).
- **`tickets.dat`**: Stores ticket reservation details (reservation number, train number, passenger details).

## Contributions

If you want to contribute to this project, feel free to open a pull request! Improvements and enhancements are always welcome.

## License

This project is open-source and available under the MIT License. See the [LICENSE](LICENSE) file for more details.

Enjoy the train booking experience!

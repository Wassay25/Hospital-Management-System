# MediCore Hospital Management System

Hey, welcome to MediCore! This is a hospital management system I built as part of an OOP project for Spring 2026. It's a single-file C++ application that handles everything from patient registration to billing and prescriptions, all wrapped up in a graphical interface using SFML. Below you'll find everything you need to get it running and understand how it works.


## What This Actually Does

MediCore is a role-based hospital management system with three types of users: patients, doctors, and an admin. Each role gets its own dashboard and set of features. Here's a quick breakdown:

**Patients can:**
- Register and log in with a personal account
- Book, view, and cancel appointments with doctors
- View their prescriptions and medical history
- Check and pay outstanding bills
- Top up their account balance

**Doctors can:**
- Log in and see their upcoming appointments
- Write prescriptions for patients
- Mark appointments as completed
- View their patient list

**Admin can:**
- Add and remove doctors from the system
- View all patients, doctors, appointments, bills, and prescriptions
- Discharge patients (archives their full records)
- Monitor the security log (login attempts, successes/failures)
- Manage system-wide data


## Prerequisites

Before you try to compile, make sure you have the following installed:

- A C++17-compatible compiler (GCC or MinGW on Windows works fine)
- [SFML 2.x](https://www.sfml-dev.org/), specifically these libraries:
  - `sfml-graphics`
  - `sfml-window`
  - `sfml-audio`
  - `sfml-system`

If you're on Ubuntu/Debian, you can grab SFML with:

```bash
sudo apt-get install libsfml-dev
```

On Windows, download the SFML SDK from their website and link it manually in your compiler settings.


## How to Compile

Open a terminal in the project directory and run:

```bash
g++ -std=c++17 Hospital_Main.cpp -o MediCore \
    -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
```

On Windows with MinGW, it would look something like:

```bash
g++ -std=c++17 Hospital_Main.cpp -o MediCore.exe \
    -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
```

Once compiled, just run `./MediCore` (or `MediCore.exe` on Windows) and the GUI window should pop up.


## Data Files

MediCore uses plain text CSV files to store and persist data between sessions. These files are created/read automatically from the same directory as the executable. Here's what each one holds:

| File | Contents |
|---|---|
| `patients.txt` | All registered patient records |
| `doctors.txt` | All doctor records |
| `appointments.txt` | Appointment history |
| `bills.txt` | Billing records |
| `prescriptions.txt` | Prescription data |
| `admin.txt` | Admin account credentials |
| `security_log.txt` | Login attempt logs (success/failure) |
| `discharged.txt` | Archived records of discharged patients |

> **Important:** Don't manually edit these files unless you really know what you're doing. The system reads them in a specific CSV format and things will break if the formatting is off.


## Logging In

When you launch the app, you'll see the main menu with options to log in as a Patient, Doctor, or Admin, or to register as a new patient.

**Admin credentials** are stored in `admin.txt`. If the file doesn't exist on first run, you'll need to create it manually with the admin's ID and password in CSV format.

**Patients** register through the GUI. Just hit "Register as Patient" and fill in the form. Your ID gets auto-assigned and shown to you after registration. Hold onto it, you'll need it to log in.

**Doctors** are added by the admin from the Admin Dashboard.


## Appointment Slots

Appointments are available in hourly slots between 9 AM and 4 PM:

```
09:00, 10:00, 11:00, 12:00, 13:00, 14:00, 15:00, 16:00
```

The system automatically checks if a slot is already taken for a specific doctor on a given date so you don't have to worry about double-booking.


## Input Rules

A few things the system enforces when you're filling out forms:

- **Contact number** must be exactly 11 digits, numbers only
- **Password** minimum 6 characters
- **Age** must be between 1 and 149
- **Gender** only `M` or `F` accepted (case-insensitive)
- **Dates** must be in `DD-MM-YYYY` format and can't be in the past

If you enter something invalid, the status bar at the bottom of the screen will tell you what went wrong.


## Project Structure

Everything lives in a single file (`Hospital_Main.cpp`), with the backend logic and the SFML GUI all combined. Here's a rough outline of how it's organized internally:

- **Helper functions** custom string handling, parsing, and number conversion (no `<string>` or `<sstream>` used, intentionally)
- **Exception classes** `HospitalException`, `FileNotFoundException`, `InsufficientFundsException`, `SlotUnavailableException`, `InvalidInputException`
- **Entity classes** `Person` (base), `Patient`, `Doctor`, `Admin`, `Appointment`, `Bill`, `Prescription`
- **`Storage<T>` template** generic fixed-size array container (max 100 records per type) used for all entities
- **`FileHandler`** handles all file I/O (loading and writing CSV data, security log, archiving)
- **`Hospital`** the central class that ties everything together; manages all storage containers
- **`Validator`** static methods for validating all user inputs
- **GUI layer** SFML-based rendering of all screens, dashboards, sidebar navigation, and form widgets


## C++ Concepts Used

This project covers a fairly wide range of C++ and OOP concepts. Here's a rundown of everything that shows up in the code and what role it plays:

**Object-Oriented Programming**

The whole system is built around classes. `Person` is an abstract base class that `Patient`, `Doctor`, and `Admin` all inherit from; that's inheritance in action. `Person` declares `display()` and `toFileString()` as pure virtual functions, which means every subclass is forced to provide its own implementation. That's polymorphism. The `virtual` keyword on the destructor also ensures proper cleanup when deleting objects through a base class pointer.

**Templates**

The `Storage<T>` class is a generic container built using C++ templates. Instead of writing a separate array-based list for patients, doctors, appointments, and so on, one template class handles all of them. It supports adding, finding by ID, removing, and clearing records, all without knowing the specific type at compile time.

**Operator Overloading**

Several operators are overloaded to make the entity classes more expressive. `Patient` overloads `+=` and `-=` to add/subtract from the account balance, and `==` to compare two patients by ID. `Appointment` overloads `==` to check for slot conflicts (same doctor, date, and time slot, with neither being cancelled). The `<<` operator is overloaded on `Patient` and `Appointment` to enable printing to `cout` in a readable format.

**Exception Handling**

The project uses a custom exception hierarchy rooted at `HospitalException`. Specific exceptions like `FileNotFoundException`, `InsufficientFundsException`, `SlotUnavailableException`, and `InvalidInputException` all extend it. These are thrown and caught throughout the system to handle error conditions gracefully rather than just crashing or printing an error and continuing.

**File I/O**

All data persistence is done manually using `ifstream` and `ofstream`. The `FileHandler` class handles loading each entity type from its CSV file on startup, writing everything back on changes, appending new records, and managing the security log and discharged patient archive. There's no database, just flat text files read line by line.

**Inheritance and Abstract Classes**

`Person` is an abstract class (it can't be instantiated directly because of its pure virtual methods). `Patient`, `Doctor`, and `Admin` all inherit from `Person` and implement the required methods. This enforces a consistent interface across all user types while letting each class define its own behaviour.

**Static Methods**

The `Validator` class uses only static methods, meaning you call them directly on the class (`Validator::isValidDate(...)`) without needing an instance. Same goes for `FileHandler`. This is a common pattern for utility classes that don't need to hold any state.

**Encapsulation**

All class data members are private or protected, with public getters and setters controlling access. For example, `Patient`'s balance, contact number, and password can't be modified directly from outside the class; you have to go through the provided methods. This keeps the internal state consistent and prevents accidental corruption.

**Custom String and Number Handling**

Since `std::string` and standard library utilities like `atoi`, `sprintf`, etc. were intentionally avoided, the project implements its own versions: `copyString`, `compareStrings`, `appendString`, `convertStringToInt`, `convertDoubleToString`, and so on. These work directly on `char[]` arrays and give a clear picture of how string operations work at a lower level.

**Composition**

The `Hospital` class is a strong example of composition. It directly owns `Storage<Patient>`, `Storage<Doctor>`, `Storage<Appointment>`, `Storage<Bill>`, `Storage<Prescription>`, and an `Admin` object as member variables. None of these exist independently outside of `Hospital`; they are created and destroyed alongside it. This is composition in the classic sense: the whole controls the lifetime of its parts.

**Association**

Association shows up in how `Appointment`, `Bill`, and `Prescription` relate to `Patient` and `Doctor`. Rather than holding actual objects, these classes store IDs (`patientID`, `doctorID`, `ownerPatientID`, `authorDoctorID`, `linkedAppointmentID`) to reference other entities. The classes know about each other and are logically connected, but neither owns the other. At runtime, `Hospital` resolves these relationships using `findPatientByID()` and `findDoctorByID()`. This is association through ID-based referencing, a common pattern when you want relationships without tight coupling.

**Sorting**

The `Hospital` class implements a bubble sort (`sortAppointmentsByDateAscending`) to order appointments chronologically. Dates are converted to sortable integers in `YYYYMMDD` format first, making numerical comparison straightforward.

**SFML (Graphics Library)**

The GUI is built entirely with SFML. The rendering loop handles window events, mouse clicks, keyboard input, and draws all screens, buttons, text fields, sidebars, and status messages. SFML's `sf::RenderWindow`, `sf::Font`, `sf::Text`, `sf::RectangleShape`, and `sf::FloatRect` are the main components used throughout.


## Known Limitations

- The `Storage<T>` container has a hard cap of **100 records per entity type** (100 patients, 100 doctors, etc.). This is intentional for the scope of the project but worth keeping in mind.
- All string handling is done manually with `char[]` arrays, no `std::string`. This was a deliberate OOP constraint for the project.
- There's no encryption on passwords stored in the data files. This is a university project, not a production system, so please don't use real credentials.
- The system date and time are read at startup; there's no live clock refresh during runtime.


## A Note on the Code Style

You'll notice the code avoids a lot of the standard library conveniences (`std::string`, `std::vector`, `atoi`, `sprintf`, etc.) in favour of custom implementations. This was on purpose; the project required demonstrating low-level understanding of how these things work under the hood. So yes, there's a hand-rolled `copyString`, `convertStringToInt`, and even a `convertDoubleToString` in there. It's not the most elegant thing in the world, but it works.


## Troubleshooting

**The window doesn't open / crashes immediately**
Make sure the SFML DLLs (on Windows) are in the same directory as your executable, or that SFML is properly installed system-wide.

**"File not found" errors on startup**
The system tries to load data files on launch. If they don't exist yet, it may throw a `FileNotFoundException`. You can safely ignore this on a first run; the files will be created as you add data.

**Login says "invalid credentials" but I know it's right**
Double-check that you're selecting the correct role (Patient / Doctor / Admin) before logging in. The system authenticates against role-specific records, so logging into the Patient portal with a Doctor ID won't work.


That's pretty much everything. If something's broken or unclear, feel free to dig through the code; it's all in one file and the sections are clearly marked with comment banners. Good luck!

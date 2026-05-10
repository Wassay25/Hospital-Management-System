//// ============================================================
//// MediCore Hospital Management System
//// Combined Single-File Build (Backend + GUI)
//// OOP Project - Spring 2026
////
//// Compile with:
////   g++ -std=c++17 MediCore_Combined.cpp -o MediCore \
////       -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
//// ============================================================
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <ctime>
//#include <cmath>
//#include <cstring>
//#include <cstdio>
//#include <cstdlib>
//#include <string>
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//
//using namespace std;
//
//// ============================================================
//// CUSTOM STRING / NUMERIC HELPERS
//// ============================================================
//
//int calculateStringLength(const char* str) {
//    int index = 0;
//    while (str[index]) index++;
//    return index;
//}
//
//void copyString(char* destination, const char* source) {
//    int index = 0;
//    while (source[index]) { destination[index] = source[index]; index++; }
//    destination[index] = '\0';
//}
//
//int compareStrings(const char* first, const char* second) {
//    int index = 0;
//    while (first[index] && second[index]) {
//        if (first[index] != second[index])
//            return (unsigned char)first[index] - (unsigned char)second[index];
//        index++;
//    }
//    return (unsigned char)first[index] - (unsigned char)second[index];
//}
//
//void appendString(char* destination, const char* source) {
//    int destinationEnd = calculateStringLength(destination);
//    int sourceIndex = 0;
//    while (source[sourceIndex]) {
//        destination[destinationEnd + sourceIndex] = source[sourceIndex];
//        sourceIndex++;
//    }
//    destination[destinationEnd + sourceIndex] = '\0';
//}
//
//int compareStringsCaseInsensitive(const char* first, const char* second) {
//    int index = 0;
//    while (first[index] && second[index]) {
//        char charA = (char)tolower((unsigned char)first[index]);
//        char charB = (char)tolower((unsigned char)second[index]);
//        if (charA != charB) return charA - charB;
//        index++;
//    }
//    return tolower((unsigned char)first[index]) - tolower((unsigned char)second[index]);
//}
//
//int parseNextToken(const char* line, int offset, char delimiter, char* tokenBuffer) {
//    int tokenIndex = 0;
//    while (line[offset] && line[offset] != delimiter
//        && line[offset] != '\n' && line[offset] != '\r') {
//        tokenBuffer[tokenIndex++] = line[offset++];
//    }
//    tokenBuffer[tokenIndex] = '\0';
//    if (line[offset] == delimiter) offset++;
//    return offset;
//}
//
//int convertStringToInt(const char* str) {
//    int value = 0, sign = 1, index = 0;
//    while (str[index] == ' ') index++;
//    if (str[index] == '-') { sign = -1; index++; }
//    else if (str[index] == '+') { index++; }
//    while (str[index] >= '0' && str[index] <= '9') {
//        value = value * 10 + (str[index] - '0');
//        index++;
//    }
//    return value * sign;
//}
//
//double convertStringToDouble(const char* str) {
//    double value = 0.0;
//    int index = 0;
//    double sign = 1.0;
//    while (str[index] == ' ') index++;
//    if (str[index] == '-') { sign = -1.0; index++; }
//    else if (str[index] == '+') { index++; }
//    while (str[index] >= '0' && str[index] <= '9') {
//        value = value * 10 + (str[index] - '0');
//        index++;
//    }
//    if (str[index] == '.') {
//        index++;
//        double fractionalMultiplier = 0.1;
//        while (str[index] >= '0' && str[index] <= '9') {
//            value += (str[index] - '0') * fractionalMultiplier;
//            fractionalMultiplier *= 0.1;
//            index++;
//        }
//    }
//    return value * sign;
//}
//
//void convertIntToString(int number, char* buffer) {
//    if (number == 0) { buffer[0] = '0'; buffer[1] = '\0'; return; }
//    char reversed[32];
//    int reversedIndex = 0;
//    bool isNegative = false;
//    if (number < 0) { isNegative = true; number = -number; }
//    while (number > 0) { reversed[reversedIndex++] = '0' + number % 10; number /= 10; }
//    if (isNegative) reversed[reversedIndex++] = '-';
//    int outputIndex = 0;
//    while (reversedIndex > 0) buffer[outputIndex++] = reversed[--reversedIndex];
//    buffer[outputIndex] = '\0';
//}
//
//void convertDoubleToString(double value, char* buffer, int decimalPlaces = 2) {
//    if (value < 0) { buffer[0] = '-'; convertDoubleToString(-value, buffer + 1, decimalPlaces); return; }
//    int integerPart = (int)value;
//    double fractionalPart = value - integerPart;
//    char integerBuffer[32];
//    convertIntToString(integerPart, integerBuffer);
//    copyString(buffer, integerBuffer);
//    appendString(buffer, ".");
//    for (int digit = 0; digit < decimalPlaces; digit++) {
//        fractionalPart *= 10;
//        int digitValue = (int)fractionalPart;
//        char digitChar[2]; digitChar[0] = '0' + digitValue; digitChar[1] = '\0';
//        appendString(buffer, digitChar);
//        fractionalPart -= digitValue;
//    }
//}
//
//bool readLineFromFile(ifstream& fileStream, char* buffer, int maxLength) {
//    if (fileStream.eof() || !fileStream.good()) return false;
//    fileStream.getline(buffer, maxLength);
//    if (fileStream.fail() && !fileStream.eof()) { fileStream.clear(); return false; }
//    int length = calculateStringLength(buffer);
//    if (length > 0 && buffer[length - 1] == '\r') buffer[length - 1] = '\0';
//    return true;
//}
//
//void readStringFromConsole(char* buffer, int maxLength) {
//    cin.getline(buffer, maxLength);
//    if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); }
//    int length = calculateStringLength(buffer);
//    if (length > 0 && buffer[length - 1] == '\r') buffer[length - 1] = '\0';
//}
//
//// ============================================================
//// FORWARD DECLARATION
//// ============================================================
//class Hospital;
//
//void getTodayDateString(char* buffer, const char* systemDate) {
//    copyString(buffer, systemDate);
//}
//
//void getCurrentTimestampString(char* buffer, const char* systemDate, const char* systemTime) {
//    copyString(buffer, systemDate);
//    appendString(buffer, " ");
//    appendString(buffer, systemTime);
//}
//
//int getCurrentYear(const char* systemDate) {
//    char copy[16];
//    copyString(copy, systemDate);
//    char day[5], month[5], year[5];
//    int offset = 0;
//    offset = parseNextToken(copy, offset, '-', day);
//    offset = parseNextToken(copy, offset, '-', month);
//    parseNextToken(copy, offset, '-', year);
//    return convertStringToInt(year);
//}
//
//int convertDateToSortableInt(const char* dateString) {
//    char copy[64];
//    copyString(copy, dateString);
//    char dayPart[5], monthPart[5], yearPart[5];
//    int offset = 0;
//    offset = parseNextToken(copy, offset, '-', dayPart);
//    offset = parseNextToken(copy, offset, '-', monthPart);
//    parseNextToken(copy, offset, '-', yearPart);
//    return convertStringToInt(yearPart) * 10000
//        + convertStringToInt(monthPart) * 100
//        + convertStringToInt(dayPart);
//}
//
//time_t convertDateToTimeT(const char* dateString) {
//    char copy[64];
//    copyString(copy, dateString);
//    char day[5], month[5], year[5];
//    int offset = 0;
//    offset = parseNextToken(copy, offset, '-', day);
//    offset = parseNextToken(copy, offset, '-', month);
//    parseNextToken(copy, offset, '-', year);
//    tm t = {};
//    t.tm_mday = convertStringToInt(day);
//    t.tm_mon = convertStringToInt(month) - 1;
//    t.tm_year = convertStringToInt(year) - 1900;
//    t.tm_hour = 0; t.tm_min = 0; t.tm_sec = 0;
//    return mktime(&t);
//}
//
//// ============================================================
//// EXCEPTION CLASSES
//// ============================================================
//
//class HospitalException {
//protected:
//    char errorMessage[200];
//public:
//    HospitalException() { errorMessage[0] = '\0'; }
//    HospitalException(const char* msg) { copyString(errorMessage, msg); }
//    virtual const char* what() const { return errorMessage; }
//    virtual ~HospitalException() {}
//};
//
//class FileNotFoundException : public HospitalException {
//public:
//    FileNotFoundException(const char* fileName) {
//        copyString(errorMessage, "File not found: ");
//        appendString(errorMessage, fileName);
//    }
//};
//
//class InsufficientFundsException : public HospitalException {
//public:
//    InsufficientFundsException() {
//        copyString(errorMessage, "Insufficient funds. Please top up your balance.");
//    }
//};
//
//class InvalidInputException : public HospitalException {
//public:
//    InvalidInputException(const char* msg) { copyString(errorMessage, msg); }
//};
//
//class SlotUnavailableException : public HospitalException {
//public:
//    SlotUnavailableException() {
//        copyString(errorMessage, "Slot unavailable. Please choose another slot.");
//    }
//};
//
//// ============================================================
//// VALIDATOR CLASS
//// ============================================================
//
//class Validator {
//public:
//    static bool isValidDate(const char* dateString, const char* systemDate) {
//        int length = calculateStringLength(dateString);
//        if (length != 10) return false;
//        if (dateString[2] != '-' || dateString[5] != '-') return false;
//        for (int i = 0; i < 10; i++) {
//            if (i == 2 || i == 5) continue;
//            if (dateString[i] < '0' || dateString[i] > '9') return false;
//        }
//        int day = (dateString[0] - '0') * 10 + (dateString[1] - '0');
//        int month = (dateString[3] - '0') * 10 + (dateString[4] - '0');
//        int year = (dateString[6] - '0') * 1000 + (dateString[7] - '0') * 100
//            + (dateString[8] - '0') * 10 + (dateString[9] - '0');
//        if (day < 1 || day > 31)                    return false;
//        if (month < 1 || month > 12)                return false;
//        if (year < getCurrentYear(systemDate))      return false;
//        return true;
//    }
//
//    static bool isValidTimeSlot(const char* slot) {
//        const char* validSlots[8] = {
//            "09:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00"
//        };
//        for (int i = 0; i < 8; i++)
//            if (compareStrings(slot, validSlots[i]) == 0) return true;
//        return false;
//    }
//
//    static bool isValidContactNumber(const char* contactNumber) {
//        if (calculateStringLength(contactNumber) != 11) return false;
//        for (int i = 0; i < 11; i++)
//            if (contactNumber[i] < '0' || contactNumber[i] > '9') return false;
//        return true;
//    }
//
//    static bool isValidPassword(const char* password) {
//        return calculateStringLength(password) >= 6;
//    }
//
//    static bool isValidPositiveAmount(const char* amountString) {
//        return convertStringToDouble(amountString) > 0.0;
//    }
//
//    static bool isValidMenuChoice(int choice, int maxChoice) {
//        return choice >= 1 && choice <= maxChoice;
//    }
//
//    static bool isValidID(int id) { return id >= 1; }
//};
//
//// ============================================================
//// ENTITY CLASSES
//// ============================================================
//
//class Person {
//protected:
//    int  personID;
//    char personName[256];
//    char loginPassword[256];
//public:
//    Person() : personID(0) { personName[0] = '\0'; loginPassword[0] = '\0'; }
//    virtual ~Person() {}
//
//    int         getID()       const { return personID; }
//    const char* getName()     const { return personName; }
//    const char* getPassword() const { return loginPassword; }
//
//    void setID(int id) { personID = id; }
//    void setName(const char* name) { copyString(personName, name); }
//    void setPassword(const char* pass) { copyString(loginPassword, pass); }
//
//    virtual void display()          const = 0;
//    virtual void toFileString(char* buffer) const = 0;
//};
//
//class Patient : public Person {
//    int    ageYears;
//    char   genderChar[4];
//    char   phoneNumber[16];
//    double accountBalance;
//public:
//    Patient() : ageYears(0), accountBalance(0.0) {
//        genderChar[0] = '\0'; phoneNumber[0] = '\0';
//    }
//
//    int         getAge()     const { return ageYears; }
//    const char* getGender()  const { return genderChar; }
//    const char* getContact() const { return phoneNumber; }
//    double      getBalance() const { return accountBalance; }
//
//    void setAge(int age) { ageYears = age; }
//    void setGender(const char* gender) { copyString(genderChar, gender); }
//    void setContact(const char* contact) { copyString(phoneNumber, contact); }
//    void setBalance(double balance) { accountBalance = balance; }
//
//    Patient& operator+=(double amount) { accountBalance += amount; return *this; }
//    Patient& operator-=(double amount) { accountBalance -= amount; return *this; }
//    bool     operator==(const Patient& other) const { return personID == other.personID; }
//
//    friend ostream& operator<<(ostream& os, const Patient& patient) {
//        char balanceStr[32];
//        convertDoubleToString(patient.accountBalance, balanceStr);
//        os << "ID: " << patient.personID
//            << " | Name: " << patient.personName
//            << " | Age: " << patient.ageYears
//            << " | Gender: " << patient.genderChar
//            << " | Contact: " << patient.phoneNumber
//            << " | Balance: PKR " << balanceStr;
//        return os;
//    }
//
//    void display() const override {
//        char balanceStr[32];
//        convertDoubleToString(accountBalance, balanceStr);
//        cout << "ID: " << personID
//            << " | Name: " << personName
//            << " | Age: " << ageYears
//            << " | Gender: " << genderChar
//            << " | Contact: " << phoneNumber
//            << " | Balance: PKR " << balanceStr << "\n";
//    }
//
//    void toFileString(char* buffer) const override {
//        char numberBuffer[32];
//        convertIntToString(personID, numberBuffer);
//        copyString(buffer, numberBuffer);     appendString(buffer, ",");
//        appendString(buffer, personName);     appendString(buffer, ",");
//        convertIntToString(ageYears, numberBuffer);
//        appendString(buffer, numberBuffer);   appendString(buffer, ",");
//        appendString(buffer, genderChar);     appendString(buffer, ",");
//        appendString(buffer, phoneNumber);    appendString(buffer, ",");
//        appendString(buffer, loginPassword);  appendString(buffer, ",");
//        convertDoubleToString(accountBalance, numberBuffer);
//        appendString(buffer, numberBuffer);
//    }
//
//    void loadFromCSVLine(const char* line) {
//        int offset = 0;
//        char idStr[16], ageStr[8], balanceStr[32];
//        offset = parseNextToken(line, offset, ',', idStr);
//        personID = convertStringToInt(idStr);
//        offset = parseNextToken(line, offset, ',', personName);
//        offset = parseNextToken(line, offset, ',', ageStr);
//        ageYears = convertStringToInt(ageStr);
//        offset = parseNextToken(line, offset, ',', genderChar);
//        offset = parseNextToken(line, offset, ',', phoneNumber);
//        offset = parseNextToken(line, offset, ',', loginPassword);
//        parseNextToken(line, offset, ',', balanceStr);
//        accountBalance = convertStringToDouble(balanceStr);
//    }
//};
//
//class Doctor : public Person {
//    char   medicalSpecialization[256];
//    char   phoneNumber[16];
//    double consultationFee;
//public:
//    Doctor() : consultationFee(0.0) {
//        medicalSpecialization[0] = '\0'; phoneNumber[0] = '\0';
//    }
//
//    const char* getSpecialization() const { return medicalSpecialization; }
//    const char* getContact()        const { return phoneNumber; }
//    double      getFee()            const { return consultationFee; }
//
//    void setSpecialization(const char* spec) { copyString(medicalSpecialization, spec); }
//    void setContact(const char* contact) { copyString(phoneNumber, contact); }
//    void setFee(double fee) { consultationFee = fee; }
//
//    bool operator==(const Doctor& other) const { return personID == other.personID; }
//
//    friend ostream& operator<<(ostream& os, const Doctor& doctor) {
//        char feeStr[32];
//        convertDoubleToString(doctor.consultationFee, feeStr);
//        os << "ID: " << doctor.personID
//            << " | Name: " << doctor.personName
//            << " | Specialization: " << doctor.medicalSpecialization
//            << " | Contact: " << doctor.phoneNumber
//            << " | Fee: PKR " << feeStr;
//        return os;
//    }
//
//    void display() const override {
//        char feeStr[32];
//        convertDoubleToString(consultationFee, feeStr);
//        cout << "ID: " << personID
//            << " | Name: " << personName
//            << " | Spec: " << medicalSpecialization
//            << " | Contact: " << phoneNumber
//            << " | Fee: PKR " << feeStr << "\n";
//    }
//
//    void toFileString(char* buffer) const override {
//        char numberBuffer[32];
//        convertIntToString(personID, numberBuffer);
//        copyString(buffer, numberBuffer);               appendString(buffer, ",");
//        appendString(buffer, personName);               appendString(buffer, ",");
//        appendString(buffer, medicalSpecialization);    appendString(buffer, ",");
//        appendString(buffer, phoneNumber);              appendString(buffer, ",");
//        appendString(buffer, loginPassword);            appendString(buffer, ",");
//        convertDoubleToString(consultationFee, numberBuffer);
//        appendString(buffer, numberBuffer);
//    }
//
//    void loadFromCSVLine(const char* line) {
//        int offset = 0;
//        char idStr[16], feeStr[32];
//        offset = parseNextToken(line, offset, ',', idStr);
//        personID = convertStringToInt(idStr);
//        offset = parseNextToken(line, offset, ',', personName);
//        offset = parseNextToken(line, offset, ',', medicalSpecialization);
//        offset = parseNextToken(line, offset, ',', phoneNumber);
//        offset = parseNextToken(line, offset, ',', loginPassword);
//        parseNextToken(line, offset, ',', feeStr);
//        consultationFee = convertStringToDouble(feeStr);
//    }
//};
//
//class Admin : public Person {
//public:
//    Admin() {}
//
//    void display() const override {
//        cout << "Admin ID: " << personID << " | Name: " << personName << "\n";
//    }
//
//    void toFileString(char* buffer) const override {
//        char idStr[16];
//        convertIntToString(personID, idStr);
//        copyString(buffer, idStr);          appendString(buffer, ",");
//        appendString(buffer, personName);   appendString(buffer, ",");
//        appendString(buffer, loginPassword);
//    }
//
//    void loadFromCSVLine(const char* line) {
//        int offset = 0;
//        char idStr[16];
//        offset = parseNextToken(line, offset, ',', idStr);
//        personID = convertStringToInt(idStr);
//        offset = parseNextToken(line, offset, ',', personName);
//        parseNextToken(line, offset, ',', loginPassword);
//    }
//};
//
//class Appointment {
//    int  appointmentID;
//    int  patientID;
//    int  doctorID;
//    char appointmentDate[16];
//    char timeSlot[8];
//    char appointmentStatus[16];
//public:
//    Appointment() : appointmentID(0), patientID(0), doctorID(0) {
//        appointmentDate[0] = '\0';
//        timeSlot[0] = '\0';
//        copyString(appointmentStatus, "pending");
//    }
//
//    int         getID()        const { return appointmentID; }
//    int         getPatientID() const { return patientID; }
//    int         getDoctorID()  const { return doctorID; }
//    const char* getDate()      const { return appointmentDate; }
//    const char* getTimeSlot()  const { return timeSlot; }
//    const char* getStatus()    const { return appointmentStatus; }
//
//    void setID(int id) { appointmentID = id; }
//    void setPatientID(int id) { patientID = id; }
//    void setDoctorID(int id) { doctorID = id; }
//    void setDate(const char* date) { copyString(appointmentDate, date); }
//    void setTimeSlot(const char* slot) { copyString(timeSlot, slot); }
//    void setStatus(const char* status) { copyString(appointmentStatus, status); }
//
//    bool operator==(const Appointment& other) const {
//        if (doctorID != other.doctorID)                                     return false;
//        if (compareStrings(appointmentDate, other.appointmentDate) != 0)    return false;
//        if (compareStrings(timeSlot, other.timeSlot) != 0)                  return false;
//        if (compareStrings(appointmentStatus, "cancelled") == 0)            return false;
//        if (compareStrings(other.appointmentStatus, "cancelled") == 0)      return false;
//        return true;
//    }
//
//    friend ostream& operator<<(ostream& os, const Appointment& apt) {
//        os << "AptID: " << apt.appointmentID
//            << " | PatID: " << apt.patientID
//            << " | DocID: " << apt.doctorID
//            << " | Date: " << apt.appointmentDate
//            << " | Slot: " << apt.timeSlot
//            << " | Status: " << apt.appointmentStatus;
//        return os;
//    }
//
//    void toFileString(char* buffer) const {
//        char numberBuffer[16];
//        convertIntToString(appointmentID, numberBuffer);
//        copyString(buffer, numberBuffer);   appendString(buffer, ",");
//        convertIntToString(patientID, numberBuffer);
//        appendString(buffer, numberBuffer); appendString(buffer, ",");
//        convertIntToString(doctorID, numberBuffer);
//        appendString(buffer, numberBuffer); appendString(buffer, ",");
//        appendString(buffer, appointmentDate);   appendString(buffer, ",");
//        appendString(buffer, timeSlot);          appendString(buffer, ",");
//        appendString(buffer, appointmentStatus);
//    }
//
//    void loadFromCSVLine(const char* line) {
//        int offset = 0;
//        char idStr[16], patStr[16], docStr[16];
//        offset = parseNextToken(line, offset, ',', idStr);  appointmentID = convertStringToInt(idStr);
//        offset = parseNextToken(line, offset, ',', patStr); patientID = convertStringToInt(patStr);
//        offset = parseNextToken(line, offset, ',', docStr); doctorID = convertStringToInt(docStr);
//        offset = parseNextToken(line, offset, ',', appointmentDate);
//        offset = parseNextToken(line, offset, ',', timeSlot);
//        parseNextToken(line, offset, ',', appointmentStatus);
//    }
//};
//
//class Bill {
//    int    billID;
//    int    ownerPatientID;
//    int    linkedAppointmentID;
//    double billedAmount;
//    char   paymentStatus[16];
//    char   billDate[16];
//public:
//    Bill() : billID(0), ownerPatientID(0), linkedAppointmentID(0), billedAmount(0.0) {
//        copyString(paymentStatus, "unpaid"); billDate[0] = '\0';
//    }
//
//    int         getID()            const { return billID; }
//    int         getPatientID()     const { return ownerPatientID; }
//    int         getAppointmentID() const { return linkedAppointmentID; }
//    double      getAmount()        const { return billedAmount; }
//    const char* getStatus()        const { return paymentStatus; }
//    const char* getDate()          const { return billDate; }
//
//    void setID(int id) { billID = id; }
//    void setPatientID(int id) { ownerPatientID = id; }
//    void setAppointmentID(int id) { linkedAppointmentID = id; }
//    void setAmount(double amount) { billedAmount = amount; }
//    void setStatus(const char* status) { copyString(paymentStatus, status); }
//    void setDate(const char* date) { copyString(billDate, date); }
//
//    void toFileString(char* buffer) const {
//        char numberBuffer[32];
//        convertIntToString(billID, numberBuffer);
//        copyString(buffer, numberBuffer);   appendString(buffer, ",");
//        convertIntToString(ownerPatientID, numberBuffer);
//        appendString(buffer, numberBuffer); appendString(buffer, ",");
//        convertIntToString(linkedAppointmentID, numberBuffer);
//        appendString(buffer, numberBuffer); appendString(buffer, ",");
//        convertDoubleToString(billedAmount, numberBuffer);
//        appendString(buffer, numberBuffer); appendString(buffer, ",");
//        appendString(buffer, paymentStatus); appendString(buffer, ",");
//        appendString(buffer, billDate);
//    }
//
//    void loadFromCSVLine(const char* line) {
//        int offset = 0;
//        char idStr[16], patStr[16], aptStr[16], amtStr[32];
//        offset = parseNextToken(line, offset, ',', idStr);  billID = convertStringToInt(idStr);
//        offset = parseNextToken(line, offset, ',', patStr); ownerPatientID = convertStringToInt(patStr);
//        offset = parseNextToken(line, offset, ',', aptStr); linkedAppointmentID = convertStringToInt(aptStr);
//        offset = parseNextToken(line, offset, ',', amtStr); billedAmount = convertStringToDouble(amtStr);
//        offset = parseNextToken(line, offset, ',', paymentStatus);
//        parseNextToken(line, offset, ',', billDate);
//    }
//};
//
//class Prescription {
//    int  prescriptionID;
//    int  linkedAppointmentID;
//    int  ownerPatientID;
//    int  authorDoctorID;
//    char prescriptionDate[16];
//    char prescribedMedicines[500];
//    char doctorNotes[300];
//public:
//    Prescription() : prescriptionID(0), linkedAppointmentID(0),
//        ownerPatientID(0), authorDoctorID(0) {
//        prescriptionDate[0] = '\0';
//        prescribedMedicines[0] = '\0';
//        doctorNotes[0] = '\0';
//    }
//
//    int         getID()            const { return prescriptionID; }
//    int         getAppointmentID() const { return linkedAppointmentID; }
//    int         getPatientID()     const { return ownerPatientID; }
//    int         getDoctorID()      const { return authorDoctorID; }
//    const char* getDate()          const { return prescriptionDate; }
//    const char* getMedicines()     const { return prescribedMedicines; }
//    const char* getNotes()         const { return doctorNotes; }
//
//    void setID(int id) { prescriptionID = id; }
//    void setAppointmentID(int id) { linkedAppointmentID = id; }
//    void setPatientID(int id) { ownerPatientID = id; }
//    void setDoctorID(int id) { authorDoctorID = id; }
//    void setDate(const char* date) { copyString(prescriptionDate, date); }
//    void setMedicines(const char* meds) { copyString(prescribedMedicines, meds); }
//    void setNotes(const char* notes) { copyString(doctorNotes, notes); }
//
//    void toFileString(char* buffer) const {
//        char numberBuffer[16];
//        auto appendQuoted = [](char* buf, const char* field) {
//            appendString(buf, "\"");
//            for (int i = 0; field[i]; i++) {
//                if (field[i] == '"') appendString(buf, "\"\"");
//                else {
//                    char ch[2]; ch[0] = field[i]; ch[1] = '\0';
//                    appendString(buf, ch);
//                }
//            }
//            appendString(buf, "\"");
//            };
//        convertIntToString(prescriptionID, numberBuffer);
//        copyString(buffer, numberBuffer);           appendString(buffer, ",");
//        convertIntToString(linkedAppointmentID, numberBuffer);
//        appendString(buffer, numberBuffer);         appendString(buffer, ",");
//        convertIntToString(ownerPatientID, numberBuffer);
//        appendString(buffer, numberBuffer);         appendString(buffer, ",");
//        convertIntToString(authorDoctorID, numberBuffer);
//        appendString(buffer, numberBuffer);         appendString(buffer, ",");
//        appendString(buffer, prescriptionDate);     appendString(buffer, ",");
//        appendQuoted(buffer, prescribedMedicines);  appendString(buffer, ",");
//        appendQuoted(buffer, doctorNotes);
//    }
//
//    static int parseQuotedField(const char* line, int offset, char* outBuffer) {
//        int outIdx = 0;
//        while (line[offset]) {
//            if (line[offset] == '"') {
//                if (line[offset + 1] == '"') {
//                    outBuffer[outIdx++] = '"';
//                    offset += 2;
//                }
//                else { offset++; break; }
//            }
//            else { outBuffer[outIdx++] = line[offset++]; }
//        }
//        outBuffer[outIdx] = '\0';
//        if (line[offset] == ',') offset++;
//        return offset;
//    }
//
//    void loadFromCSVLine(const char* line) {
//        int offset = 0;
//        char idStr[16], aptStr[16], patStr[16], docStr[16];
//        offset = parseNextToken(line, offset, ',', idStr);  prescriptionID = convertStringToInt(idStr);
//        offset = parseNextToken(line, offset, ',', aptStr); linkedAppointmentID = convertStringToInt(aptStr);
//        offset = parseNextToken(line, offset, ',', patStr); ownerPatientID = convertStringToInt(patStr);
//        offset = parseNextToken(line, offset, ',', docStr); authorDoctorID = convertStringToInt(docStr);
//        offset = parseNextToken(line, offset, ',', prescriptionDate);
//        if (line[offset] == '"') { offset++; offset = parseQuotedField(line, offset, prescribedMedicines); }
//        else { offset = parseNextToken(line, offset, ',', prescribedMedicines); }
//        if (line[offset] == '"') { offset++; parseQuotedField(line, offset, doctorNotes); }
//        else { parseNextToken(line, offset, ',', doctorNotes); }
//    }
//};
//
//// ============================================================
//// STORAGE<T>
//// ============================================================
//
//template<typename T>
//class Storage {
//    T   recordArray[100];
//    int recordCount;
//public:
//    Storage() : recordCount(0) {}
//
//    bool addRecord(const T& item) {
//        if (recordCount >= 100) return false;
//        recordArray[recordCount++] = item;
//        return true;
//    }
//
//    int size() const { return recordCount; }
//    T* getAll() { return recordArray; }
//    const T* getAll() const { return recordArray; }
//
//    T* findByID(int id) {
//        for (int i = 0; i < recordCount; i++)
//            if (recordArray[i].getID() == id) return &recordArray[i];
//        return nullptr;
//    }
//
//    bool removeByID(int id) {
//        for (int i = 0; i < recordCount; i++) {
//            if (recordArray[i].getID() == id) {
//                for (int j = i; j < recordCount - 1; j++)
//                    recordArray[j] = recordArray[j + 1];
//                recordCount--;
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void clearAll() { recordCount = 0; }
//};
//
//// ============================================================
//// FILE HANDLER
//// ============================================================
//
//class FileHandler {
//public:
//    static void loadPatientsFromFile(Storage<Patient>& store, const char* fileName) {
//        ifstream fileStream(fileName);
//        if (!fileStream.is_open()) throw FileNotFoundException(fileName);
//        char line[1024];
//        while (readLineFromFile(fileStream, line, 1024)) {
//            if (line[0] == '\0') continue;
//            Patient patient;
//            patient.loadFromCSVLine(line);
//            store.addRecord(patient);
//        }
//        fileStream.close();
//    }
//
//    static void loadDoctorsFromFile(Storage<Doctor>& store, const char* fileName) {
//        ifstream fileStream(fileName);
//        if (!fileStream.is_open()) throw FileNotFoundException(fileName);
//        char line[1024];
//        while (readLineFromFile(fileStream, line, 1024)) {
//            if (line[0] == '\0') continue;
//            Doctor doctor;
//            doctor.loadFromCSVLine(line);
//            store.addRecord(doctor);
//        }
//        fileStream.close();
//    }
//
//    static void loadAppointmentsFromFile(Storage<Appointment>& store, const char* fileName) {
//        ifstream fileStream(fileName);
//        if (!fileStream.is_open()) throw FileNotFoundException(fileName);
//        char line[512];
//        while (readLineFromFile(fileStream, line, 512)) {
//            if (line[0] == '\0') continue;
//            Appointment apt;
//            apt.loadFromCSVLine(line);
//            store.addRecord(apt);
//        }
//        fileStream.close();
//    }
//
//    static void loadBillsFromFile(Storage<Bill>& store, const char* fileName) {
//        ifstream fileStream(fileName);
//        if (!fileStream.is_open()) throw FileNotFoundException(fileName);
//        char line[512];
//        while (readLineFromFile(fileStream, line, 512)) {
//            if (line[0] == '\0') continue;
//            Bill bill;
//            bill.loadFromCSVLine(line);
//            store.addRecord(bill);
//        }
//        fileStream.close();
//    }
//
//    static void loadPrescriptionsFromFile(Storage<Prescription>& store, const char* fileName) {
//        ifstream fileStream(fileName);
//        if (!fileStream.is_open()) throw FileNotFoundException(fileName);
//        char line[1024];
//        while (readLineFromFile(fileStream, line, 1024)) {
//            if (line[0] == '\0') continue;
//            Prescription prescription;
//            prescription.loadFromCSVLine(line);
//            store.addRecord(prescription);
//        }
//        fileStream.close();
//    }
//
//    static bool loadAdminFromFile(Admin& adminUser, const char* fileName) {
//        ifstream fileStream(fileName);
//        if (!fileStream.is_open()) return false;
//        char line[256];
//        if (readLineFromFile(fileStream, line, 256) && line[0] != '\0') {
//            adminUser.loadFromCSVLine(line);
//            fileStream.close();
//            return true;
//        }
//        fileStream.close();
//        return false;
//    }
//
//    static void writeAllPatientsToFile(Storage<Patient>& store, const char* fileName) {
//        ofstream fileStream(fileName, ios::trunc);
//        char buffer[1024];
//        for (int i = 0; i < store.size(); i++) {
//            store.getAll()[i].toFileString(buffer);
//            fileStream << buffer << "\n";
//        }
//        fileStream.close();
//    }
//
//    static void writeAllDoctorsToFile(Storage<Doctor>& store, const char* fileName) {
//        ofstream fileStream(fileName, ios::trunc);
//        char buffer[1024];
//        for (int i = 0; i < store.size(); i++) {
//            store.getAll()[i].toFileString(buffer);
//            fileStream << buffer << "\n";
//        }
//        fileStream.close();
//    }
//
//    static void writeAllAppointmentsToFile(Storage<Appointment>& store, const char* fileName) {
//        ofstream fileStream(fileName, ios::trunc);
//        char buffer[512];
//        for (int i = 0; i < store.size(); i++) {
//            store.getAll()[i].toFileString(buffer);
//            fileStream << buffer << "\n";
//        }
//        fileStream.close();
//    }
//
//    static void writeAllBillsToFile(Storage<Bill>& store, const char* fileName) {
//        ofstream fileStream(fileName, ios::trunc);
//        char buffer[512];
//        for (int i = 0; i < store.size(); i++) {
//            store.getAll()[i].toFileString(buffer);
//            fileStream << buffer << "\n";
//        }
//        fileStream.close();
//    }
//
//    static void writeAllPrescriptionsToFile(Storage<Prescription>& store, const char* fileName) {
//        ofstream fileStream(fileName, ios::trunc);
//        char buffer[2048];
//        for (int i = 0; i < store.size(); i++) {
//            store.getAll()[i].toFileString(buffer);
//            fileStream << buffer << "\n";
//        }
//        fileStream.close();
//    }
//
//    static void appendPatientRecord(const Patient& patient, const char* fileName) {
//        ofstream fileStream(fileName, ios::app);
//        char buffer[1024];
//        patient.toFileString(buffer);
//        fileStream << buffer << "\n";
//        fileStream.close();
//    }
//
//    static void appendDoctorRecord(const Doctor& doctor, const char* fileName) {
//        ofstream fileStream(fileName, ios::app);
//        char buffer[1024];
//        doctor.toFileString(buffer);
//        fileStream << buffer << "\n";
//        fileStream.close();
//    }
//
//    static void appendAppointmentRecord(const Appointment& appointment, const char* fileName) {
//        ofstream fileStream(fileName, ios::app);
//        char buffer[512];
//        appointment.toFileString(buffer);
//        fileStream << buffer << "\n";
//        fileStream.close();
//    }
//
//    static void appendBillRecord(const Bill& bill, const char* fileName) {
//        ofstream fileStream(fileName, ios::app);
//        char buffer[512];
//        bill.toFileString(buffer);
//        fileStream << buffer << "\n";
//        fileStream.close();
//    }
//
//    static void appendPrescriptionRecord(const Prescription& prescription, const char* fileName) {
//        ofstream fileStream(fileName, ios::app);
//        char buffer[2048];
//        prescription.toFileString(buffer);
//        fileStream << buffer << "\n";
//        fileStream.close();
//    }
//
//    static void appendSecurityLogEntry(const char* logEntry) {
//        ofstream fileStream("security_log.txt", ios::app);
//        fileStream << logEntry << "\n";
//        fileStream.close();
//    }
//
//    static void displaySecurityLog() {
//        ifstream fileStream("security_log.txt");
//        if (!fileStream.is_open()) { cout << "No security events logged.\n"; return; }
//        char line[512];
//        bool hasEntries = false;
//        while (readLineFromFile(fileStream, line, 512)) {
//            if (line[0] == '\0') continue;
//            cout << line << "\n";
//            hasEntries = true;
//        }
//        if (!hasEntries) cout << "No security events logged.\n";
//        fileStream.close();
//    }
//
//    static void archiveDischargedPatient(const Patient& patient,
//        Storage<Appointment>& appointments,
//        Storage<Bill>& bills,
//        Storage<Prescription>& prescriptions) {
//        ofstream fileStream("discharged.txt", ios::app);
//        char buffer[2048];
//        fileStream << "PATIENT,";
//        patient.toFileString(buffer);
//        fileStream << buffer << "\n";
//        for (int i = 0; i < appointments.size(); i++) {
//            if (appointments.getAll()[i].getPatientID() == patient.getID()) {
//                fileStream << "APPOINTMENT,";
//                appointments.getAll()[i].toFileString(buffer);
//                fileStream << buffer << "\n";
//            }
//        }
//        for (int i = 0; i < bills.size(); i++) {
//            if (bills.getAll()[i].getPatientID() == patient.getID()) {
//                fileStream << "BILL,";
//                bills.getAll()[i].toFileString(buffer);
//                fileStream << buffer << "\n";
//            }
//        }
//        for (int i = 0; i < prescriptions.size(); i++) {
//            if (prescriptions.getAll()[i].getPatientID() == patient.getID()) {
//                fileStream << "PRESCRIPTION,";
//                prescriptions.getAll()[i].toFileString(buffer);
//                fileStream << buffer << "\n";
//            }
//        }
//        fileStream.close();
//    }
//};
//
//// ============================================================
//// HOSPITAL CLASS
//// ============================================================
//
//class Hospital {
//public:
//    Storage<Patient>      patients;
//    Storage<Doctor>       doctors;
//    Storage<Appointment>  appointments;
//    Storage<Bill>         bills;
//    Storage<Prescription> prescriptions;
//    Admin                 systemAdmin;
//    char                  systemDate[16];
//    char                  systemTime[12];
//
//    Hospital() { systemDate[0] = '\0'; systemTime[0] = '\0'; }
//
//    int generateNextPatientID() {
//        int maxID = 0;
//        for (int i = 0; i < patients.size(); i++)
//            if (patients.getAll()[i].getID() > maxID) maxID = patients.getAll()[i].getID();
//        return maxID + 1;
//    }
//
//    int generateNextDoctorID() {
//        int maxID = 0;
//        for (int i = 0; i < doctors.size(); i++)
//            if (doctors.getAll()[i].getID() > maxID) maxID = doctors.getAll()[i].getID();
//        return maxID + 1;
//    }
//
//    int generateNextAppointmentID() {
//        int maxID = 0;
//        for (int i = 0; i < appointments.size(); i++)
//            if (appointments.getAll()[i].getID() > maxID) maxID = appointments.getAll()[i].getID();
//        return maxID + 1;
//    }
//
//    int generateNextBillID() {
//        int maxID = 0;
//        for (int i = 0; i < bills.size(); i++)
//            if (bills.getAll()[i].getID() > maxID) maxID = bills.getAll()[i].getID();
//        return maxID + 1;
//    }
//
//    int generateNextPrescriptionID() {
//        int maxID = 0;
//        for (int i = 0; i < prescriptions.size(); i++)
//            if (prescriptions.getAll()[i].getID() > maxID) maxID = prescriptions.getAll()[i].getID();
//        return maxID + 1;
//    }
//
//    Doctor* findDoctorByID(int id) { return doctors.findByID(id); }
//    Patient* findPatientByID(int id) { return patients.findByID(id); }
//
//    bool isTimeSlotAvailable(int doctorID, const char* date, const char* slot) {
//        for (int i = 0; i < appointments.size(); i++) {
//            Appointment& apt = appointments.getAll()[i];
//            if (apt.getDoctorID() == doctorID
//                && compareStrings(apt.getDate(), date) == 0
//                && compareStrings(apt.getTimeSlot(), slot) == 0
//                && compareStrings(apt.getStatus(), "cancelled") != 0)
//                return false;
//        }
//        return true;
//    }
//
//    void printAvailableTimeSlots(int doctorID, const char* date) {
//        const char* allSlots[8] = {
//            "09:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00"
//        };
//        cout << "Available slots for " << date << ":\n";
//        bool anyAvailable = false;
//        for (int i = 0; i < 8; i++) {
//            if (isTimeSlotAvailable(doctorID, date, allSlots[i])) {
//                cout << "  " << allSlots[i] << "\n";
//                anyAvailable = true;
//            }
//        }
//        if (!anyAvailable) cout << "  No slots available.\n";
//    }
//
//    int countUnpaidBillsForPatient(int patientID) {
//        int count = 0;
//        for (int i = 0; i < bills.size(); i++)
//            if (bills.getAll()[i].getPatientID() == patientID
//                && compareStrings(bills.getAll()[i].getStatus(), "unpaid") == 0)
//                count++;
//        return count;
//    }
//
//    int countPendingAppointmentsForPatient(int patientID) {
//        int count = 0;
//        for (int i = 0; i < appointments.size(); i++)
//            if (appointments.getAll()[i].getPatientID() == patientID
//                && compareStrings(appointments.getAll()[i].getStatus(), "pending") == 0)
//                count++;
//        return count;
//    }
//
//    void sortAppointmentsByDateAscending(Appointment* arr, int count) {
//        for (int pass = 0; pass < count - 1; pass++)
//            for (int i = 0; i < count - pass - 1; i++)
//                if (convertDateToSortableInt(arr[i].getDate())
//            > convertDateToSortableInt(arr[i + 1].getDate())) {
//                    Appointment temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
//                }
//    }
//
//    void sortAppointmentsByDateDescending(Appointment* arr, int count) {
//        for (int pass = 0; pass < count - 1; pass++)
//            for (int i = 0; i < count - pass - 1; i++)
//                if (convertDateToSortableInt(arr[i].getDate())
//                    < convertDateToSortableInt(arr[i + 1].getDate())) {
//                    Appointment temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
//                }
//    }
//
//    void sortPrescriptionsByDateDescending(Prescription* arr, int count) {
//        for (int pass = 0; pass < count - 1; pass++)
//            for (int i = 0; i < count - pass - 1; i++)
//                if (convertDateToSortableInt(arr[i].getDate())
//                    < convertDateToSortableInt(arr[i + 1].getDate())) {
//                    Prescription temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
//                }
//    }
//
//    void sortAppointmentsByTimeSlotAscending(Appointment* arr, int count) {
//        for (int pass = 0; pass < count - 1; pass++)
//            for (int i = 0; i < count - pass - 1; i++)
//                if (compareStrings(arr[i].getTimeSlot(), arr[i + 1].getTimeSlot()) > 0) {
//                    Appointment temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
//                }
//    }
//};
//
//// ============================================================
//// SECURITY LOG
//// ============================================================
//
//void writeSecurityLogEntry(Hospital& hospital, const char* userRole,
//    const char* enteredID, const char* result) {
//    char logEntry[512];
//    char timestamp[32];
//    getCurrentTimestampString(timestamp, hospital.systemDate, hospital.systemTime);
//    copyString(logEntry, timestamp);     appendString(logEntry, ",");
//    appendString(logEntry, userRole);    appendString(logEntry, ",");
//    appendString(logEntry, enteredID);   appendString(logEntry, ",");
//    appendString(logEntry, result);
//    FileHandler::appendSecurityLogEntry(logEntry);
//}
//
//// ============================================================
//// STARTUP
//// ============================================================
//
//void loadAllDataFromFiles(Hospital& hospital) {
//    try { FileHandler::loadPatientsFromFile(hospital.patients, "patients.txt"); }
//    catch (...) { cout << "Warning: patients.txt could not be loaded.\n"; }
//
//    try { FileHandler::loadDoctorsFromFile(hospital.doctors, "doctors.txt"); }
//    catch (...) { cout << "Warning: doctors.txt could not be loaded.\n"; }
//
//    try { FileHandler::loadAppointmentsFromFile(hospital.appointments, "appointments.txt"); }
//    catch (...) { cout << "Warning: appointments.txt could not be loaded.\n"; }
//
//    try { FileHandler::loadBillsFromFile(hospital.bills, "bills.txt"); }
//    catch (...) { cout << "Warning: bills.txt could not be loaded.\n"; }
//
//    try { FileHandler::loadPrescriptionsFromFile(hospital.prescriptions, "prescriptions.txt"); }
//    catch (...) { cout << "Warning: prescriptions.txt could not be loaded.\n"; }
//
//    if (!FileHandler::loadAdminFromFile(hospital.systemAdmin, "admin.txt")) {
//        try { throw FileNotFoundException("admin.txt"); }
//        catch (FileNotFoundException& exception) {
//            cout << "Warning: " << exception.what() << " - creating default admin.\n";
//            hospital.systemAdmin.setID(1);
//            hospital.systemAdmin.setName("Admin");
//            hospital.systemAdmin.setPassword("admin123");
//            ofstream defaultAdminFile("admin.txt");
//            char buffer[256];
//            hospital.systemAdmin.toFileString(buffer);
//            defaultAdminFile << buffer << "\n";
//            defaultAdminFile.close();
//        }
//    }
//}
//
//void initSystemDate(Hospital& hospital) {
//    time_t t = time(nullptr);
//    tm* lt = localtime(&t);
//    sprintf(hospital.systemDate, "%02d-%02d-%04d", lt->tm_mday, lt->tm_mon + 1, lt->tm_year + 1900);
//    sprintf(hospital.systemTime, "%02d:%02d:%02d", lt->tm_hour, lt->tm_min, lt->tm_sec);
//}
//
//// ============================================================
//// GUI LAYER  -  Simple, flat, clean design
//// No textures required. Everything drawn with primitives + font.
//// ============================================================
//
//// ---- Screen IDs ----
//enum class Screen {
//    MAIN_MENU,
//    LOGIN_PATIENT,
//    LOGIN_DOCTOR,
//    LOGIN_ADMIN,
//    REGISTER_PATIENT,
//    PATIENT_DASHBOARD,
//    DOCTOR_DASHBOARD,
//    ADMIN_DASHBOARD,
//    PAT_BOOK_APPOINTMENT,
//    PAT_VIEW_APPOINTMENTS,
//    PAT_VIEW_BILLS,
//    PAT_PAY_BILL,
//    PAT_TOP_UP,
//    PAT_VIEW_PRESCRIPTIONS,
//    PAT_SEARCH_DOCTOR,
//    DOC_TODAY_APPOINTMENTS,
//    DOC_MARK_COMPLETE,
//    DOC_MARK_NOSHOW,
//    DOC_WRITE_PRESCRIPTION,
//    DOC_PATIENT_HISTORY,
//    ADM_ADD_DOCTOR,
//    ADM_REMOVE_DOCTOR,
//    ADM_VIEW_PATIENTS,
//    ADM_VIEW_DOCTORS,
//    ADM_VIEW_APPOINTMENTS,
//    ADM_VIEW_UNPAID_BILLS,
//    ADM_DISCHARGE_PATIENT,
//    ADM_SECURITY_LOG,
//    ADM_DAILY_REPORT,
//};
//
//// ---- Dark color palette (black & blue) ----
//namespace C {
//    const sf::Color BG = sf::Color(14, 17, 23);
//    const sf::Color SIDEBAR = sf::Color(10, 12, 18);
//    const sf::Color SIDEBAR_H = sf::Color(20, 35, 60);
//    const sf::Color SIDEBAR_A = sf::Color(0, 100, 200);
//    const sf::Color TOPBAR = sf::Color(8, 10, 16);
//    const sf::Color PANEL = sf::Color(22, 27, 38);
//    const sf::Color BORDER = sf::Color(40, 55, 80);
//    const sf::Color TEXT = sf::Color(210, 220, 235);
//    const sf::Color TEXT_L = sf::Color(120, 140, 170);
//    const sf::Color TEXT_W = sf::Color(225, 235, 248);
//    const sf::Color ACCENT = sf::Color(30, 110, 220);
//    const sf::Color ACCENT_H = sf::Color(50, 140, 255);
//    const sf::Color DANGER = sf::Color(200, 50, 50);
//    const sf::Color DANGER_H = sf::Color(240, 70, 70);
//    const sf::Color SUCCESS = sf::Color(40, 180, 90);
//    const sf::Color WARNING = sf::Color(220, 160, 30);
//    const sf::Color ROW_ALT = sf::Color(18, 22, 32);
//    const sf::Color ROW_SEL = sf::Color(20, 50, 100);
//    const sf::Color ROW_HOV = sf::Color(25, 40, 70);
//    const sf::Color INPUT_BG = sf::Color(18, 22, 34);
//    const sf::Color HDR_BG = sf::Color(12, 18, 35);
//    const sf::Color STAT_BG = sf::Color(18, 22, 34);
//}
//
//// ---- Font holder (loaded once) ----
//struct Assets {
//    sf::Font font;
//    bool     ok = false;
//
//    bool load() {
//        // Try common system font paths
//        const char* paths[] = {
//            "arial.ttf",
//            "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
//            "/usr/share/fonts/TTF/DejaVuSans.ttf",
//            "/System/Library/Fonts/Helvetica.ttc",
//            "C:/Windows/Fonts/arial.ttf",
//            "sprites/Nunito-Regular.ttf",
//            "sprites/Nunito-Bold.ttf",
//        };
//        for (auto p : paths) {
//            if (font.loadFromFile(p)) { ok = true; return true; }
//        }
//        return false;
//    }
//};
//
//// ---- Toast notification ----
//struct Toast {
//    char      msg[256] = {};
//    bool      active = false;
//    float     timer = 0.f;
//    float     duration = 3.5f;
//    bool      isError = false;
//
//    void show(const char* m, bool err = false, float dur = 3.5f) {
//        strncpy(msg, m, 255);
//        active = true; timer = 0.f; duration = dur; isError = err;
//    }
//    void update(float dt) {
//        if (active) { timer += dt; if (timer >= duration) active = false; }
//    }
//};
//
//// ---- InputField ----
//struct InputField {
//    sf::RectangleShape box;
//    char   buffer[512] = {};
//    bool   focused = false;
//    bool   password = false;
//    int    cursorPos = 0;
//    float  blinkTimer = 0.f;
//    bool   showCursor = true;
//    char   placeholder[128] = {};
//
//    void setup(float x, float y, float w, float h, const char* ph) {
//        box.setPosition(x, y);
//        box.setSize({ w, h });
//        strncpy(placeholder, ph, 127);
//    }
//
//    void handleEvent(const sf::Event& e) {
//        if (!focused) return;
//        if (e.type == sf::Event::TextEntered) {
//            uint32_t ch = e.text.unicode;
//            int len = (int)strlen(buffer);
//            if (ch == 8) {
//                if (cursorPos > 0) {
//                    for (int i = cursorPos - 1; i < len - 1; i++) buffer[i] = buffer[i + 1];
//                    buffer[len - 1] = '\0'; cursorPos--;
//                }
//            }
//            else if (ch >= 32 && ch < 127 && len < 511) {
//                for (int i = len; i >= cursorPos; i--) buffer[i + 1] = buffer[i];
//                buffer[cursorPos] = (char)ch; cursorPos++;
//            }
//        }
//        if (e.type == sf::Event::KeyPressed) {
//            int len = (int)strlen(buffer);
//            if (e.key.code == sf::Keyboard::Left && cursorPos > 0)   cursorPos--;
//            if (e.key.code == sf::Keyboard::Right && cursorPos < len)  cursorPos++;
//            if (e.key.code == sf::Keyboard::Home)                       cursorPos = 0;
//            if (e.key.code == sf::Keyboard::End)                        cursorPos = len;
//            if (e.key.code == sf::Keyboard::Delete && cursorPos < len) {
//                for (int i = cursorPos; i < len - 1; i++) buffer[i] = buffer[i + 1];
//                buffer[len - 1] = '\0';
//            }
//        }
//    }
//
//    void update(float dt) {
//        blinkTimer += dt;
//        if (blinkTimer > 0.53f) { showCursor = !showCursor; blinkTimer = 0.f; }
//        box.setFillColor(C::INPUT_BG);
//        box.setOutlineThickness(1.f);
//        box.setOutlineColor(focused ? C::ACCENT : C::BORDER);
//        // cursor color is set during draw
//    }
//
//    void draw(sf::RenderWindow& w, const sf::Font& font) const {
//        w.draw(box);
//        float fx = box.getPosition().x + 8.f;
//        float fy = box.getPosition().y + (box.getSize().y - 16.f) / 2.f;
//
//        std::string disp;
//        if (strlen(buffer) == 0 && !focused) {
//            sf::Text ph;
//            ph.setFont(font); ph.setString(placeholder);
//            ph.setCharacterSize(14); ph.setFillColor(sf::Color(80, 100, 130));
//            ph.setPosition(fx, fy);
//            w.draw(ph);
//            return;
//        }
//        if (password) { for (int i = 0; buffer[i]; i++) disp += '*'; }
//        else { disp = buffer; }
//
//        sf::Text t;
//        t.setFont(font); t.setString(disp);
//        t.setCharacterSize(14); t.setFillColor(C::TEXT);
//        t.setPosition(fx, fy);
//        w.draw(t);
//
//        if (focused && showCursor) {
//            std::string before = password ? std::string(cursorPos, '*')
//                : std::string(buffer, cursorPos);
//            sf::Text tmp = t; tmp.setString(before);
//            float cx2 = fx + tmp.getLocalBounds().width + 1.f;
//            sf::RectangleShape cur({ 1.5f, 18.f });
//            cur.setPosition(cx2, fy);
//            cur.setFillColor(C::ACCENT);
//            w.draw(cur);
//        }
//    }
//
//    void clear() { memset(buffer, 0, sizeof(buffer)); cursorPos = 0; }
//    bool contains(sf::Vector2f p) const { return box.getGlobalBounds().contains(p); }
//};
//
//// ---- Button ----
//struct Button {
//    sf::RectangleShape box;
//    char   label[128] = {};
//    bool   danger = false;
//    bool   secondary = false;
//    bool   hovered = false;
//
//    void setup(float x, float y, float w, float h,
//        const char* lbl, bool isDanger = false, bool isSec = false) {
//        box.setPosition(x, y); box.setSize({ w, h });
//        strncpy(label, lbl, 127);
//        danger = isDanger; secondary = isSec;
//        updateColor();
//    }
//
//    void updateColor() {
//        if (danger)         box.setFillColor(hovered ? C::DANGER_H : C::DANGER);
//        else if (secondary) box.setFillColor(hovered ? sf::Color(35, 50, 75) : sf::Color(25, 38, 60));
//        else                box.setFillColor(hovered ? C::ACCENT_H : C::ACCENT);
//        box.setOutlineThickness(0);
//    }
//
//    void update(sf::Vector2f mouse) {
//        bool was = hovered;
//        hovered = box.getGlobalBounds().contains(mouse);
//        if (hovered != was) updateColor();
//    }
//
//    void draw(sf::RenderWindow& w, const sf::Font& font) const {
//        if (box.getSize().x < 1.f) return;
//        w.draw(box);
//        sf::Text t;
//        t.setFont(font); t.setString(label);
//        t.setCharacterSize(14); t.setFillColor(sf::Color::White);
//        auto lb = t.getLocalBounds();
//        auto bp = box.getPosition(); auto bs = box.getSize();
//        t.setPosition(bp.x + (bs.x - lb.width) / 2.f - lb.left,
//            bp.y + (bs.y - lb.height) / 2.f - lb.top - 2.f);
//        w.draw(t);
//    }
//
//    bool isClicked(sf::Vector2f mp) const {
//        return box.getSize().x > 1.f && box.getGlobalBounds().contains(mp);
//    }
//};
//
//// ---- ScrollList ----
//struct ScrollList {
//    sf::RectangleShape  viewport;
//    float               scrollY = 0.f;
//    float               rowHeight = 28.f;
//    static const int    MAX_ROWS = 200;
//    char                rows[MAX_ROWS][512];
//    int                 rowCount = 0;
//    int                 selectedRow = -1;
//    int                 hoveredRow = -1;
//
//    void setup(float x, float y, float w, float h) {
//        viewport.setPosition(x, y);
//        viewport.setSize({ w, h });
//        viewport.setFillColor(sf::Color::Transparent);
//    }
//
//    void clear() { rowCount = 0; scrollY = 0.f; selectedRow = -1; }
//
//    void addRow(const char* text) {
//        if (rowCount < MAX_ROWS) strncpy(rows[rowCount++], text, 511);
//    }
//
//    float maxScroll() const {
//        float total = rowCount * rowHeight;
//        float vis = viewport.getSize().y;
//        return total > vis ? total - vis : 0.f;
//    }
//
//    void handleScroll(float delta) {
//        scrollY -= delta * 25.f;
//        scrollY = std::max(0.f, std::min(maxScroll(), scrollY));
//    }
//
//    void handleClick(sf::Vector2f p) {
//        if (!viewport.getGlobalBounds().contains(p)) return;
//        float localY = p.y - viewport.getPosition().y + scrollY;
//        int row = (int)(localY / rowHeight);
//        if (row >= 0 && row < rowCount) selectedRow = row;
//    }
//
//    void updateHover(sf::Vector2f p) {
//        if (!viewport.getGlobalBounds().contains(p)) { hoveredRow = -1; return; }
//        float localY = p.y - viewport.getPosition().y + scrollY;
//        int row = (int)(localY / rowHeight);
//        hoveredRow = (row >= 0 && row < rowCount) ? row : -1;
//    }
//
//    void draw(sf::RenderWindow& win, const sf::Font& font) const {
//        // Clip region (draw background)
//        sf::RectangleShape bg = viewport;
//        bg.setFillColor(sf::Color(18, 22, 32));
//        bg.setOutlineThickness(1.f);
//        bg.setOutlineColor(C::BORDER);
//        win.draw(bg);
//
//        float startY = viewport.getPosition().y;
//        float endY = startY + viewport.getSize().y;
//        float vx = viewport.getPosition().x;
//        float vw = viewport.getSize().x;
//
//        for (int i = 0; i < rowCount; i++) {
//            float ry = startY + i * rowHeight - scrollY;
//            if (ry + rowHeight < startY || ry > endY) continue;
//
//            sf::RectangleShape rowBg({ vw, rowHeight - 1.f });
//            rowBg.setPosition(vx, ry);
//            if (i == selectedRow)      rowBg.setFillColor(C::ROW_SEL);
//            else if (i == hoveredRow)  rowBg.setFillColor(C::ROW_HOV);
//            else if (i % 2 == 0)       rowBg.setFillColor(C::ROW_ALT);
//            else                       rowBg.setFillColor(C::PANEL);
//            win.draw(rowBg);
//
//            sf::Text t;
//            t.setFont(font);
//            t.setCharacterSize(13);
//            t.setFillColor(C::TEXT);
//            t.setString(rows[i]);
//            t.setPosition(vx + 8.f, ry + (rowHeight - 15.f) / 2.f);
//            win.draw(t);
//        }
//
//        // Scrollbar
//        float ms = maxScroll();
//        if (ms > 0.f) {
//            float barH = viewport.getSize().y * (viewport.getSize().y / (rowCount * rowHeight));
//            barH = std::max(20.f, barH);
//            float barY = startY + (scrollY / ms) * (viewport.getSize().y - barH);
//            sf::RectangleShape bar({ 5.f, barH });
//            bar.setPosition(vx + vw - 6.f, barY);
//            bar.setFillColor(sf::Color(50, 70, 110));
//            win.draw(bar);
//        }
//    }
//
//    const char* getSelected() const {
//        if (selectedRow >= 0 && selectedRow < rowCount) return rows[selectedRow];
//        return nullptr;
//    }
//};
//
//// ---- GUIState ----
//struct GUIState {
//    Screen currentScreen = Screen::MAIN_MENU;
//    Screen prevScreen = Screen::MAIN_MENU;
//    Toast  toast;
//    float  globalTime = 0.f;
//    bool   needsRefresh = true;
//    int    loggedInID = -1;
//    char   loggedInName[256] = {};
//    char   loggedInRole[32] = {};
//    int    loginAttempts = 0;
//
//    void goTo(Screen s) {
//        prevScreen = currentScreen;
//        currentScreen = s;
//        needsRefresh = true;
//    }
//
//    void logout() {
//        loggedInID = -1;
//        loggedInName[0] = '\0';
//        loggedInRole[0] = '\0';
//        loginAttempts = 0;
//        goTo(Screen::MAIN_MENU);
//    }
//};
//
//// ---- Simple draw helpers ----
//namespace Draw {
//
//    inline void rect(sf::RenderWindow& w, float x, float y, float rw, float rh,
//        sf::Color fill, sf::Color border = sf::Color::Transparent, float bthick = 0.f) {
//        sf::RectangleShape r({ rw, rh });
//        r.setPosition(x, y);
//        r.setFillColor(fill);
//        if (bthick > 0.f) { r.setOutlineThickness(bthick); r.setOutlineColor(border); }
//        w.draw(r);
//    }
//
//    inline void text(sf::RenderWindow& w, const sf::Font& font,
//        const char* str, float x, float y,
//        unsigned int size = 14, sf::Color col = C::TEXT) {
//        sf::Text t;
//        t.setFont(font); t.setString(str);
//        t.setCharacterSize(size); t.setFillColor(col);
//        t.setPosition(x, y);
//        w.draw(t);
//    }
//
//    inline void textCentered(sf::RenderWindow& w, const sf::Font& font,
//        const char* str, float cx, float cy,
//        unsigned int size, sf::Color col) {
//        sf::Text t;
//        t.setFont(font); t.setString(str);
//        t.setCharacterSize(size); t.setFillColor(col);
//        auto lb = t.getLocalBounds();
//        t.setPosition(cx - lb.width / 2.f - lb.left, cy - lb.height / 2.f - lb.top);
//        w.draw(t);
//    }
//
//    // Top bar
//    inline void topbar(sf::RenderWindow& w, const sf::Font& font,
//        const GUIState& gs) {
//        rect(w, 0.f, 0.f, 1280.f, 52.f, C::TOPBAR);
//        // Blue accent line at top
//        rect(w, 0.f, 0.f, 1280.f, 2.f, sf::Color(30, 110, 220));
//        text(w, font, "MediCore  Hospital Management System",
//            16.f, 16.f, 18, C::TEXT_W);
//        if (gs.loggedInID >= 0) {
//            char info[300];
//            snprintf(info, sizeof(info), "%s  |  %s", gs.loggedInRole, gs.loggedInName);
//            sf::Text t2;
//            t2.setFont(font); t2.setString(info);
//            t2.setCharacterSize(13); t2.setFillColor(sf::Color(100, 140, 200));
//            t2.setPosition(1270.f - t2.getLocalBounds().width, 18.f);
//            w.draw(t2);
//        }
//        // Bottom line under topbar
//        rect(w, 0.f, 52.f, 1280.f, 1.f, sf::Color(30, 110, 220));
//    }
//
//    // Left sidebar
//    struct SidebarItem {
//        const char* label;
//        Screen      target;
//        bool        isDanger;
//    };
//
//    inline int sidebar(sf::RenderWindow& w, const sf::Font& font,
//        const GUIState& gs,
//        const SidebarItem* items, int count,
//        sf::Vector2f mouse, bool click) {
//        rect(w, 0.f, 53.f, 200.f, 667.f, C::SIDEBAR);
//        int clicked = -1;
//        for (int i = 0; i < count; i++) {
//            float iy = 53.f + i * 46.f;
//            bool active = (gs.currentScreen == items[i].target);
//            bool hov = sf::FloatRect(0.f, iy, 200.f, 44.f).contains(mouse);
//
//            sf::Color bg = C::SIDEBAR;
//            if (active) bg = C::SIDEBAR_A;
//            else if (hov) bg = C::SIDEBAR_H;
//            rect(w, 0.f, iy, 200.f, 44.f, bg);
//
//            // Left accent for active
//            if (active) rect(w, 0.f, iy, 3.f, 44.f, sf::Color(50, 140, 255));
//
//            sf::Color tc = items[i].isDanger ? sf::Color(255, 80, 80)
//                : active ? sf::Color::White
//                : sf::Color(140, 160, 190);
//            text(w, font, items[i].label, 18.f, iy + 14.f, 14, tc);
//
//            if (click && hov) clicked = i;
//        }
//        return clicked;
//    }
//
//    // Panel
//    inline void panel(sf::RenderWindow& w, float x, float y,
//        float pw, float ph, const char* title, const sf::Font& font) {
//        rect(w, x, y, pw, ph, C::PANEL, C::BORDER, 1.f);
//        if (title && title[0]) {
//            rect(w, x, y, pw, 38.f, sf::Color(15, 22, 45));
//            text(w, font, title, x + 12.f, y + 11.f, 14, C::TEXT_W);
//            rect(w, x, y + 38.f, pw, 1.f, C::BORDER);
//        }
//    }
//
//    // Table header
//    inline void tableHeader(sf::RenderWindow& w, const sf::Font& font,
//        float x, float y, float tw,
//        const char* cols[], const float colW[], int n) {
//        rect(w, x, y, tw, 26.f, C::HDR_BG);
//        float cx2 = x + 6.f;
//        for (int i = 0; i < n; i++) {
//            text(w, font, cols[i], cx2, y + 6.f, 12, sf::Color(200, 215, 230));
//            cx2 += colW[i];
//        }
//    }
//
//    // Stat card
//    inline void statCard(sf::RenderWindow& w, const sf::Font& font,
//        float x, float y, float cw, float ch,
//        const char* title2, const char* value,
//        sf::Color accent) {
//        rect(w, x, y, cw, ch, C::STAT_BG, C::BORDER, 1.f);
//        rect(w, x, y, 4.f, ch, accent);
//        text(w, font, value, x + 14.f, y + 12.f, 24, C::TEXT);
//        text(w, font, title2, x + 14.f, y + ch - 22.f, 12, C::TEXT_L);
//    }
//
//    // Toast
//    inline void toast(sf::RenderWindow& w, const sf::Font& font, const Toast& t) {
//        if (!t.active) return;
//        float alpha = 1.f;
//        if (t.timer < 0.25f)              alpha = t.timer / 0.25f;
//        else if (t.timer > t.duration - 0.3f) alpha = (t.duration - t.timer) / 0.3f;
//        alpha = std::max(0.f, std::min(1.f, alpha));
//        sf::Uint8 a8 = (sf::Uint8)(alpha * 235);
//
//        float tw2 = 460.f, th = 44.f;
//        float tx = (1280.f - tw2) / 2.f, ty = 668.f;
//
//        sf::Color bg = t.isError ? sf::Color(160, 30, 30, a8)
//            : sf::Color(20, 100, 50, a8);
//        rect(w, tx, ty, tw2, th, bg);
//
//        sf::Text txt;
//        txt.setFont(font); txt.setString(t.msg);
//        txt.setCharacterSize(14); txt.setFillColor(sf::Color(255, 255, 255, a8));
//        auto lb = txt.getLocalBounds();
//        txt.setPosition(tx + (tw2 - lb.width) / 2.f, ty + (th - lb.height) / 2.f - 2.f);
//        w.draw(txt);
//    }
//
//    // Status badge text
//    inline sf::Color statusColor(const char* s) {
//        if (strncmp(s, "completed", 9) == 0) return C::SUCCESS;
//        if (strncmp(s, "cancelled", 9) == 0) return C::TEXT_L;
//        if (strncmp(s, "noshow", 6) == 0) return C::DANGER;
//        if (strncmp(s, "paid", 4) == 0) return C::SUCCESS;
//        if (strncmp(s, "unpaid", 6) == 0) return C::WARNING;
//        return C::ACCENT;  // pending
//    }
//
//} // namespace Draw
//
//// ---- Sidebar item lists ----
//static Draw::SidebarItem g_patientSidebar[] = {
//    { "Overview",          Screen::PATIENT_DASHBOARD,      false },
//    { "Book Appointment",  Screen::PAT_BOOK_APPOINTMENT,   false },
//    { "My Appointments",   Screen::PAT_VIEW_APPOINTMENTS,  false },
//    { "My Bills",          Screen::PAT_VIEW_BILLS,         false },
//    { "My Prescriptions",  Screen::PAT_VIEW_PRESCRIPTIONS, false },
//    { "Search Doctors",    Screen::PAT_SEARCH_DOCTOR,      false },
//    { "Top Up Balance",    Screen::PAT_TOP_UP,             false },
//    { "Logout",            Screen::MAIN_MENU,              true  },
//};
//
//static Draw::SidebarItem g_doctorSidebar[] = {
//    { "Overview",             Screen::DOCTOR_DASHBOARD,       false },
//    { "Today's Apts",         Screen::DOC_TODAY_APPOINTMENTS, false },
//    { "Mark Complete",        Screen::DOC_MARK_COMPLETE,      false },
//    { "Mark No-Show",         Screen::DOC_MARK_NOSHOW,        false },
//    { "Write Prescription",   Screen::DOC_WRITE_PRESCRIPTION, false },
//    { "Patient History",      Screen::DOC_PATIENT_HISTORY,    false },
//    { "Logout",               Screen::MAIN_MENU,              true  },
//};
//
//static Draw::SidebarItem g_adminSidebar[] = {
//    { "Dashboard",         Screen::ADMIN_DASHBOARD,        false },
//    { "Add Doctor",        Screen::ADM_ADD_DOCTOR,         false },
//    { "Remove Doctor",     Screen::ADM_REMOVE_DOCTOR,      false },
//    { "All Patients",      Screen::ADM_VIEW_PATIENTS,      false },
//    { "All Doctors",       Screen::ADM_VIEW_DOCTORS,       false },
//    { "Appointments",      Screen::ADM_VIEW_APPOINTMENTS,  false },
//    { "Unpaid Bills",      Screen::ADM_VIEW_UNPAID_BILLS,  false },
//    { "Discharge Patient", Screen::ADM_DISCHARGE_PATIENT,  false },
//    { "Security Log",      Screen::ADM_SECURITY_LOG,       false },
//    { "Daily Report",      Screen::ADM_DAILY_REPORT,       false },
//    { "Logout",            Screen::MAIN_MENU,              true  },
//};
//
//// ---- Status message ----
//static char g_statusMsg[512] = {};
//static bool g_statusIsError = false;
//
//void setStatus(GUIState& gs, const char* msg, bool err = false) {
//    strncpy(g_statusMsg, msg, 511);
//    g_statusIsError = err;
//    gs.toast.show(msg, err);
//}
//
//// ============================================================
//// SCREEN DRAW FUNCTIONS
//// ============================================================
//
//void drawMainMenu(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Button btns[]) {
//    // Background
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//
//    // Center card
//    float pw = 380.f, ph = 380.f;
//    float px = (1280.f - pw) / 2.f, py = 130.f;
//    Draw::rect(w, px, py, pw, ph, C::PANEL, C::BORDER, 1.f);
//
//    // Title area
//    Draw::rect(w, px, py, pw, 64.f, sf::Color(10, 14, 25));
//    Draw::rect(w, px, py, pw, 2.f, sf::Color(30, 110, 220));
//    Draw::textCentered(w, a.font, "MediCore HMS", px + pw / 2.f, py + 22.f, 20, C::TEXT_W);
//    Draw::textCentered(w, a.font, "Hospital Management System", px + pw / 2.f, py + 46.f, 12,
//        sf::Color(80, 120, 180));
//
//    Draw::rect(w, px + 20.f, py + 76.f, pw - 40.f, 1.f, C::BORDER);
//
//    for (int i = 0; i < 4; i++) btns[i].draw(w, a.font);
//}
//
//void drawLoginScreen(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Button btns[], InputField fields[]) {
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//
//    const char* roleLabel =
//        (gs.currentScreen == Screen::LOGIN_PATIENT) ? "Patient Login" :
//        (gs.currentScreen == Screen::LOGIN_DOCTOR) ? "Doctor Login" : "Admin Login";
//
//    float pw = 380.f, ph = 300.f;
//    float px = (1280.f - pw) / 2.f, py = 160.f;
//    Draw::panel(w, px, py, pw, ph, roleLabel, a.font);
//
//    Draw::text(w, a.font, "ID Number", px + 20.f, py + 52.f, 12, C::TEXT_L);
//    fields[0].draw(w, a.font);
//    Draw::text(w, a.font, "Password", px + 20.f, py + 118.f, 12, C::TEXT_L);
//    fields[1].draw(w, a.font);
//
//    if (gs.loginAttempts > 0) {
//        char attempts[64];
//        snprintf(attempts, sizeof(attempts), "Failed attempts: %d / 3", gs.loginAttempts);
//        Draw::text(w, a.font, attempts, px + 20.f, py + 182.f, 12, C::DANGER);
//    }
//
//    btns[0].draw(w, a.font);
//    btns[1].draw(w, a.font);
//}
//
//void drawRegisterScreen(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Button btns[], InputField fields[]) {
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//
//    float pw = 680.f, ph = 500.f;
//    float px = (1280.f - pw) / 2.f, py = 80.f;
//    Draw::panel(w, px, py, pw, ph, "New Patient Registration", a.font);
//
//    const char* labels[] = { "Full Name","Age","Gender (M/F)",
//                              "Contact (11 digits)","Password (min 6)","Confirm Password" };
//    for (int i = 0; i < 6; i++) {
//        float fy = py + 52.f + i * 64.f;
//        Draw::text(w, a.font, labels[i], px + 20.f, fy, 12, C::TEXT_L);
//        fields[i].draw(w, a.font);
//    }
//
//    // Info box
//    float ix = px + pw / 2.f + 10.f;
//    Draw::rect(w, ix, py + 52.f, pw / 2.f - 30.f, 180.f, sf::Color(18, 22, 34), C::BORDER, 1.f);
//    Draw::text(w, a.font, "Notes", ix + 12.f, py + 62.f, 13, C::ACCENT);
//    Draw::text(w, a.font, "- ID assigned auto", ix + 12.f, py + 86.f, 12, C::TEXT_L);
//    Draw::text(w, a.font, "- Contact: 11 digits", ix + 12.f, py + 106.f, 12, C::TEXT_L);
//    Draw::text(w, a.font, "- Password: 6+ chars", ix + 12.f, py + 126.f, 12, C::TEXT_L);
//    Draw::text(w, a.font, "- Gender: M or F", ix + 12.f, py + 146.f, 12, C::TEXT_L);
//    Draw::text(w, a.font, "- Balance starts 0", ix + 12.f, py + 166.f, 12, C::TEXT_L);
//    Draw::text(w, a.font, "- Login via ID+Pass", ix + 12.f, py + 186.f, 12, C::TEXT_L);
//
//    btns[0].draw(w, a.font);
//    btns[1].draw(w, a.font);
//}
//
//void drawPatientDashboard(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Hospital& h, ScrollList& list,
//    sf::Vector2f mouse, bool click) {
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//    Draw::sidebar(w, a.font, gs, g_patientSidebar, 8, mouse, false);
//
//    Patient* pat = h.findPatientByID(gs.loggedInID);
//    float cx = 210.f, cy = 62.f, cw = 1060.f;
//
//    // Banner
//    Draw::rect(w, cx, cy, cw, 56.f, C::TOPBAR);
//    char welcome[300];
//    snprintf(welcome, sizeof(welcome), "Welcome, %s", pat ? pat->getName() : "Patient");
//    Draw::text(w, a.font, welcome, cx + 14.f, cy + 10.f, 17, C::TEXT_W);
//    if (pat) {
//        char bBuf[32]; convertDoubleToString(pat->getBalance(), bBuf);
//        char balLine[80]; snprintf(balLine, sizeof(balLine), "Balance: PKR %s", bBuf);
//        Draw::text(w, a.font, balLine, cx + 14.f, cy + 34.f, 12, sf::Color(80, 150, 220));
//    }
//
//    // Stat cards
//    int pendingApt = 0, totalApt = 0, unpaidBills = 0;
//    if (pat) {
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (apt.getPatientID() == pat->getID()) {
//                totalApt++;
//                if (compareStrings(apt.getStatus(), "pending") == 0) pendingApt++;
//            }
//        }
//        for (int i = 0; i < h.bills.size(); i++) {
//            auto& b = h.bills.getAll()[i];
//            if (b.getPatientID() == pat->getID() &&
//                compareStrings(b.getStatus(), "unpaid") == 0) unpaidBills++;
//        }
//    }
//    char s1[16], s2[16], s3[16];
//    convertIntToString(totalApt, s1);
//    convertIntToString(pendingApt, s2);
//    convertIntToString(unpaidBills, s3);
//
//    float cardW = (cw - 30.f) / 3.f;
//    Draw::statCard(w, a.font, cx + 8.f, cy + 64.f, cardW, 72.f, "Total Appointments", s1, C::ACCENT);
//    Draw::statCard(w, a.font, cx + 8.f + cardW, cy + 64.f, cardW, 72.f, "Pending", s2, C::WARNING);
//    Draw::statCard(w, a.font, cx + 8.f + cardW * 2, cy + 64.f, cardW, 72.f, "Unpaid Bills", s3, C::DANGER);
//
//    // Recent appointments table
//    Draw::text(w, a.font, "Recent Appointments", cx + 8.f, cy + 148.f, 14, C::TEXT);
//    Draw::rect(w, cx + 8.f, cy + 168.f, cw - 16.f, 1.f, C::BORDER);
//
//    const char* cols[] = { "ID","Date","Time","Doctor","Specialization","Status" };
//    float colW[] = { 45.f,95.f,65.f,180.f,175.f,100.f };
//    Draw::tableHeader(w, a.font, cx + 8.f, cy + 170.f, cw - 16.f, cols, colW, 6);
//
//    list.setup(cx + 8.f, cy + 196.f, cw - 16.f, 520.f - 196.f);
//    list.clear();
//    if (pat) {
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (apt.getPatientID() != pat->getID()) continue;
//            Doctor* doc = h.findDoctorByID(apt.getDoctorID());
//            char row[512];
//            snprintf(row, sizeof(row), "%-5d  %-12s  %-8s  %-22s  %-22s  %s",
//                apt.getID(), apt.getDate(), apt.getTimeSlot(),
//                doc ? doc->getName() : "N/A",
//                doc ? doc->getSpecialization() : "N/A",
//                apt.getStatus());
//            list.addRow(row);
//        }
//    }
//    if (list.rowCount == 0) list.addRow("  No appointments yet.");
//    list.draw(w, a.font);
//}
//
//void drawDoctorDashboard(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Hospital& h, ScrollList& list,
//    sf::Vector2f mouse) {
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//    Draw::sidebar(w, a.font, gs, g_doctorSidebar, 7, mouse, false);
//
//    Doctor* doc = h.findDoctorByID(gs.loggedInID);
//    float cx = 210.f, cy = 62.f, cw = 1060.f;
//
//    Draw::rect(w, cx, cy, cw, 56.f, C::TOPBAR);
//    char welcome[300];
//    snprintf(welcome, sizeof(welcome), "Dr. %s", doc ? doc->getName() : "Doctor");
//    Draw::text(w, a.font, welcome, cx + 14.f, cy + 10.f, 17, C::TEXT_W);
//    if (doc) {
//        char sub[200]; char fBuf[24]; convertDoubleToString(doc->getFee(), fBuf);
//        snprintf(sub, sizeof(sub), "%s   |   Fee: PKR %s / visit", doc->getSpecialization(), fBuf);
//        Draw::text(w, a.font, sub, cx + 14.f, cy + 34.f, 12, sf::Color(80, 150, 220));
//    }
//
//    char todayDate[16]; getTodayDateString(todayDate, h.systemDate);
//    int todayTotal = 0, todayCompleted = 0;
//    if (doc) {
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (apt.getDoctorID() == doc->getID() &&
//                compareStrings(apt.getDate(), todayDate) == 0) {
//                todayTotal++;
//                if (compareStrings(apt.getStatus(), "completed") == 0) todayCompleted++;
//            }
//        }
//    }
//    char st[16], sc[16];
//    convertIntToString(todayTotal, st); convertIntToString(todayCompleted, sc);
//    float cardW = (cw - 20.f) / 2.f;
//    Draw::statCard(w, a.font, cx + 8.f, cy + 64.f, cardW, 72.f, "Today's Appointments", st, C::ACCENT);
//    Draw::statCard(w, a.font, cx + 8.f + cardW, cy + 64.f, cardW, 72.f, "Completed Today", sc, C::SUCCESS);
//
//    Draw::text(w, a.font, "Today's Schedule", cx + 8.f, cy + 148.f, 14, C::TEXT);
//    Draw::rect(w, cx + 8.f, cy + 168.f, cw - 16.f, 1.f, C::BORDER);
//    const char* cols[] = { "AptID","Patient","Time","Status" };
//    float colW[] = { 70.f,300.f,110.f,130.f };
//    Draw::tableHeader(w, a.font, cx + 8.f, cy + 170.f, cw - 16.f, cols, colW, 4);
//    list.setup(cx + 8.f, cy + 196.f, cw - 16.f, 520.f - 196.f);
//    list.clear();
//    if (doc) {
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (apt.getDoctorID() != doc->getID()) continue;
//            if (compareStrings(apt.getDate(), todayDate) != 0) continue;
//            Patient* pat = h.findPatientByID(apt.getPatientID());
//            char row[512];
//            snprintf(row, sizeof(row), "%-8d  %-32s  %-12s  %s",
//                apt.getID(), pat ? pat->getName() : "Unknown",
//                apt.getTimeSlot(), apt.getStatus());
//            list.addRow(row);
//        }
//    }
//    if (list.rowCount == 0) list.addRow("  No appointments today.");
//    list.draw(w, a.font);
//}
//
//void drawAdminDashboard(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Hospital& h, ScrollList& list, sf::Vector2f mouse) {
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//    Draw::sidebar(w, a.font, gs, g_adminSidebar, 11, mouse, false);
//
//    float cx = 210.f, cy = 62.f, cw = 1060.f;
//    Draw::rect(w, cx, cy, cw, 56.f, C::TOPBAR);
//    Draw::text(w, a.font, "Admin Panel", cx + 14.f, cy + 10.f, 17, C::TEXT_W);
//    Draw::text(w, a.font, "MediCore Hospital Management System",
//        cx + 14.f, cy + 34.f, 12, sf::Color(80, 150, 220));
//
//    char ps[16], ds[16], as2[16], us[16];
//    convertIntToString(h.patients.size(), ps);
//    convertIntToString(h.doctors.size(), ds);
//    convertIntToString(h.appointments.size(), as2);
//    int unpaid = 0;
//    for (int i = 0; i < h.bills.size(); i++)
//        if (compareStrings(h.bills.getAll()[i].getStatus(), "unpaid") == 0) unpaid++;
//    convertIntToString(unpaid, us);
//
//    float cardW = (cw - 30.f) / 4.f;
//    Draw::statCard(w, a.font, cx + 8.f, cy + 64.f, cardW, 72.f, "Total Patients", ps, C::ACCENT);
//    Draw::statCard(w, a.font, cx + 8.f + cardW, cy + 64.f, cardW, 72.f, "Total Doctors", ds, sf::Color(100, 60, 180));
//    Draw::statCard(w, a.font, cx + 8.f + cardW * 2, cy + 64.f, cardW, 72.f, "Appointments", as2, C::SUCCESS);
//    Draw::statCard(w, a.font, cx + 8.f + cardW * 3, cy + 64.f, cardW, 72.f, "Unpaid Bills", us, C::DANGER);
//
//    Draw::text(w, a.font, "All Patients", cx + 8.f, cy + 148.f, 14, C::TEXT);
//    Draw::rect(w, cx + 8.f, cy + 168.f, cw - 16.f, 1.f, C::BORDER);
//    const char* cols[] = { "ID","Name","Age","Gender","Contact","Balance" };
//    float colW[] = { 55.f,200.f,45.f,65.f,120.f,130.f };
//    Draw::tableHeader(w, a.font, cx + 8.f, cy + 170.f, cw - 16.f, cols, colW, 6);
//    list.setup(cx + 8.f, cy + 196.f, cw - 16.f, 520.f - 196.f);
//    list.clear();
//    for (int i = 0; i < h.patients.size(); i++) {
//        auto& pat = h.patients.getAll()[i];
//        char bBuf[24]; convertDoubleToString(pat.getBalance(), bBuf);
//        char row[512];
//        snprintf(row, sizeof(row), "%-6d  %-26s  %-5d  %-6s  %-14s  PKR %s",
//            pat.getID(), pat.getName(), pat.getAge(),
//            pat.getGender(), pat.getContact(), bBuf);
//        list.addRow(row);
//    }
//    if (list.rowCount == 0) list.addRow("  No patients registered.");
//    list.draw(w, a.font);
//}
//
//// ---- Sub-screen drawing ----
//void drawSubScreen(sf::RenderWindow& w, Assets& a, GUIState& gs,
//    Hospital& h, Button btns[], InputField fields[],
//    ScrollList& list, sf::Vector2f mouse) {
//    Draw::rect(w, 0, 0, 1280, 720, C::BG);
//    Draw::topbar(w, a.font, gs);
//
//    bool isP = (strncmp(gs.loggedInRole, "Patient", 7) == 0);
//    bool isD = (strncmp(gs.loggedInRole, "Doctor", 6) == 0);
//
//    if (isP)      Draw::sidebar(w, a.font, gs, g_patientSidebar, 8, mouse, false);
//    else if (isD) Draw::sidebar(w, a.font, gs, g_doctorSidebar, 7, mouse, false);
//    else          Draw::sidebar(w, a.font, gs, g_adminSidebar, 11, mouse, false);
//
//    Patient* pat = isP ? h.findPatientByID(gs.loggedInID) : nullptr;
//    Doctor* doc = isD ? h.findDoctorByID(gs.loggedInID) : nullptr;
//
//    float cx = 210.f, cy = 62.f, cw = 1060.f;
//    char todayDate[16]; getTodayDateString(todayDate, h.systemDate);
//
//    switch (gs.currentScreen) {
//
//        // ---- Patient: Book Appointment ----
//    case Screen::PAT_BOOK_APPOINTMENT: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Book Appointment", a.font);
//        Draw::text(w, a.font, "Available Doctors", cx + 12.f, cy + 48.f, 13, C::TEXT_L);
//        const char* cols[] = { "ID","Name","Specialization","Fee (PKR)" };
//        float colW[] = { 55.f,220.f,230.f,110.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 66.f, 640.f, cols, colW, 4);
//        list.setup(cx + 12.f, cy + 92.f, 640.f, 200.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            for (int i = 0; i < h.doctors.size(); i++) {
//                auto& d = h.doctors.getAll()[i];
//                char bBuf[24]; convertDoubleToString(d.getFee(), bBuf);
//                char row[512];
//                snprintf(row, sizeof(row), "%-5d  %-26s  %-26s  %s",
//                    d.getID(), d.getName(), d.getSpecialization(), bBuf);
//                list.addRow(row);
//            }
//        }
//        list.draw(w, a.font);
//
//        float fy = cy + 302.f;
//        Draw::text(w, a.font, "Doctor ID:", cx + 12.f, fy, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        Draw::text(w, a.font, "Date (DD-MM-YYYY):", cx + 12.f, fy + 64.f, 12, C::TEXT_L);
//        fields[1].draw(w, a.font);
//        Draw::text(w, a.font, "Time Slot (09:00-16:00):", cx + 12.f, fy + 128.f, 12, C::TEXT_L);
//        fields[2].draw(w, a.font);
//
//        // Slot reference box
//        float sx = cx + 680.f;
//        Draw::rect(w, sx, cy + 66.f, 360.f, 200.f, sf::Color(18, 22, 34), C::BORDER, 1.f);
//        Draw::text(w, a.font, "Available Time Slots", sx + 10.f, cy + 74.f, 13, C::ACCENT);
//        const char* slots[] = { "09:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00" };
//        for (int i = 0; i < 8; i++) {
//            float sx2 = sx + 10.f + (i % 2) * 170.f;
//            float sy2 = cy + 98.f + (i / 2) * 36.f;
//            Draw::rect(w, sx2, sy2, 150.f, 28.f, C::PANEL, C::BORDER, 1.f);
//            Draw::text(w, a.font, slots[i], sx2 + 8.f, sy2 + 7.f, 13, C::TEXT);
//        }
//
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        gs.needsRefresh = false;
//        break;
//    }
//
//                                     // ---- Patient: View Appointments ----
//    case Screen::PAT_VIEW_APPOINTMENTS: {
//        Draw::panel(w, cx, cy, cw, 656.f, "My Appointments", a.font);
//        const char* cols[] = { "ID","Date","Time","Doctor","Specialization","Status" };
//        float colW[] = { 45.f,100.f,65.f,200.f,190.f,110.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 46.f, cw - 24.f, cols, colW, 6);
//        list.setup(cx + 12.f, cy + 72.f, cw - 24.f, 530.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            if (pat) for (int i = 0; i < h.appointments.size(); i++) {
//                auto& apt = h.appointments.getAll()[i];
//                if (apt.getPatientID() != pat->getID()) continue;
//                Doctor* d = h.findDoctorByID(apt.getDoctorID());
//                char row[512];
//                snprintf(row, sizeof(row), "%-5d  %-12s  %-8s  %-24s  %-22s  %s",
//                    apt.getID(), apt.getDate(), apt.getTimeSlot(),
//                    d ? d->getName() : "N/A",
//                    d ? d->getSpecialization() : "N/A",
//                    apt.getStatus());
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No appointments found.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        Draw::text(w, a.font, "Select a pending appointment to cancel it",
//            cx + 12.f, cy + 616.f, 12, C::TEXT_L);
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                                      // ---- Patient: View Bills ----
//    case Screen::PAT_VIEW_BILLS: {
//        Draw::panel(w, cx, cy, cw, 656.f, "My Bills", a.font);
//        const char* cols[] = { "Bill ID","Apt ID","Amount (PKR)","Status","Date" };
//        float colW[] = { 80.f,80.f,160.f,130.f,130.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 46.f, cw - 24.f, cols, colW, 5);
//        list.setup(cx + 12.f, cy + 72.f, cw - 24.f, 510.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            if (pat) for (int i = 0; i < h.bills.size(); i++) {
//                auto& b = h.bills.getAll()[i];
//                if (b.getPatientID() != pat->getID()) continue;
//                char amtBuf[32]; convertDoubleToString(b.getAmount(), amtBuf);
//                char row[512];
//                snprintf(row, sizeof(row), "%-8d  %-8d  %-18s  %-14s  %s",
//                    b.getID(), b.getAppointmentID(), amtBuf, b.getStatus(), b.getDate());
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No bills found.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                               // ---- Patient: Top Up ----
//    case Screen::PAT_TOP_UP: {
//        float pw2 = 400.f, ph2 = 240.f;
//        float px2 = 640.f - pw2 / 2.f, py2 = 200.f;
//        Draw::panel(w, px2, py2, pw2, ph2, "Top Up Balance", a.font);
//        if (pat) {
//            char bBuf[32]; convertDoubleToString(pat->getBalance(), bBuf);
//            char cur[128]; snprintf(cur, sizeof(cur), "Current Balance: PKR %s", bBuf);
//            Draw::text(w, a.font, cur, px2 + 16.f, py2 + 50.f, 14, C::TEXT);
//        }
//        Draw::text(w, a.font, "Amount to Add (PKR):", px2 + 16.f, py2 + 82.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                           // ---- Patient: View Prescriptions ----
//    case Screen::PAT_VIEW_PRESCRIPTIONS: {
//        Draw::panel(w, cx, cy, cw, 656.f, "My Prescriptions", a.font);
//        const char* cols[] = { "Rx ID","Date","Doctor","Medicines","Notes" };
//        float colW[] = { 65.f,105.f,170.f,300.f,200.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 46.f, cw - 24.f, cols, colW, 5);
//        list.setup(cx + 12.f, cy + 72.f, cw - 24.f, 540.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            if (pat) for (int i = 0; i < h.prescriptions.size(); i++) {
//                auto& rx = h.prescriptions.getAll()[i];
//                if (rx.getPatientID() != pat->getID()) continue;
//                Doctor* d = h.findDoctorByID(rx.getDoctorID());
//                char row[512];
//                snprintf(row, sizeof(row), "%-6d  %-12s  %-20s  %-38s  %s",
//                    rx.getID(), rx.getDate(),
//                    d ? d->getName() : "N/A",
//                    rx.getMedicines(), rx.getNotes());
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No prescriptions found.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        break;
//    }
//
//                                       // ---- Patient: Search Doctors ----
//    case Screen::PAT_SEARCH_DOCTOR: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Search Doctors", a.font);
//        Draw::text(w, a.font, "Search (name or specialization):",
//            cx + 12.f, cy + 48.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        const char* cols[] = { "ID","Name","Specialization","Fee (PKR)","Hours" };
//        float colW[] = { 55.f,220.f,230.f,120.f,150.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 112.f, cw - 24.f, cols, colW, 5);
//        list.setup(cx + 12.f, cy + 138.f, cw - 24.f, 470.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            for (int i = 0; i < h.doctors.size(); i++) {
//                auto& d = h.doctors.getAll()[i];
//                char q[256]; strncpy(q, fields[0].buffer, 255);
//                if (q[0] != '\0') {
//                    bool match = false;
//                    char needle[256]; int ni = 0;
//                    for (int ci = 0; d.getName()[ci]; ci++)
//                        needle[ni++] = (char)tolower((unsigned char)d.getName()[ci]);
//                    needle[ni] = '\0';
//                    char spec2[256]; ni = 0;
//                    for (int ci = 0; d.getSpecialization()[ci]; ci++)
//                        spec2[ni++] = (char)tolower((unsigned char)d.getSpecialization()[ci]);
//                    spec2[ni] = '\0';
//                    char qlow[256]; ni = 0;
//                    for (int ci = 0; q[ci]; ci++)
//                        qlow[ni++] = (char)tolower((unsigned char)q[ci]);
//                    qlow[ni] = '\0';
//                    for (int ci = 0; needle[ci] && !match; ci++) {
//                        bool sub = true;
//                        for (int qi = 0; qlow[qi]; qi++) {
//                            if (!needle[ci + qi]) { sub = false; break; }
//                            if (needle[ci + qi] != qlow[qi]) { sub = false; break; }
//                        }
//                        if (sub) match = true;
//                    }
//                    for (int ci = 0; spec2[ci] && !match; ci++) {
//                        bool sub = true;
//                        for (int qi = 0; qlow[qi]; qi++) {
//                            if (!spec2[ci + qi]) { sub = false; break; }
//                            if (spec2[ci + qi] != qlow[qi]) { sub = false; break; }
//                        }
//                        if (sub) match = true;
//                    }
//                    if (!match) continue;
//                }
//                char bBuf[24]; convertDoubleToString(d.getFee(), bBuf);
//                char row[512];
//                snprintf(row, sizeof(row), "%-5d  %-26s  %-26s  %-14s  09:00-16:00",
//                    d.getID(), d.getName(), d.getSpecialization(), bBuf);
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No doctors found.");
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        break;
//    }
//
//                                  // ---- Doctor: Today's Appointments ----
//    case Screen::DOC_TODAY_APPOINTMENTS: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Today's Appointments", a.font);
//        const char* cols[] = { "Apt ID","Patient","Time","Status" };
//        float colW[] = { 80.f,300.f,120.f,140.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 46.f, cw - 24.f, cols, colW, 4);
//        list.setup(cx + 12.f, cy + 72.f, cw - 24.f, 540.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            if (doc) for (int i = 0; i < h.appointments.size(); i++) {
//                auto& apt = h.appointments.getAll()[i];
//                if (apt.getDoctorID() != doc->getID()) continue;
//                if (compareStrings(apt.getDate(), todayDate) != 0) continue;
//                Patient* p = h.findPatientByID(apt.getPatientID());
//                char row[512];
//                snprintf(row, sizeof(row), "%-8d  %-32s  %-14s  %s",
//                    apt.getID(), p ? p->getName() : "Unknown",
//                    apt.getTimeSlot(), apt.getStatus());
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No appointments today.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        break;
//    }
//
//                                       // ---- Doctor: Mark Complete / No-Show ----
//    case Screen::DOC_MARK_COMPLETE:
//    case Screen::DOC_MARK_NOSHOW: {
//        bool isComplete = (gs.currentScreen == Screen::DOC_MARK_COMPLETE);
//        const char* title2 = isComplete ? "Mark Appointment Complete" : "Mark Appointment No-Show";
//        Draw::panel(w, cx, cy, cw, 500.f, title2, a.font);
//        Draw::text(w, a.font, "Today's pending appointments:", cx + 12.f, cy + 48.f, 13, C::TEXT_L);
//        const char* cols[] = { "Apt ID","Patient","Time" };
//        float colW[] = { 80.f,340.f,140.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 66.f, cw - 24.f, cols, colW, 3);
//        list.setup(cx + 12.f, cy + 92.f, cw - 24.f, 260.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            if (doc) for (int i = 0; i < h.appointments.size(); i++) {
//                auto& apt = h.appointments.getAll()[i];
//                if (apt.getDoctorID() != doc->getID()) continue;
//                if (compareStrings(apt.getDate(), todayDate) != 0) continue;
//                if (compareStrings(apt.getStatus(), "pending") != 0) continue;
//                Patient* p = h.findPatientByID(apt.getPatientID());
//                char row[512];
//                snprintf(row, sizeof(row), "%-8d  %-38s  %s",
//                    apt.getID(), p ? p->getName() : "Unknown", apt.getTimeSlot());
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No pending appointments today.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        Draw::text(w, a.font, "Appointment ID:", cx + 12.f, cy + 366.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                                // ---- Doctor: Write Prescription ----
//    case Screen::DOC_WRITE_PRESCRIPTION: {
//        Draw::panel(w, cx, cy, cw, 500.f, "Write Prescription", a.font);
//        Draw::text(w, a.font, "Appointment ID:", cx + 12.f, cy + 48.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        Draw::text(w, a.font, "Medicines (Name Dosage;Name Dosage):", cx + 12.f, cy + 114.f, 12, C::TEXT_L);
//        fields[1].draw(w, a.font);
//        Draw::text(w, a.font, "Notes:", cx + 12.f, cy + 180.f, 12, C::TEXT_L);
//        fields[2].draw(w, a.font);
//
//        Draw::rect(w, cx + 12.f, cy + 250.f, cw - 24.f, 60.f,
//            sf::Color(18, 22, 34), C::BORDER, 1.f);
//        Draw::text(w, a.font, "Example: Paracetamol 500mg;Amoxicillin 250mg",
//            cx + 22.f, cy + 258.f, 12, C::TEXT_L);
//        Draw::text(w, a.font, "Appointment must be 'completed'. One prescription per appointment.",
//            cx + 22.f, cy + 278.f, 12, C::TEXT_L);
//
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                                       // ---- Doctor: Patient History ----
//    case Screen::DOC_PATIENT_HISTORY: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Patient Medical History", a.font);
//        Draw::text(w, a.font, "Patient ID:", cx + 12.f, cy + 48.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        btns[0].draw(w, a.font);
//        list.setup(cx + 12.f, cy + 144.f, cw - 24.f, 480.f);
//        list.draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                                    // ---- Admin: Add Doctor ----
//    case Screen::ADM_ADD_DOCTOR: {
//        Draw::panel(w, cx, cy, cw, 500.f, "Add New Doctor", a.font);
//        const char* labels[] = { "Full Name","Specialization","Contact (11 digits)",
//                                  "Consultation Fee (PKR)","Password (min 6 chars)" };
//        for (int i = 0; i < 5; i++) {
//            float fy = cy + 48.f + i * 70.f;
//            Draw::text(w, a.font, labels[i], cx + 12.f, fy, 12, C::TEXT_L);
//            fields[i].draw(w, a.font);
//        }
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                               // ---- Admin: Remove Doctor ----
//    case Screen::ADM_REMOVE_DOCTOR: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Remove Doctor", a.font);
//        const char* cols[] = { "ID","Name","Specialization","Fee (PKR)" };
//        float colW[] = { 60.f,240.f,240.f,130.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 46.f, cw - 24.f, cols, colW, 4);
//        list.setup(cx + 12.f, cy + 72.f, cw - 24.f, 380.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            for (int i = 0; i < h.doctors.size(); i++) {
//                auto& d = h.doctors.getAll()[i];
//                char bBuf[24]; convertDoubleToString(d.getFee(), bBuf);
//                char row[512];
//                snprintf(row, sizeof(row), "%-6d  %-30s  %-30s  PKR %s",
//                    d.getID(), d.getName(), d.getSpecialization(), bBuf);
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No doctors registered.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        Draw::text(w, a.font, "Doctor ID to remove:", cx + 12.f, cy + 466.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        Draw::rect(w, cx + 12.f, cy + 534.f, cw - 24.f, 28.f,
//            sf::Color(40, 15, 15), C::DANGER, 1.f);
//        Draw::text(w, a.font, "Warning: Removes the doctor and all their appointments.",
//            cx + 18.f, cy + 542.f, 12, C::DANGER);
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                                  // ---- Admin: Generic list screens ----
//    case Screen::ADM_VIEW_PATIENTS:
//    case Screen::ADM_VIEW_DOCTORS:
//    case Screen::ADM_VIEW_APPOINTMENTS:
//    case Screen::ADM_VIEW_UNPAID_BILLS: {
//        const char* title2 =
//            gs.currentScreen == Screen::ADM_VIEW_PATIENTS ? "All Patients" :
//            gs.currentScreen == Screen::ADM_VIEW_DOCTORS ? "All Doctors" :
//            gs.currentScreen == Screen::ADM_VIEW_APPOINTMENTS ? "All Appointments" : "Unpaid Bills";
//        Draw::panel(w, cx, cy, cw, 656.f, title2, a.font);
//        list.setup(cx + 12.f, cy + 46.f, cw - 24.f, 580.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            if (gs.currentScreen == Screen::ADM_VIEW_PATIENTS) {
//                for (int i = 0; i < h.patients.size(); i++) {
//                    auto& p = h.patients.getAll()[i];
//                    char bBuf[24]; convertDoubleToString(p.getBalance(), bBuf);
//                    char row[512];
//                    snprintf(row, sizeof(row), "ID:%-4d  %-26s  Age:%-3d  %-2s  %-13s  PKR %s",
//                        p.getID(), p.getName(), p.getAge(), p.getGender(), p.getContact(), bBuf);
//                    list.addRow(row);
//                }
//            }
//            else if (gs.currentScreen == Screen::ADM_VIEW_DOCTORS) {
//                for (int i = 0; i < h.doctors.size(); i++) {
//                    auto& d = h.doctors.getAll()[i];
//                    char bBuf[24]; convertDoubleToString(d.getFee(), bBuf);
//                    char row[512];
//                    snprintf(row, sizeof(row), "ID:%-4d  %-26s  %-26s  PKR %s",
//                        d.getID(), d.getName(), d.getSpecialization(), bBuf);
//                    list.addRow(row);
//                }
//            }
//            else if (gs.currentScreen == Screen::ADM_VIEW_APPOINTMENTS) {
//                for (int i = 0; i < h.appointments.size(); i++) {
//                    auto& apt = h.appointments.getAll()[i];
//                    Patient* p = h.findPatientByID(apt.getPatientID());
//                    Doctor* d = h.findDoctorByID(apt.getDoctorID());
//                    char row[512];
//                    snprintf(row, sizeof(row), "ID:%-4d  %-14s  %-8s  Pat:%-20s  Dr:%-22s  %s",
//                        apt.getID(), apt.getDate(), apt.getTimeSlot(),
//                        p ? p->getName() : "N/A", d ? d->getName() : "N/A", apt.getStatus());
//                    list.addRow(row);
//                }
//            }
//            else {
//                for (int i = 0; i < h.bills.size(); i++) {
//                    auto& b = h.bills.getAll()[i];
//                    if (compareStrings(b.getStatus(), "unpaid") != 0) continue;
//                    Patient* p = h.findPatientByID(b.getPatientID());
//                    char bBuf[24]; convertDoubleToString(b.getAmount(), bBuf);
//                    char row[512];
//                    snprintf(row, sizeof(row), "BillID:%-4d  AptID:%-4d  Pat:%-22s  PKR %-12s  %s",
//                        b.getID(), b.getAppointmentID(),
//                        p ? p->getName() : "N/A", bBuf, b.getDate());
//                    list.addRow(row);
//                }
//            }
//            if (list.rowCount == 0) list.addRow("  No records found.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        break;
//    }
//
//                                      // ---- Admin: Discharge Patient ----
//    case Screen::ADM_DISCHARGE_PATIENT: {
//        Draw::panel(w, cx, cy, cw, 400.f, "Discharge Patient", a.font);
//        Draw::text(w, a.font, "Patient ID:", cx + 12.f, cy + 48.f, 12, C::TEXT_L);
//        fields[0].draw(w, a.font);
//        Draw::rect(w, cx + 12.f, cy + 120.f, cw - 24.f, 90.f,
//            sf::Color(40, 15, 15), C::DANGER, 1.f);
//        Draw::text(w, a.font, "Discharge Requirements:", cx + 18.f, cy + 130.f, 13, C::DANGER);
//        Draw::text(w, a.font, "- No unpaid bills", cx + 18.f, cy + 152.f, 12, C::TEXT_L);
//        Draw::text(w, a.font, "- No pending appointments", cx + 18.f, cy + 170.f, 12, C::TEXT_L);
//        Draw::text(w, a.font, "- Record archived to discharged.txt", cx + 18.f, cy + 188.f, 12, C::TEXT_L);
//        btns[0].draw(w, a.font);
//        btns[1].draw(w, a.font);
//        break;
//    }
//
//                                      // ---- Admin: Security Log ----
//    case Screen::ADM_SECURITY_LOG: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Security Log", a.font);
//        list.setup(cx + 12.f, cy + 46.f, cw - 24.f, 580.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            char logLine[512];
//            FILE* logFile = fopen("security_log.txt", "r");
//            if (logFile) {
//                while (fgets(logLine, sizeof(logLine), logFile)) {
//                    int len = (int)strlen(logLine);
//                    while (len > 0 && (logLine[len - 1] == '\n' || logLine[len - 1] == '\r'))
//                        logLine[--len] = '\0';
//                    list.addRow(logLine);
//                }
//                fclose(logFile);
//            }
//            if (list.rowCount == 0) list.addRow("  Security log is empty.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        break;
//    }
//
//                                 // ---- Admin: Daily Report ----
//    case Screen::ADM_DAILY_REPORT: {
//        Draw::panel(w, cx, cy, cw, 656.f, "Daily Report", a.font);
//        char rTitle[64]; snprintf(rTitle, sizeof(rTitle), "Date: %s", h.systemDate);
//        Draw::text(w, a.font, rTitle, cx + 16.f, cy + 46.f, 13, C::TEXT_L);
//
//        int totalApt = 0, pending = 0, completed = 0, noshow = 0, cancelled = 0;
//        double revenue = 0.0;
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (compareStrings(apt.getDate(), todayDate) != 0) continue;
//            totalApt++;
//            if (compareStrings(apt.getStatus(), "pending") == 0) pending++;
//            else if (compareStrings(apt.getStatus(), "completed") == 0) completed++;
//            else if (compareStrings(apt.getStatus(), "noshow") == 0) noshow++;
//            else if (compareStrings(apt.getStatus(), "cancelled") == 0) cancelled++;
//        }
//        for (int i = 0; i < h.bills.size(); i++) {
//            auto& b = h.bills.getAll()[i];
//            if (compareStrings(b.getStatus(), "paid") == 0 &&
//                compareStrings(b.getDate(), todayDate) == 0) revenue += b.getAmount();
//        }
//
//        char s1[16], s2[16], s3[16], s4[16];
//        convertIntToString(totalApt, s1); convertIntToString(completed, s2);
//        convertIntToString(pending, s3);  convertIntToString(noshow, s4);
//
//        float cardW2 = (cw - 30.f) / 4.f;
//        float cardY = cy + 66.f;
//        Draw::statCard(w, a.font, cx + 8.f, cardY, cardW2, 72.f, "Total Today", s1, C::ACCENT);
//        Draw::statCard(w, a.font, cx + 8.f + cardW2, cardY, cardW2, 72.f, "Completed", s2, C::SUCCESS);
//        Draw::statCard(w, a.font, cx + 8.f + cardW2 * 2, cardY, cardW2, 72.f, "Pending", s3, C::WARNING);
//        Draw::statCard(w, a.font, cx + 8.f + cardW2 * 3, cardY, cardW2, 72.f, "No-show", s4, C::DANGER);
//
//        char revBuf[32]; convertDoubleToString(revenue, revBuf);
//        char revLine[128]; snprintf(revLine, sizeof(revLine), "Revenue Collected Today: PKR %s", revBuf);
//        Draw::text(w, a.font, revLine, cx + 16.f, cy + 148.f, 15, C::SUCCESS);
//
//        Draw::text(w, a.font, "Doctor Summary", cx + 16.f, cy + 178.f, 14, C::TEXT);
//        const char* cols[] = { "Doctor","Completed","Pending","No-show" };
//        float colW[] = { 260.f,130.f,130.f,130.f };
//        Draw::tableHeader(w, a.font, cx + 12.f, cy + 198.f, cw - 24.f, cols, colW, 4);
//        list.setup(cx + 12.f, cy + 224.f, cw - 24.f, 400.f);
//        if (gs.needsRefresh) {
//            list.clear();
//            for (int i = 0; i < h.doctors.size(); i++) {
//                auto& d = h.doctors.getAll()[i];
//                int dc = 0, dp = 0, dn = 0;
//                for (int j = 0; j < h.appointments.size(); j++) {
//                    auto& apt = h.appointments.getAll()[j];
//                    if (apt.getDoctorID() != d.getID() ||
//                        compareStrings(apt.getDate(), todayDate) != 0) continue;
//                    if (compareStrings(apt.getStatus(), "completed") == 0) dc++;
//                    else if (compareStrings(apt.getStatus(), "pending") == 0) dp++;
//                    else if (compareStrings(apt.getStatus(), "noshow") == 0) dn++;
//                }
//                if (dc + dp + dn == 0) continue;
//                char row[512];
//                snprintf(row, sizeof(row), "%-32s  %-16d  %-16d  %d", d.getName(), dc, dp, dn);
//                list.addRow(row);
//            }
//            if (list.rowCount == 0) list.addRow("  No doctor activity today.");
//            gs.needsRefresh = false;
//        }
//        list.draw(w, a.font);
//        btns[0].draw(w, a.font);
//        break;
//    }
//
//    default: break;
//    }
//}
//
//// ---- Widget setup for sub-screens ----
//void setupSubScreenWidgets(Screen s, Button btns[], InputField fields[],
//    float cx, float cy, float cw) {
//    for (int i = 0; i < 8; i++) btns[i].box.setSize({ 0.f, 0.f });
//
//    float bw = 140.f, bh = 36.f;
//    float backX = cx + cw - 150.f;
//
//    auto mkBtn = [&](int i, float x, float y, const char* lbl,
//        bool danger = false, bool sec = false) {
//            btns[i].setup(x, y, bw, bh, lbl, danger, sec);
//        };
//    auto mkField = [&](int i, float x, float y, const char* ph, bool pw = false) {
//        fields[i].setup(x, y, 300.f, 36.f, ph);
//        fields[i].password = pw;
//        fields[i].clear();
//        };
//
//    switch (s) {
//    case Screen::PAT_BOOK_APPOINTMENT:
//        mkField(0, cx + 12.f, cy + 318.f, "Doctor ID");
//        mkField(1, cx + 12.f, cy + 382.f, "DD-MM-YYYY");
//        mkField(2, cx + 12.f, cy + 446.f, "HH:MM");
//        mkBtn(0, cx + 12.f, cy + 500.f, "Book Appointment");
//        mkBtn(1, backX, cy + 500.f, "Back", false, true);
//        break;
//    case Screen::PAT_VIEW_APPOINTMENTS:
//        mkBtn(0, cx + 12.f, cy + 620.f, "Cancel Selected", true);
//        mkBtn(1, backX, cy + 620.f, "Back", false, true);
//        break;
//    case Screen::PAT_VIEW_BILLS:
//        mkBtn(0, cx + 12.f, cy + 600.f, "Pay Selected Bill");
//        mkBtn(1, backX, cy + 600.f, "Back", false, true);
//        break;
//    case Screen::PAT_TOP_UP: {
//        float px2 = 640.f - 200.f;
//        mkField(0, px2 + 16.f, 310.f, "Amount in PKR");
//        mkBtn(0, px2 + 16.f, 362.f, "Add Funds");
//        mkBtn(1, px2 + 16.f + 150.f, 362.f, "Cancel", false, true);
//        break;
//    }
//    case Screen::PAT_VIEW_PRESCRIPTIONS:
//    case Screen::DOC_TODAY_APPOINTMENTS:
//    case Screen::ADM_VIEW_PATIENTS:
//    case Screen::ADM_VIEW_DOCTORS:
//    case Screen::ADM_VIEW_APPOINTMENTS:
//    case Screen::ADM_VIEW_UNPAID_BILLS:
//    case Screen::ADM_SECURITY_LOG:
//    case Screen::ADM_DAILY_REPORT:
//        mkBtn(0, backX, cy + 624.f, "Back", false, true);
//        break;
//    case Screen::PAT_SEARCH_DOCTOR:
//        mkField(0, cx + 12.f, cy + 68.f, "Search by name or specialization...");
//        mkBtn(0, backX, cy + 624.f, "Back", false, true);
//        break;
//    case Screen::DOC_MARK_COMPLETE:
//    case Screen::DOC_MARK_NOSHOW:
//        mkField(0, cx + 12.f, cy + 384.f, "Appointment ID");
//        mkBtn(0, cx + 12.f, cy + 432.f, "Confirm");
//        mkBtn(1, backX, cy + 432.f, "Back", false, true);
//        break;
//    case Screen::DOC_WRITE_PRESCRIPTION:
//        mkField(0, cx + 12.f, cy + 66.f, "Appointment ID");
//        mkField(1, cx + 12.f, cy + 132.f, "Paracetamol 500mg;Amoxicillin 250mg");
//        mkField(2, cx + 12.f, cy + 198.f, "Doctor notes...");
//        mkBtn(0, cx + 12.f, cy + 330.f, "Save Prescription");
//        mkBtn(1, backX, cy + 330.f, "Back", false, true);
//        break;
//    case Screen::DOC_PATIENT_HISTORY:
//        mkField(0, cx + 12.f, cy + 66.f, "Patient ID");
//        mkBtn(0, cx + 12.f, cy + 114.f, "View History");
//        mkBtn(1, backX, cy + 114.f, "Back", false, true);
//        break;
//    case Screen::ADM_ADD_DOCTOR:
//        for (int i = 0; i < 5; i++) {
//            mkField(i, cx + 12.f, cy + 66.f + i * 70.f,
//                i == 0 ? "Full Name" : i == 1 ? "Specialization" :
//                i == 2 ? "Contact (11 digits)" : i == 3 ? "Fee (e.g. 500)" : "Password",
//                i == 4);
//        }
//        mkBtn(0, cx + 12.f, cy + 430.f, "Add Doctor");
//        mkBtn(1, backX, cy + 430.f, "Back", false, true);
//        break;
//    case Screen::ADM_REMOVE_DOCTOR:
//        mkField(0, cx + 12.f, cy + 484.f, "Doctor ID");
//        mkBtn(0, cx + 12.f, cy + 572.f, "Remove Doctor", true);
//        mkBtn(1, backX, cy + 572.f, "Back", false, true);
//        break;
//    case Screen::ADM_DISCHARGE_PATIENT:
//        mkField(0, cx + 12.f, cy + 66.f, "Patient ID");
//        mkBtn(0, cx + 12.f, cy + 230.f, "Discharge", true);
//        mkBtn(1, backX, cy + 230.f, "Back", false, true);
//        break;
//    default: break;
//    }
//}
//
//// ---- Action handlers (unchanged logic) ----
//void handleSubScreenAction(Screen s, GUIState& gs, Hospital& h,
//    Button btns[], InputField fields[],
//    ScrollList& list) {
//    Patient* pat = h.findPatientByID(gs.loggedInID);
//    Doctor* doc = h.findDoctorByID(gs.loggedInID);
//    char todayDate[16]; getTodayDateString(todayDate, h.systemDate);
//
//    switch (s) {
//    case Screen::PAT_BOOK_APPOINTMENT: {
//        int docID = convertStringToInt(fields[0].buffer);
//        const char* dateStr = fields[1].buffer;
//        const char* slotStr = fields[2].buffer;
//        Doctor* d = h.findDoctorByID(docID);
//        if (!d) { setStatus(gs, "Invalid doctor ID.", true); return; }
//        if (!Validator::isValidDate(dateStr, h.systemDate)) { setStatus(gs, "Invalid date (DD-MM-YYYY, not in past).", true); return; }
//        if (!Validator::isValidTimeSlot(slotStr)) { setStatus(gs, "Invalid slot. Use 09:00-16:00.", true); return; }
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (apt.getDoctorID() == docID &&
//                compareStrings(apt.getDate(), dateStr) == 0 &&
//                compareStrings(apt.getTimeSlot(), slotStr) == 0 &&
//                compareStrings(apt.getStatus(), "pending") == 0) {
//                setStatus(gs, "Slot unavailable. Choose another.", true); return;
//            }
//        }
//        if (!pat) { setStatus(gs, "Patient not found.", true); return; }
//        if (pat->getBalance() < d->getFee()) { setStatus(gs, "Insufficient balance. Please top up.", true); return; }
//        Appointment newApt;
//        int newID = h.generateNextAppointmentID();
//        newApt.setID(newID); newApt.setPatientID(pat->getID());
//        newApt.setDoctorID(docID); newApt.setDate(dateStr);
//        newApt.setTimeSlot(slotStr); newApt.setStatus("pending");
//        h.appointments.addRecord(newApt);
//        FileHandler::appendAppointmentRecord(newApt, "appointments.txt");
//        *pat -= d->getFee();
//        FileHandler::writeAllPatientsToFile(h.patients, "patients.txt");
//        Bill bill; int billID = h.generateNextBillID();
//        bill.setID(billID); bill.setPatientID(pat->getID());
//        bill.setAppointmentID(newID); bill.setAmount(d->getFee());
//        bill.setStatus("unpaid"); bill.setDate(dateStr);
//        h.bills.addRecord(bill);
//        FileHandler::appendBillRecord(bill, "bills.txt");
//        setStatus(gs, "Appointment booked successfully!");
//        for (int i = 0; i < 3; i++) fields[i].clear();
//        gs.needsRefresh = true;
//        break;
//    }
//    case Screen::PAT_VIEW_APPOINTMENTS: {
//        const char* sel = list.getSelected();
//        if (!sel) { setStatus(gs, "Select an appointment first.", true); return; }
//        int aptID = convertStringToInt(sel);
//        Appointment* apt = h.appointments.findByID(aptID);
//        if (!apt || apt->getPatientID() != pat->getID() ||
//            compareStrings(apt->getStatus(), "pending") != 0) {
//            setStatus(gs, "Cannot cancel - not a pending appointment.", true); return;
//        }
//        double refundAmount = 0.0;
//        for (int i = 0; i < h.bills.size(); i++) {
//            Bill& b2 = h.bills.getAll()[i];
//            if (b2.getAppointmentID() == aptID &&
//                (compareStrings(b2.getStatus(), "unpaid") == 0 ||
//                    compareStrings(b2.getStatus(), "paid") == 0)) {
//                refundAmount = b2.getAmount(); break;
//            }
//        }
//        if (refundAmount > 0.0) *pat += refundAmount;
//        apt->setStatus("cancelled");
//        for (int i = 0; i < h.bills.size(); i++)
//            if (h.bills.getAll()[i].getAppointmentID() == aptID)
//                h.bills.getAll()[i].setStatus("cancelled");
//        FileHandler::writeAllAppointmentsToFile(h.appointments, "appointments.txt");
//        FileHandler::writeAllBillsToFile(h.bills, "bills.txt");
//        if (refundAmount > 0.0) FileHandler::writeAllPatientsToFile(h.patients, "patients.txt");
//        char cancelMsg[80];
//        if (refundAmount > 0.0) {
//            char rBuf[24]; convertDoubleToString(refundAmount, rBuf);
//            snprintf(cancelMsg, sizeof(cancelMsg), "Appointment cancelled. PKR %s refunded.", rBuf);
//        }
//        else { snprintf(cancelMsg, sizeof(cancelMsg), "Appointment cancelled."); }
//        setStatus(gs, cancelMsg);
//        gs.needsRefresh = true;
//        break;
//    }
//    case Screen::PAT_VIEW_BILLS: {
//        const char* sel = list.getSelected();
//        if (!sel) { setStatus(gs, "Select a bill first.", true); return; }
//        int billID = convertStringToInt(sel);
//        Bill* b = h.bills.findByID(billID);
//        if (!b || b->getPatientID() != pat->getID() ||
//            compareStrings(b->getStatus(), "unpaid") != 0) {
//            setStatus(gs, "Invalid or already paid bill.", true); return;
//        }
//        if (pat->getBalance() < b->getAmount()) { setStatus(gs, "Insufficient balance. Please top up.", true); return; }
//        *pat -= b->getAmount();
//        b->setStatus("paid");
//        FileHandler::writeAllBillsToFile(h.bills, "bills.txt");
//        FileHandler::writeAllPatientsToFile(h.patients, "patients.txt");
//        setStatus(gs, "Bill paid successfully!");
//        gs.needsRefresh = true;
//        break;
//    }
//    case Screen::PAT_TOP_UP: {
//        if (!Validator::isValidPositiveAmount(fields[0].buffer)) { setStatus(gs, "Enter a valid positive amount.", true); return; }
//        double amount = convertStringToDouble(fields[0].buffer);
//        if (!pat) { setStatus(gs, "Patient not found.", true); return; }
//        *pat += amount;
//        FileHandler::writeAllPatientsToFile(h.patients, "patients.txt");
//        char msg[128]; char aBuf[24]; convertDoubleToString(amount, aBuf);
//        snprintf(msg, sizeof(msg), "Added PKR %s to your balance.", aBuf);
//        setStatus(gs, msg);
//        fields[0].clear();
//        gs.needsRefresh = true;
//        break;
//    }
//    case Screen::DOC_MARK_COMPLETE: {
//        int aptID = convertStringToInt(fields[0].buffer);
//        Appointment* apt = h.appointments.findByID(aptID);
//        if (!apt || apt->getDoctorID() != doc->getID() ||
//            compareStrings(apt->getStatus(), "pending") != 0 ||
//            compareStrings(apt->getDate(), todayDate) != 0) {
//            setStatus(gs, "Invalid appointment ID.", true); return;
//        }
//        apt->setStatus("completed");
//        FileHandler::writeAllAppointmentsToFile(h.appointments, "appointments.txt");
//        setStatus(gs, "Appointment marked as completed.");
//        fields[0].clear(); gs.needsRefresh = true;
//        break;
//    }
//    case Screen::DOC_MARK_NOSHOW: {
//        int aptID = convertStringToInt(fields[0].buffer);
//        Appointment* apt = h.appointments.findByID(aptID);
//        if (!apt || apt->getDoctorID() != doc->getID() ||
//            compareStrings(apt->getStatus(), "pending") != 0 ||
//            compareStrings(apt->getDate(), todayDate) != 0) {
//            setStatus(gs, "Invalid appointment ID.", true); return;
//        }
//        apt->setStatus("noshow");
//        for (int i = 0; i < h.bills.size(); i++)
//            if (h.bills.getAll()[i].getAppointmentID() == aptID)
//                h.bills.getAll()[i].setStatus("cancelled");
//        FileHandler::writeAllAppointmentsToFile(h.appointments, "appointments.txt");
//        FileHandler::writeAllBillsToFile(h.bills, "bills.txt");
//        setStatus(gs, "Appointment marked as no-show.");
//        fields[0].clear(); gs.needsRefresh = true;
//        break;
//    }
//    case Screen::DOC_WRITE_PRESCRIPTION: {
//        int aptID = convertStringToInt(fields[0].buffer);
//        Appointment* apt = h.appointments.findByID(aptID);
//        if (!apt || apt->getDoctorID() != doc->getID() ||
//            compareStrings(apt->getStatus(), "completed") != 0) {
//            setStatus(gs, "Appointment must be completed.", true); return;
//        }
//        for (int i = 0; i < h.prescriptions.size(); i++)
//            if (h.prescriptions.getAll()[i].getAppointmentID() == aptID) {
//                setStatus(gs, "Prescription already exists.", true); return;
//            }
//        if (strlen(fields[1].buffer) == 0) { setStatus(gs, "Enter medicines.", true); return; }
//        Prescription rx;
//        rx.setID(h.generateNextPrescriptionID());
//        rx.setAppointmentID(aptID);
//        rx.setPatientID(apt->getPatientID());
//        rx.setDoctorID(doc->getID());
//        rx.setDate(apt->getDate());
//        rx.setMedicines(fields[1].buffer);
//        rx.setNotes(fields[2].buffer);
//        h.prescriptions.addRecord(rx);
//        FileHandler::appendPrescriptionRecord(rx, "prescriptions.txt");
//        setStatus(gs, "Prescription saved.");
//        for (int i = 0; i < 3; i++) fields[i].clear();
//        break;
//    }
//    case Screen::DOC_PATIENT_HISTORY: {
//        int pID = convertStringToInt(fields[0].buffer);
//        Patient* p = h.findPatientByID(pID);
//        if (!p) { setStatus(gs, "Patient not found.", true); return; }
//        bool hasCompleted = false;
//        for (int i = 0; i < h.appointments.size(); i++) {
//            auto& apt = h.appointments.getAll()[i];
//            if (apt.getPatientID() == pID && apt.getDoctorID() == doc->getID() &&
//                compareStrings(apt.getStatus(), "completed") == 0) {
//                hasCompleted = true; break;
//            }
//        }
//        if (!hasCompleted) { setStatus(gs, "Access denied. No completed appointments with this patient.", true); return; }
//        list.clear();
//        for (int i = 0; i < h.prescriptions.size(); i++) {
//            auto& rx = h.prescriptions.getAll()[i];
//            if (rx.getPatientID() != pID || rx.getDoctorID() != doc->getID()) continue;
//            char row[512];
//            snprintf(row, sizeof(row), "%-12s  %-42s  %s",
//                rx.getDate(), rx.getMedicines(), rx.getNotes());
//            list.addRow(row);
//        }
//        if (list.rowCount == 0) list.addRow("  No prescriptions found.");
//        break;
//    }
//    case Screen::ADM_ADD_DOCTOR: {
//        if (strlen(fields[0].buffer) == 0) { setStatus(gs, "Name is required.", true); return; }
//        if (!Validator::isValidContactNumber(fields[2].buffer)) { setStatus(gs, "Contact must be 11 digits.", true); return; }
//        if (!Validator::isValidPassword(fields[4].buffer)) { setStatus(gs, "Password min 6 chars.", true); return; }
//        if (!Validator::isValidPositiveAmount(fields[3].buffer)) { setStatus(gs, "Enter valid fee.", true); return; }
//        Doctor newDoc;
//        newDoc.setID(h.generateNextDoctorID());
//        newDoc.setName(fields[0].buffer);
//        newDoc.setSpecialization(fields[1].buffer);
//        newDoc.setContact(fields[2].buffer);
//        newDoc.setFee(convertStringToDouble(fields[3].buffer));
//        newDoc.setPassword(fields[4].buffer);
//        h.doctors.addRecord(newDoc);
//        FileHandler::appendDoctorRecord(newDoc, "doctors.txt");
//        setStatus(gs, "Doctor added successfully.");
//        for (int i = 0; i < 5; i++) fields[i].clear();
//        gs.needsRefresh = true;
//        break;
//    }
//    case Screen::ADM_REMOVE_DOCTOR: {
//        int dID = convertStringToInt(fields[0].buffer);
//        Doctor* d = h.findDoctorByID(dID);
//        if (!d) { setStatus(gs, "Doctor not found.", true); return; }
//        h.doctors.removeByID(dID);
//        bool rem = true;
//        while (rem) {
//            rem = false;
//            for (int i = 0; i < h.appointments.size(); i++)
//                if (h.appointments.getAll()[i].getDoctorID() == dID) {
//                    h.appointments.removeByID(h.appointments.getAll()[i].getID());
//                    rem = true; break;
//                }
//        }
//        FileHandler::writeAllDoctorsToFile(h.doctors, "doctors.txt");
//        FileHandler::writeAllAppointmentsToFile(h.appointments, "appointments.txt");
//        setStatus(gs, "Doctor removed.");
//        fields[0].clear(); gs.needsRefresh = true;
//        break;
//    }
//    case Screen::ADM_DISCHARGE_PATIENT: {
//        int pID = convertStringToInt(fields[0].buffer);
//        Patient* p = h.findPatientByID(pID);
//        if (!p) { setStatus(gs, "Patient not found.", true); return; }
//        if (h.countUnpaidBillsForPatient(pID) > 0) { setStatus(gs, "Cannot discharge: unpaid bills.", true); return; }
//        if (h.countPendingAppointmentsForPatient(pID) > 0) { setStatus(gs, "Cannot discharge: pending appointments.", true); return; }
//        FileHandler::archiveDischargedPatient(*p, h.appointments, h.bills, h.prescriptions);
//        h.patients.removeByID(pID);
//        bool rem = true;
//        while (rem) {
//            rem = false;
//            for (int i = 0; i < h.appointments.size(); i++)
//                if (h.appointments.getAll()[i].getPatientID() == pID) {
//                    h.appointments.removeByID(h.appointments.getAll()[i].getID());
//                    rem = true; break;
//                }
//        }
//        FileHandler::writeAllPatientsToFile(h.patients, "patients.txt");
//        FileHandler::writeAllAppointmentsToFile(h.appointments, "appointments.txt");
//        FileHandler::writeAllBillsToFile(h.bills, "bills.txt");
//        FileHandler::writeAllPrescriptionsToFile(h.prescriptions, "prescriptions.txt");
//        setStatus(gs, "Patient discharged and archived.");
//        fields[0].clear(); gs.needsRefresh = true;
//        break;
//    }
//    default: break;
//    }
//}
//
//// ============================================================
//// MAIN
//// ============================================================
//int main() {
//    sf::RenderWindow window(sf::VideoMode(1280, 720),
//        "MediCore Hospital Management System",
//        sf::Style::Default);
//    window.setFramerateLimit(60);
//
//    sf::SoundBuffer buffer;
//    buffer.loadFromFile("BackgroundMusic.wav");
//
//    sf::Sound sound;
//    sound.setBuffer(buffer);
//    sound.setLoop(true); // <--- Makes the sound loop infinitely
//    sound.play();
//
//    // Fixed-ratio view so the 1280x720 coordinate system scales to any window size
//    sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));
//    auto applyLetterbox = [&]() {
//        float winW = (float)window.getSize().x;
//        float winH = (float)window.getSize().y;
//        float targetRatio = 1280.f / 720.f;
//        float windowRatio = winW / winH;
//        float vpW = 1.f, vpH = 1.f, vpX = 0.f, vpY = 0.f;
//        if (windowRatio > targetRatio) {
//            vpW = targetRatio / windowRatio;
//            vpX = (1.f - vpW) / 2.f;
//        }
//        else {
//            vpH = windowRatio / targetRatio;
//            vpY = (1.f - vpH) / 2.f;
//        }
//        view.setViewport(sf::FloatRect(vpX, vpY, vpW, vpH));
//        window.setView(view);
//        };
//    applyLetterbox();
//
//    Assets assets;
//    if (!assets.load()) {
//        // If no font found, still continue - SFML will use a built-in fallback
//    }
//
//    Hospital hospital;
//    initSystemDate(hospital);
//    loadAllDataFromFiles(hospital);
//
//    GUIState gs;
//
//    // Widgets
//    static Button     mainMenuBtns[4];
//    static Button     loginBtns[2];
//    static Button     registerBtns[2];
//    static Button     dashBtns[12];
//    static Button     subBtns[8];
//    static InputField loginFields[2];
//    static InputField registerFields[6];
//    static InputField subFields[6];
//    static ScrollList mainList;
//
//    InputField* focusedField = nullptr;
//
//    InputField* allLoginFlds[2] = { &loginFields[0], &loginFields[1] };
//    InputField* allRegFlds[6] = { &registerFields[0], &registerFields[1], &registerFields[2],
//                                     &registerFields[3], &registerFields[4], &registerFields[5] };
//    InputField* allSubFlds[6] = { &subFields[0], &subFields[1], &subFields[2],
//                                     &subFields[3], &subFields[4], &subFields[5] };
//
//    auto clearAllFocus = [&]() {
//        for (int i = 0; i < 2; i++) loginFields[i].focused = false;
//        for (int i = 0; i < 6; i++) registerFields[i].focused = false;
//        for (int i = 0; i < 6; i++) subFields[i].focused = false;
//        focusedField = nullptr;
//        };
//
//    auto validateFocus = [&]() {
//        if (!focusedField) return;
//        bool belongs = false;
//        if (gs.currentScreen == Screen::LOGIN_PATIENT ||
//            gs.currentScreen == Screen::LOGIN_DOCTOR ||
//            gs.currentScreen == Screen::LOGIN_ADMIN) {
//            for (int i = 0; i < 2; i++)
//                if (focusedField == &loginFields[i]) { belongs = true; break; }
//        }
//        else if (gs.currentScreen == Screen::REGISTER_PATIENT) {
//            for (int i = 0; i < 6; i++)
//                if (focusedField == &registerFields[i]) { belongs = true; break; }
//        }
//        else {
//            for (int i = 0; i < 6; i++)
//                if (focusedField == &subFields[i]) { belongs = true; break; }
//        }
//        if (!belongs) focusedField = nullptr;
//        };
//
//    // ---- Setup main menu buttons ----
//    {
//        float cx2 = (1280.f - 280.f) / 2.f, startY = 220.f;
//        const char* labels[] = { "Login as Patient", "Login as Doctor",
//                                  "Login as Admin",   "Register New Patient" };
//        for (int i = 0; i < 4; i++)
//            mainMenuBtns[i].setup(cx2, startY + i * 60.f, 280.f, 44.f,
//                labels[i], false, i == 3);
//    }
//
//    // ---- Login buttons (positioned relative to login panel py=160) ----
//    loginBtns[0].setup(1280.f / 2.f - 170.f, 160.f + 220.f, 130.f, 38.f, "Login");
//    loginBtns[1].setup(1280.f / 2.f + 10.f, 160.f + 220.f, 130.f, 38.f, "Back", false, true);
//
//    // ---- Register buttons (positioned relative to register panel py=80) ----
//    registerBtns[0].setup(340.f, 80.f + 440.f, 130.f, 38.f, "Register");
//    registerBtns[1].setup(490.f, 80.f + 440.f, 130.f, 38.f, "Back", false, true);
//
//    sf::Clock    clock;
//    sf::Vector2f mousePos;
//    bool         clickHappened = false;
//
//    // ============================================================
//    // MAIN LOOP
//    // ============================================================
//    while (window.isOpen()) {
//
//        float dt = clock.restart().asSeconds();
//        gs.globalTime += dt;
//        gs.toast.update(dt);
//        clickHappened = false;
//
//        sf::Event event;
//        while (window.pollEvent(event)) {
//
//
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::Resized) {
//                applyLetterbox();
//            }
//
//            if (event.type == sf::Event::MouseMoved) {
//                sf::Vector2i pixelPos(event.mouseMove.x, event.mouseMove.y);
//                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
//                mousePos = worldPos;
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased)
//                clickHappened = true;
//
//            if (event.type == sf::Event::MouseWheelScrolled)
//                mainList.handleScroll(event.mouseWheelScroll.delta);
//
//            // ---- Focus assignment ----
//            if (event.type == sf::Event::MouseButtonReleased &&
//                event.mouseButton.button == sf::Mouse::Left) {
//                sf::Vector2i pixelClick(event.mouseButton.x, event.mouseButton.y);
//                sf::Vector2f mp = window.mapPixelToCoords(pixelClick);
//                clearAllFocus();
//
//                if (gs.currentScreen == Screen::LOGIN_PATIENT ||
//                    gs.currentScreen == Screen::LOGIN_DOCTOR ||
//                    gs.currentScreen == Screen::LOGIN_ADMIN) {
//                    for (int i = 0; i < 2; i++) {
//                        if (loginFields[i].contains(mp)) {
//                            loginFields[i].focused = true;
//                            focusedField = &loginFields[i]; break;
//                        }
//                    }
//                }
//                else if (gs.currentScreen == Screen::REGISTER_PATIENT) {
//                    for (int i = 0; i < 6; i++) {
//                        if (registerFields[i].contains(mp)) {
//                            registerFields[i].focused = true;
//                            focusedField = &registerFields[i]; break;
//                        }
//                    }
//                }
//                else {
//                    for (int i = 0; i < 6; i++) {
//                        if (subFields[i].contains(mp)) {
//                            subFields[i].focused = true;
//                            focusedField = &subFields[i]; break;
//                        }
//                    }
//                }
//                mainList.handleClick(mp);
//            }
//
//            // ---- Tab cycling ----
//            if (event.type == sf::Event::KeyPressed &&
//                event.key.code == sf::Keyboard::Tab) {
//                InputField** flds = nullptr; int cnt = 0;
//                if (gs.currentScreen == Screen::LOGIN_PATIENT ||
//                    gs.currentScreen == Screen::LOGIN_DOCTOR ||
//                    gs.currentScreen == Screen::LOGIN_ADMIN)
//                {
//                    flds = allLoginFlds; cnt = 2;
//                }
//                else if (gs.currentScreen == Screen::REGISTER_PATIENT)
//                {
//                    flds = allRegFlds;  cnt = 6;
//                }
//                else
//                {
//                    flds = allSubFlds;  cnt = 6;
//                }
//
//                bool advanced = false;
//                for (int i = 0; i < cnt; i++) {
//                    if (flds[i]->focused) {
//                        flds[i]->focused = false;
//                        int next = (i + 1) % cnt;
//                        flds[next]->focused = true;
//                        focusedField = flds[next];
//                        advanced = true; break;
//                    }
//                }
//                if (!advanced && cnt > 0) {
//                    flds[0]->focused = true; focusedField = flds[0];
//                }
//            }
//
//            // ---- Enter to submit ----
//            if (event.type == sf::Event::KeyPressed &&
//                event.key.code == sf::Keyboard::Return) {
//                if (gs.currentScreen == Screen::LOGIN_PATIENT ||
//                    gs.currentScreen == Screen::LOGIN_DOCTOR ||
//                    gs.currentScreen == Screen::LOGIN_ADMIN) {
//                    mousePos = {
//                        loginBtns[0].box.getPosition().x + loginBtns[0].box.getSize().x / 2.f,
//                        loginBtns[0].box.getPosition().y + loginBtns[0].box.getSize().y / 2.f
//                    };
//                    clickHappened = true;
//                }
//                else if (gs.currentScreen == Screen::REGISTER_PATIENT) {
//                    mousePos = {
//                        registerBtns[0].box.getPosition().x + registerBtns[0].box.getSize().x / 2.f,
//                        registerBtns[0].box.getPosition().y + registerBtns[0].box.getSize().y / 2.f
//                    };
//                    clickHappened = true;
//                }
//            }
//
//            // ---- Text input ----
//            validateFocus();
//            if (focusedField) focusedField->handleEvent(event);
//
//            // Live search refresh
//            if (gs.currentScreen == Screen::PAT_SEARCH_DOCTOR &&
//                subFields[0].focused && event.type == sf::Event::TextEntered)
//                gs.needsRefresh = true;
//        }
//
//        // ---- Update hover ----
//        for (int i = 0; i < 4; i++) mainMenuBtns[i].update(mousePos);
//        loginBtns[0].update(mousePos); loginBtns[1].update(mousePos);
//        registerBtns[0].update(mousePos); registerBtns[1].update(mousePos);
//        for (int i = 0; i < 8; i++) subBtns[i].update(mousePos);
//        mainList.updateHover(mousePos);
//
//        // ---- Update input fields ----
//        for (int i = 0; i < 2; i++) loginFields[i].update(dt);
//        for (int i = 0; i < 6; i++) registerFields[i].update(dt);
//        for (int i = 0; i < 6; i++) subFields[i].update(dt);
//
//        // ============================================================
//        // CLICK HANDLING
//        // ============================================================
//        if (clickHappened) {
//            sf::Vector2f mp = mousePos;
//
//            // ---- Main Menu ----
//            if (gs.currentScreen == Screen::MAIN_MENU) {
//                if (mainMenuBtns[0].isClicked(mp)) {
//                    loginFields[0].setup(1280.f / 2.f - 170.f, 160.f + 68.f, 340.f, 38.f, "Enter Patient ID");
//                    loginFields[1].setup(1280.f / 2.f - 170.f, 160.f + 134.f, 340.f, 38.f, "Enter Password");
//                    loginFields[0].clear(); loginFields[1].clear();
//                    loginFields[0].password = false; loginFields[1].password = true;
//                    clearAllFocus(); gs.loginAttempts = 0;
//                    gs.goTo(Screen::LOGIN_PATIENT);
//                }
//                if (mainMenuBtns[1].isClicked(mp)) {
//                    loginFields[0].setup(1280.f / 2.f - 170.f, 160.f + 68.f, 340.f, 38.f, "Enter Doctor ID");
//                    loginFields[1].setup(1280.f / 2.f - 170.f, 160.f + 134.f, 340.f, 38.f, "Enter Password");
//                    loginFields[0].clear(); loginFields[1].clear();
//                    loginFields[0].password = false; loginFields[1].password = true;
//                    clearAllFocus(); gs.loginAttempts = 0;
//                    gs.goTo(Screen::LOGIN_DOCTOR);
//                }
//                if (mainMenuBtns[2].isClicked(mp)) {
//                    loginFields[0].setup(1280.f / 2.f - 170.f, 160.f + 68.f, 340.f, 38.f, "Enter Admin ID");
//                    loginFields[1].setup(1280.f / 2.f - 170.f, 160.f + 134.f, 340.f, 38.f, "Enter Password");
//                    loginFields[0].clear(); loginFields[1].clear();
//                    loginFields[0].password = false; loginFields[1].password = true;
//                    clearAllFocus(); gs.loginAttempts = 0;
//                    gs.goTo(Screen::LOGIN_ADMIN);
//                }
//                if (mainMenuBtns[3].isClicked(mp)) {
//                    float px2 = (1280.f - 680.f) / 2.f, py2 = 80.f;
//                    for (int i = 0; i < 6; i++) {
//                        registerFields[i].setup(px2 + 20.f, py2 + 66.f + i * 64.f, 300.f, 36.f,
//                            i == 0 ? "Full Name" :
//                            i == 1 ? "Age (1-149)" :
//                            i == 2 ? "Gender (M/F)" :
//                            i == 3 ? "Contact (11 digits)" :
//                            i == 4 ? "Password (min 6 chars)" : "Confirm Password");
//                        registerFields[i].password = (i == 4 || i == 5);
//                        registerFields[i].clear();
//                    }
//                    clearAllFocus();
//                    gs.goTo(Screen::REGISTER_PATIENT);
//                }
//            }
//
//            // ---- Login ----
//            else if (gs.currentScreen == Screen::LOGIN_PATIENT ||
//                gs.currentScreen == Screen::LOGIN_DOCTOR ||
//                gs.currentScreen == Screen::LOGIN_ADMIN) {
//                if (loginBtns[1].isClicked(mp)) { clearAllFocus(); gs.goTo(Screen::MAIN_MENU); }
//                if (loginBtns[0].isClicked(mp)) {
//                    int id = convertStringToInt(loginFields[0].buffer);
//                    const char* pass = loginFields[1].buffer;
//
//                    if (gs.currentScreen == Screen::LOGIN_PATIENT) {
//                        Patient* p = hospital.findPatientByID(id);
//                        if (p && compareStrings(p->getPassword(), pass) == 0) {
//                            gs.loggedInID = id;
//                            strncpy(gs.loggedInName, p->getName(), 255);
//                            strncpy(gs.loggedInRole, "Patient", 31);
//                            writeSecurityLogEntry(hospital, "Patient", loginFields[0].buffer, "SUCCESS");
//                            clearAllFocus(); gs.needsRefresh = true;
//                            gs.goTo(Screen::PATIENT_DASHBOARD);
//                        }
//                        else {
//                            gs.loginAttempts++;
//                            writeSecurityLogEntry(hospital, "Patient", loginFields[0].buffer, "FAILED");
//                            char msg[64];
//                            snprintf(msg, sizeof(msg), "Invalid credentials. Attempt %d/3", gs.loginAttempts);
//                            setStatus(gs, msg, true);
//                        }
//                    }
//                    else if (gs.currentScreen == Screen::LOGIN_DOCTOR) {
//                        Doctor* d = hospital.findDoctorByID(id);
//                        if (d && compareStrings(d->getPassword(), pass) == 0) {
//                            gs.loggedInID = id;
//                            strncpy(gs.loggedInName, d->getName(), 255);
//                            strncpy(gs.loggedInRole, "Doctor", 31);
//                            writeSecurityLogEntry(hospital, "Doctor", loginFields[0].buffer, "SUCCESS");
//                            clearAllFocus(); gs.needsRefresh = true;
//                            gs.goTo(Screen::DOCTOR_DASHBOARD);
//                        }
//                        else {
//                            gs.loginAttempts++;
//                            writeSecurityLogEntry(hospital, "Doctor", loginFields[0].buffer, "FAILED");
//                            char msg[64];
//                            snprintf(msg, sizeof(msg), "Invalid credentials. Attempt %d/3", gs.loginAttempts);
//                            setStatus(gs, msg, true);
//                        }
//                    }
//                    else {
//                        if (hospital.systemAdmin.getID() == id &&
//                            compareStrings(hospital.systemAdmin.getPassword(), pass) == 0) {
//                            gs.loggedInID = id;
//                            strncpy(gs.loggedInName, "Administrator", 255);
//                            strncpy(gs.loggedInRole, "Admin", 31);
//                            writeSecurityLogEntry(hospital, "Admin", loginFields[0].buffer, "SUCCESS");
//                            clearAllFocus(); gs.needsRefresh = true;
//                            gs.goTo(Screen::ADMIN_DASHBOARD);
//                        }
//                        else {
//                            gs.loginAttempts++;
//                            writeSecurityLogEntry(hospital, "Admin", loginFields[0].buffer, "FAILED");
//                            char msg[64];
//                            snprintf(msg, sizeof(msg), "Invalid credentials. Attempt %d/3", gs.loginAttempts);
//                            setStatus(gs, msg, true);
//                        }
//                    }
//                }
//            }
//
//            // ---- Register ----
//            else if (gs.currentScreen == Screen::REGISTER_PATIENT) {
//                if (registerBtns[1].isClicked(mp)) { clearAllFocus(); gs.goTo(Screen::MAIN_MENU); }
//                if (registerBtns[0].isClicked(mp)) {
//                    if (strlen(registerFields[0].buffer) == 0) {
//                        setStatus(gs, "Name required.", true);
//                    }
//                    else {
//                        int age = convertStringToInt(registerFields[1].buffer);
//                        char g0 = registerFields[2].buffer[0];
//                        if (age < 1 || age > 149) { setStatus(gs, "Age must be 1-149.", true); }
//                        else if (g0 != 'M' && g0 != 'F' && g0 != 'm' && g0 != 'f') { setStatus(gs, "Gender must be M or F.", true); }
//                        else if (!Validator::isValidContactNumber(registerFields[3].buffer)) { setStatus(gs, "Contact: exactly 11 digits.", true); }
//                        else if (!Validator::isValidPassword(registerFields[4].buffer)) { setStatus(gs, "Password: min 6 characters.", true); }
//                        else if (compareStrings(registerFields[4].buffer, registerFields[5].buffer) != 0) { setStatus(gs, "Passwords do not match.", true); }
//                        else {
//                            Patient newPat;
//                            int nid = hospital.generateNextPatientID();
//                            newPat.setID(nid);
//                            newPat.setName(registerFields[0].buffer);
//                            newPat.setAge(age);
//                            char gStr[4] = { (char)(g0 >= 'a' ? g0 - 32 : g0), '\0' };
//                            newPat.setGender(gStr);
//                            newPat.setContact(registerFields[3].buffer);
//                            newPat.setPassword(registerFields[4].buffer);
//                            newPat.setBalance(0.0);
//                            hospital.patients.addRecord(newPat);
//                            FileHandler::appendPatientRecord(newPat, "patients.txt");
//                            char msg[128], idBuf[16];
//                            convertIntToString(nid, idBuf);
//                            snprintf(msg, sizeof(msg), "Registration successful! Your ID: %s", idBuf);
//                            setStatus(gs, msg);
//                            clearAllFocus();
//                            gs.goTo(Screen::MAIN_MENU);
//                        }
//                    }
//                }
//            }
//
//            // ---- Logged-in screens ----
//            else if (strncmp(gs.loggedInRole, "Patient", 7) == 0 ||
//                strncmp(gs.loggedInRole, "Doctor", 6) == 0 ||
//                strncmp(gs.loggedInRole, "Admin", 5) == 0) {
//
//                bool isP = (strncmp(gs.loggedInRole, "Patient", 7) == 0);
//                bool isD = (strncmp(gs.loggedInRole, "Doctor", 6) == 0);
//
//                const Draw::SidebarItem* sidebar =
//                    isP ? g_patientSidebar : isD ? g_doctorSidebar : g_adminSidebar;
//                int sidebarCount = isP ? 8 : isD ? 7 : 11;
//                Screen dashScreen =
//                    isP ? Screen::PATIENT_DASHBOARD :
//                    isD ? Screen::DOCTOR_DASHBOARD : Screen::ADMIN_DASHBOARD;
//
//                // Sidebar hit-test
//                int sideIdx = -1;
//                for (int si = 0; si < sidebarCount; si++) {
//                    sf::FloatRect itemRect(0.f, 53.f + si * 46.f, 200.f, 44.f);
//                    if (itemRect.contains(mp)) { sideIdx = si; break; }
//                }
//
//                if (sideIdx >= 0) {
//                    if (sidebar[sideIdx].target == Screen::MAIN_MENU) {
//                        clearAllFocus(); gs.logout();
//                    }
//                    else {
//                        Screen target = sidebar[sideIdx].target;
//                        if (target != gs.currentScreen) {
//                            clearAllFocus();
//                            gs.goTo(target);
//                            for (int ci = 0; ci < 6; ci++) subFields[ci].clear();
//                            setupSubScreenWidgets(target, subBtns, subFields,
//                                210.f, 62.f, 1060.f);
//                        }
//                    }
//                }
//                else {
//                    // Back button check
//                    bool backClicked = false;
//                    for (int bi = 0; bi < 8; bi++) {
//                        if (subBtns[bi].box.getSize().x < 1.f) continue;
//                        if (subBtns[bi].secondary && subBtns[bi].isClicked(mp)) {
//                            backClicked = true; break;
//                        }
//                    }
//                    if (backClicked) {
//                        clearAllFocus(); gs.goTo(dashScreen); gs.needsRefresh = true;
//                    }
//                    else {
//                        bool primaryClicked = false;
//                        for (int bi = 0; bi < 8; bi++) {
//                            if (subBtns[bi].box.getSize().x < 1.f) continue;
//                            if (!subBtns[bi].secondary && subBtns[bi].isClicked(mp)) {
//                                primaryClicked = true; break;
//                            }
//                        }
//                        if (primaryClicked)
//                            handleSubScreenAction(gs.currentScreen, gs, hospital,
//                                subBtns, subFields, mainList);
//                    }
//                }
//            }
//        } // end clickHappened
//
//        // ============================================================
//        // RENDER
//        // ============================================================
//        window.clear(sf::Color(5, 5, 10));
//        window.setView(view);
//
//        Patient* curPat = hospital.findPatientByID(gs.loggedInID);
//        Doctor* curDoc = hospital.findDoctorByID(gs.loggedInID);
//
//        switch (gs.currentScreen) {
//        case Screen::MAIN_MENU:
//            drawMainMenu(window, assets, gs, mainMenuBtns);
//            break;
//        case Screen::LOGIN_PATIENT:
//        case Screen::LOGIN_DOCTOR:
//        case Screen::LOGIN_ADMIN:
//            drawLoginScreen(window, assets, gs, loginBtns, loginFields);
//            break;
//        case Screen::REGISTER_PATIENT:
//            drawRegisterScreen(window, assets, gs, registerBtns, registerFields);
//            break;
//        case Screen::PATIENT_DASHBOARD:
//            drawPatientDashboard(window, assets, gs, hospital, mainList, mousePos,
//                clickHappened);
//            break;
//        case Screen::DOCTOR_DASHBOARD:
//            drawDoctorDashboard(window, assets, gs, hospital, mainList, mousePos);
//            break;
//        case Screen::ADMIN_DASHBOARD:
//            drawAdminDashboard(window, assets, gs, hospital, mainList, mousePos);
//            break;
//        default:
//            drawSubScreen(window, assets, gs, hospital,
//                subBtns, subFields, mainList, mousePos);
//            break;
//        }
//
//        Draw::toast(window, assets.font, gs.toast);
//        window.display();
//    }
//
//    return 0;
////}
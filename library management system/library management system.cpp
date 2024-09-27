
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 100;
int check_currentDates[MAX_MEMBERS][11];
// Arrays to store book details
int acqNos[MAX_BOOKS];
int accNos[MAX_BOOKS];
char authors[MAX_BOOKS][100];
char titles[MAX_BOOKS][100];
char publishers[MAX_BOOKS][100];
float prices[MAX_BOOKS];
int pages[MAX_BOOKS];
int bookCount = 0;
// Arrays to store member details
int membNos[MAX_MEMBERS];
char names[MAX_MEMBERS][100];
char addresses[MAX_MEMBERS][100];
int beginDates[MAX_MEMBERS][3]; // For storing begin date as [DD, MM, YYYY]
int expiryDates[MAX_MEMBERS][3]; // For storing expiry date as [DD, MM, YYYY]
float cautionMoney[MAX_MEMBERS];
float membershipfee[MAX_MEMBERS];
int memberCount = 0;
int currentDay = 28;
int currentMonth = 5;
int currentYear = 2024;
void mainMenu();
// Acquisition section functions
void acquisitionSection();
void keepNewRecord();
void updateRecord();
void deleteRecord();
void displayBook(int index);
// Membership section functions
void membershipSection();
void recordNewMember();
void updateMember();
void deleteMember();
void displayMember(int index);
// Answer management queries functions
void answerManagementQueries();
void displayAcquisitionRegister();
void displayMembershipRegister();
void displayIssuedRegister();
void List_of_Overdue_Books();
void Fine_register();
void List_of_Expired_Members();
// Arrays to store issued book details
int issuedAcqNos[MAX_MEMBERS];
int issuedAccNos[MAX_MEMBERS];
int proposeDates[MAX_MEMBERS][3];
int issueDates[MAX_MEMBERS][3];
int returnDates[MAX_MEMBERS][3];
bool bookIssued[MAX_MEMBERS] = { false }; 
// Book issue functions
int membNo, acqNo, accNo;
void bookIssue();
void bookReturn();
bool temp_return_num=false;
int membNo_r, acqNo_r, accNo_r;
bool isBookExists(int acqNo, int accNo, int& index);
bool isMemberExists(int membNo, int& index);
void renewMembership(); // New function for renewing membership
bool isExpired(int day1, int month1, int year1, int day2, int month2, int year2);
bool isOverdue(int day1, int month1, int year1, int day2, int month2, int year2);
int main() {
    mainMenu();
    return 0;
}
void mainMenu() {
    int choice;
    do {
        cout << "\n\n\t\t|=====================================================================================|";
        cout << "\n\n\t\t|\t\t       Library Management System                                      |\n\n";
        cout << "\t\t|=====================================================================================|";
        cout << "\n\n\t\t|\t\t1. Acquisition Section                                                |\n\n";
        cout << "\t\t|\t\t2. Membership Maintenance                                             |\n\n";
        cout << "\t\t|\t\t3. Book Issue                                                         |\n\n";
        cout << "\t\t|\t\t4. Book Return                                                        |\n\n";
        cout << "\t\t|\t\t5. Renewal of Membership                                              |\n\n";
        cout << "\t\t|\t\t6. Answer Management Queries                                          |\n\n";
        cout << "\t\t|\t\t0. Exit                                                               |\n";
        cout << "\n\n\t\t|=====================================================================================|";
        cout << "\n\n\t\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: acquisitionSection(); break;
        case 2: membershipSection(); break;
        case 3: bookIssue(); break;
        case 4: bookReturn(); break;
        case 5: renewMembership(); break; 
        case 6: answerManagementQueries(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

void acquisitionSection() {
    int choice;
    do {
        cout << "\n\n\t\t|============================================================================================|";
        cout << "\n\n\t\t|\t\t                   Library Console                                           |\n\n";
        cout << "\t\t|============================================================================================|";
        cout << "\n\n\t\t|\t\t\t1. Keeping New Record                                                |\n\n";
        cout << "\t\t|\t\t\t2. Changing Existing Record                                          |\n\n";
        cout << "\t\t|\t\t\t3. Deleting Existing Record                                          |\n\n";
        cout << "\t\t|\t\t\t0. Return                                                            |\n\n";
        cout << "\t\t|============================================================================================|";
        cout << "\n\n\t\t\t\tEnter Your Choice : ";
        cin >> choice;
        switch (choice) {
        case 1: keepNewRecord(); break;
        case 2: updateRecord(); break;
        case 3: deleteRecord(); break;
        case 0: break;
        default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

void keepNewRecord() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Cannot add more books. Maximum limit reached.\n";
        return;
    }

    int newAcqNo, newAccNo;
    cout << "\n\n\t\t|============================================================================================|";
    cout << "\n\n\t\t|\t\tLibrary Acquisition Entry                                                    |\n\n";
    cout << "\t\t|============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Acquisition Number: ";
    cin >> newAcqNo;
    cout << "\n\n\t\t\t\tEnter Accession Number: ";
    cin >> newAccNo;

    // Check if the book with the same acquisition number and accession number already exists
    for (int i = 0; i < bookCount; i++) {
        if (acqNos[i] == newAcqNo || accNos[i] == newAccNo) {
            cout << "\n\n\t\t\t\tA book with this acquisition number and accession number is already stored.\n";
            return;
        }
    }

    // Proceed to add the new book record
    acqNos[bookCount] = newAcqNo;
    accNos[bookCount] = newAccNo;
    cout << "\n\n\t\t\t\tEnter Authors: ";
    cin.ignore();
    cin.getline(authors[bookCount], 100);
    cout << "\n\n\t\t\t\tEnter Title: ";
    cin.getline(titles[bookCount], 100);
    cout << "\n\n\t\t\t\tEnter Publisher: ";
    cin.getline(publishers[bookCount], 100);
    cout << "\n\n\t\t\t\tEnter Price: ";
    cin >> prices[bookCount];
    cout << "\n\n\t\t\t\tEnter Pages: ";
    cin >> pages[bookCount];
    cout << "\t\t|=============================================================================================|";

    cout << "\n\n\t\t\t\tDo you want to save this record? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        bookCount++;
        cout << "\n\n\t\t\t\tRecord saved successfully.\n";
    }
    else {
        cout << "\n\n\t\t\t\tRecord not saved.\n";
        
    }
}

void updateRecord() {
    int acqNo;
    cout << "\n\n\t\t|============================================================================================|";
    cout << "\n\n\t\t|\t\tUpdate Record                                                                |\n\n";
    cout << "\t\t|============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Acquisition Number of the book to update: ";
    cin >> acqNo;

    for (int i = 0; i < bookCount; i++) {
        if (acqNos[i] == acqNo) {
            displayBook(i);
            cout << "\n\t\t\t\tEnter new details for the book.\n\n";
            cout << "\n\n\t\t\t\tEnter Accession Number: ";
            cin >> accNos[i];
            cout << "\n\n\t\t\t\tEnter Authors: ";
            cin.ignore();
            cin.getline(authors[i], 100);
            cout << "\n\n\t\t\t\tEnter Title: ";
            cin.getline(titles[i], 100);
            cout << "\n\n\t\t\t\tEnter Publisher: ";
            cin.getline(publishers[i], 100);
            cout << "\n\n\t\t\t\tEnter Price: ";
            cin >> prices[i];
            cout << "\n\n\t\t\t\tEnter Pages: ";
            cin >> pages[i];
            cout << "\t\t|=============================================================================================|";

            cout << "\n\n\t\t\t\tDo you want to update this record? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                cout << "\n\n\t\t\t\tRecord updated successfully.\n";
            }
            else {
                cout << "\n\n\t\t\t\tRecord not updated.\n";
            }
            return;
        }
    }

    cout << "\n\n\t\t\t\tNo book found with Acquisition Number " << acqNo << ".\n";
}

void deleteRecord() {
    int acqNo;
    cout << "\n\n\t\t|============================================================================================|";
    cout << "\n\n\t\t|\t\tDeletion Record                                                              |\n\n";
    cout << "\t\t|============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Acquisition Number of the book to delete: ";
    cin >> acqNo;

    for (int i = 0; i < bookCount; i++) {
        if (acqNos[i] == acqNo) {
            displayBook(i);

            cout << "\n\n\t\t\t\tDo you want to delete this record? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < bookCount - 1; j++) {
                    acqNos[j] = acqNos[j + 1];
                    accNos[j] = accNos[j + 1];

                    for (int k = 0; k < 100; k++) {
                        authors[j][k] = authors[j + 1][k];
                        titles[j][k] = titles[j + 1][k];
                        publishers[j][k] = publishers[j + 1][k];
                    }

                    prices[j] = prices[j + 1];
                    pages[j] = pages[j + 1];
                }
                bookCount--;
                cout << "\n\n\t\t\t\tRecord deleted successfully.\n";
            }
            else {
                cout << "\n\n\t\t\t\tRecord not deleted.\n";
            }
            return;
        }
    }

    cout << "\n\n\t\t\t\tNo book found with Acquisition Number " << acqNo << ".\n";
}

void displayBook(int index) {
    cout << "\n\n\t\t\t\tBook Details:\n";
    cout << "\n\n\t\t\t\tAcquisition Number: " << acqNos[index] << "\n";
    cout << "\n\n\t\t\t\tAccession Number: " << accNos[index] << "\n";
    cout << "\n\n\t\t\t\tAuthors: " << authors[index] << "\n";
    cout << "\n\n\t\t\t\tTitle: " << titles[index] << "\n";
    cout << "\n\n\t\t\t\tPublisher: " << publishers[index] << "\n";
    cout << "\n\n\t\t\t\tPrice: " << prices[index] << "\n";
    cout << "\n\n\t\t\t\tPages: " << pages[index] << "\n";
}

void membershipSection() {
    int choice;
    do {
        cout << "\n\n\t\t|==============================================================================================|";
        cout << "\n\n\t\t|\t\tMembership Maintenance                                                         |\n\n";
        cout << "\t\t|==============================================================================================|";
        cout << "\n\n\t\t|\t\t\t1. Record New Member                                                   |\n\n";
        cout << "\t\t|\t\t\t2. Update Member Details                                               |\n\n";
        cout << "\t\t|\t\t\t3. Delete Member                                                       |\n\n";
        cout << "\t\t|\t\t\t0. Return                                                              |\n\n";
        cout << "\t\t|==============================================================================================|";
        cout << "\n\n\t\t\t\tEnter Your Choice : ";

        cin >> choice;

        switch (choice) {
        case 1: recordNewMember(); break;
        case 2: updateMember(); break;
        case 3: deleteMember(); break;
        case 0: break;
        default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

void recordNewMember() {
    if (memberCount >= MAX_MEMBERS) {
        cout << "Cannot add more members. Maximum limit reached.\n";
        return;
    }
    cout << "\n\n\t\t|===============================================================================================|";
    cout << "\n\n\t\t|\t\tNew Membership Entry                                                            |\n\n";
    cout << "\t\t|===============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Member Number: ";
    cin >> membNos[memberCount];
    cout << "\n\n\t\t\t\tEnter Name: ";
    cin.ignore();
    cin.getline(names[memberCount], 100);
    cout << "\n\n\t\t\t\tEnter Address: ";
    cin.getline(addresses[memberCount], 100);
    cout << "\nEnter Membership Start Date (DD-MM-YYYY): ";
    cin >> beginDates[memberCount][0]; // Read day
    cin.ignore(); // Ignore the dash
    cin >> beginDates[memberCount][1]; // Read month
    cin.ignore(); // Ignore the dash
    cin >> beginDates[memberCount][2]; // Read year
    cout << "Enter Membership Expiry Date (DD-MM-YYYY): ";
    cin >> expiryDates[memberCount][0]; // Read day
    cin.ignore(); // Ignore the dash
    cin >> expiryDates[memberCount][1]; // Read month
    cin.ignore(); // Ignore the dash
    cin >> expiryDates[memberCount][2]; // Read year
    cout << "\n\n\t\t\t\tEnter Membership fees: ";
    cin >> membershipfee[memberCount];
    cout << "\n\n\t\t\t\tEnter Caution Money: ";
    cin >> cautionMoney[memberCount];
    cout << "\t\t|==================================================================================================|";

    cout << "\n\n\t\t\t\tDo you want to save this record? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        memberCount++;
        cout << "\n\n\t\t\t\tRecord saved successfully.\n";
    }
    else {
        cout << "\n\n\t\t\t\tRecord not saved.\n";
    }
}

void updateMember() {
    int membNo;
    cout << "\n\n\t\t|===============================================================================================|";
    cout << "\n\n\t\t|\t\tUpdate Member Details                                                           |\n\n";
    cout << "\t\t|===============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Member Number of the member to update: ";
    cin >> membNo;

    for (int i = 0; i < memberCount; i++) {
        if (membNos[i] == membNo) {
            displayMember(i);
            cout << "\n\t\t\t\tEnter new details for the member.\n\n";
            cout << "\n\n\t\t\t\tEnter Name: ";
            cin.ignore();
            cin.getline(names[i], 100);
            cout << "\n\n\t\t\t\tEnter Address: ";
            cin.getline(addresses[i], 100);
            cout << "\nEnter Membership Start Date (DD-MM-YYYY): ";
            cin >> beginDates[memberCount][0]; // Read day
            cin.ignore(); // Ignore the dash
            cin >> beginDates[memberCount][1]; // Read month
            cin.ignore(); // Ignore the dash
            cin >> beginDates[memberCount][2]; // Read year
            cout << "Enter Membership Expiry Date (DD-MM-YYYY): ";
            cin >> expiryDates[memberCount][0]; // Read day
            cin.ignore(); // Ignore the dash
            cin >> expiryDates[memberCount][1]; // Read month
            cin.ignore(); // Ignore the dash
            cin >> expiryDates[memberCount][2]; // Read year
            cout << "\n\n\t\t\t\tEnter Membership fees: ";
            cin >> membershipfee[i];
            cout << "\n\n\t\t\t\tEnter Caution Money: ";
            cin >> cautionMoney[i];
            cout << "\t\t|==================================================================================================|";
            cout << "\n\n\t\t\t\tDo you want to update this record? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                cout << "\n\n\t\t\t\tRecord updated successfully.\n";
            }
            else {
                cout << "\n\n\t\t\t\tRecord not updated.\n";
            }
            return;
        }
    }

    cout << "\n\n\t\t\t\tNo member found with Member Number " << membNo << ".\n";
}

void deleteMember() {
    int membNo;
    cout << "\n\n\t\t|===============================================================================================|";
    cout << "\n\n\t\t|\t\tDelete Member                                                                   |\n\n";
    cout << "\t\t|===============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Member Number of the member to delete: ";
    cin >> membNo;

    for (int i = 0; i < memberCount; i++) {
        if (membNos[i] == membNo) {
            displayMember(i);
            cout << "\t\t|==================================================================================================|";
            cout << "\n\n\t\t\t\tDo you want to delete this record? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < memberCount - 1; j++) {
                    membNos[j] = membNos[j + 1];

                    for (int k = 0; k < 100; k++) {
                        names[j][k] = names[j + 1][k];
                        addresses[j][k] = addresses[j + 1][k];
                    }

                    for (int k = 0; k < 11; k++) {
                        beginDates[i][0] = beginDates[i + 1][0];
                        beginDates[i][1] = beginDates[i + 1][1];
                        beginDates[i][2] = beginDates[i + 1][2];
                        expiryDates[i][0] = expiryDates[i + 1][0];
                        expiryDates[i][1] = expiryDates[i + 1][1];
                        expiryDates[i][2] = expiryDates[i + 1][2];
                    }
                    membershipfee[j] = membershipfee[j + 1];
                    cautionMoney[j] = cautionMoney[j + 1];

                }
                memberCount--;
                cout << "\n\n\t\t\t\tRecord deleted successfully.\n";
            }
            else {
                cout << "\n\n\t\t\t\tRecord not deleted.\n";
            }
            return;
        }
    }

    cout << "\n\n\t\t\t\tNo member found with Member Number " << membNo << ".\n";
}

void displayMember(int index) {
    cout << "\n\n\t\t\t\tMember Details:\n";
    cout << "\n\n\t\t\t\tMember Number: " << membNos[index] << "\n";
    cout << "\n\n\t\t\t\tName: " << names[index] << "\n";
    cout << "\n\n\t\t\t\tAddress: " << addresses[index] << "\n";
    cout << "\n\n\t\t\t\tMembership Date: " << beginDates[index][0] << "-"<< beginDates[index][1] << "-"<< beginDates[index][2] << "\n";
    cout << "\n\n\t\t\t\tExpiry Date: " << expiryDates[index][0] << "-"<< expiryDates[index][1] << "-"<< expiryDates[index][2] << "\n";
    cout << "\n\n\t\t\t\tMembership Fess: " << membershipfee[index] << "\n";
    cout << "\n\n\t\t\t\tCaution Money: " << cautionMoney[index] << "\n";
    
}

void answerManagementQueries() {
    int choice;
    do {
        cout << "\n\n\t\t|===============================================================================================|";
        cout << "\n\n\t\t|\t\t                       Reporting Console                                        |\n\n";
        cout << "\t\t|===============================================================================================|";
        cout << "\n\n\t\t|\t\t\t1. Acquisition Register                                                 |\n\n";
        cout << "\t\t|\t\t\t2. Membership Register                                                  |\n\n";
        cout << "\t\t|\t\t\t3. Issue Register                                                       |\n\n";
        cout << "\t\t|\t\t\t4. List of Overdue Books                                                |\n\n";
        cout << "\t\t|\t\t\t5. Fine Register                                                        |\n\n";
        cout << "\t\t|\t\t\t6.List of Expired Members                                               |\n\n";
        cout << "\t\t|\t\t\t0. Return                                                               |\n\n";
        cout << "\t\t|===============================================================================================|";
        cout << "\n\n\t\t\t\tEnter Your Choice : ";

        cin >> choice;

        switch (choice) {
        case 1: displayAcquisitionRegister(); break;
        case 2: displayMembershipRegister(); break;
        case 3: displayIssuedRegister(); break;
        case 4: List_of_Overdue_Books(); break;
        case 5: Fine_register(); break;
        case 6: List_of_Expired_Members(); break;
        case 0: break;
        default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

void displayAcquisitionRegister() {
    cout << "\n\n\t|========================================================================================================|\n";
    cout << "\n\t|\t\t\t\t\tAcquisition Register                                             |\n";
    cout << "\n\t|========================================================================================================|";

    cout << "\n\n\t| " << setw(6) << "Sr.No" << " | " << setw(6) << "Acq.No" << " | " << setw(6) << "Acc.No" << " | "
        << setw(30) << "Title & Author" << " | " << setw(15) << "Publisher" << " | " << setw(7) << "Price"
        << " | " << setw(5) << "Pages" << " | " << setw(6) << "Status" << " |\n";
    cout << "\n\t|========================================================================================================|\n\n";

    for (int i = 0; i < bookCount; i++) {
        cout << "\t| " << setw(6) << i + 1 << " | " << setw(6) << acqNos[i] << " | " << setw(6) << accNos[i] << " | "
            << setw(30) << (string(titles[i]) + " by " + string(authors[i])) << " | " << setw(15) << publishers[i] << " | "
            << setw(7) << prices[i] << " | " << setw(5) << pages[i] << " | " << setw(6) << "Y" << " |\n";
    }
    cout << "\t|========================================================================================================|\n";
}
void displayMembershipRegister() {
    cout << "\n\n\t|========================================================================================================|\n";
    cout << "\n\t|\t\t\t\t\tMembership Register                                              |\n";
    cout << "\n\t|========================================================================================================|";

    cout << "\n\n\t| " << setw(8) << "Sr.No" << " | " << setw(8) << "Memb.No" << " | " << setw(14) << "Name & Address"
        << "     | " << setw(8) << "Memb.Date" << " | " << setw(8) << "Exp.Date" << " | "<<setw(7)<<"MEMBERSHIP FEES"<<" | " << setw(10) << "Caution Money" << "|\n";
    cout << "\n\t|========================================================================================================|\n\n";

    for (int i = 0; i < memberCount; i++) {
        cout << "\t| " << setw(8) << i + 1 << " | " << setw(8) << membNos[i] << " | " << setw(14) << (string(names[i]) + ", " + string(addresses[i]))
            << " | " << setw(8) << beginDates[i][0] << "-" << beginDates[i][1] << "-" << beginDates[i][2] << " | " << setw(8) << expiryDates[i][0] << "-" << expiryDates[i][1] << "-" << expiryDates[i][2] << " | "<<setw(7)<<membershipfee[i]<<" | " << setw(10) << cautionMoney[i] << "  |\n";
    }

    cout << "\t|========================================================================================================|\n";
}
void displayIssuedRegister() {
    cout << "\n\n\t|========================================================================================================|\n";
    cout << "\n\t|\t\t\t\t\tIssued Register                                                  |\n";
    cout << "\n\t|========================================================================================================|";

    cout << "\n\n\t| " << setw(12) << "Sr.No" << " | " << setw(12) << "Memb.No" << " | " << setw(12) << "Acq.No" << " | "
        << setw(12) << "Acc.No" << " | " << setw(16) << "Issue Date" << " | " << setw(16) << "Propose Date" << "        |\n";
    cout << "\n\t|========================================================================================================|\n\n";

    for (int i = 0; i < memberCount; i++) {
        if (bookIssued[i]) {
            cout << "\t| " << setw(12) << i + 1 << " | " << setw(12) << membNos[i] << " | " << setw(12) << issuedAcqNos[i] << " | "
                << setw(12) << issuedAccNos[i] << " | " << setw(13) << issueDates[memberCount][0] << "-" << issueDates[memberCount][1] << "-" << issueDates[memberCount][2] << " | " << setw(10) << proposeDates[memberCount][0] << "-" << proposeDates[memberCount][1] << "-" << proposeDates[memberCount][2] << "  |\n\n";
        }
    }
    cout << "\t|========================================================================================================|\n";
}

void List_of_Overdue_Books() {
    cout << "\n\n\t|========================================================================================================|\n";
    cout << "\n\t|\t\t\t\t\tOverdue Books                                                    |\n";
    cout << "\n\t|========================================================================================================|";

    cout << "\n\n\t| " << setw(8) << "Sr.No" << " | " << setw(8) << "Memb.No" << " | " << setw(12) << "Acq.No" << " | "
        << setw(12) << "Acc.No" << " | " << setw(16) << "Issue Date" << " | " << setw(16) << "Return date" << " | "<<setw(12)<<"days overdue"<<" | \n";
    cout << "\n\t|========================================================================================================|\n\n";
    if (temp_return_num = true && returnDates != proposeDates) {
        if (returnDates != proposeDates) {
            for (int i = 0; i < memberCount; i++) {
                cout << "\t| " << setw(8) << i + 1 << " | " << setw(8) << membNos[i] << " | " << setw(12) << issuedAcqNos[i] << " | "
                    << setw(12) << issuedAccNos[i] << " | " << setw(16) << issueDates[i][0]<<"-" << issueDates[i][1]<<"-" << issueDates[i][2] << " | " << setw(16) << returnDates[i][0]<<"-" << returnDates[i][1]<<"-" << returnDates[i][2] << " | " << setw(12) << "1" << "   |    \n\n";
            }
        }
        else if (returnDates==proposeDates){
            return;
        }
    }
    cout << "\t|========================================================================================================|\n";
}
void Fine_register() {
    cout << "\n\n\t|========================================================================================================|\n";
    cout << "\n\t|\t\t\t\t\tFine Register                                                    |\n";
    cout << "\n\t|========================================================================================================|";

    cout << "\n\n\t| " << setw(3) << "Sr.No" << " | " << setw(3) << "Memb.No" << " | " << setw(10) << "Acq.No" << " | "
        << setw(10) << "Acc.No" << " | " << setw(10) << "Issue Date" << " | " << setw(10) << "Return Date" << " | "<<setw(18)<<"Returned On"<<" | "<<setw(10)<<"Fine"<<" | \n";
    cout << "\n\t|========================================================================================================|\n\n";
        
    for (int i = 0; i < memberCount; i++) {
          cout << "\t| " << setw(3) << i + 1 << " | " << setw(3) << membNos[i] << " | " << setw(10) << issuedAcqNos[i] << " | "
          << setw(10) << issuedAccNos[i] << " | " << setw(10) << issueDates[i][0]<<"-" << issueDates[i][1]<<"-" << issueDates[i][2] << " | " << setw(10) << proposeDates[i][0]<<"-" << proposeDates[i][1]<<"-" << proposeDates[i][2] << " | " << setw(18) << returnDates[i][0]<<"-" << returnDates[i][1]<<"-" << returnDates[i][2] << " | " << setw(10) << "1" << " | \n\n";
    }
    
    cout << "\t|========================================================================================================|\n";
}
void List_of_Expired_Members() {
    cout << "\n\n\t|========================================================================================================|\n";
    cout << "\n\t|\t\t\t\t\tExpired Membership Register                                      |\n";
    cout << "\n\t|========================================================================================================|";
    
    
    cout << "\n\n\t| " << setw(8) << "Sr.No" << " | " << setw(4) << " beginig Memb.No" << " | " << setw(34) << "Name & Address"
    << " | " << setw(14) << "Memb.Date" << " | " << setw(16) << "Exp membership.Date" << "| " << "\n";
    cout << "\n\t|========================================================================================================|\n";
    for (int i = 0; i < memberCount; i++) {
        if (isExpired(expiryDates[i][0], expiryDates[i][1], expiryDates[i][2], currentDay, currentMonth, currentYear)) {
            cout << "\t| " << setw(8) << i + 1 << " | " << setw(4) << membNos[i] << " | " << setw(34) << (string(names[i]) + ", " + string(addresses[i]))
            << " | " << setw(14) << beginDates[i][0] << "-"  << beginDates[i][1] << "-"<< beginDates[i][2] << " | " << setw(16) << expiryDates[i][0] << "-" << expiryDates[i][1] << "-"<< expiryDates[i][2] << " | " << " |\n";
        }
    } 
    

    cout << "\t|========================================================================================================|\n";
}
void bookIssue() {
    int membNo, acqNo, accNo;
    cout << "\n\n\t\t|============================================================================================|";
    cout << "\n\n\t\t|\t\tBook Issue                                                                   |\n\n";
    cout << "\t\t|============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Membership Number: ";
    cin >> membNo;

    int memberIndex;
    if (!isMemberExists(membNo, memberIndex)) {
        cout << "\n\n\t\t\t\tNo member found with Membership Number " << membNo << ".\n";
        return;
    }

    if (bookIssued[memberIndex]) {
        cout << "\n\n\t\t\t\tThis member already has an issued book. Please return the current book before issuing a new one.\n";
        return;
    }

    displayMember(memberIndex);

    cout << "\n\n\t\t\t\tEnter Acquisition Number of the book: ";
    cin >> acqNo;
    cout << "\n\n\t\t\t\tEnter Accession Number of the book: ";
    cin >> accNo;
    // Check if the book is already issued
    for (int i = 0; i < memberCount; i++) {
        if (bookIssued[i] && issuedAcqNos[i] == acqNo && issuedAccNos[i] == accNo) {
            cout << "This book is already issued to another member.\n";
            return;
        }
    }

    int bookIndex;
    if (!isBookExists(acqNo, accNo, bookIndex)) {
        cout << "\n\n\t\t\t\tNo book found with Acquisition Number " << acqNo << " and Accession Number " << accNo << ".\n";
        return;
    }

    displayBook(bookIndex);

    cout << "\n\n\t\t\t\tEnter Issue Date (DD/MM/YYYY): ";
    cin.ignore();
    cin >> issueDates[memberCount][0]; // Read day
    cin.ignore(); // Ignore the dash
    cin >> issueDates[memberCount][1]; // Read month
    cin.ignore(); // Ignore the dash
    cin >> issueDates[memberCount][2]; // Read year
    cout << "\n\n\t\t\t\tEnter Proposed Return Date (DD/MM/YYYY): ";
    cin >> proposeDates[memberCount][0]; // Read day
    cin.ignore(); // Ignore the dash
    cin >> proposeDates[memberCount][1]; // Read month
    cin.ignore(); // Ignore the dash
    cin >> proposeDates[memberCount][2]; // Read year
    bookIssued[memberIndex] = true;
    issuedAcqNos[memberIndex] = acqNo;
    issuedAccNos[memberIndex] = accNo;

    cout << "\t\t|=============================================================================================|";

    cout << "\n\n\t\t\t\tDo you want to issue this book? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cout << "\n\n\t\t\t\tBook issued successfully to member.\n";
    }
    else {
        cout << "\n\n\t\t\t\tBook is not issued.\n";
        return;
    }
}
void bookReturn() {
    cout << "\n\n\t\t|============================================================================================|";
    cout << "\n\n\t\t|\t\tBook Return                                                                  |\n\n";
    cout << "\t\t|============================================================================================|";
    cout << "\n\n\t\t\t\tEnter Membership Number: ";
    cin >> membNo;

    int memberIndex;
    if (!isMemberExists(membNo, memberIndex)) {
        cout << "\n\n\t\t\t\tNo member found with Membership Number " << membNo << ".\n";
        return;
    }

    if (!bookIssued[memberIndex]) {
        cout << "\n\n\t\t\t\tThis member does not have any issued book.\n";
        return;
    }

    displayMember(memberIndex);
    displayBook(memberIndex);

    // Record the return date
    cout << "\n\n\t\t\t\tEnter Return Date (DD/MM/YYYY): ";
    cin.ignore();
    cin >> returnDates[memberCount][0]; // Read day
    cin.ignore(); // Ignore the dash
    cin >> returnDates[memberCount][1]; // Read month
    cin.ignore(); // Ignore the dash
    cin >> returnDates[memberCount][2]; // Read year
    bookIssued[memberIndex] = false;
    temp_return_num = true;
    cout << "\t\t|=============================================================================================|";

    cout << "\n\n\t\t\t\tDo you want to return this book? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cout << "\n\n\t\t\t\tBook returned successfully by member.\n";
    }
    else {
        cout << "\n\n\t\t\t\tBook is not returned.\n";
        return;
    }
}
void renewMembership() {
    int membNo;
    cout << "\n\n\t\t|=====================================================================================|";
    cout << "\n\n\t\t|\t\tRenew Membership                                                    |\n\n";
    cout << "\t\t|=====================================================================================|";
    cout << "\n\n\t\t\t\tEnter Member Number to renew: ";
    cin >> membNo;

    for (int i = 0; i < memberCount; i++) {
        if (membNos[i] == membNo) {
            displayMember(i);
            cout << "\n\n\t\t\t\tEnter New Expiry Date (DD-MM-YYYY): ";
            cin.ignore();
            cin >> expiryDates[i][0]; // Read day
            cin.ignore(); // Ignore the dash
            cin >> expiryDates[i][1]; // Read month
            cin.ignore(); // Ignore the dash
            cin >> expiryDates[i][2]; // Read year
            cout << "\n\n\t\t\t\tDo you want to renew this membership? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                cout << "\n\n\t\t\t\tMembership renewed successfully.\n";
            }
            else {
                cout << "\n\n\t\t\t\tMembership not renewed.\n";
            }
            return;
        }
    }

    cout << "\n\n\t\t\t\tNo member found with Member Number " << membNo << ".\n";
}
bool isBookExists(int acqNo, int accNo, int& index) {
    for (int i = 0; i < bookCount; i++) {
        if (acqNos[i] == acqNo && accNos[i] == accNo) {
            index = i;
            return true;
        }
    }
    return false;
}
bool isMemberExists(int membNo, int& index) {
    for (int i = 0; i < memberCount; i++) {
        if (membNos[i] == membNo) {
            index = i;
            return true;
        } 
    }
    return false;
}
bool isExpired(int day1, int month1, int year1, int day2, int month2, int year2) {
    if (year1 < year2) {
        return true;
    }
    else if (year1 == year2) {
        if (month1 < month2) {
            return true;
        }
        else if (month1 == month2) {
            if (day1 < day2) {
                return true;
            }
        }
    }
    return false;
}
bool isOverdue(int day1, int month1, int year1, int day2, int month2, int year2) {
    if (year1 > year2) return false;
    if (year1 < year2) return true;
    if (month1 > month2) return false;
    if (month1 < month2) return true;
    return day1 > day2 ? false : true;
}

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
class Node {
public:
    string Emp_Id, Name, Post, Department;
    float salary;
    Node* Next_Add;
};
class Employee {
private:
    Node* Head;
    string user;
    string pass;
public:
    Employee();
    void Introduction();
    void Login(); // User Authentication
    // Algorithm: User Authentication
    // Purpose: User authentication is implemented to verify user identity based on provided username and password. It checks credentials against predefined user credentials to grant or deny access.
    void Control_Panel();
    void Insert(); // Insertion at the End of the Linked List
    // Data Structure: Linked List
    // Purpose: A singly linked list is used to dynamically store and manage employee records. Each node contains employee information and a reference to the next node.
    // Algorithms: Linear Search, Insertion at the End, Deletion by Employee ID
    // Comments: Linked lists provide efficient record storage and retrieval, and linear search, insertion, and deletion algorithms are used to manipulate records in the list.
    void Search_Id(); // Linear Search
    // Algorithm: Linear Search
    // Purpose: Linear search is used to find employee records based on Employee ID or department. It iterates through the linked list to locate the desired record.
    void Edit();
    void Del(); // Deletion by Employee ID
    // Algorithm: Deletion by Employee ID
    // Purpose: Deletion of an employee record is done by searching for the record using Employee ID and removing it from the linked list.
    void Display(); // Linear Search
    // Algorithm: Linear Search
    // Purpose: Linear search is used to find employee records based on Employee ID or department. It iterates through the linked list to locate the desired record.
    void Salary_Slip();
    void Search_Dept(); // Linear Search
     // Algorithm: Linear Search
    // Purpose: Linear search is used to find employee records based on Employee ID or department. It iterates through the linked list to locate the desired record.
};
Employee::Employee() {
    Head = NULL;
    user = "";
    pass = "";
}
void Employee::Introduction() {
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t====================================";
    cout << "\n\t\t\t==================================";
    cout << "\n\n\n\t\t\t   EMPLOYEE MANAGEMENT SYSTEM";
    cout << "\n\n\n\t\t\t\t FINAL VERSION ";
    cout << "\n\n\t\t\t=================================";
    cout << "\n\t\t\t===================================";
    getch();
}

void Employee::Login() {
    p:
    system("cls");
    system("color 4f");

    cout << "\n\n";
    cout << "\t\t\t===============================";
    cout << "\n\n\t\t\t\tLOGIN PANEL";
    cout << "\n\n\t\t\t===========================";
    cout << "\n\n\n ENTER USER NAME: ";
    cin >> user;
    cout << "\n\n ENTER PASSWORD: ";
    for (int i = 1; i <= 6; i++) {
        pass += getch();
        cout << "*";
    }

    if ((user == "Zunaid" && pass == "123456") || (user == "Ifti" && pass == "123456")) {
        cout << "\n\n\n\t\t\tCONGRATULATIONS! LOGIN SUCCESS";
        cout << "\n\n\n\t\t\t\tLOADING";

        for (int i = 1; i <= 6; i++) {
            Sleep(500);
            cout << ".";
        }
        Control_Panel();
    }
    else {
        cout << "\n\n\n\t\t\t  Invalid login.........";
    }

    getch();
    goto p;
}
// The rest of the code follows a similar structure with data structures and algorithms used for various operations.
int main() {
    Employee users[3];  // Array of Employee instances for three users
    // Data Structure: Arrays
    // Purpose: Arrays are used to manage multiple instances of the Employee class, representing different users. Each element of the array corresponds to a different user.
    // Comments: Arrays allow the system to accommodate multiple users and manage their interactions, providing a straightforward way to store and access user data.
    // Set data for three users
    users[0].Introduction();
    users[0].Login();
    users[1].Introduction();
    users[1].Login();
    users[2].Introduction();
    users[2].Login();
    return 0;
    // Error Handling
    // Purpose: Error handling is implemented to manage and report errors during user interactions, ensuring the system handles invalid or unexpected inputs gracefully.
    // Data Validation
    // Purpose: Data validation ensures that user input adheres to specific rules and constraints. For example, during record insertion, it checks for duplicate Employee IDs to maintain data integrity.
}

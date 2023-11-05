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
    void Login();
    void Control_Panel();
    void Insert();
    void Search_Id();
    void Edit();
    void Del();
    void Display();
    void Salary_Slip();
    void Search_Dept();
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

void Employee::Control_Panel() {
p:
    system("cls");

    int x;
    cout << "\n\n\t\t\t=========================";
    cout << "\n\n\t\t\t EMPLOYEE CONTROL PANEL";
    cout << "\n\n\t\t\t=========================";
    cout << "\n\n\n 1. INSERT RECORD";
    cout << "\n 2. SEARCH RECORD";
    cout << "\n 3. EDIT RECORD";
    cout << "\n 4. DELETE RECORD";
    cout << "\n 5. DISPLAY RECORD";
    cout << "\n 6. SALARY SLIP";
    cout << "\n 7. SEARCH DEPARTMENT";
    cout << "\n 8. EXIT";
    cout << "\n\n YOUR CHOICE: ";
    cin >> x;

    switch (x) {
    case 1:
        Insert();
        break;
    case 2:
        Search_Id();
        break;
    case 3:
        Edit();
        break;
    case 4:
        Del();
        break;
    case 5:
        Display();
        break;
    case 6:
        Salary_Slip();
        break;
    case 7:
        Search_Dept();
        break;
    case 8:
        exit(0);
    default:
        cout << "\n\n *****INVALID CHOICE......PLEASE TRY AGAIN******";
    }
    getch();
    goto p;
}

void Employee::Insert() {
p:
    system("cls");
    system("color 5f");
    Node* New_Node = new Node;
    cout << "\n\n\t\t\t===========================";
    cout << "\n\n\t\t\t INSERT EMPLOYEE RECORD";
    cout << "\n\n\t\t\t===========================";
    cout << "\n\n EMPLOYEE ID: ";
    cin >> New_Node->Emp_Id;
    cout << "\n\n EMPLOYEE NAME: ";
    cin >> New_Node->Name;
    cout << "\n\n EMPLOYEE POST: ";
    cin >> New_Node->Post;
    cout << "\n\n EMPLOYEE DEPARTMENT: ";
    cin >> New_Node->Department;
    cout << "\n\n EMPLOYEE SALARY: ";
    cin >> New_Node->salary;
    New_Node->Next_Add = nullptr;
    if (Head == nullptr) {
        Head = New_Node;
    }
    else {
        Node* ptr = Head;
        while (ptr != nullptr) {
            if (New_Node->Emp_Id == ptr->Emp_Id) {
                cout << "****Duplicate Employee Record****";
                delete New_Node;
                getch();
                goto p;
            }
            ptr = ptr->Next_Add;
        }
        ptr = Head;
        while (ptr->Next_Add != nullptr) {
            ptr = ptr->Next_Add;
        }
        ptr->Next_Add = New_Node;
    }
    cout << "\n\n ***EMPLOYEE RECORD INSERTED***";
}

void Employee::Search_Id() {
    system("cls");
    system("color 5f");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t====================================";
    cout << "\n\n\t\t\t  SEARCH EMPLOYEE RECORD";
    cout << "\n\n\t\t\t====================================";
    if (Head == nullptr) {
        cout << "\n\n ***LINKED LIST IS EMPTY ***";
    }
    else {
        cout << "\n\n Employee ID For Search : ";
        cin >> EmpId;
        Node* ptr = Head;
        while (ptr != nullptr) {
            if (EmpId == ptr->Emp_Id) {
                system("cls");
                cout << "\n\n\t\t\t====================================";
                cout << "\n\n\t\t\t  SEARCH EMPLOYEE RECORD";
                cout << "\n\n\t\t\t====================================";
                cout << "\n\n EMPLOYEE ID :" << ptr->Emp_Id;
                cout << "\n\n EMPLOYEE NAME :" << ptr->Name;
                cout << "\n\n EMPLOYEE Post :" << ptr->Post;
                cout << "\n\n EMPLOYEE Department :" << ptr->Department;
                cout << "\n\n EMPLOYEE salary :" << ptr->salary;
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0) {
            cout << "\n\n****EMPLOYEE NOT FOUND****";
        }
    }
}

void Employee::Edit() {
    system("cls");
    system("color 5f");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t MODIFY EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    if (Head == nullptr) {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else {
        cout << "\n\n EMPLOYEE ID FOR MODIFY:";
        cin >> EmpId;
        Node* ptr = Head;
        while (ptr != nullptr) {
            if (EmpId == ptr->Emp_Id) {
                cout << "\n\n EMPLOYEE NAME:";
                cin >> ptr->Name;
                cout << "\n\n EMPLOYEE POST:";
                cin >> ptr->Post;
                cout << "\n\n EMPLOYEE DEPARTMENT:";
                cin >> ptr->Department;
                cout << "\n\n EMPLOYEE SALARY :";
                cin >> ptr->salary;
                cout << "\n\n ****EMPLOYEE RECORD MODIFIED****";
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0) {
            cout << "\n\n****EMPLOYEE NOT FOUND****";
        }
    }
}

void Employee::Del() {
    system("cls");
    system("color 5f");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t DELETE EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    if (Head == nullptr) {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else {
        cout << "\n\n EMPLOYEE ID FOR DELETE:";
        cin >> EmpId;
        if (EmpId == Head->Emp_Id) {
            Node* ptr = Head;
            Head = Head->Next_Add;
            delete ptr;
            cout << "\n\n ***EMPLOYEE RECORD DELETED***";
        }
        else {
            Node* pre = Head;
            Node* ptr = Head;
            while (ptr != nullptr) {
                if (EmpId == ptr->Emp_Id) {
                    pre->Next_Add = ptr->Next_Add;
                    cout << "\n\n ***EMPLOYEE RECORD DELETED***";
                    found++;
                    break;
                }
                pre = ptr;
                ptr = ptr->Next_Add;
            }
            if (found == 0) {
                cout << "\n\n****EMPLOYEE NOT FOUND****";
            }
        }
    }
}

void Employee::Display() {
    system("cls");
    system("color 5f");
    cout << "\n\n\t\t\t====================================";
    cout << "\n\n\t\t\t  DISPLAY EMPLOYEE RECORD";
    cout << "\n\n\t\t\t====================================";
    if (Head == nullptr) {
        cout << "\n\n ***LINKED LIST IS EMPTY ***";
    }
    else {
        Node* ptr = Head;
        while (ptr != nullptr) {
            cout << "\n\n EMPLOYEE ID :" << ptr->Emp_Id;
            cout << "\n\n EMPLOYEE NAME :" << ptr->Name;
            cout << "\n\n EMPLOYEE POST :" << ptr->Post;
            cout << "\n\n EMPLOYEE DEPARTMENT :" << ptr->Department;
            cout << "\n\n EMPLOYEE SALARY :" << ptr->salary;
            ptr = ptr->Next_Add;
        }
    }
}

void Employee::Salary_Slip() {
    system("cls");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t====================================";
    cout << "\n\n\t\t\t  SALARY SLIP GENERATOR";
    cout << "\n\n\t\t\t====================================";
    if (Head == nullptr) {
        cout << "\n\n ***LINKED LIST IS EMPTY ***";
    }
    else {
        cout << "\n\n Employee ID For SLIP : ";
        cin >> EmpId;
        Node* ptr = Head;
        while (ptr != nullptr) {
            if (EmpId == ptr->Emp_Id) {
                system("cls");
                cout << "\n\n\t\t\t====================================";
                cout << "\n\n\t\t\t  SALARY SLIP";
                cout << "\n\n\t\t\t====================================";
                cout << "\n\n EMPLOYEE ID :         " << ptr->Emp_Id;
                cout << "\n\n EMPLOYEE NAME :       " << ptr->Name;
                cout << "\n\n EMPLOYEE POST :       " << ptr->Post;
                cout << "\n\n EMPLOYEE DEPARTMENT : " << ptr->Department;
                cout << "\n\n EMPLOYEE SALARY :     " << ptr->salary;
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0) {
            cout << "\n\n****EMPLOYEE NOT FOUND****";
        }
    }
}

void Employee::Search_Dept() {
    system("cls");
    int found = 0;
    string dept;
    cout << "\n\n\t\t\t====================================";
    cout << "\n\n\t\t\t  SEARCH DEPARTMENT RECORD";
    cout << "\n\n\t\t\t====================================";
    if (Head == nullptr) {
        cout << "\n\n ***LINKED LIST IS EMPTY ***";
    }
    else {
        cout << "\n\n DEPARTMENT For Search : ";
        cin >> dept;
        Node* ptr = Head;
        while (ptr != nullptr) {
            if (dept == ptr->Department) {
                system("cls");
                cout << "\n\n\t\t\t====================================";
                cout << "\n\n\t\t\t  SEARCH EMPLOYEE RECORD";
                cout << "\n\n\t\t\t====================================";
                cout << "\n\n EMPLOYEE ID :" << ptr->Emp_Id;
                cout << "\n\n EMPLOYEE NAME :" << ptr->Name;
                cout << "\n\n EMPLOYEE POST :" << ptr->Post;
                cout << "\n\n EMPLOYEE DEPARTMENT :" << ptr->Department;
                cout << "\n\n EMPLOYEE SALARY :" << ptr->salary;
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0) {
            cout << "\n\n****DEPARTMENT NAME NOT FOUND****";
        }
        else
            cout << "\n\n Total Employee: " << found;
    }
}

int main() {
    Employee users[3];  // Array of Employee instances for three users

    // Set data for three users
    users[0].Introduction();
    users[0].Login();

    users[1].Introduction();
    users[1].Login();

    users[2].Introduction();
    users[2].Login();

    return 0;
}

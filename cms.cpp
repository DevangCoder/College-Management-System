
/*
 * To make the student data entry from Admin Portal
 * To authenticathe the login of both profile(students and faculties)
 * To help both profile users to recover the password
 * Allow the student to add a new subject in his profile.
 * Allow the student to delete a subject from his profile.
 * Allow the student to modify the personal profile details.
 * Alow the admin to make a new entry of the faculty user.
 * To display all the student records to admin.
 * To display all the faculty records to admin.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <fstream>
#include <ios>
#include <limits>

using namespace std;

char userName[15];

/*
 * To maintain the student and faculty profile
 * It provide the unique login to both profile users, and allows them to update their record further.
*/
class Admin
{
    char name[30];
    int totalSubjects;
    char subject[10][10];
    char mobile[12], mail[50], fatherName[30], password[30], recoveryPassowrd[10];

public:
    char rollNo[15];

    /*
     *This function is used to input the student data entry from the admin portal
     *All the record entries of student are made by this method
    */
    void setStudentData()
    {
        cout << "\nEnter Student Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(name, 30);

        cout << "\nEnter Student Id/RollNo : ";
        cin >> rollNo;

        cout << "\nEnter Student Father's Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To clear the input buffer. used after every cin for using getline
        cin.getline(fatherName, 30);

        cout << "\nEnter Mobile Number : ";
        cin >> mobile;

        cout << "\nEnter the E-mail id : ";
        cin >> mail;

        cout << "\nEnter the total subject : ";
        cin >> totalSubjects;

        for (int i = 0; i < totalSubjects; i++)
        {
            cout << "\nEnter the SUbject " << i + 1 << " Name : ";
            cin >> subject[i];
        }

        cout << "\nCreate your login password : ";
        cin >> password;

        cout << "\nEnter the unique keyword to recover password : ";
        cin >> recoveryPassowrd;

        cout << "\n\nPlease note your username is ID/Rollno. \n";
    }

    /*
     *This function display all the relevant information to the admin, related
        to the studnets at the admin portals
    */
    void getStudentData()
    {
        cout << "\nStudent Name          : " << name;

        cout << "\nStudent ID/Rollno.    : " << rollNo;

        cout << "\nStudent Father Name   : " << fatherName;

        cout << "\nStudent Mobile Number : " << mobile;

        cout << "\nStudent E-mail ID     : " << mail;

        cout << "\nStudent Subjects      : " << totalSubjects;

        for (int i = 0; i < totalSubjects; i++)
        {
            cout << "\n\tSubject " << i + 1 << " : " << subject[i];
        }

        if (totalSubjects == 0)
        {
            cout << "None SUbject specified...";
        }
    }

    /*
     *this function display the student profile at the student portal
    */
    int showStudentProfile()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nName : " << name;

            cout << "\nFather's Name : " << fatherName;

            cout << "\nMobile Number : " << mobile;

            cout << "\nE-mail id : " << mail;
            return 1;
        }
        return 0;
    }

    /*
     *this function displays the different enrolled subjects 
        of the respective students according to their profile
    */
    int getStudentSubjects()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nStudent total subjects : " << totalSubjects;

            for (int i = 0; i < totalSubjects; i++)
            {
                cout << "\n\tSubject " << i + 1 << " : " << subject[i];
            }
            return 1;
        }
        return 0;
    }

    /*
     *this function allows the student to add subjects in total subjects of the student profile
    */
    void addStudentSubject()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nEnter the new subject : ";
            cin >> subject[totalSubjects++];

            cout << "\n\nNew Subject added successfully....";
        }
    }

    void deleteStudentSubject()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            getStudentSubjects();

            if (totalSubjects <= 0)
            {
                totalSubjects = 0;

                cout << "\nNone subjects exist...";

                exit(0);
            }

            cout << "\nEnter the subject no to delete : ";
            int subNum;
            cin >> subNum;

            if (subNum > totalSubjects || subNum < 1)
            {
                cout << "Invalid input..";
                return;
            }
            else if (subNum == totalSubjects)
            {
                totalSubjects--;

                strcpy(subject[totalSubjects], " ");
            }
            else if (totalSubjects == 1)
            {
                totalSubjects = 0;

                strcpy(subject[totalSubjects], " ");
            }
            else
            {
                subNum--;

                for (int i = 0; i < totalSubjects - 1; i++)
                {
                    strcpy(subject[i], subject[i + 1]);
                }

                totalSubjects--;
            }
            cout << "\n\nRecord updated successfully....";
        }
    }

    void modifyStudentProfile()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nProfile details are :-";

            cout << "\n 1. Student E-mail : " << mail;

            cout << "\n 2. Student Mobile Number : " << mobile;

            cout << "\n\nEnter the Detail Number to be modified : ";
            int num;
            cin >> num;

            if (num == 1)
            {
                char newMail[50];

                cout << "\nEnter the new E-mail id : ";
                cin >> newMail;

                strcpy(mail, newMail);

                cout << "\nRecord Updated Successfully...";
            }
            else if (num == 2)
            {
                char newMobile[12];
                cout << "\nEnter the new Mobile Number : ";
                cin >> newMobile;

                strcpy(mobile, newMobile);

                cout << "\nRecord Updated Successfully...";
            }
            else
            {
                cout << "\nInvalid input provided";
            }
        }
    }

    /*
     *This function allow the ADMIN to make a new record entry for the different new faculties.
     *New faculty records are updated with the help of these functions.
    */
    void setFacultyData()
    {
        cout << "\nEnter the Faculty Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // To clear the input buffer
        cin.getline(name, 30);

        cout << "\nEnter the Faculty Id/RollNo. : ";
        cin >> rollNo;

        cout << "Enter the Faculty's Father Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //to clear the input buffer
        cin.getline(fatherName, 30);

        cout << "Enter the Mobile No. : ";
        cin >> mobile;

        cout << "Enter the E-mail id : ";
        cin >> mail;

        cout << "Enter the total subjects : ";
        cin >> totalSubjects;

        for (int i = 0; i < totalSubjects; i++)
        {
            cout << "\nEnter the Subject " << i + 1 << " Name : ";
            cin >> subject[i]; //No space between the words of the subject
        }

        cout << "\nCreate Your Login Password : ";
        cin >> password;

        cout << "\nEnter the unique keyword to recover the password : ";
        cin >> recoveryPassowrd;

        cout << "\n\nPlease note your UserName is ID/Roll no.\n";
    }

    /*
     *This function displays all the relevant information to the admin, related
        to the faculty at the Admin Portal 
    */
    void getFacultyData()
    {
        cout << "\nFaculty Name          : " << name;

        cout << "\nFaculty Id/Roll no.   : " << rollNo;

        cout << "\nFaculty's Father Name : " << fatherName;

        cout << "\nFaculty Mobile Number : " << mobile;

        cout << "\nFaculty E-mail id     : " << mail;

        cout << "\nFaculty Subjects      : " << totalSubjects;

        for (int i = 0; i < totalSubjects; i++)
        {
            cout << "\n\tSubject " << i + 1 << " :" << subject[i];
        }
        if (totalSubjects == 0)
        {
            cout << "None Subject Specified...";
        }
    }

    /*
     *This function authenticates the login of both the students & faculties
     *With their refrence to there unique ID/PASSWORD, login is provided
    */
    int login()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nEnter the Login Password : ";
            char inputPassword[30];
            cin >> inputPassword;

            if (strcmp(inputPassword, password) == 0)
            {
                return 1;
            }
        }
        return 0;
    }

    /*
     *This function help both the students & faculties to recover the password with
        the help of unique keyword provided by the Admin
    */
    int recover()
    {
        char key[10];
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nEnter the unique keyword (Provided by the admin) : ";
            cin >> key;

            if (strcmp(key, recoveryPassowrd) == 0)
            {
                cout << "\nYou are a valid user.";

                cout << "\nYour Password is " << password;

                cout << "\nPlease exit to login again";

                return 1;
            }
        }
        return 0;
    }

    /*
     *This function displays the different subjects of the faculty at their respective portal.
    */
    int showFacultyProfile()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nFaculty Name           : " << name;

            cout << "\nFaculty Father's Name  : " << fatherName;

            cout << "\nFaculty Mobile Number. : " << mobile;

            cout << "\nFaculty E-Mail id      : " << mail;

            return 1;
        }
        return 0;
    }

    /*
     *This function displays the different subjects of the faculty at their respective portals
    */
    int getFacultySubjects()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nFaculty Subjects : " << totalSubjects;

            for (int i = 0; i < totalSubjects; i++)
            {
                cout << "\n\tSubject " << i + 1 << " Name : " << subject[i];
            }
            return 1;
        }
        return 0;
    }

    // this function helps a faculty to add a subject in their profile
    void addFacultySubject()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nEnter the New Subject : ";
            cin >> subject[totalSubjects++];

            cout << "\n\nNew Subject Added successfully....";
        }
    }

    // this function helps a faculty to delete a subject from their profile
    void deleteFacultySubject()
    {
        getFacultySubjects();

        if (strcmp(::userName, rollNo) == 0)
        {
            if (totalSubjects <= 0)
            {
                totalSubjects = 0;

                cout << "\n None Subjects exist...";

                exit(0);
            }

            cout << "\nEnter the subject No. to be deleted : ";
            int subNumber;
            cin >> subNumber;

            if (subNumber > totalSubjects || subNumber < 1)
            {
                cout << "\nWrong input";
                return;
            }
            else if (subNumber == totalSubjects)
            {
                totalSubjects--;
                strcpy(subject[totalSubjects], " ");
            }
            else if (totalSubjects == 1)
            {
                totalSubjects = 0;
                strcpy(subject[totalSubjects], " ");
            }
            else
            {
                subNumber--;

                for (int s = subNumber; s < totalSubjects - 1; s++)
                {
                    strcpy(subject[s], subject[s + 1]);
                }
                totalSubjects--;
            }
            cout << "\nRecords updated successfully....";
        }
    }

    // this function helps facluty to modify his personal profile
    void modifyFacultyProfile()
    {
        if (strcmp(::userName, rollNo) == 0)
        {
            cout << "\nThe Profile Details are : ";

            cout << "\n 1. Faculty E-Mail : " << mail;

            cout << "\n 2. Mobile         : " << mobile;

            cout << "\nEnter the Detail No. to be modified : ";
            int num;
            cin >> num;
            if (num == 1)
            {
                char newMail[50];

                cout << "\nEnter new E-mail Id : ";
                cin >> newMail;

                strcpy(mail, newMail);

                cout << "\nRecord Updated successfully...";
            }
            else if (num == 2)
            {
                char newMobile[12];

                cout << "\nEnter the new mobile number : ";
                cin >> newMobile;

                strcpy(mobile, newMobile);

                cout << "Record Updated Successfully....";
            }
            else
            {
                cout << "\nWrong Input provided";
            }
        }
    }
} a, f;

int main()
{
    system("clear");

    cout << "\n\n\n\t\t\tWelcome to Amity Database Portal";
    cout << "\n\n\n\t\t\tEnter to continue";
    getchar();

    system("clear");

    // choices for the first menu
    cout << "\n\n\n\t\t\tPress 1 for Admin Portal";

    cout << "\n\t\t\tPress 2 for Fauclty Poratl";

    cout << "\n\t\t\tPress 3 for Student Poratl";

    cout << "\n\n\t\t\tEnter your chocice : ";
    int ch;
    cin >> ch;

    system("clear");

    // Begin of Admin Portal
    if (ch == 1)
    {
        string adminUser, adminPassword;

        cout << "\n\t\t\tWelcome to Admin Portal";

        cout << "\n\nEnter the user name : ";
        cin >> adminUser;

        cout << "\nEnter the password : ";
        cin >> adminPassword;

        // authenticating the admin with username : "admin" and password : "password"
        if (adminUser.compare("admin") != 0 && adminPassword.compare("pass") != 0)
        {
            cout << "\n\n\t\t\t Invalid Access to portal";
            cout << "\n\n\t\t\t Thank you !!!";

            // exiting the program if authentication fails
            exit(0);
        }
        else
        {

            char opera = 'y';
            do
            {
                system("clear");

                // menu for admin after successful login

                cout << "\n\t\t\tWelcome to Admin Panel";

                cout << "\n\nPress 1 to Add a faculty falculty record ";

                cout << "\nPress 2 to Add multiple records of the faculty";

                cout << "\nPress 3 to View of all the Records of the Faculty";

                cout << "\nPress 4 to Delete the faculty record";

                cout << "\nPress 5 to Add student record";

                cout << "\nPress 6 to Add multiple records of students";

                cout << "\nPress 7 to View all records of students";

                cout << "\nPress 8 to Delete a student record";

                cout << "\nPress 9 to Exit";

                cout << "\n\n\tEnter your choice : ";
                int temp;
                cin >> temp;

                system("clear");

                // for inserting the single faculty record
                if (temp == 1)
                {
                    cout << "\nEnter the Details :- ";

                    fstream fs;
                    fs.open("fainfo.txt", ios::out | ios::app);

                    a.setFacultyData();

                    fs.write((char *)&a, sizeof(a));
                    fs.close();

                    cout << "\nRecord Entered Successfult...";
                }

                // for inserting multiple faculty records
                else if (temp == 2)
                {
                    int m = 1;

                    fstream fs;
                    fs.open("fainfo.txt", ios::out | ios::app);
                    do
                    {
                        cout << "\nEnter the details :-";

                        a.setFacultyData();

                        fs.write((char *)&a, sizeof(a));

                        cout << "Press 1 If you want to enter more records : ";
                        cin >> m;
                    } while (m == 1);

                    fs.close();

                    cout << "\nRecord Entered Successfully...";
                }

                // to view all the records of the faculty
                else if (temp == 3)
                {
                    system("clear");
                    fstream fs;
                    fs.open("fainfo.txt", ios::in);
                    fs.seekg(0);

                    while (fs.read((char *)&a, sizeof(a)))
                    {
                        a.getFacultyData();
                    }

                    fs.close();
                }

                // to delete a faculty record
                else if (temp == 4)
                {
                    string tempFacultyId;
                    int del = 0;

                    cout << "\nEnter the faculty ID/Roll no. : ";
                    cin >> tempFacultyId;

                    system("clear");

                    fstream fs, fs1;

                    fs.open("fainfo.txt", ios::in);
                    fs1.open("fa_new_info.txt", ios::out | ios::app);

                    while (fs.read((char *)&a, sizeof(a)))
                    {
                        //if record matches
                        if (tempFacultyId.compare(a.rollNo) == 0)
                        {
                            del = 1;
                        }
                        else
                        {
                            fs1.write((char *)&a, sizeof(a));
                        }
                    }
                    if (del == 1)
                    {
                        cout << "\nRecord Deleted Successfully....";
                    }
                    else
                    {
                        cout << "\nRecord not found...";
                    }

                    fs.close();
                    fs1.close();

                    remove("fainfo.txt");
                    rename("fa_new_info.txt", "fainfo.txt");
                }

                // to add a single student record
                else if (temp == 5)
                {
                    cout << "\nEnter the details :-";

                    fstream fs;
                    fs.open("stinfo.txt", ios::out | ios::app);

                    a.setStudentData();

                    fs.write((char *)&a, sizeof(a));
                    fs.close();

                    cout << "\nRecord Entered Successfully...";
                }

                // for multiple student record entry
                else if (temp == 6)
                {
                    int m = 1;

                    fstream fs;
                    fs.open("stinfo.txt", ios::out | ios::app);

                    do
                    {
                        cout << "\nEnter the Details :-";

                        a.setStudentData();

                        fs.write((char *)&a, sizeof(a));

                        cout << "\nPress 1 if you want to enter more records : ";
                        cin >> m;

                    } while (m == 1);

                    fs.close();

                    cout << "\nRecord Entered Successfully...";
                }

                // to view all the student record
                else if (temp == 7)
                {
                    fstream fs;
                    fs.open("stinfo.txt", ios::in);
                    fs.seekg(0);

                    while (fs.read((char *)&a, sizeof(a)))
                    {
                        a.getStudentData();
                    }

                    fs.close();
                }

                // to delete a student record
                else if (temp == 8)
                {
                    string tempStudentId;
                    int del = 0;

                    cout << "Enter the student Id/roll No : ";
                    cin >> tempStudentId;

                    fstream fs, fs1;

                    fs.open("stinfo.txt", ios::in);
                    fs1.open("stnewinfo.txt", ios::out | ios::app);

                    while (fs.read((char *)&a, sizeof(a)))
                    {
                        // if record matches
                        if (tempStudentId.compare(a.rollNo) == 0)
                        {
                            del = 1;
                        }
                        else
                        {
                            fs1.write((char *)&a, sizeof(a));
                        }
                    }

                    if (del == 1)
                    {
                        cout << "\nRecord Deleted Successfully....";
                    }
                    else
                    {
                        cout << "\nRecord not found...";
                    }

                    fs.close();
                    fs1.close();

                    remove("stinfo.txt");
                    rename("stnewinfo.txt", "stinfo.txt");
                }

                else if (temp == 9)
                {
                    cout << "\n\n\n\n\t\t\t\tThank You!!!";
                    exit(0);
                }
                else
                {
                    cout << "\n\n\n\t\t\tInvalid Choice!!!!!";
                }

                cout << "\n\nPress y for more operations otherwiese n : ";
                cin >> opera;

            } while (opera == 'y' || opera == 'Y');
        }
    }

    // begin of faculty view portal
    else if (ch == 2)
    {
        system("clear");

        int s = 0;

        cout << "\n\t\t\tWelcome to Faculty Login Page ";

        cout << "\n\nEnter the username : ";
        cin >> ::userName;

        fstream fs;
        fs.open("fainfo.txt", ios::in | ios::binary);
        fs.seekg(0);

        int val;

        // authenticating the faculty
        while (fs.read((char *)&f, sizeof(f)))
        {
            val = -1;
            val = f.login();
            if (val == 1)
            {
                s = 1;
                break;
            }
        }
        fs.close();

        // if first login is invalid
        if (s != 1)
        {
            system("clear");

            cout << "\n\n\t\tLogin Credentials are In-Correct!!!";

            cout << "\n\nThe username is your ID/Rollno";

            cout << "\nThe password is Case Sensitive";

            cout << "\nPress 1 to Recover Password";

            cout << "\nPress 2 to for Last Attemp";

            cout << "\nEnter your choice : ";
            int choice;
            cin >> choice;

            // password recovery
            if (choice == 1)
            {
                cout << "\nEnter the username : ";
                cin >> ::userName;

                int re, su = -1;

                fstream fs;
                fs.open("fainfo.txt", ios::in | ios::binary);
                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    re = -1;
                    re = f.recover();

                    if (re == 1)
                    {
                        su = 1;
                        break;
                    }
                }

                fs.close();

                if (su == 1)
                {
                    cout << "\n\n\n\n\t\tThank You!!!";
                }
                else
                {
                    cout << "\nYou are a invalid user.";
                }
                exit(0);
            }

            // re-attempt of login
            else if (choice == 2)
            {
                cout << "\n\nEnter the username : ";
                cin >> ::userName;

                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);
                int valu, suc = -1;
                while (fs.read((char *)&f, sizeof(f)))
                {
                    valu = -1;
                    valu = f.login();

                    if (valu == 1)
                    {
                        suc = 1;
                        break;
                    }
                }

                fs.close();

                if (suc != 1)
                {
                    cout << "\nYou are an Invalid User...";

                    cout << "\nThank You!!!";

                    exit(0);
                }
            }
            else
            {
                cout << "\n\nInvalid Input provided.";

                cout << "\n\n\t\tThank You !!!";

                exit(0);
            }
        }

        // if login is successfull
        char con = 'y';
        do
        {
            system("clear");

            cout << "\n\n\t\t\tWelcome to Faculty Panel";

            cout << "\n\n\t\t\t\t\t\tYour userid is : " << ::userName;

            cout << "\n\nPress 1 to view your profile.";

            cout << "\nPress 2 to know your subjects.";

            cout << "\nPress 3 to add a subbject.";

            cout << "\nPress 4 to delete a subject.";

            cout << "\nPress 5 to modify profile";

            cout << "\n\nEnter your choice : ";
            int choice;
            cin >> choice;

            // faculty can view the profile
            if (choice == 1)
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in);

                int x;

                while (fs.read((char *)&f, sizeof(f)))
                {
                    x = 0;
                    x = f.showFacultyProfile();

                    if (x == 1)
                    {
                        break;
                    }
                }

                fs.close();
            }

            // faculty can see the subjects
            else if (choice == 2)
            {
                int y;
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    y = 0;
                    y = f.getFacultySubjects();

                    if (y == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }

            // adding a new subject
            else if (choice == 3)
            {
                fstream fs, fs1;

                fs.open("fainfo.txt", ios::in);
                fs1.open("tempfainfo.txt", ios::out | ios::app);
                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    f.addFacultySubject();
                    fs1.write((char *)&f, sizeof(f));
                }
                fs.close();
                fs1.close();

                remove("fainfo.txt");
                rename("tempfainfo.txt", "fainfo.txt");
            }

            // to delete a subject
            else if (choice == 4)
            {
                fstream fs, fs1;

                fs.open("fainfo.txt", ios::in);
                fs1.open("delfainfo.txt", ios::out | ios::app);

                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    f.deleteFacultySubject();
                    fs1.write((char *)&f, sizeof(f));
                }

                fs.close();
                fs1.close();

                remove("fainfo.txt");
                rename("delfainfo.txt", "fainfo.txt");
            }

            // to modify profile of faculty
            else if (choice == 5)
            {
                fstream fs, fs1;

                fs.open("fainfo.txt", ios::in);
                fs1.open("modfainfo.txt", ios::out | ios::app);

                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    f.modifyFacultyProfile();
                    fs1.write((char *)&f, sizeof(f));
                }
                fs.close();
                fs1.close();

                remove("fainfo.txt");
                rename("modfainfo.txt", "fainfo.txt");
            }

            else
            {
                cout << "\nInvalid input provided!!!";
            }

            cout << "\n\nPress y to continue otherwise n : ";
            cin >> con;
        } while (con == 'y' || con == 'Y');
    }

    // begin of student view
    else if (ch == 3)
    {
        system("clear");

        int value, s1 = 0;

        cout << "\n\t\t\tWelcome to Student Login Page";

        cout << "\n\nEnter the username : ";
        cin >> ::userName;

        fstream fs;
        fs.open("stinfo.txt", ios::in);
        fs.seekg(0);

        while (fs.read((char *)&f, sizeof(f)))
        {
            value = -1;
            value = f.login();
            if (value == 1)
            {
                s1 = 1;
                break;
            }
        }

        if (s1 != 1)
        {
            system("clear");

            cout << "\n\n\t\tYour Login credentials are In-Correct";

            cout << "\n\nThe username is your ID/Rollno";

            cout << "\nThe password is Case Sensitive";

            cout << "\nPress 1 to Recover Password";

            cout << "\nPress 2 to for Last Attemp";

            cout << "\nEnter your choice : ";
            int choice;
            cin >> choice;

            // password recovery
            if (choice == 1)
            {
                cout << "\nEnter the username : ";
                cin >> ::userName;

                int re, su = -1;

                fstream fs;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    re = -1;
                    re = f.recover();

                    if (re == 1)
                    {
                        su = 1;
                        break;
                    }
                }

                fs.close();

                if (su == 1)
                {
                    cout << "\n\n\n\n\t\tThank You!!!";
                }
                else
                {
                    cout << "\nYou are a invalid user.";
                }
                exit(0);
            }

            // re-attempt of login
            else if (choice == 2)
            {
                cout << "\n\nEnter the username : ";
                cin >> ::userName;

                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);

                int valu, suc = -1;

                while (fs.read((char *)&f, sizeof(f)))
                {
                    valu = -1;
                    valu = f.login();

                    if (valu == 1)
                    {
                        suc = 1;
                        break;
                    }
                }

                fs.close();

                if (suc != 1)
                {
                    cout << "\nYou are an Invalid User...";

                    cout << "\nThank You!!!";

                    exit(0);
                }
            }
            else
            {
                cout << "\n\nInvalid Input provided.";

                cout << "\n\n\t\tThank You !!!";

                exit(0);
            }
        }

        // begin of student pannel after successful login

        char moreOp = 'y';
        do
        {
            system("clear");

            cout << "\n\n\t\t\tWelcome to student pannel";

            cout << "\n\n\t\t\t\t\t\tYour user id is : " << ::userName;

            cout << "\n\nPress 1 to view your profile";

            cout << "\nPress 2 to know your subjects.";

            cout << "\nPress 3 to add a subject.";

            cout << "\nPress 4 to delete subject.";

            cout << "\nPress 5 to modify your profile.";

            cout << "\n\nEnter your choice : ";
            int choice;
            cin >> choice;

            // to view the profile
            if (choice == 1)
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);

                int x;

                while (fs.read((char *)&f, sizeof(f)))
                {
                    x = 0;
                    x = f.showStudentProfile();
                    if (x == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }

            // to know student subjects
            else if (choice == 2)
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);

                int x;

                while (fs.read((char *)&f, sizeof(f)))
                {
                    x = 0;
                    x = f.getStudentSubjects();
                    if (x == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }

            else if (choice == 3)
            {
                fstream fs, fs1;

                fs.open("stinfo.txt", ios::in);
                fs1.open("tempstinfo.txt", ios::out | ios::app);

                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    f.addStudentSubject();
                    fs1.write((char *)&f, sizeof(f));
                }

                fs.close();
                fs1.close();

                remove("stinfo.txt");
                rename("tempstinfo.txt", "stinfo.txt");
            }

            // to delete a student subject
            else if (choice == 4)
            {
                fstream fs, fs1;

                fs.open("stinfo.txt", ios::in);
                fs1.open("delstinfo.txt", ios::out | ios::app);

                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    f.deleteStudentSubject();
                    fs1.write((char *)&f, sizeof(f));
                }

                fs.close();
                fs1.close();

                remove("stinfo.txt");
                rename("delstinfo.txt", "stinfo.txt");
            }

            // to modify the student profile
            else if (choice == 5)
            {
                fstream fs, fs1;
                fs.open("stinfo.txt", ios::in);
                fs1.open("modstinfo.txt", ios::out | ios::app);

                fs.seekg(0);

                while (fs.read((char *)&f, sizeof(f)))
                {
                    f.modifyStudentProfile();
                    fs1.write((char *)&f, sizeof(f));
                }

                fs.close();
                fs1.close();

                remove("stinfo.txt");
                rename("modstinfo.txt", "stinfo.txt");
            }
            else
            {
                cout << "\nInvalid Input provided...";
            }

            cout << "\npress y to continue otherwise n : ";
            cin >> moreOp;
        } while (moreOp == 'y' || moreOp == 'Y');
    }
    else
    {
        cout << "Invalid Input provided !!!";
        system("clear");
        cout << "\n\n\n\t\t\tThank You\n\n";
    }
    return 0;
}

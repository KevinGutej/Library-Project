#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>


using namespace std;

struct book
{

    string title;
    string author;
    string premier_date;
    int number_of_pages;
    int number_of_available;
    int number_of_taken;

};

void input_error()
{
    cin.clear();
    cin.ignore();
}
void menu()
{
    cout << " [1] - Display data base " << endl;
    cout << " [2] - Display specific record " << endl;
    cout << " [3] - Enter data " << endl;
    cout << " [4] - Delete data " << endl;
    cout << " [5] - Edit data " << endl;
    cout << " [6] - Export data base to file " << endl;
    cout << " [7] - Import data base from file " << endl;
    cout << " [8] - Exit the program " << endl;
}

void space()
{
    cout << endl;
    cout << endl;
}

void line()
{
    cout << "====================================" << endl;
}

void option1(vector<book>&library)
{
    Sleep(1000);
    cout << "Displaying all data..." << endl;
    space();
    if(library.size()==0)
    {
        cout << "It appears that data base is empty..." << endl;
    }
    if(library.size()!=0)cout << "DATA BASE RECORDS: " << endl;
    Sleep(950);
    space();
    for(int i=0; i<library.size(); i++)
    {
        cout << "Record number: " << i << endl;
        line();
        space();
        Sleep(450);
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Premier date: " << library[i].premier_date << endl;
        cout << "Number of pages: " << library[i].number_of_pages << endl;
        cout << "Number of available: " << library[i].number_of_available << endl;
        cout << "Number of taken: " << library[i].number_of_taken << endl;
        space();
        system("pause");


    }
}

void option2(vector<book>&library, int &specific_record_number)
{
    cout << "Working..." << endl;
    Sleep(800);
    cout << "[INFO] Number of all records is: " << library.size() << endl;
    space();
    Sleep(600);
    cout << "Checking if your number is valid..." << endl;
    space();
    Sleep(1250);
    for(;;)
    {

        Sleep(900);
        if(specific_record_number>=0&&specific_record_number<=library.size())break;
        cout << "Wrong number! You number is not in range of the wanted value!" << endl;
        cout << "Enter again: ";
        cin >> specific_record_number;
        space();

    }
    cout << "Data base record of your number is available!" << endl;
    space();
    Sleep(500);
    cout << "Record number: " << specific_record_number << endl;
    line();
    space();
    Sleep(650);
    cout << "Title: " << library[specific_record_number].title << endl;
    cout << "Author: " << library[specific_record_number].author << endl;
    cout << "Premier date: " << library[specific_record_number].premier_date << endl;
    cout << "Number of pages: " << library[specific_record_number].number_of_pages << endl;
    cout << "Number of available: " << library[specific_record_number].number_of_available << endl;
    cout << "Number of taken: " << library[specific_record_number].number_of_taken << endl;
    space();
    line();
    Sleep(1000);
    space();
    Sleep(1000);
    system("pause");

}

void option3(vector<book>&library)
{
    for(int i=0; i<library.size(); i++)
     {
        cout << "Enter title: ";
        input_error();
        getline(cin, library[i].title);
        cout << "Enter author: ";
        getline(cin, library[i].author);
        cout << "Enter premier date: ";
        getline(cin, library[i].premier_date);
        cout << "Enter number of pages: ";
        cin >>  library[i].number_of_pages;
        cout << "Enter number of available: ";
        cin >>  library[i].number_of_available;
        cout << "Number of taken: ";
        cin >>  library[i].number_of_taken;
     }
}

void option4(vector<book>&library, int &help_d)
{
    cout << "Enter the record you want to erase: ";
    cin >> help_d;
    cout << "Working..." << endl;
    Sleep(1250);
    library.erase(library.begin() + help_d);
    system("pause");
}

void option5(vector<book>&library,int &help_e)
{
    cout << "[1] - Title " << endl;
    cout << "[2] - Author " << endl;
    cout << "[3] - Premier date " << endl;
    cout << "[4] - Number of pages " << endl;
    cout << "[5] - Number of available " << endl;
    cout << "[6] - Number of taken " << endl;
    Sleep(250);
    space();
    int s;
    cout << "Enter which specific data would you like to edit: ";
    cin >> s;
    space();
    Sleep(250);
    for(;;)
        {
            if(s < 1 || s > 6)
                {
                    Sleep(500);
                    cout << "Error! That number is not avaiable" << endl;
                    space();
                    cout << "Please enter another number: " << endl;
                    cin >> s;
                    space();
                    Sleep(500);
                }
            else
                {
                    break;
                }
        }
    switch(s)
    {
        case 1:
            {
                Sleep(500);
                cout << "Editing title..." << endl;
                space();
                cout << "Enter new title: ";
                input_error();
                getline(cin, library[help_e].title);
                space();
                Sleep(500);
            }
        break;
         case 2:
            {
                Sleep(500);
                cout << "Editing author..." << endl;
                space();
                cout << "Enter new author: ";
                input_error();
                getline(cin, library[help_e].author);
                space();
                Sleep(500);
            }
        break;
        case 3:
            {
                Sleep(500);
                cout << "Editing premier date..." << endl;
                space();
                cout << "Enter new premier date: ";
                input_error();
                getline(cin, library[help_e].premier_date);
                space();
                Sleep(500);

            }
        break;
        case 4:
            {
                Sleep(500);
                cout << "Editing number of pages..." << endl;
                space();
                cout << "Enter new number of pages: ";
                input_error();
                cin >>  library[help_e].number_of_pages;
                space();
                Sleep(500);
            }
        break;
        case 5:
            {
                Sleep(500);
                cout << "Editing number of available..." << endl;
                space();
                cout << "Enter new number of available: ";
                input_error();
                cin >>  library[help_e].number_of_available;
                space();
                Sleep(500);
            }
        break;
        case 6:
            {
                Sleep(500);
                cout << "Editing number of taken..." << endl;
                space();
                cout << "Enter new number of taken: ";
                input_error();
                cin >>  library[help_e].number_of_taken;
                space();
                Sleep(500);
            }
        break;
            }

    }



void option6(vector<book>&library, fstream &file, string &file_name)
{
    cout << "Your data is being exported now to the file now..." << endl;
    Sleep(950);
    file.open(file_name, ios::out);
    {
        for(int i=0;i<library.size();i++)
        {
            file << "Record number: " << i << endl;
            file << "Title: " << library[i].title << endl;
            file<< "Author: " << library[i].author << endl;
            file << "Premier date: " << library[i].premier_date << endl;
            file << "Number of pages: " << library[i].number_of_pages << endl;
            file << "Number of available: " << library[i].number_of_available << endl;
            file << "Number of taken: " << library[i].number_of_taken << endl;
            file << "======================================" << endl;

        }
    file.close();
    Sleep(700);
    cout << "Work in progress..." << endl;
    Sleep(1000);
    cout << "Your data has been exported successfully" << endl;
    }
    system("pause");


}
void option8()
{
    cout << "Exiting the library program..." << endl;
    Sleep(900);
    space();
    system("pause");
    Sleep(900);
    exit(0);
    space();

}
int main()
{
    vector<book>library(3);
    fstream file;
    string file_name;
    int help_d , x, help_e;
    library[0]={"Harry Potter","J.K.Rowling","18/01/2002",700,1200,800};
    library[1]={"Lord of The Rings: The Fellowship of The Ring","J.R.R.Tolkien","12/05/1990",100,1500,33};
    library[2]={"The Dairy of the Wimpy","Jeff Kinney","05/12/2007",120,30,0};
    //cout << "Title is: " << library[0].title << endl; // wtf?!
    int menu_choice_number, specific_record_number; // for switch-case funtionality & for option2 functionality
    for(;;)
    {
        cout << "WELCOME IN LIBRARY PROGRAM!" << endl;
        space();
        line();
        menu();
        line();
        space();
        cout << "PLEASE CHOOSE A OPTION FROM 1 TO 7" << endl;
        Sleep(950);
        cout << "Your choice: ";
        cin >> menu_choice_number; // for switch-case funtionality
        Sleep(650);
        cout << "You have chosen option number: " << menu_choice_number << endl;
        Sleep(450);
        cout << "Executing..." << endl;
        Sleep(1050);
        switch(menu_choice_number)
        {
                case 1:
                {
                    option1(library);
                    space();
                    system("pause");

                }
                    break;

                case 2:
                {
                    space();
                    cout << "Enter specific record number: ";
                    cin >> specific_record_number;
                    option2(library,specific_record_number);
                    system("pause");

                }
                    break;

                case 3:
                {
                    space();
                    int x;
                    cout << "How many elements you'd like to enter: ";
                    cin >> x;
                    library.resize(library.size()+x);
                    option3(library);
                    system("pause");

                }
                    break;

                case 4:
                {
                    space();
                    option4(library,help_d);

                }
                    break;

                case 5:
                {
                    space();
                    cout << "Please enter record number you would like to edit: ";
                    space();
                    Sleep(250);
                    cin >> help_e;
                    Sleep(250);
                    for(;;)
                    {
                        if(help_e > library.size())
                        {

                            cout << "Error! That number is not avaiable" << endl;
                            space();
                            cout << "Please enter another number: " << endl;
                            cin >> help_e;
                            space();
                            Sleep(250);
                        }
                        else
                        {
                            break;
                        }
                    }
                    option5(library,help_e);
                    space();
                }
                    break;

                case 6:
                {
                    cout << "Please enter the name of the file" << endl;
                    input_error();
                    getline(cin, file_name);
                    option6(library, file, file_name);
                    space();

                }
                    break;

                case 7:
                {
                    space();
                }
                    break;

                case 8:
                {
                    space();
                    option8();

                }
                    break;

        }
    }
}

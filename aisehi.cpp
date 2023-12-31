#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Person
{
    string name;
    string surename;
    short age;
    string telephone;
};
short peopleInDataBase;
Person people[20];
void requireEnter();
void addPerson();
void showpeople();
void savepeopletofile();
void loadpeople();
void searchdatabase();
void removeperson();

int main(){

    char test;
do
{
cout<< "Number of people in Database: "<< peopleInDataBase <<endl;
cout<< "MENU" <<endl;

cout<< "1. ADD PERSON" <<endl;
cout<<"2. show all people" <<endl;
cout<< "3. SAVE TO FILE--" <<endl;
cout<< "4. LOAD FROM FILE--" <<endl;
cout<< "5. Searching someone??" <<endl;
cout<< "6. REMOVE SOMEONE" <<endl;


cout<<endl;
test = getch();

switch(test){
case '1':
   addPerson();
    break;
case '2':
    showpeople();
    break;
case '3':
    savepeopletofile();
    break;
case '4':
    loadpeople();
    break;
case '5':
searchdatabase();
break;

case '6':
removeperson();
break;
}

requireEnter();

system("cls");

} while(test !=27);

return 0;}

void requireEnter(){

cout<<"click to erase" <<endl;
while(getch() != 13);

}

void addPerson()
{
 cout<< "TYPE NAME:";
 cin>> people[peopleInDataBase].name;

 cout<< "TYPE SURENAME:";
 cin>> people[peopleInDataBase].surename;

 cout<< "TYPE AGE:";
 cin>> people[peopleInDataBase].age;

 cout<< "TYPE TELEPHONE:";
 cin>> people[peopleInDataBase].telephone;

  peopleInDataBase++;
}

void showpeople()
{
    if(peopleInDataBase>0)
    {
       for(int i=0; i<peopleInDataBase; i++)
       {
           cout<< "Person Index:" << (i+1) <<endl;
           cout<< "NAME : " <<people[i].name <<endl;
           cout<< "SURENAME : " <<people[i].surename <<endl;
           cout<< "AGE : " <<people[i].age <<endl;
           cout<< "TELEPHONE : " <<people[i].telephone <<endl<<endl;;

       }
    }
    else
        cout<<"NONONE"<< endl;
}
void savepeopletofile()
{
    ofstream file("database.txt");
    if (file.is_open())
    {
        file << peopleInDataBase << endl;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            file << people[i].name << endl;
            file << people[i].surename << endl;
            file << people[i].age << endl;
            file << people[i].telephone << endl;
        }

        file.close();
    }
    else
        cout << "NOT ABLE TO SAVE" << endl;
}

void loadpeople()
{
    ifstream file("database.txt");
    if (file.is_open())
    {
        file >> peopleInDataBase;

        if (peopleInDataBase > 0)
        {
            for (int i = 0; i < peopleInDataBase; i++)
            {
                file >> people[i].name;
                file >> people[i].surename;
                file >> people[i].age;
                file >> people[i].telephone;
            }
            cout << "people were loaded" << endl;
        }
        else
            cout << "DATA BASE IS EMPTY " << endl;
    }
    else
        cout << "THE FILE DOES NOT EXIST" << endl;
}

void searchdatabase()
{
    if (peopleInDataBase > 0)
    {
        string name;
        cout << "Type the name please!! :";
        cin >> name;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            if (name == people[i].name)
            {
                cout << "Person Index:" << (i + 1) << endl;
                cout << "NAME : " << people[i].name << endl;
                cout << "SURENAME : " << people[i].surename << endl;
                cout << "AGE : " << people[i].age << endl;
                cout << "TELEPHONE : " << people[i].telephone << endl
                     << endl;
            }
        }
    }
    else
        cout << "Nobody Found" << endl;
}

void removeperson()
{
    if(peopleInDataBase >0 )
    {
        short index;
        cout<< "Who is the girl?" <<endl;
        cin >> index ;

        if (peopleInDataBase >= index)
        {
            for ( short k = index; k< peopleInDataBase; k++)
            {
                people[k-1].name = people[k].name;
                people[k-1].surename = people[k].surename;
                people[k-1].age = people[k].age;
                people[k-1].telephone = people[k].telephone;
            }
            peopleInDataBase--;
            savepeopletofile();
        }
        else
            cout << "Please recheck" <<endl;
    }
    else
        cout<<"THERE IS NOTHING " <<endl;
}

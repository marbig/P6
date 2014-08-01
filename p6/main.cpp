#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Tworzenie struktury
struct Users{
    string name;
    string shell;
};

//deklaracja wektora obiektow strukturalnych
vector <Users> user_list;

//funkcja wczytujaca z pliku
void readfile(Users obiekt)
{
    ifstream file;
    file.open("passwd");
    if(!file) cout << "problem!" << endl;

    string str;
    string str1;
    int pos;

    while(file.good())
    {
        if(getline(file, str))
        {
            str1=str;
            pos = str.find(":");
            str.erase(pos);
            obiekt.name = str;
            pos = str1.find("/");
            str1.erase(0,pos);
            obiekt.shell = str1;
            user_list.push_back(obiekt); //dodawanie uzytkownika do wektora
        }

    }
    file.close();

}

//funkcja wyswietlajaca wszystkich uzytkownikow
void show_all()
{
    if(user_list.size()!=0)
    {
        for(unsigned int i=0; i<user_list.size(); i++)
        cout << "user: " << user_list.at(i).name << " shell: " << user_list.at(i).shell << endl;
    }
    else
        cout << "wektor pusty!!" << endl;
}


//funkcja wyswietlajaca pojedynczego, wybranego uzytkownika
void show_unit(unsigned int i)
{
    if(user_list.size()!=0 && i< user_list.size())
        cout << "user: " << user_list.at(i).name << " shell: " << user_list.at(i).shell << endl;

}
int main()
{
    Users obiekt;
    readfile(obiekt);
    show_all();
    show_unit(13);
    return 0;
}

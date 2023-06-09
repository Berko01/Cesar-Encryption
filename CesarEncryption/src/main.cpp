#include <iostream>
#include <vector>
using namespace std;

class Person
{
    string name;
    string surname;
    string cryptoPassword;

public:
    Person() {}
    Person(string name, string surname, string cryptoPassword)
    {
        this->name = name;
        this->cryptoPassword = cryptoPassword;
        this->surname = surname;
    }

    friend void signUp(vector<Person> &v);
    friend void login(vector<Person> &v);
    friend void list(vector<Person> &v);
    friend ostream &operator<<(ostream &out, Person &p);
};

ostream &operator<<(ostream &out, Person &p)
{
    out << "Name: " << p.name << endl
        << "Surname: " << p.surname << endl
        << "CryptoPassword:" << p.cryptoPassword << endl;
    return out;
}

string cesarEncryption(string password, int a)
{ // bu fonksiyon 2 parametre alıcak biri string biri int. int deger 2 olsun ornegin
    // password ahmet olsun int deger 2 deger olursa a alfabede kendinden 2 sonraki harfle degistirilir
    int i = 0;
    char cr;
    string cryptoPassword;

    while (password.length() != i)
    {
        cr = password.at(i);
        cr += a;
        cryptoPassword += cr;
        i++;
    }

    cout << cryptoPassword << endl;
    cout << password << endl;
    return cryptoPassword;
}

void login(vector<Person> &v)
{
    cout << "Isminizi giriniz : ";
    string name;
    cin >> name;
    cout << endl;

    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << endl;
        if ((*i).name == name)
        {
            cout << "Kullaniciya ait isim bilgisi bulundu." << endl;

            cout << "Sifrenizi giriniz : ";
            string password;
            cin >> password;
            string cryptoPassword = cesarEncryption(password, 2);
            if ((*i).cryptoPassword == cryptoPassword)
            {
                cout << "Sifreniz kabul edildi." << endl;
                cout << "Hosgeldiniz." << endl;
                return;
            }
            else
            {
                cout << "Sifreniz yanlis sistemden cikiliyor..." << endl;
                return;
            }
        }
        cout << "Kullanici bulunamadi..." << endl;
        return;
    }
}

void list(vector<Person> &v)
{
    cout << v.size() << endl;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << endl;
    }
}

// uye olma fonku
void signUp(vector<Person> &v)
{

    cout << "Isminizi giriniz : ";
    string name;
    cin >> name;
    cout << endl
         << "Soy isminizi girinizi giriniz : ";
    string surname;
    cin >> surname;
    cout << endl
         << "Sifrenizi giriniz : ";
    string password;
    cin >> password;
    cout << endl;
    password = cesarEncryption(password, 2);

    Person newPerson(name, surname, password);
    v.push_back(newPerson);
    cout << v.size() << endl;
    cout << "Kayit gerceklestirildi." << endl;
}

int main()
{
    vector<Person> People;
    while (true)
    {
        cout << "Kayit sistemine hosgeldiniz...." << endl;
        cout << "___________" << endl;
        cout << "Isleminizi seciniz : " << endl
             << "1 - Uye ol" << endl
             << "2 - Giris yap." << endl
             << "3-Listele." << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            signUp(People);
            break;
        case 2:

            login(People);
            break;
        case 3:
            list(People);
            break;
        }
    }

    system("pause");
    return 0;
}
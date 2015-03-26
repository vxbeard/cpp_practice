#include<iostream>
#include<string>
#include<vector>

using namespace std;

class notebook_record {
private:
    string _name;
    string _surname;
    string _birth_date;
    string _phone;
public:
    notebook_record() : _name(""), _surname(""), _birth_date(""), _phone("") {}
    notebook_record(const string& name, const string& surname, const string& birth_date, const string& phone) :
        _name(name), _surname(surname), _birth_date(birth_date), _phone(phone) {}

    string getBirthDate() const {
        return _birth_date;
    }

    void setBirthDate(const string& birthDate) {
        _birth_date = birthDate;
    }

    string getName() const {
        return _name;
    }

    void setName(const string& name) {
        _name = name;
    }

    string getPhone() const {
        return _phone;
    }

    void setPhone(const string& phone) {
        _phone = phone;
    }

    string getSurname() const {
        return _surname;
    }

    void setSurname(const string& surname) {
        _surname = surname;
    }
};

ostream& operator<<(ostream& out, const notebook_record& record) {
    return out<<"Record-----------------------------------------"<<endl
              <<"Name       : "<<record.getName()<<endl
              <<"Surname    : "<<record.getSurname()<<endl
              <<"Birth date : "<<record.getBirthDate()<<endl
              <<"Phone      : "<<record.getPhone()<<endl
              <<"==============================================="<<endl;
}

class Notebook {
private:
    vector<notebook_record> records;

public:
    Notebook() : records(20) {};

    void addRecord(notebook_record record) {records.push_back(record);}
    void showAll() {
        vector<notebook_record>::const_iterator iter;
        for(iter = records.begin(); iter != records.end(); ++iter) {
            cout<<*iter;
        }
    }
};

notebook_record inputRecord() {
    string name, surname, birth_date, phone;

    cout<<"Enter the name : ";
    cin>>name;
    cout<<endl;

    cout<<"Enter the surname : ";
    cin>>surname;
    cout<<endl;

    cout<<"Enter the birth date : ";
    cin>>birth_date;
    cout<<endl;

    cout<<"Enter the phone number : ";
    cin>>phone;
    cout<<endl;

    return notebook_record(name, surname, birth_date, phone);
}

int main() {
    cout<<notebook_record("TestName", "TestSurname", "TestBirthDate", "TestPhone");

    Notebook notebook;

    char ch = 0;



    while ((ch != 'q') && (ch != 'Q')) {
        cout<<"Chose action:"<<endl
            <<" 1) Add new record"<<endl
            <<" 2) Show all records"<<endl
            <<" 3) Search by..."<<endl
            <<" 4) Sord by..."<<endl
            <<" q) Quit"<<endl;
        cin.get(ch);
        cin.get();

        switch(ch) {
            case '1':
                notebook.addRecord(inputRecord());
                break;
            case '2':
                notebook.showAll();
                break;
            case '3':
                break;
            case '4':
                break;
        }
    }

    return 0;
}

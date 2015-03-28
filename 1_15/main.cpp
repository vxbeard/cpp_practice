#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

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

/*class AbstractNotebookSearch: public unary_function<notebook_record,bool> {
public:
    virtual bool operator() (const notebook_record& r) const = 0;
    virtual ~AbstractNotebookSearch(){}
};*/

class CompareByName: public unary_function<notebook_record,bool> {
private:
    string _key;
public:
    explicit CompareByName(string s) : _key(s) {}
    bool operator() (const notebook_record& r) const {return r.getName() == _key;}
};

class CompareBySurname: public unary_function<notebook_record,bool> {
private:
    string _key;
public:
    explicit CompareBySurname(string s) : _key(s) {}
    bool operator() (const notebook_record& r) const {return r.getSurname() == _key;}
};

class CompareByBirthDate: public unary_function<notebook_record,bool> {
private:
    string _key;
public:
    explicit CompareByBirthDate(string s) : _key(s) {}
    bool operator() (const notebook_record& r) const {return r.getBirthDate() == _key;}
};

class CompareByPhone: public unary_function<notebook_record,bool> {
private:
    string _key;
public:
    explicit CompareByPhone(string s) : _key(s) {}
    bool operator() (const notebook_record& r) const {return r.getPhone() == _key;}
};

class Notebook {
private:
    vector<notebook_record> records;

public:
    Notebook() : records() {};

    void addRecord(notebook_record record) {records.push_back(record);}

    void showAll() {
        vector<notebook_record>::const_iterator iter;
        for(iter = records.begin(); iter != records.end(); ++iter) {
            cout<<*iter;
        }
    }

    template<typename TFunctor>
    notebook_record search(TFunctor functor) const {
        vector<notebook_record>::const_iterator iter = find_if(records.begin(), records.end(), functor);
        if (iter != records.end()) {
            return *iter;
        }

        throw "Record is absent.";
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

void search_menu(const Notebook& notebook) {
    char ch = 0;
    string keyword;
    notebook_record record;

    cout<<"Make search by :"<<endl
        <<" 1) Name"<<endl
        <<" 2) Surname"<<endl
        <<" 3) Date of birth"<<endl
        <<" 4) Phone number"<<endl
        <<" ANY) Cancel"<<endl;
    cin.get(ch);
    while(cin.get() != '\n');

    if (ch < '1' || ch > '4')
        return;

    cout<<"Searching keyword : ";
    cin>>keyword;

    try {
        switch(ch) {
            case '1':
                record = notebook.search(CompareByName(keyword));
                break;
            case '2':
                record = notebook.search(CompareBySurname(keyword));
                break;
            case '3':
                record = notebook.search(CompareByBirthDate(keyword));
                break;
            case '4':
                record = notebook.search(CompareByPhone(keyword));
                break;
            default:
                return;
        }

        cout<<"Record has been founded:"<<endl
            <<record;
    } catch (const char* p) {
        cout<<"Unable to find record("<< p <<")"<<endl;
    }
}

void sort_menu(Notebook& notebook) {
    char ch = 0;

    cout<<"Make sort by :"<<endl
        <<" 1) Name"<<endl
        <<" 2) Surname"<<endl
        <<" 3) Date of birth"<<endl
        <<" 4) Phone number"<<endl
        <<" ANY) Cancel"<<endl;
    cin.get(ch);
    while(cin.get() != '\n');

    switch(ch) {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        default:
            return;
    }
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
            <<" 4) Sort by..."<<endl
            <<" q) Quit"<<endl;
        cin.get(ch);
        while(cin.get() != '\n');

        switch(ch) {
            case '1':
                cout<<"Adding new record"<<endl;
                notebook.addRecord(inputRecord());
                break;
            case '2':
                cout<<"Notebook:"<<endl;
                notebook.showAll();
                break;
            case '3':
                search_menu(notebook);
                break;
            case '4':
                sort_menu(notebook);
                break;
        }
    }

    return 0;
}

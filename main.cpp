#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

istream& operator>>(istream& stream, Date& date){
    int day, month, year;
    if(!(stream >> day) || day<0 || day>31 || stream.peek() != '.') throw invalid_argument("Error of input");
    stream.ignore(1);
    if(!(stream >> month) || month<0 || month>12 || stream.peek() != '.') throw invalid_argument("Error of input");
    stream.ignore(1);
    if(!(stream >> year) || year<0 || year>9999) throw invalid_argument("Error of input");
    if(stream.peek()==' ' || stream.peek()=='\n' || stream.peek()=='\t');
    else throw invalid_argument("Error of input");
    date.year = year;
    date.month = month;
    date.day = day;
    return stream;
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setfill('0');
    stream << setw(2) << date.day << '.' << setw(2) << date.month << '.' << setw(4) << date.year;
    return stream;
}

struct Record{
    string first_name;
    string last_name;
    Date date;
    int payment;
};

istream& operator>>(istream& stream, Record& rec){
    string first_name, last_name;
    Date date;
    int payment;
    stream >> first_name >> last_name;
    stream >> date;
    if(!(stream >> payment) || stream.peek()!='\n') throw invalid_argument("Error of input");
    rec.first_name = first_name;
    rec.last_name = last_name;
    rec.date = date;
    rec.payment = payment;
    return stream;
}

ostream& operator<<(ostream& stream, const Record& rec){
    stream << rec.first_name << ' ' << rec.last_name << ' ' << rec.date << ' ' << rec.payment << endl;
    return stream;
}

int main() {
    ofstream file("D:\\teach programm skillbox\\20.5\\1 statement\\statement.txt", ios::app);
    if(!file.is_open()){
        cerr<<"File opening error";
        return 0;
    }
    Record input;
    try{
        cin >> input;
        file << input;
    }
    catch(invalid_argument& inv){
        cerr<<inv.what()<<endl;
    }
    file.close();
    return 0;
}

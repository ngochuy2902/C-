#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

bool isLeapYear(int y)
{
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        return true;
    return false;
}

bool isValidDate(Date date)
{
    if (date.day < 0 || date.day > 31)
        return false;
    if (date.month < 1 || date.month > 12)
        return false;
    if (date.month == 2)
    {
        if (isLeapYear(date.year) && date.day > 29)
            return false;
        if (!isLeapYear(date.year) && date.day > 28)
            return false;
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        if (date.day > 30)
            return false;
    }
    return true;
}

istream &operator>>(istream &is, Date &date)
{
    while (true)
    {
        cout << "Day: ";
        is >> date.day;
        cout << "Month: ";
        is >> date.month;
        cout << "Year: ";
        is >> date.year;
        if (isValidDate(date))
            break;
        else
            cout << "Invalid date! Enter date again!" << endl;
    }
    return is;
}

ostream &operator<<(ostream &os, const Date date)
{
    date.day < 10 ? os << "0" << date.day : os << date.day;
    os << "/";
    date.month < 10 ? os << "0" << date.month : os << date.month;
    os << "/";
    date.year < 10 ? os << "0" << date.year : os << date.year;
    os << endl;
    return os;
}

string dayOfWeek(Date date)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    date.year -= date.month < 3;
    int d = (date.year + date.year / 4 - date.year / 100 + date.year / 400 + t[date.month - 1] + date.day) % 7;
    string weekday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return weekday[d];
}

int dayOfMonth(int m, int y)
{
    int dayOfMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(y))
        dayOfMonths[2] = 29;
    return dayOfMonths[m];
}

Date &operator++(Date &date) //prefix
{
    if (date.day < dayOfMonth(date.month, date.year))
        date.day++;
    else if (date.month < 12)
    {
        date.day = 1;
        date.month++;
    }
    else
    {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    return date;
}

Date operator++(Date &date, int) //postfix
{
    Date temp = date;
    ++date;
    return temp;
}

Date &operator--(Date &date) //prefix
{
    if (date.day > 1)
        date.day--;
    else
    {
        if (date.month>1)
        {
            date.month--;
            date.day = dayOfMonth(date.month, date.year);
        }
        else
        {
            date.day = 31;
            date.month = 12;
            date.year--;
        }
    }
    return date;
}

Date operator--(Date &date, int) //postfix
{
    Date temp = date;
    --date;
    return temp;
}

bool operator>(Date date1, Date date2)
{
    if (date1.year > date2.year)
        return true;
    if (date1.year == date2.year)
    {
        if (date1.month > date2.month)
            return true;
        if (date1.month == date2.month)
        {
            if (date1.day > date2.day)
                return true;
        }
    }
    return false;
}

bool operator<(Date date1, Date date2)
{
    if (date1.year < date2.year)
        return true;
    if (date1.year == date2.year)
    {
        if (date1.month < date2.month)
            return true;
        if (date1.month == date2.month)
        {
            if (date1.day < date2.day)
                return true;
        }
    }
    return false;
}

bool operator==(Date date1, Date date2)
{
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
        return true;
    return false;
}

bool operator!=(Date date1, Date date2)
{
    if (date1.day != date2.day || date1.month != date2.month || date1.year != date2.year)
        return true;
    return false;
}

int main()
{
    Date d1, d2;
    cout << "+ Enter date 1" << endl;
    cin >> d1;
    cout << "+ Enter date 2" << endl;
    cin >> d2;
    cout << "+ Date 1: " << dayOfWeek(d1) << " " << d1;
    cout << "+ Date 2: " << dayOfWeek(d2) << " " << d2;
    cout << "+ Date 1 after 1 day: " << ++d1;
    cout << "+ Date 2 before 1 day: " << --d2;
    if (d1 > d2)
        cout << "Date 1 is after Date 2" << endl;
    if (d1 < d2)
        cout << "Date 1 is before Date 2" << endl;
    if (d1 == d2)
        cout << "Date 1 is equal to Date 2" << endl;
    if (d1 != d2)
        cout << "Date 1 is different from Date 2" << endl;

    return 0;
}

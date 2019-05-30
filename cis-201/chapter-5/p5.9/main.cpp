#include <iostream>
#include <iomanip>

using namespace std;

int day_of_week(int, int, int);
void printHeader(int, int);
int daysInMonth(int, int);
void printDateRow(int, int);
void printDates(int, int);

int main() {
    int year;
    int month;
    cout << "Enter the year: ";
    cin >> year;

    cout << "Enter the month: ";
    cin >> month;

    if (month <= 0 || month > 12)
    {
        cout << "Please enter month in range 1-12 only" << endl;
        return 0;
    }

    printHeader(year, month);
    cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
    printDates(month, year);

    cout << endl;
}


int day_of_week(int day, int month, int year)
{

    int y = year;
    int m = month - 1;
    if (month < 3) {
        y--;
        m = m + 4;
    }
    return (y + y/4 - y/100 + y/400 + 3 * m + 4 - (m - m/8) / 2 + day) % 7;
}

void printHeader(int year, int month)
{
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"
    };

    cout << "\t\t" << months[month - 1] << " " << year << endl;
}

int daysInMonth(int month, int year)
{
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2:
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                return 29;
            else
                return 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 0;
    }
}

void printDateRow(int startDate, int endDate) {
    for(int i = startDate; i <= endDate; i++)
    {
        cout << setw(4);
        cout << i;
    }
    cout << endl;
}

void printDates(int month, int year) {
    int current = day_of_week(1, month, year);
    int days = daysInMonth(month, year);
    int i;
    for (i = 0; i < current; i++)
        cout << "    ";

    for(int j = 1; j<=days; )
    {
        int endDate = j + (6 - i);
        if (endDate > days) {
            endDate = days;
        }
        printDateRow(j, endDate);
        j = endDate + 1;
        i = 0;
    }
}

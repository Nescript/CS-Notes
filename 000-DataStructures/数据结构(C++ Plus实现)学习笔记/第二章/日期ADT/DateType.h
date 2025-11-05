#ifndef DATETYPE_H
#define DATETYPE_H

#include <string>
#include <fstream>
using namespace std;

enum RelationType {LESS, EQUAL, GREATER};

class DateType
{
public:
    RelationType ComparedTo(DateType someDate) const; //将自身（self）与 someDate 比较
    void Initialize(int newMonth, int newDay, int newYear);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    string GetMonthAsString() const;
    DateType Adjust(int daysAway) const;
private:
    int year;
    int month;
    int day;
};

#endif
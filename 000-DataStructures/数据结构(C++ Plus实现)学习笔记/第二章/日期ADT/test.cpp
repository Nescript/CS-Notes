#include <iostream>
#include "DateType.h"
using namespace std;

int main()
{
    cout << "=== DateType Class Test Program ===" << endl;
    
    try {
        // Test 1: Basic construction and initialization
        cout << "\n1. Test basic initialization:" << endl;
        DateType date1;
        date1.Initialize(8, 21, 2025);
        cout << "Date 1: " << date1.GetYear() << "/" << date1.GetMonth() << "/" << date1.GetDay() << endl;
        cout << "Month string: " << date1.GetMonthAsString() << endl;
        
        // Test 2: Another date
        cout << "\n2. Test another date:" << endl;
        DateType date2;
        date2.Initialize(12, 25, 2025);
        cout << "Date 2: " << date2.GetYear() << "/" << date2.GetMonth() << "/" << date2.GetDay() << endl;
        cout << "Month string: " << date2.GetMonthAsString() << endl;
        
        // Test 3: Date comparison
        cout << "\n3. Test date comparison:" << endl;
        RelationType result = date1.ComparedTo(date2);
        cout << "Date 1 compared to Date 2: ";
        if (result == LESS)
            cout << "Date 1 < Date 2" << endl;
        else if (result == GREATER)
            cout << "Date 1 > Date 2" << endl;
        else
            cout << "Date 1 = Date 2" << endl;
            
        // Test 4: Same date comparison
        cout << "\n4. Test same date comparison:" << endl;
        DateType date3;
        date3.Initialize(8, 21, 2025);
        RelationType result2 = date1.ComparedTo(date3);
        cout << "Date 1 compared to Date 3: ";
        if (result2 == LESS)
            cout << "Date 1 < Date 3" << endl;
        else if (result2 == GREATER)
            cout << "Date 1 > Date 3" << endl;
        else
            cout << "Date 1 = Date 3" << endl;
        
        // Test 5: Date adjustment (adding days)
        cout << "\n5. Test date adjustment:" << endl;
        DateType adjustedDate = date1.Adjust(10);
        cout << "Original date: " << date1.GetYear() << "/" << date1.GetMonth() << "/" << date1.GetDay() << endl;
        cout << "After +10 days: " << adjustedDate.GetYear() << "/" << adjustedDate.GetMonth() << "/" << adjustedDate.GetDay() << endl;
        
        // Test 6: Cross-month adjustment
        cout << "\n6. Test cross-month adjustment:" << endl;
        DateType date4;
        date4.Initialize(1, 25, 2025);
        DateType adjustedDate2 = date4.Adjust(20);  // Jan 25 + 20 days = Feb 14
        cout << "Original date: " << date4.GetYear() << "/" << date4.GetMonth() << "/" << date4.GetDay() << endl;
        cout << "After +20 days: " << adjustedDate2.GetYear() << "/" << adjustedDate2.GetMonth() << "/" << adjustedDate2.GetDay() << endl;
        
        // Test 7: Leap year test
        cout << "\n7. Test leap year (February 2024):" << endl;
        DateType leapYear;
        leapYear.Initialize(2, 28, 2024);
        DateType leapAdjusted = leapYear.Adjust(2);  // Feb 28 + 2 days, test leap year
        cout << "Original date: " << leapYear.GetYear() << "/" << leapYear.GetMonth() << "/" << leapYear.GetDay() << endl;
        cout << "After +2 days: " << leapAdjusted.GetYear() << "/" << leapAdjusted.GetMonth() << "/" << leapAdjusted.GetDay() << endl;
        
        // Test 8: All month names
        cout << "\n8. Test all month names:" << endl;
        for (int i = 1; i <= 12; i++) {
            DateType monthTest;
            monthTest.Initialize(i, 15, 2025);
            cout << "Month " << i << ": " << monthTest.GetMonthAsString() << endl;
        }
        
    } catch (const string& error) {
        cout << "Error: " << error << endl;
    }
    
    // Test 9: Exception handling
    cout << "\n9. Test exception handling:" << endl;
    
    // Invalid month
    try {
        DateType invalidMonth;
        invalidMonth.Initialize(13, 15, 2025);
    } catch (const string& error) {
        cout << "Caught exception - " << error << endl;
    }
    
    // Invalid day
    try {
        DateType invalidDay;
        invalidDay.Initialize(2, 30, 2025);  // February doesn't have 30 days
    } catch (const string& error) {
        cout << "Caught exception - " << error << endl;
    }
    
    // Invalid year
    try {
        DateType invalidYear;
        invalidYear.Initialize(5, 15, 1500);  // Before 1583
    } catch (const string& error) {
        cout << "Caught exception - " << error << endl;
    }
    
    cout << "\n=== Test Completed ===" << endl;
    
    return 0;
}
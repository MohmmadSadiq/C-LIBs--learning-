#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;
class clsDate
{
private:
    short _Day;
    short _Month;
    short _Year;


public:
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        _Year = now->tm_year + 1900;
        _Month = now->tm_mon + 1;
        _Day = now->tm_mday;
    }
    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(string Date)
    {
        *this = ConvertDateStringToDate(Date);
    }

    clsDate(short DateOrderInYear, short Year)
    {
        clsDate Date1 = getDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;
    }

    enum enComparDates { Before = -1, Equal = 0, After = 1 };

    void setDay(short Day)
    {
        _Day = Day;
    }
    short GetDay()
    {
        return _Day;
    }
    void setMonth(short Month)
    {
        _Month = Month;
    }
    short GetMonth()
    {
        return _Month;
    }
    void setYear(short Year)
    {
        _Year = Year;
    }
    short GetYear()
    {
        return _Year;
    }
    __declspec(property(get = GetDay, put = setDay)) short Day;
    __declspec(property(get = GetMonth, put = setMonth)) short Month;
    __declspec(property(get = GetYear, put = setYear)) short Year;


    static bool isLeapYear(short Year)
    {
        return (Year % 400 == 0 ? true : (Year % 100 == 0 ? false : Year % 4 == 0 ? true : false));
    }
    bool isLeapYear()
    {
        isLeapYear(_Year);
    }
    static short NumberOfDaysInAYear(short Year)
    {
        return (isLeapYear(Year) ? 366 : 365);
    }
    static int NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfDaysInAYear()
    {
        return NumberOfDaysInAYear(_Year);
    }
    int NumberOfHoursInAYear()
    {
        return NumberOfHoursInAYear(_Year);
    }

    int NumberOfMinutesInAYear()
    {
        return NumberOfMinutesInAYear(_Year);
    }

    int NumberOfSecondsInAYear()
    {
        return NumberOfSecondsInAYear(_Year);
    }
    static short NumberOfDaysInMonth(short Month, short Year)
    {
        if (Month > 12 || Month < 1)
            return 0;
        int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        return (Month == 2 ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1]);

    }
    short NumberOfDaysInMonth()
    {
        return NumberOfDaysInMonth(_Month, _Year);
    }
    static short DayOfWeekOrder(clsDate Date)
    {
        short a = (14 - Date.Month) / 12;
        short y = Date.Year - a;
        short m = Date.Month + 12 * a - 2;

        short d = (Date.Day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;


        return d;
    }
    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(*this);
    }

    static string MonthName(short Month)
    {
        string MonthArr[] = { "Jan", "Fab", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return MonthArr[Month - 1];
    }
    static string NameOfTheDay(short DayOrder)
    {
        if (DayOrder < 1 || DayOrder > 7)
            return "";
        string DayString[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return DayString[DayOrder];
    }
    string NameOfTheDay()
    {
        return NameOfTheDay(this->DayOfWeekOrder());
    }

    string MonthName()
    {
        return MonthName(_Month);
    }

    static void PrintCalander(clsDate Date)
    {
        string DayString[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        Date.setDay(1);
        short DayOrder = DayOfWeekOrder(Date);
        short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
        cout << "  ______________" << MonthName(Date.Month) << "________________\n\n";
        //rintf("  ______________%s______________\n\n", MonthName(Month).c_str());
        for (short i = 0; i < 7; i++)
        {
            cout << right << setw(5) << DayString[i];
        }
        cout << endl;

        short j;
        for (j = 0; j < DayOrder; j++)
        {
            cout << right << setw(5) << " ";

        }
        for (short i = 1; i <= MonthDays; i++)
        {


            cout << right << setw(5) << i;

            if (i == MonthDays)
            {
                break;
            }

            if (++j == 7)
            {
                cout << endl;
                j = 0;
            }


        }
        cout << "\n  _________________________________\n\n";



    }
    void PrintCalander()
    {
        PrintCalander(*this);
    }
    static void PrintYearCalander(clsDate Date)
    {
        cout << "\n  _________________________________\n\n";
        cout << "\t\tCalender - " << Date.Year;
        cout << "\n  _________________________________\n\n";

        for (short i = 1; i <= 12; i++)
        {
            Date.setMonth(i);
            PrintCalander(Date);
        }


    }
    void PrintYearCalander()
    {
        PrintYearCalander(*this);
    }

    static short CountNumberOfDaysInYear(clsDate Date)
    {
        short Sum = 0;
        for (short i = 1; i < Date.Month; i++)
        {
            Sum += NumberOfDaysInMonth(i, Date.Year);
        }
        Sum += Date.Day;
        return Sum;

    }
    short CountNumberOfDaysInYear()
    {
        return CountNumberOfDaysInYear(*this);
    }


    static clsDate getDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        while (true)
        {
            MonthDays = NumberOfDaysInMonth(Date.Month, Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;
            }
            else {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    static clsDate DateAfterAddingDays(clsDate Date, int AddedNumber)
    {
        Date.Day = CountNumberOfDaysInYear(Date);
        Date.Day += AddedNumber;
        Date.Month = 1;
        short DaysInMonth = 0;

        while (true)
        {
            DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
            if (DaysInMonth < Date.Day)
            {
                Date.Day -= DaysInMonth;
                Date.Month++;
                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else
            {
                break;
            }


        }
        return Date;
    }

    void DateAfterAddingDays(int AddedNumber)
    {
        *this = DateAfterAddingDays(*this, AddedNumber);
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false));
    }
    bool IsDateBeforeDate2(clsDate Date)
    {
        return IsDate1BeforeDate2(*this, Date);
    }

    static string GetDateString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    static void Print(clsDate Date)
    {
        cout << GetDateString(Date);
    }

    void Print()
    {
        Print(*this);
    }
    string GetDateString()
    {
        return GetDateString(*this);
    }

    static clsDate ReadData()
    {
        clsDate Date;
        short Day, Month, Year;
        cout << "Please Enter a Day? ";
        std::cin >> Day;
        cout << "Please Enter a Month? ";
        std::cin >> Month;
        cout << "Please Enter a Year? ";
        std::cin >> Year;
        Date.Day = Day;
        Date.Month = Month;
        Date.Year = Year;
        return Date;
    }

    void ReadObjectDate()
    {
        short Day, Month, Year;
        cout << "Please Enter a Day? ";
        std::cin >> Day;
        cout << "Please Enter a Month? ";
        std::cin >> Month;
        cout << "Please Enter a Year? ";
        std::cin >> Year;
        this->Day = Day;
        this->Month = Month;
        this->Year = Year;
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year == Date2.Year ? Date1.Month == Date2.Month ? Date1.Day == Date2.Day ? true : false : false : false);
    }

    bool IsDateEqualDate2(clsDate Date)
    {
        return IsDate1EqualDate2(*this, Date);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(this->Month);
    }

    static clsDate IncreseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
            Date.Day++;

        return Date;
    }

    void IncreseDateByOneDay()
    {
        *this = IncreseDateByOneDay(*this);
    }

    static clsDate GetSystemDate()
    {
        clsDate Date;
        time_t t = time(0);
        tm* now = localtime(&t);

        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;

        return Date;
    }

    void ConverToSystemDate()
    {
        *this = GetSystemDate();
    }

    static void SwapDate(clsDate& Date1, clsDate& Date2)
    {
        clsDate temp;
        temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }
    void SwapDate(clsDate& Date1)
    {
        SwapDate(*this, Date1);
    }

    static int GetDiffrenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDate(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }

    int GetDiffrenceInDays(clsDate Date1)
    {
        return GetDiffrenceInDays(*this, Date1);
    }


    static clsDate IncreaseDateByXDays(clsDate Date, int Days)
    {
        for (int i = 1; i <= Days; i++)
        {
            Date = IncreseDateByOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByXDays(int Days)
    {
        *this = IncreaseDateByXDays(*this, Days);
    }

    static clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        return IncreaseDateByXDays(Date, 7);
    }

    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeek(clsDate Date, int Weeks)
    {
        for (int i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeek(int Weeks)
    {
        *this = IncreaseDateByXWeek(*this, Weeks);
    }





    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Year++;
            Date.Month = 1;
        }
        else
            Date.Month++;

        short NumberOfDaysInCurantMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurantMonth)
        {
            Date.Day = NumberOfDaysInCurantMonth;
        }


        return Date;
    }

    void IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonths(clsDate Date, int Months)
    {
        for (int i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonths(int Months)
    {
        *this = IncreaseDateByXMonths(*this, Months);
    }

    clsDate IncreaseDateByOneYear(clsDate Date)
    {
        return IncreaseDateByXMonths(Date, 12);
    }

    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }



    clsDate IncreaseDateByXYears(clsDate Date, int Years)
    {
        Date.Year += Years;
        return Date;
    }

    void IncreaseDateByXYears(int Years)
    {
        *this = IncreaseDateByXYears(*this, Years);
    }

    clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        return IncreaseDateByXYears(Date, 10);
    }
    void IncreaseDateByOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }


    static clsDate IncreaseDateByXDecade(clsDate Date, int Decade)
    {
        Date.Year += Decade * 10;
        return Date;
    }


    void IncreaseDateByXDecade(int Decade)
    {
        *this = IncreaseDateByXDecade(*this, Decade);
    }


    static clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        return IncreaseDateByXDecade(Date, 10);
    }

    void IncreaseDateByOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate Date)
    {
        return IncreaseDateByXDecade(Date, 100);
    }

    void IncreaseDateByOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);
    }

    static bool IsEndOfWeek(clsDate Date)
    {
        short CurrentDayOfWeekOrder = DayOfWeekOrder(Date);
        return CurrentDayOfWeekOrder == 6;
    }
    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }
    static bool IsWeekend(clsDate Date)
    {
        short CurrentDayOfWeekOrder = DayOfWeekOrder(Date);
        return (CurrentDayOfWeekOrder == 6 || CurrentDayOfWeekOrder == 5);
    }

    bool IsWeekend()
    {
        return IsWeekend(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return (!IsWeekend(Date));
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }
    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        short CurrentDayOfWeekOrder = DayOfWeekOrder(Date);
        return 6 - CurrentDayOfWeekOrder;
    }

    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date)
    {
        return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date)
    {
        return NumberOfDaysInAYear(Date.Year) - CountNumberOfDaysInYear(Date);
    }

    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    bool IsDateAfterDate2(clsDate Date)
    {
        return IsDate1AfterDate2(*this, Date);
    }

    static enComparDates ComparDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enComparDates::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enComparDates::Equal;

        return enComparDates::After;

    }

    enComparDates ComparDates(clsDate Date)
    {
        return  ComparDates(*this, Date);
    }

    static bool IsValidDate(clsDate Date)
    {
        return (Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year) && Date.Day > 0 && Date.Month <= 12 && Date.Month > 0);
    }

    bool IsValideDate()
    {
        return IsValidDate(*this);
    }

    static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
            pos = S1.find(StringToReplace);
        }
        return S1;

    }

    static string FormatingDate(clsDate Date, string Format)
    {
        Format = ReplaceWord(Format, "dd", to_string(Date.Day));
        Format = ReplaceWord(Format, "mm", to_string(Date.Month));
        Format = ReplaceWord(Format, "yyyy", to_string(Date.Year));

        return Format;

    }

    string FormatingDate(string Format)
    {
        return FormatingDate(*this, Format);
    }

    string ReadStringDate(string Message)
    {
        string DateString;
        cout << Message;
        getline(cin >> ws, DateString);
        return DateString;
    }

    static vector <string> SplitEachWordInVector(string S1, string delim = " ")
    {
        vector <string> veSplitString;
        short pos;
        string sWord;
        while ((pos = S1.find(delim)) != std::string::npos)
        {

            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                veSplitString.push_back(sWord);
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
            veSplitString.push_back(S1);
        return veSplitString;
    }

    static clsDate ConvertDateStringToDate(string DString)
    {
        vector <string> DateVector = SplitEachWordInVector(DString, "/");
        clsDate Date;
        Date.Day = stoi(DateVector[0]);
        Date.Month = stoi(DateVector[1]);
        Date.Year = stoi(DateVector[2]);
        return Date;
    }

    void ConvertDateStringToDateObj(string DStrign)
    {
        *this = ConvertDateStringToDate(DStrign);
    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year, Hour, Minute, Second;
        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;

        return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " +
            to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }

};


#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }
    static enum enCharType { SmallLetter = 1, CapitalLetter, SpecialCharacter, DigitInOrder, MixChars };
    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    static char GetRandomCharacter(enCharType Char)
    {

        switch (Char)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
            break;
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
            break;
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
            break;
        case enCharType::DigitInOrder:
            return char(RandomNumber(48, 57));
            break;
        case enCharType::MixChars:
            return GetRandomCharacter(enCharType(RandomNumber(1, 4)));
            break;
        default:
            break;
        }
        return ' ';
    }
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";
        for (int i = 0; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;

    }

    static string GenerateKey(enCharType CharType)
    {
        string Key = "";
        for (int i = 0; i < 4; i++)
        {
            Key = Key + GenerateWord(CharType, 4);
            if (i < 3)
            {
                Key += "-";
            }
        }
        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void Swap(int& A, int& B)
    {
        int Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(double& A, double& B)
    {
        double Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(string& A, string& B)
    {
        string Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void ShuffleArray(int arr[100], int num)
    {
        for (int i = 0; i < num; i++)
        {
            Swap(arr[RandomNumber(1, num) - 1], arr[RandomNumber(1, num)]);
        }
    }

    static void ShuffleArray(string arr[100], int num)
    {
        for (int i = 0; i < num; i++)
        {
            Swap(arr[RandomNumber(1, num) - 1], arr[RandomNumber(1, num)]);
        }
    }

    static  void ShuffleArray1(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray1(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static void FillArrayFrom1ToN(int arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            arr[i] = i + 1;
        }

    }


    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int from, int to)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }

    static void FillArrayWithRandomWord(string arr[100], int arrLength, enCharType CharType, int WordLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, WordLength);
    }
    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";
        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string EncryptText(string Text, int EncryptionKey)
    {
        int lenght = size(Text);
        for (int i = 0; i < lenght; i++)
        {
            Text[i] += EncryptionKey;
        }
        return Text;


    }
    static string DecryptText(string Text, int DcryptionKey)
    {
        int lenght = size(Text);
        for (int i = 0; i < lenght; i++)
        {
            Text[i] -= DcryptionKey;
        }
        return Text;
    }
    static string NumberToString(long long int Number)
    {
        if (Number == 0)
            return "";
        if (Number >= 1 && Number <= 19)
        {
            string arr1[] = { "","One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr1[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr2[] = { "", "", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return arr2[Number / 10] + " " + NumberToString(Number % 10);
        }
        if (Number >= 100 && Number <= 199)
        {
            return "One Hundreds" + NumberToString(Number % 100);
        }
        if (Number >= 200 && Number <= 999)
        {
            return NumberToString(Number / 100) + "Hundreds " + NumberToString(Number % 100);
        }
        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToString(Number % 1000);
        }
        else if (Number >= 2000 && Number <= 999999)
        {
            return NumberToString(Number / 1000) + "Thousands " + NumberToString(Number % 1000);
        }
        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToString(Number % 1000000);
        }
        else if (Number >= 2000000 && Number <= 999999999)
        {
            return  NumberToString(Number / 1000000) + "Millions " + NumberToString(Number % 1000000);
        }
        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToString(Number % 1000000000);
        }
        else if (Number >= 2000000000 && Number <= 999999999999)
        {
            return  NumberToString(Number / 1000000000) + "Billions " + NumberToString(Number % 1000000000);
        }
        return "";
    }

};

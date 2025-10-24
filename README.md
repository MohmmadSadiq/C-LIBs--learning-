# Welcome to My C++ Utility Libs Learning Lab! 🚀

Hello and welcome! 👋 This repository is my personal lab for building and perfecting a set of powerful, reusable C++ utility libraries.

This isn't just about making things *work*—it's about making them *right*. My core mission here is to write code that is not only functional but also exceptionally **clean**, **highly organized**, and **infinitely reusable**.

## ✨ My Guiding Principles ✨

I believe that elegant code is a work of art. My development process is strictly guided by foundational software design principles to ensure everything here is robust, maintainable, and a genuine pleasure to read and use.

### 🧠 1. Divide and Conquer
I don't tackle mountains; I move small stones. You won't find one massive "God" header here. The entire library is built on a **Divide and Conquer** strategy, where every major problem domain gets its own dedicated class.

### 🎯 2. Single Responsibility Principle (SRP)
Each class has **one specific job** and does it perfectly. This clarity is the key to building a maintainable and testable codebase.

* `clsDate.h`: The master of all things time-related. Its *only* responsibility is to handle date creation, calculation, formatting, and arithmetic.
* `clsString.h`: The expert for all string manipulations. It focuses entirely on text transformation, splitting, and analysis.
* `clsInputValidate.h`: A perfect example of SRP. It has a single, vital mission: to safely read and validate user input.
* `clsUtil.h`: The general-purpose toolkit. It handles all the non-domain-specific utilities like random number generation, array shuffling, and encryption.

### 🚫 3. Don't Repeat Yourself (DRY)
Why write the same logic twice? This library is built on abstraction and re-use.

* **Internal Re-use:** You'll see this pattern everywhere. For example, in `clsInputValidate.h`, the `ReadIntNumberBetween` function re-uses both `ReadIntNumber` and `IsNumberBetween`, avoiding duplicate validation logic.
* **Static & Member Methods:** In `clsDate.h`, many non-static member functions (like `isLeapYear()`) are clean, DRY implementations that simply call their static counterparts (`isLeapYear(_Year)`), reusing the core logic.

## 📚 What's Inside This Repository?

This repository is a growing collection of practical C++ utility headers. Here's what you'll find:

* **`clsDate.h`**: A comprehensive class for all date operations. It can get the system date, parse from a string, calculate differences, add/subtract days/weeks/months, and even print a full calendar.
* **`clsString.h`**: A powerful wrapper class for `std::string` that adds a ton of useful functionality like `Split`, `Trim`, `ReplaceWord`, `UpperFirstLetterOfEachWord`, and `CountVowels`.
* **`clsInputValidate.h`**: A vital static helper class for robustly handling user input. It includes functions like `ReadIntNumberBetween`, `IsValideDate`, and `ReadString` to prevent your program from crashing on bad input.
* **`clsUtil.h`**: A general utility "toolbox" class for common tasks, including `RandomNumber`, `GenerateKey`, `Swap` (for multiple data types), `EncryptText`/`DecryptText`, and `NumberToString`.

## 🚀 How to Use

Using these libraries in your C++ project is simple!

1.  Clone or download the `.h` files you need from this repository.
2.  Place them in your project directory.
3.  `#include` them at the top of your `.cpp` file.

### Quick Example:

Here’s a small example of how `clsString.h` and `clsInputValidate.h` can work together.

```cpp
#include <iostream>
#include "clsString.h"
#include "clsInputValidate.h"

using namespace std;

int main() {
    
    // 1. Using clsInputValidate to safely get a number
    cout << "Please enter your age (18-65): ";
    int Age = clsInputValidate::ReadIntNumberBetween(18, 65, "Invalid age, try again: ");
    
    cout << "Great, your age is: " << Age << endl;

    // 2. Using clsString to format a name
    cout << "\nPlease enter your full name: ";
    string FullName = clsInputValidate::ReadString();
    
    clsString strName(FullName);
    strName.UpperFirstLetterOfEachWord();

    cout << "Your formatted name: " << strName.Value << endl;

    return 0;
}

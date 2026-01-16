/**
 * CHAPTER: C++ PROGRAM AND FILE ORGANIZATION
 * --- THE CONCEPT ---
 * 1. File Types:
 * - Header Files (.h): Contain declarations (classes, prototypes, constants).
 * - Source Files (.cpp, .cc): Contain definitions (function bodies, global variables).
 * 2. Header Guards: Use #ifndef, #define, and #endif to prevent double-inclusion errors.
 * 3. Scope & Linkage:
 * - 'extern' keyword: Allows a source file to access global variables defined in another file.
 * - Linker: Combines separate object files into a single executable.
 * 4. Separation of Concerns: 
 * - Accessors and small methods are often defined "in-line" within the header.
 * - Complex logic belongs in the .cpp file to keep the interface clean.
 * 5. Preprocessor: Handles #directives (like #include) before the actual compilation begins.
 */

// =============================================================================
// FILE: CreditCard.h
// =============================================================================
#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <string>
#include <iostream>

class CreditCard {
public:
    // Constructor
    CreditCard(const std::string& no, const std::string& nm, int lim, double bal = 0);

    // Accessors (Defined in-line for efficiency)
    std::string getNumber() const  { return number; }
    std::string getName() const    { return name; }
    double getBalance() const      { return balance; }
    int getLimit() const           { return limit; }

    // Update functions
    bool chargeIt(double price); 
    void makePayment(double payment);

private:
    std::string number;
    std::string name;
    int limit;
    double balance;
};

// Overloaded output operator declaration
std::ostream& operator<<(std::ostream& out, const CreditCard& c);

#endif

// =============================================================================
// FILE: CreditCard.cpp
// =============================================================================
// #include "CreditCard.h"

using namespace std;

// Constructor implementation
CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal) 
    : number(no), name(nm), limit(lim), balance(bal) { }

// Business Logic: Check limit before charging
bool CreditCard::chargeIt(double price) {
    if (price + balance > double(limit))
        return false; 
    balance += price;
    return true;
}

void CreditCard::makePayment(double payment) {
    balance -= payment;
}

// Global operator implementation
ostream& operator<<(ostream& out, const CreditCard& c) {
    out << "Number = "  << c.getNumber()  << "\n"
        << "Name = "    << c.getName()    << "\n"
        << "Balance = " << c.getBalance() << "\n"
        << "Limit = "   << c.getLimit()   << "\n";
    return out;
}

// =============================================================================
// FILE: TestCard.cpp (Main Execution)
// =============================================================================
#include <vector>
#include <cstdlib>

// void testCard() {
//     vector<CreditCard*> wallet(3); 
    
//     wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
//     wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
//     wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

//     // Simulate usage
//     for (int j = 1; j <= 16; j++) {
//         wallet[0]->chargeIt(double(j));
//         wallet[1]->chargeIt(2.0 * j);
//         wallet[2]->chargeIt(3.0 * j);
//     }

//     cout << "Card payments:\n";
//     for (int i = 0; i < 3; i++) {
//         cout << *wallet[i];
//         while (wallet[i]->getBalance() > 100.0) {
//             wallet[i]->makePayment(100.0);
//             cout << "New balance = " << wallet[i]->getBalance() << "\n";
//         }
//         cout << "\n";
//         delete wallet[i]; // Memory cleanup
//     }
// }

// int main() {
//     testCard();
//     return EXIT_SUCCESS;
// }

/**
 * CHAPTER 2: OBJECT-ORIENTED DESIGN - GOALS, PRINCIPLES, AND PATTERNS
 * --- THE CONCEPT ---
 * 1. OOD Goals:
 * - Robustness: Handling unexpected/invalid inputs gracefully.
 * - Adaptability: Evolving with changing environments (portability).
 * - Reusability: Using the same code across different systems.
 * 2. OOD Principles:
 * - Abstraction: Distilling systems to fundamental parts (ADTs).
 * - Encapsulation: Hiding internal implementation details.
 * - Modularity: Dividing code into functional units.
 * 3. Hierarchical Organization: Using "is-a" relationships to group
 * common functionality (e.g., A Ranch is a House is a Building).
 * 4. Design Patterns: Abstract templates for recurring problems.
 */

#include <iostream>
#include <string>

//------------------------------------------------------------------------------
// 2.1.1 PRINCIPLE: ABSTRACTION (Abstract Data Type)
//------------------------------------------------------------------------------

/**
 * In C++, Abstraction is often achieved via "Interfaces" (Pure Virtual Classes).
 * This defines WHAT the data structure does, but not HOW.
 */
class Progression {
public:
    virtual ~Progression() {}
    virtual long nextValue() = 0;  // Pure virtual: The signature of the ADT
    virtual void printProgression(int n) = 0;
};

//------------------------------------------------------------------------------
// 2.1.2 PRINCIPLE: ENCAPLUSATION & MODULARITY
//------------------------------------------------------------------------------

class BankAccount {
public:
    BankAccount(long initialBalance) : balance(initialBalance) {}

    // Public Interface: Abstraction of "Money Management"
    void deposit(long amount) {
        if (amount > 0) balance += amount; // Robustness: check for negative
    }

    long getBalance() const { return balance; }

private:
    // Encapsulation: The user cannot "cheat" and set the balance to 1 million.
    long balance; 
};

//------------------------------------------------------------------------------
// 2.1.3 HIERARCHICAL ORGANIZATION ("Is-a" Relationship)
//------------------------------------------------------------------------------

/* * Hierarchy Example:
 * Building -> House -> Ranch
 */



class Building {
public:
    virtual string getDescription() { return "A generic building"; }
};

class House : public Building {
public:
    string getDescription() override { return "A house for a family"; }
};

class Ranch : public House {
public:
    string getDescription() override { return "A single-story ranch house"; }
};

//------------------------------------------------------------------------------
// MAIN EXECUTION: DESIGN GOALS IN ACTION
//------------------------------------------------------------------------------

int main() {
    // ROBUSTNESS: Handling bad input
    BankAccount myAccount(100);
    myAccount.deposit(-500); // Program ignores this, staying robust.
    std::cout << "Balance after invalid deposit: " << myAccount.getBalance() << std::endl;

    // HIERARCHY / ADAPTABILITY
    Building* myHome = new Ranch();
    std::cout << "Home Type: " << myHome->getDescription() << std::endl;

    delete myHome;
    return 0;
}

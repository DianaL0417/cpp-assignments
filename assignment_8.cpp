#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(const string& item, double cost) {
        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
        } else {
            balance -= cost;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() {
        cout << fixed << setprecision(2);
        cout << "Current Balance: $" << balance << endl;
    }

    void saveTransaction(const string& type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << fixed << setprecision(2) << amount << endl;
            file.close();
        }
    }
};

int main() {
    BankAccount myAccount;

    myAccount.deposit(100.00);
    myAccount.makePurchase("Coffee", 4.50);
    myAccount.makePurchase("Book", 25.00);
    myAccount.displayBalance();

    return 0;
}

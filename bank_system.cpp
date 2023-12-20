#include <iostream>
using namespace std;

class Account {
    private:
        int AccountNumber;
        string AccountName;
        double Balance;

    public:
        Account() : AccountNumber(0), AccountName(""), Balance(0.0) {} // default constructor

        Account(int AccountNumber, string AccountName, double Balance) {
            this->AccountNumber = AccountNumber;
            this->AccountName = AccountName;
            this->Balance = Balance;
        }

        int getAccountNumber() {
            return AccountNumber;
        }

        string getAccountName() {
            return AccountName;
        }

        double getBalance() {
            return Balance;
        }

        void setAccountNumber(int AccountNumber) {
            this->AccountNumber = AccountNumber;
        }

        void setAccountName(string AccountName) {
            this->AccountName = AccountName;
        }

        void setBalance(double Balance) {
            this->Balance = Balance;
        }

        void deposit(double amount) {
            Balance += amount;
            cout << "Deposit Successful! New balance is:" << Balance << endl;
        }

        int withdrawn(double amount) {
            if (Balance >= amount) {
                Balance -= amount;
            } else {
                cout << "Amount withdrawn exceeds the current balance!" << endl;
                return 0;
            }
            cout << "Withdrawn Successful! New balance is: " << Balance << endl;
            return 1;
        }

        void print() {
            cout << "Account Number: " << AccountNumber << endl;
            cout << "Account Name: " << AccountName << endl;
            cout << "Balance: " << Balance << endl << endl;
        }    
};

class Bank {
    private:
        Account accounts[100];
        int totalAccounts;

    public:
        Bank() {
            totalAccounts = 0;
        }

        int getTotalAccounts() {
            return totalAccounts;
        }

        void addAccount() {
            
            int AccountNumber;
            int AccountDeposit;
            int AccountWithdrawn;
            double AccountBalance;
            string AccountName;

            cout << "Enter Account Number: ";
            cin >> AccountNumber;
            cout << "Enter Account Name: ";
            cin >> AccountName;
            cout << "Enter Account Balance: ";
            cin >> AccountBalance;

            Account account = Account(AccountNumber, AccountName, AccountBalance);

            accounts[totalAccounts++] = account;

            cout << "\nAccount Created Successfully!" << endl;
        }

        bool CheckValidAccount(int accountNumber) {
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    return true;
                }
            }
            cout << "Account does not exist!" << endl;
            return false;
        }

        void deposit(int accountNumber, double amount) {
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    accounts[i].deposit(amount);
                    return;
                }
            }
        }

        void withdrawn(int accountNumber, double amount) {
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    accounts[i].withdrawn(amount);
                    return;
                }
            }
        }

        void print(int accountNumber) {
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    accounts[i].print();
                    return;
                }
            }
        }
};


int main() {

    Bank bank;

    bool loop = true;
    while (loop)
    {

        int end;

        cout << "Do you want to add an account or check an account? (1/0/-1)\n";
        cin >> end;

        switch (end)
        {
        case 0:

            if (bank.getTotalAccounts() == 0) {
                cout << "No accounts exist!" << endl;
                break;
            }

            int accountNumber;
            cout << "Enter Account Number: \n";
            cin >> accountNumber;

            while(!bank.CheckValidAccount(accountNumber)) {
                cout << "Invalid Account Number! Please enter a valid account number: \n";
                cin.clear();
                cin >> accountNumber;
            }

            bank.print(accountNumber);

            cout << "Would you like to make a deposit or withdrawn? (1/0/-1)\n";
            cin >> end;
            
            double amount;
            switch (end) {
                case 1:
                    cout << "Enter amount to deposit: \n";
                    cin >> amount;
                    bank.deposit(accountNumber, amount);
                    break;
                case 0:
                    cout << "Enter amount to withdrawn: \n";
                    cin >> amount;
                    bank.withdrawn(accountNumber, amount);
                    break;
                case -1:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid input!" << endl;
                    break;
            }

            break;

        case 1:
            bank.addAccount();
            break;

        case -1:
        cout << "Exiting..." << endl;
            loop = false;
            break;

        default:
            cout << "Invalid input!" << endl;
            break;
        }

        cout << endl;
    }
}

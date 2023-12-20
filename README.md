# SimpleBankingSystem

This repository contains a simple banking system implemented in C++. The system allows for the creation of new bank accounts, checking of existing accounts, depositing and withdrawing money, and printing account details.

## Features

- Create new bank accounts with an account number, name, and initial balance.
- Check if an account exists.
- Deposit money into an account.
- Withdraw money from an account.
- Print account details.

## How to Run

1. Clone this repository.
2. Compile the `bank_system.cpp` file using a C++ compiler (e.g., `g++ -o bank_system bank_system.cpp`).
3. Run the compiled file (e.g., `./bank_system`).

## Code Structure

The code consists of two classes: `Account` and `Bank`.

- The `Account` class represents a bank account with properties like account number, account name, and balance. It also has methods for depositing and withdrawing money, and printing account details.

- The `Bank` class represents a bank that can hold multiple accounts. It has methods for adding accounts, checking if an account exists, depositing and withdrawing money from an account, and printing account details.

The `main` function provides a simple text-based interface for interacting with the banking system.

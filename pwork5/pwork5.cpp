#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;



class BankAccount 
{
private:
    int accountNumber;
    double balance;
    double interestRate;
    struct Info
    {
        int accountNumber;
        double balance;
        double interestRate;

        Info(int accountNumber, double balance, double interestRate)
        {
            this->accountNumber = accountNumber;
            this->balance = 0;
            this->interestRate = 0;
        }
    };

public:

    void deposit();
    void withdraw();
    void getBalance();
    double getInterestRate();
    void setInterestRate();
    int getAccountNumber();
    bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount);


    BankAccount(int accountNumber, double balance, double interestRate) 
    {
        this->accountNumber = accountNumber;
        this->balance = 0;
        this->interestRate = 0;
    }



};



void BankAccount::deposit() 
{
    cout << "\nВведите номер счета: ";
    cin >> this->accountNumber;
    cout << "\nВнесите деньги: ";
    cin >> this->balance;
    cout << "\nСчёт открыт!!!" << endl << endl;
}

void BankAccount::getBalance() 
{
    cout << endl << "\nекущее состояние счёта: " << endl;
    cout << "\nНомер счета: " << this->accountNumber << endl;
    cout << "\nКоличество средств на счёте: " << this->balance << endl;
}

void BankAccount::withdraw() 
{
    long long int a;

    do 
    {
        cout << "\nСколько желаете снять?\n ";
        cin >> a;
        if (a > this->balance) cout << "\nНедостаточно средств на счете!" << endl;
    }
    while (a > this->balance);
    this->balance -= a;
    cout << "\nДеньги успешно сняты" << endl;
}

double BankAccount::getInterestRate()
{
    return this->balance * this->interestRate * (1 / 12);
}

void BankAccount::setInterestRate() 
{
    double newInterestRate;
    cout << "\nвведите процентную ставку\n";
    cin >> newInterestRate;
    this->interestRate = newInterestRate;
}

int BankAccount::getAccountNumber() 
{
    return this->accountNumber;
}

bool BankAccount::transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount)
{
    if (amount > 0 && amount <= fromAccount.balance)
    {
        fromAccount.balance -= amount;
        toAccount.balance += amount;
        return true;
    }
    else 
    {
        std::cout << "\nОшибка: Недостаточно средств для перевода." << std::endl;
        return false;
    }
}

int main() 
{
    setlocale(LC_ALL, "");

    vector<BankAccount> accaunts;
    BankAccount acc1(0, 0, 0);
    BankAccount acc2(1, 0, 0);
    accaunts.push_back(acc1);
    accaunts.push_back(acc2);

    while (true)
    {
        int choose;
        cout << "\nЧто вы хотите сделать? 1)Внести деньги, 2)Вывести деньги, 3)Узнать баланс, 4)Узнать процентную ставку, 5)установить процентную ставку, 6)получить номер аккаунта, 7)перевести средства на другой счет, 8)выход \n";
        cin >> choose;
        if (choose == 1)
        {
            acc1.deposit();
        }
        else if (choose == 2)
        {
            acc1.withdraw();
        }
        else if (choose == 3)
        {
            acc1.getBalance();
        }
        else if (choose == 4)
        {
            cout << acc1.getInterestRate();
        }
        else if (choose == 5)
        {
            acc1.setInterestRate();
        }
        else if (choose == 6)
        {
            cout << acc1.getAccountNumber();
        }
        else if (choose == 7)
        {
            int fromAccount0;
            int toAccount0;
            double amount;
            while (true)
            {
                cout << "введите номер аккаунта-отправителя";
                cin >> fromAccount0;
                if (fromAccount0 >= accaunts.size())
                {
                    cout << "такого аккаунта нет";
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "введите номер аккаунта-отправителя";
                cin >> toAccount0;
                if (toAccount0 >= accaunts.size())
                {
                    cout << "такого аккаунта нет";
                }
                else
                {
                    break;
                }
            }
      
            cout << "введите сумму";
            cin >> amount;
            BankAccount& fromAccount = accaunts[fromAccount0];
            BankAccount& toAccount = accaunts[toAccount0];
            acc1.transfer(fromAccount, toAccount, amount);
        }
        else if (choose == 8)
        {
            break;
        }
        else
        {
            cout << "ошибка";
        }

    }
}
//void deposit();
//void withdraw();
//void getBalance();
//double getInterestRate();
//void setInterestRate(double newInterestRate);
//int getAccountNumber();
//bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount);
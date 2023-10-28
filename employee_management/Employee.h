#pragma once

#include <string>

namespace Records {
    using namespace std;

    const int DefaultStartingSalary{30'000};
    const int DefaultRaiseAmdDemeritAmount{1'000};

    class Employee {
    public:
        Employee(string firstName, string lastName);

        void promote(int raiseAmount = DefaultRaiseAmdDemeritAmount);

        void demote(int demeritAmount = DefaultRaiseAmdDemeritAmount);

        void hire();

        void fire();

        void display() const;

        void setFirstName(const string &firstName);

        [[nodiscard]] const string &getFirstName() const;

        void setLastName(const string &lastName);

        [[nodiscard]] const string &getLastName() const;

        void setEmployeeNumber(int employeeNumber);

        [[nodiscard]] int getEmployeeNumber() const;

        void setSalary(int newSalary);

        [[nodiscard]] int getSalary() const;

        [[nodiscard]] bool isHired() const;

    private:
        string m_firstName;
        string m_lastName;
        int m_employeeNumber{-1};
        int m_salary{DefaultStartingSalary};
        bool m_hired{false};
    };
}

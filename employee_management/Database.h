#pragma once

#include <string>
#include <vector>
#include "Employee.h"

namespace Records {
    using namespace std;

    const int FirstEmployeeNumber{1'000};

    class Database {
    public:
        Employee &addEmployee(const string &firstName, const string &lastName);

        Employee &getEmployee(int employeeNumber);

        Employee &getEmployee(const string &firstName, const string &lastName);

        void displayAll() const;

        void displayCurrent() const;

        void displayFormer() const;

    private:
        vector<Employee> m_employees;
        int m_nextEmployeeNumber{FirstEmployeeNumber};
    };
}
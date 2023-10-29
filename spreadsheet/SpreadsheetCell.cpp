#include <string>
#include <charconv>
#include <iostream>
#include "SpreadsheetCell.h"

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue) {
    setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue) {
    setString(initialValue);
}

SpreadsheetCell::~SpreadsheetCell() {
    cout << "Destructor called." << endl;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell &rhs) {
    if (this == &rhs) return *this;

    m_value = rhs.m_value;
    return *this;
}

void SpreadsheetCell::setValue(double value) {
    m_value = value;
}

double SpreadsheetCell::getValue() const {
    return m_value;
}

void SpreadsheetCell::setString(std::string_view value) {
    m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const {
    return doubleToString(m_value);
}

string SpreadsheetCell::doubleToString(double value) {
    return to_string(value);
}

double SpreadsheetCell::stringToDouble(std::string_view value) {
    double number{0};
    from_chars(value.data(), value.data() + value.size(), number);
    return number;
}
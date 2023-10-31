#include <string>
#include <charconv>
#include <iostream>
#include "SpreadsheetCell.h"

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue) {
    set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue) {
    set(initialValue);
}

SpreadsheetCell::~SpreadsheetCell() {
    cout << "Destructor called." << endl;
}

SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rhs) {
    if (this == &rhs) return *this;

    m_value = rhs.m_value;
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell &cell) const {
    return SpreadsheetCell{getValue() + cell.getValue()};
}

SpreadsheetCell SpreadsheetCell::operator+(double rhs) const {
    return SpreadsheetCell{getValue() + rhs};
}

void SpreadsheetCell::set(double value) {
    m_value = value;
}

double SpreadsheetCell::getValue() const {
    return m_value;
}

void SpreadsheetCell::set(std::string_view value) {
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

bool SpreadsheetCell::operator==(double rhs) const
{
    return getValue() == rhs;
}
std::partial_ordering SpreadsheetCell::operator<=>(double rhs) const
{
    return getValue() <=> rhs;
}
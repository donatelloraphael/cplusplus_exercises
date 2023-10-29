#pragma once

#include <string_view>

class SpreadsheetCell {
public:
    SpreadsheetCell() = default;
    SpreadsheetCell(const SpreadsheetCell &src) = default;
    explicit SpreadsheetCell(double initialValue);
    explicit SpreadsheetCell(std::string_view initial_value);

    ~SpreadsheetCell();

//    SpreadsheetCell& operator=(const SpreadsheetCell &rhs) = default;
    SpreadsheetCell& operator=(const SpreadsheetCell &rhs);

    void setValue(double value);
    [[nodiscard]] double getValue() const;

    void setString(std::string_view value);

    [[nodiscard]] std::string getString() const;
private:
    [[nodiscard]] static std::string doubleToString(double value) ;
    [[nodiscard]] static double stringToDouble(std::string_view value) ;
    double m_value{0};
};

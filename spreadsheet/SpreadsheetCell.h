#pragma once

#include <string_view>

class SpreadsheetCell {
public:
    SpreadsheetCell() = default;

    SpreadsheetCell(const SpreadsheetCell &src) = default;

    explicit SpreadsheetCell(double initialValue);

    explicit SpreadsheetCell(std::string_view initial_value);

    ~SpreadsheetCell();

    SpreadsheetCell &operator=(const SpreadsheetCell &rhs);

    SpreadsheetCell operator+(const SpreadsheetCell& cell) const;

    SpreadsheetCell operator+(double rhs) const;

    bool operator==(double rhs) const;

    std::partial_ordering operator<=>(double rhs) const;

    // C++20 can provide all comparison operator overloads if <=> operator is defaulted and all data members support <=>
    // [[nodiscard]] auto operator<=>(const SpreadsheetCell&) const = default;

    void set(double value);

    [[nodiscard]] double getValue() const;

    void set(std::string_view value);

    [[nodiscard]] std::string getString() const;

private:
    [[nodiscard]] static std::string doubleToString(double value);

    [[nodiscard]] static double stringToDouble(std::string_view value);

    double m_value{0};
};

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
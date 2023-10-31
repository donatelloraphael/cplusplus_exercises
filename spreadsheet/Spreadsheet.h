#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class Spreadsheet {
public:
    explicit Spreadsheet(size_t width = MaxWidth, size_t height = MaxHeight);

    Spreadsheet(const Spreadsheet &src);

    Spreadsheet(Spreadsheet &&src) noexcept;

    Spreadsheet &operator=(const Spreadsheet &rhs);

    Spreadsheet &operator=(Spreadsheet &&rhs) noexcept;

    ~Spreadsheet();

    void swap(Spreadsheet &other) noexcept;

    void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);

    SpreadsheetCell &getCellAt(size_t x, size_t y);

    [[nodiscard]] const SpreadsheetCell &getCellAt(size_t x, size_t y) const;

    static const size_t MaxHeight{100};
    static const size_t MaxWidth{100};
private:
    void verifyCoordinate(size_t x, size_t y) const;

    size_t m_width{0};
    size_t m_height{0};
    SpreadsheetCell **m_cells{nullptr};
    static inline size_t ms_counter{0}; // inline or initialize in the implementation file
    const size_t m_id{0};
};

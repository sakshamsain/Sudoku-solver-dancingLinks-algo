#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <string>
#include <array>  // Include this header

// Functions relating to the dancing links component of algorithmX
namespace dl
{
    struct Column;

    struct Cell
    {
        Cell* up;
        Cell* down;
        Cell* left;
        Cell* right;
        Column* col;
        int32_t row; //todo remove and calculate based on index
    };

    struct Column : public Cell
    {
        int32_t count;
        std::string name;

        Column() : count(0) {}
    };

    void cover(Column* cell);
    void uncover(Column* cell);
}

namespace
{
    class Sudoku
    {
        static int32_t constexpr grid_size = 81;
        static int32_t constexpr constraints = grid_size * 4;
        static int32_t constexpr row_size = 729;
        static int32_t constexpr cells_per_row = 4;
        static int32_t constexpr column_size = constraints + 1;

        int32_t row_count = 0;
        dl::Column columns[column_size];
        dl::Cell cells[row_size][cells_per_row];
        dl::Column* root;
        int32_t solution[grid_size];

    public:
        Sudoku();

        void insertRow(std::array<int32_t, cells_per_row> const& items);
        void loadGridAndSolve(std::vector<std::vector<int32_t>> const& grid);

    private:
        void printSolution();
        void search(int32_t k = 0);
    };
}
#endif // SUDOKU_H

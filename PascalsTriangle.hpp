#ifndef DBR_PASCALS_TRIANGLE_HPP
#define DBR_PASCALS_TRIANGLE_HPP

// defines a compile time version of Pascal's Triangle
// 1-indexed for ease of use relative to common usages

// example usage:
//     dbr::PascalsTriangle<7, 5>::value();
// = 15

namespace dbr
{
    // pascal's triangle
    template<int Degree, int Index, typename E = std::bool_constant<(Index > 0 && Index <= Degree)>>
    struct PascalsTriangle;

    // base definition
    template<>
    struct PascalsTriangle<1, 1>
    {
        static int value()
        {
            return 1;
        }
    };

    // recursive definition
    template<int Degree, int Index>
    struct PascalsTriangle<Degree, Index, std::true_type>
    {
        static int value()
        {
            constexpr int PrevDegree = Degree - 1;
            return PascalsTriangle<PrevDegree, Index - 1>::value() + PascalsTriangle<PrevDegree, Index>::value();
        }
    };

    // outside the triangle
    template<int Degree, int Index>
    struct PascalsTriangle<Degree, Index, std::false_type>
    {
        static int value()
        {
            return 0;
        }
    };
}

// from server: 100% by king_originala
// from server: 57% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared roc_unit_0e534b6d9cc556c5.cpp

// Candidate translation unit (score above; library headers required).
namespace ATL
{
    template<class T>
    class ChTraitsCRT;

    template<class T, class Traits>
    class CStringT;
}

template<class T, class Traits = ATL::ChTraitsCRT<T> >
class StrTraitMFC_DLL;

namespace ATL
{
    template<class T, class Traits>
    class CStringT
    {
        T* data;

    public:
        __declspec(dllimport) operator const T*() const throw();
        __declspec(dllimport) ~CStringT() throw();
    };
}

typedef ATL::CStringT<char, StrTraitMFC_DLL<char> > CString;

namespace G3D
{
    struct Color3uint8
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;

        Color3uint8();
    };
}

namespace RBX
{
    class BrickColor
    {
        int number;

    public:
        BrickColor();
        static BrickColor parse(const char* name);
        G3D::Color3uint8 color3uint8() const;
    };
}

unsigned long roc_property_grid_brick_color(CString value)
{
    const G3D::Color3uint8 color = RBX::BrickColor::parse(value).color3uint8();
    return static_cast<unsigned long>(color.r) |
           (static_cast<unsigned long>(color.g) << 8) |
           (static_cast<unsigned long>(color.b) << 16);
}

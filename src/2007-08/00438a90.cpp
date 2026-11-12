// from server: 69% by EspClaude
// from server: 53% by atomic.potato
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_07223b91fad0fc9e.cpp

// Candidate translation unit (score above; library headers required).
// CPropertyGridItemBrickColor::brickColorRef (2008-06 native 00437b90 analog), 2007-08 copy.
// Target needs the wrapper settings  // roc-cl: 50727  and  // roc-flags: /O2 /GS /EHsc /MD
typedef unsigned long COLORREF;
#define RGB(r,g,b) ((COLORREF)(((unsigned char)(r)|((unsigned short)((unsigned char)(g))<<8))|(((unsigned long)(unsigned char)(b))<<16)))
// MFC80 CString (CStringT, one pointer); members imported from MFC80.DLL as the target's IAT calls show.
struct CString {
    void* m_pszData;
    __declspec(dllimport) CString(const CString&);
    __declspec(dllimport) ~CString() throw();
    __declspec(dllimport) operator const char*() const;
};

namespace G3D {
class Color3uint8 {
public:
    unsigned char r, g, b;
    Color3uint8() {}
};
}

namespace RBX {
class BrickColor {
public:
    int number;
    BrickColor();
    G3D::Color3uint8 color3uint8() const;
    static BrickColor parse(const char* name);
};
}

class CPropertyGridItemBrickColor {
public:
    static COLORREF brickColorRef(CString strName);
};

COLORREF CPropertyGridItemBrickColor::brickColorRef(CString strName)
{
    G3D::Color3uint8 color = RBX::BrickColor::parse(strName).color3uint8();
    return RGB(color.r, color.g, color.b);
}

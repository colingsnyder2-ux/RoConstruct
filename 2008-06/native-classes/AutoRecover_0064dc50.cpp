// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided, so RBX::Point is declared locally as a
// polymorphic class with a trivial virtual destructor and no base with a
// non-trivial destructor (the body only re-stores the vtable pointer).
// INFERRED: the 31-byte body (test flag&1, store vtable, operator delete) is the
// scalar deleting destructor shape; the original symbol name ??_E is the result
// of identical-COMDAT folding of the compiler-generated deleting destructor.

namespace RBX {

class Point {
public:
    Point();
    virtual ~Point();
};

Point::Point() {}

Point::~Point() {}

}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so the classes are declared locally.
// INFERRED: the target is the compiler-generated vector deleting destructor of
// a class derived from CXTPPropertyGridItemMetrics. It calls the base
// destructor (0x776720), then the optional global operator delete.
// Base constructor and destructor are declared but not defined here.

class CXTPPropertyGridItemMetrics
{
public:
    CXTPPropertyGridItemMetrics();
    virtual ~CXTPPropertyGridItemMetrics();
};

// INFERRED: the derived class name is unknown, so a unique local name is used.
class Local_00778840 : public CXTPPropertyGridItemMetrics
{
public:
    Local_00778840();
    virtual ~Local_00778840() {}
};

// INFERRED: defining the constructor out of line makes this translation unit
// emit the vtable, and with it the deleting destructor (the target).
Local_00778840::Local_00778840()
{
}

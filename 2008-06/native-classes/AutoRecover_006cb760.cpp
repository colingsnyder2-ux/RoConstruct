// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <afxwin.h>

// INFERRED: no class header was provided, so the classes are declared locally.
// INFERRED: the base derives from the MFC CDialog (same shape as the twin at 0x44f5a0).
// Its destructor (0x6cb700) is declared but not defined here.
// The target is the compiler-generated deleting destructor of the derived
// class: an inlined, empty derived destructor that calls the base
// destructor, then the optional global operator delete.

class Local_006cb700 : public CDialog
{
public:
    Local_006cb700();
    virtual ~Local_006cb700();
};

class Local_006cb760 : public Local_006cb700
{
public:
    Local_006cb760();
    virtual ~Local_006cb760() {}
};

// INFERRED: defining the constructor out of line makes this translation unit
// emit the vtable, and with it the deleting destructor (the target).
Local_006cb760::Local_006cb760()
{
}

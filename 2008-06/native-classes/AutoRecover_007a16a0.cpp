// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <afxwin.h>

// INFERRED: no class header was provided, so CXTMemDC is declared locally.
// INFERRED: CXTMemDC derives from the MFC CDC.
// The target is the compiler-generated scalar deleting destructor of CXTMemDC.
// It calls the out-of-line destructor (??1CXTMemDC@@UAE@XZ at 0x7a1590),
// then the optional global operator delete.
class CXTMemDC : public CDC
{
public:
    CXTMemDC();
    virtual ~CXTMemDC();
};

// INFERRED: defining the constructor out of line makes this translation unit
// emit the vtable, and with it the deleting destructor (the target).
CXTMemDC::CXTMemDC()
{
}

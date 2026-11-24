// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <afxwin.h>

// INFERRED: no class header was provided, so the classes are declared locally.
// INFERRED: CSaveToRobloxDialog derives from the MFC CDialog (names and /D_AFXDLL suggest it).
// Its constructor and destructor (??1CSaveToRobloxDialog@@UAE@XZ at 0x45fe20)
// are declared but not defined here.
// The target is the compiler-generated vector deleting destructor of
// CPublishAsPlaceDialog: an inlined, empty ~CPublishAsPlaceDialog that calls
// the base destructor, then the optional global operator delete.

class CSaveToRobloxDialog : public CDialog
{
public:
    CSaveToRobloxDialog();
    virtual ~CSaveToRobloxDialog();
};

class CPublishAsPlaceDialog : public CSaveToRobloxDialog
{
public:
    CPublishAsPlaceDialog();
    virtual ~CPublishAsPlaceDialog() {}
};

// INFERRED: defining the constructor out of line makes this translation unit
// emit the vtable, and with it the deleting destructor (the target).
CPublishAsPlaceDialog::CPublishAsPlaceDialog()
{
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

class CXTPDockingPane;

extern "C" CXTPDockingPane* __fastcall fn_00707950(
    CXTPDockingPane* self, int unusedEdx, unsigned int flags);

// INFERRED: The destructor is protected and virtual, as indicated by its decorated name.
class CXTPDockingPane
{
protected:
    virtual ~CXTPDockingPane();

    friend CXTPDockingPane* __fastcall fn_00707950(
        CXTPDockingPane* self, int unusedEdx, unsigned int flags);
};

extern "C" CXTPDockingPane* __fastcall fn_00707950(
    CXTPDockingPane* self, int unusedEdx, unsigned int flags)
{
    self->CXTPDockingPane::~CXTPDockingPane();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

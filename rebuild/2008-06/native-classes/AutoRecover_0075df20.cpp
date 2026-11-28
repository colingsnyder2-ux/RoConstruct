// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <afxwin.h>
#include <afxole.h>
#include <new>

// INFERRED: The target is a scalar deleting destructor for a COleDropTarget-derived object.
extern "C" COleDropTarget* __fastcall fn_0075df20(
    COleDropTarget* self, int unusedEdx, unsigned int flags)
{
    self->COleDropTarget::~COleDropTarget();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

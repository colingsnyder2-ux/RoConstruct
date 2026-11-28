// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: Only the destructor declaration is needed here.
class CXTPControlButton
{
public:
    virtual ~CXTPControlButton();
};

extern "C" CXTPControlButton* __fastcall fn_007457e0(
    CXTPControlButton* self, int unusedEdx, int flags)
{
    self->CXTPControlButton::~CXTPControlButton();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

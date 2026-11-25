// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: Only the destructor declaration is needed here.
class CXTPImageManagerIcon
{
public:
    virtual ~CXTPImageManagerIcon();
};

extern "C" CXTPImageManagerIcon* __fastcall fn_006bdea0(
    CXTPImageManagerIcon* self, int unusedEdx, unsigned int flags)
{
    self->CXTPImageManagerIcon::~CXTPImageManagerIcon();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

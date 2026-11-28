// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: Only the destructor declaration is needed for this call.
class CXTPControls
{
public:
    virtual ~CXTPControls();
};

extern "C" CXTPControls* __fastcall fn_00798f70(CXTPControls* self, int unusedEdx, unsigned int flags)
{
    self->CXTPControls::~CXTPControls();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

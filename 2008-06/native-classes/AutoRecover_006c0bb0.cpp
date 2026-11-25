// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: The destructor is virtual; no native class header was found.
class CXTPImageManager
{
public:
    virtual ~CXTPImageManager();
};

extern "C" CXTPImageManager* __fastcall fn_006c0bb0(
    CXTPImageManager* self, int unusedEdx, unsigned int flags)
{
    self->CXTPImageManager::~CXTPImageManager();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

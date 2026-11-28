// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: The class declaration exposes the named destructor.
class CXTPPropertyGridPaintManager
{
public:
    virtual ~CXTPPropertyGridPaintManager();
};

extern "C" CXTPPropertyGridPaintManager* __fastcall fn_0077a3c0(
    CXTPPropertyGridPaintManager* self, int unusedEdx, unsigned int flags)
{
    self->CXTPPropertyGridPaintManager::~CXTPPropertyGridPaintManager();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

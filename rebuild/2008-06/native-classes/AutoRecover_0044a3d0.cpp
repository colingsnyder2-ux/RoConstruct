// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <ostream>

// INFERRED: standalone instance of std::basic_ostream<char>::sentry::~sentry (MSVC 2008 STL).
extern "C" void __fastcall fn_0044a3d0(std::ostream::sentry* self, int unusedEdx)
{
    self->~sentry();
}

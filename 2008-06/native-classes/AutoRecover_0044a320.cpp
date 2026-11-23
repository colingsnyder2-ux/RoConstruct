// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <ostream>
#include <new>

// INFERRED: this is the out-of-line copy of std::basic_ostream<char>::sentry::sentry(ostream&).
// Layout: [0] = _Myostr reference, [4] = _Ok.
extern "C" std::ostream::sentry* __fastcall fn_0044a320(std::ostream::sentry* self, int unusedEdx, std::ostream* os)
{
    return new (self) std::ostream::sentry(*os);
}

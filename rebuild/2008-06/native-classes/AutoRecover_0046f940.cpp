// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

// INFERRED: checked-iterator layout {container, ptr}; container -4 means "no check" sentinel.
struct StrIter {
    const std::string* cont;
    const char* ptr;
};

struct StrPeek : std::string {
    const char* peek() const { return _Myptr(); }
};

extern "C" const char* __fastcall fn_0046f940(StrIter* self, int unusedEdx)
{
    if (self->cont != (const std::string*)-4) {
        if (self->cont == 0)
            _invalid_parameter_noinfo();
        if (self->ptr >= static_cast<const StrPeek*>(self->cont)->peek() + self->cont->size())
            _invalid_parameter_noinfo();
    }
    return self->ptr;
}

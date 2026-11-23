// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

// INFERRED: checked string iterator (_Mycont at +0, _Ptr at +4); -4 marks an unchecked iterator
struct StrIter {
    const std::string* cont;
    const char* ptr;
};

struct StrAccess : std::string {
    const char* myptr() const { return _Myptr(); }
};

extern "C" StrIter* __fastcall fn_0046f980(StrIter* self, int unusedEdx)
{
    if (self->cont != (const std::string*)-4) {
        if (self->cont == 0)
            _invalid_parameter_noinfo();
        if (!(self->ptr < static_cast<const StrAccess*>(self->cont)->myptr() + self->cont->size()))
            _invalid_parameter_noinfo();
    }
    ++self->ptr;
    return self;
}

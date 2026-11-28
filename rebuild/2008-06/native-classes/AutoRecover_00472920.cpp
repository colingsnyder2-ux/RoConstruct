// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdexcept>
#include <string>

struct __declspec(novtable) Local_472920 : public std::runtime_error
{
    std::string reason;
    std::string filename;
    __forceinline ~Local_472920() {}
};

extern "C" void __fastcall fn_00472920(Local_472920* self, int unusedEdx)
{
    self->Local_472920::~Local_472920();
}

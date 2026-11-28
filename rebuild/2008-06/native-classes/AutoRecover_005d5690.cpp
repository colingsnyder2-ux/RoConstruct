// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

extern "C" void __fastcall fn_005d3bc0(void* self);

// INFERRED: base dtor is fn_005d3bc0 (FactoryProduct<Hole,Feature,...>), string member at +0x134
struct Local_005d5690_Base {
    char pad[0x134];
    __forceinline ~Local_005d5690_Base() { fn_005d3bc0(this); }
};

struct Local_005d5690 : Local_005d5690_Base {
    std::string s;
    __forceinline ~Local_005d5690() {}
};

extern "C" void __fastcall fn_005d5690(Local_005d5690* self, int unusedEdx)
{
    self->~Local_005d5690();
}

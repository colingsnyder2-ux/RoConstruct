// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: The string begins four bytes into the object.
struct Local_00413460 {
    char prefix[4];
    std::string value;
};

// INFERRED: The required cdecl signature passes self on the stack.
// The disassembly instead receives the object in ECX, so this cannot match its ABI.
extern "C" void __fastcall fn_00413460(Local_00413460* self, int)
{
    self->value.~basic_string();
}

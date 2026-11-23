// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: layout from the disassembly. +0 callback, +8 payload, +0x28 std::string, +0x48 int.
struct fn_00596400_Node;
typedef void (__cdecl *fn_00596400_Callback)(void* payload, std::string name, int value);

struct fn_00596400_Node {
    fn_00596400_Callback callback;
    char pad04[4];
    char payload[0x20];
    std::string name;
    int value;
};

extern "C" void fn_00596400(fn_00596400_Node** arg)
{
    fn_00596400_Node* n = *arg;
    n->callback(n->payload, n->name, n->value);
}

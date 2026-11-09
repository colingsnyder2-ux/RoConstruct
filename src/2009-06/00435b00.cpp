// from server: 100% by EspClaude
// roc 2009-06 00435b00  unit: MVCXTPPropertyGridItem::?$XItem  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00435b00
//
// 00435b00  51                   push ecx
// 00435b01  53                   push ebx
// 00435b02  8d442404             lea eax, [esp + 4]
// 00435b06  50                   push eax
// 00435b07  e844bbffff           call 0x431650
// 00435b0c  8bc8                 mov ecx, eax
// 00435b0e  ff155cfb8900         call dword ptr [0x89fb5c]
// 00435b14  8d4c2404             lea ecx, [esp + 4]
// 00435b18  8ad8                 mov bl, al
// 00435b1a  ff1510fd8900         call dword ptr [0x89fd10]
// 00435b20  8ac3                 mov al, bl
// 00435b22  5b                   pop ebx
// 00435b23  59                   pop ecx
// 00435b24  c3                   ret 
// copied from an identical function in another client (function ?f@X_00437ed0@ns_ROCX000000@@QAE_NXZ)

namespace ns_ROCX000000 {
struct Str_00437ed0 {
    int words[8];
};

extern bool (__thiscall* query)(Str_00437ed0*);
extern void (__thiscall* destroy)(Str_00437ed0*);

struct X_00437ed0 {
    char pad[0xa4];
    Str_00437ed0 value;
    Str_00437ed0* copy(Str_00437ed0* out);
    bool f();
};

bool X_00437ed0::f()
{
    int storage;
    bool result = query(copy(reinterpret_cast<Str_00437ed0*>(&storage)));
    destroy(reinterpret_cast<Str_00437ed0*>(&storage));
    return result;
}
}

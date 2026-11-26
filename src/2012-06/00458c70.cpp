// from server: 100% by Xemicl
// roc 2012-06 00458c70  unit: MVCXTPPropertyGridItem::?$XItem  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00458c70
//
// 00458c70  51                   push ecx
// 00458c71  53                   push ebx
// 00458c72  8d442404             lea eax, [esp + 4]
// 00458c76  50                   push eax
// 00458c77  e8c4b9ffff           call 0x454640
// 00458c7c  8bc8                 mov ecx, eax
// 00458c7e  ff156046b200         call dword ptr [0xb24660]
// 00458c84  8d4c2404             lea ecx, [esp + 4]
// 00458c88  8ad8                 mov bl, al
// 00458c8a  ff15d047b200         call dword ptr [0xb247d0]
// 00458c90  8ac3                 mov al, bl
// 00458c92  5b                   pop ebx
// 00458c93  59                   pop ecx
// 00458c94  c3                   ret 
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
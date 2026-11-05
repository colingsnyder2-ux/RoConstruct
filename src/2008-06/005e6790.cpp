// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 005e6790  unit: RBX::Clump  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e6790
//
// 005e6790  8b442404             mov eax, dword ptr [esp + 4]
// 005e6794  56                   push esi
// 005e6795  50                   push eax
// 005e6796  8bf1                 mov esi, ecx
// 005e6798  e853f8ffff           call 0x5e5ff0
// 005e679d  b001                 mov al, 1
// 005e679f  884614               mov byte ptr [esi + 0x14], al
// 005e67a2  884654               mov byte ptr [esi + 0x54], al
// 005e67a5  884669               mov byte ptr [esi + 0x69], al
// 005e67a8  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e67ab  5e                   pop esi
// 005e67ac  85c9                 test ecx, ecx
// 005e67ae  7405                 je 0x5e67b5
// 005e67b0  e8ebfaffff           call 0x5e62a0
// 005e67b5  c20400               ret 4
#include <intrin.h>

struct Owner {
    char pad_00[0x14];
    bool field_14;
    char pad_15[0x0b];
    Owner* field_20;
    char pad_24[0x30];
    bool field_54;
    char pad_55[0x14];
    bool field_69;

    void reset(int value);
    void update();
    void func_005e6790(int value);
};

void Owner::func_005e6790(int value)
{
    reset(value);
    field_14 = true;
    field_54 = true;
    field_69 = true;
    _ReadWriteBarrier();
    if (field_20)
        field_20->update();
}

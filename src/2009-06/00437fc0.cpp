// from server: 100% by EspClaude
// roc 2009-06 00437fc0  unit: Vector3Item  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00437fc0
//
// 00437fc0  53                   push ebx
// 00437fc1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00437fc5  56                   push esi
// 00437fc6  57                   push edi
// 00437fc7  53                   push ebx
// 00437fc8  8bf1                 mov esi, ecx
// 00437fca  e8d1e1ffff           call 0x4361a0
// 00437fcf  83c624               add esi, 0x24
// 00437fd2  bf03000000           mov edi, 3
// 00437fd7  833e00               cmp dword ptr [esi], 0
// 00437fda  740f                 je 0x437feb
// 00437fdc  8b06                 mov eax, dword ptr [esi]
// 00437fde  8d880c010000         lea ecx, [eax + 0x10c]
// 00437fe4  8b01                 mov eax, dword ptr [ecx]
// 00437fe6  8b10                 mov edx, dword ptr [eax]
// 00437fe8  53                   push ebx
// 00437fe9  ffd2                 call edx
// 00437feb  83c604               add esi, 4
// 00437fee  83ef01               sub edi, 1
// 00437ff1  75e4                 jne 0x437fd7
// 00437ff3  5f                   pop edi
// 00437ff4  5e                   pop esi
// 00437ff5  5b                   pop ebx
// 00437ff6  c20400               ret 4
// copied from an identical function in another client (function ?setValue@Vector3Item@ns_ROCX00000a@@QAEXPAX@Z)

namespace ns_ROCX00000a {
// from server: 91% by colin
struct CXTPPropertyGridItem {
    char reserved00[0x24];
    void* items[3];

    void setValue(void* value);
};

struct Vector3Item : CXTPPropertyGridItem {
    void setValue(void* value);
};

void Vector3Item::setValue(void* value)
{
    CXTPPropertyGridItem::setValue(value);
    for (int i = 0; i < 3; ++i) {
        if (items[i] != 0) {
            void** vtable = *(void***)((char*)items[i] + 0x10C);
            ((void (__thiscall*)(void*, void*))vtable[0])((char*)items[i] + 0x10C, value);
        }
    }
}
}

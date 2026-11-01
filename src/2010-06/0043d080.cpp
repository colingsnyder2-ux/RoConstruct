// from server: 100% by Yeetserama
// roc 2010-06 0043d080  unit: AxesItem  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043d080
//
// 0043d080  53                   push ebx
// 0043d081  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0043d085  56                   push esi
// 0043d086  57                   push edi
// 0043d087  53                   push ebx
// 0043d088  8bf1                 mov esi, ecx
// 0043d08a  e841c9ffff           call 0x4399d0
// 0043d08f  83c624               add esi, 0x24
// 0043d092  bf03000000           mov edi, 3
// 0043d097  833e00               cmp dword ptr [esi], 0
// 0043d09a  740f                 je 0x43d0ab
// 0043d09c  8b06                 mov eax, dword ptr [esi]
// 0043d09e  8d880c010000         lea ecx, [eax + 0x10c]
// 0043d0a4  8b01                 mov eax, dword ptr [ecx]
// 0043d0a6  8b10                 mov edx, dword ptr [eax]
// 0043d0a8  53                   push ebx
// 0043d0a9  ffd2                 call edx
// 0043d0ab  83c604               add esi, 4
// 0043d0ae  83ef01               sub edi, 1
// 0043d0b1  75e4                 jne 0x43d097
// 0043d0b3  5f                   pop edi
// 0043d0b4  5e                   pop esi
// 0043d0b5  5b                   pop ebx
// 0043d0b6  c20400               ret 4
// copied from an identical function in another client (function ?setValue@Vector3Item@ns_ROCX000003@@QAEXPAX@Z)

namespace ns_ROCX000003 {
// from server: 100% by Espeon
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

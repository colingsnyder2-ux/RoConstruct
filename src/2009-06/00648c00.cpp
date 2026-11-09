// from server: 100% by EspClaude
// from server: 86% by EspClaude
// roc 2009-06 00648c00  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00648c00
//
// 00648c00  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 00648c06  85c0                 test eax, eax
// 00648c08  742d                 je 0x648c37
// 00648c0a  d981bc000000         fld dword ptr [ecx + 0xbc]
// 00648c10  83ec0c               sub esp, 0xc
// 00648c13  d95c2408             fstp dword ptr [esp + 8]
// 00648c17  d981b8000000         fld dword ptr [ecx + 0xb8]
// 00648c1d  d95c2404             fstp dword ptr [esp + 4]
// 00648c21  d981b4000000         fld dword ptr [ecx + 0xb4]
// 00648c27  d91c24               fstp dword ptr [esp]
// 00648c2a  50                   push eax
// 00648c2b  e814f20c00           call 0x717e44
// 00648c30  50                   push eax
// 00648c31  e87ae8ffff           call 0x6474b0
// 00648c36  59                   pop ecx
// 00648c37  c20400               ret 4

// from server: 100% by tester
// roc 2008-06 005b97b0  unit: VSoundIdTypedPropertyDescriptor::?$FactoryProduct  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b97b0
//
// 005b97b0  8b8134010000         mov eax, dword ptr [ecx + 0x134]
// 005b97b6  85c0                 test eax, eax
// 005b97b8  742d                 je 0x5b97e7
// 005b97ba  d98164010000         fld dword ptr [ecx + 0x164]
// 005b97c0  83ec0c               sub esp, 0xc
// 005b97c3  d95c2408             fstp dword ptr [esp + 8]
// 005b97c7  d98160010000         fld dword ptr [ecx + 0x160]
// 005b97cd  d95c2404             fstp dword ptr [esp + 4]
// 005b97d1  d9815c010000         fld dword ptr [ecx + 0x15c]
// 005b97d7  d91c24               fstp dword ptr [esp]
// 005b97da  50                   push eax
// 005b97db  e80e640e00           call 0x69fbee
// 005b97e0  50                   push eax
// 005b97e1  e8baefffff           call 0x5b87a0
// 005b97e6  59                   pop ecx
// 005b97e7  c3                   ret 

struct VSoundIdTypedPropertyDescriptor {
    char pad[0x8c];
    int field134;
    char pad2[0xb4 - 0x90];
    float field15c;
    float field160;
    float field164;
    void method(int);
};

extern "C" int __stdcall sub_69fbee(int, float, float, float);
extern "C" void __cdecl sub_5b87a0(int);

void VSoundIdTypedPropertyDescriptor::method(int) {
    if (field134 != 0) {
        sub_5b87a0(sub_69fbee(field134, field15c, field160, field164));
    }
}

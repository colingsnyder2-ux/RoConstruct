// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fe280  unit: RBX::VInstance::?$NonFactoryProduct  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fe280
//
// 005fe280  6aff                 push -1
// 005fe282  68e87e7d00           push 0x7d7ee8
// 005fe287  64a100000000         mov eax, dword ptr fs:[0]
// 005fe28d  50                   push eax
// 005fe28e  64892500000000       mov dword ptr fs:[0], esp
// 005fe295  51                   push ecx
// 005fe296  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fe29a  56                   push esi
// 005fe29b  8bf1                 mov esi, ecx
// 005fe29d  50                   push eax
// 005fe29e  89742408             mov dword ptr [esp + 8], esi
// 005fe2a2  e8394e0400           call 0x6430e0
// 005fe2a7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005fe2ab  51                   push ecx
// 005fe2ac  8d5624               lea edx, [esi + 0x24]
// 005fe2af  52                   push edx
// 005fe2b0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005fe2b8  c7063c188400         mov dword ptr [esi], 0x84183c
// 005fe2be  c7460424188400       mov dword ptr [esi + 4], 0x841824
// 005fe2c5  e876a70100           call 0x618a40
// 005fe2ca  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005fe2ce  83c408               add esp, 8
// 005fe2d1  8bc6                 mov eax, esi
// 005fe2d3  5e                   pop esi
// 005fe2d4  64890d00000000       mov dword ptr fs:[0], ecx
// 005fe2db  83c410               add esp, 0x10
// 005fe2de  c20800               ret 8

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char padding[28];
    Base(void*);
    ~Base();
};

extern void __cdecl initialize(void*, const void*);

struct S : Base {
    char value[8];
    S(void*, const void*);
    ~S();
};

S::S(void* first, const void* second)
    : Base(first)
{
    initialize(value, second);
}

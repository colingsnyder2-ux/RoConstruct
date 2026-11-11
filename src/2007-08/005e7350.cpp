// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 71% by tajop
// roc 2007-08 005e7350  unit: RBX::Flag  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e7350
//
// 005e7350  6aff                 push -1
// 005e7352  6858ae7500           push 0x75ae58
// 005e7357  64a100000000         mov eax, dword ptr fs:[0]
// 005e735d  50                   push eax
// 005e735e  64892500000000       mov dword ptr fs:[0], esp
// 005e7365  51                   push ecx
// 005e7366  837c241400           cmp dword ptr [esp + 0x14], 0
// 005e736b  56                   push esi
// 005e736c  8bf1                 mov esi, ecx
// 005e736e  89742404             mov dword ptr [esp + 4], esi
// 005e7372  7414                 je 0x5e7388
// 005e7374  c786680100001cb77b00 mov dword ptr [esi + 0x168], 0x7bb71c
// 005e737e  c78620020000cc4c7a00 mov dword ptr [esi + 0x220], 0x7a4ccc
// 005e7388  6a00                 push 0
// 005e738a  e861eeffff           call 0x5e61f0
// 005e738f  8b8668010000         mov eax, dword ptr [esi + 0x168]
// 005e7395  c7061cd67b00         mov dword ptr [esi], 0x7bd61c
// 005e739b  c7460410d67b00       mov dword ptr [esi + 4], 0x7bd610
// 005e73a2  c7461008d67b00       mov dword ptr [esi + 0x10], 0x7bd608
// 005e73a9  c74614f8d57b00       mov dword ptr [esi + 0x14], 0x7bd5f8
// 005e73b0  c7462ce8d57b00       mov dword ptr [esi + 0x2c], 0x7bd5e8
// 005e73b7  c74644d8d57b00       mov dword ptr [esi + 0x44], 0x7bd5d8
// 005e73be  c7465cc8d57b00       mov dword ptr [esi + 0x5c], 0x7bd5c8
// 005e73c5  c74674b8d57b00       mov dword ptr [esi + 0x74], 0x7bd5b8
// 005e73cc  c7868c000000a8d57b00 mov dword ptr [esi + 0x8c], 0x7bd5a8
// 005e73d6  c786e8000000a0d57b00 mov dword ptr [esi + 0xe8], 0x7bd5a0
// 005e73e0  c7865801000088d57b00 mov dword ptr [esi + 0x158], 0x7bd588
// 005e73ea  8b4804               mov ecx, dword ptr [eax + 4]
// 005e73ed  c784316801000080d57b00 mov dword ptr [ecx + esi + 0x168], 0x7bd580
// 005e73f8  8b9668010000         mov edx, dword ptr [esi + 0x168]
// 005e73fe  8b4204               mov eax, dword ptr [edx + 4]
// 005e7401  8d8848ffffff         lea ecx, [eax - 0xb8]
// 005e7407  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005e740f  898c3064010000       mov dword ptr [eax + esi + 0x164], ecx
// 005e7416  e8159efaff           call 0x591230
// 005e741b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005e741f  89460c               mov dword ptr [esi + 0xc], eax
// 005e7422  8bc6                 mov eax, esi
// 005e7424  5e                   pop esi
// 005e7425  64890d00000000       mov dword ptr fs:[0], ecx
// 005e742c  83c410               add esp, 0x10
// 005e742f  c20400               ret 4

struct FlagBase {
    char pad0[0xc];
    int field_c;
    char pad1[0x168 - 0x10];
    void* field_168;
    char pad2[0x220 - 0x16c];
    void* field_220;
    FlagBase(int);
    ~FlagBase();
};

struct Flag : FlagBase {
    Flag(int);
};

int sub_591230();

Flag::Flag(int flag)
    : FlagBase((flag != 0 ? (field_168 = (void*)0x7bb71c, field_220 = (void*)0x7a4ccc, 0) : 0))
{
    *(int*)((char*)this + 0x00) = 0x7bd61c;
    *(int*)((char*)this + 0x04) = 0x7bd610;
    *(int*)((char*)this + 0x10) = 0x7bd608;
    *(int*)((char*)this + 0x14) = 0x7bd5f8;
    *(int*)((char*)this + 0x2c) = 0x7bd5e8;
    *(int*)((char*)this + 0x44) = 0x7bd5d8;
    *(int*)((char*)this + 0x5c) = 0x7bd5c8;
    *(int*)((char*)this + 0x74) = 0x7bd5b8;
    *(int*)((char*)this + 0x8c) = 0x7bd5a8;
    *(int*)((char*)this + 0xe8) = 0x7bd5a0;
    *(int*)((char*)this + 0x158) = 0x7bd588;
    int v = *(int*)((char*)field_168 + 4);
    *(int*)((char*)this + v + 0x168) = 0x7bd580;
    int w = *(int*)((char*)field_168 + 4);
    *(int*)((char*)this + w + 0x164) = w - 0xb8;
    field_c = sub_591230();
}

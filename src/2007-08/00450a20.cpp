// from server: 100% by Intel_Inside
// from server: 29% by tester
// roc 2007-08 00450a20  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 100 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Make this compile to the exact bytes below, then: roc check 2007-08 00450a20
//
// 00450a20  6aff                 push -1
// 00450a22  68eaf27500           push 0x75f2ea
// 00450a27  64a100000000         mov eax, dword ptr fs:[0]
// 00450a2d  50                   push eax
// 00450a2e  51                   push ecx
// 00450a2f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00450a34  33c4                 xor eax, esp
// 00450a36  50                   push eax
// 00450a37  8d442408             lea eax, [esp + 8]
// 00450a3b  64a300000000         mov dword ptr fs:[0], eax
// 00450a41  6a7c                 push 0x7c
// 00450a43  e8aef41d00           call 0x62fef6
// 00450a48  83c404               add esp, 4
// 00450a4b  89442404             mov dword ptr [esp + 4], eax
// 00450a4f  85c0                 test eax, eax
// 00450a51  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00450a59  7417                 je 0x450a72
// 00450a5b  8bc8                 mov ecx, eax
// 00450a5d  e8beeeffff           call 0x44f920
// 00450a62  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00450a66  64890d00000000       mov dword ptr fs:[0], ecx
// 00450a6d  59                   pop ecx
// 00450a6e  83c410               add esp, 0x10
// 00450a71  c3                   ret
// 00450a72  33c0                 xor eax, eax
// 00450a74  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00450a78  64890d00000000       mov dword ptr fs:[0], ecx
// 00450a7f  59                   pop ecx
// 00450a80  83c410               add esp, 0x10
// 00450a83  c3                   ret

// Twin 0040c7b0/00430770/004357a0 pattern: simple factory with char storage[]

struct VVisitFactoryProductCreator
{
    char storage[0x7c];
    VVisitFactoryProductCreator();
};

VVisitFactoryProductCreator* __cdecl createVVisitFactoryProductCreator()
{
    return new VVisitFactoryProductCreator;
}
// from server: 100% by Intel_Inside
// from server: 32% by colin
// roc 2007-08 004357a0  unit: CDeclarationView  size: 103 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Make this compile to the exact bytes below, then: roc check 2007-08 004357a0
//
// 004357a0  6aff                 push -1
// 004357a2  68eaf27500           push 0x75f2ea
// 004357a7  64a100000000         mov eax, dword ptr fs:[0]
// 004357ad  50                   push eax
// 004357ae  51                   push ecx
// 004357af  a188518b00           mov eax, dword ptr [0x8b5188]
// 004357b4  33c4                 xor eax, esp
// 004357b6  50                   push eax
// 004357b7  8d442408             lea eax, [esp + 8]
// 004357bb  64a300000000         mov dword ptr fs:[0], eax
// 004357c1  6810010000           push 0x110
// 004357c6  e82ba71f00           call 0x62fef6
// 004357cb  83c404               add esp, 4
// 004357ce  89442404             mov dword ptr [esp + 4], eax
// 004357d2  85c0                 test eax, eax
// 004357d4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004357dc  7417                 je 0x4357f5
// 004357de  8bc8                 mov ecx, eax
// 004357e0  e87bfeffff           call 0x435660
// 004357e5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004357e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004357f0  59                   pop ecx
// 004357f1  83c410               add esp, 0x10
// 004357f4  c3                   ret
// 004357f5  33c0                 xor eax, eax
// 004357f7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004357fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00435802  59                   pop ecx
// 00435803  83c410               add esp, 0x10
// 00435806  c3                   ret

// Twin pattern from 0040c7b0/00430770/00434700: simple factory with char storage[]

struct CDeclarationView
{
    char storage[0x110];
    CDeclarationView();
};

CDeclarationView* __cdecl createDeclarationView()
{
    return new CDeclarationView;
}
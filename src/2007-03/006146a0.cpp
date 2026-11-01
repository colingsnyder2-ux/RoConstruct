// from server: 100% by auto
// roc 2007-03 006146a0  unit: seg_00610000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006146a0
//
// 006146a0  53                   push ebx
// 006146a1  56                   push esi
// 006146a2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006146a6  8b06                 mov eax, dword ptr [esi]
// 006146a8  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 006146ab  0fb6484b             movzx ecx, byte ptr [eax + 0x4b]
// 006146af  035c2410             add ebx, dword ptr [esp + 0x10]
// 006146b3  3bd9                 cmp ebx, ecx
// 006146b5  7e1e                 jle 0x6146d5
// 006146b7  81fbfa000000         cmp ebx, 0xfa
// 006146bd  7c11                 jl 0x6146d0
// 006146bf  8b560c               mov edx, dword ptr [esi + 0xc]
// 006146c2  6894207c00           push 0x7c2094
// 006146c7  52                   push edx
// 006146c8  e8a3c8feff           call 0x600f70
// 006146cd  83c408               add esp, 8
// 006146d0  8b06                 mov eax, dword ptr [esi]
// 006146d2  88584b               mov byte ptr [eax + 0x4b], bl
// 006146d5  5e                   pop esi
// 006146d6  5b                   pop ebx
// 006146d7  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_checkstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c

// from server: 100% by auto
// roc 2009-12 007dc120  unit: RBX::GroupDragTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc120
//
// 007dc120  53                   push ebx
// 007dc121  56                   push esi
// 007dc122  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dc126  8b06                 mov eax, dword ptr [esi]
// 007dc128  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 007dc12b  0fb6484b             movzx ecx, byte ptr [eax + 0x4b]
// 007dc12f  035c2410             add ebx, dword ptr [esp + 0x10]
// 007dc133  3bd9                 cmp ebx, ecx
// 007dc135  7e1e                 jle 0x7dc155
// 007dc137  81fbfa000000         cmp ebx, 0xfa
// 007dc13d  7c11                 jl 0x7dc150
// 007dc13f  8b560c               mov edx, dword ptr [esi + 0xc]
// 007dc142  6834fb9e00           push 0x9efb34
// 007dc147  52                   push edx
// 007dc148  e8f391ffff           call 0x7d5340
// 007dc14d  83c408               add esp, 8
// 007dc150  8b06                 mov eax, dword ptr [esi]
// 007dc152  88584b               mov byte ptr [eax + 0x4b], bl
// 007dc155  5e                   pop esi
// 007dc156  5b                   pop ebx
// 007dc157  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_checkstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

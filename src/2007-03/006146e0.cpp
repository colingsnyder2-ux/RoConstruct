// from server: 100% by auto
// roc 2007-03 006146e0  unit: seg_00610000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006146e0
//
// 006146e0  53                   push ebx
// 006146e1  56                   push esi
// 006146e2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006146e6  8b06                 mov eax, dword ptr [esi]
// 006146e8  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 006146eb  0fb6484b             movzx ecx, byte ptr [eax + 0x4b]
// 006146ef  57                   push edi
// 006146f0  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006146f4  03df                 add ebx, edi
// 006146f6  3bd9                 cmp ebx, ecx
// 006146f8  7e1e                 jle 0x614718
// 006146fa  81fbfa000000         cmp ebx, 0xfa
// 00614700  7c11                 jl 0x614713
// 00614702  8b560c               mov edx, dword ptr [esi + 0xc]
// 00614705  6894207c00           push 0x7c2094
// 0061470a  52                   push edx
// 0061470b  e860c8feff           call 0x600f70
// 00614710  83c408               add esp, 8
// 00614713  8b06                 mov eax, dword ptr [esi]
// 00614715  88584b               mov byte ptr [eax + 0x4b], bl
// 00614718  017e24               add dword ptr [esi + 0x24], edi
// 0061471b  5f                   pop edi
// 0061471c  5e                   pop esi
// 0061471d  5b                   pop ebx
// 0061471e  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_reserveregs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c

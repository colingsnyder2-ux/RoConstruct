// from server: 100% by auto
// roc 2009-12 007dc160  unit: RBX::GroupDragTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc160
//
// 007dc160  53                   push ebx
// 007dc161  56                   push esi
// 007dc162  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dc166  8b06                 mov eax, dword ptr [esi]
// 007dc168  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 007dc16b  0fb6484b             movzx ecx, byte ptr [eax + 0x4b]
// 007dc16f  57                   push edi
// 007dc170  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007dc174  03df                 add ebx, edi
// 007dc176  3bd9                 cmp ebx, ecx
// 007dc178  7e1e                 jle 0x7dc198
// 007dc17a  81fbfa000000         cmp ebx, 0xfa
// 007dc180  7c11                 jl 0x7dc193
// 007dc182  8b560c               mov edx, dword ptr [esi + 0xc]
// 007dc185  6834fb9e00           push 0x9efb34
// 007dc18a  52                   push edx
// 007dc18b  e8b091ffff           call 0x7d5340
// 007dc190  83c408               add esp, 8
// 007dc193  8b06                 mov eax, dword ptr [esi]
// 007dc195  88584b               mov byte ptr [eax + 0x4b], bl
// 007dc198  017e24               add dword ptr [esi + 0x24], edi
// 007dc19b  5f                   pop edi
// 007dc19c  5e                   pop esi
// 007dc19d  5b                   pop ebx
// 007dc19e  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_reserveregs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

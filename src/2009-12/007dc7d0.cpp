// from server: 100% by auto
// roc 2009-12 007dc7d0  unit: RBX::GroupDragTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc7d0
//
// 007dc7d0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007dc7d4  56                   push esi
// 007dc7d5  8b742408             mov esi, dword ptr [esp + 8]
// 007dc7d9  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dc7dc  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc7df  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dc7e3  42                   inc edx
// 007dc7e4  c1e217               shl edx, 0x17
// 007dc7e7  c1e006               shl eax, 6
// 007dc7ea  0bd0                 or edx, eax
// 007dc7ec  51                   push ecx
// 007dc7ed  83ca1e               or edx, 0x1e
// 007dc7f0  52                   push edx
// 007dc7f1  e86afdffff           call 0x7dc560
// 007dc7f6  83c408               add esp, 8
// 007dc7f9  5e                   pop esi
// 007dc7fa  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_ret)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

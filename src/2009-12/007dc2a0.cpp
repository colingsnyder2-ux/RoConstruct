// from server: 100% by auto
// roc 2009-12 007dc2a0  unit: RBX::GroupDragTool  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc2a0
//
// 007dc2a0  83ec10               sub esp, 0x10
// 007dc2a3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dc2a7  8d0c24               lea ecx, [esp]
// 007dc2aa  890424               mov dword ptr [esp], eax
// 007dc2ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dc2b1  51                   push ecx
// 007dc2b2  c744240c04000000     mov dword ptr [esp + 0xc], 4
// 007dc2ba  e801ffffff           call 0x7dc1c0
// 007dc2bf  83c414               add esp, 0x14
// 007dc2c2  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_stringK)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

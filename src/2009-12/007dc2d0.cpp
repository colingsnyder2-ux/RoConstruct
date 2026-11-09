// from server: 100% by auto
// roc 2009-12 007dc2d0  unit: RBX::GroupDragTool  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc2d0
//
// 007dc2d0  83ec10               sub esp, 0x10
// 007dc2d3  dd442418             fld qword ptr [esp + 0x18]
// 007dc2d7  8d0424               lea eax, [esp]
// 007dc2da  50                   push eax
// 007dc2db  dd5c2404             fstp qword ptr [esp + 4]
// 007dc2df  8bc8                 mov ecx, eax
// 007dc2e1  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dc2e5  c744240c03000000     mov dword ptr [esp + 0xc], 3
// 007dc2ed  e8cefeffff           call 0x7dc1c0
// 007dc2f2  83c414               add esp, 0x14
// 007dc2f5  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_numberK)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

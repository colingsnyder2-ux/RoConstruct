// from server: 100% by auto
// roc 2009-12 007dcce0  unit: RBX::GroupDragTool  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcce0
//
// 007dcce0  8b442408             mov eax, dword ptr [esp + 8]
// 007dcce4  8b4810               mov ecx, dword ptr [eax + 0x10]
// 007dcce7  89442408             mov dword ptr [esp + 8], eax
// 007dcceb  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 007dccee  7405                 je 0x7dccf5
// 007dccf0  e99bffffff           jmp 0x7dcc90
// 007dccf5  e986fbffff           jmp 0x7dc880
// library lua-5.1/lcode.c (function _luaK_exp2val)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

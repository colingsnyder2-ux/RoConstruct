// from server: 100% by auto
// roc 2009-12 007dd220  unit: RBX::GroupDragTool  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd220
//
// 007dd220  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dd224  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dd228  50                   push eax
// 007dd229  51                   push ecx
// 007dd22a  e8d1faffff           call 0x7dcd00
// 007dd22f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007dd233  83c408               add esp, 8
// 007dd236  89410c               mov dword ptr [ecx + 0xc], eax
// 007dd239  c70109000000         mov dword ptr [ecx], 9
// 007dd23f  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_indexed)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

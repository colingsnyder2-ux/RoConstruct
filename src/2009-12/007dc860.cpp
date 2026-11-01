// from server: 100% by auto
// roc 2009-12 007dc860  unit: RBX::GroupDragTool  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc860
//
// 007dc860  8b442404             mov eax, dword ptr [esp + 4]
// 007dc864  8b4818               mov ecx, dword ptr [eax + 0x18]
// 007dc867  8b542408             mov edx, dword ptr [esp + 8]
// 007dc86b  89481c               mov dword ptr [eax + 0x1c], ecx
// 007dc86e  52                   push edx
// 007dc86f  8d4820               lea ecx, [eax + 0x20]
// 007dc872  51                   push ecx
// 007dc873  50                   push eax
// 007dc874  e857f8ffff           call 0x7dc0d0
// 007dc879  83c40c               add esp, 0xc
// 007dc87c  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_patchtohere)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

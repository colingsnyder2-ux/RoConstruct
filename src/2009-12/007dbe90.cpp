// from server: 100% by auto
// roc 2009-12 007dbe90  unit: RBX::GroupDragTool  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dbe90
//
// 007dbe90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dbe94  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007dbe97  89411c               mov dword ptr [ecx + 0x1c], eax
// 007dbe9a  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_getlabel)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

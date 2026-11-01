// from server: 100% by auto
// roc 2009-12 007dc540  unit: RBX::GroupDragTool  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc540
//
// 007dc540  8b442404             mov eax, dword ptr [esp + 4]
// 007dc544  8b10                 mov edx, dword ptr [eax]
// 007dc546  8b4818               mov ecx, dword ptr [eax + 0x18]
// 007dc549  8b4214               mov eax, dword ptr [edx + 0x14]
// 007dc54c  8b542408             mov edx, dword ptr [esp + 8]
// 007dc550  895488fc             mov dword ptr [eax + ecx*4 - 4], edx
// 007dc554  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_fixline)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c

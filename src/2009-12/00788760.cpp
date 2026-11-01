// from server: 100% by auto
// roc 2009-12 00788760  unit: RBX::UniversalTool  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788760
//
// 00788760  8b442404             mov eax, dword ptr [esp + 4]
// 00788764  668b4834             mov cx, word ptr [eax + 0x34]
// 00788768  8b542408             mov edx, dword ptr [esp + 8]
// 0078876c  66894a34             mov word ptr [edx + 0x34], cx
// 00788770  c3                   ret 
// library lua-5.1.3/lapi.c (function _lua_setlevel)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lapi.c

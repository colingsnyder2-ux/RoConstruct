// from server: 100% by auto
// roc 2009-12 0078ab20  unit: RBX::UniversalTool  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078ab20
//
// 0078ab20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078ab24  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0078ab28  8b542404             mov edx, dword ptr [esp + 4]
// 0078ab2c  6a00                 push 0
// 0078ab2e  50                   push eax
// 0078ab2f  51                   push ecx
// 0078ab30  52                   push edx
// 0078ab31  e81afeffff           call 0x78a950
// 0078ab36  83c410               add esp, 0x10
// 0078ab39  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_register)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c

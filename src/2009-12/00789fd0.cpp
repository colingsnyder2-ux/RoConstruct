// from server: 100% by auto
// roc 2009-12 00789fd0  unit: RBX::UniversalTool  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789fd0
//
// 00789fd0  56                   push esi
// 00789fd1  8b742408             mov esi, dword ptr [esp + 8]
// 00789fd5  8b06                 mov eax, dword ptr [esi]
// 00789fd7  2bc6                 sub eax, esi
// 00789fd9  83e80c               sub eax, 0xc
// 00789fdc  741e                 je 0x789ffc
// 00789fde  57                   push edi
// 00789fdf  50                   push eax
// 00789fe0  8b4608               mov eax, dword ptr [esi + 8]
// 00789fe3  8d7e0c               lea edi, [esi + 0xc]
// 00789fe6  57                   push edi
// 00789fe7  50                   push eax
// 00789fe8  e8b3edffff           call 0x788da0
// 00789fed  ff4604               inc dword ptr [esi + 4]
// 00789ff0  56                   push esi
// 00789ff1  893e                 mov dword ptr [esi], edi
// 00789ff3  e868ffffff           call 0x789f60
// 00789ff8  83c410               add esp, 0x10
// 00789ffb  5f                   pop edi
// 00789ffc  8d460c               lea eax, [esi + 0xc]
// 00789fff  5e                   pop esi
// 0078a000  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_prepbuffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c

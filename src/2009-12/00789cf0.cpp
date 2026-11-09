// from server: 100% by auto
// roc 2009-12 00789cf0  unit: RBX::UniversalTool  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789cf0
//
// 00789cf0  56                   push esi
// 00789cf1  8b742408             mov esi, dword ptr [esp + 8]
// 00789cf5  6a01                 push 1
// 00789cf7  56                   push esi
// 00789cf8  e883ffffff           call 0x789c80
// 00789cfd  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00789d01  8d442418             lea eax, [esp + 0x18]
// 00789d05  50                   push eax
// 00789d06  51                   push ecx
// 00789d07  56                   push esi
// 00789d08  e843f1ffff           call 0x788e50
// 00789d0d  6a02                 push 2
// 00789d0f  56                   push esi
// 00789d10  e85bfaffff           call 0x789770
// 00789d15  56                   push esi
// 00789d16  e805faffff           call 0x789720
// 00789d1b  83c420               add esp, 0x20
// 00789d1e  5e                   pop esi
// 00789d1f  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c

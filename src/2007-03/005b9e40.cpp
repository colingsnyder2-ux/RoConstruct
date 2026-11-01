// from server: 100% by auto
// roc 2007-03 005b9e40  unit: seg_005b0000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9e40
//
// 005b9e40  56                   push esi
// 005b9e41  8b742408             mov esi, dword ptr [esp + 8]
// 005b9e45  8b06                 mov eax, dword ptr [esi]
// 005b9e47  2bc6                 sub eax, esi
// 005b9e49  83e80c               sub eax, 0xc
// 005b9e4c  741f                 je 0x5b9e6d
// 005b9e4e  57                   push edi
// 005b9e4f  50                   push eax
// 005b9e50  8b4608               mov eax, dword ptr [esi + 8]
// 005b9e53  8d7e0c               lea edi, [esi + 0xc]
// 005b9e56  57                   push edi
// 005b9e57  50                   push eax
// 005b9e58  e823f2ffff           call 0x5b9080
// 005b9e5d  83460401             add dword ptr [esi + 4], 1
// 005b9e61  56                   push esi
// 005b9e62  893e                 mov dword ptr [esi], edi
// 005b9e64  e857ffffff           call 0x5b9dc0
// 005b9e69  83c410               add esp, 0x10
// 005b9e6c  5f                   pop edi
// 005b9e6d  8d460c               lea eax, [esi + 0xc]
// 005b9e70  5e                   pop esi
// 005b9e71  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_prepbuffer)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c

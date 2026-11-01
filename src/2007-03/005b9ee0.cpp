// from server: 100% by auto
// roc 2007-03 005b9ee0  unit: seg_005b0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9ee0
//
// 005b9ee0  56                   push esi
// 005b9ee1  8b742408             mov esi, dword ptr [esp + 8]
// 005b9ee5  8b06                 mov eax, dword ptr [esi]
// 005b9ee7  2bc6                 sub eax, esi
// 005b9ee9  83e80c               sub eax, 0xc
// 005b9eec  7419                 je 0x5b9f07
// 005b9eee  57                   push edi
// 005b9eef  50                   push eax
// 005b9ef0  8b4608               mov eax, dword ptr [esi + 8]
// 005b9ef3  8d7e0c               lea edi, [esi + 0xc]
// 005b9ef6  57                   push edi
// 005b9ef7  50                   push eax
// 005b9ef8  e883f1ffff           call 0x5b9080
// 005b9efd  83c40c               add esp, 0xc
// 005b9f00  83460401             add dword ptr [esi + 4], 1
// 005b9f04  893e                 mov dword ptr [esi], edi
// 005b9f06  5f                   pop edi
// 005b9f07  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b9f0a  8b5608               mov edx, dword ptr [esi + 8]
// 005b9f0d  51                   push ecx
// 005b9f0e  52                   push edx
// 005b9f0f  e8ecfaffff           call 0x5b9a00
// 005b9f14  83c408               add esp, 8
// 005b9f17  c7460401000000       mov dword ptr [esi + 4], 1
// 005b9f1e  5e                   pop esi
// 005b9f1f  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_pushresult)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c

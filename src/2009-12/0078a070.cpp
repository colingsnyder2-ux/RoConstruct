// from server: 100% by auto
// roc 2009-12 0078a070  unit: RBX::UniversalTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a070
//
// 0078a070  56                   push esi
// 0078a071  8b742408             mov esi, dword ptr [esp + 8]
// 0078a075  8b06                 mov eax, dword ptr [esi]
// 0078a077  2bc6                 sub eax, esi
// 0078a079  83e80c               sub eax, 0xc
// 0078a07c  7418                 je 0x78a096
// 0078a07e  57                   push edi
// 0078a07f  50                   push eax
// 0078a080  8b4608               mov eax, dword ptr [esi + 8]
// 0078a083  8d7e0c               lea edi, [esi + 0xc]
// 0078a086  57                   push edi
// 0078a087  50                   push eax
// 0078a088  e813edffff           call 0x788da0
// 0078a08d  83c40c               add esp, 0xc
// 0078a090  ff4604               inc dword ptr [esi + 4]
// 0078a093  893e                 mov dword ptr [esi], edi
// 0078a095  5f                   pop edi
// 0078a096  8b4e04               mov ecx, dword ptr [esi + 4]
// 0078a099  8b5608               mov edx, dword ptr [esi + 8]
// 0078a09c  51                   push ecx
// 0078a09d  52                   push edx
// 0078a09e  e8cdf6ffff           call 0x789770
// 0078a0a3  83c408               add esp, 8
// 0078a0a6  c7460401000000       mov dword ptr [esi + 4], 1
// 0078a0ad  5e                   pop esi
// 0078a0ae  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_pushresult)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c

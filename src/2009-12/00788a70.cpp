// from server: 100% by auto
// roc 2009-12 00788a70  unit: RBX::UniversalTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788a70
//
// 00788a70  8b442408             mov eax, dword ptr [esp + 8]
// 00788a74  56                   push esi
// 00788a75  57                   push edi
// 00788a76  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00788a7a  8bcf                 mov ecx, edi
// 00788a7c  e86ffbffff           call 0x7885f0
// 00788a81  8bf0                 mov esi, eax
// 00788a83  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788a87  8bcf                 mov ecx, edi
// 00788a89  e862fbffff           call 0x7885f0
// 00788a8e  81fe28aa9e00         cmp esi, 0x9eaa28
// 00788a94  7414                 je 0x788aaa
// 00788a96  3d28aa9e00           cmp eax, 0x9eaa28
// 00788a9b  740d                 je 0x788aaa
// 00788a9d  50                   push eax
// 00788a9e  56                   push esi
// 00788a9f  e88c160100           call 0x79a130
// 00788aa4  83c408               add esp, 8
// 00788aa7  5f                   pop edi
// 00788aa8  5e                   pop esi
// 00788aa9  c3                   ret 
// 00788aaa  5f                   pop edi
// 00788aab  33c0                 xor eax, eax
// 00788aad  5e                   pop esi
// 00788aae  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

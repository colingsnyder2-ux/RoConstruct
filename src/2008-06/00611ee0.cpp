// from server: 100% by auto
// roc 2008-06 00611ee0  unit: seg_00610000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611ee0
//
// 00611ee0  8b442408             mov eax, dword ptr [esp + 8]
// 00611ee4  56                   push esi
// 00611ee5  57                   push edi
// 00611ee6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00611eea  8bcf                 mov ecx, edi
// 00611eec  e89ffbffff           call 0x611a90
// 00611ef1  8bf0                 mov esi, eax
// 00611ef3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00611ef7  8bcf                 mov ecx, edi
// 00611ef9  e892fbffff           call 0x611a90
// 00611efe  81fe80488400         cmp esi, 0x844880
// 00611f04  7414                 je 0x611f1a
// 00611f06  3d80488400           cmp eax, 0x844880
// 00611f0b  740d                 je 0x611f1a
// 00611f0d  50                   push eax
// 00611f0e  56                   push esi
// 00611f0f  e85c070100           call 0x622670
// 00611f14  83c408               add esp, 8
// 00611f17  5f                   pop edi
// 00611f18  5e                   pop esi
// 00611f19  c3                   ret 
// 00611f1a  5f                   pop edi
// 00611f1b  33c0                 xor eax, eax
// 00611f1d  5e                   pop esi
// 00611f1e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

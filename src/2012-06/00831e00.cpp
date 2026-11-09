// from server: 100% by auto
// roc 2012-06 00831e00  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831e00
//
// 00831e00  8b442408             mov eax, dword ptr [esp + 8]
// 00831e04  56                   push esi
// 00831e05  8b742408             mov esi, dword ptr [esp + 8]
// 00831e09  57                   push edi
// 00831e0a  8bce                 mov ecx, esi
// 00831e0c  e82ffbffff           call 0x831940
// 00831e11  8bf8                 mov edi, eax
// 00831e13  8b442414             mov eax, dword ptr [esp + 0x14]
// 00831e17  8bce                 mov ecx, esi
// 00831e19  e822fbffff           call 0x831940
// 00831e1e  81ff202dbd00         cmp edi, 0xbd2d20
// 00831e24  7415                 je 0x831e3b
// 00831e26  3d202dbd00           cmp eax, 0xbd2d20
// 00831e2b  740e                 je 0x831e3b
// 00831e2d  50                   push eax
// 00831e2e  57                   push edi
// 00831e2f  56                   push esi
// 00831e30  e8eb1d1000           call 0x933c20
// 00831e35  83c40c               add esp, 0xc
// 00831e38  5f                   pop edi
// 00831e39  5e                   pop esi
// 00831e3a  c3                   ret 
// 00831e3b  5f                   pop edi
// 00831e3c  33c0                 xor eax, eax
// 00831e3e  5e                   pop esi
// 00831e3f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

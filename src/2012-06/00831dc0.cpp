// from server: 100% by auto
// roc 2012-06 00831dc0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831dc0
//
// 00831dc0  8b442408             mov eax, dword ptr [esp + 8]
// 00831dc4  56                   push esi
// 00831dc5  57                   push edi
// 00831dc6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00831dca  8bcf                 mov ecx, edi
// 00831dcc  e86ffbffff           call 0x831940
// 00831dd1  8bf0                 mov esi, eax
// 00831dd3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00831dd7  8bcf                 mov ecx, edi
// 00831dd9  e862fbffff           call 0x831940
// 00831dde  81fe202dbd00         cmp esi, 0xbd2d20
// 00831de4  7414                 je 0x831dfa
// 00831de6  3d202dbd00           cmp eax, 0xbd2d20
// 00831deb  740d                 je 0x831dfa
// 00831ded  50                   push eax
// 00831dee  56                   push esi
// 00831def  e8fcde0100           call 0x84fcf0
// 00831df4  83c408               add esp, 8
// 00831df7  5f                   pop edi
// 00831df8  5e                   pop esi
// 00831df9  c3                   ret 
// 00831dfa  5f                   pop edi
// 00831dfb  33c0                 xor eax, eax
// 00831dfd  5e                   pop esi
// 00831dfe  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

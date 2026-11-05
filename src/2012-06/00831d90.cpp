// from server: 100% by auto
// roc 2012-06 00831d90  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831d90
//
// 00831d90  8b442408             mov eax, dword ptr [esp + 8]
// 00831d94  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831d98  e8a3fbffff           call 0x831940
// 00831d9d  3d202dbd00           cmp eax, 0xbd2d20
// 00831da2  740d                 je 0x831db1
// 00831da4  8b4008               mov eax, dword ptr [eax + 8]
// 00831da7  83f804               cmp eax, 4
// 00831daa  7408                 je 0x831db4
// 00831dac  83f803               cmp eax, 3
// 00831daf  7403                 je 0x831db4
// 00831db1  33c0                 xor eax, eax
// 00831db3  c3                   ret 
// 00831db4  b801000000           mov eax, 1
// 00831db9  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

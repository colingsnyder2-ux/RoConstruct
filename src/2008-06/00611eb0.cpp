// from server: 100% by auto
// roc 2008-06 00611eb0  unit: seg_00610000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611eb0
//
// 00611eb0  8b442408             mov eax, dword ptr [esp + 8]
// 00611eb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611eb8  e8d3fbffff           call 0x611a90
// 00611ebd  3d80488400           cmp eax, 0x844880
// 00611ec2  740d                 je 0x611ed1
// 00611ec4  8b4008               mov eax, dword ptr [eax + 8]
// 00611ec7  83f804               cmp eax, 4
// 00611eca  7408                 je 0x611ed4
// 00611ecc  83f803               cmp eax, 3
// 00611ecf  7403                 je 0x611ed4
// 00611ed1  33c0                 xor eax, eax
// 00611ed3  c3                   ret 
// 00611ed4  b801000000           mov eax, 1
// 00611ed9  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

// from server: 100% by auto
// roc 2010-06 007211f0  unit: RBX::UniversalTool  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007211f0
//
// 007211f0  8b442408             mov eax, dword ptr [esp + 8]
// 007211f4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007211f8  e8a3fbffff           call 0x720da0
// 007211fd  3d78dca400           cmp eax, 0xa4dc78
// 00721202  740d                 je 0x721211
// 00721204  8b4008               mov eax, dword ptr [eax + 8]
// 00721207  83f804               cmp eax, 4
// 0072120a  7408                 je 0x721214
// 0072120c  83f803               cmp eax, 3
// 0072120f  7403                 je 0x721214
// 00721211  33c0                 xor eax, eax
// 00721213  c3                   ret 
// 00721214  b801000000           mov eax, 1
// 00721219  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c

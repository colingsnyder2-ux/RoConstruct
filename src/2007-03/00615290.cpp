// from server: 100% by auto
// roc 2007-03 00615290  unit: seg_00610000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615290
//
// 00615290  8b442408             mov eax, dword ptr [esp + 8]
// 00615294  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00615297  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0061529a  89442408             mov dword ptr [esp + 8], eax
// 0061529e  7405                 je 0x6152a5
// 006152a0  e99bffffff           jmp 0x615240
// 006152a5  e986fbffff           jmp 0x614e30
// library lua-5.1.1/lcode.c (function _luaK_exp2val)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c

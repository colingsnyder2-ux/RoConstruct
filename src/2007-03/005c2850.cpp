// from server: 100% by auto
// roc 2007-03 005c2850  unit: seg_005c0000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2850
//
// 005c2850  8b442404             mov eax, dword ptr [esp + 4]
// 005c2854  8bc8                 mov ecx, eax
// 005c2856  83e13f               and ecx, 0x3f
// 005c2859  83f91c               cmp ecx, 0x1c
// 005c285c  7c17                 jl 0x5c2875
// 005c285e  83f91e               cmp ecx, 0x1e
// 005c2861  7e05                 jle 0x5c2868
// 005c2863  83f922               cmp ecx, 0x22
// 005c2866  750d                 jne 0x5c2875
// 005c2868  25000080ff           and eax, 0xff800000
// 005c286d  f7d8                 neg eax
// 005c286f  1bc0                 sbb eax, eax
// 005c2871  83c001               add eax, 1
// 005c2874  c3                   ret 
// 005c2875  33c0                 xor eax, eax
// 005c2877  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_checkopenop)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c

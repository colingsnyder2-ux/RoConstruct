// from server: 100% by auto
// roc 2007-03 005fc310  unit: seg_005f0000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc310
//
// 005fc310  8b442408             mov eax, dword ptr [esp + 8]
// 005fc314  81781070037c00       cmp dword ptr [eax + 0x10], 0x7c0370
// 005fc31b  7516                 jne 0x5fc333
// 005fc31d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fc321  33d2                 xor edx, edx
// 005fc323  52                   push edx
// 005fc324  8b542408             mov edx, dword ptr [esp + 8]
// 005fc328  51                   push ecx
// 005fc329  52                   push edx
// 005fc32a  e801feffff           call 0x5fc130
// 005fc32f  83c40c               add esp, 0xc
// 005fc332  c3                   ret 
// 005fc333  8a4807               mov cl, byte ptr [eax + 7]
// 005fc336  ba01000000           mov edx, 1
// 005fc33b  d3e2                 shl edx, cl
// 005fc33d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fc341  52                   push edx
// 005fc342  8b542408             mov edx, dword ptr [esp + 8]
// 005fc346  51                   push ecx
// 005fc347  52                   push edx
// 005fc348  e8e3fdffff           call 0x5fc130
// 005fc34d  83c40c               add esp, 0xc
// 005fc350  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_resizearray)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c

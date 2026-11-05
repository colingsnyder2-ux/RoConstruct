// from server: 100% by auto
// roc 2007-08 00612960  unit: seg_00610000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612960
//
// 00612960  8b442408             mov eax, dword ptr [esp + 8]
// 00612964  817810b8327c00       cmp dword ptr [eax + 0x10], 0x7c32b8
// 0061296b  7516                 jne 0x612983
// 0061296d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00612971  33d2                 xor edx, edx
// 00612973  52                   push edx
// 00612974  8b542408             mov edx, dword ptr [esp + 8]
// 00612978  51                   push ecx
// 00612979  52                   push edx
// 0061297a  e801feffff           call 0x612780
// 0061297f  83c40c               add esp, 0xc
// 00612982  c3                   ret 
// 00612983  8a4807               mov cl, byte ptr [eax + 7]
// 00612986  ba01000000           mov edx, 1
// 0061298b  d3e2                 shl edx, cl
// 0061298d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00612991  52                   push edx
// 00612992  8b542408             mov edx, dword ptr [esp + 8]
// 00612996  51                   push ecx
// 00612997  52                   push edx
// 00612998  e8e3fdffff           call 0x612780
// 0061299d  83c40c               add esp, 0xc
// 006129a0  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_resizearray)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c

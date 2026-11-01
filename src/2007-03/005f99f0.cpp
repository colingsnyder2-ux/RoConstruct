// from server: 100% by auto
// roc 2007-03 005f99f0  unit: seg_005f0000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f99f0
//
// 005f99f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005f99f4  56                   push esi
// 005f99f5  8b742408             mov esi, dword ptr [esp + 8]
// 005f99f9  50                   push eax
// 005f99fa  56                   push esi
// 005f99fb  e880240000           call 0x5fbe80
// 005f9a00  83c408               add esp, 8
// 005f9a03  83780800             cmp dword ptr [eax + 8], 0
// 005f9a07  750d                 jne 0x5f9a16
// 005f9a09  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005f9a0d  b201                 mov dl, 1
// 005f9a0f  d2e2                 shl dl, cl
// 005f9a11  085606               or byte ptr [esi + 6], dl
// 005f9a14  33c0                 xor eax, eax
// 005f9a16  5e                   pop esi
// 005f9a17  c3                   ret 
// library lua-5.1.1/ltm.c (function _luaT_gettm)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltm.c

// from server: 100% by auto
// roc 2009-12 007cde50  unit: RBX::PartDropTool  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cde50
//
// 007cde50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007cde54  56                   push esi
// 007cde55  8b742408             mov esi, dword ptr [esp + 8]
// 007cde59  50                   push eax
// 007cde5a  56                   push esi
// 007cde5b  e890240000           call 0x7d02f0
// 007cde60  83c408               add esp, 8
// 007cde63  83780800             cmp dword ptr [eax + 8], 0
// 007cde67  750d                 jne 0x7cde76
// 007cde69  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007cde6d  b201                 mov dl, 1
// 007cde6f  d2e2                 shl dl, cl
// 007cde71  085606               or byte ptr [esi + 6], dl
// 007cde74  33c0                 xor eax, eax
// 007cde76  5e                   pop esi
// 007cde77  c3                   ret 
// library lua-5.1/ltm.c (function _luaT_gettm)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltm.c

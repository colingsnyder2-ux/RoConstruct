// from server: 100% by auto
// roc 2009-12 004049a0  unit: ATL::CRegObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004049a0
//
// 004049a0  8b442404             mov eax, dword ptr [esp + 4]
// 004049a4  833800               cmp dword ptr [eax], 0
// 004049a7  7520                 jne 0x4049c9
// 004049a9  83780400             cmp dword ptr [eax + 4], 0
// 004049ad  751a                 jne 0x4049c9
// 004049af  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004049b6  7511                 jne 0x4049c9
// 004049b8  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 004049bf  7508                 jne 0x4049c9
// 004049c1  b801000000           mov eax, 1
// 004049c6  c20400               ret 4
// 004049c9  33c0                 xor eax, eax
// 004049cb  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp

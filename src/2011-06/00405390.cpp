// from server: 100% by auto
// roc 2011-06 00405390  unit: ATL::CRegObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00405390
//
// 00405390  8b442404             mov eax, dword ptr [esp + 4]
// 00405394  833800               cmp dword ptr [eax], 0
// 00405397  7520                 jne 0x4053b9
// 00405399  83780400             cmp dword ptr [eax + 4], 0
// 0040539d  751a                 jne 0x4053b9
// 0040539f  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004053a6  7511                 jne 0x4053b9
// 004053a8  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 004053af  7508                 jne 0x4053b9
// 004053b1  b801000000           mov eax, 1
// 004053b6  c20400               ret 4
// 004053b9  33c0                 xor eax, eax
// 004053bb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp

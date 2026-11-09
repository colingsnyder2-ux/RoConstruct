// from server: 100% by auto
// roc 2009-06 00404b00  unit: ATL::CRegObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404b00
//
// 00404b00  8b442404             mov eax, dword ptr [esp + 4]
// 00404b04  833800               cmp dword ptr [eax], 0
// 00404b07  7520                 jne 0x404b29
// 00404b09  83780400             cmp dword ptr [eax + 4], 0
// 00404b0d  751a                 jne 0x404b29
// 00404b0f  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00404b16  7511                 jne 0x404b29
// 00404b18  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00404b1f  7508                 jne 0x404b29
// 00404b21  b801000000           mov eax, 1
// 00404b26  c20400               ret 4
// 00404b29  33c0                 xor eax, eax
// 00404b2b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp

// from server: 100% by auto
// roc 2007-08 00401c00  unit: VCWorkspace::?$CComObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401c00
//
// 00401c00  8b442404             mov eax, dword ptr [esp + 4]
// 00401c04  833800               cmp dword ptr [eax], 0
// 00401c07  7520                 jne 0x401c29
// 00401c09  83780400             cmp dword ptr [eax + 4], 0
// 00401c0d  751a                 jne 0x401c29
// 00401c0f  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00401c16  7511                 jne 0x401c29
// 00401c18  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00401c1f  7508                 jne 0x401c29
// 00401c21  b801000000           mov eax, 1
// 00401c26  c20400               ret 4
// 00401c29  33c0                 xor eax, eax
// 00401c2b  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp

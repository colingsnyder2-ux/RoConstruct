// from server: 100% by auto
// roc 2007-03 00401bf0  unit: seg_00400000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401bf0
//
// 00401bf0  8b442404             mov eax, dword ptr [esp + 4]
// 00401bf4  833800               cmp dword ptr [eax], 0
// 00401bf7  7520                 jne 0x401c19
// 00401bf9  83780400             cmp dword ptr [eax + 4], 0
// 00401bfd  751a                 jne 0x401c19
// 00401bff  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00401c06  7511                 jne 0x401c19
// 00401c08  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00401c0f  7508                 jne 0x401c19
// 00401c11  b801000000           mov eax, 1
// 00401c16  c20400               ret 4
// 00401c19  33c0                 xor eax, eax
// 00401c1b  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp

// from server: 100% by auto
// roc 2012-06 00405b30  unit: VCApp::?$CComObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405b30
//
// 00405b30  8b442404             mov eax, dword ptr [esp + 4]
// 00405b34  833800               cmp dword ptr [eax], 0
// 00405b37  7520                 jne 0x405b59
// 00405b39  83780400             cmp dword ptr [eax + 4], 0
// 00405b3d  751a                 jne 0x405b59
// 00405b3f  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00405b46  7511                 jne 0x405b59
// 00405b48  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00405b4f  7508                 jne 0x405b59
// 00405b51  b801000000           mov eax, 1
// 00405b56  c20400               ret 4
// 00405b59  33c0                 xor eax, eax
// 00405b5b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp

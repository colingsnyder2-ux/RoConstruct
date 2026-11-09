// from server: 100% by auto
// roc 2008-06 00401b60  unit: VCWorkspace::?$CComObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401b60
//
// 00401b60  8b442404             mov eax, dword ptr [esp + 4]
// 00401b64  833800               cmp dword ptr [eax], 0
// 00401b67  7520                 jne 0x401b89
// 00401b69  83780400             cmp dword ptr [eax + 4], 0
// 00401b6d  751a                 jne 0x401b89
// 00401b6f  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00401b76  7511                 jne 0x401b89
// 00401b78  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00401b7f  7508                 jne 0x401b89
// 00401b81  b801000000           mov eax, 1
// 00401b86  c20400               ret 4
// 00401b89  33c0                 xor eax, eax
// 00401b8b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp

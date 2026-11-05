// from server: 100% by auto
// roc 2010-06 004045c0  unit: VCApp::?$CComObject  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004045c0
//
// 004045c0  8b442404             mov eax, dword ptr [esp + 4]
// 004045c4  833800               cmp dword ptr [eax], 0
// 004045c7  7520                 jne 0x4045e9
// 004045c9  83780400             cmp dword ptr [eax + 4], 0
// 004045cd  751a                 jne 0x4045e9
// 004045cf  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004045d6  7511                 jne 0x4045e9
// 004045d8  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 004045df  7508                 jne 0x4045e9
// 004045e1  b801000000           mov eax, 1
// 004045e6  c20400               ret 4
// 004045e9  33c0                 xor eax, eax
// 004045eb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp

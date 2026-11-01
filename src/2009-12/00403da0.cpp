// from server: 100% by auto
// roc 2009-12 00403da0  unit: VCApp::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403da0
//
// 00403da0  56                   push esi
// 00403da1  8bf1                 mov esi, ecx
// 00403da3  8b06                 mov eax, dword ptr [esi]
// 00403da5  85c0                 test eax, eax
// 00403da7  740d                 je 0x403db6
// 00403da9  50                   push eax
// 00403daa  ff1508b09800         call dword ptr [0x98b008]
// 00403db0  c70600000000         mov dword ptr [esi], 0
// 00403db6  c7460400000000       mov dword ptr [esi + 4], 0
// 00403dbd  5e                   pop esi
// 00403dbe  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp

// from server: 100% by auto
// roc 2010-06 00403e00  unit: VCApp::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403e00
//
// 00403e00  56                   push esi
// 00403e01  8bf1                 mov esi, ecx
// 00403e03  8b06                 mov eax, dword ptr [esi]
// 00403e05  85c0                 test eax, eax
// 00403e07  740d                 je 0x403e16
// 00403e09  50                   push eax
// 00403e0a  ff1510a09e00         call dword ptr [0x9ea010]
// 00403e10  c70600000000         mov dword ptr [esi], 0
// 00403e16  c7460400000000       mov dword ptr [esi + 4], 0
// 00403e1d  5e                   pop esi
// 00403e1e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp

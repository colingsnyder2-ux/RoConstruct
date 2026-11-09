// from server: 100% by auto
// roc 2009-06 004040e0  unit: VCApp::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004040e0
//
// 004040e0  56                   push esi
// 004040e1  8bf1                 mov esi, ecx
// 004040e3  8b06                 mov eax, dword ptr [esi]
// 004040e5  85c0                 test eax, eax
// 004040e7  740d                 je 0x4040f6
// 004040e9  50                   push eax
// 004040ea  ff1508e08900         call dword ptr [0x89e008]
// 004040f0  c70600000000         mov dword ptr [esi], 0
// 004040f6  c7460400000000       mov dword ptr [esi + 4], 0
// 004040fd  5e                   pop esi
// 004040fe  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp

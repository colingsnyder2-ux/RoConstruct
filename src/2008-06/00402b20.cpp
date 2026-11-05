// from server: 100% by auto
// roc 2008-06 00402b20  unit: VCWorkspace::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402b20
//
// 00402b20  56                   push esi
// 00402b21  8bf1                 mov esi, ecx
// 00402b23  8b06                 mov eax, dword ptr [esi]
// 00402b25  85c0                 test eax, eax
// 00402b27  740d                 je 0x402b36
// 00402b29  50                   push eax
// 00402b2a  ff1508208000         call dword ptr [0x802008]
// 00402b30  c70600000000         mov dword ptr [esi], 0
// 00402b36  c7460400000000       mov dword ptr [esi + 4], 0
// 00402b3d  5e                   pop esi
// 00402b3e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp

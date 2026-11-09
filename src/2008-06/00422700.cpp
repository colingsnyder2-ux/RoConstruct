// from server: 100% by auto
// roc 2008-06 00422700  unit: CEnabledCmdUI  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00422700
//
// 00422700  8b442404             mov eax, dword ptr [esp + 4]
// 00422704  894128               mov dword ptr [ecx + 0x28], eax
// 00422707  c7411801000000       mov dword ptr [ecx + 0x18], 1
// 0042270e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?Enable@CMFCColorBarCmdUI@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp

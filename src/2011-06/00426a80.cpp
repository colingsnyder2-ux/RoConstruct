// from server: 100% by auto
// roc 2011-06 00426a80  unit: CEnabledCmdUI  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00426a80
//
// 00426a80  8b442404             mov eax, dword ptr [esp + 4]
// 00426a84  894128               mov dword ptr [ecx + 0x28], eax
// 00426a87  c7411801000000       mov dword ptr [ecx + 0x18], 1
// 00426a8e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?Enable@CMFCColorBarCmdUI@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp

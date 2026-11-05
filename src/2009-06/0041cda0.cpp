// from server: 100% by auto
// roc 2009-06 0041cda0  unit: CEnabledCmdUI  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cda0
//
// 0041cda0  8b442404             mov eax, dword ptr [esp + 4]
// 0041cda4  894128               mov dword ptr [ecx + 0x28], eax
// 0041cda7  c7411801000000       mov dword ptr [ecx + 0x18], 1
// 0041cdae  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?Enable@CMFCColorBarCmdUI@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp

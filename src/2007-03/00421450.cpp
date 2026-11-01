// from server: 100% by auto
// roc 2007-03 00421450  unit: seg_00420000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00421450
//
// 00421450  8b442404             mov eax, dword ptr [esp + 4]
// 00421454  894128               mov dword ptr [ecx + 0x28], eax
// 00421457  c7411801000000       mov dword ptr [ecx + 0x18], 1
// 0042145e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?Enable@CMFCColorBarCmdUI@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp

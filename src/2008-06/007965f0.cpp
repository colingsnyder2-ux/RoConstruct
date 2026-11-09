// from server: 100% by auto
// roc 2008-06 007965f0  unit: CXTPRibbonTabPopupToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007965f0
//
// 007965f0  8b442404             mov eax, dword ptr [esp + 4]
// 007965f4  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007965f7  8910                 mov dword ptr [eax], edx
// 007965f9  8b5124               mov edx, dword ptr [ecx + 0x24]
// 007965fc  895004               mov dword ptr [eax + 4], edx
// 007965ff  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00796602  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 00796605  895008               mov dword ptr [eax + 8], edx
// 00796608  89480c               mov dword ptr [eax + 0xc], ecx
// 0079660b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?GetRect@CMFCRibbonCategory@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp

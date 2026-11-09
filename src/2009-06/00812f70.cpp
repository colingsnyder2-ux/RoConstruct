// from server: 100% by auto
// roc 2009-06 00812f70  unit: CXTPRibbonTabPopupToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00812f70
//
// 00812f70  8b442404             mov eax, dword ptr [esp + 4]
// 00812f74  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00812f77  8910                 mov dword ptr [eax], edx
// 00812f79  8b5124               mov edx, dword ptr [ecx + 0x24]
// 00812f7c  895004               mov dword ptr [eax + 4], edx
// 00812f7f  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00812f82  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 00812f85  895008               mov dword ptr [eax + 8], edx
// 00812f88  89480c               mov dword ptr [eax + 0xc], ecx
// 00812f8b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?GetRect@CMFCRibbonCategory@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp

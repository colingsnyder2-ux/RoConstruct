// from server: 100% by auto
// roc 2011-06 008fb840  unit: CXTPRibbonTabPopupToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fb840
//
// 008fb840  8b442404             mov eax, dword ptr [esp + 4]
// 008fb844  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008fb847  8910                 mov dword ptr [eax], edx
// 008fb849  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008fb84c  895004               mov dword ptr [eax + 4], edx
// 008fb84f  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008fb852  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 008fb855  895008               mov dword ptr [eax + 8], edx
// 008fb858  89480c               mov dword ptr [eax + 0xc], ecx
// 008fb85b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?GetRect@CMFCRibbonCategory@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp

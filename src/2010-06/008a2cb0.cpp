// from server: 100% by auto
// roc 2010-06 008a2cb0  unit: CXTPRibbonTabPopupToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a2cb0
//
// 008a2cb0  8b442404             mov eax, dword ptr [esp + 4]
// 008a2cb4  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008a2cb7  8910                 mov dword ptr [eax], edx
// 008a2cb9  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008a2cbc  895004               mov dword ptr [eax + 4], edx
// 008a2cbf  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008a2cc2  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 008a2cc5  895008               mov dword ptr [eax + 8], edx
// 008a2cc8  89480c               mov dword ptr [eax + 0xc], ecx
// 008a2ccb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?GetRect@CMFCRibbonCategory@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp

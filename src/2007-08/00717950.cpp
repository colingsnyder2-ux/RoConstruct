// from server: 100% by auto
// roc 2007-08 00717950  unit: CXTPRibbonTabPopupToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00717950
//
// 00717950  8b442404             mov eax, dword ptr [esp + 4]
// 00717954  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00717957  8910                 mov dword ptr [eax], edx
// 00717959  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0071795c  895004               mov dword ptr [eax + 4], edx
// 0071795f  8b5124               mov edx, dword ptr [ecx + 0x24]
// 00717962  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00717965  895008               mov dword ptr [eax + 8], edx
// 00717968  89480c               mov dword ptr [eax + 0xc], ecx
// 0071796b  c20400               ret 4
// library xtp-15.2.1/Source\Controls\CoreTree\XTPCoreTreeItem.cpp (function ?GetRect@CXTPCoreTreeItem@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/CoreTree/XTPCoreTreeItem.cpp

// from server: 100% by auto
// roc 2009-12 008d09d0  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2003  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d09d0
//
// 008d09d0  8b5118               mov edx, dword ptr [ecx + 0x18]
// 008d09d3  035104               add edx, dword ptr [ecx + 4]
// 008d09d6  8b442404             mov eax, dword ptr [esp + 4]
// 008d09da  8910                 mov dword ptr [eax], edx
// 008d09dc  8b5108               mov edx, dword ptr [ecx + 8]
// 008d09df  895004               mov dword ptr [eax + 4], edx
// 008d09e2  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008d09e5  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008d09e8  895008               mov dword ptr [eax + 8], edx
// 008d09eb  89480c               mov dword ptr [eax + 0xc], ecx
// 008d09ee  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

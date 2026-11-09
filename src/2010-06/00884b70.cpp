// from server: 100% by auto
// roc 2010-06 00884b70  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2003  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884b70
//
// 00884b70  8b5118               mov edx, dword ptr [ecx + 0x18]
// 00884b73  035104               add edx, dword ptr [ecx + 4]
// 00884b76  8b442404             mov eax, dword ptr [esp + 4]
// 00884b7a  8910                 mov dword ptr [eax], edx
// 00884b7c  8b5108               mov edx, dword ptr [ecx + 8]
// 00884b7f  895004               mov dword ptr [eax + 4], edx
// 00884b82  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00884b85  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00884b88  895008               mov dword ptr [eax + 8], edx
// 00884b8b  89480c               mov dword ptr [eax + 0xc], ecx
// 00884b8e  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp

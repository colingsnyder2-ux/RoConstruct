// from server: 100% by auto
// roc 2009-06 007f5e10  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2003  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5e10
//
// 007f5e10  8b5118               mov edx, dword ptr [ecx + 0x18]
// 007f5e13  035104               add edx, dword ptr [ecx + 4]
// 007f5e16  8b442404             mov eax, dword ptr [esp + 4]
// 007f5e1a  8910                 mov dword ptr [eax], edx
// 007f5e1c  8b5108               mov edx, dword ptr [ecx + 8]
// 007f5e1f  895004               mov dword ptr [eax + 4], edx
// 007f5e22  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007f5e25  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 007f5e28  895008               mov dword ptr [eax + 8], edx
// 007f5e2b  89480c               mov dword ptr [eax + 0xc], ecx
// 007f5e2e  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

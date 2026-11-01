// from server: 100% by auto
// roc 2009-06 007f5f00  unit: CXTPTabPaintManager::CAppearanceSetVisualStudio2005  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5f00
//
// 007f5f00  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007f5f03  99                   cdq 
// 007f5f04  2bc2                 sub eax, edx
// 007f5f06  8bd0                 mov edx, eax
// 007f5f08  8b442404             mov eax, dword ptr [esp + 4]
// 007f5f0c  d1fa                 sar edx, 1
// 007f5f0e  035104               add edx, dword ptr [ecx + 4]
// 007f5f11  8910                 mov dword ptr [eax], edx
// 007f5f13  8b5108               mov edx, dword ptr [ecx + 8]
// 007f5f16  895004               mov dword ptr [eax + 4], edx
// 007f5f19  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007f5f1c  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 007f5f1f  895008               mov dword ptr [eax + 8], edx
// 007f5f22  89480c               mov dword ptr [eax + 0xc], ecx
// 007f5f25  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

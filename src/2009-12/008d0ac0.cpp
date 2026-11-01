// from server: 100% by auto
// roc 2009-12 008d0ac0  unit: CXTPTabPaintManager::CAppearanceSetVisualStudio2005  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0ac0
//
// 008d0ac0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 008d0ac3  99                   cdq 
// 008d0ac4  2bc2                 sub eax, edx
// 008d0ac6  8bd0                 mov edx, eax
// 008d0ac8  8b442404             mov eax, dword ptr [esp + 4]
// 008d0acc  d1fa                 sar edx, 1
// 008d0ace  035104               add edx, dword ptr [ecx + 4]
// 008d0ad1  8910                 mov dword ptr [eax], edx
// 008d0ad3  8b5108               mov edx, dword ptr [ecx + 8]
// 008d0ad6  895004               mov dword ptr [eax + 4], edx
// 008d0ad9  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008d0adc  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008d0adf  895008               mov dword ptr [eax + 8], edx
// 008d0ae2  89480c               mov dword ptr [eax + 0xc], ecx
// 008d0ae5  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

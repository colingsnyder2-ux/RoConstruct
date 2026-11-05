// from server: 100% by auto
// roc 2010-06 00884c70  unit: CXTPTabPaintManager::CAppearanceSetVisualStudio2005  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884c70
//
// 00884c70  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00884c73  99                   cdq 
// 00884c74  2bc2                 sub eax, edx
// 00884c76  8bd0                 mov edx, eax
// 00884c78  8b442404             mov eax, dword ptr [esp + 4]
// 00884c7c  d1fa                 sar edx, 1
// 00884c7e  035104               add edx, dword ptr [ecx + 4]
// 00884c81  8910                 mov dword ptr [eax], edx
// 00884c83  8b5108               mov edx, dword ptr [ecx + 8]
// 00884c86  895004               mov dword ptr [eax + 4], edx
// 00884c89  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00884c8c  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00884c8f  895008               mov dword ptr [eax + 8], edx
// 00884c92  89480c               mov dword ptr [eax + 0xc], ecx
// 00884c95  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp

// from server: 100% by auto
// roc 2009-06 007f5f70  unit: CXTPTabPaintManager::CAppearanceSetExcel  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5f70
//
// 007f5f70  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007f5f73  99                   cdq 
// 007f5f74  56                   push esi
// 007f5f75  8b7104               mov esi, dword ptr [ecx + 4]
// 007f5f78  2bc2                 sub eax, edx
// 007f5f7a  8bd0                 mov edx, eax
// 007f5f7c  8b442408             mov eax, dword ptr [esp + 8]
// 007f5f80  d1fa                 sar edx, 1
// 007f5f82  03f2                 add esi, edx
// 007f5f84  8930                 mov dword ptr [eax], esi
// 007f5f86  8b7108               mov esi, dword ptr [ecx + 8]
// 007f5f89  897004               mov dword ptr [eax + 4], esi
// 007f5f8c  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007f5f8f  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 007f5f92  03f2                 add esi, edx
// 007f5f94  897008               mov dword ptr [eax + 8], esi
// 007f5f97  89480c               mov dword ptr [eax + 0xc], ecx
// 007f5f9a  5e                   pop esi
// 007f5f9b  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetExcel@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

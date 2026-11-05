// from server: 100% by auto
// roc 2010-06 00884ce0  unit: CXTPTabPaintManager::CAppearanceSetExcel  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884ce0
//
// 00884ce0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00884ce3  99                   cdq 
// 00884ce4  56                   push esi
// 00884ce5  8b7104               mov esi, dword ptr [ecx + 4]
// 00884ce8  2bc2                 sub eax, edx
// 00884cea  8bd0                 mov edx, eax
// 00884cec  8b442408             mov eax, dword ptr [esp + 8]
// 00884cf0  d1fa                 sar edx, 1
// 00884cf2  03f2                 add esi, edx
// 00884cf4  8930                 mov dword ptr [eax], esi
// 00884cf6  8b7108               mov esi, dword ptr [ecx + 8]
// 00884cf9  897004               mov dword ptr [eax + 4], esi
// 00884cfc  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00884cff  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00884d02  03f2                 add esi, edx
// 00884d04  897008               mov dword ptr [eax + 8], esi
// 00884d07  89480c               mov dword ptr [eax + 0xc], ecx
// 00884d0a  5e                   pop esi
// 00884d0b  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetExcel@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp

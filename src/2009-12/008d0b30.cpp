// from server: 100% by auto
// roc 2009-12 008d0b30  unit: CXTPTabPaintManager::CAppearanceSetExcel  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0b30
//
// 008d0b30  8b4118               mov eax, dword ptr [ecx + 0x18]
// 008d0b33  99                   cdq 
// 008d0b34  56                   push esi
// 008d0b35  8b7104               mov esi, dword ptr [ecx + 4]
// 008d0b38  2bc2                 sub eax, edx
// 008d0b3a  8bd0                 mov edx, eax
// 008d0b3c  8b442408             mov eax, dword ptr [esp + 8]
// 008d0b40  d1fa                 sar edx, 1
// 008d0b42  03f2                 add esi, edx
// 008d0b44  8930                 mov dword ptr [eax], esi
// 008d0b46  8b7108               mov esi, dword ptr [ecx + 8]
// 008d0b49  897004               mov dword ptr [eax + 4], esi
// 008d0b4c  8b710c               mov esi, dword ptr [ecx + 0xc]
// 008d0b4f  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008d0b52  03f2                 add esi, edx
// 008d0b54  897008               mov dword ptr [eax + 8], esi
// 008d0b57  89480c               mov dword ptr [eax + 0xc], ecx
// 008d0b5a  5e                   pop esi
// 008d0b5b  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetExcel@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

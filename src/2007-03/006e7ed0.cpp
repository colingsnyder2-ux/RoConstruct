// from server: 100% by auto
// roc 2007-03 006e7ed0  unit: seg_006e0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7ed0
//
// 006e7ed0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006e7ed3  99                   cdq 
// 006e7ed4  56                   push esi
// 006e7ed5  8b7104               mov esi, dword ptr [ecx + 4]
// 006e7ed8  2bc2                 sub eax, edx
// 006e7eda  8bd0                 mov edx, eax
// 006e7edc  8b442408             mov eax, dword ptr [esp + 8]
// 006e7ee0  d1fa                 sar edx, 1
// 006e7ee2  03f2                 add esi, edx
// 006e7ee4  8930                 mov dword ptr [eax], esi
// 006e7ee6  8b7108               mov esi, dword ptr [ecx + 8]
// 006e7ee9  897004               mov dword ptr [eax + 4], esi
// 006e7eec  8b710c               mov esi, dword ptr [ecx + 0xc]
// 006e7eef  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 006e7ef2  03f2                 add esi, edx
// 006e7ef4  897008               mov dword ptr [eax + 8], esi
// 006e7ef7  89480c               mov dword ptr [eax + 0xc], ecx
// 006e7efa  5e                   pop esi
// 006e7efb  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetExcel@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp

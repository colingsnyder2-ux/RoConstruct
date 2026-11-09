// from server: 100% by auto
// roc 2010-06 008885c0  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008885c0
//
// 008885c0  83ec10               sub esp, 0x10
// 008885c3  8d0c24               lea ecx, [esp]
// 008885c6  e8a56cf7ff           call 0x7ff270
// 008885cb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008885cf  8b10                 mov edx, dword ptr [eax]
// 008885d1  8911                 mov dword ptr [ecx], edx
// 008885d3  8b5004               mov edx, dword ptr [eax + 4]
// 008885d6  895104               mov dword ptr [ecx + 4], edx
// 008885d9  8b5008               mov edx, dword ptr [eax + 8]
// 008885dc  8b400c               mov eax, dword ptr [eax + 0xc]
// 008885df  895108               mov dword ptr [ecx + 8], edx
// 008885e2  89410c               mov dword ptr [ecx + 0xc], eax
// 008885e5  8bc1                 mov eax, ecx
// 008885e7  83c410               add esp, 0x10
// 008885ea  c21800               ret 0x18
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetHeaderRect@CAppearanceSetVisio@CXTPTabPaintManager@@UAE?AVCRect@@V3@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp

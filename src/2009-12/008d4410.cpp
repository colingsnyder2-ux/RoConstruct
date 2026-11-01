// from server: 100% by auto
// roc 2009-12 008d4410  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d4410
//
// 008d4410  83ec10               sub esp, 0x10
// 008d4413  8d0c24               lea ecx, [esp]
// 008d4416  e8156ef7ff           call 0x84b230
// 008d441b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d441f  8b10                 mov edx, dword ptr [eax]
// 008d4421  8911                 mov dword ptr [ecx], edx
// 008d4423  8b5004               mov edx, dword ptr [eax + 4]
// 008d4426  895104               mov dword ptr [ecx + 4], edx
// 008d4429  8b5008               mov edx, dword ptr [eax + 8]
// 008d442c  8b400c               mov eax, dword ptr [eax + 0xc]
// 008d442f  895108               mov dword ptr [ecx + 8], edx
// 008d4432  89410c               mov dword ptr [ecx + 0xc], eax
// 008d4435  8bc1                 mov eax, ecx
// 008d4437  83c410               add esp, 0x10
// 008d443a  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetHeaderRect@CAppearanceSetVisio@CXTPTabPaintManager@@UAE?AVCRect@@V3@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp

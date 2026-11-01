// from server: 100% by auto
// roc 2009-06 007f9870  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f9870
//
// 007f9870  83ec10               sub esp, 0x10
// 007f9873  8d0c24               lea ecx, [esp]
// 007f9876  e8b56bf7ff           call 0x770430
// 007f987b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007f987f  8b10                 mov edx, dword ptr [eax]
// 007f9881  8911                 mov dword ptr [ecx], edx
// 007f9883  8b5004               mov edx, dword ptr [eax + 4]
// 007f9886  895104               mov dword ptr [ecx + 4], edx
// 007f9889  8b5008               mov edx, dword ptr [eax + 8]
// 007f988c  8b400c               mov eax, dword ptr [eax + 0xc]
// 007f988f  895108               mov dword ptr [ecx + 8], edx
// 007f9892  89410c               mov dword ptr [ecx + 0xc], eax
// 007f9895  8bc1                 mov eax, ecx
// 007f9897  83c410               add esp, 0x10
// 007f989a  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetHeaderRect@CAppearanceSetVisio@CXTPTabPaintManager@@UAE?AVCRect@@V3@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp

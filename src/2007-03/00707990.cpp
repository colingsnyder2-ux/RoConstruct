// from server: 100% by auto
// roc 2007-03 00707990  unit: seg_00700000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707990
//
// 00707990  83ec10               sub esp, 0x10
// 00707993  8d0c24               lea ecx, [esp]
// 00707996  e8f53df6ff           call 0x66b790
// 0070799b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0070799f  8b10                 mov edx, dword ptr [eax]
// 007079a1  8911                 mov dword ptr [ecx], edx
// 007079a3  8b5004               mov edx, dword ptr [eax + 4]
// 007079a6  895104               mov dword ptr [ecx + 4], edx
// 007079a9  8b5008               mov edx, dword ptr [eax + 8]
// 007079ac  8b400c               mov eax, dword ptr [eax + 0xc]
// 007079af  895108               mov dword ptr [ecx + 8], edx
// 007079b2  89410c               mov dword ptr [ecx + 0xc], eax
// 007079b5  8bc1                 mov eax, ecx
// 007079b7  83c410               add esp, 0x10
// 007079ba  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetHeaderRect@CAppearanceSetVisio@CXTPTabPaintManager@@UAE?AVCRect@@V3@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp

// from server: 100% by auto
// roc 2010-06 00888230  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888230
//
// 00888230  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00888233  8b442404             mov eax, dword ptr [esp + 4]
// 00888237  8b5140               mov edx, dword ptr [ecx + 0x40]
// 0088823a  83c140               add ecx, 0x40
// 0088823d  8910                 mov dword ptr [eax], edx
// 0088823f  8b5104               mov edx, dword ptr [ecx + 4]
// 00888242  895004               mov dword ptr [eax + 4], edx
// 00888245  8b5108               mov edx, dword ptr [ecx + 8]
// 00888248  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0088824b  895008               mov dword ptr [eax + 8], edx
// 0088824e  89480c               mov dword ptr [eax + 0xc], ecx
// 00888251  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetClientMargin@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp

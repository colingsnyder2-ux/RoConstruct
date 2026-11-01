// from server: 100% by auto
// roc 2009-06 00795240  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00795240
//
// 00795240  8b442404             mov eax, dword ptr [esp + 4]
// 00795244  8b5104               mov edx, dword ptr [ecx + 4]
// 00795247  8910                 mov dword ptr [eax], edx
// 00795249  8b5108               mov edx, dword ptr [ecx + 8]
// 0079524c  895004               mov dword ptr [eax + 4], edx
// 0079524f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00795252  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00795255  895008               mov dword ptr [eax + 8], edx
// 00795258  89480c               mov dword ptr [eax + 0xc], ecx
// 0079525b  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?GetStandardValue@?$CXTPCalendarThemeCustomizableXValueT@VCRect@@V1@@@UBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarThemeOffice2007.cpp

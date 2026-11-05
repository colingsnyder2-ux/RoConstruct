// from server: 100% by auto
// roc 2010-06 0082cb10  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082cb10
//
// 0082cb10  8b442404             mov eax, dword ptr [esp + 4]
// 0082cb14  8b5104               mov edx, dword ptr [ecx + 4]
// 0082cb17  8910                 mov dword ptr [eax], edx
// 0082cb19  8b5108               mov edx, dword ptr [ecx + 8]
// 0082cb1c  895004               mov dword ptr [eax + 4], edx
// 0082cb1f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0082cb22  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0082cb25  895008               mov dword ptr [eax + 8], edx
// 0082cb28  89480c               mov dword ptr [eax + 0xc], ecx
// 0082cb2b  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?GetStandardValue@?$CXTPCalendarThemeCustomizableXValueT@VCRect@@V1@@@UBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarThemeOffice2007.cpp

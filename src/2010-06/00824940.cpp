// from server: 100% by auto
// roc 2010-06 00824940  unit: CXTPControlGallery  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824940
//
// 00824940  8b817cffffff         mov eax, dword ptr [ecx - 0x84]
// 00824946  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?GetEventIconsToDrawPart@CTODayViewEvent@CXTPCalendarThemeOffice2007@@UAEPAVCTOEventIconsToDraw@CXTPCalendarTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarThemeOffice2007.cpp

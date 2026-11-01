// from server: 100% by auto
// roc 2009-06 0079c7c0  unit: CXTPControlGallery  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079c7c0
//
// 0079c7c0  8b817cffffff         mov eax, dword ptr [ecx - 0x84]
// 0079c7c6  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?GetHeightFormulaPart@CTODayViewTimeScale@CXTPCalendarThemeOffice2007@@UBEPAVCTOFormula_MulDivC@CXTPCalendarTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarThemeOffice2007.cpp

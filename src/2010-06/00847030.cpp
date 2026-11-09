// from server: 100% by auto
// roc 2010-06 00847030  unit: CXTPMenuBarMDIMenuInfo  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847030
//
// 00847030  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 00847033  f7d8                 neg eax
// 00847035  1bc0                 sbb eax, eax
// 00847037  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ?GetStartPosition@CXTPCalendarCustomProperties@@QBEPAU__POSITION@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp

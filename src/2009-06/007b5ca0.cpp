// from server: 100% by auto
// roc 2009-06 007b5ca0  unit: CXTPMenuBarMDIMenuInfo  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b5ca0
//
// 007b5ca0  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 007b5ca3  f7d8                 neg eax
// 007b5ca5  1bc0                 sbb eax, eax
// 007b5ca7  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ?GetStartPosition@CXTPCalendarCustomProperties@@QBEPAU__POSITION@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp

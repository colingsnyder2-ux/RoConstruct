// from server: 100% by auto
// roc 2009-06 0076fc90  unit: CXTPControlSelector  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076fc90
//
// 0076fc90  e88b4efeff           call 0x754b20
// 0076fc95  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076fc99  51                   push ecx
// 0076fc9a  8bc8                 mov ecx, eax
// 0076fc9c  e8bf47feff           call 0x754460
// 0076fca1  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventPropertiesDlg.cpp (function ?GetXtremeColor@@YAKI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventPropertiesDlg.cpp

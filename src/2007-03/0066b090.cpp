// from server: 100% by auto
// roc 2007-03 0066b090  unit: seg_00660000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066b090
//
// 0066b090  e80b9ffeff           call 0x654fa0
// 0066b095  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0066b099  51                   push ecx
// 0066b09a  8bc8                 mov ecx, eax
// 0066b09c  e8cf98feff           call 0x654970
// 0066b0a1  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventPropertiesDlg.cpp (function ?GetXtremeColor@@YAKI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventPropertiesDlg.cpp

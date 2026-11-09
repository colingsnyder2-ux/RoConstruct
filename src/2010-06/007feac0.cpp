// from server: 100% by auto
// roc 2010-06 007feac0  unit: CXTPControlSelector  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007feac0
//
// 007feac0  e85b50feff           call 0x7e3b20
// 007feac5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007feac9  51                   push ecx
// 007feaca  8bc8                 mov ecx, eax
// 007feacc  e89f49feff           call 0x7e3470
// 007fead1  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarEventPropertiesDlg.cpp (function ?GetXtremeColor@@YAKI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarEventPropertiesDlg.cpp

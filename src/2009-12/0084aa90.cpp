// from server: 100% by auto
// roc 2009-12 0084aa90  unit: CXTPControlSelector  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084aa90
//
// 0084aa90  e83b4ffeff           call 0x82f9d0
// 0084aa95  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084aa99  51                   push ecx
// 0084aa9a  8bc8                 mov ecx, eax
// 0084aa9c  e81f48feff           call 0x82f2c0
// 0084aaa1  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventPropertiesDlg.cpp (function ?GetXtremeColor@@YAKI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventPropertiesDlg.cpp

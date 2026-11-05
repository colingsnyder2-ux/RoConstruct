// from server: 100% by auto
// roc 2010-06 00861fa0  unit: CXTPDockingPaneWindowSelect  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00861fa0
//
// 00861fa0  c70114b0a600         mov dword ptr [ecx], 0xa6b014
// 00861fa6  83c108               add ecx, 8
// 00861fa9  e972eaffff           jmp 0x860a20
// library xtp-13.2.1/Source\Calendar\XTPCalendarMAPIDataProvider.cpp (function ??1CXTPMAPIBinary@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarMAPIDataProvider.cpp

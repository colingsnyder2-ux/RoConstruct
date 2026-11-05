// from server: 100% by auto
// roc 2010-06 00428240  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00428240
//
// 00428240  8b09                 mov ecx, dword ptr [ecx]
// 00428242  85c9                 test ecx, ecx
// 00428244  7405                 je 0x42824b
// 00428246  e9d1fc3700           jmp 0x7a7f1c
// 0042824b  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ??1CXTPPropExchangeSection@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp

// from server: 100% by auto
// roc 2007-03 00460ad0  unit: seg_00460000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00460ad0
//
// 00460ad0  8d4104               lea eax, [ecx + 4]
// 00460ad3  3901                 cmp dword ptr [ecx], eax
// 00460ad5  7405                 je 0x460adc
// 00460ad7  e9b41dfaff           jmp 0x402890
// 00460adc  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp

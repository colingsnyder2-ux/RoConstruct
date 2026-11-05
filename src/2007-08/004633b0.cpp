// from server: 100% by auto
// roc 2007-08 004633b0  unit: CSettingsDialog  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004633b0
//
// 004633b0  8d4104               lea eax, [ecx + 4]
// 004633b3  3901                 cmp dword ptr [ecx], eax
// 004633b5  7405                 je 0x4633bc
// 004633b7  e9b4f4f9ff           jmp 0x402870
// 004633bc  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp

// from server: 100% by auto
// roc 2010-06 007bd240  unit: CXTPCommandBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd240
//
// 007bd240  8b4178               mov eax, dword ptr [ecx + 0x78]
// 007bd243  83f801               cmp eax, 1
// 007bd246  7503                 jne 0x7bd24b
// 007bd248  c20400               ret 4
// 007bd24b  83f802               cmp eax, 2
// 007bd24e  7510                 jne 0x7bd260
// 007bd250  8b442404             mov eax, dword ptr [esp + 4]
// 007bd254  50                   push eax
// 007bd255  e8f62e0400           call 0x800150
// 007bd25a  83c404               add esp, 4
// 007bd25d  c20400               ret 4
// 007bd260  33c0                 xor eax, eax
// 007bd262  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?IsDrawReverted@CXTPImageManager@@QBEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

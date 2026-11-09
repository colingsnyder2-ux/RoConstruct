// from server: 100% by auto
// roc 2010-06 00805e50  unit: CXTPPropExchangeArchive  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805e50
//
// 00805e50  8d4104               lea eax, [ecx + 4]
// 00805e53  3901                 cmp dword ptr [ecx], eax
// 00805e55  7405                 je 0x805e5c
// 00805e57  e934dcbfff           jmp 0x403a90
// 00805e5c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp

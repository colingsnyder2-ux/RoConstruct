// from server: 100% by auto
// roc 2011-06 00861330  unit: CXTPPropExchangeArchive  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00861330
//
// 00861330  8d4104               lea eax, [ecx + 4]
// 00861333  3901                 cmp dword ptr [ecx], eax
// 00861335  7405                 je 0x86133c
// 00861337  e9f42fbaff           jmp 0x404330
// 0086133c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp

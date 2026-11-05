// from server: 100% by auto
// roc 2008-06 006fe710  unit: CXTPPropExchangeArchive  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fe710
//
// 006fe710  8d4104               lea eax, [ecx + 4]
// 006fe713  3901                 cmp dword ptr [ecx], eax
// 006fe715  7405                 je 0x6fe71c
// 006fe717  e9e4f1ffff           jmp 0x6fd900
// 006fe71c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp

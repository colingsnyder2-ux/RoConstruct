// from server: 100% by auto
// roc 2009-12 004040f0  unit: ATL::CRegObject  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004040f0
//
// 004040f0  8d4104               lea eax, [ecx + 4]
// 004040f3  3901                 cmp dword ptr [ecx], eax
// 004040f5  7405                 je 0x4040fc
// 004040f7  e9c4ce4400           jmp 0x850fc0
// 004040fc  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp

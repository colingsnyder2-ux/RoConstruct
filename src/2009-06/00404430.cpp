// from server: 100% by auto
// roc 2009-06 00404430  unit: ATL::CRegObject  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404430
//
// 00404430  8d4104               lea eax, [ecx + 4]
// 00404433  3901                 cmp dword ptr [ecx], eax
// 00404435  7405                 je 0x40443c
// 00404437  e9e4f7ffff           jmp 0x403c20
// 0040443c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??1?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp

// from server: 100% by auto
// roc 2009-12 0086f7d0  unit: CXTPDockingPaneAutoHidePanel  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086f7d0
//
// 0086f7d0  83791000             cmp dword ptr [ecx + 0x10], 0
// 0086f7d4  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0086f7d7  741a                 je 0x86f7f3
// 0086f7d9  83790800             cmp dword ptr [ecx + 8], 0
// 0086f7dd  7411                 je 0x86f7f0
// 0086f7df  83790c00             cmp dword ptr [ecx + 0xc], 0
// 0086f7e3  750b                 jne 0x86f7f0
// 0086f7e5  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 0086f7e8  50                   push eax
// 0086f7e9  ff1520ca9800         call dword ptr [0x98ca20]
// 0086f7ef  c3                   ret 
// 0086f7f0  8b4140               mov eax, dword ptr [ecx + 0x40]
// 0086f7f3  50                   push eax
// 0086f7f4  ff1520ca9800         call dword ptr [0x98ca20]
// 0086f7fa  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?FreshenCursor@CXTPCustomizeDropSource@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeTools.cpp

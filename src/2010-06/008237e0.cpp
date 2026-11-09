// from server: 100% by auto
// roc 2010-06 008237e0  unit: CXTPDockingPaneAutoHidePanel  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008237e0
//
// 008237e0  83791000             cmp dword ptr [ecx + 0x10], 0
// 008237e4  8b4138               mov eax, dword ptr [ecx + 0x38]
// 008237e7  741a                 je 0x823803
// 008237e9  83790800             cmp dword ptr [ecx + 8], 0
// 008237ed  7411                 je 0x823800
// 008237ef  83790c00             cmp dword ptr [ecx + 0xc], 0
// 008237f3  750b                 jne 0x823800
// 008237f5  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 008237f8  50                   push eax
// 008237f9  ff15b4bb9e00         call dword ptr [0x9ebbb4]
// 008237ff  c3                   ret 
// 00823800  8b4140               mov eax, dword ptr [ecx + 0x40]
// 00823803  50                   push eax
// 00823804  ff15b4bb9e00         call dword ptr [0x9ebbb4]
// 0082380a  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?FreshenCursor@CXTPCustomizeDropSource@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeTools.cpp

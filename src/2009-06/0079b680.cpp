// from server: 100% by auto
// roc 2009-06 0079b680  unit: CXTPResourceManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b680
//
// 0079b680  83791000             cmp dword ptr [ecx + 0x10], 0
// 0079b684  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0079b687  741a                 je 0x79b6a3
// 0079b689  83790800             cmp dword ptr [ecx + 8], 0
// 0079b68d  7411                 je 0x79b6a0
// 0079b68f  83790c00             cmp dword ptr [ecx + 0xc], 0
// 0079b693  750b                 jne 0x79b6a0
// 0079b695  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 0079b698  50                   push eax
// 0079b699  ff1590ed8900         call dword ptr [0x89ed90]
// 0079b69f  c3                   ret 
// 0079b6a0  8b4140               mov eax, dword ptr [ecx + 0x40]
// 0079b6a3  50                   push eax
// 0079b6a4  ff1590ed8900         call dword ptr [0x89ed90]
// 0079b6aa  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?FreshenCursor@CXTPCustomizeDropSource@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeTools.cpp

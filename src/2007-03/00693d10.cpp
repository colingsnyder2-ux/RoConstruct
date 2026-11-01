// from server: 100% by auto
// roc 2007-03 00693d10  unit: seg_00690000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00693d10
//
// 00693d10  83791000             cmp dword ptr [ecx + 0x10], 0
// 00693d14  8b4138               mov eax, dword ptr [ecx + 0x38]
// 00693d17  741a                 je 0x693d33
// 00693d19  83790800             cmp dword ptr [ecx + 8], 0
// 00693d1d  7411                 je 0x693d30
// 00693d1f  83790c00             cmp dword ptr [ecx + 0xc], 0
// 00693d23  750b                 jne 0x693d30
// 00693d25  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 00693d28  50                   push eax
// 00693d29  ff15d0ed7700         call dword ptr [0x77edd0]
// 00693d2f  c3                   ret 
// 00693d30  8b4140               mov eax, dword ptr [ecx + 0x40]
// 00693d33  50                   push eax
// 00693d34  ff15d0ed7700         call dword ptr [0x77edd0]
// 00693d3a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?FreshenCursor@CXTPCustomizeDropSource@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeTools.cpp

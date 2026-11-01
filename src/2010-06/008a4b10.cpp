// from server: 100% by auto
// roc 2010-06 008a4b10  unit: CXTPRibbonControlTab  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a4b10
//
// 008a4b10  8b817cffffff         mov eax, dword ptr [ecx - 0x84]
// 008a4b16  85c0                 test eax, eax
// 008a4b18  7412                 je 0x8a4b2c
// 008a4b1a  83782000             cmp dword ptr [eax + 0x20], 0
// 008a4b1e  740c                 je 0x8a4b2c
// 008a4b20  8bc8                 mov ecx, eax
// 008a4b22  8b01                 mov eax, dword ptr [ecx]
// 008a4b24  8b9084010000         mov edx, dword ptr [eax + 0x184]
// 008a4b2a  ffe2                 jmp edx
// 008a4b2c  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonControlTab.cpp (function ?Reposition@CXTPRibbonControlTab@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonControlTab.cpp

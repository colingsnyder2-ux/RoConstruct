// from server: 100% by auto
// roc 2011-06 008fd6d0  unit: CXTPRibbonControlTab  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fd6d0
//
// 008fd6d0  8b817cffffff         mov eax, dword ptr [ecx - 0x84]
// 008fd6d6  85c0                 test eax, eax
// 008fd6d8  7412                 je 0x8fd6ec
// 008fd6da  83782000             cmp dword ptr [eax + 0x20], 0
// 008fd6de  740c                 je 0x8fd6ec
// 008fd6e0  8bc8                 mov ecx, eax
// 008fd6e2  8b01                 mov eax, dword ptr [ecx]
// 008fd6e4  8b9084010000         mov edx, dword ptr [eax + 0x184]
// 008fd6ea  ffe2                 jmp edx
// 008fd6ec  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Ribbon\XTPRibbonControlTab.cpp (function ?Reposition@CXTPRibbonControlTab@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Ribbon/XTPRibbonControlTab.cpp

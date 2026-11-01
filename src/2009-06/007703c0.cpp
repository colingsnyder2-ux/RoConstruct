// from server: 100% by auto
// roc 2009-06 007703c0  unit: CXTPPrintingDialog  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007703c0
//
// 007703c0  83ec18               sub esp, 0x18
// 007703c3  8b442420             mov eax, dword ptr [esp + 0x20]
// 007703c7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007703cb  8b542428             mov edx, dword ptr [esp + 0x28]
// 007703cf  890424               mov dword ptr [esp], eax
// 007703d2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007703d6  894c2404             mov dword ptr [esp + 4], ecx
// 007703da  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007703de  89542408             mov dword ptr [esp + 8], edx
// 007703e2  8b542434             mov edx, dword ptr [esp + 0x34]
// 007703e6  8944240c             mov dword ptr [esp + 0xc], eax
// 007703ea  894c2410             mov dword ptr [esp + 0x10], ecx
// 007703ee  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007703f2  6a03                 push 3
// 007703f4  8d442404             lea eax, [esp + 4]
// 007703f8  89542418             mov dword ptr [esp + 0x18], edx
// 007703fc  8b5104               mov edx, dword ptr [ecx + 4]
// 007703ff  50                   push eax
// 00770400  52                   push edx
// 00770401  ff15e4e08900         call dword ptr [0x89e0e4]
// 00770407  83c418               add esp, 0x18
// 0077040a  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonSystemTheme.cpp (function ?Triangle@CXTPDrawHelpers@@SAXPAVCDC@@VCPoint@@11@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonSystemTheme.cpp

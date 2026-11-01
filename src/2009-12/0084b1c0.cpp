// from server: 100% by auto
// roc 2009-12 0084b1c0  unit: CXTPPrintingDialog  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084b1c0
//
// 0084b1c0  83ec18               sub esp, 0x18
// 0084b1c3  8b442420             mov eax, dword ptr [esp + 0x20]
// 0084b1c7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0084b1cb  8b542428             mov edx, dword ptr [esp + 0x28]
// 0084b1cf  890424               mov dword ptr [esp], eax
// 0084b1d2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0084b1d6  894c2404             mov dword ptr [esp + 4], ecx
// 0084b1da  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0084b1de  89542408             mov dword ptr [esp + 8], edx
// 0084b1e2  8b542434             mov edx, dword ptr [esp + 0x34]
// 0084b1e6  8944240c             mov dword ptr [esp + 0xc], eax
// 0084b1ea  894c2410             mov dword ptr [esp + 0x10], ecx
// 0084b1ee  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0084b1f2  6a03                 push 3
// 0084b1f4  8d442404             lea eax, [esp + 4]
// 0084b1f8  89542418             mov dword ptr [esp + 0x18], edx
// 0084b1fc  8b5104               mov edx, dword ptr [ecx + 4]
// 0084b1ff  50                   push eax
// 0084b200  52                   push edx
// 0084b201  ff1520b19800         call dword ptr [0x98b120]
// 0084b207  83c418               add esp, 0x18
// 0084b20a  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonSystemTheme.cpp (function ?Triangle@CXTPDrawHelpers@@SAXPAVCDC@@VCPoint@@11@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonSystemTheme.cpp

// from server: 100% by auto
// roc 2007-03 0066b720  unit: seg_00660000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066b720
//
// 0066b720  83ec18               sub esp, 0x18
// 0066b723  8b442420             mov eax, dword ptr [esp + 0x20]
// 0066b727  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0066b72b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0066b72f  890424               mov dword ptr [esp], eax
// 0066b732  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0066b736  894c2404             mov dword ptr [esp + 4], ecx
// 0066b73a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0066b73e  89542408             mov dword ptr [esp + 8], edx
// 0066b742  8b542434             mov edx, dword ptr [esp + 0x34]
// 0066b746  8944240c             mov dword ptr [esp + 0xc], eax
// 0066b74a  894c2410             mov dword ptr [esp + 0x10], ecx
// 0066b74e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0066b752  6a03                 push 3
// 0066b754  8d442404             lea eax, [esp + 4]
// 0066b758  89542418             mov dword ptr [esp + 0x18], edx
// 0066b75c  8b5104               mov edx, dword ptr [ecx + 4]
// 0066b75f  50                   push eax
// 0066b760  52                   push edx
// 0066b761  ff1518d17700         call dword ptr [0x77d118]
// 0066b767  83c418               add esp, 0x18
// 0066b76a  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonSystemTheme.cpp (function ?Triangle@CXTPDrawHelpers@@SAXPAVCDC@@VCPoint@@11@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonSystemTheme.cpp

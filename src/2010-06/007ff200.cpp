// from server: 100% by auto
// roc 2010-06 007ff200  unit: CXTPPrintingDialog  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ff200
//
// 007ff200  83ec18               sub esp, 0x18
// 007ff203  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ff207  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007ff20b  8b542428             mov edx, dword ptr [esp + 0x28]
// 007ff20f  890424               mov dword ptr [esp], eax
// 007ff212  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007ff216  894c2404             mov dword ptr [esp + 4], ecx
// 007ff21a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007ff21e  89542408             mov dword ptr [esp + 8], edx
// 007ff222  8b542434             mov edx, dword ptr [esp + 0x34]
// 007ff226  8944240c             mov dword ptr [esp + 0xc], eax
// 007ff22a  894c2410             mov dword ptr [esp + 0x10], ecx
// 007ff22e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007ff232  6a03                 push 3
// 007ff234  8d442404             lea eax, [esp + 4]
// 007ff238  89542418             mov dword ptr [esp + 0x18], edx
// 007ff23c  8b5104               mov edx, dword ptr [ecx + 4]
// 007ff23f  50                   push eax
// 007ff240  52                   push edx
// 007ff241  ff1568a19e00         call dword ptr [0x9ea168]
// 007ff247  83c418               add esp, 0x18
// 007ff24a  c3                   ret 
// library xtp-13.2.1/Source\Ribbon\XTPRibbonSystemTheme.cpp (function ?Triangle@CXTPDrawHelpers@@SAXPAVCDC@@VCPoint@@11@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonSystemTheme.cpp

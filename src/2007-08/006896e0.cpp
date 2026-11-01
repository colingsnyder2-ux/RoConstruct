// from server: 100% by auto
// roc 2007-08 006896e0  unit: CXTPTabClientWnd::CWorkspace  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006896e0
//
// 006896e0  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 006896e6  85c0                 test eax, eax
// 006896e8  7407                 je 0x6896f1
// 006896ea  8b808c000000         mov eax, dword ptr [eax + 0x8c]
// 006896f0  c3                   ret 
// 006896f1  33c0                 xor eax, eax
// 006896f3  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetPaintManager@CWorkspace@CXTPTabClientWnd@@MBEPAVCXTPTabPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp

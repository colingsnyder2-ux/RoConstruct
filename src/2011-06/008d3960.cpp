// from server: 100% by auto
// roc 2011-06 008d3960  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d3960
//
// 008d3960  56                   push esi
// 008d3961  8bf1                 mov esi, ecx
// 008d3963  8d4e28               lea ecx, [esi + 0x28]
// 008d3966  c706e878ad00         mov dword ptr [esi], 0xad78e8
// 008d396c  ff15b42da400         call dword ptr [0xa42db4]
// 008d3972  8b442408             mov eax, dword ptr [esp + 8]
// 008d3976  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d397a  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d397e  89460c               mov dword ptr [esi + 0xc], eax
// 008d3981  8d4610               lea eax, [esi + 0x10]
// 008d3984  50                   push eax
// 008d3985  894e04               mov dword ptr [esi + 4], ecx
// 008d3988  895608               mov dword ptr [esi + 8], edx
// 008d398b  ff15ac19a400         call dword ptr [0xa419ac]
// 008d3991  33c0                 xor eax, eax
// 008d3993  894624               mov dword ptr [esi + 0x24], eax
// 008d3996  89462c               mov dword ptr [esi + 0x2c], eax
// 008d3999  c7462001000000       mov dword ptr [esi + 0x20], 1
// 008d39a0  8bc6                 mov eax, esi
// 008d39a2  5e                   pop esi
// 008d39a3  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabManager.cpp (function ??0CXTPTabManagerNavigateButton@@QAE@PAVCXTPTabManager@@IW4XTPTabNavigateButtonFlags@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabManager.cpp

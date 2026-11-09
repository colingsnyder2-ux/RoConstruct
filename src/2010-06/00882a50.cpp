// from server: 100% by auto
// roc 2010-06 00882a50  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882a50
//
// 00882a50  56                   push esi
// 00882a51  8bf1                 mov esi, ecx
// 00882a53  8d4e28               lea ecx, [esi + 0x28]
// 00882a56  c70694e9a600         mov dword ptr [esi], 0xa6e994
// 00882a5c  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 00882a62  8b442408             mov eax, dword ptr [esp + 8]
// 00882a66  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00882a6a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00882a6e  89460c               mov dword ptr [esi + 0xc], eax
// 00882a71  8d4610               lea eax, [esi + 0x10]
// 00882a74  50                   push eax
// 00882a75  894e04               mov dword ptr [esi + 4], ecx
// 00882a78  895608               mov dword ptr [esi + 8], edx
// 00882a7b  ff15e4ba9e00         call dword ptr [0x9ebae4]
// 00882a81  33c0                 xor eax, eax
// 00882a83  894624               mov dword ptr [esi + 0x24], eax
// 00882a86  89462c               mov dword ptr [esi + 0x2c], eax
// 00882a89  c7462001000000       mov dword ptr [esi + 0x20], 1
// 00882a90  8bc6                 mov eax, esi
// 00882a92  5e                   pop esi
// 00882a93  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabManager.cpp (function ??0CXTPTabManagerNavigateButton@@QAE@PAVCXTPTabManager@@IW4XTPTabNavigateButtonFlags@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabManager.cpp

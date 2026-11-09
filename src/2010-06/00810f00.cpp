// from server: 100% by auto
// roc 2010-06 00810f00  unit: CXTPDockingPane  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810f00
//
// 00810f00  8b442404             mov eax, dword ptr [esp + 4]
// 00810f04  8b542408             mov edx, dword ptr [esp + 8]
// 00810f08  89413c               mov dword ptr [ecx + 0x3c], eax
// 00810f0b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00810f0f  895140               mov dword ptr [ecx + 0x40], edx
// 00810f12  8b542410             mov edx, dword ptr [esp + 0x10]
// 00810f16  894144               mov dword ptr [ecx + 0x44], eax
// 00810f19  895148               mov dword ptr [ecx + 0x48], edx
// 00810f1c  8b4144               mov eax, dword ptr [ecx + 0x44]
// 00810f1f  2b413c               sub eax, dword ptr [ecx + 0x3c]
// 00810f22  2b5140               sub edx, dword ptr [ecx + 0x40]
// 00810f25  894124               mov dword ptr [ecx + 0x24], eax
// 00810f28  895128               mov dword ptr [ecx + 0x28], edx
// 00810f2b  c21000               ret 0x10
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?SetWindowRect@CXTPDockingPane@@IAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp

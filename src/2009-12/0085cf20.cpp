// from server: 100% by auto
// roc 2009-12 0085cf20  unit: CXTPDockingPane  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085cf20
//
// 0085cf20  8b442404             mov eax, dword ptr [esp + 4]
// 0085cf24  8b542408             mov edx, dword ptr [esp + 8]
// 0085cf28  89413c               mov dword ptr [ecx + 0x3c], eax
// 0085cf2b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0085cf2f  895140               mov dword ptr [ecx + 0x40], edx
// 0085cf32  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085cf36  894144               mov dword ptr [ecx + 0x44], eax
// 0085cf39  895148               mov dword ptr [ecx + 0x48], edx
// 0085cf3c  8b4144               mov eax, dword ptr [ecx + 0x44]
// 0085cf3f  2b413c               sub eax, dword ptr [ecx + 0x3c]
// 0085cf42  2b5140               sub edx, dword ptr [ecx + 0x40]
// 0085cf45  894124               mov dword ptr [ecx + 0x24], eax
// 0085cf48  895128               mov dword ptr [ecx + 0x28], edx
// 0085cf4b  c21000               ret 0x10
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?SetWindowRect@CXTPDockingPane@@IAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp

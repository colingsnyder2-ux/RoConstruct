// from server: 100% by auto
// roc 2007-03 006794b0  unit: seg_00670000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006794b0
//
// 006794b0  8b442404             mov eax, dword ptr [esp + 4]
// 006794b4  8b542408             mov edx, dword ptr [esp + 8]
// 006794b8  89413c               mov dword ptr [ecx + 0x3c], eax
// 006794bb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006794bf  895140               mov dword ptr [ecx + 0x40], edx
// 006794c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 006794c6  894144               mov dword ptr [ecx + 0x44], eax
// 006794c9  895148               mov dword ptr [ecx + 0x48], edx
// 006794cc  8b4144               mov eax, dword ptr [ecx + 0x44]
// 006794cf  2b413c               sub eax, dword ptr [ecx + 0x3c]
// 006794d2  2b5140               sub edx, dword ptr [ecx + 0x40]
// 006794d5  894124               mov dword ptr [ecx + 0x24], eax
// 006794d8  895128               mov dword ptr [ecx + 0x28], edx
// 006794db  c21000               ret 0x10
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?SetWindowRect@CXTPDockingPane@@IAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp

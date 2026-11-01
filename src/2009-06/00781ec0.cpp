// from server: 100% by auto
// roc 2009-06 00781ec0  unit: CXTPDockingPane  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00781ec0
//
// 00781ec0  8b442404             mov eax, dword ptr [esp + 4]
// 00781ec4  8b542408             mov edx, dword ptr [esp + 8]
// 00781ec8  89413c               mov dword ptr [ecx + 0x3c], eax
// 00781ecb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00781ecf  895140               mov dword ptr [ecx + 0x40], edx
// 00781ed2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00781ed6  894144               mov dword ptr [ecx + 0x44], eax
// 00781ed9  895148               mov dword ptr [ecx + 0x48], edx
// 00781edc  8b4144               mov eax, dword ptr [ecx + 0x44]
// 00781edf  2b413c               sub eax, dword ptr [ecx + 0x3c]
// 00781ee2  2b5140               sub edx, dword ptr [ecx + 0x40]
// 00781ee5  894124               mov dword ptr [ecx + 0x24], eax
// 00781ee8  895128               mov dword ptr [ecx + 0x28], edx
// 00781eeb  c21000               ret 0x10
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?SetWindowRect@CXTPDockingPane@@IAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp

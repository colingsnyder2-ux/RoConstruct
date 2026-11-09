// from server: 100% by auto
// roc 2010-06 008701b0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008701b0
//
// 008701b0  83ec10               sub esp, 0x10
// 008701b3  56                   push esi
// 008701b4  8b742418             mov esi, dword ptr [esp + 0x18]
// 008701b8  8d442404             lea eax, [esp + 4]
// 008701bc  56                   push esi
// 008701bd  50                   push eax
// 008701be  e80d07f8ff           call 0x7f08d0
// 008701c3  8bc8                 mov ecx, eax
// 008701c5  e81602f8ff           call 0x7f03e0
// 008701ca  8b442404             mov eax, dword ptr [esp + 4]
// 008701ce  3906                 cmp dword ptr [esi], eax
// 008701d0  7d02                 jge 0x8701d4
// 008701d2  8906                 mov dword ptr [esi], eax
// 008701d4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008701d8  3906                 cmp dword ptr [esi], eax
// 008701da  7e02                 jle 0x8701de
// 008701dc  8906                 mov dword ptr [esi], eax
// 008701de  8b442408             mov eax, dword ptr [esp + 8]
// 008701e2  394604               cmp dword ptr [esi + 4], eax
// 008701e5  7d03                 jge 0x8701ea
// 008701e7  894604               mov dword ptr [esi + 4], eax
// 008701ea  8b442410             mov eax, dword ptr [esp + 0x10]
// 008701ee  394604               cmp dword ptr [esi + 4], eax
// 008701f1  7e03                 jle 0x8701f6
// 008701f3  894604               mov dword ptr [esi + 4], eax
// 008701f6  5e                   pop esi
// 008701f7  83c410               add esp, 0x10
// 008701fa  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?AdjustCursor@CXTPDockingPaneContext@@KAXAAVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneContext.cpp

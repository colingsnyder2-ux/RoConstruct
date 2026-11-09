// from server: 100% by auto
// roc 2010-06 007ed340  unit: CXTPDockingPaneManager  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ed340
//
// 007ed340  56                   push esi
// 007ed341  8b742408             mov esi, dword ptr [esp + 8]
// 007ed345  85f6                 test esi, esi
// 007ed347  7450                 je 0x7ed399
// 007ed349  837e1800             cmp dword ptr [esi + 0x18], 0
// 007ed34d  750e                 jne 0x7ed35d
// 007ed34f  8d46e0               lea eax, [esi - 0x20]
// 007ed352  6a00                 push 0
// 007ed354  50                   push eax
// 007ed355  e846feffff           call 0x7ed1a0
// 007ed35a  8b7610               mov esi, dword ptr [esi + 0x10]
// 007ed35d  837e1801             cmp dword ptr [esi + 0x18], 1
// 007ed361  750a                 jne 0x7ed36d
// 007ed363  8d4eac               lea ecx, [esi - 0x54]
// 007ed366  6a00                 push 0
// 007ed368  e8137d0700           call 0x865080
// 007ed36d  8b06                 mov eax, dword ptr [esi]
// 007ed36f  8b5018               mov edx, dword ptr [eax + 0x18]
// 007ed372  8bce                 mov ecx, esi
// 007ed374  ffd2                 call edx
// 007ed376  8bf0                 mov esi, eax
// 007ed378  56                   push esi
// 007ed379  e812520700           call 0x862590
// 007ed37e  50                   push eax
// 007ed37f  e8faa9fbff           call 0x7a7d7e
// 007ed384  83c408               add esp, 8
// 007ed387  85c0                 test eax, eax
// 007ed389  740e                 je 0x7ed399
// 007ed38b  8b4620               mov eax, dword ptr [esi + 0x20]
// 007ed38e  5e                   pop esi
// 007ed38f  89442404             mov dword ptr [esp + 4], eax
// 007ed393  ff25fcb99e00         jmp dword ptr [0x9eb9fc]
// 007ed399  5e                   pop esi
// 007ed39a  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneManager.cpp (function ?EnsureVisible@CXTPDockingPaneManager@@QAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneManager.cpp

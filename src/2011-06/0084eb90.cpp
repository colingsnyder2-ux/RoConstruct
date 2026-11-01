// from server: 100% by auto
// roc 2011-06 0084eb90  unit: CXTPDockingPaneManager  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0084eb90
//
// 0084eb90  56                   push esi
// 0084eb91  8b742408             mov esi, dword ptr [esp + 8]
// 0084eb95  85f6                 test esi, esi
// 0084eb97  7450                 je 0x84ebe9
// 0084eb99  837e1800             cmp dword ptr [esi + 0x18], 0
// 0084eb9d  750e                 jne 0x84ebad
// 0084eb9f  8d46e0               lea eax, [esi - 0x20]
// 0084eba2  6a00                 push 0
// 0084eba4  50                   push eax
// 0084eba5  e846feffff           call 0x84e9f0
// 0084ebaa  8b7610               mov esi, dword ptr [esi + 0x10]
// 0084ebad  837e1801             cmp dword ptr [esi + 0x18], 1
// 0084ebb1  750a                 jne 0x84ebbd
// 0084ebb3  8d4eac               lea ecx, [esi - 0x54]
// 0084ebb6  6a00                 push 0
// 0084ebb8  e813390700           call 0x8c24d0
// 0084ebbd  8b06                 mov eax, dword ptr [esi]
// 0084ebbf  8b5018               mov edx, dword ptr [eax + 0x18]
// 0084ebc2  8bce                 mov ecx, esi
// 0084ebc4  ffd2                 call edx
// 0084ebc6  8bf0                 mov esi, eax
// 0084ebc8  56                   push esi
// 0084ebc9  e8120e0700           call 0x8bf9e0
// 0084ebce  50                   push eax
// 0084ebcf  e868b8fbff           call 0x80a43c
// 0084ebd4  83c408               add esp, 8
// 0084ebd7  85c0                 test eax, eax
// 0084ebd9  740e                 je 0x84ebe9
// 0084ebdb  8b4620               mov eax, dword ptr [esi + 0x20]
// 0084ebde  5e                   pop esi
// 0084ebdf  89442404             mov dword ptr [esp + 4], eax
// 0084ebe3  ff25941aa400         jmp dword ptr [0xa41a94]
// 0084ebe9  5e                   pop esi
// 0084ebea  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneManager.cpp (function ?EnsureVisible@CXTPDockingPaneManager@@QAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneManager.cpp

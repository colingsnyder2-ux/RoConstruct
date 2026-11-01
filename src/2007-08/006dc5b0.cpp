// from server: 100% by auto
// roc 2007-08 006dc5b0  unit: CXTPDockingPaneWindowSelect  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006dc5b0
//
// 006dc5b0  56                   push esi
// 006dc5b1  8bf1                 mov esi, ecx
// 006dc5b3  e8863cf5ff           call 0x63023e
// 006dc5b8  f6463c10             test byte ptr [esi + 0x3c], 0x10
// 006dc5bc  740e                 je 0x6dc5cc
// 006dc5be  8b06                 mov eax, dword ptr [esi]
// 006dc5c0  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 006dc5c6  6a02                 push 2
// 006dc5c8  8bce                 mov ecx, esi
// 006dc5ca  ffd2                 call edx
// 006dc5cc  5e                   pop esi
// 006dc5cd  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKillFocus@CXTPDockingPaneWindowSelect@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

// from server: 100% by auto
// roc 2007-08 006dc5d0  unit: CXTPDockingPaneWindowSelect  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006dc5d0
//
// 006dc5d0  56                   push esi
// 006dc5d1  8bf1                 mov esi, ecx
// 006dc5d3  f6463c10             test byte ptr [esi + 0x3c], 0x10
// 006dc5d7  740c                 je 0x6dc5e5
// 006dc5d9  8b06                 mov eax, dword ptr [esi]
// 006dc5db  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 006dc5e1  6a02                 push 2
// 006dc5e3  ffd2                 call edx
// 006dc5e5  8bce                 mov ecx, esi
// 006dc5e7  e8523cf5ff           call 0x63023e
// 006dc5ec  5e                   pop esi
// 006dc5ed  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnCaptureChanged@CXTPDockingPaneWindowSelect@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

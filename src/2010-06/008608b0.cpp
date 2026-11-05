// from server: 100% by auto
// roc 2010-06 008608b0  unit: CXTPDockingPaneWindowSelect  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008608b0
//
// 008608b0  56                   push esi
// 008608b1  8bf1                 mov esi, ecx
// 008608b3  e8b876f4ff           call 0x7a7f70
// 008608b8  f6463c10             test byte ptr [esi + 0x3c], 0x10
// 008608bc  740e                 je 0x8608cc
// 008608be  8b06                 mov eax, dword ptr [esi]
// 008608c0  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 008608c6  6a02                 push 2
// 008608c8  8bce                 mov ecx, esi
// 008608ca  ffd2                 call edx
// 008608cc  5e                   pop esi
// 008608cd  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKillFocus@CXTPDockingPaneWindowSelect@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

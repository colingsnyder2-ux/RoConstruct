// from server: 100% by auto
// roc 2010-06 008608d0  unit: CXTPDockingPaneWindowSelect  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008608d0
//
// 008608d0  56                   push esi
// 008608d1  8bf1                 mov esi, ecx
// 008608d3  f6463c10             test byte ptr [esi + 0x3c], 0x10
// 008608d7  740c                 je 0x8608e5
// 008608d9  8b06                 mov eax, dword ptr [esi]
// 008608db  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 008608e1  6a02                 push 2
// 008608e3  ffd2                 call edx
// 008608e5  8bce                 mov ecx, esi
// 008608e7  e88476f4ff           call 0x7a7f70
// 008608ec  5e                   pop esi
// 008608ed  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnCaptureChanged@CXTPDockingPaneWindowSelect@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

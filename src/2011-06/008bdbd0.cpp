// from server: 100% by auto
// roc 2011-06 008bdbd0  unit: CXTPDockingPaneWindowSelect  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bdbd0
//
// 008bdbd0  56                   push esi
// 008bdbd1  8bf1                 mov esi, ecx
// 008bdbd3  f6463c10             test byte ptr [esi + 0x3c], 0x10
// 008bdbd7  740c                 je 0x8bdbe5
// 008bdbd9  8b06                 mov eax, dword ptr [esi]
// 008bdbdb  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 008bdbe1  6a02                 push 2
// 008bdbe3  ffd2                 call edx
// 008bdbe5  8bce                 mov ecx, esi
// 008bdbe7  e842caf4ff           call 0x80a62e
// 008bdbec  5e                   pop esi
// 008bdbed  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnCaptureChanged@CXTPDockingPaneWindowSelect@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

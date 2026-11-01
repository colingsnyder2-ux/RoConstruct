// from server: 100% by auto
// roc 2011-06 008bdbb0  unit: CXTPDockingPaneWindowSelect  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bdbb0
//
// 008bdbb0  56                   push esi
// 008bdbb1  8bf1                 mov esi, ecx
// 008bdbb3  e876caf4ff           call 0x80a62e
// 008bdbb8  f6463c10             test byte ptr [esi + 0x3c], 0x10
// 008bdbbc  740e                 je 0x8bdbcc
// 008bdbbe  8b06                 mov eax, dword ptr [esi]
// 008bdbc0  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 008bdbc6  6a02                 push 2
// 008bdbc8  8bce                 mov ecx, esi
// 008bdbca  ffd2                 call edx
// 008bdbcc  5e                   pop esi
// 008bdbcd  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKillFocus@CXTPDockingPaneWindowSelect@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

// from server: 100% by auto
// roc 2010-06 008608f0  unit: CXTPDockingPaneWindowSelect  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008608f0
//
// 008608f0  8b442404             mov eax, dword ptr [esp + 4]
// 008608f4  398124010000         cmp dword ptr [ecx + 0x124], eax
// 008608fa  7414                 je 0x860910
// 008608fc  6a00                 push 0
// 008608fe  898124010000         mov dword ptr [ecx + 0x124], eax
// 00860904  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00860907  6a00                 push 0
// 00860909  50                   push eax
// 0086090a  ff1578ba9e00         call dword ptr [0x9eba78]
// 00860910  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?Select@CXTPDockingPaneWindowSelect@@QAEXPAUCItem@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

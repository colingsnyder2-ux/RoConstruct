// from server: 100% by auto
// roc 2009-12 008ac7a0  unit: CXTPDockingPaneWindowSelect  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ac7a0
//
// 008ac7a0  8b442404             mov eax, dword ptr [esp + 4]
// 008ac7a4  398124010000         cmp dword ptr [ecx + 0x124], eax
// 008ac7aa  7414                 je 0x8ac7c0
// 008ac7ac  6a00                 push 0
// 008ac7ae  898124010000         mov dword ptr [ecx + 0x124], eax
// 008ac7b4  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008ac7b7  6a00                 push 0
// 008ac7b9  50                   push eax
// 008ac7ba  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008ac7c0  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?Select@CXTPDockingPaneWindowSelect@@QAEXPAUCItem@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

// from server: 100% by auto
// roc 2009-06 007d1b40  unit: CXTPDockingPaneWindowSelect  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d1b40
//
// 007d1b40  8b442404             mov eax, dword ptr [esp + 4]
// 007d1b44  398124010000         cmp dword ptr [ecx + 0x124], eax
// 007d1b4a  7414                 je 0x7d1b60
// 007d1b4c  6a00                 push 0
// 007d1b4e  898124010000         mov dword ptr [ecx + 0x124], eax
// 007d1b54  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007d1b57  6a00                 push 0
// 007d1b59  50                   push eax
// 007d1b5a  ff157cee8900         call dword ptr [0x89ee7c]
// 007d1b60  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?Select@CXTPDockingPaneWindowSelect@@QAEXPAUCItem@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

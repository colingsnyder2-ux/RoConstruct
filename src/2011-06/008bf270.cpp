// from server: 100% by auto
// roc 2011-06 008bf270  unit: CXTPDockingPaneWindowSelect  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bf270
//
// 008bf270  56                   push esi
// 008bf271  8bf1                 mov esi, ecx
// 008bf273  6a0a                 push 0xa
// 008bf275  8d4e08               lea ecx, [esi + 8]
// 008bf278  c706245aad00         mov dword ptr [esi], 0xad5a24
// 008bf27e  e86deaffff           call 0x8bdcf0
// 008bf283  33c0                 xor eax, eax
// 008bf285  894628               mov dword ptr [esi + 0x28], eax
// 008bf288  894604               mov dword ptr [esi + 4], eax
// 008bf28b  894624               mov dword ptr [esi + 0x24], eax
// 008bf28e  8bc6                 mov eax, esi
// 008bf290  5e                   pop esi
// 008bf291  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ??0CXTPDockingPaneKeyboardHook@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

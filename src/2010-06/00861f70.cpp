// from server: 100% by auto
// roc 2010-06 00861f70  unit: CXTPDockingPaneWindowSelect  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00861f70
//
// 00861f70  56                   push esi
// 00861f71  8bf1                 mov esi, ecx
// 00861f73  6a0a                 push 0xa
// 00861f75  8d4e08               lea ecx, [esi + 8]
// 00861f78  c70614b0a600         mov dword ptr [esi], 0xa6b014
// 00861f7e  e86deaffff           call 0x8609f0
// 00861f83  33c0                 xor eax, eax
// 00861f85  894628               mov dword ptr [esi + 0x28], eax
// 00861f88  894604               mov dword ptr [esi + 4], eax
// 00861f8b  894624               mov dword ptr [esi + 0x24], eax
// 00861f8e  8bc6                 mov eax, esi
// 00861f90  5e                   pop esi
// 00861f91  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ??0CXTPDockingPaneKeyboardHook@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

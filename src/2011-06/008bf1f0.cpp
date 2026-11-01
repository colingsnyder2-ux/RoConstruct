// from server: 100% by auto
// roc 2011-06 008bf1f0  unit: CXTPDockingPaneWindowSelect  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bf1f0
//
// 008bf1f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008bf1f4  56                   push esi
// 008bf1f5  8bf1                 mov esi, ecx
// 008bf1f7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008bf1fb  50                   push eax
// 008bf1fc  51                   push ecx
// 008bf1fd  8bce                 mov ecx, esi
// 008bf1ff  e83ceeffff           call 0x8be040
// 008bf204  85c0                 test eax, eax
// 008bf206  7414                 je 0x8bf21c
// 008bf208  8b16                 mov edx, dword ptr [esi]
// 008bf20a  898624010000         mov dword ptr [esi + 0x124], eax
// 008bf210  8b8294000000         mov eax, dword ptr [edx + 0x94]
// 008bf216  6a01                 push 1
// 008bf218  8bce                 mov ecx, esi
// 008bf21a  ffd0                 call eax
// 008bf21c  8bce                 mov ecx, esi
// 008bf21e  e80bb4f4ff           call 0x80a62e
// 008bf223  5e                   pop esi
// 008bf224  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnLButtonUp@CXTPDockingPaneWindowSelect@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

// from server: 100% by auto
// roc 2010-06 00861ef0  unit: CXTPDockingPaneWindowSelect  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00861ef0
//
// 00861ef0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00861ef4  56                   push esi
// 00861ef5  8bf1                 mov esi, ecx
// 00861ef7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00861efb  50                   push eax
// 00861efc  51                   push ecx
// 00861efd  8bce                 mov ecx, esi
// 00861eff  e83ceeffff           call 0x860d40
// 00861f04  85c0                 test eax, eax
// 00861f06  7414                 je 0x861f1c
// 00861f08  8b16                 mov edx, dword ptr [esi]
// 00861f0a  898624010000         mov dword ptr [esi + 0x124], eax
// 00861f10  8b8294000000         mov eax, dword ptr [edx + 0x94]
// 00861f16  6a01                 push 1
// 00861f18  8bce                 mov ecx, esi
// 00861f1a  ffd0                 call eax
// 00861f1c  8bce                 mov ecx, esi
// 00861f1e  e84d60f4ff           call 0x7a7f70
// 00861f23  5e                   pop esi
// 00861f24  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnLButtonUp@CXTPDockingPaneWindowSelect@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

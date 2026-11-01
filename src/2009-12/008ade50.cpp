// from server: 100% by auto
// roc 2009-12 008ade50  unit: CXTPDockingPaneWindowSelect  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ade50
//
// 008ade50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008ade54  56                   push esi
// 008ade55  8bf1                 mov esi, ecx
// 008ade57  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ade5b  50                   push eax
// 008ade5c  51                   push ecx
// 008ade5d  8bce                 mov ecx, esi
// 008ade5f  e8fcedffff           call 0x8acc60
// 008ade64  85c0                 test eax, eax
// 008ade66  7411                 je 0x8ade79
// 008ade68  8bb628010000         mov esi, dword ptr [esi + 0x128]
// 008ade6e  56                   push esi
// 008ade6f  ff1520ca9800         call dword ptr [0x98ca20]
// 008ade75  5e                   pop esi
// 008ade76  c20c00               ret 0xc
// 008ade79  8bb62c010000         mov esi, dword ptr [esi + 0x12c]
// 008ade7f  56                   push esi
// 008ade80  ff1520ca9800         call dword ptr [0x98ca20]
// 008ade86  5e                   pop esi
// 008ade87  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnMouseMove@CXTPDockingPaneWindowSelect@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

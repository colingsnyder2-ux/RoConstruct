// from server: 100% by auto
// roc 2007-08 0070cc20  unit: CXTColorWnd  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070cc20
//
// 0070cc20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0070cc24  8b542404             mov edx, dword ptr [esp + 4]
// 0070cc28  56                   push esi
// 0070cc29  8bf1                 mov esi, ecx
// 0070cc2b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0070cc2f  50                   push eax
// 0070cc30  51                   push ecx
// 0070cc31  52                   push edx
// 0070cc32  8bce                 mov ecx, esi
// 0070cc34  e8e7feffff           call 0x70cb20
// 0070cc39  8b4620               mov eax, dword ptr [esi + 0x20]
// 0070cc3c  6a00                 push 0
// 0070cc3e  6a00                 push 0
// 0070cc40  50                   push eax
// 0070cc41  ff15dcec7700         call dword ptr [0x77ecdc]
// 0070cc47  5e                   pop esi
// 0070cc48  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?OnSize@CXTPDockingPaneSidePanel@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp

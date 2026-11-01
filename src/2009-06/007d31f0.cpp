// from server: 100% by auto
// roc 2009-06 007d31f0  unit: CXTPDockingPaneWindowSelect  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d31f0
//
// 007d31f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d31f4  56                   push esi
// 007d31f5  8bf1                 mov esi, ecx
// 007d31f7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007d31fb  50                   push eax
// 007d31fc  51                   push ecx
// 007d31fd  8bce                 mov ecx, esi
// 007d31ff  e8fcedffff           call 0x7d2000
// 007d3204  85c0                 test eax, eax
// 007d3206  7411                 je 0x7d3219
// 007d3208  8bb628010000         mov esi, dword ptr [esi + 0x128]
// 007d320e  56                   push esi
// 007d320f  ff1590ed8900         call dword ptr [0x89ed90]
// 007d3215  5e                   pop esi
// 007d3216  c20c00               ret 0xc
// 007d3219  8bb62c010000         mov esi, dword ptr [esi + 0x12c]
// 007d321f  56                   push esi
// 007d3220  ff1590ed8900         call dword ptr [0x89ed90]
// 007d3226  5e                   pop esi
// 007d3227  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnMouseMove@CXTPDockingPaneWindowSelect@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

// from server: 100% by auto
// roc 2010-06 00861f30  unit: CXTPDockingPaneWindowSelect  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00861f30
//
// 00861f30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00861f34  56                   push esi
// 00861f35  8bf1                 mov esi, ecx
// 00861f37  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00861f3b  50                   push eax
// 00861f3c  51                   push ecx
// 00861f3d  8bce                 mov ecx, esi
// 00861f3f  e8fcedffff           call 0x860d40
// 00861f44  85c0                 test eax, eax
// 00861f46  7411                 je 0x861f59
// 00861f48  8bb628010000         mov esi, dword ptr [esi + 0x128]
// 00861f4e  56                   push esi
// 00861f4f  ff15b4bb9e00         call dword ptr [0x9ebbb4]
// 00861f55  5e                   pop esi
// 00861f56  c20c00               ret 0xc
// 00861f59  8bb62c010000         mov esi, dword ptr [esi + 0x12c]
// 00861f5f  56                   push esi
// 00861f60  ff15b4bb9e00         call dword ptr [0x9ebbb4]
// 00861f66  5e                   pop esi
// 00861f67  c20c00               ret 0xc
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnMouseMove@CXTPDockingPaneWindowSelect@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp

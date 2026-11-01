// from server: 100% by auto
// roc 2009-06 007e15f0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e15f0
//
// 007e15f0  56                   push esi
// 007e15f1  8bf1                 mov esi, ecx
// 007e15f3  e8287df3ff           call 0x719320
// 007e15f8  8b442408             mov eax, dword ptr [esp + 8]
// 007e15fc  89465c               mov dword ptr [esi + 0x5c], eax
// 007e15ff  33c0                 xor eax, eax
// 007e1601  894658               mov dword ptr [esi + 0x58], eax
// 007e1604  894654               mov dword ptr [esi + 0x54], eax
// 007e1607  c706ec809000         mov dword ptr [esi], 0x9080ec
// 007e160d  8bc6                 mov eax, esi
// 007e160f  5e                   pop esi
// 007e1610  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??0CXTPDockingPaneContextStickerWnd@@QAE@PAVCXTPDockingPaneContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp

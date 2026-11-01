// from server: 100% by auto
// roc 2009-12 008bc100  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bc100
//
// 008bc100  56                   push esi
// 008bc101  8bf1                 mov esi, ecx
// 008bc103  e84080f3ff           call 0x7f4148
// 008bc108  8b442408             mov eax, dword ptr [esp + 8]
// 008bc10c  89465c               mov dword ptr [esi + 0x5c], eax
// 008bc10f  33c0                 xor eax, eax
// 008bc111  894658               mov dword ptr [esi + 0x58], eax
// 008bc114  894654               mov dword ptr [esi + 0x54], eax
// 008bc117  c7065c85a000         mov dword ptr [esi], 0xa0855c
// 008bc11d  8bc6                 mov eax, esi
// 008bc11f  5e                   pop esi
// 008bc120  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??0CXTPDockingPaneContextStickerWnd@@QAE@PAVCXTPDockingPaneContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp

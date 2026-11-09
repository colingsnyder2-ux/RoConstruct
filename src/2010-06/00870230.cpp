// from server: 100% by auto
// roc 2010-06 00870230  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00870230
//
// 00870230  56                   push esi
// 00870231  8bf1                 mov esi, ecx
// 00870233  e85080f3ff           call 0x7a8288
// 00870238  8b442408             mov eax, dword ptr [esp + 8]
// 0087023c  89465c               mov dword ptr [esi + 0x5c], eax
// 0087023f  33c0                 xor eax, eax
// 00870241  894658               mov dword ptr [esi + 0x58], eax
// 00870244  894654               mov dword ptr [esi + 0x54], eax
// 00870247  c70644c8a600         mov dword ptr [esi], 0xa6c844
// 0087024d  8bc6                 mov eax, esi
// 0087024f  5e                   pop esi
// 00870250  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??0CXTPDockingPaneContextStickerWnd@@QAE@PAVCXTPDockingPaneContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneContext.cpp

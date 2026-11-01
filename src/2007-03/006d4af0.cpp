// from server: 100% by auto
// roc 2007-03 006d4af0  unit: seg_006d0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d4af0
//
// 006d4af0  56                   push esi
// 006d4af1  8bf1                 mov esi, ecx
// 006d4af3  e8769ff4ff           call 0x61ea6e
// 006d4af8  8b442408             mov eax, dword ptr [esp + 8]
// 006d4afc  89465c               mov dword ptr [esi + 0x5c], eax
// 006d4aff  33c0                 xor eax, eax
// 006d4b01  894658               mov dword ptr [esi + 0x58], eax
// 006d4b04  894654               mov dword ptr [esi + 0x54], eax
// 006d4b07  c706cc7a7d00         mov dword ptr [esi], 0x7d7acc
// 006d4b0d  8bc6                 mov eax, esi
// 006d4b0f  5e                   pop esi
// 006d4b10  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??0CXTPDockingPaneContextStickerWnd@@QAE@PAVCXTPDockingPaneContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp

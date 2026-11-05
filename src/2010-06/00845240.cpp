// from server: 100% by auto
// roc 2010-06 00845240  unit: CXTPDockBar  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845240
//
// 00845240  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00845244  8bc1                 mov eax, ecx
// 00845246  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084524a  56                   push esi
// 0084524b  8b742414             mov esi, dword ptr [esp + 0x14]
// 0084524f  8908                 mov dword ptr [eax], ecx
// 00845251  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00845255  894804               mov dword ptr [eax + 4], ecx
// 00845258  894814               mov dword ptr [eax + 0x14], ecx
// 0084525b  57                   push edi
// 0084525c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00845260  895008               mov dword ptr [eax + 8], edx
// 00845263  895018               mov dword ptr [eax + 0x18], edx
// 00845266  8b542420             mov edx, dword ptr [esp + 0x20]
// 0084526a  89700c               mov dword ptr [eax + 0xc], esi
// 0084526d  89701c               mov dword ptr [eax + 0x1c], esi
// 00845270  897810               mov dword ptr [eax + 0x10], edi
// 00845273  897820               mov dword ptr [eax + 0x20], edi
// 00845276  33c9                 xor ecx, ecx
// 00845278  5f                   pop edi
// 00845279  895024               mov dword ptr [eax + 0x24], edx
// 0084527c  894828               mov dword ptr [eax + 0x28], ecx
// 0084527f  89482c               mov dword ptr [eax + 0x2c], ecx
// 00845282  5e                   pop esi
// 00845283  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ??0DOCK_INFO@CXTPDockBar@@QAE@PAVCXTPToolBar@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp

// from server: 100% by auto
// roc 2009-06 007b2680  unit: CXTPDockBar  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2680
//
// 007b2680  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007b2684  8bc1                 mov eax, ecx
// 007b2686  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b268a  56                   push esi
// 007b268b  8b742414             mov esi, dword ptr [esp + 0x14]
// 007b268f  8908                 mov dword ptr [eax], ecx
// 007b2691  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007b2695  894804               mov dword ptr [eax + 4], ecx
// 007b2698  894814               mov dword ptr [eax + 0x14], ecx
// 007b269b  57                   push edi
// 007b269c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007b26a0  895008               mov dword ptr [eax + 8], edx
// 007b26a3  895018               mov dword ptr [eax + 0x18], edx
// 007b26a6  8b542420             mov edx, dword ptr [esp + 0x20]
// 007b26aa  89700c               mov dword ptr [eax + 0xc], esi
// 007b26ad  89701c               mov dword ptr [eax + 0x1c], esi
// 007b26b0  897810               mov dword ptr [eax + 0x10], edi
// 007b26b3  897820               mov dword ptr [eax + 0x20], edi
// 007b26b6  33c9                 xor ecx, ecx
// 007b26b8  5f                   pop edi
// 007b26b9  895024               mov dword ptr [eax + 0x24], edx
// 007b26bc  894828               mov dword ptr [eax + 0x28], ecx
// 007b26bf  89482c               mov dword ptr [eax + 0x2c], ecx
// 007b26c2  5e                   pop esi
// 007b26c3  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ??0DOCK_INFO@CXTPDockBar@@QAE@PAVCXTPToolBar@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp

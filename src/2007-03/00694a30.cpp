// from server: 100% by auto
// roc 2007-03 00694a30  unit: seg_00690000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00694a30
//
// 00694a30  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00694a34  8bc1                 mov eax, ecx
// 00694a36  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00694a3a  56                   push esi
// 00694a3b  8b742414             mov esi, dword ptr [esp + 0x14]
// 00694a3f  8908                 mov dword ptr [eax], ecx
// 00694a41  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00694a45  894804               mov dword ptr [eax + 4], ecx
// 00694a48  894814               mov dword ptr [eax + 0x14], ecx
// 00694a4b  57                   push edi
// 00694a4c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00694a50  895008               mov dword ptr [eax + 8], edx
// 00694a53  895018               mov dword ptr [eax + 0x18], edx
// 00694a56  8b542420             mov edx, dword ptr [esp + 0x20]
// 00694a5a  89700c               mov dword ptr [eax + 0xc], esi
// 00694a5d  89701c               mov dword ptr [eax + 0x1c], esi
// 00694a60  897810               mov dword ptr [eax + 0x10], edi
// 00694a63  897820               mov dword ptr [eax + 0x20], edi
// 00694a66  33c9                 xor ecx, ecx
// 00694a68  5f                   pop edi
// 00694a69  895024               mov dword ptr [eax + 0x24], edx
// 00694a6c  894828               mov dword ptr [eax + 0x28], ecx
// 00694a6f  89482c               mov dword ptr [eax + 0x2c], ecx
// 00694a72  5e                   pop esi
// 00694a73  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ??0DOCK_INFO@CXTPDockBar@@QAE@PAVCXTPToolBar@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp

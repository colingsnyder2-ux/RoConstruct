// from server: 100% by auto
// roc 2009-12 00835300  unit: CXTPControls  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00835300
//
// 00835300  56                   push esi
// 00835301  8bf1                 mov esi, ecx
// 00835303  83c8ff               or eax, 0xffffffff
// 00835306  57                   push edi
// 00835307  33ff                 xor edi, edi
// 00835309  894610               mov dword ptr [esi + 0x10], eax
// 0083530c  89460c               mov dword ptr [esi + 0xc], eax
// 0083530f  8d461c               lea eax, [esi + 0x1c]
// 00835312  50                   push eax
// 00835313  893e                 mov dword ptr [esi], edi
// 00835315  897e08               mov dword ptr [esi + 8], edi
// 00835318  897e04               mov dword ptr [esi + 4], edi
// 0083531b  897e38               mov dword ptr [esi + 0x38], edi
// 0083531e  c74614ff7f0000       mov dword ptr [esi + 0x14], 0x7fff
// 00835325  897e18               mov dword ptr [esi + 0x18], edi
// 00835328  ff159cca9800         call dword ptr [0x98ca9c]
// 0083532e  33c0                 xor eax, eax
// 00835330  894630               mov dword ptr [esi + 0x30], eax
// 00835333  b8c8000000           mov eax, 0xc8
// 00835338  33c9                 xor ecx, ecx
// 0083533a  894e34               mov dword ptr [esi + 0x34], ecx
// 0083533d  8bc8                 mov ecx, eax
// 0083533f  897e2c               mov dword ptr [esi + 0x2c], edi
// 00835342  897e3c               mov dword ptr [esi + 0x3c], edi
// 00835345  894640               mov dword ptr [esi + 0x40], eax
// 00835348  894648               mov dword ptr [esi + 0x48], eax
// 0083534b  5f                   pop edi
// 0083534c  894e44               mov dword ptr [esi + 0x44], ecx
// 0083534f  894e4c               mov dword ptr [esi + 0x4c], ecx
// 00835352  8bc6                 mov eax, esi
// 00835354  5e                   pop esi
// 00835355  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ??0CToolBarInfo@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp

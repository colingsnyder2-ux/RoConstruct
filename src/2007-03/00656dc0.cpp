// from server: 100% by auto
// roc 2007-03 00656dc0  unit: seg_00650000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00656dc0
//
// 00656dc0  56                   push esi
// 00656dc1  8bf1                 mov esi, ecx
// 00656dc3  83c8ff               or eax, 0xffffffff
// 00656dc6  57                   push edi
// 00656dc7  33ff                 xor edi, edi
// 00656dc9  894610               mov dword ptr [esi + 0x10], eax
// 00656dcc  89460c               mov dword ptr [esi + 0xc], eax
// 00656dcf  8d461c               lea eax, [esi + 0x1c]
// 00656dd2  50                   push eax
// 00656dd3  893e                 mov dword ptr [esi], edi
// 00656dd5  897e08               mov dword ptr [esi + 8], edi
// 00656dd8  897e04               mov dword ptr [esi + 4], edi
// 00656ddb  897e38               mov dword ptr [esi + 0x38], edi
// 00656dde  c74614ff7f0000       mov dword ptr [esi + 0x14], 0x7fff
// 00656de5  897e18               mov dword ptr [esi + 0x18], edi
// 00656de8  ff1514ef7700         call dword ptr [0x77ef14]
// 00656dee  33c0                 xor eax, eax
// 00656df0  894630               mov dword ptr [esi + 0x30], eax
// 00656df3  b8c8000000           mov eax, 0xc8
// 00656df8  33c9                 xor ecx, ecx
// 00656dfa  894e34               mov dword ptr [esi + 0x34], ecx
// 00656dfd  8bc8                 mov ecx, eax
// 00656dff  897e2c               mov dword ptr [esi + 0x2c], edi
// 00656e02  897e3c               mov dword ptr [esi + 0x3c], edi
// 00656e05  894640               mov dword ptr [esi + 0x40], eax
// 00656e08  894648               mov dword ptr [esi + 0x48], eax
// 00656e0b  5f                   pop edi
// 00656e0c  894e44               mov dword ptr [esi + 0x44], ecx
// 00656e0f  894e4c               mov dword ptr [esi + 0x4c], ecx
// 00656e12  8bc6                 mov eax, esi
// 00656e14  5e                   pop esi
// 00656e15  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ??0CToolBarInfo@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp

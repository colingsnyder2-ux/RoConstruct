// from server: 100% by auto
// roc 2010-06 007e9520  unit: CXTPControls  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9520
//
// 007e9520  56                   push esi
// 007e9521  8bf1                 mov esi, ecx
// 007e9523  83c8ff               or eax, 0xffffffff
// 007e9526  57                   push edi
// 007e9527  33ff                 xor edi, edi
// 007e9529  894610               mov dword ptr [esi + 0x10], eax
// 007e952c  89460c               mov dword ptr [esi + 0xc], eax
// 007e952f  8d461c               lea eax, [esi + 0x1c]
// 007e9532  50                   push eax
// 007e9533  893e                 mov dword ptr [esi], edi
// 007e9535  897e08               mov dword ptr [esi + 8], edi
// 007e9538  897e04               mov dword ptr [esi + 4], edi
// 007e953b  897e38               mov dword ptr [esi + 0x38], edi
// 007e953e  c74614ff7f0000       mov dword ptr [esi + 0x14], 0x7fff
// 007e9545  897e18               mov dword ptr [esi + 0x18], edi
// 007e9548  ff15e4ba9e00         call dword ptr [0x9ebae4]
// 007e954e  33c0                 xor eax, eax
// 007e9550  894630               mov dword ptr [esi + 0x30], eax
// 007e9553  b8c8000000           mov eax, 0xc8
// 007e9558  33c9                 xor ecx, ecx
// 007e955a  894e34               mov dword ptr [esi + 0x34], ecx
// 007e955d  8bc8                 mov ecx, eax
// 007e955f  897e2c               mov dword ptr [esi + 0x2c], edi
// 007e9562  897e3c               mov dword ptr [esi + 0x3c], edi
// 007e9565  894640               mov dword ptr [esi + 0x40], eax
// 007e9568  894648               mov dword ptr [esi + 0x48], eax
// 007e956b  5f                   pop edi
// 007e956c  894e44               mov dword ptr [esi + 0x44], ecx
// 007e956f  894e4c               mov dword ptr [esi + 0x4c], ecx
// 007e9572  8bc6                 mov eax, esi
// 007e9574  5e                   pop esi
// 007e9575  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDockState.cpp (function ??0CToolBarInfo@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockState.cpp

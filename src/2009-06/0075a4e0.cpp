// from server: 100% by auto
// roc 2009-06 0075a4e0  unit: CXTPControls  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a4e0
//
// 0075a4e0  56                   push esi
// 0075a4e1  8bf1                 mov esi, ecx
// 0075a4e3  83c8ff               or eax, 0xffffffff
// 0075a4e6  57                   push edi
// 0075a4e7  33ff                 xor edi, edi
// 0075a4e9  894610               mov dword ptr [esi + 0x10], eax
// 0075a4ec  89460c               mov dword ptr [esi + 0xc], eax
// 0075a4ef  8d461c               lea eax, [esi + 0x1c]
// 0075a4f2  50                   push eax
// 0075a4f3  893e                 mov dword ptr [esi], edi
// 0075a4f5  897e08               mov dword ptr [esi + 8], edi
// 0075a4f8  897e04               mov dword ptr [esi + 4], edi
// 0075a4fb  897e38               mov dword ptr [esi + 0x38], edi
// 0075a4fe  c74614ff7f0000       mov dword ptr [esi + 0x14], 0x7fff
// 0075a505  897e18               mov dword ptr [esi + 0x18], edi
// 0075a508  ff15c8ee8900         call dword ptr [0x89eec8]
// 0075a50e  33c0                 xor eax, eax
// 0075a510  894630               mov dword ptr [esi + 0x30], eax
// 0075a513  b8c8000000           mov eax, 0xc8
// 0075a518  33c9                 xor ecx, ecx
// 0075a51a  894e34               mov dword ptr [esi + 0x34], ecx
// 0075a51d  8bc8                 mov ecx, eax
// 0075a51f  897e2c               mov dword ptr [esi + 0x2c], edi
// 0075a522  897e3c               mov dword ptr [esi + 0x3c], edi
// 0075a525  894640               mov dword ptr [esi + 0x40], eax
// 0075a528  894648               mov dword ptr [esi + 0x48], eax
// 0075a52b  5f                   pop edi
// 0075a52c  894e44               mov dword ptr [esi + 0x44], ecx
// 0075a52f  894e4c               mov dword ptr [esi + 0x4c], ecx
// 0075a532  8bc6                 mov eax, esi
// 0075a534  5e                   pop esi
// 0075a535  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ??0CToolBarInfo@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp

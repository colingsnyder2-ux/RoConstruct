// from server: 100% by auto
// roc 2010-06 008915e0  unit: CXTColorBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008915e0
//
// 008915e0  56                   push esi
// 008915e1  8bf1                 mov esi, ecx
// 008915e3  8b4620               mov eax, dword ptr [esi + 0x20]
// 008915e6  50                   push eax
// 008915e7  ff1528bc9e00         call dword ptr [0x9ebc28]
// 008915ed  85c0                 test eax, eax
// 008915ef  7422                 je 0x891613
// 008915f1  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008915f4  6af0                 push -0x10
// 008915f6  51                   push ecx
// 008915f7  ff15fcbb9e00         call dword ptr [0x9ebbfc]
// 008915fd  8b5620               mov edx, dword ptr [esi + 0x20]
// 00891600  0d00010000           or eax, 0x100
// 00891605  50                   push eax
// 00891606  6af0                 push -0x10
// 00891608  52                   push edx
// 00891609  ff1500bc9e00         call dword ptr [0x9ebc00]
// 0089160f  b001                 mov al, 1
// 00891611  5e                   pop esi
// 00891612  c3                   ret 
// 00891613  32c0                 xor al, al
// 00891615  5e                   pop esi
// 00891616  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?Init@CXTColorBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp

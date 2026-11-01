// from server: 100% by auto
// roc 2009-12 008dd390  unit: CXTColorBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd390
//
// 008dd390  56                   push esi
// 008dd391  8bf1                 mov esi, ecx
// 008dd393  8b4620               mov eax, dword ptr [esi + 0x20]
// 008dd396  50                   push eax
// 008dd397  ff1584cc9800         call dword ptr [0x98cc84]
// 008dd39d  85c0                 test eax, eax
// 008dd39f  7422                 je 0x8dd3c3
// 008dd3a1  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008dd3a4  6af0                 push -0x10
// 008dd3a6  51                   push ecx
// 008dd3a7  ff15d8c99800         call dword ptr [0x98c9d8]
// 008dd3ad  8b5620               mov edx, dword ptr [esi + 0x20]
// 008dd3b0  0d00010000           or eax, 0x100
// 008dd3b5  50                   push eax
// 008dd3b6  6af0                 push -0x10
// 008dd3b8  52                   push edx
// 008dd3b9  ff15c0c99800         call dword ptr [0x98c9c0]
// 008dd3bf  b001                 mov al, 1
// 008dd3c1  5e                   pop esi
// 008dd3c2  c3                   ret 
// 008dd3c3  32c0                 xor al, al
// 008dd3c5  5e                   pop esi
// 008dd3c6  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?Init@CXTPColorBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp

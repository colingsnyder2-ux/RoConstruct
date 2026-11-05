// from server: 100% by auto
// roc 2010-06 0088d3a0  unit: CXTColorHex  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088d3a0
//
// 0088d3a0  56                   push esi
// 0088d3a1  8bf1                 mov esi, ecx
// 0088d3a3  8b4620               mov eax, dword ptr [esi + 0x20]
// 0088d3a6  50                   push eax
// 0088d3a7  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0088d3ad  85c0                 test eax, eax
// 0088d3af  7414                 je 0x88d3c5
// 0088d3b1  6a00                 push 0
// 0088d3b3  6800010000           push 0x100
// 0088d3b8  6a00                 push 0
// 0088d3ba  8bce                 mov ecx, esi
// 0088d3bc  e859adf1ff           call 0x7a811a
// 0088d3c1  b001                 mov al, 1
// 0088d3c3  5e                   pop esi
// 0088d3c4  c3                   ret 
// 0088d3c5  32c0                 xor al, al
// 0088d3c7  5e                   pop esi
// 0088d3c8  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?Init@CXTColorHex@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

// from server: 100% by auto
// roc 2009-12 008d91f0  unit: CXTColorHex  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d91f0
//
// 008d91f0  56                   push esi
// 008d91f1  8bf1                 mov esi, ecx
// 008d91f3  8b4620               mov eax, dword ptr [esi + 0x20]
// 008d91f6  50                   push eax
// 008d91f7  ff1584cc9800         call dword ptr [0x98cc84]
// 008d91fd  85c0                 test eax, eax
// 008d91ff  7414                 je 0x8d9215
// 008d9201  6a00                 push 0
// 008d9203  6800010000           push 0x100
// 008d9208  6a00                 push 0
// 008d920a  8bce                 mov ecx, esi
// 008d920c  e8c9adf1ff           call 0x7f3fda
// 008d9211  b001                 mov al, 1
// 008d9213  5e                   pop esi
// 008d9214  c3                   ret 
// 008d9215  32c0                 xor al, al
// 008d9217  5e                   pop esi
// 008d9218  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?Init@CXTColorHex@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

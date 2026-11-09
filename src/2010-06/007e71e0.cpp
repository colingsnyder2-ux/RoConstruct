// from server: 100% by auto
// roc 2010-06 007e71e0  unit: CXTTreeBase  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e71e0
//
// 007e71e0  56                   push esi
// 007e71e1  8bf1                 mov esi, ecx
// 007e71e3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e71e6  e8f35b1900           call 0x97cdde
// 007e71eb  a900020000           test eax, 0x200
// 007e71f0  741e                 je 0x7e7210
// 007e71f2  837e1400             cmp dword ptr [esi + 0x14], 0
// 007e71f6  7418                 je 0x7e7210
// 007e71f8  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e71fb  6a00                 push 0
// 007e71fd  c7461400000000       mov dword ptr [esi + 0x14], 0
// 007e7204  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e7207  6a00                 push 0
// 007e7209  51                   push ecx
// 007e720a  ff1578ba9e00         call dword ptr [0x9eba78]
// 007e7210  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7213  e8580dfcff           call 0x7a7f70
// 007e7218  5e                   pop esi
// 007e7219  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnNcMouseMove@CXTTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp

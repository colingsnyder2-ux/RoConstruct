// from server: 100% by auto
// roc 2011-06 008e6030  unit: CXTColorHex  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e6030
//
// 008e6030  56                   push esi
// 008e6031  8bf1                 mov esi, ecx
// 008e6033  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e6036  50                   push eax
// 008e6037  ff15ec1ba400         call dword ptr [0xa41bec]
// 008e603d  85c0                 test eax, eax
// 008e603f  7414                 je 0x8e6055
// 008e6041  6a00                 push 0
// 008e6043  6800010000           push 0x100
// 008e6048  6a00                 push 0
// 008e604a  8bce                 mov ecx, esi
// 008e604c  e88747f2ff           call 0x80a7d8
// 008e6051  b001                 mov al, 1
// 008e6053  5e                   pop esi
// 008e6054  c3                   ret 
// 008e6055  32c0                 xor al, al
// 008e6057  5e                   pop esi
// 008e6058  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?Init@CXTColorHex@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

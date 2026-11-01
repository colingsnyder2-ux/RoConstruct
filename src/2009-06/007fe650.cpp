// from server: 100% by auto
// roc 2009-06 007fe650  unit: CXTColorHex  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fe650
//
// 007fe650  56                   push esi
// 007fe651  8bf1                 mov esi, ecx
// 007fe653  8b4620               mov eax, dword ptr [esi + 0x20]
// 007fe656  50                   push eax
// 007fe657  ff15e0ed8900         call dword ptr [0x89ede0]
// 007fe65d  85c0                 test eax, eax
// 007fe65f  7414                 je 0x7fe675
// 007fe661  6a00                 push 0
// 007fe663  6800010000           push 0x100
// 007fe668  6a00                 push 0
// 007fe66a  8bce                 mov ecx, esi
// 007fe66c  e841abf1ff           call 0x7191b2
// 007fe671  b001                 mov al, 1
// 007fe673  5e                   pop esi
// 007fe674  c3                   ret 
// 007fe675  32c0                 xor al, al
// 007fe677  5e                   pop esi
// 007fe678  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?Init@CXTColorHex@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

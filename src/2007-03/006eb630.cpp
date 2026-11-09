// from server: 100% by auto
// roc 2007-03 006eb630  unit: seg_006e0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006eb630
//
// 006eb630  56                   push esi
// 006eb631  8bf1                 mov esi, ecx
// 006eb633  8b4620               mov eax, dword ptr [esi + 0x20]
// 006eb636  50                   push eax
// 006eb637  ff1574ed7700         call dword ptr [0x77ed74]
// 006eb63d  85c0                 test eax, eax
// 006eb63f  7414                 je 0x6eb655
// 006eb641  6a00                 push 0
// 006eb643  6800010000           push 0x100
// 006eb648  6a00                 push 0
// 006eb64a  8bce                 mov ecx, esi
// 006eb64c  e8fb31f3ff           call 0x61e84c
// 006eb651  b001                 mov al, 1
// 006eb653  5e                   pop esi
// 006eb654  c3                   ret 
// 006eb655  32c0                 xor al, al
// 006eb657  5e                   pop esi
// 006eb658  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?Init@CXTColorHex@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

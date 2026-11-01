// from server: 100% by auto
// roc 2009-12 008df630  unit: CXTColorPageCustom  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df630
//
// 008df630  56                   push esi
// 008df631  8bf1                 mov esi, ecx
// 008df633  8b8620010000         mov eax, dword ptr [esi + 0x120]
// 008df639  c70694bca000         mov dword ptr [esi], 0xa0bc94
// 008df63f  85c0                 test eax, eax
// 008df641  7407                 je 0x8df64a
// 008df643  50                   push eax
// 008df644  ff15f8b19800         call dword ptr [0x98b1f8]
// 008df64a  8bce                 mov ecx, esi
// 008df64c  5e                   pop esi
// 008df64d  e9904df1ff           jmp 0x7f43e2
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ??1CXTPRichRender@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp

// from server: 100% by auto
// roc 2007-03 006885c0  unit: seg_00680000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006885c0
//
// 006885c0  56                   push esi
// 006885c1  8bf1                 mov esi, ecx
// 006885c3  e80a61f9ff           call 0x61e6d2
// 006885c8  8bce                 mov ecx, esi
// 006885ca  e8e1feffff           call 0x6884b0
// 006885cf  8b4620               mov eax, dword ptr [esi + 0x20]
// 006885d2  6a00                 push 0
// 006885d4  6a00                 push 0
// 006885d6  50                   push eax
// 006885d7  ff1554ee7700         call dword ptr [0x77ee54]
// 006885dd  5e                   pop esi
// 006885de  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnSize@CXTPPropertyGridView@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp

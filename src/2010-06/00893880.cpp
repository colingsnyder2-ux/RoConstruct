// from server: 100% by auto
// roc 2010-06 00893880  unit: CXTColorPageCustom  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893880
//
// 00893880  56                   push esi
// 00893881  8bf1                 mov esi, ecx
// 00893883  8b8620010000         mov eax, dword ptr [esi + 0x120]
// 00893889  c7068cffa600         mov dword ptr [esi], 0xa6ff8c
// 0089388f  85c0                 test eax, eax
// 00893891  7407                 je 0x89389a
// 00893893  50                   push eax
// 00893894  ff1568a39e00         call dword ptr [0x9ea368]
// 0089389a  8bce                 mov ecx, esi
// 0089389c  5e                   pop esi
// 0089389d  e9804cf1ff           jmp 0x7a8522
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ??1CXTPRichRender@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp

// from server: 100% by auto
// roc 2009-06 007916c0  unit: CXTCaption  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007916c0
//
// 007916c0  56                   push esi
// 007916c1  8bf1                 mov esi, ecx
// 007916c3  e84079f8ff           call 0x719008
// 007916c8  83becc00000000       cmp dword ptr [esi + 0xcc], 0
// 007916cf  7413                 je 0x7916e4
// 007916d1  8b4620               mov eax, dword ptr [esi + 0x20]
// 007916d4  6805010000           push 0x105
// 007916d9  6a00                 push 0
// 007916db  6a00                 push 0
// 007916dd  50                   push eax
// 007916de  ff15e8ee8900         call dword ptr [0x89eee8]
// 007916e4  5e                   pop esi
// 007916e5  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSize@CXTCaption@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp

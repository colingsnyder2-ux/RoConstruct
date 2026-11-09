// from server: 100% by auto
// roc 2007-03 0068b800  unit: seg_00680000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068b800
//
// 0068b800  56                   push esi
// 0068b801  8bf1                 mov esi, ecx
// 0068b803  e8ca2ef9ff           call 0x61e6d2
// 0068b808  83becc00000000       cmp dword ptr [esi + 0xcc], 0
// 0068b80f  7413                 je 0x68b824
// 0068b811  8b4620               mov eax, dword ptr [esi + 0x20]
// 0068b814  6805010000           push 0x105
// 0068b819  6a00                 push 0
// 0068b81b  6a00                 push 0
// 0068b81d  50                   push eax
// 0068b81e  ff1518ef7700         call dword ptr [0x77ef18]
// 0068b824  5e                   pop esi
// 0068b825  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSize@CXTCaption@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp

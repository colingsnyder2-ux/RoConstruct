// from server: 100% by auto
// roc 2011-06 0087ead0  unit: CXTCaption  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087ead0
//
// 0087ead0  56                   push esi
// 0087ead1  8bf1                 mov esi, ecx
// 0087ead3  e856bbf8ff           call 0x80a62e
// 0087ead8  83becc00000000       cmp dword ptr [esi + 0xcc], 0
// 0087eadf  7413                 je 0x87eaf4
// 0087eae1  8b4620               mov eax, dword ptr [esi + 0x20]
// 0087eae4  6805010000           push 0x105
// 0087eae9  6a00                 push 0
// 0087eaeb  6a00                 push 0
// 0087eaed  50                   push eax
// 0087eaee  ff15b41aa400         call dword ptr [0xa41ab4]
// 0087eaf4  5e                   pop esi
// 0087eaf5  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSize@CXTCaption@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp

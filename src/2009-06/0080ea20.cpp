// from server: 100% by auto
// roc 2009-06 0080ea20  unit: CXTPRibbonGroupControlPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080ea20
//
// 0080ea20  56                   push esi
// 0080ea21  8bf1                 mov esi, ecx
// 0080ea23  8b4658               mov eax, dword ptr [esi + 0x58]
// 0080ea26  50                   push eax
// 0080ea27  e854530000           call 0x813d80
// 0080ea2c  83c404               add esp, 4
// 0080ea2f  85c0                 test eax, eax
// 0080ea31  740c                 je 0x80ea3f
// 0080ea33  397014               cmp dword ptr [eax + 0x14], esi
// 0080ea36  7507                 jne 0x80ea3f
// 0080ea38  b801000000           mov eax, 1
// 0080ea3d  5e                   pop esi
// 0080ea3e  c3                   ret 
// 0080ea3f  33c0                 xor eax, eax
// 0080ea41  5e                   pop esi
// 0080ea42  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsHighlighted@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroup.cpp

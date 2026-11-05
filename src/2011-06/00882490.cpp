// from server: 100% by auto
// roc 2011-06 00882490  unit: CXTPControlGallery  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00882490
//
// 00882490  e85bf1ffff           call 0x8815f0
// 00882495  85c0                 test eax, eax
// 00882497  7407                 je 0x8824a0
// 00882499  8bc8                 mov ecx, eax
// 0088249b  e9e0fcffff           jmp 0x882180
// 008824a0  33c0                 xor eax, eax
// 008824a2  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetItem@CXTPControlGallery@@QBEPAVCXTPControlGalleryItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp

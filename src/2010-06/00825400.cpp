// from server: 100% by auto
// roc 2010-06 00825400  unit: CXTPControlGallery  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00825400
//
// 00825400  e84bf1ffff           call 0x824550
// 00825405  85c0                 test eax, eax
// 00825407  7407                 je 0x825410
// 00825409  8bc8                 mov ecx, eax
// 0082540b  e9e0fcffff           jmp 0x8250f0
// 00825410  33c0                 xor eax, eax
// 00825412  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetItem@CXTPControlGallery@@QBEPAVCXTPControlGalleryItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp

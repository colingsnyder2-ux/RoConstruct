// from server: 100% by auto
// roc 2009-06 0079d270  unit: CXTPControlGallery  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079d270
//
// 0079d270  e85bf1ffff           call 0x79c3d0
// 0079d275  85c0                 test eax, eax
// 0079d277  7407                 je 0x79d280
// 0079d279  8bc8                 mov ecx, eax
// 0079d27b  e9e0fcffff           jmp 0x79cf60
// 0079d280  33c0                 xor eax, eax
// 0079d282  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetItem@CXTPControlGallery@@QBEPAVCXTPControlGalleryItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp

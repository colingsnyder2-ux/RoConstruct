// from server: 100% by auto
// roc 2009-12 00878200  unit: CXTPControlGallery  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00878200
//
// 00878200  e84bf1ffff           call 0x877350
// 00878205  85c0                 test eax, eax
// 00878207  7407                 je 0x878210
// 00878209  8bc8                 mov ecx, eax
// 0087820b  e9e0fcffff           jmp 0x877ef0
// 00878210  33c0                 xor eax, eax
// 00878212  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetItem@CXTPControlGallery@@QBEPAVCXTPControlGalleryItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp

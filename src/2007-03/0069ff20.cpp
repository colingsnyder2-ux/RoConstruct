// from server: 100% by auto
// roc 2007-03 0069ff20  unit: seg_00690000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069ff20
//
// 0069ff20  e88bf8ffff           call 0x69f7b0
// 0069ff25  85c0                 test eax, eax
// 0069ff27  7407                 je 0x69ff30
// 0069ff29  8bc8                 mov ecx, eax
// 0069ff2b  e9a0ffffff           jmp 0x69fed0
// 0069ff30  33c0                 xor eax, eax
// 0069ff32  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetItem@CXTPControlGallery@@QBEPAVCXTPControlGalleryItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp

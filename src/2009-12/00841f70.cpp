// from server: 100% by auto
// roc 2009-12 00841f70  unit: CXTPPopupBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00841f70
//
// 00841f70  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00841f73  85c0                 test eax, eax
// 00841f75  7411                 je 0x841f88
// 00841f77  50                   push eax
// 00841f78  ff1564ca9800         call dword ptr [0x98ca64]
// 00841f7e  85c0                 test eax, eax
// 00841f80  7406                 je 0x841f88
// 00841f82  b801000000           mov eax, 1
// 00841f87  c3                   ret 
// 00841f88  33c0                 xor eax, eax
// 00841f8a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPGalleryListBox.cpp (function ?IsVisible@CXTPGalleryListBox@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPGalleryListBox.cpp

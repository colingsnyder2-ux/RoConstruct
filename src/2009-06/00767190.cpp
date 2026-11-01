// from server: 100% by auto
// roc 2009-06 00767190  unit: CXTPPopupBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00767190
//
// 00767190  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00767193  85c0                 test eax, eax
// 00767195  7411                 je 0x7671a8
// 00767197  50                   push eax
// 00767198  ff15c8ed8900         call dword ptr [0x89edc8]
// 0076719e  85c0                 test eax, eax
// 007671a0  7406                 je 0x7671a8
// 007671a2  b801000000           mov eax, 1
// 007671a7  c3                   ret 
// 007671a8  33c0                 xor eax, eax
// 007671aa  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPGalleryListBox.cpp (function ?IsVisible@CXTPGalleryListBox@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPGalleryListBox.cpp

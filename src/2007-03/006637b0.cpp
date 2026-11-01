// from server: 100% by auto
// roc 2007-03 006637b0  unit: seg_00660000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006637b0
//
// 006637b0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006637b3  85c0                 test eax, eax
// 006637b5  7411                 je 0x6637c8
// 006637b7  50                   push eax
// 006637b8  ff158ced7700         call dword ptr [0x77ed8c]
// 006637be  85c0                 test eax, eax
// 006637c0  7406                 je 0x6637c8
// 006637c2  b801000000           mov eax, 1
// 006637c7  c3                   ret 
// 006637c8  33c0                 xor eax, eax
// 006637ca  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPGalleryListBox.cpp (function ?IsVisible@CXTPGalleryListBox@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPGalleryListBox.cpp

// from server: 100% by auto
// roc 2010-06 007e5b00  unit: CXTTreeBase  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5b00
//
// 007e5b00  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e5b03  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007e5b06  6a00                 push 0
// 007e5b08  6a09                 push 9
// 007e5b0a  680a110000           push 0x110a
// 007e5b0f  50                   push eax
// 007e5b10  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e5b16  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetFocusedItem@CXTTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp

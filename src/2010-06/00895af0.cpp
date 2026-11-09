// from server: 100% by auto
// roc 2010-06 00895af0  unit: CXTPOffice2007Image  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00895af0
//
// 00895af0  56                   push esi
// 00895af1  8bf1                 mov esi, ecx
// 00895af3  e8e6720e00           call 0x97cdde
// 00895af8  85c0                 test eax, eax
// 00895afa  7909                 jns 0x895b05
// 00895afc  b803000000           mov eax, 3
// 00895b01  5e                   pop esi
// 00895b02  c20c00               ret 0xc
// 00895b05  8bce                 mov ecx, esi
// 00895b07  e86424f1ff           call 0x7a7f70
// 00895b0c  5e                   pop esi
// 00895b0d  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?OnMouseActivate@CXTColorSelectorCtrl@@IAEHPAVCWnd@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp

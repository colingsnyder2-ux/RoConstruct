// from server: 100% by auto
// roc 2009-12 008e1890  unit: CXTPOffice2007Image  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e1890
//
// 008e1890  56                   push esi
// 008e1891  8bf1                 mov esi, ecx
// 008e1893  e8da4b0400           call 0x926472
// 008e1898  85c0                 test eax, eax
// 008e189a  7909                 jns 0x8e18a5
// 008e189c  b803000000           mov eax, 3
// 008e18a1  5e                   pop esi
// 008e18a2  c20c00               ret 0xc
// 008e18a5  8bce                 mov ecx, esi
// 008e18a7  e88425f1ff           call 0x7f3e30
// 008e18ac  5e                   pop esi
// 008e18ad  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Popup\XTPColorSelectorCtrl.cpp (function ?OnMouseActivate@CXTPColorSelectorCtrl@@IAEHPAVCWnd@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Popup/XTPColorSelectorCtrl.cpp

// from server: 100% by auto
// roc 2009-06 00806d80  unit: CXTPOffice2007Image  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00806d80
//
// 00806d80  56                   push esi
// 00806d81  8bf1                 mov esi, ecx
// 00806d83  e854510400           call 0x84bedc
// 00806d88  85c0                 test eax, eax
// 00806d8a  7909                 jns 0x806d95
// 00806d8c  b803000000           mov eax, 3
// 00806d91  5e                   pop esi
// 00806d92  c20c00               ret 0xc
// 00806d95  8bce                 mov ecx, esi
// 00806d97  e86c22f1ff           call 0x719008
// 00806d9c  5e                   pop esi
// 00806d9d  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Popup\XTPColorSelectorCtrl.cpp (function ?OnMouseActivate@CXTPColorSelectorCtrl@@IAEHPAVCWnd@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Popup/XTPColorSelectorCtrl.cpp

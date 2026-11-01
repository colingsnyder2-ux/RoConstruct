// from server: 100% by auto
// roc 2011-06 008e7c20  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e7c20
//
// 008e7c20  56                   push esi
// 008e7c21  8bf1                 mov esi, ecx
// 008e7c23  837e6000             cmp dword ptr [esi + 0x60], 0
// 008e7c27  7411                 je 0x8e7c3a
// 008e7c29  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e7c2d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e7c31  50                   push eax
// 008e7c32  51                   push ecx
// 008e7c33  8bce                 mov ecx, esi
// 008e7c35  e806feffff           call 0x8e7a40
// 008e7c3a  8bce                 mov ecx, esi
// 008e7c3c  e8ed29f2ff           call 0x80a62e
// 008e7c41  5e                   pop esi
// 008e7c42  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnMouseMove@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

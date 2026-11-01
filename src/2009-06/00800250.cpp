// from server: 100% by auto
// roc 2009-06 00800250  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00800250
//
// 00800250  56                   push esi
// 00800251  8bf1                 mov esi, ecx
// 00800253  837e6000             cmp dword ptr [esi + 0x60], 0
// 00800257  7411                 je 0x80026a
// 00800259  8b442410             mov eax, dword ptr [esp + 0x10]
// 0080025d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00800261  50                   push eax
// 00800262  51                   push ecx
// 00800263  8bce                 mov ecx, esi
// 00800265  e806feffff           call 0x800070
// 0080026a  8bce                 mov ecx, esi
// 0080026c  e8978df1ff           call 0x719008
// 00800271  5e                   pop esi
// 00800272  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnMouseMove@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

// from server: 100% by auto
// roc 2010-06 0088efe0  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088efe0
//
// 0088efe0  56                   push esi
// 0088efe1  8bf1                 mov esi, ecx
// 0088efe3  837e6000             cmp dword ptr [esi + 0x60], 0
// 0088efe7  7411                 je 0x88effa
// 0088efe9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088efed  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0088eff1  50                   push eax
// 0088eff2  51                   push ecx
// 0088eff3  8bce                 mov ecx, esi
// 0088eff5  e806feffff           call 0x88ee00
// 0088effa  8bce                 mov ecx, esi
// 0088effc  e86f8ff1ff           call 0x7a7f70
// 0088f001  5e                   pop esi
// 0088f002  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnMouseMove@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

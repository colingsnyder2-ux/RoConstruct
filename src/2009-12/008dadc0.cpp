// from server: 100% by auto
// roc 2009-12 008dadc0  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dadc0
//
// 008dadc0  56                   push esi
// 008dadc1  8bf1                 mov esi, ecx
// 008dadc3  837e6000             cmp dword ptr [esi + 0x60], 0
// 008dadc7  7411                 je 0x8dadda
// 008dadc9  8b442410             mov eax, dword ptr [esp + 0x10]
// 008dadcd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008dadd1  50                   push eax
// 008dadd2  51                   push ecx
// 008dadd3  8bce                 mov ecx, esi
// 008dadd5  e806feffff           call 0x8dabe0
// 008dadda  8bce                 mov ecx, esi
// 008daddc  e84f90f1ff           call 0x7f3e30
// 008dade1  5e                   pop esi
// 008dade2  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnMouseMove@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

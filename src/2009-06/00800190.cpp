// from server: 100% by auto
// roc 2009-06 00800190  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00800190
//
// 00800190  56                   push esi
// 00800191  8bf1                 mov esi, ecx
// 00800193  ff1578ee8900         call dword ptr [0x89ee78]
// 00800199  50                   push eax
// 0080019a  e8638bf1ff           call 0x718d02
// 0080019f  3bc6                 cmp eax, esi
// 008001a1  7407                 je 0x8001aa
// 008001a3  8bce                 mov ecx, esi
// 008001a5  e8308cf1ff           call 0x718dda
// 008001aa  8b442410             mov eax, dword ptr [esp + 0x10]
// 008001ae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008001b2  50                   push eax
// 008001b3  51                   push ecx
// 008001b4  8bce                 mov ecx, esi
// 008001b6  e8b5feffff           call 0x800070
// 008001bb  8bce                 mov ecx, esi
// 008001bd  c7466001000000       mov dword ptr [esi + 0x60], 1
// 008001c4  e83f8ef1ff           call 0x719008
// 008001c9  5e                   pop esi
// 008001ca  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDown@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

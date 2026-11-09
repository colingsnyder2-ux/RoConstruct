// from server: 100% by auto
// roc 2011-06 008e7b60  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e7b60
//
// 008e7b60  56                   push esi
// 008e7b61  8bf1                 mov esi, ecx
// 008e7b63  ff15f819a400         call dword ptr [0xa419f8]
// 008e7b69  50                   push eax
// 008e7b6a  e8b927f2ff           call 0x80a328
// 008e7b6f  3bc6                 cmp eax, esi
// 008e7b71  7407                 je 0x8e7b7a
// 008e7b73  8bce                 mov ecx, esi
// 008e7b75  e88628f2ff           call 0x80a400
// 008e7b7a  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e7b7e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e7b82  50                   push eax
// 008e7b83  51                   push ecx
// 008e7b84  8bce                 mov ecx, esi
// 008e7b86  e8b5feffff           call 0x8e7a40
// 008e7b8b  8bce                 mov ecx, esi
// 008e7b8d  c7466001000000       mov dword ptr [esi + 0x60], 1
// 008e7b94  e8952af2ff           call 0x80a62e
// 008e7b99  5e                   pop esi
// 008e7b9a  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDown@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

// from server: 100% by auto
// roc 2009-12 008dad00  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dad00
//
// 008dad00  56                   push esi
// 008dad01  8bf1                 mov esi, ecx
// 008dad03  ff15eccb9800         call dword ptr [0x98cbec]
// 008dad09  50                   push eax
// 008dad0a  e81b8ef1ff           call 0x7f3b2a
// 008dad0f  3bc6                 cmp eax, esi
// 008dad11  7407                 je 0x8dad1a
// 008dad13  8bce                 mov ecx, esi
// 008dad15  e8e88ef1ff           call 0x7f3c02
// 008dad1a  8b442410             mov eax, dword ptr [esp + 0x10]
// 008dad1e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008dad22  50                   push eax
// 008dad23  51                   push ecx
// 008dad24  8bce                 mov ecx, esi
// 008dad26  e8b5feffff           call 0x8dabe0
// 008dad2b  8bce                 mov ecx, esi
// 008dad2d  c7466001000000       mov dword ptr [esi + 0x60], 1
// 008dad34  e8f790f1ff           call 0x7f3e30
// 008dad39  5e                   pop esi
// 008dad3a  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDown@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

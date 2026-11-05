// from server: 100% by auto
// roc 2010-06 0088ef20  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088ef20
//
// 0088ef20  56                   push esi
// 0088ef21  8bf1                 mov esi, ecx
// 0088ef23  ff1580ba9e00         call dword ptr [0x9eba80]
// 0088ef29  50                   push eax
// 0088ef2a  e83b8df1ff           call 0x7a7c6a
// 0088ef2f  3bc6                 cmp eax, esi
// 0088ef31  7407                 je 0x88ef3a
// 0088ef33  8bce                 mov ecx, esi
// 0088ef35  e8088ef1ff           call 0x7a7d42
// 0088ef3a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088ef3e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0088ef42  50                   push eax
// 0088ef43  51                   push ecx
// 0088ef44  8bce                 mov ecx, esi
// 0088ef46  e8b5feffff           call 0x88ee00
// 0088ef4b  8bce                 mov ecx, esi
// 0088ef4d  c7466001000000       mov dword ptr [esi + 0x60], 1
// 0088ef54  e81790f1ff           call 0x7a7f70
// 0088ef59  5e                   pop esi
// 0088ef5a  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDown@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

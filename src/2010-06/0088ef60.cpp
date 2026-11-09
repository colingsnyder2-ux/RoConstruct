// from server: 100% by auto
// roc 2010-06 0088ef60  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088ef60
//
// 0088ef60  53                   push ebx
// 0088ef61  56                   push esi
// 0088ef62  57                   push edi
// 0088ef63  8bf1                 mov esi, ecx
// 0088ef65  e80690f1ff           call 0x7a7f70
// 0088ef6a  ff1580ba9e00         call dword ptr [0x9eba80]
// 0088ef70  50                   push eax
// 0088ef71  e8f48cf1ff           call 0x7a7c6a
// 0088ef76  3bc6                 cmp eax, esi
// 0088ef78  7407                 je 0x88ef81
// 0088ef7a  8bce                 mov ecx, esi
// 0088ef7c  e8c18df1ff           call 0x7a7d42
// 0088ef81  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0088ef85  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0088ef89  57                   push edi
// 0088ef8a  53                   push ebx
// 0088ef8b  8bce                 mov ecx, esi
// 0088ef8d  e84efaffff           call 0x88e9e0
// 0088ef92  83f8ff               cmp eax, -1
// 0088ef95  7437                 je 0x88efce
// 0088ef97  57                   push edi
// 0088ef98  53                   push ebx
// 0088ef99  8bce                 mov ecx, esi
// 0088ef9b  e860feffff           call 0x88ee00
// 0088efa0  8b4620               mov eax, dword ptr [esi + 0x20]
// 0088efa3  c7466001000000       mov dword ptr [esi + 0x60], 1
// 0088efaa  8b354cba9e00         mov esi, dword ptr [0x9eba4c]
// 0088efb0  50                   push eax
// 0088efb1  ffd6                 call esi
// 0088efb3  50                   push eax
// 0088efb4  e8b18cf1ff           call 0x7a7c6a
// 0088efb9  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0088efbc  51                   push ecx
// 0088efbd  ffd6                 call esi
// 0088efbf  50                   push eax
// 0088efc0  e8a58cf1ff           call 0x7a7c6a
// 0088efc5  6a01                 push 1
// 0088efc7  8bc8                 mov ecx, eax
// 0088efc9  e810e70e00           call 0x97d6de
// 0088efce  5f                   pop edi
// 0088efcf  5e                   pop esi
// 0088efd0  5b                   pop ebx
// 0088efd1  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDblClk@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

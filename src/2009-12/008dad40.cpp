// from server: 100% by auto
// roc 2009-12 008dad40  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dad40
//
// 008dad40  53                   push ebx
// 008dad41  56                   push esi
// 008dad42  57                   push edi
// 008dad43  8bf1                 mov esi, ecx
// 008dad45  e8e690f1ff           call 0x7f3e30
// 008dad4a  ff15eccb9800         call dword ptr [0x98cbec]
// 008dad50  50                   push eax
// 008dad51  e8d48df1ff           call 0x7f3b2a
// 008dad56  3bc6                 cmp eax, esi
// 008dad58  7407                 je 0x8dad61
// 008dad5a  8bce                 mov ecx, esi
// 008dad5c  e8a18ef1ff           call 0x7f3c02
// 008dad61  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008dad65  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008dad69  57                   push edi
// 008dad6a  53                   push ebx
// 008dad6b  8bce                 mov ecx, esi
// 008dad6d  e8befaffff           call 0x8da830
// 008dad72  83f8ff               cmp eax, -1
// 008dad75  7437                 je 0x8dadae
// 008dad77  57                   push edi
// 008dad78  53                   push ebx
// 008dad79  8bce                 mov ecx, esi
// 008dad7b  e860feffff           call 0x8dabe0
// 008dad80  8b4620               mov eax, dword ptr [esi + 0x20]
// 008dad83  c7466001000000       mov dword ptr [esi + 0x60], 1
// 008dad8a  8b35bccb9800         mov esi, dword ptr [0x98cbbc]
// 008dad90  50                   push eax
// 008dad91  ffd6                 call esi
// 008dad93  50                   push eax
// 008dad94  e8918df1ff           call 0x7f3b2a
// 008dad99  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008dad9c  51                   push ecx
// 008dad9d  ffd6                 call esi
// 008dad9f  50                   push eax
// 008dada0  e8858df1ff           call 0x7f3b2a
// 008dada5  6a01                 push 1
// 008dada7  8bc8                 mov ecx, eax
// 008dada9  e8eebf0400           call 0x926d9c
// 008dadae  5f                   pop edi
// 008dadaf  5e                   pop esi
// 008dadb0  5b                   pop ebx
// 008dadb1  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDblClk@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp

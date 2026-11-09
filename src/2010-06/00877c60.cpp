// from server: 100% by auto
// roc 2010-06 00877c60  unit: CXTPImageEditorDlg  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00877c60
//
// 00877c60  56                   push esi
// 00877c61  8bf1                 mov esi, ecx
// 00877c63  83be680a000000       cmp dword ptr [esi + 0xa68], 0
// 00877c6a  7423                 je 0x877c8f
// 00877c6c  68e0a57a00           push 0x7aa5e0
// 00877c71  b90062c200           mov ecx, 0xc26200
// 00877c76  e8fd501000           call 0x97cd78
// 00877c7b  85c0                 test eax, eax
// 00877c7d  7505                 jne 0x877c84
// 00877c7f  e8c8fff2ff           call 0x7a7c4c
// 00877c84  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00877c87  51                   push ecx
// 00877c88  8bc8                 mov ecx, eax
// 00877c8a  e8c1b4faff           call 0x823150
// 00877c8f  8bce                 mov ecx, esi
// 00877c91  5e                   pop esi
// 00877c92  e9c507f3ff           jmp 0x7a845c
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnDestroy@CXTPImageEditorDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp

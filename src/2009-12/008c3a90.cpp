// from server: 100% by auto
// roc 2009-12 008c3a90  unit: CXTPImageEditorDlg  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c3a90
//
// 008c3a90  56                   push esi
// 008c3a91  8bf1                 mov esi, ecx
// 008c3a93  83be680a000000       cmp dword ptr [esi + 0xa68], 0
// 008c3a9a  7423                 je 0x8c3abf
// 008c3a9c  68b0647f00           push 0x7f64b0
// 008c3aa1  b9d0bab900           mov ecx, 0xb9bad0
// 008c3aa6  e891290600           call 0x92643c
// 008c3aab  85c0                 test eax, eax
// 008c3aad  7505                 jne 0x8c3ab4
// 008c3aaf  e85800f3ff           call 0x7f3b0c
// 008c3ab4  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008c3ab7  51                   push ecx
// 008c3ab8  8bc8                 mov ecx, eax
// 008c3aba  e881b6faff           call 0x86f140
// 008c3abf  8bce                 mov ecx, esi
// 008c3ac1  5e                   pop esi
// 008c3ac2  e95508f3ff           jmp 0x7f431c
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnDestroy@CXTPImageEditorDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp

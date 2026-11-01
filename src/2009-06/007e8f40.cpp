// from server: 100% by auto
// roc 2009-06 007e8f40  unit: CXTPImageEditorDlg  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e8f40
//
// 007e8f40  56                   push esi
// 007e8f41  8bf1                 mov esi, ecx
// 007e8f43  83be680a000000       cmp dword ptr [esi + 0xa68], 0
// 007e8f4a  7423                 je 0x7e8f6f
// 007e8f4c  68f0b87100           push 0x71b8f0
// 007e8f51  b99426a500           mov ecx, 0xa52694
// 007e8f56  e8a52f0600           call 0x84bf00
// 007e8f5b  85c0                 test eax, eax
// 007e8f5d  7505                 jne 0x7e8f64
// 007e8f5f  e880fdf2ff           call 0x718ce4
// 007e8f64  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007e8f67  51                   push ecx
// 007e8f68  8bc8                 mov ecx, eax
// 007e8f6a  e871b0faff           call 0x793fe0
// 007e8f6f  8bce                 mov ecx, esi
// 007e8f71  5e                   pop esi
// 007e8f72  e97705f3ff           jmp 0x7194ee
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnDestroy@CXTPImageEditorDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp

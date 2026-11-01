// from server: 100% by auto
// roc 2009-12 00867c70  unit: CXTPPropertyGridView  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867c70
//
// 00867c70  83ec10               sub esp, 0x10
// 00867c73  53                   push ebx
// 00867c74  56                   push esi
// 00867c75  57                   push edi
// 00867c76  8bf1                 mov esi, ecx
// 00867c78  e8a1bef8ff           call 0x7f3b1e
// 00867c7d  68007f0000           push 0x7f00
// 00867c82  6a00                 push 0
// 00867c84  ff1548ca9800         call dword ptr [0x98ca48]
// 00867c8a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00867c8e  6a00                 push 0
// 00867c90  6a00                 push 0
// 00867c92  53                   push ebx
// 00867c93  8d4c2418             lea ecx, [esp + 0x18]
// 00867c97  8bf8                 mov edi, eax
// 00867c99  e89235feff           call 0x84b230
// 00867c9e  50                   push eax
// 00867c9f  6800000080           push 0x80000000
// 00867ca4  6856fd9900           push 0x99fd56
// 00867ca9  6a00                 push 0
// 00867cab  6a00                 push 0
// 00867cad  57                   push edi
// 00867cae  6a00                 push 0
// 00867cb0  e871c5f8ff           call 0x7f4226
// 00867cb5  50                   push eax
// 00867cb6  6a00                 push 0
// 00867cb8  8bce                 mov ecx, esi
// 00867cba  e813bcf8ff           call 0x7f38d2
// 00867cbf  5f                   pop edi
// 00867cc0  895e54               mov dword ptr [esi + 0x54], ebx
// 00867cc3  5e                   pop esi
// 00867cc4  5b                   pop ebx
// 00867cc5  83c410               add esp, 0x10
// 00867cc8  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?Create@CXTPPropertyGridToolTip@@QAEXPAVCXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp

// from server: 100% by auto
// roc 2010-06 0081bc80  unit: CXTPPropertyGridView  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081bc80
//
// 0081bc80  83ec10               sub esp, 0x10
// 0081bc83  53                   push ebx
// 0081bc84  56                   push esi
// 0081bc85  57                   push edi
// 0081bc86  8bf1                 mov esi, ecx
// 0081bc88  e8d1bff8ff           call 0x7a7c5e
// 0081bc8d  68007f0000           push 0x7f00
// 0081bc92  6a00                 push 0
// 0081bc94  ff15ccbb9e00         call dword ptr [0x9ebbcc]
// 0081bc9a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0081bc9e  6a00                 push 0
// 0081bca0  6a00                 push 0
// 0081bca2  53                   push ebx
// 0081bca3  8d4c2418             lea ecx, [esp + 0x18]
// 0081bca7  8bf8                 mov edi, eax
// 0081bca9  e8c235feff           call 0x7ff270
// 0081bcae  50                   push eax
// 0081bcaf  6800000080           push 0x80000000
// 0081bcb4  68fe08a000           push 0xa008fe
// 0081bcb9  6a00                 push 0
// 0081bcbb  6a00                 push 0
// 0081bcbd  57                   push edi
// 0081bcbe  6a00                 push 0
// 0081bcc0  e8a1c6f8ff           call 0x7a8366
// 0081bcc5  50                   push eax
// 0081bcc6  6a00                 push 0
// 0081bcc8  8bce                 mov ecx, esi
// 0081bcca  e843bdf8ff           call 0x7a7a12
// 0081bccf  5f                   pop edi
// 0081bcd0  895e54               mov dword ptr [esi + 0x54], ebx
// 0081bcd3  5e                   pop esi
// 0081bcd4  5b                   pop ebx
// 0081bcd5  83c410               add esp, 0x10
// 0081bcd8  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?Create@CXTPPropertyGridToolTip@@QAEXPAVCXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp

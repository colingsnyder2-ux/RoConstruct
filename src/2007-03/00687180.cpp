// from server: 100% by auto
// roc 2007-03 00687180  unit: seg_00680000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00687180
//
// 00687180  83ec10               sub esp, 0x10
// 00687183  53                   push ebx
// 00687184  56                   push esi
// 00687185  57                   push edi
// 00687186  8bf1                 mov esi, ecx
// 00687188  e80372f9ff           call 0x61e390
// 0068718d  68007f0000           push 0x7f00
// 00687192  6a00                 push 0
// 00687194  ff15f0ec7700         call dword ptr [0x77ecf0]
// 0068719a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0068719e  6a00                 push 0
// 006871a0  6a00                 push 0
// 006871a2  53                   push ebx
// 006871a3  8d4c2418             lea ecx, [esp + 0x18]
// 006871a7  8bf8                 mov edi, eax
// 006871a9  e8e245feff           call 0x66b790
// 006871ae  50                   push eax
// 006871af  6800000080           push 0x80000000
// 006871b4  68ac497800           push 0x7849ac
// 006871b9  6a00                 push 0
// 006871bb  6a00                 push 0
// 006871bd  57                   push edi
// 006871be  6a00                 push 0
// 006871c0  e8bf77f9ff           call 0x61e984
// 006871c5  50                   push eax
// 006871c6  6a00                 push 0
// 006871c8  8bce                 mov ecx, esi
// 006871ca  e8a56ff9ff           call 0x61e174
// 006871cf  5f                   pop edi
// 006871d0  895e54               mov dword ptr [esi + 0x54], ebx
// 006871d3  5e                   pop esi
// 006871d4  5b                   pop ebx
// 006871d5  83c410               add esp, 0x10
// 006871d8  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?Create@CXTPPropertyGridToolTip@@QAEXPAVCXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp

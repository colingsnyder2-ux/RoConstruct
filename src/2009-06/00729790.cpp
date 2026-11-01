// from server: 100% by auto
// roc 2009-06 00729790  unit: MyXTPCommandBars  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729790
//
// 00729790  56                   push esi
// 00729791  51                   push ecx
// 00729792  e819d40300           call 0x766bb0
// 00729797  6a00                 push 0
// 00729799  6a01                 push 1
// 0072979b  6800e80000           push 0xe800
// 007297a0  8bf0                 mov esi, eax
// 007297a2  6a00                 push 0
// 007297a4  56                   push esi
// 007297a5  e866480400           call 0x76e010
// 007297aa  83c418               add esp, 0x18
// 007297ad  8bc6                 mov eax, esi
// 007297af  5e                   pop esi
// 007297b0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetToolbarsPopup@CXTPCommandBars@@UAEPAVCXTPPopupBar@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp

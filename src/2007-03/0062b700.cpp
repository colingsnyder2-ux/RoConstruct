// from server: 100% by auto
// roc 2007-03 0062b700  unit: seg_00620000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b700
//
// 0062b700  56                   push esi
// 0062b701  51                   push ecx
// 0062b702  e8c97a0300           call 0x6631d0
// 0062b707  6a00                 push 0
// 0062b709  6a01                 push 1
// 0062b70b  6800e80000           push 0xe800
// 0062b710  8bf0                 mov esi, eax
// 0062b712  6a00                 push 0
// 0062b714  56                   push esi
// 0062b715  e896b50400           call 0x676cb0
// 0062b71a  83c418               add esp, 0x18
// 0062b71d  8bc6                 mov eax, esi
// 0062b71f  5e                   pop esi
// 0062b720  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetToolbarsPopup@CXTPCommandBars@@UAEPAVCXTPPopupBar@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp

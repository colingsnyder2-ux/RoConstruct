// from server: 100% by auto
// roc 2007-03 00666730  unit: seg_00660000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00666730
//
// 00666730  68c8ab7c00           push 0x7cabc8
// 00666735  8d442408             lea eax, [esp + 8]
// 00666739  68c0ab7c00           push 0x7cabc0
// 0066673e  50                   push eax
// 0066673f  e87cfeffff           call 0x6665c0
// 00666744  68bcab7c00           push 0x7cabbc
// 00666749  8d4c2414             lea ecx, [esp + 0x14]
// 0066674d  68b4ab7c00           push 0x7cabb4
// 00666752  51                   push ecx
// 00666753  e868feffff           call 0x6665c0
// 00666758  68b0ab7c00           push 0x7cabb0
// 0066675d  8d542420             lea edx, [esp + 0x20]
// 00666761  68a8ab7c00           push 0x7caba8
// 00666766  52                   push edx
// 00666767  e854feffff           call 0x6665c0
// 0066676c  68a4ab7c00           push 0x7caba4
// 00666771  8d44242c             lea eax, [esp + 0x2c]
// 00666775  689cab7c00           push 0x7cab9c
// 0066677a  50                   push eax
// 0066677b  e840feffff           call 0x6665c0
// 00666780  6898ab7c00           push 0x7cab98
// 00666785  8d4c2438             lea ecx, [esp + 0x38]
// 00666789  68c8ab7c00           push 0x7cabc8
// 0066678e  51                   push ecx
// 0066678f  e82cfeffff           call 0x6665c0
// 00666794  83c43c               add esp, 0x3c
// 00666797  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@IAEXPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp

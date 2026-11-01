// from server: 100% by auto
// roc 2007-03 00667ac0  unit: seg_00660000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00667ac0
//
// 00667ac0  6a00                 push 0
// 00667ac2  8d442408             lea eax, [esp + 8]
// 00667ac6  50                   push eax
// 00667ac7  68fc807c00           push 0x7c80fc
// 00667acc  51                   push ecx
// 00667acd  e86ef2ffff           call 0x666d40
// 00667ad2  83c410               add esp, 0x10
// 00667ad5  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?WriteCount@CXTPPropExchange@@UAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp

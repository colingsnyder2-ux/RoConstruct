// from server: 100% by auto
// roc 2009-06 00776a90  unit: CXTPPropExchange  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776a90
//
// 00776a90  6a00                 push 0
// 00776a92  8d442408             lea eax, [esp + 8]
// 00776a96  50                   push eax
// 00776a97  68e4788f00           push 0x8f78e4
// 00776a9c  51                   push ecx
// 00776a9d  e8fef1ffff           call 0x775ca0
// 00776aa2  83c410               add esp, 0x10
// 00776aa5  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?WriteCount@CXTPPropExchange@@UAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp

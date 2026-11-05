// from server: 100% by auto
// roc 2010-06 00805860  unit: CXTPPropExchange  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805860
//
// 00805860  6a00                 push 0
// 00805862  8d442408             lea eax, [esp + 8]
// 00805866  50                   push eax
// 00805867  685014a100           push 0xa11450
// 0080586c  51                   push ecx
// 0080586d  e8cef1ffff           call 0x804a40
// 00805872  83c410               add esp, 0x10
// 00805875  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?WriteCount@CXTPPropExchange@@UAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp

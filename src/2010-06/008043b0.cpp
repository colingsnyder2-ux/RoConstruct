// from server: 100% by auto
// roc 2010-06 008043b0  unit: CXTPPropExchange  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008043b0
//
// 008043b0  68dc06a600           push 0xa606dc
// 008043b5  8d442408             lea eax, [esp + 8]
// 008043b9  68d406a600           push 0xa606d4
// 008043be  50                   push eax
// 008043bf  e87cfeffff           call 0x804240
// 008043c4  683459a500           push 0xa55934
// 008043c9  8d4c2414             lea ecx, [esp + 0x14]
// 008043cd  68cc06a600           push 0xa606cc
// 008043d2  51                   push ecx
// 008043d3  e868feffff           call 0x804240
// 008043d8  68c806a600           push 0xa606c8
// 008043dd  8d542420             lea edx, [esp + 0x20]
// 008043e1  68c006a600           push 0xa606c0
// 008043e6  52                   push edx
// 008043e7  e854feffff           call 0x804240
// 008043ec  68bc06a600           push 0xa606bc
// 008043f1  8d44242c             lea eax, [esp + 0x2c]
// 008043f5  68b406a600           push 0xa606b4
// 008043fa  50                   push eax
// 008043fb  e840feffff           call 0x804240
// 00804400  68b006a600           push 0xa606b0
// 00804405  8d4c2438             lea ecx, [esp + 0x38]
// 00804409  68dc06a600           push 0xa606dc
// 0080440e  51                   push ecx
// 0080440f  e82cfeffff           call 0x804240
// 00804414  83c43c               add esp, 0x3c
// 00804417  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@IAEXPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp

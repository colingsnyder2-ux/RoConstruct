// from server: 100% by auto
// roc 2009-12 00850350  unit: CXTPPropExchange  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850350
//
// 00850350  681cc49f00           push 0x9fc41c
// 00850355  8d442408             lea eax, [esp + 8]
// 00850359  6814c49f00           push 0x9fc414
// 0085035e  50                   push eax
// 0085035f  e87cfeffff           call 0x8501e0
// 00850364  682c169f00           push 0x9f162c
// 00850369  8d4c2414             lea ecx, [esp + 0x14]
// 0085036d  680cc49f00           push 0x9fc40c
// 00850372  51                   push ecx
// 00850373  e868feffff           call 0x8501e0
// 00850378  6808c49f00           push 0x9fc408
// 0085037d  8d542420             lea edx, [esp + 0x20]
// 00850381  6800c49f00           push 0x9fc400
// 00850386  52                   push edx
// 00850387  e854feffff           call 0x8501e0
// 0085038c  68fcc39f00           push 0x9fc3fc
// 00850391  8d44242c             lea eax, [esp + 0x2c]
// 00850395  68f4c39f00           push 0x9fc3f4
// 0085039a  50                   push eax
// 0085039b  e840feffff           call 0x8501e0
// 008503a0  68f0c39f00           push 0x9fc3f0
// 008503a5  8d4c2438             lea ecx, [esp + 0x38]
// 008503a9  681cc49f00           push 0x9fc41c
// 008503ae  51                   push ecx
// 008503af  e82cfeffff           call 0x8501e0
// 008503b4  83c43c               add esp, 0x3c
// 008503b7  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@IAEXPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp

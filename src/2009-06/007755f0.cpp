// from server: 100% by auto
// roc 2009-06 007755f0  unit: CXTPPropExchange  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007755f0
//
// 007755f0  6874bf8f00           push 0x8fbf74
// 007755f5  8d442408             lea eax, [esp + 8]
// 007755f9  686cbf8f00           push 0x8fbf6c
// 007755fe  50                   push eax
// 007755ff  e87cfeffff           call 0x775480
// 00775604  686c118f00           push 0x8f116c
// 00775609  8d4c2414             lea ecx, [esp + 0x14]
// 0077560d  6864bf8f00           push 0x8fbf64
// 00775612  51                   push ecx
// 00775613  e868feffff           call 0x775480
// 00775618  6860bf8f00           push 0x8fbf60
// 0077561d  8d542420             lea edx, [esp + 0x20]
// 00775621  6858bf8f00           push 0x8fbf58
// 00775626  52                   push edx
// 00775627  e854feffff           call 0x775480
// 0077562c  6854bf8f00           push 0x8fbf54
// 00775631  8d44242c             lea eax, [esp + 0x2c]
// 00775635  684cbf8f00           push 0x8fbf4c
// 0077563a  50                   push eax
// 0077563b  e840feffff           call 0x775480
// 00775640  6848bf8f00           push 0x8fbf48
// 00775645  8d4c2438             lea ecx, [esp + 0x38]
// 00775649  6874bf8f00           push 0x8fbf74
// 0077564e  51                   push ecx
// 0077564f  e82cfeffff           call 0x775480
// 00775654  83c43c               add esp, 0x3c
// 00775657  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@IAEXPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp

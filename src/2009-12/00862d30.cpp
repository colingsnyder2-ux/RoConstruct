// from server: 100% by auto
// roc 2009-12 00862d30  unit: CXTPToolTipContext  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00862d30
//
// 00862d30  837c240400           cmp dword ptr [esp + 4], 0
// 00862d35  56                   push esi
// 00862d36  8bf1                 mov esi, ecx
// 00862d38  7437                 je 0x862d71
// 00862d3a  833d78b6b90000       cmp dword ptr [0xb9b678], 0
// 00862d41  755a                 jne 0x862d9d
// 00862d43  833d7cb6b90000       cmp dword ptr [0xb9b67c], 0
// 00862d4a  7551                 jne 0x862d9d
// 00862d4c  ff1524b29800         call dword ptr [0x98b224]
// 00862d52  50                   push eax
// 00862d53  6a00                 push 0
// 00862d55  68802c8600           push 0x862c80
// 00862d5a  6a07                 push 7
// 00862d5c  ff15d0ca9800         call dword ptr [0x98cad0]
// 00862d62  89357cb6b900         mov dword ptr [0xb9b67c], esi
// 00862d68  a378b6b900           mov dword ptr [0xb9b678], eax
// 00862d6d  5e                   pop esi
// 00862d6e  c20400               ret 4
// 00862d71  a178b6b900           mov eax, dword ptr [0xb9b678]
// 00862d76  85c0                 test eax, eax
// 00862d78  7423                 je 0x862d9d
// 00862d7a  39357cb6b900         cmp dword ptr [0xb9b67c], esi
// 00862d80  751b                 jne 0x862d9d
// 00862d82  50                   push eax
// 00862d83  ff15ccca9800         call dword ptr [0x98cacc]
// 00862d89  c70578b6b90000000000 mov dword ptr [0xb9b678], 0
// 00862d93  c7057cb6b90000000000 mov dword ptr [0xb9b67c], 0
// 00862d9d  5e                   pop esi
// 00862d9e  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?HookMouseMove@CXTPToolTipContextToolTip@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp

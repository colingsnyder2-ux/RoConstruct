// from server: 100% by auto
// roc 2007-08 00650900  unit: CXTPToolBar  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00650900
//
// 00650900  83ec10               sub esp, 0x10
// 00650903  56                   push esi
// 00650904  8bf1                 mov esi, ecx
// 00650906  85f6                 test esi, esi
// 00650908  7441                 je 0x65094b
// 0065090a  837e2000             cmp dword ptr [esi + 0x20], 0
// 0065090e  743b                 je 0x65094b
// 00650910  8b06                 mov eax, dword ptr [esi]
// 00650912  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 00650918  ffd2                 call edx
// 0065091a  85c0                 test eax, eax
// 0065091c  742d                 je 0x65094b
// 0065091e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00650921  50                   push eax
// 00650922  ff15a0ed7700         call dword ptr [0x77eda0]
// 00650928  85c0                 test eax, eax
// 0065092a  741f                 je 0x65094b
// 0065092c  56                   push esi
// 0065092d  8d4c2408             lea ecx, [esp + 8]
// 00650931  e86af60200           call 0x67ffa0
// 00650936  50                   push eax
// 00650937  ff15dced7700         call dword ptr [0x77eddc]
// 0065093d  85c0                 test eax, eax
// 0065093f  750a                 jne 0x65094b
// 00650941  b801000000           mov eax, 1
// 00650946  5e                   pop esi
// 00650947  83c410               add esp, 0x10
// 0065094a  c3                   ret 
// 0065094b  33c0                 xor eax, eax
// 0065094d  5e                   pop esi
// 0065094e  83c410               add esp, 0x10
// 00650951  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?IsWindowVisible@CXTPToolBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp

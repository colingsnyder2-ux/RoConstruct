// from server: 100% by auto
// roc 2007-08 0070c9a0  unit: CSpinButtonCtrl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070c9a0
//
// 0070c9a0  56                   push esi
// 0070c9a1  8bf1                 mov esi, ecx
// 0070c9a3  e89638f2ff           call 0x63023e
// 0070c9a8  83f8ff               cmp eax, -1
// 0070c9ab  7506                 jne 0x70c9b3
// 0070c9ad  0bc0                 or eax, eax
// 0070c9af  5e                   pop esi
// 0070c9b0  c20400               ret 4
// 0070c9b3  8b06                 mov eax, dword ptr [esi]
// 0070c9b5  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 0070c9bb  8bce                 mov ecx, esi
// 0070c9bd  ffd2                 call edx
// 0070c9bf  33c0                 xor eax, eax
// 0070c9c1  5e                   pop esi
// 0070c9c2  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorComboBox.cpp (function ?OnCreate@CXTPSyntaxEditColorComboBox@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorComboBox.cpp

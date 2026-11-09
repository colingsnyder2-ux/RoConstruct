// from server: 100% by auto
// roc 2010-06 00891920  unit: CXTColorBase  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891920
//
// 00891920  56                   push esi
// 00891921  8bf1                 mov esi, ecx
// 00891923  e84866f1ff           call 0x7a7f70
// 00891928  83f8ff               cmp eax, -1
// 0089192b  7506                 jne 0x891933
// 0089192d  0bc0                 or eax, eax
// 0089192f  5e                   pop esi
// 00891930  c20400               ret 4
// 00891933  8b06                 mov eax, dword ptr [esi]
// 00891935  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 0089193b  8bce                 mov ecx, esi
// 0089193d  ffd2                 call edx
// 0089193f  33c0                 xor eax, eax
// 00891941  5e                   pop esi
// 00891942  c20400               ret 4
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditColorComboBox.cpp (function ?OnCreate@CXTPSyntaxEditColorComboBox@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditColorComboBox.cpp

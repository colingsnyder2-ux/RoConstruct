// from server: 100% by auto
// roc 2009-06 00802be0  unit: CXTColorBase  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00802be0
//
// 00802be0  56                   push esi
// 00802be1  8bf1                 mov esi, ecx
// 00802be3  e82064f1ff           call 0x719008
// 00802be8  83f8ff               cmp eax, -1
// 00802beb  7506                 jne 0x802bf3
// 00802bed  0bc0                 or eax, eax
// 00802bef  5e                   pop esi
// 00802bf0  c20400               ret 4
// 00802bf3  8b06                 mov eax, dword ptr [esi]
// 00802bf5  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 00802bfb  8bce                 mov ecx, esi
// 00802bfd  ffd2                 call edx
// 00802bff  33c0                 xor eax, eax
// 00802c01  5e                   pop esi
// 00802c02  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorComboBox.cpp (function ?OnCreate@CXTPSyntaxEditColorComboBox@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorComboBox.cpp

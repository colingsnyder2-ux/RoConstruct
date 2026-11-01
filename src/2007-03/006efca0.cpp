// from server: 100% by auto
// roc 2007-03 006efca0  unit: seg_006e0000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006efca0
//
// 006efca0  56                   push esi
// 006efca1  8bf1                 mov esi, ecx
// 006efca3  e82aeaf2ff           call 0x61e6d2
// 006efca8  83f8ff               cmp eax, -1
// 006efcab  7506                 jne 0x6efcb3
// 006efcad  0bc0                 or eax, eax
// 006efcaf  5e                   pop esi
// 006efcb0  c20400               ret 4
// 006efcb3  8b06                 mov eax, dword ptr [esi]
// 006efcb5  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 006efcbb  8bce                 mov ecx, esi
// 006efcbd  ffd2                 call edx
// 006efcbf  33c0                 xor eax, eax
// 006efcc1  5e                   pop esi
// 006efcc2  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorComboBox.cpp (function ?OnCreate@CXTPSyntaxEditColorComboBox@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorComboBox.cpp

// from server: 100% by auto
// roc 2009-12 008dd6d0  unit: CXTColorBase  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd6d0
//
// 008dd6d0  56                   push esi
// 008dd6d1  8bf1                 mov esi, ecx
// 008dd6d3  e85867f1ff           call 0x7f3e30
// 008dd6d8  83f8ff               cmp eax, -1
// 008dd6db  7506                 jne 0x8dd6e3
// 008dd6dd  0bc0                 or eax, eax
// 008dd6df  5e                   pop esi
// 008dd6e0  c20400               ret 4
// 008dd6e3  8b06                 mov eax, dword ptr [esi]
// 008dd6e5  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 008dd6eb  8bce                 mov ecx, esi
// 008dd6ed  ffd2                 call edx
// 008dd6ef  33c0                 xor eax, eax
// 008dd6f1  5e                   pop esi
// 008dd6f2  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorComboBox.cpp (function ?OnCreate@CXTPSyntaxEditColorComboBox@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorComboBox.cpp

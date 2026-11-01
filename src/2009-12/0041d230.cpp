// from server: 100% by auto
// roc 2009-12 0041d230  unit: CXTTreeCtrl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041d230
//
// 0041d230  56                   push esi
// 0041d231  8bf1                 mov esi, ecx
// 0041d233  e8f86b3d00           call 0x7f3e30
// 0041d238  83f8ff               cmp eax, -1
// 0041d23b  7506                 jne 0x41d243
// 0041d23d  0bc0                 or eax, eax
// 0041d23f  5e                   pop esi
// 0041d240  c20400               ret 4
// 0041d243  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041d246  8b5048               mov edx, dword ptr [eax + 0x48]
// 0041d249  8d4e54               lea ecx, [esi + 0x54]
// 0041d24c  ffd2                 call edx
// 0041d24e  33c0                 xor eax, eax
// 0041d250  5e                   pop esi
// 0041d251  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnCreate@CXTPShellTreeBaseCTreeCtrl@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp

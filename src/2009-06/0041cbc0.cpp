// from server: 100% by auto
// roc 2009-06 0041cbc0  unit: CXTTreeCtrl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cbc0
//
// 0041cbc0  56                   push esi
// 0041cbc1  8bf1                 mov esi, ecx
// 0041cbc3  e840c42f00           call 0x719008
// 0041cbc8  83f8ff               cmp eax, -1
// 0041cbcb  7506                 jne 0x41cbd3
// 0041cbcd  0bc0                 or eax, eax
// 0041cbcf  5e                   pop esi
// 0041cbd0  c20400               ret 4
// 0041cbd3  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041cbd6  8b5048               mov edx, dword ptr [eax + 0x48]
// 0041cbd9  8d4e54               lea ecx, [esi + 0x54]
// 0041cbdc  ffd2                 call edx
// 0041cbde  33c0                 xor eax, eax
// 0041cbe0  5e                   pop esi
// 0041cbe1  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnCreate@CXTPShellTreeBaseCTreeCtrl@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp

// from server: 100% by auto
// roc 2010-06 0041d110  unit: CXTTreeCtrl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041d110
//
// 0041d110  56                   push esi
// 0041d111  8bf1                 mov esi, ecx
// 0041d113  e858ae3800           call 0x7a7f70
// 0041d118  83f8ff               cmp eax, -1
// 0041d11b  7506                 jne 0x41d123
// 0041d11d  0bc0                 or eax, eax
// 0041d11f  5e                   pop esi
// 0041d120  c20400               ret 4
// 0041d123  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041d126  8b5048               mov edx, dword ptr [eax + 0x48]
// 0041d129  8d4e54               lea ecx, [esi + 0x54]
// 0041d12c  ffd2                 call edx
// 0041d12e  33c0                 xor eax, eax
// 0041d130  5e                   pop esi
// 0041d131  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnCreate@CXTShellTreeBaseCTreeCtrl@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp

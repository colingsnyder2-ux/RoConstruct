// from server: 100% by auto
// roc 2010-06 00810a20  unit: CXTPDockingPane  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810a20
//
// 00810a20  56                   push esi
// 00810a21  8bf1                 mov esi, ecx
// 00810a23  837e3000             cmp dword ptr [esi + 0x30], 0
// 00810a27  7445                 je 0x810a6e
// 00810a29  8b4620               mov eax, dword ptr [esi + 0x20]
// 00810a2c  8b501c               mov edx, dword ptr [eax + 0x1c]
// 00810a2f  8d4e20               lea ecx, [esi + 0x20]
// 00810a32  ffd2                 call edx
// 00810a34  85c0                 test eax, eax
// 00810a36  7536                 jne 0x810a6e
// 00810a38  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00810a3b  8b01                 mov eax, dword ptr [ecx]
// 00810a3d  8b5020               mov edx, dword ptr [eax + 0x20]
// 00810a40  ffd2                 call edx
// 00810a42  85c0                 test eax, eax
// 00810a44  7428                 je 0x810a6e
// 00810a46  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00810a49  8b01                 mov eax, dword ptr [ecx]
// 00810a4b  8b5018               mov edx, dword ptr [eax + 0x18]
// 00810a4e  ffd2                 call edx
// 00810a50  8bf0                 mov esi, eax
// 00810a52  85f6                 test esi, esi
// 00810a54  7418                 je 0x810a6e
// 00810a56  e8351b0500           call 0x862590
// 00810a5b  50                   push eax
// 00810a5c  8bce                 mov ecx, esi
// 00810a5e  e8c574f9ff           call 0x7a7f28
// 00810a63  85c0                 test eax, eax
// 00810a65  7407                 je 0x810a6e
// 00810a67  b801000000           mov eax, 1
// 00810a6c  5e                   pop esi
// 00810a6d  c3                   ret 
// 00810a6e  33c0                 xor eax, eax
// 00810a70  5e                   pop esi
// 00810a71  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPane.cpp (function ?IsFloating@CXTPDockingPane@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPane.cpp

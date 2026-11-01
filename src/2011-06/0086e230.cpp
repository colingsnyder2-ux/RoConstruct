// from server: 100% by auto
// roc 2011-06 0086e230  unit: CXTPDockingPane  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086e230
//
// 0086e230  56                   push esi
// 0086e231  8bf1                 mov esi, ecx
// 0086e233  837e3000             cmp dword ptr [esi + 0x30], 0
// 0086e237  7445                 je 0x86e27e
// 0086e239  8b4620               mov eax, dword ptr [esi + 0x20]
// 0086e23c  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0086e23f  8d4e20               lea ecx, [esi + 0x20]
// 0086e242  ffd2                 call edx
// 0086e244  85c0                 test eax, eax
// 0086e246  7536                 jne 0x86e27e
// 0086e248  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 0086e24b  8b01                 mov eax, dword ptr [ecx]
// 0086e24d  8b5020               mov edx, dword ptr [eax + 0x20]
// 0086e250  ffd2                 call edx
// 0086e252  85c0                 test eax, eax
// 0086e254  7428                 je 0x86e27e
// 0086e256  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 0086e259  8b01                 mov eax, dword ptr [ecx]
// 0086e25b  8b5018               mov edx, dword ptr [eax + 0x18]
// 0086e25e  ffd2                 call edx
// 0086e260  8bf0                 mov esi, eax
// 0086e262  85f6                 test esi, esi
// 0086e264  7418                 je 0x86e27e
// 0086e266  e875170500           call 0x8bf9e0
// 0086e26b  50                   push eax
// 0086e26c  8bce                 mov ecx, esi
// 0086e26e  e873c3f9ff           call 0x80a5e6
// 0086e273  85c0                 test eax, eax
// 0086e275  7407                 je 0x86e27e
// 0086e277  b801000000           mov eax, 1
// 0086e27c  5e                   pop esi
// 0086e27d  c3                   ret 
// 0086e27e  33c0                 xor eax, eax
// 0086e280  5e                   pop esi
// 0086e281  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPane.cpp (function ?IsFloating@CXTPDockingPane@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPane.cpp

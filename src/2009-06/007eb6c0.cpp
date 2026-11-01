// from server: 100% by auto
// roc 2009-06 007eb6c0  unit: CXTPPropertyGridInplaceButton  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007eb6c0
//
// 007eb6c0  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 007eb6c4  7503                 jne 0x7eb6c9
// 007eb6c6  33c0                 xor eax, eax
// 007eb6c8  c3                   ret 
// 007eb6c9  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 007eb6cc  83f8ff               cmp eax, -1
// 007eb6cf  74f5                 je 0x7eb6c6
// 007eb6d1  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 007eb6d4  6a00                 push 0
// 007eb6d6  50                   push eax
// 007eb6d7  e88412faff           call 0x78c960
// 007eb6dc  8bc8                 mov ecx, eax
// 007eb6de  e8add3f4ff           call 0x738a90
// 007eb6e3  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?GetImage@CXTPPropertyGridInplaceButton@@UBEPAVCXTPImageManagerIcon@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp

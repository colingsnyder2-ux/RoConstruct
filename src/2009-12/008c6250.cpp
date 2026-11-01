// from server: 100% by auto
// roc 2009-12 008c6250  unit: CXTPPropertyGridInplaceButton  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6250
//
// 008c6250  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 008c6254  7503                 jne 0x8c6259
// 008c6256  33c0                 xor eax, eax
// 008c6258  c3                   ret 
// 008c6259  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 008c625c  83f8ff               cmp eax, -1
// 008c625f  74f5                 je 0x8c6256
// 008c6261  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 008c6264  6a00                 push 0
// 008c6266  50                   push eax
// 008c6267  e8f416faff           call 0x867960
// 008c626c  8bc8                 mov ecx, eax
// 008c626e  e80d99f4ff           call 0x80fb80
// 008c6273  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?GetImage@CXTPPropertyGridInplaceButton@@UBEPAVCXTPImageManagerIcon@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp

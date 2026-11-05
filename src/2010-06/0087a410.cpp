// from server: 100% by auto
// roc 2010-06 0087a410  unit: CXTPPropertyGridInplaceButton  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087a410
//
// 0087a410  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 0087a414  7503                 jne 0x87a419
// 0087a416  33c0                 xor eax, eax
// 0087a418  c3                   ret 
// 0087a419  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 0087a41c  83f8ff               cmp eax, -1
// 0087a41f  74f5                 je 0x87a416
// 0087a421  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 0087a424  6a00                 push 0
// 0087a426  50                   push eax
// 0087a427  e8e414faff           call 0x81b910
// 0087a42c  8bc8                 mov ecx, eax
// 0087a42e  e8ed97f4ff           call 0x7c3c20
// 0087a433  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?GetImage@CXTPPropertyGridInplaceButton@@UBEPAVCXTPImageManagerIcon@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp

// from server: 100% by auto
// roc 2007-03 006d88d0  unit: seg_006d0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d88d0
//
// 006d88d0  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 006d88d4  7503                 jne 0x6d88d9
// 006d88d6  33c0                 xor eax, eax
// 006d88d8  c3                   ret 
// 006d88d9  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 006d88dc  83f8ff               cmp eax, -1
// 006d88df  74f5                 je 0x6d88d6
// 006d88e1  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 006d88e4  6a00                 push 0
// 006d88e6  50                   push eax
// 006d88e7  e894e5faff           call 0x686e80
// 006d88ec  8bc8                 mov ecx, eax
// 006d88ee  e87d20f5ff           call 0x62a970
// 006d88f3  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?GetImage@CXTPPropertyGridInplaceButton@@UBEPAVCXTPImageManagerIcon@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp

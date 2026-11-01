// from server: 100% by auto
// roc 2007-08 006fcf20  unit: CXTPPropertyGridInplaceList  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fcf20
//
// 006fcf20  56                   push esi
// 006fcf21  8bf1                 mov esi, ecx
// 006fcf23  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 006fcf26  85c9                 test ecx, ecx
// 006fcf28  7411                 je 0x6fcf3b
// 006fcf2a  8b01                 mov eax, dword ptr [ecx]
// 006fcf2c  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 006fcf32  ffd2                 call edx
// 006fcf34  c7465400000000       mov dword ptr [esi + 0x54], 0
// 006fcf3b  837e2000             cmp dword ptr [esi + 0x20], 0
// 006fcf3f  743b                 je 0x6fcf7c
// 006fcf41  57                   push edi
// 006fcf42  8b7e20               mov edi, dword ptr [esi + 0x20]
// 006fcf45  ff15d4ec7700         call dword ptr [0x77ecd4]
// 006fcf4b  3bc7                 cmp eax, edi
// 006fcf4d  752c                 jne 0x6fcf7b
// 006fcf4f  8b7638               mov esi, dword ptr [esi + 0x38]
// 006fcf52  85f6                 test esi, esi
// 006fcf54  740f                 je 0x6fcf65
// 006fcf56  56                   push esi
// 006fcf57  e86432f3ff           call 0x6301c0
// 006fcf5c  5f                   pop edi
// 006fcf5d  8bc8                 mov ecx, eax
// 006fcf5f  5e                   pop esi
// 006fcf60  e99f30f3ff           jmp 0x630004
// 006fcf65  57                   push edi
// 006fcf66  ff15f8eb7700         call dword ptr [0x77ebf8]
// 006fcf6c  50                   push eax
// 006fcf6d  e84e32f3ff           call 0x6301c0
// 006fcf72  5f                   pop edi
// 006fcf73  8bc8                 mov ecx, eax
// 006fcf75  5e                   pop esi
// 006fcf76  e98930f3ff           jmp 0x630004
// 006fcf7b  5f                   pop edi
// 006fcf7c  5e                   pop esi
// 006fcf7d  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?Cancel@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp

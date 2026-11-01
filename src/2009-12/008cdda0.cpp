// from server: 100% by auto
// roc 2009-12 008cdda0  unit: CXTPPropertyGridInplaceList  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cdda0
//
// 008cdda0  56                   push esi
// 008cdda1  8bf1                 mov esi, ecx
// 008cdda3  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 008cdda6  85c9                 test ecx, ecx
// 008cdda8  7411                 je 0x8cddbb
// 008cddaa  8b01                 mov eax, dword ptr [ecx]
// 008cddac  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 008cddb2  ffd2                 call edx
// 008cddb4  c7465400000000       mov dword ptr [esi + 0x54], 0
// 008cddbb  837e2000             cmp dword ptr [esi + 0x20], 0
// 008cddbf  743b                 je 0x8cddfc
// 008cddc1  57                   push edi
// 008cddc2  8b7e20               mov edi, dword ptr [esi + 0x20]
// 008cddc5  ff15eccb9800         call dword ptr [0x98cbec]
// 008cddcb  3bc7                 cmp eax, edi
// 008cddcd  752c                 jne 0x8cddfb
// 008cddcf  8b7638               mov esi, dword ptr [esi + 0x38]
// 008cddd2  85f6                 test esi, esi
// 008cddd4  740f                 je 0x8cdde5
// 008cddd6  56                   push esi
// 008cddd7  e84e5df2ff           call 0x7f3b2a
// 008cdddc  5f                   pop edi
// 008cdddd  8bc8                 mov ecx, eax
// 008cdddf  5e                   pop esi
// 008cdde0  e91d5ef2ff           jmp 0x7f3c02
// 008cdde5  57                   push edi
// 008cdde6  ff15bccb9800         call dword ptr [0x98cbbc]
// 008cddec  50                   push eax
// 008cdded  e8385df2ff           call 0x7f3b2a
// 008cddf2  5f                   pop edi
// 008cddf3  8bc8                 mov ecx, eax
// 008cddf5  5e                   pop esi
// 008cddf6  e9075ef2ff           jmp 0x7f3c02
// 008cddfb  5f                   pop edi
// 008cddfc  5e                   pop esi
// 008cddfd  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?Cancel@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp

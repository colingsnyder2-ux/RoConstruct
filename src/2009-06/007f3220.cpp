// from server: 100% by auto
// roc 2009-06 007f3220  unit: CXTPPropertyGridInplaceList  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3220
//
// 007f3220  56                   push esi
// 007f3221  8bf1                 mov esi, ecx
// 007f3223  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 007f3226  85c9                 test ecx, ecx
// 007f3228  7411                 je 0x7f323b
// 007f322a  8b01                 mov eax, dword ptr [ecx]
// 007f322c  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 007f3232  ffd2                 call edx
// 007f3234  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007f323b  837e2000             cmp dword ptr [esi + 0x20], 0
// 007f323f  743b                 je 0x7f327c
// 007f3241  57                   push edi
// 007f3242  8b7e20               mov edi, dword ptr [esi + 0x20]
// 007f3245  ff1578ee8900         call dword ptr [0x89ee78]
// 007f324b  3bc7                 cmp eax, edi
// 007f324d  752c                 jne 0x7f327b
// 007f324f  8b7638               mov esi, dword ptr [esi + 0x38]
// 007f3252  85f6                 test esi, esi
// 007f3254  740f                 je 0x7f3265
// 007f3256  56                   push esi
// 007f3257  e8a65af2ff           call 0x718d02
// 007f325c  5f                   pop edi
// 007f325d  8bc8                 mov ecx, eax
// 007f325f  5e                   pop esi
// 007f3260  e9755bf2ff           jmp 0x718dda
// 007f3265  57                   push edi
// 007f3266  ff1598ee8900         call dword ptr [0x89ee98]
// 007f326c  50                   push eax
// 007f326d  e8905af2ff           call 0x718d02
// 007f3272  5f                   pop edi
// 007f3273  8bc8                 mov ecx, eax
// 007f3275  5e                   pop esi
// 007f3276  e95f5bf2ff           jmp 0x718dda
// 007f327b  5f                   pop edi
// 007f327c  5e                   pop esi
// 007f327d  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?Cancel@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp

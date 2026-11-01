// from server: 100% by auto
// roc 2007-03 006dd290  unit: seg_006d0000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dd290
//
// 006dd290  56                   push esi
// 006dd291  8bf1                 mov esi, ecx
// 006dd293  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 006dd296  85c9                 test ecx, ecx
// 006dd298  7411                 je 0x6dd2ab
// 006dd29a  8b01                 mov eax, dword ptr [ecx]
// 006dd29c  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 006dd2a2  ffd2                 call edx
// 006dd2a4  c7465400000000       mov dword ptr [esi + 0x54], 0
// 006dd2ab  837e2000             cmp dword ptr [esi + 0x20], 0
// 006dd2af  743b                 je 0x6dd2ec
// 006dd2b1  57                   push edi
// 006dd2b2  8b7e20               mov edi, dword ptr [esi + 0x20]
// 006dd2b5  ff154cee7700         call dword ptr [0x77ee4c]
// 006dd2bb  3bc7                 cmp eax, edi
// 006dd2bd  752c                 jne 0x6dd2eb
// 006dd2bf  8b7638               mov esi, dword ptr [esi + 0x38]
// 006dd2c2  85f6                 test esi, esi
// 006dd2c4  740f                 je 0x6dd2d5
// 006dd2c6  56                   push esi
// 006dd2c7  e88213f4ff           call 0x61e64e
// 006dd2cc  5f                   pop edi
// 006dd2cd  8bc8                 mov ecx, eax
// 006dd2cf  5e                   pop esi
// 006dd2d0  e9bd11f4ff           jmp 0x61e492
// 006dd2d5  57                   push edi
// 006dd2d6  ff15c8ec7700         call dword ptr [0x77ecc8]
// 006dd2dc  50                   push eax
// 006dd2dd  e86c13f4ff           call 0x61e64e
// 006dd2e2  5f                   pop edi
// 006dd2e3  8bc8                 mov ecx, eax
// 006dd2e5  5e                   pop esi
// 006dd2e6  e9a711f4ff           jmp 0x61e492
// 006dd2eb  5f                   pop edi
// 006dd2ec  5e                   pop esi
// 006dd2ed  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?Cancel@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp

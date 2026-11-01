// from server: 100% by auto
// roc 2009-12 004b2410  unit: Ogre::TextureCompositor  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b2410
//
// 004b2410  83ec08               sub esp, 8
// 004b2413  53                   push ebx
// 004b2414  55                   push ebp
// 004b2415  56                   push esi
// 004b2416  8bf1                 mov esi, ecx
// 004b2418  8b4610               mov eax, dword ptr [esi + 0x10]
// 004b241b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004b241e  8bc8                 mov ecx, eax
// 004b2420  2bcb                 sub ecx, ebx
// 004b2422  57                   push edi
// 004b2423  f7c1c0ffffff         test ecx, 0xffffffc0
// 004b2429  7504                 jne 0x4b242f
// 004b242b  33ff                 xor edi, edi
// 004b242d  eb27                 jmp 0x4b2456
// 004b242f  3bd8                 cmp ebx, eax
// 004b2431  7606                 jbe 0x4b2439
// 004b2433  ff1560b79800         call dword ptr [0x98b760]
// 004b2439  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004b243d  8b06                 mov eax, dword ptr [esi]
// 004b243f  85c9                 test ecx, ecx
// 004b2441  7404                 je 0x4b2447
// 004b2443  3bc8                 cmp ecx, eax
// 004b2445  7406                 je 0x4b244d
// 004b2447  ff1560b79800         call dword ptr [0x98b760]
// 004b244d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004b2451  2bfb                 sub edi, ebx
// 004b2453  c1ff06               sar edi, 6
// 004b2456  8b542428             mov edx, dword ptr [esp + 0x28]
// 004b245a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004b245e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004b2462  52                   push edx
// 004b2463  6a01                 push 1
// 004b2465  50                   push eax
// 004b2466  51                   push ecx
// 004b2467  8bce                 mov ecx, esi
// 004b2469  e802fcffff           call 0x4b2070
// 004b246e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004b2471  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004b2474  7606                 jbe 0x4b247c
// 004b2476  ff1560b79800         call dword ptr [0x98b760]
// 004b247c  8b36                 mov esi, dword ptr [esi]
// 004b247e  8bee                 mov ebp, esi
// 004b2480  895c2414             mov dword ptr [esp + 0x14], ebx
// 004b2484  85f6                 test esi, esi
// 004b2486  751a                 jne 0x4b24a2
// 004b2488  ff1560b79800         call dword ptr [0x98b760]
// 004b248e  33c0                 xor eax, eax
// 004b2490  c1e706               shl edi, 6
// 004b2493  03fb                 add edi, ebx
// 004b2495  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004b2498  7713                 ja 0x4b24ad
// 004b249a  85f6                 test esi, esi
// 004b249c  7408                 je 0x4b24a6
// 004b249e  8b36                 mov esi, dword ptr [esi]
// 004b24a0  eb06                 jmp 0x4b24a8
// 004b24a2  8b06                 mov eax, dword ptr [esi]
// 004b24a4  ebea                 jmp 0x4b2490
// 004b24a6  33f6                 xor esi, esi
// 004b24a8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004b24ab  7306                 jae 0x4b24b3
// 004b24ad  ff1560b79800         call dword ptr [0x98b760]
// 004b24b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b24b7  897804               mov dword ptr [eax + 4], edi
// 004b24ba  5f                   pop edi
// 004b24bb  5e                   pop esi
// 004b24bc  8928                 mov dword ptr [eax], ebp
// 004b24be  5d                   pop ebp
// 004b24bf  5b                   pop ebx
// 004b24c0  83c408               add esp, 8
// 004b24c3  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;

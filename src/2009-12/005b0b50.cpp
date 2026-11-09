// from server: 100% by auto
// roc 2009-12 005b0b50  unit: seg_005b0000  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0b50
//
// 005b0b50  83ec08               sub esp, 8
// 005b0b53  53                   push ebx
// 005b0b54  55                   push ebp
// 005b0b55  56                   push esi
// 005b0b56  8bf1                 mov esi, ecx
// 005b0b58  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b0b5b  57                   push edi
// 005b0b5c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005b0b5f  8bc8                 mov ecx, eax
// 005b0b61  2bcf                 sub ecx, edi
// 005b0b63  f7c1feffffff         test ecx, 0xfffffffe
// 005b0b69  7504                 jne 0x5b0b6f
// 005b0b6b  33db                 xor ebx, ebx
// 005b0b6d  eb26                 jmp 0x5b0b95
// 005b0b6f  3bf8                 cmp edi, eax
// 005b0b71  7606                 jbe 0x5b0b79
// 005b0b73  ff1560b79800         call dword ptr [0x98b760]
// 005b0b79  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005b0b7d  8b06                 mov eax, dword ptr [esi]
// 005b0b7f  85c9                 test ecx, ecx
// 005b0b81  7404                 je 0x5b0b87
// 005b0b83  3bc8                 cmp ecx, eax
// 005b0b85  7406                 je 0x5b0b8d
// 005b0b87  ff1560b79800         call dword ptr [0x98b760]
// 005b0b8d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b0b91  2bdf                 sub ebx, edi
// 005b0b93  d1fb                 sar ebx, 1
// 005b0b95  8b542428             mov edx, dword ptr [esp + 0x28]
// 005b0b99  8b442424             mov eax, dword ptr [esp + 0x24]
// 005b0b9d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005b0ba1  52                   push edx
// 005b0ba2  6a01                 push 1
// 005b0ba4  50                   push eax
// 005b0ba5  51                   push ecx
// 005b0ba6  8bce                 mov ecx, esi
// 005b0ba8  e8a3fcffff           call 0x5b0850
// 005b0bad  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005b0bb0  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005b0bb3  7606                 jbe 0x5b0bbb
// 005b0bb5  ff1560b79800         call dword ptr [0x98b760]
// 005b0bbb  8b36                 mov esi, dword ptr [esi]
// 005b0bbd  8bee                 mov ebp, esi
// 005b0bbf  897c2414             mov dword ptr [esp + 0x14], edi
// 005b0bc3  85f6                 test esi, esi
// 005b0bc5  7518                 jne 0x5b0bdf
// 005b0bc7  ff1560b79800         call dword ptr [0x98b760]
// 005b0bcd  33c0                 xor eax, eax
// 005b0bcf  8d3c5f               lea edi, [edi + ebx*2]
// 005b0bd2  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005b0bd5  7713                 ja 0x5b0bea
// 005b0bd7  85f6                 test esi, esi
// 005b0bd9  7408                 je 0x5b0be3
// 005b0bdb  8b36                 mov esi, dword ptr [esi]
// 005b0bdd  eb06                 jmp 0x5b0be5
// 005b0bdf  8b06                 mov eax, dword ptr [esi]
// 005b0be1  ebec                 jmp 0x5b0bcf
// 005b0be3  33f6                 xor esi, esi
// 005b0be5  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005b0be8  7306                 jae 0x5b0bf0
// 005b0bea  ff1560b79800         call dword ptr [0x98b760]
// 005b0bf0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b0bf4  897804               mov dword ptr [eax + 4], edi
// 005b0bf7  5f                   pop edi
// 005b0bf8  5e                   pop esi
// 005b0bf9  8928                 mov dword ptr [eax], ebp
// 005b0bfb  5d                   pop ebp
// 005b0bfc  5b                   pop ebx
// 005b0bfd  83c408               add esp, 8
// 005b0c00  c21000               ret 0x10
// standard library vector<short> (function ?insert@?$vector@FV?$allocator@F@std@@@std@@QAE?AV?$_Vector_iterator@FV?$allocator@F@std@@@2@V?$_Vector_const_iterator@FV?$allocator@F@std@@@2@ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

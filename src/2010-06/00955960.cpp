// from server: 100% by auto
// roc 2010-06 00955960  unit: seg_00950000  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955960
//
// 00955960  83ec08               sub esp, 8
// 00955963  53                   push ebx
// 00955964  55                   push ebp
// 00955965  56                   push esi
// 00955966  8bf1                 mov esi, ecx
// 00955968  8b4610               mov eax, dword ptr [esi + 0x10]
// 0095596b  57                   push edi
// 0095596c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0095596f  8bc8                 mov ecx, eax
// 00955971  2bcf                 sub ecx, edi
// 00955973  f7c1feffffff         test ecx, 0xfffffffe
// 00955979  7504                 jne 0x95597f
// 0095597b  33db                 xor ebx, ebx
// 0095597d  eb26                 jmp 0x9559a5
// 0095597f  3bf8                 cmp edi, eax
// 00955981  7606                 jbe 0x955989
// 00955983  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955989  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0095598d  8b06                 mov eax, dword ptr [esi]
// 0095598f  85c9                 test ecx, ecx
// 00955991  7404                 je 0x955997
// 00955993  3bc8                 cmp ecx, eax
// 00955995  7406                 je 0x95599d
// 00955997  ff150ca99e00         call dword ptr [0x9ea90c]
// 0095599d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 009559a1  2bdf                 sub ebx, edi
// 009559a3  d1fb                 sar ebx, 1
// 009559a5  8b542428             mov edx, dword ptr [esp + 0x28]
// 009559a9  8b442424             mov eax, dword ptr [esp + 0x24]
// 009559ad  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 009559b1  52                   push edx
// 009559b2  6a01                 push 1
// 009559b4  50                   push eax
// 009559b5  51                   push ecx
// 009559b6  8bce                 mov ecx, esi
// 009559b8  e8a33ac0ff           call 0x559460
// 009559bd  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 009559c0  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 009559c3  7606                 jbe 0x9559cb
// 009559c5  ff150ca99e00         call dword ptr [0x9ea90c]
// 009559cb  8b36                 mov esi, dword ptr [esi]
// 009559cd  8bee                 mov ebp, esi
// 009559cf  897c2414             mov dword ptr [esp + 0x14], edi
// 009559d3  85f6                 test esi, esi
// 009559d5  7518                 jne 0x9559ef
// 009559d7  ff150ca99e00         call dword ptr [0x9ea90c]
// 009559dd  33c0                 xor eax, eax
// 009559df  8d3c5f               lea edi, [edi + ebx*2]
// 009559e2  3b7810               cmp edi, dword ptr [eax + 0x10]
// 009559e5  7713                 ja 0x9559fa
// 009559e7  85f6                 test esi, esi
// 009559e9  7408                 je 0x9559f3
// 009559eb  8b36                 mov esi, dword ptr [esi]
// 009559ed  eb06                 jmp 0x9559f5
// 009559ef  8b06                 mov eax, dword ptr [esi]
// 009559f1  ebec                 jmp 0x9559df
// 009559f3  33f6                 xor esi, esi
// 009559f5  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 009559f8  7306                 jae 0x955a00
// 009559fa  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955a00  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00955a04  897804               mov dword ptr [eax + 4], edi
// 00955a07  5f                   pop edi
// 00955a08  5e                   pop esi
// 00955a09  8928                 mov dword ptr [eax], ebp
// 00955a0b  5d                   pop ebp
// 00955a0c  5b                   pop ebx
// 00955a0d  83c408               add esp, 8
// 00955a10  c21000               ret 0x10
// standard library vector<short> (function ?insert@?$vector@FV?$allocator@F@std@@@std@@QAE?AV?$_Vector_iterator@FV?$allocator@F@std@@@2@V?$_Vector_const_iterator@FV?$allocator@F@std@@@2@ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

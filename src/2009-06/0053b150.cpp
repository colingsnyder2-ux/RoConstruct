// from server: 100% by auto
// roc 2009-06 0053b150  unit: RBX::VerticalCylinderBuilder  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053b150
//
// 0053b150  83ec08               sub esp, 8
// 0053b153  56                   push esi
// 0053b154  8bf1                 mov esi, ecx
// 0053b156  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0053b159  57                   push edi
// 0053b15a  85c9                 test ecx, ecx
// 0053b15c  7504                 jne 0x53b162
// 0053b15e  33c0                 xor eax, eax
// 0053b160  eb07                 jmp 0x53b169
// 0053b162  8b4614               mov eax, dword ptr [esi + 0x14]
// 0053b165  2bc1                 sub eax, ecx
// 0053b167  d1f8                 sar eax, 1
// 0053b169  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0053b16c  8bd7                 mov edx, edi
// 0053b16e  2bd1                 sub edx, ecx
// 0053b170  d1fa                 sar edx, 1
// 0053b172  3bd0                 cmp edx, eax
// 0053b174  7318                 jae 0x53b18e
// 0053b176  8b442414             mov eax, dword ptr [esp + 0x14]
// 0053b17a  668b08               mov cx, word ptr [eax]
// 0053b17d  66890f               mov word ptr [edi], cx
// 0053b180  83c702               add edi, 2
// 0053b183  897e10               mov dword ptr [esi + 0x10], edi
// 0053b186  5f                   pop edi
// 0053b187  5e                   pop esi
// 0053b188  83c408               add esp, 8
// 0053b18b  c20400               ret 4
// 0053b18e  3bcf                 cmp ecx, edi
// 0053b190  7606                 jbe 0x53b198
// 0053b192  ff15ace98900         call dword ptr [0x89e9ac]
// 0053b198  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053b19c  8b06                 mov eax, dword ptr [esi]
// 0053b19e  52                   push edx
// 0053b19f  57                   push edi
// 0053b1a0  50                   push eax
// 0053b1a1  8d442414             lea eax, [esp + 0x14]
// 0053b1a5  50                   push eax
// 0053b1a6  8bce                 mov ecx, esi
// 0053b1a8  e8e3feffff           call 0x53b090
// 0053b1ad  5f                   pop edi
// 0053b1ae  5e                   pop esi
// 0053b1af  83c408               add esp, 8
// 0053b1b2  c20400               ret 4
// standard library vector<short> (function ?push_back@?$vector@FV?$allocator@F@std@@@std@@QAEXABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2009-12 005b0ec0  unit: seg_005b0000  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0ec0
//
// 005b0ec0  83ec08               sub esp, 8
// 005b0ec3  56                   push esi
// 005b0ec4  8bf1                 mov esi, ecx
// 005b0ec6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005b0ec9  57                   push edi
// 005b0eca  85c9                 test ecx, ecx
// 005b0ecc  7504                 jne 0x5b0ed2
// 005b0ece  33c0                 xor eax, eax
// 005b0ed0  eb07                 jmp 0x5b0ed9
// 005b0ed2  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b0ed5  2bc1                 sub eax, ecx
// 005b0ed7  d1f8                 sar eax, 1
// 005b0ed9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005b0edc  8bd7                 mov edx, edi
// 005b0ede  2bd1                 sub edx, ecx
// 005b0ee0  d1fa                 sar edx, 1
// 005b0ee2  3bd0                 cmp edx, eax
// 005b0ee4  7318                 jae 0x5b0efe
// 005b0ee6  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b0eea  668b08               mov cx, word ptr [eax]
// 005b0eed  66890f               mov word ptr [edi], cx
// 005b0ef0  83c702               add edi, 2
// 005b0ef3  897e10               mov dword ptr [esi + 0x10], edi
// 005b0ef6  5f                   pop edi
// 005b0ef7  5e                   pop esi
// 005b0ef8  83c408               add esp, 8
// 005b0efb  c20400               ret 4
// 005b0efe  3bcf                 cmp ecx, edi
// 005b0f00  7606                 jbe 0x5b0f08
// 005b0f02  ff1560b79800         call dword ptr [0x98b760]
// 005b0f08  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b0f0c  8b06                 mov eax, dword ptr [esi]
// 005b0f0e  52                   push edx
// 005b0f0f  57                   push edi
// 005b0f10  50                   push eax
// 005b0f11  8d442414             lea eax, [esp + 0x14]
// 005b0f15  50                   push eax
// 005b0f16  8bce                 mov ecx, esi
// 005b0f18  e833fcffff           call 0x5b0b50
// 005b0f1d  5f                   pop edi
// 005b0f1e  5e                   pop esi
// 005b0f1f  83c408               add esp, 8
// 005b0f22  c20400               ret 4
// standard library vector<short> (function ?push_back@?$vector@FV?$allocator@F@std@@@std@@QAEXABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2010-06 00955cd0  unit: seg_00950000  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955cd0
//
// 00955cd0  83ec08               sub esp, 8
// 00955cd3  56                   push esi
// 00955cd4  8bf1                 mov esi, ecx
// 00955cd6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00955cd9  57                   push edi
// 00955cda  85c9                 test ecx, ecx
// 00955cdc  7504                 jne 0x955ce2
// 00955cde  33c0                 xor eax, eax
// 00955ce0  eb07                 jmp 0x955ce9
// 00955ce2  8b4614               mov eax, dword ptr [esi + 0x14]
// 00955ce5  2bc1                 sub eax, ecx
// 00955ce7  d1f8                 sar eax, 1
// 00955ce9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00955cec  8bd7                 mov edx, edi
// 00955cee  2bd1                 sub edx, ecx
// 00955cf0  d1fa                 sar edx, 1
// 00955cf2  3bd0                 cmp edx, eax
// 00955cf4  7318                 jae 0x955d0e
// 00955cf6  8b442414             mov eax, dword ptr [esp + 0x14]
// 00955cfa  668b08               mov cx, word ptr [eax]
// 00955cfd  66890f               mov word ptr [edi], cx
// 00955d00  83c702               add edi, 2
// 00955d03  897e10               mov dword ptr [esi + 0x10], edi
// 00955d06  5f                   pop edi
// 00955d07  5e                   pop esi
// 00955d08  83c408               add esp, 8
// 00955d0b  c20400               ret 4
// 00955d0e  3bcf                 cmp ecx, edi
// 00955d10  7606                 jbe 0x955d18
// 00955d12  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955d18  8b542414             mov edx, dword ptr [esp + 0x14]
// 00955d1c  8b06                 mov eax, dword ptr [esi]
// 00955d1e  52                   push edx
// 00955d1f  57                   push edi
// 00955d20  50                   push eax
// 00955d21  8d442414             lea eax, [esp + 0x14]
// 00955d25  50                   push eax
// 00955d26  8bce                 mov ecx, esi
// 00955d28  e833fcffff           call 0x955960
// 00955d2d  5f                   pop edi
// 00955d2e  5e                   pop esi
// 00955d2f  83c408               add esp, 8
// 00955d32  c20400               ret 4
// standard library vector<short> (function ?push_back@?$vector@FV?$allocator@F@std@@@std@@QAEXABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

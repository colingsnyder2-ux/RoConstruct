// from server: 100% by auto
// roc 2009-12 007b7e50  unit: RBX::SleepStage  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b7e50
//
// 007b7e50  83ec08               sub esp, 8
// 007b7e53  56                   push esi
// 007b7e54  8bf1                 mov esi, ecx
// 007b7e56  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007b7e59  57                   push edi
// 007b7e5a  85c9                 test ecx, ecx
// 007b7e5c  7504                 jne 0x7b7e62
// 007b7e5e  33c0                 xor eax, eax
// 007b7e60  eb08                 jmp 0x7b7e6a
// 007b7e62  8b4614               mov eax, dword ptr [esi + 0x14]
// 007b7e65  2bc1                 sub eax, ecx
// 007b7e67  c1f802               sar eax, 2
// 007b7e6a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007b7e6d  8bd7                 mov edx, edi
// 007b7e6f  2bd1                 sub edx, ecx
// 007b7e71  c1fa02               sar edx, 2
// 007b7e74  3bd0                 cmp edx, eax
// 007b7e76  7316                 jae 0x7b7e8e
// 007b7e78  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b7e7c  8b08                 mov ecx, dword ptr [eax]
// 007b7e7e  890f                 mov dword ptr [edi], ecx
// 007b7e80  83c704               add edi, 4
// 007b7e83  897e10               mov dword ptr [esi + 0x10], edi
// 007b7e86  5f                   pop edi
// 007b7e87  5e                   pop esi
// 007b7e88  83c408               add esp, 8
// 007b7e8b  c20400               ret 4
// 007b7e8e  3bcf                 cmp ecx, edi
// 007b7e90  7606                 jbe 0x7b7e98
// 007b7e92  ff1560b79800         call dword ptr [0x98b760]
// 007b7e98  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b7e9c  8b06                 mov eax, dword ptr [esi]
// 007b7e9e  52                   push edx
// 007b7e9f  57                   push edi
// 007b7ea0  50                   push eax
// 007b7ea1  8d442414             lea eax, [esp + 0x14]
// 007b7ea5  50                   push eax
// 007b7ea6  8bce                 mov ecx, esi
// 007b7ea8  e8f38eccff           call 0x480da0
// 007b7ead  5f                   pop edi
// 007b7eae  5e                   pop esi
// 007b7eaf  83c408               add esp, 8
// 007b7eb2  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

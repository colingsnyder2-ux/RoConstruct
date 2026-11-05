// from server: 100% by auto
// roc 2008-06 004213a0  unit: RBX::VInstance::?$MarshaledListener  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004213a0
//
// 004213a0  83ec08               sub esp, 8
// 004213a3  56                   push esi
// 004213a4  8bf1                 mov esi, ecx
// 004213a6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004213a9  57                   push edi
// 004213aa  85c9                 test ecx, ecx
// 004213ac  7504                 jne 0x4213b2
// 004213ae  33c0                 xor eax, eax
// 004213b0  eb08                 jmp 0x4213ba
// 004213b2  8b4614               mov eax, dword ptr [esi + 0x14]
// 004213b5  2bc1                 sub eax, ecx
// 004213b7  c1f802               sar eax, 2
// 004213ba  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004213bd  8bd7                 mov edx, edi
// 004213bf  2bd1                 sub edx, ecx
// 004213c1  c1fa02               sar edx, 2
// 004213c4  3bd0                 cmp edx, eax
// 004213c6  7316                 jae 0x4213de
// 004213c8  8b442414             mov eax, dword ptr [esp + 0x14]
// 004213cc  8b08                 mov ecx, dword ptr [eax]
// 004213ce  890f                 mov dword ptr [edi], ecx
// 004213d0  83c704               add edi, 4
// 004213d3  897e10               mov dword ptr [esi + 0x10], edi
// 004213d6  5f                   pop edi
// 004213d7  5e                   pop esi
// 004213d8  83c408               add esp, 8
// 004213db  c20400               ret 4
// 004213de  3bcf                 cmp ecx, edi
// 004213e0  7606                 jbe 0x4213e8
// 004213e2  ff1590288000         call dword ptr [0x802890]
// 004213e8  8b542414             mov edx, dword ptr [esp + 0x14]
// 004213ec  8b06                 mov eax, dword ptr [esi]
// 004213ee  52                   push edx
// 004213ef  57                   push edi
// 004213f0  50                   push eax
// 004213f1  8d442414             lea eax, [esp + 0x14]
// 004213f5  50                   push eax
// 004213f6  8bce                 mov ecx, esi
// 004213f8  e863680a00           call 0x4c7c60
// 004213fd  5f                   pop edi
// 004213fe  5e                   pop esi
// 004213ff  83c408               add esp, 8
// 00421402  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

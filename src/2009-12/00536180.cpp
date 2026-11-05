// from server: 100% by auto
// roc 2009-12 00536180  unit: RBX::Network::IdSerializer  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00536180
//
// 00536180  83ec08               sub esp, 8
// 00536183  53                   push ebx
// 00536184  56                   push esi
// 00536185  8bf1                 mov esi, ecx
// 00536187  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0053618a  57                   push edi
// 0053618b  85db                 test ebx, ebx
// 0053618d  7504                 jne 0x536193
// 0053618f  33c9                 xor ecx, ecx
// 00536191  eb15                 jmp 0x5361a8
// 00536193  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00536196  2bcb                 sub ecx, ebx
// 00536198  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053619d  f7e9                 imul ecx
// 0053619f  d1fa                 sar edx, 1
// 005361a1  8bca                 mov ecx, edx
// 005361a3  c1e91f               shr ecx, 0x1f
// 005361a6  03ca                 add ecx, edx
// 005361a8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005361ab  8bd7                 mov edx, edi
// 005361ad  2bd3                 sub edx, ebx
// 005361af  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005361b4  f7ea                 imul edx
// 005361b6  d1fa                 sar edx, 1
// 005361b8  8bc2                 mov eax, edx
// 005361ba  c1e81f               shr eax, 0x1f
// 005361bd  03c2                 add eax, edx
// 005361bf  3bc1                 cmp eax, ecx
// 005361c1  7332                 jae 0x5361f5
// 005361c3  8b542418             mov edx, dword ptr [esp + 0x18]
// 005361c7  c644240c00           mov byte ptr [esp + 0xc], 0
// 005361cc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005361d0  51                   push ecx
// 005361d1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005361d5  52                   push edx
// 005361d6  8d4608               lea eax, [esi + 8]
// 005361d9  50                   push eax
// 005361da  51                   push ecx
// 005361db  6a01                 push 1
// 005361dd  57                   push edi
// 005361de  e88defffff           call 0x535170
// 005361e3  83c418               add esp, 0x18
// 005361e6  83c70c               add edi, 0xc
// 005361e9  897e10               mov dword ptr [esi + 0x10], edi
// 005361ec  5f                   pop edi
// 005361ed  5e                   pop esi
// 005361ee  5b                   pop ebx
// 005361ef  83c408               add esp, 8
// 005361f2  c20400               ret 4
// 005361f5  3bdf                 cmp ebx, edi
// 005361f7  7606                 jbe 0x5361ff
// 005361f9  ff1560b79800         call dword ptr [0x98b760]
// 005361ff  8b542418             mov edx, dword ptr [esp + 0x18]
// 00536203  8b06                 mov eax, dword ptr [esi]
// 00536205  52                   push edx
// 00536206  57                   push edi
// 00536207  50                   push eax
// 00536208  8d442418             lea eax, [esp + 0x18]
// 0053620c  50                   push eax
// 0053620d  8bce                 mov ecx, esi
// 0053620f  e89cfeffff           call 0x5360b0
// 00536214  5f                   pop edi
// 00536215  5e                   pop esi
// 00536216  5b                   pop ebx
// 00536217  83c408               add esp, 8
// 0053621a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2007-08 0042e090  unit: VCLuaFunction::?$CComObject  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042e090
//
// 0042e090  83ec08               sub esp, 8
// 0042e093  56                   push esi
// 0042e094  8bf1                 mov esi, ecx
// 0042e096  8b5604               mov edx, dword ptr [esi + 4]
// 0042e099  85d2                 test edx, edx
// 0042e09b  57                   push edi
// 0042e09c  7504                 jne 0x42e0a2
// 0042e09e  33c9                 xor ecx, ecx
// 0042e0a0  eb08                 jmp 0x42e0aa
// 0042e0a2  8b4e08               mov ecx, dword ptr [esi + 8]
// 0042e0a5  2bca                 sub ecx, edx
// 0042e0a7  c1f903               sar ecx, 3
// 0042e0aa  85d2                 test edx, edx
// 0042e0ac  743d                 je 0x42e0eb
// 0042e0ae  8b460c               mov eax, dword ptr [esi + 0xc]
// 0042e0b1  2bc2                 sub eax, edx
// 0042e0b3  c1f803               sar eax, 3
// 0042e0b6  3bc8                 cmp ecx, eax
// 0042e0b8  7331                 jae 0x42e0eb
// 0042e0ba  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042e0be  8b542414             mov edx, dword ptr [esp + 0x14]
// 0042e0c2  8b7e08               mov edi, dword ptr [esi + 8]
// 0042e0c5  c644240800           mov byte ptr [esp + 8], 0
// 0042e0ca  8b442408             mov eax, dword ptr [esp + 8]
// 0042e0ce  50                   push eax
// 0042e0cf  51                   push ecx
// 0042e0d0  56                   push esi
// 0042e0d1  52                   push edx
// 0042e0d2  6a01                 push 1
// 0042e0d4  57                   push edi
// 0042e0d5  e856f9ffff           call 0x42da30
// 0042e0da  83c418               add esp, 0x18
// 0042e0dd  83c708               add edi, 8
// 0042e0e0  897e08               mov dword ptr [esi + 8], edi
// 0042e0e3  5f                   pop edi
// 0042e0e4  5e                   pop esi
// 0042e0e5  83c408               add esp, 8
// 0042e0e8  c20400               ret 4
// 0042e0eb  8b7e08               mov edi, dword ptr [esi + 8]
// 0042e0ee  3bd7                 cmp edx, edi
// 0042e0f0  7606                 jbe 0x42e0f8
// 0042e0f2  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042e0f8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042e0fc  50                   push eax
// 0042e0fd  57                   push edi
// 0042e0fe  56                   push esi
// 0042e0ff  8d4c2414             lea ecx, [esp + 0x14]
// 0042e103  51                   push ecx
// 0042e104  8bce                 mov ecx, esi
// 0042e106  e855feffff           call 0x42df60
// 0042e10b  5f                   pop edi
// 0042e10c  5e                   pop esi
// 0042e10d  83c408               add esp, 8
// 0042e110  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;

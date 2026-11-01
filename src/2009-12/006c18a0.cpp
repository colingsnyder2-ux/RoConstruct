// from server: 100% by auto
// roc 2009-12 006c18a0  unit: RBX::VInstance::?$NonFactoryProduct  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c18a0
//
// 006c18a0  55                   push ebp
// 006c18a1  8bec                 mov ebp, esp
// 006c18a3  6aff                 push -1
// 006c18a5  6848919400           push 0x949148
// 006c18aa  64a100000000         mov eax, dword ptr fs:[0]
// 006c18b0  50                   push eax
// 006c18b1  64892500000000       mov dword ptr fs:[0], esp
// 006c18b8  83ec0c               sub esp, 0xc
// 006c18bb  53                   push ebx
// 006c18bc  56                   push esi
// 006c18bd  57                   push edi
// 006c18be  8965f0               mov dword ptr [ebp - 0x10], esp
// 006c18c1  8bf9                 mov edi, ecx
// 006c18c3  6a04                 push 4
// 006c18c5  897de8               mov dword ptr [ebp - 0x18], edi
// 006c18c8  e8931f1300           call 0x7f3860
// 006c18cd  33c9                 xor ecx, ecx
// 006c18cf  83c404               add esp, 4
// 006c18d2  3bc1                 cmp eax, ecx
// 006c18d4  7404                 je 0x6c18da
// 006c18d6  8938                 mov dword ptr [eax], edi
// 006c18d8  eb02                 jmp 0x6c18dc
// 006c18da  33c0                 xor eax, eax
// 006c18dc  8907                 mov dword ptr [edi], eax
// 006c18de  8b5d08               mov ebx, dword ptr [ebp + 8]
// 006c18e1  8b7310               mov esi, dword ptr [ebx + 0x10]
// 006c18e4  2b730c               sub esi, dword ptr [ebx + 0xc]
// 006c18e7  894dfc               mov dword ptr [ebp - 4], ecx
// 006c18ea  c1fe05               sar esi, 5
// 006c18ed  894f0c               mov dword ptr [edi + 0xc], ecx
// 006c18f0  894f10               mov dword ptr [edi + 0x10], ecx
// 006c18f3  894f14               mov dword ptr [edi + 0x14], ecx
// 006c18f6  3bf1                 cmp esi, ecx
// 006c18f8  746c                 je 0x6c1966
// 006c18fa  81feffffff07         cmp esi, 0x7ffffff
// 006c1900  7605                 jbe 0x6c1907
// 006c1902  e85908d8ff           call 0x442160
// 006c1907  51                   push ecx
// 006c1908  56                   push esi
// 006c1909  e87237dcff           call 0x485080
// 006c190e  c1e605               shl esi, 5
// 006c1911  03f0                 add esi, eax
// 006c1913  89470c               mov dword ptr [edi + 0xc], eax
// 006c1916  894710               mov dword ptr [edi + 0x10], eax
// 006c1919  897714               mov dword ptr [edi + 0x14], esi
// 006c191c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006c191f  83c408               add esp, 8
// 006c1922  c645fc01             mov byte ptr [ebp - 4], 1
// 006c1926  8945ec               mov dword ptr [ebp - 0x14], eax
// 006c1929  39430c               cmp dword ptr [ebx + 0xc], eax
// 006c192c  7606                 jbe 0x6c1934
// 006c192e  ff1560b79800         call dword ptr [0x98b760]
// 006c1934  8b730c               mov esi, dword ptr [ebx + 0xc]
// 006c1937  3b7310               cmp esi, dword ptr [ebx + 0x10]
// 006c193a  7606                 jbe 0x6c1942
// 006c193c  ff1560b79800         call dword ptr [0x98b760]
// 006c1942  8b470c               mov eax, dword ptr [edi + 0xc]
// 006c1945  c6450800             mov byte ptr [ebp + 8], 0
// 006c1949  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006c194c  8b5508               mov edx, dword ptr [ebp + 8]
// 006c194f  51                   push ecx
// 006c1950  52                   push edx
// 006c1951  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 006c1954  8d4f08               lea ecx, [edi + 8]
// 006c1957  51                   push ecx
// 006c1958  50                   push eax
// 006c1959  52                   push edx
// 006c195a  56                   push esi
// 006c195b  e810e3ffff           call 0x6bfc70
// 006c1960  83c418               add esp, 0x18
// 006c1963  894710               mov dword ptr [edi + 0x10], eax
// 006c1966  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006c1969  8bc7                 mov eax, edi
// 006c196b  5f                   pop edi
// 006c196c  5e                   pop esi
// 006c196d  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1974  5b                   pop ebx
// 006c1975  8be5                 mov esp, ebp
// 006c1977  5d                   pop ebp
// 006c1978  c20400               ret 4
// standard library vector<pod32> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;

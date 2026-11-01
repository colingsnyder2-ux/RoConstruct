// from server: 100% by auto
// roc 2009-12 005b1840  unit: RBX::BrickBuilder  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1840
//
// 005b1840  6aff                 push -1
// 005b1842  6838ca9300           push 0x93ca38
// 005b1847  64a100000000         mov eax, dword ptr fs:[0]
// 005b184d  50                   push eax
// 005b184e  64892500000000       mov dword ptr fs:[0], esp
// 005b1855  51                   push ecx
// 005b1856  53                   push ebx
// 005b1857  56                   push esi
// 005b1858  57                   push edi
// 005b1859  8bf1                 mov esi, ecx
// 005b185b  6a04                 push 4
// 005b185d  89742410             mov dword ptr [esp + 0x10], esi
// 005b1861  e8fa1f2400           call 0x7f3860
// 005b1866  33c9                 xor ecx, ecx
// 005b1868  83c404               add esp, 4
// 005b186b  3bc1                 cmp eax, ecx
// 005b186d  7404                 je 0x5b1873
// 005b186f  8930                 mov dword ptr [eax], esi
// 005b1871  eb02                 jmp 0x5b1875
// 005b1873  33c0                 xor eax, eax
// 005b1875  8906                 mov dword ptr [esi], eax
// 005b1877  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005b187b  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 005b187e  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 005b1881  894c2418             mov dword ptr [esp + 0x18], ecx
// 005b1885  c1ff02               sar edi, 2
// 005b1888  894e0c               mov dword ptr [esi + 0xc], ecx
// 005b188b  894e10               mov dword ptr [esi + 0x10], ecx
// 005b188e  894e14               mov dword ptr [esi + 0x14], ecx
// 005b1891  3bf9                 cmp edi, ecx
// 005b1893  7467                 je 0x5b18fc
// 005b1895  81ffffffff3f         cmp edi, 0x3fffffff
// 005b189b  7605                 jbe 0x5b18a2
// 005b189d  e8be08e9ff           call 0x442160
// 005b18a2  51                   push ecx
// 005b18a3  57                   push edi
// 005b18a4  e897f0e7ff           call 0x430940
// 005b18a9  89460c               mov dword ptr [esi + 0xc], eax
// 005b18ac  894610               mov dword ptr [esi + 0x10], eax
// 005b18af  8d04b8               lea eax, [eax + edi*4]
// 005b18b2  894614               mov dword ptr [esi + 0x14], eax
// 005b18b5  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 005b18b8  83c408               add esp, 8
// 005b18bb  397b0c               cmp dword ptr [ebx + 0xc], edi
// 005b18be  7606                 jbe 0x5b18c6
// 005b18c0  ff1560b79800         call dword ptr [0x98b760]
// 005b18c6  55                   push ebp
// 005b18c7  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 005b18ca  3b6b10               cmp ebp, dword ptr [ebx + 0x10]
// 005b18cd  7606                 jbe 0x5b18d5
// 005b18cf  ff1560b79800         call dword ptr [0x98b760]
// 005b18d5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005b18d8  2bfd                 sub edi, ebp
// 005b18da  c1ff02               sar edi, 2
// 005b18dd  8d04bd00000000       lea eax, [edi*4]
// 005b18e4  8d1c08               lea ebx, [eax + ecx]
// 005b18e7  85ff                 test edi, edi
// 005b18e9  760d                 jbe 0x5b18f8
// 005b18eb  50                   push eax
// 005b18ec  55                   push ebp
// 005b18ed  50                   push eax
// 005b18ee  51                   push ecx
// 005b18ef  ff15c0b79800         call dword ptr [0x98b7c0]
// 005b18f5  83c410               add esp, 0x10
// 005b18f8  895e10               mov dword ptr [esi + 0x10], ebx
// 005b18fb  5d                   pop ebp
// 005b18fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b1900  5f                   pop edi
// 005b1901  8bc6                 mov eax, esi
// 005b1903  5e                   pop esi
// 005b1904  5b                   pop ebx
// 005b1905  64890d00000000       mov dword ptr fs:[0], ecx
// 005b190c  83c410               add esp, 0x10
// 005b190f  c20400               ret 4
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

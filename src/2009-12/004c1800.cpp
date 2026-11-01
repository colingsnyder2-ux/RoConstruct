// from server: 100% by auto
// roc 2009-12 004c1800  unit: RBX::VSparkles::?$FactoryProduct::Creator  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c1800
//
// 004c1800  83ec08               sub esp, 8
// 004c1803  56                   push esi
// 004c1804  8bf1                 mov esi, ecx
// 004c1806  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c1809  57                   push edi
// 004c180a  85c9                 test ecx, ecx
// 004c180c  7504                 jne 0x4c1812
// 004c180e  33c0                 xor eax, eax
// 004c1810  eb08                 jmp 0x4c181a
// 004c1812  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c1815  2bc1                 sub eax, ecx
// 004c1817  c1f803               sar eax, 3
// 004c181a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004c181d  8bd7                 mov edx, edi
// 004c181f  2bd1                 sub edx, ecx
// 004c1821  c1fa03               sar edx, 3
// 004c1824  3bd0                 cmp edx, eax
// 004c1826  7331                 jae 0x4c1859
// 004c1828  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c182c  c644240800           mov byte ptr [esp + 8], 0
// 004c1831  8b442408             mov eax, dword ptr [esp + 8]
// 004c1835  50                   push eax
// 004c1836  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c183a  51                   push ecx
// 004c183b  8d5608               lea edx, [esi + 8]
// 004c183e  52                   push edx
// 004c183f  50                   push eax
// 004c1840  6a01                 push 1
// 004c1842  57                   push edi
// 004c1843  e818f4ffff           call 0x4c0c60
// 004c1848  83c418               add esp, 0x18
// 004c184b  83c708               add edi, 8
// 004c184e  897e10               mov dword ptr [esi + 0x10], edi
// 004c1851  5f                   pop edi
// 004c1852  5e                   pop esi
// 004c1853  83c408               add esp, 8
// 004c1856  c20400               ret 4
// 004c1859  3bcf                 cmp ecx, edi
// 004c185b  7606                 jbe 0x4c1863
// 004c185d  ff1560b79800         call dword ptr [0x98b760]
// 004c1863  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c1867  8b06                 mov eax, dword ptr [esi]
// 004c1869  51                   push ecx
// 004c186a  57                   push edi
// 004c186b  50                   push eax
// 004c186c  8d542414             lea edx, [esp + 0x14]
// 004c1870  52                   push edx
// 004c1871  8bce                 mov ecx, esi
// 004c1873  e848fbffff           call 0x4c13c0
// 004c1878  5f                   pop edi
// 004c1879  5e                   pop esi
// 004c187a  83c408               add esp, 8
// 004c187d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;

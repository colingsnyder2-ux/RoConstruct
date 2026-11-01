// from server: 100% by auto
// roc 2009-12 006c17b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c17b0
//
// 006c17b0  51                   push ecx
// 006c17b1  8b442414             mov eax, dword ptr [esp + 0x14]
// 006c17b5  53                   push ebx
// 006c17b6  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006c17bc  56                   push esi
// 006c17bd  57                   push edi
// 006c17be  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006c17c2  8b7714               mov esi, dword ptr [edi + 0x14]
// 006c17c5  894c240c             mov dword ptr [esp + 0xc], ecx
// 006c17c9  8b0f                 mov ecx, dword ptr [edi]
// 006c17cb  85c0                 test eax, eax
// 006c17cd  7404                 je 0x6c17d3
// 006c17cf  3bc1                 cmp eax, ecx
// 006c17d1  7406                 je 0x6c17d9
// 006c17d3  ffd3                 call ebx
// 006c17d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 006c17d9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006c17dd  3bce                 cmp ecx, esi
// 006c17df  7479                 je 0x6c185a
// 006c17e1  55                   push ebp
// 006c17e2  8be8                 mov ebp, eax
// 006c17e4  8bf1                 mov esi, ecx
// 006c17e6  85c0                 test eax, eax
// 006c17e8  7577                 jne 0x6c1861
// 006c17ea  ffd3                 call ebx
// 006c17ec  8b442424             mov eax, dword ptr [esp + 0x24]
// 006c17f0  33c9                 xor ecx, ecx
// 006c17f2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 006c17f5  7506                 jne 0x6c17fd
// 006c17f7  ffd3                 call ebx
// 006c17f9  8b442424             mov eax, dword ptr [esp + 0x24]
// 006c17fd  8b36                 mov esi, dword ptr [esi]
// 006c17ff  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c1803  397c2410             cmp dword ptr [esp + 0x10], edi
// 006c1807  7534                 jne 0x6c183d
// 006c1809  85c9                 test ecx, ecx
// 006c180b  7404                 je 0x6c1811
// 006c180d  3bc8                 cmp ecx, eax
// 006c180f  740a                 je 0x6c181b
// 006c1811  ffd3                 call ebx
// 006c1813  8b442424             mov eax, dword ptr [esp + 0x24]
// 006c1817  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c181b  8b542428             mov edx, dword ptr [esp + 0x28]
// 006c181f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 006c1823  7434                 je 0x6c1859
// 006c1825  85c9                 test ecx, ecx
// 006c1827  7404                 je 0x6c182d
// 006c1829  3bcd                 cmp ecx, ebp
// 006c182b  740a                 je 0x6c1837
// 006c182d  ffd3                 call ebx
// 006c182f  8b442424             mov eax, dword ptr [esp + 0x24]
// 006c1833  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c1837  3974241c             cmp dword ptr [esp + 0x1c], esi
// 006c183b  741c                 je 0x6c1859
// 006c183d  8b542428             mov edx, dword ptr [esp + 0x28]
// 006c1841  6a00                 push 0
// 006c1843  6a01                 push 1
// 006c1845  56                   push esi
// 006c1846  55                   push ebp
// 006c1847  52                   push edx
// 006c1848  50                   push eax
// 006c1849  8b442434             mov eax, dword ptr [esp + 0x34]
// 006c184d  57                   push edi
// 006c184e  50                   push eax
// 006c184f  51                   push ecx
// 006c1850  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006c1854  e817f2ffff           call 0x6c0a70
// 006c1859  5d                   pop ebp
// 006c185a  5f                   pop edi
// 006c185b  5e                   pop esi
// 006c185c  5b                   pop ebx
// 006c185d  59                   pop ecx
// 006c185e  c21400               ret 0x14
// 006c1861  8b08                 mov ecx, dword ptr [eax]
// 006c1863  eb8d                 jmp 0x6c17f2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;

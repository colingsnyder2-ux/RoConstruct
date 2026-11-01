// from server: 100% by auto
// roc 2007-03 005f1550  unit: seg_005f0000  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f1550
//
// 005f1550  64a100000000         mov eax, dword ptr fs:[0]
// 005f1556  6aff                 push -1
// 005f1558  68926f7500           push 0x756f92
// 005f155d  50                   push eax
// 005f155e  64892500000000       mov dword ptr fs:[0], esp
// 005f1565  8b442418             mov eax, dword ptr [esp + 0x18]
// 005f1569  83ec48               sub esp, 0x48
// 005f156c  80781900             cmp byte ptr [eax + 0x19], 0
// 005f1570  55                   push ebp
// 005f1571  8be9                 mov ebp, ecx
// 005f1573  7459                 je 0x5f15ce
// 005f1575  68dc3e7800           push 0x783edc
// 005f157a  8d4c240c             lea ecx, [esp + 0xc]
// 005f157e  ff1578e77700         call dword ptr [0x77e778]
// 005f1584  8d4c2424             lea ecx, [esp + 0x24]
// 005f1588  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005f1590  ff1560e97700         call dword ptr [0x77e960]
// 005f1596  8d442408             lea eax, [esp + 8]
// 005f159a  50                   push eax
// 005f159b  8d4c2434             lea ecx, [esp + 0x34]
// 005f159f  c644245801           mov byte ptr [esp + 0x58], 1
// 005f15a4  c7442428383e7800     mov dword ptr [esp + 0x28], 0x783e38
// 005f15ac  ff157ce77700         call dword ptr [0x77e77c]
// 005f15b2  68ccf38300           push 0x83f3cc
// 005f15b7  8d4c2428             lea ecx, [esp + 0x28]
// 005f15bb  51                   push ecx
// 005f15bc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005f15c1  c744242c503e7800     mov dword ptr [esp + 0x2c], 0x783e50
// 005f15c9  e860da0200           call 0x61f02e
// 005f15ce  53                   push ebx
// 005f15cf  56                   push esi
// 005f15d0  8bd8                 mov ebx, eax
// 005f15d2  57                   push edi
// 005f15d3  8d4c246c             lea ecx, [esp + 0x6c]
// 005f15d7  895c2410             mov dword ptr [esp + 0x10], ebx
// 005f15db  e820fcffff           call 0x5f1200
// 005f15e0  8b03                 mov eax, dword ptr [ebx]
// 005f15e2  80781900             cmp byte ptr [eax + 0x19], 0
// 005f15e6  7405                 je 0x5f15ed
// 005f15e8  8b7b08               mov edi, dword ptr [ebx + 8]
// 005f15eb  eb18                 jmp 0x5f1605
// 005f15ed  8b5308               mov edx, dword ptr [ebx + 8]
// 005f15f0  807a1900             cmp byte ptr [edx + 0x19], 0
// 005f15f4  7404                 je 0x5f15fa
// 005f15f6  8bf8                 mov edi, eax
// 005f15f8  eb0b                 jmp 0x5f1605
// 005f15fa  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 005f15fe  3bcb                 cmp ecx, ebx
// 005f1600  8b7908               mov edi, dword ptr [ecx + 8]
// 005f1603  756b                 jne 0x5f1670
// 005f1605  807f1900             cmp byte ptr [edi + 0x19], 0
// 005f1609  8b7304               mov esi, dword ptr [ebx + 4]
// 005f160c  7503                 jne 0x5f1611
// 005f160e  897704               mov dword ptr [edi + 4], esi
// 005f1611  8b4504               mov eax, dword ptr [ebp + 4]
// 005f1614  395804               cmp dword ptr [eax + 4], ebx
// 005f1617  7505                 jne 0x5f161e
// 005f1619  897804               mov dword ptr [eax + 4], edi
// 005f161c  eb0b                 jmp 0x5f1629
// 005f161e  391e                 cmp dword ptr [esi], ebx
// 005f1620  7504                 jne 0x5f1626
// 005f1622  893e                 mov dword ptr [esi], edi
// 005f1624  eb03                 jmp 0x5f1629
// 005f1626  897e08               mov dword ptr [esi + 8], edi
// 005f1629  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005f162c  8b03                 mov eax, dword ptr [ebx]
// 005f162e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005f1632  7515                 jne 0x5f1649
// 005f1634  807f1900             cmp byte ptr [edi + 0x19], 0
// 005f1638  7404                 je 0x5f163e
// 005f163a  8bc6                 mov eax, esi
// 005f163c  eb09                 jmp 0x5f1647
// 005f163e  57                   push edi
// 005f163f  e85ca9eaff           call 0x49bfa0
// 005f1644  83c404               add esp, 4
// 005f1647  8903                 mov dword ptr [ebx], eax
// 005f1649  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005f164c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f1650  394b08               cmp dword ptr [ebx + 8], ecx
// 005f1653  7572                 jne 0x5f16c7
// 005f1655  807f1900             cmp byte ptr [edi + 0x19], 0
// 005f1659  7407                 je 0x5f1662
// 005f165b  8bc6                 mov eax, esi
// 005f165d  894308               mov dword ptr [ebx + 8], eax
// 005f1660  eb65                 jmp 0x5f16c7
// 005f1662  57                   push edi
// 005f1663  e888f8ffff           call 0x5f0ef0
// 005f1668  83c404               add esp, 4
// 005f166b  894308               mov dword ptr [ebx + 8], eax
// 005f166e  eb57                 jmp 0x5f16c7
// 005f1670  894804               mov dword ptr [eax + 4], ecx
// 005f1673  8b13                 mov edx, dword ptr [ebx]
// 005f1675  8911                 mov dword ptr [ecx], edx
// 005f1677  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005f167a  7504                 jne 0x5f1680
// 005f167c  8bf1                 mov esi, ecx
// 005f167e  eb1a                 jmp 0x5f169a
// 005f1680  807f1900             cmp byte ptr [edi + 0x19], 0
// 005f1684  8b7104               mov esi, dword ptr [ecx + 4]
// 005f1687  7503                 jne 0x5f168c
// 005f1689  897704               mov dword ptr [edi + 4], esi
// 005f168c  893e                 mov dword ptr [esi], edi
// 005f168e  8b4308               mov eax, dword ptr [ebx + 8]
// 005f1691  894108               mov dword ptr [ecx + 8], eax
// 005f1694  8b5308               mov edx, dword ptr [ebx + 8]
// 005f1697  894a04               mov dword ptr [edx + 4], ecx
// 005f169a  8b4504               mov eax, dword ptr [ebp + 4]
// 005f169d  395804               cmp dword ptr [eax + 4], ebx
// 005f16a0  7505                 jne 0x5f16a7
// 005f16a2  894804               mov dword ptr [eax + 4], ecx
// 005f16a5  eb0e                 jmp 0x5f16b5
// 005f16a7  8b4304               mov eax, dword ptr [ebx + 4]
// 005f16aa  3918                 cmp dword ptr [eax], ebx
// 005f16ac  7504                 jne 0x5f16b2
// 005f16ae  8908                 mov dword ptr [eax], ecx
// 005f16b0  eb03                 jmp 0x5f16b5
// 005f16b2  894808               mov dword ptr [eax + 8], ecx
// 005f16b5  8b4304               mov eax, dword ptr [ebx + 4]
// 005f16b8  894104               mov dword ptr [ecx + 4], eax
// 005f16bb  8a5318               mov dl, byte ptr [ebx + 0x18]
// 005f16be  8a4118               mov al, byte ptr [ecx + 0x18]
// 005f16c1  885118               mov byte ptr [ecx + 0x18], dl
// 005f16c4  884318               mov byte ptr [ebx + 0x18], al
// 005f16c7  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f16cb  b301                 mov bl, 1
// 005f16cd  385818               cmp byte ptr [eax + 0x18], bl
// 005f16d0  0f85f2000000         jne 0x5f17c8
// 005f16d6  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005f16d9  3b7904               cmp edi, dword ptr [ecx + 4]
// 005f16dc  0f84e3000000         je 0x5f17c5
// 005f16e2  385f18               cmp byte ptr [edi + 0x18], bl
// 005f16e5  0f85da000000         jne 0x5f17c5
// 005f16eb  8b06                 mov eax, dword ptr [esi]
// 005f16ed  3bf8                 cmp edi, eax
// 005f16ef  7563                 jne 0x5f1754
// 005f16f1  8b4608               mov eax, dword ptr [esi + 8]
// 005f16f4  80781800             cmp byte ptr [eax + 0x18], 0
// 005f16f8  7512                 jne 0x5f170c
// 005f16fa  885818               mov byte ptr [eax + 0x18], bl
// 005f16fd  56                   push esi
// 005f16fe  8bcd                 mov ecx, ebp
// 005f1700  c6461800             mov byte ptr [esi + 0x18], 0
// 005f1704  e8a7faffff           call 0x5f11b0
// 005f1709  8b4608               mov eax, dword ptr [esi + 8]
// 005f170c  80781900             cmp byte ptr [eax + 0x19], 0
// 005f1710  7572                 jne 0x5f1784
// 005f1712  8b10                 mov edx, dword ptr [eax]
// 005f1714  385a18               cmp byte ptr [edx + 0x18], bl
// 005f1717  7508                 jne 0x5f1721
// 005f1719  8b4808               mov ecx, dword ptr [eax + 8]
// 005f171c  385918               cmp byte ptr [ecx + 0x18], bl
// 005f171f  745f                 je 0x5f1780
// 005f1721  8b4808               mov ecx, dword ptr [eax + 8]
// 005f1724  385918               cmp byte ptr [ecx + 0x18], bl
// 005f1727  7512                 jne 0x5f173b
// 005f1729  885a18               mov byte ptr [edx + 0x18], bl
// 005f172c  50                   push eax
// 005f172d  8bcd                 mov ecx, ebp
// 005f172f  c6401800             mov byte ptr [eax + 0x18], 0
// 005f1733  e828a7eaff           call 0x49be60
// 005f1738  8b4608               mov eax, dword ptr [esi + 8]
// 005f173b  8a4e18               mov cl, byte ptr [esi + 0x18]
// 005f173e  884818               mov byte ptr [eax + 0x18], cl
// 005f1741  885e18               mov byte ptr [esi + 0x18], bl
// 005f1744  8b5008               mov edx, dword ptr [eax + 8]
// 005f1747  56                   push esi
// 005f1748  8bcd                 mov ecx, ebp
// 005f174a  885a18               mov byte ptr [edx + 0x18], bl
// 005f174d  e85efaffff           call 0x5f11b0
// 005f1752  eb71                 jmp 0x5f17c5
// 005f1754  80781800             cmp byte ptr [eax + 0x18], 0
// 005f1758  7511                 jne 0x5f176b
// 005f175a  885818               mov byte ptr [eax + 0x18], bl
// 005f175d  56                   push esi
// 005f175e  8bcd                 mov ecx, ebp
// 005f1760  c6461800             mov byte ptr [esi + 0x18], 0
// 005f1764  e8f7a6eaff           call 0x49be60
// 005f1769  8b06                 mov eax, dword ptr [esi]
// 005f176b  80781900             cmp byte ptr [eax + 0x19], 0
// 005f176f  7513                 jne 0x5f1784
// 005f1771  8b5008               mov edx, dword ptr [eax + 8]
// 005f1774  385a18               cmp byte ptr [edx + 0x18], bl
// 005f1777  751e                 jne 0x5f1797
// 005f1779  8b08                 mov ecx, dword ptr [eax]
// 005f177b  385918               cmp byte ptr [ecx + 0x18], bl
// 005f177e  7517                 jne 0x5f1797
// 005f1780  c6401800             mov byte ptr [eax + 0x18], 0
// 005f1784  8b5504               mov edx, dword ptr [ebp + 4]
// 005f1787  8bfe                 mov edi, esi
// 005f1789  3b7a04               cmp edi, dword ptr [edx + 4]
// 005f178c  8b7604               mov esi, dword ptr [esi + 4]
// 005f178f  0f854dffffff         jne 0x5f16e2
// 005f1795  eb2e                 jmp 0x5f17c5
// 005f1797  8b08                 mov ecx, dword ptr [eax]
// 005f1799  385918               cmp byte ptr [ecx + 0x18], bl
// 005f179c  7511                 jne 0x5f17af
// 005f179e  885a18               mov byte ptr [edx + 0x18], bl
// 005f17a1  50                   push eax
// 005f17a2  8bcd                 mov ecx, ebp
// 005f17a4  c6401800             mov byte ptr [eax + 0x18], 0
// 005f17a8  e803faffff           call 0x5f11b0
// 005f17ad  8b06                 mov eax, dword ptr [esi]
// 005f17af  8a4e18               mov cl, byte ptr [esi + 0x18]
// 005f17b2  884818               mov byte ptr [eax + 0x18], cl
// 005f17b5  885e18               mov byte ptr [esi + 0x18], bl
// 005f17b8  8b10                 mov edx, dword ptr [eax]
// 005f17ba  56                   push esi
// 005f17bb  8bcd                 mov ecx, ebp
// 005f17bd  885a18               mov byte ptr [edx + 0x18], bl
// 005f17c0  e89ba6eaff           call 0x49be60
// 005f17c5  885f18               mov byte ptr [edi + 0x18], bl
// 005f17c8  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f17cc  50                   push eax
// 005f17cd  e81ec90200           call 0x61e0f0
// 005f17d2  8b4508               mov eax, dword ptr [ebp + 8]
// 005f17d5  83c404               add esp, 4
// 005f17d8  85c0                 test eax, eax
// 005f17da  5f                   pop edi
// 005f17db  5e                   pop esi
// 005f17dc  5b                   pop ebx
// 005f17dd  7606                 jbe 0x5f17e5
// 005f17df  83c0ff               add eax, -1
// 005f17e2  894508               mov dword ptr [ebp + 8], eax
// 005f17e5  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005f17e9  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005f17ed  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f17f1  8908                 mov dword ptr [eax], ecx
// 005f17f3  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005f17f7  895004               mov dword ptr [eax + 4], edx
// 005f17fa  5d                   pop ebp
// 005f17fb  64890d00000000       mov dword ptr fs:[0], ecx
// 005f1802  83c454               add esp, 0x54
// 005f1805  c20c00               ret 0xc
// standard library set<double> (function ?erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;

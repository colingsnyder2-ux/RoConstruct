// from server: 100% by auto
// roc 2008-06 004c1600  unit: ProfiledRakPeer  size: 710 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1600
//
// 004c1600  83ec60               sub esp, 0x60
// 004c1603  33c0                 xor eax, eax
// 004c1605  56                   push esi
// 004c1606  8b742468             mov esi, dword ptr [esp + 0x68]
// 004c160a  89442418             mov dword ptr [esp + 0x18], eax
// 004c160e  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c1612  89442420             mov dword ptr [esp + 0x20], eax
// 004c1616  8d442424             lea eax, [esp + 0x24]
// 004c161a  50                   push eax
// 004c161b  56                   push esi
// 004c161c  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004c1624  e817f8ffff           call 0x4c0e40
// 004c1629  8d4c244c             lea ecx, [esp + 0x4c]
// 004c162d  51                   push ecx
// 004c162e  8d542440             lea edx, [esp + 0x40]
// 004c1632  52                   push edx
// 004c1633  8d442434             lea eax, [esp + 0x34]
// 004c1637  50                   push eax
// 004c1638  56                   push esi
// 004c1639  e872d2ffff           call 0x4be8b0
// 004c163e  83c418               add esp, 0x18
// 004c1641  33c0                 xor eax, eax
// 004c1643  837c844400           cmp dword ptr [esp + eax*4 + 0x44], 0
// 004c1648  752a                 jne 0x4c1674
// 004c164a  40                   inc eax
// 004c164b  83f804               cmp eax, 4
// 004c164e  72f3                 jb 0x4c1643
// 004c1650  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 004c1654  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c1658  8b542418             mov edx, dword ptr [esp + 0x18]
// 004c165c  8908                 mov dword ptr [eax], ecx
// 004c165e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c1662  895004               mov dword ptr [eax + 4], edx
// 004c1665  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c1669  894808               mov dword ptr [eax + 8], ecx
// 004c166c  89500c               mov dword ptr [eax + 0xc], edx
// 004c166f  5e                   pop esi
// 004c1670  83c460               add esp, 0x60
// 004c1673  c3                   ret 
// 004c1674  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c1677  8b5608               mov edx, dword ptr [esi + 8]
// 004c167a  8b06                 mov eax, dword ptr [esi]
// 004c167c  894c2408             mov dword ptr [esp + 8], ecx
// 004c1680  8d4c2434             lea ecx, [esp + 0x34]
// 004c1684  8954240c             mov dword ptr [esp + 0xc], edx
// 004c1688  89442404             mov dword ptr [esp + 4], eax
// 004c168c  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c168f  51                   push ecx
// 004c1690  8d542408             lea edx, [esp + 8]
// 004c1694  52                   push edx
// 004c1695  89442418             mov dword ptr [esp + 0x18], eax
// 004c1699  e822b0ffff           call 0x4bc6c0
// 004c169e  8d44242c             lea eax, [esp + 0x2c]
// 004c16a2  50                   push eax
// 004c16a3  8d4c2440             lea ecx, [esp + 0x40]
// 004c16a7  51                   push ecx
// 004c16a8  8d542454             lea edx, [esp + 0x54]
// 004c16ac  52                   push edx
// 004c16ad  50                   push eax
// 004c16ae  e8fdd1ffff           call 0x4be8b0
// 004c16b3  83c418               add esp, 0x18
// 004c16b6  33c0                 xor eax, eax
// 004c16b8  837c842400           cmp dword ptr [esp + eax*4 + 0x24], 0
// 004c16bd  7531                 jne 0x4c16f0
// 004c16bf  40                   inc eax
// 004c16c0  83f804               cmp eax, 4
// 004c16c3  72f3                 jb 0x4c16b8
// 004c16c5  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 004c16c9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c16cd  8b542408             mov edx, dword ptr [esp + 8]
// 004c16d1  8908                 mov dword ptr [eax], ecx
// 004c16d3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c16d7  895004               mov dword ptr [eax + 4], edx
// 004c16da  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c16de  894808               mov dword ptr [eax + 8], ecx
// 004c16e1  89500c               mov dword ptr [eax + 0xc], edx
// 004c16e4  5e                   pop esi
// 004c16e5  83c460               add esp, 0x60
// 004c16e8  c3                   ret 
// 004c16e9  8da42400000000       lea esp, [esp]
// 004c16f0  8d442454             lea eax, [esp + 0x54]
// 004c16f4  50                   push eax
// 004c16f5  56                   push esi
// 004c16f6  8d4c241c             lea ecx, [esp + 0x1c]
// 004c16fa  51                   push ecx
// 004c16fb  8d542410             lea edx, [esp + 0x10]
// 004c16ff  52                   push edx
// 004c1700  8d442444             lea eax, [esp + 0x44]
// 004c1704  50                   push eax
// 004c1705  e876d4ffff           call 0x4beb80
// 004c170a  8d4c2458             lea ecx, [esp + 0x58]
// 004c170e  51                   push ecx
// 004c170f  8d54244c             lea edx, [esp + 0x4c]
// 004c1713  52                   push edx
// 004c1714  8d442440             lea eax, [esp + 0x40]
// 004c1718  50                   push eax
// 004c1719  51                   push ecx
// 004c171a  e891d1ffff           call 0x4be8b0
// 004c171f  83c424               add esp, 0x24
// 004c1722  33c0                 xor eax, eax
// 004c1724  837c844400           cmp dword ptr [esp + eax*4 + 0x44], 0
// 004c1729  752a                 jne 0x4c1755
// 004c172b  40                   inc eax
// 004c172c  83f804               cmp eax, 4
// 004c172f  72f3                 jb 0x4c1724
// 004c1731  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 004c1735  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004c1739  8b542458             mov edx, dword ptr [esp + 0x58]
// 004c173d  8908                 mov dword ptr [eax], ecx
// 004c173f  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 004c1743  895004               mov dword ptr [eax + 4], edx
// 004c1746  8b542460             mov edx, dword ptr [esp + 0x60]
// 004c174a  894808               mov dword ptr [eax + 8], ecx
// 004c174d  89500c               mov dword ptr [eax + 0xc], edx
// 004c1750  5e                   pop esi
// 004c1751  83c460               add esp, 0x60
// 004c1754  c3                   ret 
// 004c1755  8d542414             lea edx, [esp + 0x14]
// 004c1759  52                   push edx
// 004c175a  56                   push esi
// 004c175b  8d44240c             lea eax, [esp + 0xc]
// 004c175f  50                   push eax
// 004c1760  8d4c2460             lea ecx, [esp + 0x60]
// 004c1764  51                   push ecx
// 004c1765  8d542444             lea edx, [esp + 0x44]
// 004c1769  52                   push edx
// 004c176a  e811d4ffff           call 0x4beb80
// 004c176f  8d442438             lea eax, [esp + 0x38]
// 004c1773  50                   push eax
// 004c1774  8d4c244c             lea ecx, [esp + 0x4c]
// 004c1778  51                   push ecx
// 004c1779  8d542460             lea edx, [esp + 0x60]
// 004c177d  52                   push edx
// 004c177e  50                   push eax
// 004c177f  e82cd1ffff           call 0x4be8b0
// 004c1784  83c424               add esp, 0x24
// 004c1787  33c0                 xor eax, eax
// 004c1789  8da42400000000       lea esp, [esp]
// 004c1790  837c842400           cmp dword ptr [esp + eax*4 + 0x24], 0
// 004c1795  750b                 jne 0x4c17a2
// 004c1797  40                   inc eax
// 004c1798  83f804               cmp eax, 4
// 004c179b  72f3                 jb 0x4c1790
// 004c179d  e9aefeffff           jmp 0x4c1650
// 004c17a2  8d4c2404             lea ecx, [esp + 4]
// 004c17a6  51                   push ecx
// 004c17a7  56                   push esi
// 004c17a8  8d54245c             lea edx, [esp + 0x5c]
// 004c17ac  52                   push edx
// 004c17ad  8d442420             lea eax, [esp + 0x20]
// 004c17b1  50                   push eax
// 004c17b2  8d4c2444             lea ecx, [esp + 0x44]
// 004c17b6  51                   push ecx
// 004c17b7  e8c4d3ffff           call 0x4beb80
// 004c17bc  8d542458             lea edx, [esp + 0x58]
// 004c17c0  52                   push edx
// 004c17c1  8d44244c             lea eax, [esp + 0x4c]
// 004c17c5  50                   push eax
// 004c17c6  8d4c2440             lea ecx, [esp + 0x40]
// 004c17ca  51                   push ecx
// 004c17cb  52                   push edx
// 004c17cc  e8dfd0ffff           call 0x4be8b0
// 004c17d1  83c424               add esp, 0x24
// 004c17d4  33c0                 xor eax, eax
// 004c17d6  837c844400           cmp dword ptr [esp + eax*4 + 0x44], 0
// 004c17db  750b                 jne 0x4c17e8
// 004c17dd  40                   inc eax
// 004c17de  83f804               cmp eax, 4
// 004c17e1  72f3                 jb 0x4c17d6
// 004c17e3  e9ddfeffff           jmp 0x4c16c5
// 004c17e8  8d442454             lea eax, [esp + 0x54]
// 004c17ec  50                   push eax
// 004c17ed  56                   push esi
// 004c17ee  8d4c241c             lea ecx, [esp + 0x1c]
// 004c17f2  51                   push ecx
// 004c17f3  8d542410             lea edx, [esp + 0x10]
// 004c17f7  52                   push edx
// 004c17f8  8d442444             lea eax, [esp + 0x44]
// 004c17fc  50                   push eax
// 004c17fd  e87ed3ffff           call 0x4beb80
// 004c1802  8d4c2438             lea ecx, [esp + 0x38]
// 004c1806  51                   push ecx
// 004c1807  8d54244c             lea edx, [esp + 0x4c]
// 004c180b  52                   push edx
// 004c180c  8d442460             lea eax, [esp + 0x60]
// 004c1810  50                   push eax
// 004c1811  51                   push ecx
// 004c1812  e899d0ffff           call 0x4be8b0
// 004c1817  83c424               add esp, 0x24
// 004c181a  33c0                 xor eax, eax
// 004c181c  8d642400             lea esp, [esp]
// 004c1820  837c842400           cmp dword ptr [esp + eax*4 + 0x24], 0
// 004c1825  750b                 jne 0x4c1832
// 004c1827  40                   inc eax
// 004c1828  83f804               cmp eax, 4
// 004c182b  72f3                 jb 0x4c1820
// 004c182d  e9fffeffff           jmp 0x4c1731
// 004c1832  8d542414             lea edx, [esp + 0x14]
// 004c1836  52                   push edx
// 004c1837  56                   push esi
// 004c1838  8d44240c             lea eax, [esp + 0xc]
// 004c183c  50                   push eax
// 004c183d  8d4c2460             lea ecx, [esp + 0x60]
// 004c1841  51                   push ecx
// 004c1842  8d542444             lea edx, [esp + 0x44]
// 004c1846  52                   push edx
// 004c1847  e834d3ffff           call 0x4beb80
// 004c184c  8d442458             lea eax, [esp + 0x58]
// 004c1850  50                   push eax
// 004c1851  8d4c244c             lea ecx, [esp + 0x4c]
// 004c1855  51                   push ecx
// 004c1856  8d542440             lea edx, [esp + 0x40]
// 004c185a  52                   push edx
// 004c185b  50                   push eax
// 004c185c  e84fd0ffff           call 0x4be8b0
// 004c1861  83c424               add esp, 0x24
// 004c1864  33c0                 xor eax, eax
// 004c1866  837c844400           cmp dword ptr [esp + eax*4 + 0x44], 0
// 004c186b  750b                 jne 0x4c1878
// 004c186d  40                   inc eax
// 004c186e  83f804               cmp eax, 4
// 004c1871  72f3                 jb 0x4c1866
// 004c1873  e9d8fdffff           jmp 0x4c1650
// 004c1878  8d4c2404             lea ecx, [esp + 4]
// 004c187c  51                   push ecx
// 004c187d  56                   push esi
// 004c187e  8d54245c             lea edx, [esp + 0x5c]
// 004c1882  52                   push edx
// 004c1883  8d442420             lea eax, [esp + 0x20]
// 004c1887  50                   push eax
// 004c1888  8d4c2444             lea ecx, [esp + 0x44]
// 004c188c  51                   push ecx
// 004c188d  e8eed2ffff           call 0x4beb80
// 004c1892  8d542438             lea edx, [esp + 0x38]
// 004c1896  52                   push edx
// 004c1897  8d44244c             lea eax, [esp + 0x4c]
// 004c189b  50                   push eax
// 004c189c  8d4c2460             lea ecx, [esp + 0x60]
// 004c18a0  51                   push ecx
// 004c18a1  52                   push edx
// 004c18a2  e809d0ffff           call 0x4be8b0
// 004c18a7  83c424               add esp, 0x24
// 004c18aa  33c0                 xor eax, eax
// 004c18ac  8d642400             lea esp, [esp]
// 004c18b0  837c842400           cmp dword ptr [esp + eax*4 + 0x24], 0
// 004c18b5  0f8535feffff         jne 0x4c16f0
// 004c18bb  40                   inc eax
// 004c18bc  83f804               cmp eax, 4
// 004c18bf  72ef                 jb 0x4c18b0
// 004c18c1  e9fffdffff           jmp 0x4c16c5
// library openrbx-raknet/RakPeer.cpp (function ??$computeRinverse@$$BY03I@big@@YAXAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp

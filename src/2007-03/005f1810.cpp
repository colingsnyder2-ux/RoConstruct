// from server: 100% by auto
// roc 2007-03 005f1810  unit: seg_005f0000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f1810
//
// 005f1810  64a100000000         mov eax, dword ptr fs:[0]
// 005f1816  6aff                 push -1
// 005f1818  68926f7500           push 0x756f92
// 005f181d  50                   push eax
// 005f181e  64892500000000       mov dword ptr fs:[0], esp
// 005f1825  83ec44               sub esp, 0x44
// 005f1828  57                   push edi
// 005f1829  8bf9                 mov edi, ecx
// 005f182b  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 005f1832  7259                 jb 0x5f188d
// 005f1834  68903f7800           push 0x783f90
// 005f1839  8d4c2408             lea ecx, [esp + 8]
// 005f183d  ff1578e77700         call dword ptr [0x77e778]
// 005f1843  8d4c2420             lea ecx, [esp + 0x20]
// 005f1847  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005f184f  ff1560e97700         call dword ptr [0x77e960]
// 005f1855  8d442404             lea eax, [esp + 4]
// 005f1859  50                   push eax
// 005f185a  8d4c2430             lea ecx, [esp + 0x30]
// 005f185e  c644245401           mov byte ptr [esp + 0x54], 1
// 005f1863  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 005f186b  ff157ce77700         call dword ptr [0x77e77c]
// 005f1871  6870f78300           push 0x83f770
// 005f1876  8d4c2424             lea ecx, [esp + 0x24]
// 005f187a  51                   push ecx
// 005f187b  c644245800           mov byte ptr [esp + 0x58], 0
// 005f1880  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 005f1888  e8a1d70200           call 0x61f02e
// 005f188d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f1891  8b4704               mov eax, dword ptr [edi + 4]
// 005f1894  53                   push ebx
// 005f1895  55                   push ebp
// 005f1896  56                   push esi
// 005f1897  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005f189b  6a00                 push 0
// 005f189d  52                   push edx
// 005f189e  50                   push eax
// 005f189f  56                   push esi
// 005f18a0  50                   push eax
// 005f18a1  e81afcffff           call 0x5f14c0
// 005f18a6  8be8                 mov ebp, eax
// 005f18a8  8b4704               mov eax, dword ptr [edi + 4]
// 005f18ab  bb01000000           mov ebx, 1
// 005f18b0  015f08               add dword ptr [edi + 8], ebx
// 005f18b3  3bf0                 cmp esi, eax
// 005f18b5  7510                 jne 0x5f18c7
// 005f18b7  896804               mov dword ptr [eax + 4], ebp
// 005f18ba  8b4704               mov eax, dword ptr [edi + 4]
// 005f18bd  8928                 mov dword ptr [eax], ebp
// 005f18bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 005f18c2  896908               mov dword ptr [ecx + 8], ebp
// 005f18c5  eb22                 jmp 0x5f18e9
// 005f18c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005f18cc  740d                 je 0x5f18db
// 005f18ce  892e                 mov dword ptr [esi], ebp
// 005f18d0  8b4704               mov eax, dword ptr [edi + 4]
// 005f18d3  3b30                 cmp esi, dword ptr [eax]
// 005f18d5  7512                 jne 0x5f18e9
// 005f18d7  8928                 mov dword ptr [eax], ebp
// 005f18d9  eb0e                 jmp 0x5f18e9
// 005f18db  896e08               mov dword ptr [esi + 8], ebp
// 005f18de  8b4704               mov eax, dword ptr [edi + 4]
// 005f18e1  3b7008               cmp esi, dword ptr [eax + 8]
// 005f18e4  7503                 jne 0x5f18e9
// 005f18e6  896808               mov dword ptr [eax + 8], ebp
// 005f18e9  8b5504               mov edx, dword ptr [ebp + 4]
// 005f18ec  807a1800             cmp byte ptr [edx + 0x18], 0
// 005f18f0  8d4504               lea eax, [ebp + 4]
// 005f18f3  8bf5                 mov esi, ebp
// 005f18f5  0f85ea000000         jne 0x5f19e5
// 005f18fb  eb03                 jmp 0x5f1900
// 005f18fd  8d4900               lea ecx, [ecx]
// 005f1900  8b08                 mov ecx, dword ptr [eax]
// 005f1902  8b5104               mov edx, dword ptr [ecx + 4]
// 005f1905  3b0a                 cmp ecx, dword ptr [edx]
// 005f1907  7551                 jne 0x5f195a
// 005f1909  8b5208               mov edx, dword ptr [edx + 8]
// 005f190c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005f1910  7519                 jne 0x5f192b
// 005f1912  885918               mov byte ptr [ecx + 0x18], bl
// 005f1915  885a18               mov byte ptr [edx + 0x18], bl
// 005f1918  8b10                 mov edx, dword ptr [eax]
// 005f191a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005f191d  c6411800             mov byte ptr [ecx + 0x18], 0
// 005f1921  8b10                 mov edx, dword ptr [eax]
// 005f1923  8b7204               mov esi, dword ptr [edx + 4]
// 005f1926  e9aa000000           jmp 0x5f19d5
// 005f192b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005f192e  750a                 jne 0x5f193a
// 005f1930  8bf1                 mov esi, ecx
// 005f1932  56                   push esi
// 005f1933  8bcf                 mov ecx, edi
// 005f1935  e876f8ffff           call 0x5f11b0
// 005f193a  8b4604               mov eax, dword ptr [esi + 4]
// 005f193d  885818               mov byte ptr [eax + 0x18], bl
// 005f1940  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f1943  8b5104               mov edx, dword ptr [ecx + 4]
// 005f1946  c6421800             mov byte ptr [edx + 0x18], 0
// 005f194a  8b4604               mov eax, dword ptr [esi + 4]
// 005f194d  8b4804               mov ecx, dword ptr [eax + 4]
// 005f1950  51                   push ecx
// 005f1951  8bcf                 mov ecx, edi
// 005f1953  e808a5eaff           call 0x49be60
// 005f1958  eb7b                 jmp 0x5f19d5
// 005f195a  8b12                 mov edx, dword ptr [edx]
// 005f195c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005f1960  7516                 jne 0x5f1978
// 005f1962  885918               mov byte ptr [ecx + 0x18], bl
// 005f1965  885a18               mov byte ptr [edx + 0x18], bl
// 005f1968  8b10                 mov edx, dword ptr [eax]
// 005f196a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005f196d  c6411800             mov byte ptr [ecx + 0x18], 0
// 005f1971  8b10                 mov edx, dword ptr [eax]
// 005f1973  8b7204               mov esi, dword ptr [edx + 4]
// 005f1976  eb5d                 jmp 0x5f19d5
// 005f1978  3b31                 cmp esi, dword ptr [ecx]
// 005f197a  750a                 jne 0x5f1986
// 005f197c  8bf1                 mov esi, ecx
// 005f197e  56                   push esi
// 005f197f  8bcf                 mov ecx, edi
// 005f1981  e8daa4eaff           call 0x49be60
// 005f1986  8b4604               mov eax, dword ptr [esi + 4]
// 005f1989  885818               mov byte ptr [eax + 0x18], bl
// 005f198c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f198f  8b5104               mov edx, dword ptr [ecx + 4]
// 005f1992  c6421800             mov byte ptr [edx + 0x18], 0
// 005f1996  8b4604               mov eax, dword ptr [esi + 4]
// 005f1999  8b4004               mov eax, dword ptr [eax + 4]
// 005f199c  8b4808               mov ecx, dword ptr [eax + 8]
// 005f199f  8b11                 mov edx, dword ptr [ecx]
// 005f19a1  895008               mov dword ptr [eax + 8], edx
// 005f19a4  8b11                 mov edx, dword ptr [ecx]
// 005f19a6  807a1900             cmp byte ptr [edx + 0x19], 0
// 005f19aa  7503                 jne 0x5f19af
// 005f19ac  894204               mov dword ptr [edx + 4], eax
// 005f19af  8b5004               mov edx, dword ptr [eax + 4]
// 005f19b2  895104               mov dword ptr [ecx + 4], edx
// 005f19b5  8b5704               mov edx, dword ptr [edi + 4]
// 005f19b8  3b4204               cmp eax, dword ptr [edx + 4]
// 005f19bb  7505                 jne 0x5f19c2
// 005f19bd  894a04               mov dword ptr [edx + 4], ecx
// 005f19c0  eb0e                 jmp 0x5f19d0
// 005f19c2  8b5004               mov edx, dword ptr [eax + 4]
// 005f19c5  3b02                 cmp eax, dword ptr [edx]
// 005f19c7  7504                 jne 0x5f19cd
// 005f19c9  890a                 mov dword ptr [edx], ecx
// 005f19cb  eb03                 jmp 0x5f19d0
// 005f19cd  894a08               mov dword ptr [edx + 8], ecx
// 005f19d0  8901                 mov dword ptr [ecx], eax
// 005f19d2  894804               mov dword ptr [eax + 4], ecx
// 005f19d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f19d8  80791800             cmp byte ptr [ecx + 0x18], 0
// 005f19dc  8d4604               lea eax, [esi + 4]
// 005f19df  0f841bffffff         je 0x5f1900
// 005f19e5  8b5704               mov edx, dword ptr [edi + 4]
// 005f19e8  8b4204               mov eax, dword ptr [edx + 4]
// 005f19eb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 005f19ef  885818               mov byte ptr [eax + 0x18], bl
// 005f19f2  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f19f6  5e                   pop esi
// 005f19f7  896804               mov dword ptr [eax + 4], ebp
// 005f19fa  5d                   pop ebp
// 005f19fb  8938                 mov dword ptr [eax], edi
// 005f19fd  5b                   pop ebx
// 005f19fe  5f                   pop edi
// 005f19ff  64890d00000000       mov dword ptr fs:[0], ecx
// 005f1a06  83c450               add esp, 0x50
// 005f1a09  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

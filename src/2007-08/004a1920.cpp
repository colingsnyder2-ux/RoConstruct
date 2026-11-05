// from server: 100% by auto
// roc 2007-08 004a1920  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a1920
//
// 004a1920  83ec0c               sub esp, 0xc
// 004a1923  53                   push ebx
// 004a1924  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004a1928  55                   push ebp
// 004a1929  56                   push esi
// 004a192a  8be9                 mov ebp, ecx
// 004a192c  57                   push edi
// 004a192d  8b7d04               mov edi, dword ptr [ebp + 4]
// 004a1930  8b7704               mov esi, dword ptr [edi + 4]
// 004a1933  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004a1937  b001                 mov al, 1
// 004a1939  88442410             mov byte ptr [esp + 0x10], al
// 004a193d  7526                 jne 0x4a1965
// 004a193f  90                   nop 
// 004a1940  8d460c               lea eax, [esi + 0xc]
// 004a1943  50                   push eax
// 004a1944  53                   push ebx
// 004a1945  8bfe                 mov edi, esi
// 004a1947  ff1520e67700         call dword ptr [0x77e620]
// 004a194d  83c408               add esp, 8
// 004a1950  84c0                 test al, al
// 004a1952  88442410             mov byte ptr [esp + 0x10], al
// 004a1956  7404                 je 0x4a195c
// 004a1958  8b36                 mov esi, dword ptr [esi]
// 004a195a  eb03                 jmp 0x4a195f
// 004a195c  8b7608               mov esi, dword ptr [esi + 8]
// 004a195f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004a1963  74db                 je 0x4a1940
// 004a1965  84c0                 test al, al
// 004a1967  8bf7                 mov esi, edi
// 004a1969  89742418             mov dword ptr [esp + 0x18], esi
// 004a196d  896c2414             mov dword ptr [esp + 0x14], ebp
// 004a1971  7442                 je 0x4a19b5
// 004a1973  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004a1976  3b39                 cmp edi, dword ptr [ecx]
// 004a1978  752e                 jne 0x4a19a8
// 004a197a  53                   push ebx
// 004a197b  57                   push edi
// 004a197c  6a01                 push 1
// 004a197e  8d542420             lea edx, [esp + 0x20]
// 004a1982  52                   push edx
// 004a1983  8bcd                 mov ecx, ebp
// 004a1985  e8c6f9ffff           call 0x4a1350
// 004a198a  5f                   pop edi
// 004a198b  8bc8                 mov ecx, eax
// 004a198d  8b11                 mov edx, dword ptr [ecx]
// 004a198f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a1993  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a1996  5e                   pop esi
// 004a1997  5d                   pop ebp
// 004a1998  894804               mov dword ptr [eax + 4], ecx
// 004a199b  c6400801             mov byte ptr [eax + 8], 1
// 004a199f  8910                 mov dword ptr [eax], edx
// 004a19a1  5b                   pop ebx
// 004a19a2  83c40c               add esp, 0xc
// 004a19a5  c20800               ret 8
// 004a19a8  8d4c2414             lea ecx, [esp + 0x14]
// 004a19ac  e86f1a0e00           call 0x583420
// 004a19b1  8b742418             mov esi, dword ptr [esp + 0x18]
// 004a19b5  8d560c               lea edx, [esi + 0xc]
// 004a19b8  53                   push ebx
// 004a19b9  52                   push edx
// 004a19ba  ff1520e67700         call dword ptr [0x77e620]
// 004a19c0  83c408               add esp, 8
// 004a19c3  84c0                 test al, al
// 004a19c5  7431                 je 0x4a19f8
// 004a19c7  8b442410             mov eax, dword ptr [esp + 0x10]
// 004a19cb  53                   push ebx
// 004a19cc  57                   push edi
// 004a19cd  50                   push eax
// 004a19ce  8d4c2420             lea ecx, [esp + 0x20]
// 004a19d2  51                   push ecx
// 004a19d3  8bcd                 mov ecx, ebp
// 004a19d5  e876f9ffff           call 0x4a1350
// 004a19da  5f                   pop edi
// 004a19db  8bc8                 mov ecx, eax
// 004a19dd  8b11                 mov edx, dword ptr [ecx]
// 004a19df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a19e3  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a19e6  5e                   pop esi
// 004a19e7  5d                   pop ebp
// 004a19e8  894804               mov dword ptr [eax + 4], ecx
// 004a19eb  c6400801             mov byte ptr [eax + 8], 1
// 004a19ef  8910                 mov dword ptr [eax], edx
// 004a19f1  5b                   pop ebx
// 004a19f2  83c40c               add esp, 0xc
// 004a19f5  c20800               ret 8
// 004a19f8  8b442420             mov eax, dword ptr [esp + 0x20]
// 004a19fc  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1a00  5f                   pop edi
// 004a1a01  897004               mov dword ptr [eax + 4], esi
// 004a1a04  5e                   pop esi
// 004a1a05  5d                   pop ebp
// 004a1a06  c6400800             mov byte ptr [eax + 8], 0
// 004a1a0a  8910                 mov dword ptr [eax], edx
// 004a1a0c  5b                   pop ebx
// 004a1a0d  83c40c               add esp, 0xc
// 004a1a10  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

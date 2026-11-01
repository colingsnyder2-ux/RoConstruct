// from server: 100% by auto
// roc 2009-12 00535290  unit: RBX::Network::IdSerializer  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00535290
//
// 00535290  83ec14               sub esp, 0x14
// 00535293  53                   push ebx
// 00535294  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00535298  55                   push ebp
// 00535299  56                   push esi
// 0053529a  8be9                 mov ebp, ecx
// 0053529c  57                   push edi
// 0053529d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005352a0  8b7704               mov esi, dword ptr [edi + 4]
// 005352a3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005352a7  b001                 mov al, 1
// 005352a9  88442410             mov byte ptr [esp + 0x10], al
// 005352ad  7526                 jne 0x5352d5
// 005352af  90                   nop 
// 005352b0  8d460c               lea eax, [esi + 0xc]
// 005352b3  50                   push eax
// 005352b4  53                   push ebx
// 005352b5  8bfe                 mov edi, esi
// 005352b7  ff15d8b59800         call dword ptr [0x98b5d8]
// 005352bd  83c408               add esp, 8
// 005352c0  88442410             mov byte ptr [esp + 0x10], al
// 005352c4  84c0                 test al, al
// 005352c6  7404                 je 0x5352cc
// 005352c8  8b36                 mov esi, dword ptr [esi]
// 005352ca  eb03                 jmp 0x5352cf
// 005352cc  8b7608               mov esi, dword ptr [esi + 8]
// 005352cf  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005352d3  74db                 je 0x5352b0
// 005352d5  8b7500               mov esi, dword ptr [ebp]
// 005352d8  897c2418             mov dword ptr [esp + 0x18], edi
// 005352dc  89742414             mov dword ptr [esp + 0x14], esi
// 005352e0  84c0                 test al, al
// 005352e2  7458                 je 0x53533c
// 005352e4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005352e7  8b11                 mov edx, dword ptr [ecx]
// 005352e9  89542420             mov dword ptr [esp + 0x20], edx
// 005352ed  85f6                 test esi, esi
// 005352ef  7404                 je 0x5352f5
// 005352f1  3bf6                 cmp esi, esi
// 005352f3  7406                 je 0x5352fb
// 005352f5  ff1560b79800         call dword ptr [0x98b760]
// 005352fb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 005352ff  752e                 jne 0x53532f
// 00535301  53                   push ebx
// 00535302  57                   push edi
// 00535303  6a01                 push 1
// 00535305  8d442428             lea eax, [esp + 0x28]
// 00535309  50                   push eax
// 0053530a  8bcd                 mov ecx, ebp
// 0053530c  e8dffbffff           call 0x534ef0
// 00535311  5f                   pop edi
// 00535312  8bc8                 mov ecx, eax
// 00535314  8b11                 mov edx, dword ptr [ecx]
// 00535316  8b442424             mov eax, dword ptr [esp + 0x24]
// 0053531a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0053531d  5e                   pop esi
// 0053531e  5d                   pop ebp
// 0053531f  8910                 mov dword ptr [eax], edx
// 00535321  894804               mov dword ptr [eax + 4], ecx
// 00535324  c6400801             mov byte ptr [eax + 8], 1
// 00535328  5b                   pop ebx
// 00535329  83c414               add esp, 0x14
// 0053532c  c20800               ret 8
// 0053532f  8d4c2414             lea ecx, [esp + 0x14]
// 00535333  e8c8351500           call 0x688900
// 00535338  8b742414             mov esi, dword ptr [esp + 0x14]
// 0053533c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00535340  83c20c               add edx, 0xc
// 00535343  53                   push ebx
// 00535344  52                   push edx
// 00535345  ff15d8b59800         call dword ptr [0x98b5d8]
// 0053534b  83c408               add esp, 8
// 0053534e  84c0                 test al, al
// 00535350  740e                 je 0x535360
// 00535352  8b442410             mov eax, dword ptr [esp + 0x10]
// 00535356  53                   push ebx
// 00535357  57                   push edi
// 00535358  50                   push eax
// 00535359  8d4c2428             lea ecx, [esp + 0x28]
// 0053535d  51                   push ecx
// 0053535e  ebaa                 jmp 0x53530a
// 00535360  8b442428             mov eax, dword ptr [esp + 0x28]
// 00535364  8b542418             mov edx, dword ptr [esp + 0x18]
// 00535368  5f                   pop edi
// 00535369  8930                 mov dword ptr [eax], esi
// 0053536b  5e                   pop esi
// 0053536c  5d                   pop ebp
// 0053536d  895004               mov dword ptr [eax + 4], edx
// 00535370  c6400800             mov byte ptr [eax + 8], 0
// 00535374  5b                   pop ebx
// 00535375  83c414               add esp, 0x14
// 00535378  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

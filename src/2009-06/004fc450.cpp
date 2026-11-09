// from server: 100% by auto
// roc 2009-06 004fc450  unit: RBX::Network::ServerReplicator  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fc450
//
// 004fc450  83ec14               sub esp, 0x14
// 004fc453  53                   push ebx
// 004fc454  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004fc458  55                   push ebp
// 004fc459  56                   push esi
// 004fc45a  8be9                 mov ebp, ecx
// 004fc45c  57                   push edi
// 004fc45d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004fc460  8b7704               mov esi, dword ptr [edi + 4]
// 004fc463  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fc467  b001                 mov al, 1
// 004fc469  88442410             mov byte ptr [esp + 0x10], al
// 004fc46d  7526                 jne 0x4fc495
// 004fc46f  90                   nop 
// 004fc470  8d460c               lea eax, [esi + 0xc]
// 004fc473  50                   push eax
// 004fc474  53                   push ebx
// 004fc475  8bfe                 mov edi, esi
// 004fc477  ff15e0e48900         call dword ptr [0x89e4e0]
// 004fc47d  83c408               add esp, 8
// 004fc480  88442410             mov byte ptr [esp + 0x10], al
// 004fc484  84c0                 test al, al
// 004fc486  7404                 je 0x4fc48c
// 004fc488  8b36                 mov esi, dword ptr [esi]
// 004fc48a  eb03                 jmp 0x4fc48f
// 004fc48c  8b7608               mov esi, dword ptr [esi + 8]
// 004fc48f  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fc493  74db                 je 0x4fc470
// 004fc495  8b7500               mov esi, dword ptr [ebp]
// 004fc498  897c2418             mov dword ptr [esp + 0x18], edi
// 004fc49c  89742414             mov dword ptr [esp + 0x14], esi
// 004fc4a0  84c0                 test al, al
// 004fc4a2  7458                 je 0x4fc4fc
// 004fc4a4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004fc4a7  8b11                 mov edx, dword ptr [ecx]
// 004fc4a9  89542420             mov dword ptr [esp + 0x20], edx
// 004fc4ad  85f6                 test esi, esi
// 004fc4af  7404                 je 0x4fc4b5
// 004fc4b1  3bf6                 cmp esi, esi
// 004fc4b3  7406                 je 0x4fc4bb
// 004fc4b5  ff15ace98900         call dword ptr [0x89e9ac]
// 004fc4bb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004fc4bf  752e                 jne 0x4fc4ef
// 004fc4c1  53                   push ebx
// 004fc4c2  57                   push edi
// 004fc4c3  6a01                 push 1
// 004fc4c5  8d442428             lea eax, [esp + 0x28]
// 004fc4c9  50                   push eax
// 004fc4ca  8bcd                 mov ecx, ebp
// 004fc4cc  e87ffcffff           call 0x4fc150
// 004fc4d1  5f                   pop edi
// 004fc4d2  8bc8                 mov ecx, eax
// 004fc4d4  8b11                 mov edx, dword ptr [ecx]
// 004fc4d6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004fc4da  8b4904               mov ecx, dword ptr [ecx + 4]
// 004fc4dd  5e                   pop esi
// 004fc4de  5d                   pop ebp
// 004fc4df  8910                 mov dword ptr [eax], edx
// 004fc4e1  894804               mov dword ptr [eax + 4], ecx
// 004fc4e4  c6400801             mov byte ptr [eax + 8], 1
// 004fc4e8  5b                   pop ebx
// 004fc4e9  83c414               add esp, 0x14
// 004fc4ec  c20800               ret 8
// 004fc4ef  8d4c2414             lea ecx, [esp + 0x14]
// 004fc4f3  e8b8f5ffff           call 0x4fbab0
// 004fc4f8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004fc4fc  8b542418             mov edx, dword ptr [esp + 0x18]
// 004fc500  83c20c               add edx, 0xc
// 004fc503  53                   push ebx
// 004fc504  52                   push edx
// 004fc505  ff15e0e48900         call dword ptr [0x89e4e0]
// 004fc50b  83c408               add esp, 8
// 004fc50e  84c0                 test al, al
// 004fc510  740e                 je 0x4fc520
// 004fc512  8b442410             mov eax, dword ptr [esp + 0x10]
// 004fc516  53                   push ebx
// 004fc517  57                   push edi
// 004fc518  50                   push eax
// 004fc519  8d4c2428             lea ecx, [esp + 0x28]
// 004fc51d  51                   push ecx
// 004fc51e  ebaa                 jmp 0x4fc4ca
// 004fc520  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fc524  8b542418             mov edx, dword ptr [esp + 0x18]
// 004fc528  5f                   pop edi
// 004fc529  8930                 mov dword ptr [eax], esi
// 004fc52b  5e                   pop esi
// 004fc52c  5d                   pop ebp
// 004fc52d  895004               mov dword ptr [eax + 4], edx
// 004fc530  c6400800             mov byte ptr [eax + 8], 0
// 004fc534  5b                   pop ebx
// 004fc535  83c414               add esp, 0x14
// 004fc538  c20800               ret 8
// standard library map_str<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

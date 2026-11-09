// from server: 100% by auto
// roc 2009-12 006686c0  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006686c0
//
// 006686c0  83ec14               sub esp, 0x14
// 006686c3  53                   push ebx
// 006686c4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006686c8  55                   push ebp
// 006686c9  56                   push esi
// 006686ca  8be9                 mov ebp, ecx
// 006686cc  57                   push edi
// 006686cd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 006686d0  8b7704               mov esi, dword ptr [edi + 4]
// 006686d3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 006686d7  b001                 mov al, 1
// 006686d9  88442410             mov byte ptr [esp + 0x10], al
// 006686dd  7526                 jne 0x668705
// 006686df  90                   nop 
// 006686e0  8d460c               lea eax, [esi + 0xc]
// 006686e3  50                   push eax
// 006686e4  53                   push ebx
// 006686e5  8bfe                 mov edi, esi
// 006686e7  ff15d8b59800         call dword ptr [0x98b5d8]
// 006686ed  83c408               add esp, 8
// 006686f0  88442410             mov byte ptr [esp + 0x10], al
// 006686f4  84c0                 test al, al
// 006686f6  7404                 je 0x6686fc
// 006686f8  8b36                 mov esi, dword ptr [esi]
// 006686fa  eb03                 jmp 0x6686ff
// 006686fc  8b7608               mov esi, dword ptr [esi + 8]
// 006686ff  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00668703  74db                 je 0x6686e0
// 00668705  8b7500               mov esi, dword ptr [ebp]
// 00668708  897c2418             mov dword ptr [esp + 0x18], edi
// 0066870c  89742414             mov dword ptr [esp + 0x14], esi
// 00668710  84c0                 test al, al
// 00668712  7458                 je 0x66876c
// 00668714  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00668717  8b11                 mov edx, dword ptr [ecx]
// 00668719  89542420             mov dword ptr [esp + 0x20], edx
// 0066871d  85f6                 test esi, esi
// 0066871f  7404                 je 0x668725
// 00668721  3bf6                 cmp esi, esi
// 00668723  7406                 je 0x66872b
// 00668725  ff1560b79800         call dword ptr [0x98b760]
// 0066872b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0066872f  752e                 jne 0x66875f
// 00668731  53                   push ebx
// 00668732  57                   push edi
// 00668733  6a01                 push 1
// 00668735  8d442428             lea eax, [esp + 0x28]
// 00668739  50                   push eax
// 0066873a  8bcd                 mov ecx, ebp
// 0066873c  e87ff3ffff           call 0x667ac0
// 00668741  5f                   pop edi
// 00668742  8bc8                 mov ecx, eax
// 00668744  8b11                 mov edx, dword ptr [ecx]
// 00668746  8b442424             mov eax, dword ptr [esp + 0x24]
// 0066874a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066874d  5e                   pop esi
// 0066874e  5d                   pop ebp
// 0066874f  8910                 mov dword ptr [eax], edx
// 00668751  894804               mov dword ptr [eax + 4], ecx
// 00668754  c6400801             mov byte ptr [eax + 8], 1
// 00668758  5b                   pop ebx
// 00668759  83c414               add esp, 0x14
// 0066875c  c20800               ret 8
// 0066875f  8d4c2414             lea ecx, [esp + 0x14]
// 00668763  e898010200           call 0x688900
// 00668768  8b742414             mov esi, dword ptr [esp + 0x14]
// 0066876c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00668770  83c20c               add edx, 0xc
// 00668773  53                   push ebx
// 00668774  52                   push edx
// 00668775  ff15d8b59800         call dword ptr [0x98b5d8]
// 0066877b  83c408               add esp, 8
// 0066877e  84c0                 test al, al
// 00668780  740e                 je 0x668790
// 00668782  8b442410             mov eax, dword ptr [esp + 0x10]
// 00668786  53                   push ebx
// 00668787  57                   push edi
// 00668788  50                   push eax
// 00668789  8d4c2428             lea ecx, [esp + 0x28]
// 0066878d  51                   push ecx
// 0066878e  ebaa                 jmp 0x66873a
// 00668790  8b442428             mov eax, dword ptr [esp + 0x28]
// 00668794  8b542418             mov edx, dword ptr [esp + 0x18]
// 00668798  5f                   pop edi
// 00668799  8930                 mov dword ptr [eax], esi
// 0066879b  5e                   pop esi
// 0066879c  5d                   pop ebp
// 0066879d  895004               mov dword ptr [eax + 4], edx
// 006687a0  c6400800             mov byte ptr [eax + 8], 0
// 006687a4  5b                   pop ebx
// 006687a5  83c414               add esp, 0x14
// 006687a8  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

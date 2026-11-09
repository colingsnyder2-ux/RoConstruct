// from server: 100% by auto
// roc 2009-06 005dc420  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005dc420
//
// 005dc420  83ec14               sub esp, 0x14
// 005dc423  53                   push ebx
// 005dc424  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005dc428  55                   push ebp
// 005dc429  56                   push esi
// 005dc42a  8be9                 mov ebp, ecx
// 005dc42c  57                   push edi
// 005dc42d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005dc430  8b7704               mov esi, dword ptr [edi + 4]
// 005dc433  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005dc437  b001                 mov al, 1
// 005dc439  88442410             mov byte ptr [esp + 0x10], al
// 005dc43d  7526                 jne 0x5dc465
// 005dc43f  90                   nop 
// 005dc440  8d460c               lea eax, [esi + 0xc]
// 005dc443  50                   push eax
// 005dc444  53                   push ebx
// 005dc445  8bfe                 mov edi, esi
// 005dc447  ff15e0e48900         call dword ptr [0x89e4e0]
// 005dc44d  83c408               add esp, 8
// 005dc450  88442410             mov byte ptr [esp + 0x10], al
// 005dc454  84c0                 test al, al
// 005dc456  7404                 je 0x5dc45c
// 005dc458  8b36                 mov esi, dword ptr [esi]
// 005dc45a  eb03                 jmp 0x5dc45f
// 005dc45c  8b7608               mov esi, dword ptr [esi + 8]
// 005dc45f  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005dc463  74db                 je 0x5dc440
// 005dc465  8b7500               mov esi, dword ptr [ebp]
// 005dc468  897c2418             mov dword ptr [esp + 0x18], edi
// 005dc46c  89742414             mov dword ptr [esp + 0x14], esi
// 005dc470  84c0                 test al, al
// 005dc472  7458                 je 0x5dc4cc
// 005dc474  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005dc477  8b11                 mov edx, dword ptr [ecx]
// 005dc479  89542420             mov dword ptr [esp + 0x20], edx
// 005dc47d  85f6                 test esi, esi
// 005dc47f  7404                 je 0x5dc485
// 005dc481  3bf6                 cmp esi, esi
// 005dc483  7406                 je 0x5dc48b
// 005dc485  ff15ace98900         call dword ptr [0x89e9ac]
// 005dc48b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 005dc48f  752e                 jne 0x5dc4bf
// 005dc491  53                   push ebx
// 005dc492  57                   push edi
// 005dc493  6a01                 push 1
// 005dc495  8d442428             lea eax, [esp + 0x28]
// 005dc499  50                   push eax
// 005dc49a  8bcd                 mov ecx, ebp
// 005dc49c  e83ff3ffff           call 0x5db7e0
// 005dc4a1  5f                   pop edi
// 005dc4a2  8bc8                 mov ecx, eax
// 005dc4a4  8b11                 mov edx, dword ptr [ecx]
// 005dc4a6  8b442424             mov eax, dword ptr [esp + 0x24]
// 005dc4aa  8b4904               mov ecx, dword ptr [ecx + 4]
// 005dc4ad  5e                   pop esi
// 005dc4ae  5d                   pop ebp
// 005dc4af  8910                 mov dword ptr [eax], edx
// 005dc4b1  894804               mov dword ptr [eax + 4], ecx
// 005dc4b4  c6400801             mov byte ptr [eax + 8], 1
// 005dc4b8  5b                   pop ebx
// 005dc4b9  83c414               add esp, 0x14
// 005dc4bc  c20800               ret 8
// 005dc4bf  8d4c2414             lea ecx, [esp + 0x14]
// 005dc4c3  e8d8cbffff           call 0x5d90a0
// 005dc4c8  8b742414             mov esi, dword ptr [esp + 0x14]
// 005dc4cc  8b542418             mov edx, dword ptr [esp + 0x18]
// 005dc4d0  83c20c               add edx, 0xc
// 005dc4d3  53                   push ebx
// 005dc4d4  52                   push edx
// 005dc4d5  ff15e0e48900         call dword ptr [0x89e4e0]
// 005dc4db  83c408               add esp, 8
// 005dc4de  84c0                 test al, al
// 005dc4e0  740e                 je 0x5dc4f0
// 005dc4e2  8b442410             mov eax, dword ptr [esp + 0x10]
// 005dc4e6  53                   push ebx
// 005dc4e7  57                   push edi
// 005dc4e8  50                   push eax
// 005dc4e9  8d4c2428             lea ecx, [esp + 0x28]
// 005dc4ed  51                   push ecx
// 005dc4ee  ebaa                 jmp 0x5dc49a
// 005dc4f0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005dc4f4  8b542418             mov edx, dword ptr [esp + 0x18]
// 005dc4f8  5f                   pop edi
// 005dc4f9  8930                 mov dword ptr [eax], esi
// 005dc4fb  5e                   pop esi
// 005dc4fc  5d                   pop ebp
// 005dc4fd  895004               mov dword ptr [eax + 4], edx
// 005dc500  c6400800             mov byte ptr [eax + 8], 0
// 005dc504  5b                   pop ebx
// 005dc505  83c414               add esp, 0x14
// 005dc508  c20800               ret 8
// standard library map_str<pod20> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

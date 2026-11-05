// from server: 100% by auto
// roc 2009-06 006e4570  unit: RBX::ScoreHud  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e4570
//
// 006e4570  83ec14               sub esp, 0x14
// 006e4573  53                   push ebx
// 006e4574  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006e4578  55                   push ebp
// 006e4579  56                   push esi
// 006e457a  8be9                 mov ebp, ecx
// 006e457c  57                   push edi
// 006e457d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 006e4580  8b7704               mov esi, dword ptr [edi + 4]
// 006e4583  807e4900             cmp byte ptr [esi + 0x49], 0
// 006e4587  b001                 mov al, 1
// 006e4589  88442410             mov byte ptr [esp + 0x10], al
// 006e458d  7526                 jne 0x6e45b5
// 006e458f  90                   nop 
// 006e4590  8d460c               lea eax, [esi + 0xc]
// 006e4593  50                   push eax
// 006e4594  53                   push ebx
// 006e4595  8bfe                 mov edi, esi
// 006e4597  ff15e0e48900         call dword ptr [0x89e4e0]
// 006e459d  83c408               add esp, 8
// 006e45a0  88442410             mov byte ptr [esp + 0x10], al
// 006e45a4  84c0                 test al, al
// 006e45a6  7404                 je 0x6e45ac
// 006e45a8  8b36                 mov esi, dword ptr [esi]
// 006e45aa  eb03                 jmp 0x6e45af
// 006e45ac  8b7608               mov esi, dword ptr [esi + 8]
// 006e45af  807e4900             cmp byte ptr [esi + 0x49], 0
// 006e45b3  74db                 je 0x6e4590
// 006e45b5  8b7500               mov esi, dword ptr [ebp]
// 006e45b8  897c2418             mov dword ptr [esp + 0x18], edi
// 006e45bc  89742414             mov dword ptr [esp + 0x14], esi
// 006e45c0  84c0                 test al, al
// 006e45c2  7458                 je 0x6e461c
// 006e45c4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006e45c7  8b11                 mov edx, dword ptr [ecx]
// 006e45c9  89542420             mov dword ptr [esp + 0x20], edx
// 006e45cd  85f6                 test esi, esi
// 006e45cf  7404                 je 0x6e45d5
// 006e45d1  3bf6                 cmp esi, esi
// 006e45d3  7406                 je 0x6e45db
// 006e45d5  ff15ace98900         call dword ptr [0x89e9ac]
// 006e45db  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 006e45df  752e                 jne 0x6e460f
// 006e45e1  53                   push ebx
// 006e45e2  57                   push edi
// 006e45e3  6a01                 push 1
// 006e45e5  8d442428             lea eax, [esp + 0x28]
// 006e45e9  50                   push eax
// 006e45ea  8bcd                 mov ecx, ebp
// 006e45ec  e85ff4ffff           call 0x6e3a50
// 006e45f1  5f                   pop edi
// 006e45f2  8bc8                 mov ecx, eax
// 006e45f4  8b11                 mov edx, dword ptr [ecx]
// 006e45f6  8b442424             mov eax, dword ptr [esp + 0x24]
// 006e45fa  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e45fd  5e                   pop esi
// 006e45fe  5d                   pop ebp
// 006e45ff  8910                 mov dword ptr [eax], edx
// 006e4601  894804               mov dword ptr [eax + 4], ecx
// 006e4604  c6400801             mov byte ptr [eax + 8], 1
// 006e4608  5b                   pop ebx
// 006e4609  83c414               add esp, 0x14
// 006e460c  c20800               ret 8
// 006e460f  8d4c2414             lea ecx, [esp + 0x14]
// 006e4613  e808dcffff           call 0x6e2220
// 006e4618  8b742414             mov esi, dword ptr [esp + 0x14]
// 006e461c  8b542418             mov edx, dword ptr [esp + 0x18]
// 006e4620  83c20c               add edx, 0xc
// 006e4623  53                   push ebx
// 006e4624  52                   push edx
// 006e4625  ff15e0e48900         call dword ptr [0x89e4e0]
// 006e462b  83c408               add esp, 8
// 006e462e  84c0                 test al, al
// 006e4630  740e                 je 0x6e4640
// 006e4632  8b442410             mov eax, dword ptr [esp + 0x10]
// 006e4636  53                   push ebx
// 006e4637  57                   push edi
// 006e4638  50                   push eax
// 006e4639  8d4c2428             lea ecx, [esp + 0x28]
// 006e463d  51                   push ecx
// 006e463e  ebaa                 jmp 0x6e45ea
// 006e4640  8b442428             mov eax, dword ptr [esp + 0x28]
// 006e4644  8b542418             mov edx, dword ptr [esp + 0x18]
// 006e4648  5f                   pop edi
// 006e4649  8930                 mov dword ptr [eax], esi
// 006e464b  5e                   pop esi
// 006e464c  5d                   pop ebp
// 006e464d  895004               mov dword ptr [eax + 4], edx
// 006e4650  c6400800             mov byte ptr [eax + 8], 0
// 006e4654  5b                   pop ebx
// 006e4655  83c414               add esp, 0x14
// 006e4658  c20800               ret 8
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

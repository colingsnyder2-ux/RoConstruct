// from server: 100% by auto
// roc 2009-12 007c4390  unit: RBX::ChatOutput  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c4390
//
// 007c4390  83ec14               sub esp, 0x14
// 007c4393  53                   push ebx
// 007c4394  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007c4398  55                   push ebp
// 007c4399  56                   push esi
// 007c439a  8be9                 mov ebp, ecx
// 007c439c  57                   push edi
// 007c439d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 007c43a0  8b7704               mov esi, dword ptr [edi + 4]
// 007c43a3  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 007c43a7  b001                 mov al, 1
// 007c43a9  88442410             mov byte ptr [esp + 0x10], al
// 007c43ad  7526                 jne 0x7c43d5
// 007c43af  90                   nop 
// 007c43b0  8d460c               lea eax, [esi + 0xc]
// 007c43b3  50                   push eax
// 007c43b4  53                   push ebx
// 007c43b5  8bfe                 mov edi, esi
// 007c43b7  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c43bd  83c408               add esp, 8
// 007c43c0  88442410             mov byte ptr [esp + 0x10], al
// 007c43c4  84c0                 test al, al
// 007c43c6  7404                 je 0x7c43cc
// 007c43c8  8b36                 mov esi, dword ptr [esi]
// 007c43ca  eb03                 jmp 0x7c43cf
// 007c43cc  8b7608               mov esi, dword ptr [esi + 8]
// 007c43cf  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 007c43d3  74db                 je 0x7c43b0
// 007c43d5  8b7500               mov esi, dword ptr [ebp]
// 007c43d8  897c2418             mov dword ptr [esp + 0x18], edi
// 007c43dc  89742414             mov dword ptr [esp + 0x14], esi
// 007c43e0  84c0                 test al, al
// 007c43e2  7458                 je 0x7c443c
// 007c43e4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007c43e7  8b11                 mov edx, dword ptr [ecx]
// 007c43e9  89542420             mov dword ptr [esp + 0x20], edx
// 007c43ed  85f6                 test esi, esi
// 007c43ef  7404                 je 0x7c43f5
// 007c43f1  3bf6                 cmp esi, esi
// 007c43f3  7406                 je 0x7c43fb
// 007c43f5  ff1560b79800         call dword ptr [0x98b760]
// 007c43fb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 007c43ff  752e                 jne 0x7c442f
// 007c4401  53                   push ebx
// 007c4402  57                   push edi
// 007c4403  6a01                 push 1
// 007c4405  8d442428             lea eax, [esp + 0x28]
// 007c4409  50                   push eax
// 007c440a  8bcd                 mov ecx, ebp
// 007c440c  e8cff1ffff           call 0x7c35e0
// 007c4411  5f                   pop edi
// 007c4412  8bc8                 mov ecx, eax
// 007c4414  8b11                 mov edx, dword ptr [ecx]
// 007c4416  8b442424             mov eax, dword ptr [esp + 0x24]
// 007c441a  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c441d  5e                   pop esi
// 007c441e  5d                   pop ebp
// 007c441f  8910                 mov dword ptr [eax], edx
// 007c4421  894804               mov dword ptr [eax + 4], ecx
// 007c4424  c6400801             mov byte ptr [eax + 8], 1
// 007c4428  5b                   pop ebx
// 007c4429  83c414               add esp, 0x14
// 007c442c  c20800               ret 8
// 007c442f  8d4c2414             lea ecx, [esp + 0x14]
// 007c4433  e8a8daffff           call 0x7c1ee0
// 007c4438  8b742414             mov esi, dword ptr [esp + 0x14]
// 007c443c  8b542418             mov edx, dword ptr [esp + 0x18]
// 007c4440  83c20c               add edx, 0xc
// 007c4443  53                   push ebx
// 007c4444  52                   push edx
// 007c4445  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c444b  83c408               add esp, 8
// 007c444e  84c0                 test al, al
// 007c4450  740e                 je 0x7c4460
// 007c4452  8b442410             mov eax, dword ptr [esp + 0x10]
// 007c4456  53                   push ebx
// 007c4457  57                   push edi
// 007c4458  50                   push eax
// 007c4459  8d4c2428             lea ecx, [esp + 0x28]
// 007c445d  51                   push ecx
// 007c445e  ebaa                 jmp 0x7c440a
// 007c4460  8b442428             mov eax, dword ptr [esp + 0x28]
// 007c4464  8b542418             mov edx, dword ptr [esp + 0x18]
// 007c4468  5f                   pop edi
// 007c4469  8930                 mov dword ptr [eax], esi
// 007c446b  5e                   pop esi
// 007c446c  5d                   pop ebp
// 007c446d  895004               mov dword ptr [eax + 4], edx
// 007c4470  c6400800             mov byte ptr [eax + 8], 0
// 007c4474  5b                   pop ebx
// 007c4475  83c414               add esp, 0x14
// 007c4478  c20800               ret 8
// standard library map_str<pod36> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

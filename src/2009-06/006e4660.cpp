// from server: 100% by auto
// roc 2009-06 006e4660  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e4660
//
// 006e4660  83ec0c               sub esp, 0xc
// 006e4663  53                   push ebx
// 006e4664  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006e4668  55                   push ebp
// 006e4669  56                   push esi
// 006e466a  57                   push edi
// 006e466b  8bf9                 mov edi, ecx
// 006e466d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006e4670  8b4604               mov eax, dword ptr [esi + 4]
// 006e4673  80783100             cmp byte ptr [eax + 0x31], 0
// 006e4677  b101                 mov cl, 1
// 006e4679  884c2410             mov byte ptr [esp + 0x10], cl
// 006e467d  751f                 jne 0x6e469e
// 006e467f  8b13                 mov edx, dword ptr [ebx]
// 006e4681  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006e4684  8bf0                 mov esi, eax
// 006e4686  0f92c1               setb cl
// 006e4689  884c2410             mov byte ptr [esp + 0x10], cl
// 006e468d  84c9                 test cl, cl
// 006e468f  7404                 je 0x6e4695
// 006e4691  8b00                 mov eax, dword ptr [eax]
// 006e4693  eb03                 jmp 0x6e4698
// 006e4695  8b4008               mov eax, dword ptr [eax + 8]
// 006e4698  80783100             cmp byte ptr [eax + 0x31], 0
// 006e469c  74e3                 je 0x6e4681
// 006e469e  8b17                 mov edx, dword ptr [edi]
// 006e46a0  8bee                 mov ebp, esi
// 006e46a2  896c2418             mov dword ptr [esp + 0x18], ebp
// 006e46a6  89542414             mov dword ptr [esp + 0x14], edx
// 006e46aa  84c9                 test cl, cl
// 006e46ac  7452                 je 0x6e4700
// 006e46ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e46b1  8b28                 mov ebp, dword ptr [eax]
// 006e46b3  85d2                 test edx, edx
// 006e46b5  7404                 je 0x6e46bb
// 006e46b7  3bd2                 cmp edx, edx
// 006e46b9  7406                 je 0x6e46c1
// 006e46bb  ff15ace98900         call dword ptr [0x89e9ac]
// 006e46c1  8d4c2414             lea ecx, [esp + 0x14]
// 006e46c5  3bf5                 cmp esi, ebp
// 006e46c7  752a                 jne 0x6e46f3
// 006e46c9  53                   push ebx
// 006e46ca  56                   push esi
// 006e46cb  6a01                 push 1
// 006e46cd  51                   push ecx
// 006e46ce  8bcf                 mov ecx, edi
// 006e46d0  e87bf5ffff           call 0x6e3c50
// 006e46d5  5f                   pop edi
// 006e46d6  8bc8                 mov ecx, eax
// 006e46d8  8b11                 mov edx, dword ptr [ecx]
// 006e46da  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e46de  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e46e1  5e                   pop esi
// 006e46e2  5d                   pop ebp
// 006e46e3  894804               mov dword ptr [eax + 4], ecx
// 006e46e6  c6400801             mov byte ptr [eax + 8], 1
// 006e46ea  8910                 mov dword ptr [eax], edx
// 006e46ec  5b                   pop ebx
// 006e46ed  83c40c               add esp, 0xc
// 006e46f0  c20800               ret 8
// 006e46f3  e8b8ecf3ff           call 0x6233b0
// 006e46f8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006e46fc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006e4700  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006e4703  3b03                 cmp eax, dword ptr [ebx]
// 006e4705  7331                 jae 0x6e4738
// 006e4707  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006e470b  53                   push ebx
// 006e470c  56                   push esi
// 006e470d  51                   push ecx
// 006e470e  8d542420             lea edx, [esp + 0x20]
// 006e4712  52                   push edx
// 006e4713  8bcf                 mov ecx, edi
// 006e4715  e836f5ffff           call 0x6e3c50
// 006e471a  5f                   pop edi
// 006e471b  8bc8                 mov ecx, eax
// 006e471d  8b11                 mov edx, dword ptr [ecx]
// 006e471f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e4723  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e4726  5e                   pop esi
// 006e4727  5d                   pop ebp
// 006e4728  894804               mov dword ptr [eax + 4], ecx
// 006e472b  c6400801             mov byte ptr [eax + 8], 1
// 006e472f  8910                 mov dword ptr [eax], edx
// 006e4731  5b                   pop ebx
// 006e4732  83c40c               add esp, 0xc
// 006e4735  c20800               ret 8
// 006e4738  8b442420             mov eax, dword ptr [esp + 0x20]
// 006e473c  5f                   pop edi
// 006e473d  5e                   pop esi
// 006e473e  896804               mov dword ptr [eax + 4], ebp
// 006e4741  5d                   pop ebp
// 006e4742  c6400800             mov byte ptr [eax + 8], 0
// 006e4746  8910                 mov dword ptr [eax], edx
// 006e4748  5b                   pop ebx
// 006e4749  83c40c               add esp, 0xc
// 006e474c  c20800               ret 8
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;

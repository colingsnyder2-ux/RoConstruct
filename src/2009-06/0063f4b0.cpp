// from server: 100% by auto
// roc 2009-06 0063f4b0  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f4b0
//
// 0063f4b0  83ec0c               sub esp, 0xc
// 0063f4b3  53                   push ebx
// 0063f4b4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0063f4b8  55                   push ebp
// 0063f4b9  56                   push esi
// 0063f4ba  57                   push edi
// 0063f4bb  8bf9                 mov edi, ecx
// 0063f4bd  8b7718               mov esi, dword ptr [edi + 0x18]
// 0063f4c0  8b4604               mov eax, dword ptr [esi + 4]
// 0063f4c3  80782100             cmp byte ptr [eax + 0x21], 0
// 0063f4c7  b101                 mov cl, 1
// 0063f4c9  884c2410             mov byte ptr [esp + 0x10], cl
// 0063f4cd  751f                 jne 0x63f4ee
// 0063f4cf  8b13                 mov edx, dword ptr [ebx]
// 0063f4d1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0063f4d4  8bf0                 mov esi, eax
// 0063f4d6  0f9cc1               setl cl
// 0063f4d9  884c2410             mov byte ptr [esp + 0x10], cl
// 0063f4dd  84c9                 test cl, cl
// 0063f4df  7404                 je 0x63f4e5
// 0063f4e1  8b00                 mov eax, dword ptr [eax]
// 0063f4e3  eb03                 jmp 0x63f4e8
// 0063f4e5  8b4008               mov eax, dword ptr [eax + 8]
// 0063f4e8  80782100             cmp byte ptr [eax + 0x21], 0
// 0063f4ec  74e3                 je 0x63f4d1
// 0063f4ee  8b17                 mov edx, dword ptr [edi]
// 0063f4f0  8bee                 mov ebp, esi
// 0063f4f2  896c2418             mov dword ptr [esp + 0x18], ebp
// 0063f4f6  89542414             mov dword ptr [esp + 0x14], edx
// 0063f4fa  84c9                 test cl, cl
// 0063f4fc  7452                 je 0x63f550
// 0063f4fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063f501  8b28                 mov ebp, dword ptr [eax]
// 0063f503  85d2                 test edx, edx
// 0063f505  7404                 je 0x63f50b
// 0063f507  3bd2                 cmp edx, edx
// 0063f509  7406                 je 0x63f511
// 0063f50b  ff15ace98900         call dword ptr [0x89e9ac]
// 0063f511  8d4c2414             lea ecx, [esp + 0x14]
// 0063f515  3bf5                 cmp esi, ebp
// 0063f517  752a                 jne 0x63f543
// 0063f519  53                   push ebx
// 0063f51a  56                   push esi
// 0063f51b  6a01                 push 1
// 0063f51d  51                   push ecx
// 0063f51e  8bcf                 mov ecx, edi
// 0063f520  e8ebf6ffff           call 0x63ec10
// 0063f525  5f                   pop edi
// 0063f526  8bc8                 mov ecx, eax
// 0063f528  8b11                 mov edx, dword ptr [ecx]
// 0063f52a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063f52e  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063f531  5e                   pop esi
// 0063f532  5d                   pop ebp
// 0063f533  894804               mov dword ptr [eax + 4], ecx
// 0063f536  c6400801             mov byte ptr [eax + 8], 1
// 0063f53a  8910                 mov dword ptr [eax], edx
// 0063f53c  5b                   pop ebx
// 0063f53d  83c40c               add esp, 0xc
// 0063f540  c20800               ret 8
// 0063f543  e84882edff           call 0x517790
// 0063f548  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0063f54c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0063f550  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0063f553  3b03                 cmp eax, dword ptr [ebx]
// 0063f555  7d31                 jge 0x63f588
// 0063f557  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063f55b  53                   push ebx
// 0063f55c  56                   push esi
// 0063f55d  51                   push ecx
// 0063f55e  8d542420             lea edx, [esp + 0x20]
// 0063f562  52                   push edx
// 0063f563  8bcf                 mov ecx, edi
// 0063f565  e8a6f6ffff           call 0x63ec10
// 0063f56a  5f                   pop edi
// 0063f56b  8bc8                 mov ecx, eax
// 0063f56d  8b11                 mov edx, dword ptr [ecx]
// 0063f56f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063f573  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063f576  5e                   pop esi
// 0063f577  5d                   pop ebp
// 0063f578  894804               mov dword ptr [eax + 4], ecx
// 0063f57b  c6400801             mov byte ptr [eax + 8], 1
// 0063f57f  8910                 mov dword ptr [eax], edx
// 0063f581  5b                   pop ebx
// 0063f582  83c40c               add esp, 0xc
// 0063f585  c20800               ret 8
// 0063f588  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063f58c  5f                   pop edi
// 0063f58d  5e                   pop esi
// 0063f58e  896804               mov dword ptr [eax + 4], ebp
// 0063f591  5d                   pop ebp
// 0063f592  c6400800             mov byte ptr [eax + 8], 0
// 0063f596  8910                 mov dword ptr [eax], edx
// 0063f598  5b                   pop ebx
// 0063f599  83c40c               add esp, 0xc
// 0063f59c  c20800               ret 8
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;

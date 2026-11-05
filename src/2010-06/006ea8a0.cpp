// from server: 100% by auto
// roc 2010-06 006ea8a0  unit: RBX::VBadgeService::?$BoundFuncDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ea8a0
//
// 006ea8a0  83ec0c               sub esp, 0xc
// 006ea8a3  53                   push ebx
// 006ea8a4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006ea8a8  55                   push ebp
// 006ea8a9  56                   push esi
// 006ea8aa  57                   push edi
// 006ea8ab  8bf9                 mov edi, ecx
// 006ea8ad  8b7718               mov esi, dword ptr [edi + 0x18]
// 006ea8b0  8b4604               mov eax, dword ptr [esi + 4]
// 006ea8b3  80783100             cmp byte ptr [eax + 0x31], 0
// 006ea8b7  b101                 mov cl, 1
// 006ea8b9  884c2410             mov byte ptr [esp + 0x10], cl
// 006ea8bd  751f                 jne 0x6ea8de
// 006ea8bf  8b13                 mov edx, dword ptr [ebx]
// 006ea8c1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006ea8c4  8bf0                 mov esi, eax
// 006ea8c6  0f9cc1               setl cl
// 006ea8c9  884c2410             mov byte ptr [esp + 0x10], cl
// 006ea8cd  84c9                 test cl, cl
// 006ea8cf  7404                 je 0x6ea8d5
// 006ea8d1  8b00                 mov eax, dword ptr [eax]
// 006ea8d3  eb03                 jmp 0x6ea8d8
// 006ea8d5  8b4008               mov eax, dword ptr [eax + 8]
// 006ea8d8  80783100             cmp byte ptr [eax + 0x31], 0
// 006ea8dc  74e3                 je 0x6ea8c1
// 006ea8de  8b17                 mov edx, dword ptr [edi]
// 006ea8e0  8bee                 mov ebp, esi
// 006ea8e2  896c2418             mov dword ptr [esp + 0x18], ebp
// 006ea8e6  89542414             mov dword ptr [esp + 0x14], edx
// 006ea8ea  84c9                 test cl, cl
// 006ea8ec  7452                 je 0x6ea940
// 006ea8ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ea8f1  8b28                 mov ebp, dword ptr [eax]
// 006ea8f3  85d2                 test edx, edx
// 006ea8f5  7404                 je 0x6ea8fb
// 006ea8f7  3bd2                 cmp edx, edx
// 006ea8f9  7406                 je 0x6ea901
// 006ea8fb  ff150ca99e00         call dword ptr [0x9ea90c]
// 006ea901  8d4c2414             lea ecx, [esp + 0x14]
// 006ea905  3bf5                 cmp esi, ebp
// 006ea907  752a                 jne 0x6ea933
// 006ea909  53                   push ebx
// 006ea90a  56                   push esi
// 006ea90b  6a01                 push 1
// 006ea90d  51                   push ecx
// 006ea90e  8bcf                 mov ecx, edi
// 006ea910  e8cbf0ffff           call 0x6e99e0
// 006ea915  5f                   pop edi
// 006ea916  8bc8                 mov ecx, eax
// 006ea918  8b11                 mov edx, dword ptr [ecx]
// 006ea91a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ea91e  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ea921  5e                   pop esi
// 006ea922  5d                   pop ebp
// 006ea923  894804               mov dword ptr [eax + 4], ecx
// 006ea926  c6400801             mov byte ptr [eax + 8], 1
// 006ea92a  8910                 mov dword ptr [eax], edx
// 006ea92c  5b                   pop ebx
// 006ea92d  83c40c               add esp, 0xc
// 006ea930  c20800               ret 8
// 006ea933  e8a88bd8ff           call 0x4734e0
// 006ea938  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006ea93c  8b542414             mov edx, dword ptr [esp + 0x14]
// 006ea940  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006ea943  3b03                 cmp eax, dword ptr [ebx]
// 006ea945  7d31                 jge 0x6ea978
// 006ea947  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ea94b  53                   push ebx
// 006ea94c  56                   push esi
// 006ea94d  51                   push ecx
// 006ea94e  8d542420             lea edx, [esp + 0x20]
// 006ea952  52                   push edx
// 006ea953  8bcf                 mov ecx, edi
// 006ea955  e886f0ffff           call 0x6e99e0
// 006ea95a  5f                   pop edi
// 006ea95b  8bc8                 mov ecx, eax
// 006ea95d  8b11                 mov edx, dword ptr [ecx]
// 006ea95f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ea963  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ea966  5e                   pop esi
// 006ea967  5d                   pop ebp
// 006ea968  894804               mov dword ptr [eax + 4], ecx
// 006ea96b  c6400801             mov byte ptr [eax + 8], 1
// 006ea96f  8910                 mov dword ptr [eax], edx
// 006ea971  5b                   pop ebx
// 006ea972  83c40c               add esp, 0xc
// 006ea975  c20800               ret 8
// 006ea978  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ea97c  5f                   pop edi
// 006ea97d  5e                   pop esi
// 006ea97e  896804               mov dword ptr [eax + 4], ebp
// 006ea981  5d                   pop ebp
// 006ea982  c6400800             mov byte ptr [eax + 8], 0
// 006ea986  8910                 mov dword ptr [eax], edx
// 006ea988  5b                   pop ebx
// 006ea989  83c40c               add esp, 0xc
// 006ea98c  c20800               ret 8
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;

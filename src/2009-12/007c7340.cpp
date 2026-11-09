// from server: 100% by auto
// roc 2009-12 007c7340  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c7340
//
// 007c7340  83ec0c               sub esp, 0xc
// 007c7343  53                   push ebx
// 007c7344  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007c7348  55                   push ebp
// 007c7349  56                   push esi
// 007c734a  57                   push edi
// 007c734b  8bf9                 mov edi, ecx
// 007c734d  8b7718               mov esi, dword ptr [edi + 0x18]
// 007c7350  8b4604               mov eax, dword ptr [esi + 4]
// 007c7353  80782900             cmp byte ptr [eax + 0x29], 0
// 007c7357  b101                 mov cl, 1
// 007c7359  884c2410             mov byte ptr [esp + 0x10], cl
// 007c735d  751f                 jne 0x7c737e
// 007c735f  8b13                 mov edx, dword ptr [ebx]
// 007c7361  3b500c               cmp edx, dword ptr [eax + 0xc]
// 007c7364  8bf0                 mov esi, eax
// 007c7366  0f92c1               setb cl
// 007c7369  884c2410             mov byte ptr [esp + 0x10], cl
// 007c736d  84c9                 test cl, cl
// 007c736f  7404                 je 0x7c7375
// 007c7371  8b00                 mov eax, dword ptr [eax]
// 007c7373  eb03                 jmp 0x7c7378
// 007c7375  8b4008               mov eax, dword ptr [eax + 8]
// 007c7378  80782900             cmp byte ptr [eax + 0x29], 0
// 007c737c  74e3                 je 0x7c7361
// 007c737e  8b17                 mov edx, dword ptr [edi]
// 007c7380  8bee                 mov ebp, esi
// 007c7382  896c2418             mov dword ptr [esp + 0x18], ebp
// 007c7386  89542414             mov dword ptr [esp + 0x14], edx
// 007c738a  84c9                 test cl, cl
// 007c738c  7452                 je 0x7c73e0
// 007c738e  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7391  8b28                 mov ebp, dword ptr [eax]
// 007c7393  85d2                 test edx, edx
// 007c7395  7404                 je 0x7c739b
// 007c7397  3bd2                 cmp edx, edx
// 007c7399  7406                 je 0x7c73a1
// 007c739b  ff1560b79800         call dword ptr [0x98b760]
// 007c73a1  8d4c2414             lea ecx, [esp + 0x14]
// 007c73a5  3bf5                 cmp esi, ebp
// 007c73a7  752a                 jne 0x7c73d3
// 007c73a9  53                   push ebx
// 007c73aa  56                   push esi
// 007c73ab  6a01                 push 1
// 007c73ad  51                   push ecx
// 007c73ae  8bcf                 mov ecx, edi
// 007c73b0  e83bfaffff           call 0x7c6df0
// 007c73b5  5f                   pop edi
// 007c73b6  8bc8                 mov ecx, eax
// 007c73b8  8b11                 mov edx, dword ptr [ecx]
// 007c73ba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c73be  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c73c1  5e                   pop esi
// 007c73c2  5d                   pop ebp
// 007c73c3  894804               mov dword ptr [eax + 4], ecx
// 007c73c6  c6400801             mov byte ptr [eax + 8], 1
// 007c73ca  8910                 mov dword ptr [eax], edx
// 007c73cc  5b                   pop ebx
// 007c73cd  83c40c               add esp, 0xc
// 007c73d0  c20800               ret 8
// 007c73d3  e8f85de0ff           call 0x5cd1d0
// 007c73d8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007c73dc  8b542414             mov edx, dword ptr [esp + 0x14]
// 007c73e0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007c73e3  3b03                 cmp eax, dword ptr [ebx]
// 007c73e5  7331                 jae 0x7c7418
// 007c73e7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c73eb  53                   push ebx
// 007c73ec  56                   push esi
// 007c73ed  51                   push ecx
// 007c73ee  8d542420             lea edx, [esp + 0x20]
// 007c73f2  52                   push edx
// 007c73f3  8bcf                 mov ecx, edi
// 007c73f5  e8f6f9ffff           call 0x7c6df0
// 007c73fa  5f                   pop edi
// 007c73fb  8bc8                 mov ecx, eax
// 007c73fd  8b11                 mov edx, dword ptr [ecx]
// 007c73ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c7403  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c7406  5e                   pop esi
// 007c7407  5d                   pop ebp
// 007c7408  894804               mov dword ptr [eax + 4], ecx
// 007c740b  c6400801             mov byte ptr [eax + 8], 1
// 007c740f  8910                 mov dword ptr [eax], edx
// 007c7411  5b                   pop ebx
// 007c7412  83c40c               add esp, 0xc
// 007c7415  c20800               ret 8
// 007c7418  8b442420             mov eax, dword ptr [esp + 0x20]
// 007c741c  5f                   pop edi
// 007c741d  5e                   pop esi
// 007c741e  896804               mov dword ptr [eax + 4], ebp
// 007c7421  5d                   pop ebp
// 007c7422  c6400800             mov byte ptr [eax + 8], 0
// 007c7426  8910                 mov dword ptr [eax], edx
// 007c7428  5b                   pop ebx
// 007c7429  83c40c               add esp, 0xc
// 007c742c  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;

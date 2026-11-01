// from server: 100% by auto
// roc 2009-12 00434730  unit: CPropGrid::UpdateItemsJob  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00434730
//
// 00434730  83ec0c               sub esp, 0xc
// 00434733  53                   push ebx
// 00434734  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00434738  55                   push ebp
// 00434739  56                   push esi
// 0043473a  57                   push edi
// 0043473b  8bf9                 mov edi, ecx
// 0043473d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00434740  8b4604               mov eax, dword ptr [esi + 4]
// 00434743  80781900             cmp byte ptr [eax + 0x19], 0
// 00434747  b101                 mov cl, 1
// 00434749  884c2410             mov byte ptr [esp + 0x10], cl
// 0043474d  751f                 jne 0x43476e
// 0043474f  8b13                 mov edx, dword ptr [ebx]
// 00434751  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00434754  8bf0                 mov esi, eax
// 00434756  0f92c1               setb cl
// 00434759  884c2410             mov byte ptr [esp + 0x10], cl
// 0043475d  84c9                 test cl, cl
// 0043475f  7404                 je 0x434765
// 00434761  8b00                 mov eax, dword ptr [eax]
// 00434763  eb03                 jmp 0x434768
// 00434765  8b4008               mov eax, dword ptr [eax + 8]
// 00434768  80781900             cmp byte ptr [eax + 0x19], 0
// 0043476c  74e3                 je 0x434751
// 0043476e  8b17                 mov edx, dword ptr [edi]
// 00434770  8bee                 mov ebp, esi
// 00434772  896c2418             mov dword ptr [esp + 0x18], ebp
// 00434776  89542414             mov dword ptr [esp + 0x14], edx
// 0043477a  84c9                 test cl, cl
// 0043477c  7452                 je 0x4347d0
// 0043477e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00434781  8b28                 mov ebp, dword ptr [eax]
// 00434783  85d2                 test edx, edx
// 00434785  7404                 je 0x43478b
// 00434787  3bd2                 cmp edx, edx
// 00434789  7406                 je 0x434791
// 0043478b  ff1560b79800         call dword ptr [0x98b760]
// 00434791  8d4c2414             lea ecx, [esp + 0x14]
// 00434795  3bf5                 cmp esi, ebp
// 00434797  752a                 jne 0x4347c3
// 00434799  53                   push ebx
// 0043479a  56                   push esi
// 0043479b  6a01                 push 1
// 0043479d  51                   push ecx
// 0043479e  8bcf                 mov ecx, edi
// 004347a0  e80b162c00           call 0x6f5db0
// 004347a5  5f                   pop edi
// 004347a6  8bc8                 mov ecx, eax
// 004347a8  8b11                 mov edx, dword ptr [ecx]
// 004347aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004347ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 004347b1  5e                   pop esi
// 004347b2  5d                   pop ebp
// 004347b3  894804               mov dword ptr [eax + 4], ecx
// 004347b6  c6400801             mov byte ptr [eax + 8], 1
// 004347ba  8910                 mov dword ptr [eax], edx
// 004347bc  5b                   pop ebx
// 004347bd  83c40c               add esp, 0xc
// 004347c0  c20800               ret 8
// 004347c3  e8e8262400           call 0x676eb0
// 004347c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004347cc  8b542414             mov edx, dword ptr [esp + 0x14]
// 004347d0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004347d3  3b03                 cmp eax, dword ptr [ebx]
// 004347d5  7331                 jae 0x434808
// 004347d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004347db  53                   push ebx
// 004347dc  56                   push esi
// 004347dd  51                   push ecx
// 004347de  8d542420             lea edx, [esp + 0x20]
// 004347e2  52                   push edx
// 004347e3  8bcf                 mov ecx, edi
// 004347e5  e8c6152c00           call 0x6f5db0
// 004347ea  5f                   pop edi
// 004347eb  8bc8                 mov ecx, eax
// 004347ed  8b11                 mov edx, dword ptr [ecx]
// 004347ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004347f3  8b4904               mov ecx, dword ptr [ecx + 4]
// 004347f6  5e                   pop esi
// 004347f7  5d                   pop ebp
// 004347f8  894804               mov dword ptr [eax + 4], ecx
// 004347fb  c6400801             mov byte ptr [eax + 8], 1
// 004347ff  8910                 mov dword ptr [eax], edx
// 00434801  5b                   pop ebx
// 00434802  83c40c               add esp, 0xc
// 00434805  c20800               ret 8
// 00434808  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043480c  5f                   pop edi
// 0043480d  5e                   pop esi
// 0043480e  896804               mov dword ptr [eax + 4], ebp
// 00434811  5d                   pop ebp
// 00434812  c6400800             mov byte ptr [eax + 8], 0
// 00434816  8910                 mov dword ptr [eax], edx
// 00434818  5b                   pop ebx
// 00434819  83c40c               add esp, 0xc
// 0043481c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;

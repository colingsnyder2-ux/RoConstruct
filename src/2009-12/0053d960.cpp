// from server: 100% by auto
// roc 2009-12 0053d960  unit: RBX::Network::DirectPhysicsReceiver  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053d960
//
// 0053d960  83ec0c               sub esp, 0xc
// 0053d963  53                   push ebx
// 0053d964  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0053d968  55                   push ebp
// 0053d969  56                   push esi
// 0053d96a  57                   push edi
// 0053d96b  8bf9                 mov edi, ecx
// 0053d96d  8b7718               mov esi, dword ptr [edi + 0x18]
// 0053d970  8b4604               mov eax, dword ptr [esi + 4]
// 0053d973  80783500             cmp byte ptr [eax + 0x35], 0
// 0053d977  b101                 mov cl, 1
// 0053d979  884c2410             mov byte ptr [esp + 0x10], cl
// 0053d97d  751f                 jne 0x53d99e
// 0053d97f  8b13                 mov edx, dword ptr [ebx]
// 0053d981  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0053d984  8bf0                 mov esi, eax
// 0053d986  0f92c1               setb cl
// 0053d989  884c2410             mov byte ptr [esp + 0x10], cl
// 0053d98d  84c9                 test cl, cl
// 0053d98f  7404                 je 0x53d995
// 0053d991  8b00                 mov eax, dword ptr [eax]
// 0053d993  eb03                 jmp 0x53d998
// 0053d995  8b4008               mov eax, dword ptr [eax + 8]
// 0053d998  80783500             cmp byte ptr [eax + 0x35], 0
// 0053d99c  74e3                 je 0x53d981
// 0053d99e  8b17                 mov edx, dword ptr [edi]
// 0053d9a0  8bee                 mov ebp, esi
// 0053d9a2  896c2418             mov dword ptr [esp + 0x18], ebp
// 0053d9a6  89542414             mov dword ptr [esp + 0x14], edx
// 0053d9aa  84c9                 test cl, cl
// 0053d9ac  7452                 je 0x53da00
// 0053d9ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053d9b1  8b28                 mov ebp, dword ptr [eax]
// 0053d9b3  85d2                 test edx, edx
// 0053d9b5  7404                 je 0x53d9bb
// 0053d9b7  3bd2                 cmp edx, edx
// 0053d9b9  7406                 je 0x53d9c1
// 0053d9bb  ff1560b79800         call dword ptr [0x98b760]
// 0053d9c1  8d4c2414             lea ecx, [esp + 0x14]
// 0053d9c5  3bf5                 cmp esi, ebp
// 0053d9c7  752a                 jne 0x53d9f3
// 0053d9c9  53                   push ebx
// 0053d9ca  56                   push esi
// 0053d9cb  6a01                 push 1
// 0053d9cd  51                   push ecx
// 0053d9ce  8bcf                 mov ecx, edi
// 0053d9d0  e81becffff           call 0x53c5f0
// 0053d9d5  5f                   pop edi
// 0053d9d6  8bc8                 mov ecx, eax
// 0053d9d8  8b11                 mov edx, dword ptr [ecx]
// 0053d9da  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053d9de  8b4904               mov ecx, dword ptr [ecx + 4]
// 0053d9e1  5e                   pop esi
// 0053d9e2  5d                   pop ebp
// 0053d9e3  894804               mov dword ptr [eax + 4], ecx
// 0053d9e6  c6400801             mov byte ptr [eax + 8], 1
// 0053d9ea  8910                 mov dword ptr [eax], edx
// 0053d9ec  5b                   pop ebx
// 0053d9ed  83c40c               add esp, 0xc
// 0053d9f0  c20800               ret 8
// 0053d9f3  e818611700           call 0x6b3b10
// 0053d9f8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0053d9fc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053da00  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0053da03  3b03                 cmp eax, dword ptr [ebx]
// 0053da05  7331                 jae 0x53da38
// 0053da07  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053da0b  53                   push ebx
// 0053da0c  56                   push esi
// 0053da0d  51                   push ecx
// 0053da0e  8d542420             lea edx, [esp + 0x20]
// 0053da12  52                   push edx
// 0053da13  8bcf                 mov ecx, edi
// 0053da15  e8d6ebffff           call 0x53c5f0
// 0053da1a  5f                   pop edi
// 0053da1b  8bc8                 mov ecx, eax
// 0053da1d  8b11                 mov edx, dword ptr [ecx]
// 0053da1f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053da23  8b4904               mov ecx, dword ptr [ecx + 4]
// 0053da26  5e                   pop esi
// 0053da27  5d                   pop ebp
// 0053da28  894804               mov dword ptr [eax + 4], ecx
// 0053da2b  c6400801             mov byte ptr [eax + 8], 1
// 0053da2f  8910                 mov dword ptr [eax], edx
// 0053da31  5b                   pop ebx
// 0053da32  83c40c               add esp, 0xc
// 0053da35  c20800               ret 8
// 0053da38  8b442420             mov eax, dword ptr [esp + 0x20]
// 0053da3c  5f                   pop edi
// 0053da3d  5e                   pop esi
// 0053da3e  896804               mov dword ptr [eax + 4], ebp
// 0053da41  5d                   pop ebp
// 0053da42  c6400800             mov byte ptr [eax + 8], 0
// 0053da46  8910                 mov dword ptr [eax], edx
// 0053da48  5b                   pop ebx
// 0053da49  83c40c               add esp, 0xc
// 0053da4c  c20800               ret 8
// standard library map_ptr<pod36> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod36>
struct E { int v[9]; };
#include <map>
struct K; template class std::map<K*, E>;

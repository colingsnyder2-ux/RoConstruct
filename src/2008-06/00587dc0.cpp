// from server: 100% by auto
// roc 2008-06 00587dc0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587dc0
//
// 00587dc0  83ec0c               sub esp, 0xc
// 00587dc3  53                   push ebx
// 00587dc4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00587dc8  55                   push ebp
// 00587dc9  56                   push esi
// 00587dca  57                   push edi
// 00587dcb  8bf9                 mov edi, ecx
// 00587dcd  8b7718               mov esi, dword ptr [edi + 0x18]
// 00587dd0  8b4604               mov eax, dword ptr [esi + 4]
// 00587dd3  80781900             cmp byte ptr [eax + 0x19], 0
// 00587dd7  b101                 mov cl, 1
// 00587dd9  884c2410             mov byte ptr [esp + 0x10], cl
// 00587ddd  751f                 jne 0x587dfe
// 00587ddf  8b13                 mov edx, dword ptr [ebx]
// 00587de1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00587de4  8bf0                 mov esi, eax
// 00587de6  0f92c1               setb cl
// 00587de9  884c2410             mov byte ptr [esp + 0x10], cl
// 00587ded  84c9                 test cl, cl
// 00587def  7404                 je 0x587df5
// 00587df1  8b00                 mov eax, dword ptr [eax]
// 00587df3  eb03                 jmp 0x587df8
// 00587df5  8b4008               mov eax, dword ptr [eax + 8]
// 00587df8  80781900             cmp byte ptr [eax + 0x19], 0
// 00587dfc  74e3                 je 0x587de1
// 00587dfe  8b17                 mov edx, dword ptr [edi]
// 00587e00  8bee                 mov ebp, esi
// 00587e02  896c2418             mov dword ptr [esp + 0x18], ebp
// 00587e06  89542414             mov dword ptr [esp + 0x14], edx
// 00587e0a  84c9                 test cl, cl
// 00587e0c  7452                 je 0x587e60
// 00587e0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00587e11  8b28                 mov ebp, dword ptr [eax]
// 00587e13  85d2                 test edx, edx
// 00587e15  7404                 je 0x587e1b
// 00587e17  3bd2                 cmp edx, edx
// 00587e19  7406                 je 0x587e21
// 00587e1b  ff1590288000         call dword ptr [0x802890]
// 00587e21  8d4c2414             lea ecx, [esp + 0x14]
// 00587e25  3bf5                 cmp esi, ebp
// 00587e27  752a                 jne 0x587e53
// 00587e29  53                   push ebx
// 00587e2a  56                   push esi
// 00587e2b  6a01                 push 1
// 00587e2d  51                   push ecx
// 00587e2e  8bcf                 mov ecx, edi
// 00587e30  e8ebf9ffff           call 0x587820
// 00587e35  5f                   pop edi
// 00587e36  8bc8                 mov ecx, eax
// 00587e38  8b11                 mov edx, dword ptr [ecx]
// 00587e3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00587e3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00587e41  5e                   pop esi
// 00587e42  5d                   pop ebp
// 00587e43  894804               mov dword ptr [eax + 4], ecx
// 00587e46  c6400801             mov byte ptr [eax + 8], 1
// 00587e4a  8910                 mov dword ptr [eax], edx
// 00587e4c  5b                   pop ebx
// 00587e4d  83c40c               add esp, 0xc
// 00587e50  c20800               ret 8
// 00587e53  e8e840f2ff           call 0x4abf40
// 00587e58  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00587e5c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00587e60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00587e63  3b03                 cmp eax, dword ptr [ebx]
// 00587e65  7331                 jae 0x587e98
// 00587e67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00587e6b  53                   push ebx
// 00587e6c  56                   push esi
// 00587e6d  51                   push ecx
// 00587e6e  8d542420             lea edx, [esp + 0x20]
// 00587e72  52                   push edx
// 00587e73  8bcf                 mov ecx, edi
// 00587e75  e8a6f9ffff           call 0x587820
// 00587e7a  5f                   pop edi
// 00587e7b  8bc8                 mov ecx, eax
// 00587e7d  8b11                 mov edx, dword ptr [ecx]
// 00587e7f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00587e83  8b4904               mov ecx, dword ptr [ecx + 4]
// 00587e86  5e                   pop esi
// 00587e87  5d                   pop ebp
// 00587e88  894804               mov dword ptr [eax + 4], ecx
// 00587e8b  c6400801             mov byte ptr [eax + 8], 1
// 00587e8f  8910                 mov dword ptr [eax], edx
// 00587e91  5b                   pop ebx
// 00587e92  83c40c               add esp, 0xc
// 00587e95  c20800               ret 8
// 00587e98  8b442420             mov eax, dword ptr [esp + 0x20]
// 00587e9c  5f                   pop edi
// 00587e9d  5e                   pop esi
// 00587e9e  896804               mov dword ptr [eax + 4], ebp
// 00587ea1  5d                   pop ebp
// 00587ea2  c6400800             mov byte ptr [eax + 8], 0
// 00587ea6  8910                 mov dword ptr [eax], edx
// 00587ea8  5b                   pop ebx
// 00587ea9  83c40c               add esp, 0xc
// 00587eac  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;

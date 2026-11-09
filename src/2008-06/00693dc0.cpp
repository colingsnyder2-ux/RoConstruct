// from server: 100% by auto
// roc 2008-06 00693dc0  unit: Ogre::RbxSceneManager  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693dc0
//
// 00693dc0  83ec0c               sub esp, 0xc
// 00693dc3  53                   push ebx
// 00693dc4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00693dc8  55                   push ebp
// 00693dc9  56                   push esi
// 00693dca  57                   push edi
// 00693dcb  8bf9                 mov edi, ecx
// 00693dcd  8b7718               mov esi, dword ptr [edi + 0x18]
// 00693dd0  8b4604               mov eax, dword ptr [esi + 4]
// 00693dd3  80783900             cmp byte ptr [eax + 0x39], 0
// 00693dd7  b101                 mov cl, 1
// 00693dd9  884c2410             mov byte ptr [esp + 0x10], cl
// 00693ddd  751f                 jne 0x693dfe
// 00693ddf  8b13                 mov edx, dword ptr [ebx]
// 00693de1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00693de4  8bf0                 mov esi, eax
// 00693de6  0f92c1               setb cl
// 00693de9  884c2410             mov byte ptr [esp + 0x10], cl
// 00693ded  84c9                 test cl, cl
// 00693def  7404                 je 0x693df5
// 00693df1  8b00                 mov eax, dword ptr [eax]
// 00693df3  eb03                 jmp 0x693df8
// 00693df5  8b4008               mov eax, dword ptr [eax + 8]
// 00693df8  80783900             cmp byte ptr [eax + 0x39], 0
// 00693dfc  74e3                 je 0x693de1
// 00693dfe  8b17                 mov edx, dword ptr [edi]
// 00693e00  8bee                 mov ebp, esi
// 00693e02  896c2418             mov dword ptr [esp + 0x18], ebp
// 00693e06  89542414             mov dword ptr [esp + 0x14], edx
// 00693e0a  84c9                 test cl, cl
// 00693e0c  7452                 je 0x693e60
// 00693e0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00693e11  8b28                 mov ebp, dword ptr [eax]
// 00693e13  85d2                 test edx, edx
// 00693e15  7404                 je 0x693e1b
// 00693e17  3bd2                 cmp edx, edx
// 00693e19  7406                 je 0x693e21
// 00693e1b  ff1590288000         call dword ptr [0x802890]
// 00693e21  8d4c2414             lea ecx, [esp + 0x14]
// 00693e25  3bf5                 cmp esi, ebp
// 00693e27  752a                 jne 0x693e53
// 00693e29  53                   push ebx
// 00693e2a  56                   push esi
// 00693e2b  6a01                 push 1
// 00693e2d  51                   push ecx
// 00693e2e  8bcf                 mov ecx, edi
// 00693e30  e8bbe4ffff           call 0x6922f0
// 00693e35  5f                   pop edi
// 00693e36  8bc8                 mov ecx, eax
// 00693e38  8b11                 mov edx, dword ptr [ecx]
// 00693e3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00693e3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00693e41  5e                   pop esi
// 00693e42  5d                   pop ebp
// 00693e43  894804               mov dword ptr [eax + 4], ecx
// 00693e46  c6400801             mov byte ptr [eax + 8], 1
// 00693e4a  8910                 mov dword ptr [eax], edx
// 00693e4c  5b                   pop ebx
// 00693e4d  83c40c               add esp, 0xc
// 00693e50  c20800               ret 8
// 00693e53  e86894ffff           call 0x68d2c0
// 00693e58  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00693e5c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00693e60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00693e63  3b03                 cmp eax, dword ptr [ebx]
// 00693e65  7331                 jae 0x693e98
// 00693e67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00693e6b  53                   push ebx
// 00693e6c  56                   push esi
// 00693e6d  51                   push ecx
// 00693e6e  8d542420             lea edx, [esp + 0x20]
// 00693e72  52                   push edx
// 00693e73  8bcf                 mov ecx, edi
// 00693e75  e876e4ffff           call 0x6922f0
// 00693e7a  5f                   pop edi
// 00693e7b  8bc8                 mov ecx, eax
// 00693e7d  8b11                 mov edx, dword ptr [ecx]
// 00693e7f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00693e83  8b4904               mov ecx, dword ptr [ecx + 4]
// 00693e86  5e                   pop esi
// 00693e87  5d                   pop ebp
// 00693e88  894804               mov dword ptr [eax + 4], ecx
// 00693e8b  c6400801             mov byte ptr [eax + 8], 1
// 00693e8f  8910                 mov dword ptr [eax], edx
// 00693e91  5b                   pop ebx
// 00693e92  83c40c               add esp, 0xc
// 00693e95  c20800               ret 8
// 00693e98  8b442420             mov eax, dword ptr [esp + 0x20]
// 00693e9c  5f                   pop edi
// 00693e9d  5e                   pop esi
// 00693e9e  896804               mov dword ptr [eax + 4], ebp
// 00693ea1  5d                   pop ebp
// 00693ea2  c6400800             mov byte ptr [eax + 8], 0
// 00693ea6  8910                 mov dword ptr [eax], edx
// 00693ea8  5b                   pop ebx
// 00693ea9  83c40c               add esp, 0xc
// 00693eac  c20800               ret 8
// standard library map_ptr<pod40> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod40>
struct E { int v[10]; };
#include <map>
struct K; template class std::map<K*, E>;

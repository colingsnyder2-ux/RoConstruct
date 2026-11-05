// from server: 100% by auto
// roc 2008-06 00681b40  unit: Ogre::RbxSceneNode  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00681b40
//
// 00681b40  83ec0c               sub esp, 0xc
// 00681b43  53                   push ebx
// 00681b44  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00681b48  55                   push ebp
// 00681b49  56                   push esi
// 00681b4a  57                   push edi
// 00681b4b  8bf9                 mov edi, ecx
// 00681b4d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00681b50  8b4604               mov eax, dword ptr [esi + 4]
// 00681b53  80782100             cmp byte ptr [eax + 0x21], 0
// 00681b57  b101                 mov cl, 1
// 00681b59  884c2410             mov byte ptr [esp + 0x10], cl
// 00681b5d  751f                 jne 0x681b7e
// 00681b5f  8b13                 mov edx, dword ptr [ebx]
// 00681b61  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00681b64  8bf0                 mov esi, eax
// 00681b66  0f92c1               setb cl
// 00681b69  884c2410             mov byte ptr [esp + 0x10], cl
// 00681b6d  84c9                 test cl, cl
// 00681b6f  7404                 je 0x681b75
// 00681b71  8b00                 mov eax, dword ptr [eax]
// 00681b73  eb03                 jmp 0x681b78
// 00681b75  8b4008               mov eax, dword ptr [eax + 8]
// 00681b78  80782100             cmp byte ptr [eax + 0x21], 0
// 00681b7c  74e3                 je 0x681b61
// 00681b7e  8b17                 mov edx, dword ptr [edi]
// 00681b80  8bee                 mov ebp, esi
// 00681b82  896c2418             mov dword ptr [esp + 0x18], ebp
// 00681b86  89542414             mov dword ptr [esp + 0x14], edx
// 00681b8a  84c9                 test cl, cl
// 00681b8c  7452                 je 0x681be0
// 00681b8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00681b91  8b28                 mov ebp, dword ptr [eax]
// 00681b93  85d2                 test edx, edx
// 00681b95  7404                 je 0x681b9b
// 00681b97  3bd2                 cmp edx, edx
// 00681b99  7406                 je 0x681ba1
// 00681b9b  ff1590288000         call dword ptr [0x802890]
// 00681ba1  8d4c2414             lea ecx, [esp + 0x14]
// 00681ba5  3bf5                 cmp esi, ebp
// 00681ba7  752a                 jne 0x681bd3
// 00681ba9  53                   push ebx
// 00681baa  56                   push esi
// 00681bab  6a01                 push 1
// 00681bad  51                   push ecx
// 00681bae  8bcf                 mov ecx, edi
// 00681bb0  e8abf7ffff           call 0x681360
// 00681bb5  5f                   pop edi
// 00681bb6  8bc8                 mov ecx, eax
// 00681bb8  8b11                 mov edx, dword ptr [ecx]
// 00681bba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00681bbe  8b4904               mov ecx, dword ptr [ecx + 4]
// 00681bc1  5e                   pop esi
// 00681bc2  5d                   pop ebp
// 00681bc3  894804               mov dword ptr [eax + 4], ecx
// 00681bc6  c6400801             mov byte ptr [eax + 8], 1
// 00681bca  8910                 mov dword ptr [eax], edx
// 00681bcc  5b                   pop ebx
// 00681bcd  83c40c               add esp, 0xc
// 00681bd0  c20800               ret 8
// 00681bd3  e89846e6ff           call 0x4e6270
// 00681bd8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00681bdc  8b542414             mov edx, dword ptr [esp + 0x14]
// 00681be0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00681be3  3b03                 cmp eax, dword ptr [ebx]
// 00681be5  7331                 jae 0x681c18
// 00681be7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00681beb  53                   push ebx
// 00681bec  56                   push esi
// 00681bed  51                   push ecx
// 00681bee  8d542420             lea edx, [esp + 0x20]
// 00681bf2  52                   push edx
// 00681bf3  8bcf                 mov ecx, edi
// 00681bf5  e866f7ffff           call 0x681360
// 00681bfa  5f                   pop edi
// 00681bfb  8bc8                 mov ecx, eax
// 00681bfd  8b11                 mov edx, dword ptr [ecx]
// 00681bff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00681c03  8b4904               mov ecx, dword ptr [ecx + 4]
// 00681c06  5e                   pop esi
// 00681c07  5d                   pop ebp
// 00681c08  894804               mov dword ptr [eax + 4], ecx
// 00681c0b  c6400801             mov byte ptr [eax + 8], 1
// 00681c0f  8910                 mov dword ptr [eax], edx
// 00681c11  5b                   pop ebx
// 00681c12  83c40c               add esp, 0xc
// 00681c15  c20800               ret 8
// 00681c18  8b442420             mov eax, dword ptr [esp + 0x20]
// 00681c1c  5f                   pop edi
// 00681c1d  5e                   pop esi
// 00681c1e  896804               mov dword ptr [eax + 4], ebp
// 00681c21  5d                   pop ebp
// 00681c22  c6400800             mov byte ptr [eax + 8], 0
// 00681c26  8910                 mov dword ptr [eax], edx
// 00681c28  5b                   pop ebx
// 00681c29  83c40c               add esp, 0xc
// 00681c2c  c20800               ret 8
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;

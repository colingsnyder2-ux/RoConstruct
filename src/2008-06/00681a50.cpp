// from server: 100% by auto
// roc 2008-06 00681a50  unit: Ogre::RbxSceneNode  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00681a50
//
// 00681a50  83ec0c               sub esp, 0xc
// 00681a53  53                   push ebx
// 00681a54  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00681a58  55                   push ebp
// 00681a59  56                   push esi
// 00681a5a  57                   push edi
// 00681a5b  8bf9                 mov edi, ecx
// 00681a5d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00681a60  8b4604               mov eax, dword ptr [esi + 4]
// 00681a63  80781500             cmp byte ptr [eax + 0x15], 0
// 00681a67  b101                 mov cl, 1
// 00681a69  884c2410             mov byte ptr [esp + 0x10], cl
// 00681a6d  751f                 jne 0x681a8e
// 00681a6f  8b13                 mov edx, dword ptr [ebx]
// 00681a71  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00681a74  8bf0                 mov esi, eax
// 00681a76  0f92c1               setb cl
// 00681a79  884c2410             mov byte ptr [esp + 0x10], cl
// 00681a7d  84c9                 test cl, cl
// 00681a7f  7404                 je 0x681a85
// 00681a81  8b00                 mov eax, dword ptr [eax]
// 00681a83  eb03                 jmp 0x681a88
// 00681a85  8b4008               mov eax, dword ptr [eax + 8]
// 00681a88  80781500             cmp byte ptr [eax + 0x15], 0
// 00681a8c  74e3                 je 0x681a71
// 00681a8e  8b17                 mov edx, dword ptr [edi]
// 00681a90  8bee                 mov ebp, esi
// 00681a92  896c2418             mov dword ptr [esp + 0x18], ebp
// 00681a96  89542414             mov dword ptr [esp + 0x14], edx
// 00681a9a  84c9                 test cl, cl
// 00681a9c  7452                 je 0x681af0
// 00681a9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00681aa1  8b28                 mov ebp, dword ptr [eax]
// 00681aa3  85d2                 test edx, edx
// 00681aa5  7404                 je 0x681aab
// 00681aa7  3bd2                 cmp edx, edx
// 00681aa9  7406                 je 0x681ab1
// 00681aab  ff1590288000         call dword ptr [0x802890]
// 00681ab1  8d4c2414             lea ecx, [esp + 0x14]
// 00681ab5  3bf5                 cmp esi, ebp
// 00681ab7  752a                 jne 0x681ae3
// 00681ab9  53                   push ebx
// 00681aba  56                   push esi
// 00681abb  6a01                 push 1
// 00681abd  51                   push ecx
// 00681abe  8bcf                 mov ecx, edi
// 00681ac0  e84b65feff           call 0x668010
// 00681ac5  5f                   pop edi
// 00681ac6  8bc8                 mov ecx, eax
// 00681ac8  8b11                 mov edx, dword ptr [ecx]
// 00681aca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00681ace  8b4904               mov ecx, dword ptr [ecx + 4]
// 00681ad1  5e                   pop esi
// 00681ad2  5d                   pop ebp
// 00681ad3  894804               mov dword ptr [eax + 4], ecx
// 00681ad6  c6400801             mov byte ptr [eax + 8], 1
// 00681ada  8910                 mov dword ptr [eax], edx
// 00681adc  5b                   pop ebx
// 00681add  83c40c               add esp, 0xc
// 00681ae0  c20800               ret 8
// 00681ae3  e8e880f8ff           call 0x609bd0
// 00681ae8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00681aec  8b542414             mov edx, dword ptr [esp + 0x14]
// 00681af0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00681af3  3b03                 cmp eax, dword ptr [ebx]
// 00681af5  7331                 jae 0x681b28
// 00681af7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00681afb  53                   push ebx
// 00681afc  56                   push esi
// 00681afd  51                   push ecx
// 00681afe  8d542420             lea edx, [esp + 0x20]
// 00681b02  52                   push edx
// 00681b03  8bcf                 mov ecx, edi
// 00681b05  e80665feff           call 0x668010
// 00681b0a  5f                   pop edi
// 00681b0b  8bc8                 mov ecx, eax
// 00681b0d  8b11                 mov edx, dword ptr [ecx]
// 00681b0f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00681b13  8b4904               mov ecx, dword ptr [ecx + 4]
// 00681b16  5e                   pop esi
// 00681b17  5d                   pop ebp
// 00681b18  894804               mov dword ptr [eax + 4], ecx
// 00681b1b  c6400801             mov byte ptr [eax + 8], 1
// 00681b1f  8910                 mov dword ptr [eax], edx
// 00681b21  5b                   pop ebx
// 00681b22  83c40c               add esp, 0xc
// 00681b25  c20800               ret 8
// 00681b28  8b442420             mov eax, dword ptr [esp + 0x20]
// 00681b2c  5f                   pop edi
// 00681b2d  5e                   pop esi
// 00681b2e  896804               mov dword ptr [eax + 4], ebp
// 00681b31  5d                   pop ebp
// 00681b32  c6400800             mov byte ptr [eax + 8], 0
// 00681b36  8910                 mov dword ptr [eax], edx
// 00681b38  5b                   pop ebx
// 00681b39  83c40c               add esp, 0xc
// 00681b3c  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;

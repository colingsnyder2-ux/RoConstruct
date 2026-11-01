// from server: 100% by auto
// roc 2009-12 00498c10  unit: Ogre::RbxSceneNode  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00498c10
//
// 00498c10  83ec0c               sub esp, 0xc
// 00498c13  53                   push ebx
// 00498c14  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00498c18  55                   push ebp
// 00498c19  56                   push esi
// 00498c1a  57                   push edi
// 00498c1b  8bf9                 mov edi, ecx
// 00498c1d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00498c20  8b4604               mov eax, dword ptr [esi + 4]
// 00498c23  80781500             cmp byte ptr [eax + 0x15], 0
// 00498c27  b101                 mov cl, 1
// 00498c29  884c2410             mov byte ptr [esp + 0x10], cl
// 00498c2d  751f                 jne 0x498c4e
// 00498c2f  8b13                 mov edx, dword ptr [ebx]
// 00498c31  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00498c34  8bf0                 mov esi, eax
// 00498c36  0f92c1               setb cl
// 00498c39  884c2410             mov byte ptr [esp + 0x10], cl
// 00498c3d  84c9                 test cl, cl
// 00498c3f  7404                 je 0x498c45
// 00498c41  8b00                 mov eax, dword ptr [eax]
// 00498c43  eb03                 jmp 0x498c48
// 00498c45  8b4008               mov eax, dword ptr [eax + 8]
// 00498c48  80781500             cmp byte ptr [eax + 0x15], 0
// 00498c4c  74e3                 je 0x498c31
// 00498c4e  8b17                 mov edx, dword ptr [edi]
// 00498c50  8bee                 mov ebp, esi
// 00498c52  896c2418             mov dword ptr [esp + 0x18], ebp
// 00498c56  89542414             mov dword ptr [esp + 0x14], edx
// 00498c5a  84c9                 test cl, cl
// 00498c5c  7452                 je 0x498cb0
// 00498c5e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00498c61  8b28                 mov ebp, dword ptr [eax]
// 00498c63  85d2                 test edx, edx
// 00498c65  7404                 je 0x498c6b
// 00498c67  3bd2                 cmp edx, edx
// 00498c69  7406                 je 0x498c71
// 00498c6b  ff1560b79800         call dword ptr [0x98b760]
// 00498c71  8d4c2414             lea ecx, [esp + 0x14]
// 00498c75  3bf5                 cmp esi, ebp
// 00498c77  752a                 jne 0x498ca3
// 00498c79  53                   push ebx
// 00498c7a  56                   push esi
// 00498c7b  6a01                 push 1
// 00498c7d  51                   push ecx
// 00498c7e  8bcf                 mov ecx, edi
// 00498c80  e89b462100           call 0x6ad320
// 00498c85  5f                   pop edi
// 00498c86  8bc8                 mov ecx, eax
// 00498c88  8b11                 mov edx, dword ptr [ecx]
// 00498c8a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00498c8e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00498c91  5e                   pop esi
// 00498c92  5d                   pop ebp
// 00498c93  894804               mov dword ptr [eax + 4], ecx
// 00498c96  c6400801             mov byte ptr [eax + 8], 1
// 00498c9a  8910                 mov dword ptr [eax], edx
// 00498c9c  5b                   pop ebx
// 00498c9d  83c40c               add esp, 0xc
// 00498ca0  c20800               ret 8
// 00498ca3  e888b5faff           call 0x444230
// 00498ca8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00498cac  8b542414             mov edx, dword ptr [esp + 0x14]
// 00498cb0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00498cb3  3b03                 cmp eax, dword ptr [ebx]
// 00498cb5  7331                 jae 0x498ce8
// 00498cb7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00498cbb  53                   push ebx
// 00498cbc  56                   push esi
// 00498cbd  51                   push ecx
// 00498cbe  8d542420             lea edx, [esp + 0x20]
// 00498cc2  52                   push edx
// 00498cc3  8bcf                 mov ecx, edi
// 00498cc5  e856462100           call 0x6ad320
// 00498cca  5f                   pop edi
// 00498ccb  8bc8                 mov ecx, eax
// 00498ccd  8b11                 mov edx, dword ptr [ecx]
// 00498ccf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00498cd3  8b4904               mov ecx, dword ptr [ecx + 4]
// 00498cd6  5e                   pop esi
// 00498cd7  5d                   pop ebp
// 00498cd8  894804               mov dword ptr [eax + 4], ecx
// 00498cdb  c6400801             mov byte ptr [eax + 8], 1
// 00498cdf  8910                 mov dword ptr [eax], edx
// 00498ce1  5b                   pop ebx
// 00498ce2  83c40c               add esp, 0xc
// 00498ce5  c20800               ret 8
// 00498ce8  8b442420             mov eax, dword ptr [esp + 0x20]
// 00498cec  5f                   pop edi
// 00498ced  5e                   pop esi
// 00498cee  896804               mov dword ptr [eax + 4], ebp
// 00498cf1  5d                   pop ebp
// 00498cf2  c6400800             mov byte ptr [eax + 8], 0
// 00498cf6  8910                 mov dword ptr [eax], edx
// 00498cf8  5b                   pop ebx
// 00498cf9  83c40c               add esp, 0xc
// 00498cfc  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;

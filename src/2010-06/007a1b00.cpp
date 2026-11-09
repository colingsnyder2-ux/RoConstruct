// from server: 100% by auto
// roc 2010-06 007a1b00  unit: W4_D3DFORMAT::?$EnumDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a1b00
//
// 007a1b00  83ec0c               sub esp, 0xc
// 007a1b03  53                   push ebx
// 007a1b04  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007a1b08  55                   push ebp
// 007a1b09  56                   push esi
// 007a1b0a  57                   push edi
// 007a1b0b  8bf9                 mov edi, ecx
// 007a1b0d  8b7718               mov esi, dword ptr [edi + 0x18]
// 007a1b10  8b4604               mov eax, dword ptr [esi + 4]
// 007a1b13  80781500             cmp byte ptr [eax + 0x15], 0
// 007a1b17  b101                 mov cl, 1
// 007a1b19  884c2410             mov byte ptr [esp + 0x10], cl
// 007a1b1d  751f                 jne 0x7a1b3e
// 007a1b1f  8b13                 mov edx, dword ptr [ebx]
// 007a1b21  3b500c               cmp edx, dword ptr [eax + 0xc]
// 007a1b24  8bf0                 mov esi, eax
// 007a1b26  0f92c1               setb cl
// 007a1b29  884c2410             mov byte ptr [esp + 0x10], cl
// 007a1b2d  84c9                 test cl, cl
// 007a1b2f  7404                 je 0x7a1b35
// 007a1b31  8b00                 mov eax, dword ptr [eax]
// 007a1b33  eb03                 jmp 0x7a1b38
// 007a1b35  8b4008               mov eax, dword ptr [eax + 8]
// 007a1b38  80781500             cmp byte ptr [eax + 0x15], 0
// 007a1b3c  74e3                 je 0x7a1b21
// 007a1b3e  8b17                 mov edx, dword ptr [edi]
// 007a1b40  8bee                 mov ebp, esi
// 007a1b42  896c2418             mov dword ptr [esp + 0x18], ebp
// 007a1b46  89542414             mov dword ptr [esp + 0x14], edx
// 007a1b4a  84c9                 test cl, cl
// 007a1b4c  7452                 je 0x7a1ba0
// 007a1b4e  8b4718               mov eax, dword ptr [edi + 0x18]
// 007a1b51  8b28                 mov ebp, dword ptr [eax]
// 007a1b53  85d2                 test edx, edx
// 007a1b55  7404                 je 0x7a1b5b
// 007a1b57  3bd2                 cmp edx, edx
// 007a1b59  7406                 je 0x7a1b61
// 007a1b5b  ff150ca99e00         call dword ptr [0x9ea90c]
// 007a1b61  8d4c2414             lea ecx, [esp + 0x14]
// 007a1b65  3bf5                 cmp esi, ebp
// 007a1b67  752a                 jne 0x7a1b93
// 007a1b69  53                   push ebx
// 007a1b6a  56                   push esi
// 007a1b6b  6a01                 push 1
// 007a1b6d  51                   push ecx
// 007a1b6e  8bcf                 mov ecx, edi
// 007a1b70  e83bfdffff           call 0x7a18b0
// 007a1b75  5f                   pop edi
// 007a1b76  8bc8                 mov ecx, eax
// 007a1b78  8b11                 mov edx, dword ptr [ecx]
// 007a1b7a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a1b7e  8b4904               mov ecx, dword ptr [ecx + 4]
// 007a1b81  5e                   pop esi
// 007a1b82  5d                   pop ebp
// 007a1b83  894804               mov dword ptr [eax + 4], ecx
// 007a1b86  c6400801             mov byte ptr [eax + 8], 1
// 007a1b8a  8910                 mov dword ptr [eax], edx
// 007a1b8c  5b                   pop ebx
// 007a1b8d  83c40c               add esp, 0xc
// 007a1b90  c20800               ret 8
// 007a1b93  e8a880f6ff           call 0x709c40
// 007a1b98  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007a1b9c  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a1ba0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007a1ba3  3b03                 cmp eax, dword ptr [ebx]
// 007a1ba5  7331                 jae 0x7a1bd8
// 007a1ba7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a1bab  53                   push ebx
// 007a1bac  56                   push esi
// 007a1bad  51                   push ecx
// 007a1bae  8d542420             lea edx, [esp + 0x20]
// 007a1bb2  52                   push edx
// 007a1bb3  8bcf                 mov ecx, edi
// 007a1bb5  e8f6fcffff           call 0x7a18b0
// 007a1bba  5f                   pop edi
// 007a1bbb  8bc8                 mov ecx, eax
// 007a1bbd  8b11                 mov edx, dword ptr [ecx]
// 007a1bbf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a1bc3  8b4904               mov ecx, dword ptr [ecx + 4]
// 007a1bc6  5e                   pop esi
// 007a1bc7  5d                   pop ebp
// 007a1bc8  894804               mov dword ptr [eax + 4], ecx
// 007a1bcb  c6400801             mov byte ptr [eax + 8], 1
// 007a1bcf  8910                 mov dword ptr [eax], edx
// 007a1bd1  5b                   pop ebx
// 007a1bd2  83c40c               add esp, 0xc
// 007a1bd5  c20800               ret 8
// 007a1bd8  8b442420             mov eax, dword ptr [esp + 0x20]
// 007a1bdc  5f                   pop edi
// 007a1bdd  5e                   pop esi
// 007a1bde  896804               mov dword ptr [eax + 4], ebp
// 007a1be1  5d                   pop ebp
// 007a1be2  c6400800             mov byte ptr [eax + 8], 0
// 007a1be6  8910                 mov dword ptr [eax], edx
// 007a1be8  5b                   pop ebx
// 007a1be9  83c40c               add esp, 0xc
// 007a1bec  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;

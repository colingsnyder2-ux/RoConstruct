// from server: 100% by auto
// roc 2008-06 005b38a0  unit: RBX::VHat::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b38a0
//
// 005b38a0  83ec0c               sub esp, 0xc
// 005b38a3  53                   push ebx
// 005b38a4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005b38a8  55                   push ebp
// 005b38a9  56                   push esi
// 005b38aa  57                   push edi
// 005b38ab  8bf9                 mov edi, ecx
// 005b38ad  8b7718               mov esi, dword ptr [edi + 0x18]
// 005b38b0  8b4604               mov eax, dword ptr [esi + 4]
// 005b38b3  80781500             cmp byte ptr [eax + 0x15], 0
// 005b38b7  b101                 mov cl, 1
// 005b38b9  884c2410             mov byte ptr [esp + 0x10], cl
// 005b38bd  751f                 jne 0x5b38de
// 005b38bf  8b13                 mov edx, dword ptr [ebx]
// 005b38c1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005b38c4  8bf0                 mov esi, eax
// 005b38c6  0f9cc1               setl cl
// 005b38c9  884c2410             mov byte ptr [esp + 0x10], cl
// 005b38cd  84c9                 test cl, cl
// 005b38cf  7404                 je 0x5b38d5
// 005b38d1  8b00                 mov eax, dword ptr [eax]
// 005b38d3  eb03                 jmp 0x5b38d8
// 005b38d5  8b4008               mov eax, dword ptr [eax + 8]
// 005b38d8  80781500             cmp byte ptr [eax + 0x15], 0
// 005b38dc  74e3                 je 0x5b38c1
// 005b38de  8b17                 mov edx, dword ptr [edi]
// 005b38e0  8bee                 mov ebp, esi
// 005b38e2  896c2418             mov dword ptr [esp + 0x18], ebp
// 005b38e6  89542414             mov dword ptr [esp + 0x14], edx
// 005b38ea  84c9                 test cl, cl
// 005b38ec  7452                 je 0x5b3940
// 005b38ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b38f1  8b28                 mov ebp, dword ptr [eax]
// 005b38f3  85d2                 test edx, edx
// 005b38f5  7404                 je 0x5b38fb
// 005b38f7  3bd2                 cmp edx, edx
// 005b38f9  7406                 je 0x5b3901
// 005b38fb  ff1590288000         call dword ptr [0x802890]
// 005b3901  8d4c2414             lea ecx, [esp + 0x14]
// 005b3905  3bf5                 cmp esi, ebp
// 005b3907  752a                 jne 0x5b3933
// 005b3909  53                   push ebx
// 005b390a  56                   push esi
// 005b390b  6a01                 push 1
// 005b390d  51                   push ecx
// 005b390e  8bcf                 mov ecx, edi
// 005b3910  e8fb460b00           call 0x668010
// 005b3915  5f                   pop edi
// 005b3916  8bc8                 mov ecx, eax
// 005b3918  8b11                 mov edx, dword ptr [ecx]
// 005b391a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b391e  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b3921  5e                   pop esi
// 005b3922  5d                   pop ebp
// 005b3923  894804               mov dword ptr [eax + 4], ecx
// 005b3926  c6400801             mov byte ptr [eax + 8], 1
// 005b392a  8910                 mov dword ptr [eax], edx
// 005b392c  5b                   pop ebx
// 005b392d  83c40c               add esp, 0xc
// 005b3930  c20800               ret 8
// 005b3933  e898620500           call 0x609bd0
// 005b3938  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005b393c  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b3940  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b3943  3b03                 cmp eax, dword ptr [ebx]
// 005b3945  7d31                 jge 0x5b3978
// 005b3947  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b394b  53                   push ebx
// 005b394c  56                   push esi
// 005b394d  51                   push ecx
// 005b394e  8d542420             lea edx, [esp + 0x20]
// 005b3952  52                   push edx
// 005b3953  8bcf                 mov ecx, edi
// 005b3955  e8b6460b00           call 0x668010
// 005b395a  5f                   pop edi
// 005b395b  8bc8                 mov ecx, eax
// 005b395d  8b11                 mov edx, dword ptr [ecx]
// 005b395f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3963  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b3966  5e                   pop esi
// 005b3967  5d                   pop ebp
// 005b3968  894804               mov dword ptr [eax + 4], ecx
// 005b396b  c6400801             mov byte ptr [eax + 8], 1
// 005b396f  8910                 mov dword ptr [eax], edx
// 005b3971  5b                   pop ebx
// 005b3972  83c40c               add esp, 0xc
// 005b3975  c20800               ret 8
// 005b3978  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b397c  5f                   pop edi
// 005b397d  5e                   pop esi
// 005b397e  896804               mov dword ptr [eax + 4], ebp
// 005b3981  5d                   pop ebp
// 005b3982  c6400800             mov byte ptr [eax + 8], 0
// 005b3986  8910                 mov dword ptr [eax], edx
// 005b3988  5b                   pop ebx
// 005b3989  83c40c               add esp, 0xc
// 005b398c  c20800               ret 8
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

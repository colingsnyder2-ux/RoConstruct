// from server: 100% by auto
// roc 2009-06 0063f330  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f330
//
// 0063f330  83ec0c               sub esp, 0xc
// 0063f333  53                   push ebx
// 0063f334  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0063f338  55                   push ebp
// 0063f339  56                   push esi
// 0063f33a  57                   push edi
// 0063f33b  8bf9                 mov edi, ecx
// 0063f33d  8b7718               mov esi, dword ptr [edi + 0x18]
// 0063f340  8b4604               mov eax, dword ptr [esi + 4]
// 0063f343  80781500             cmp byte ptr [eax + 0x15], 0
// 0063f347  b101                 mov cl, 1
// 0063f349  884c2410             mov byte ptr [esp + 0x10], cl
// 0063f34d  751f                 jne 0x63f36e
// 0063f34f  8b13                 mov edx, dword ptr [ebx]
// 0063f351  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0063f354  8bf0                 mov esi, eax
// 0063f356  0f9cc1               setl cl
// 0063f359  884c2410             mov byte ptr [esp + 0x10], cl
// 0063f35d  84c9                 test cl, cl
// 0063f35f  7404                 je 0x63f365
// 0063f361  8b00                 mov eax, dword ptr [eax]
// 0063f363  eb03                 jmp 0x63f368
// 0063f365  8b4008               mov eax, dword ptr [eax + 8]
// 0063f368  80781500             cmp byte ptr [eax + 0x15], 0
// 0063f36c  74e3                 je 0x63f351
// 0063f36e  8b17                 mov edx, dword ptr [edi]
// 0063f370  8bee                 mov ebp, esi
// 0063f372  896c2418             mov dword ptr [esp + 0x18], ebp
// 0063f376  89542414             mov dword ptr [esp + 0x14], edx
// 0063f37a  84c9                 test cl, cl
// 0063f37c  7452                 je 0x63f3d0
// 0063f37e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063f381  8b28                 mov ebp, dword ptr [eax]
// 0063f383  85d2                 test edx, edx
// 0063f385  7404                 je 0x63f38b
// 0063f387  3bd2                 cmp edx, edx
// 0063f389  7406                 je 0x63f391
// 0063f38b  ff15ace98900         call dword ptr [0x89e9ac]
// 0063f391  8d4c2414             lea ecx, [esp + 0x14]
// 0063f395  3bf5                 cmp esi, ebp
// 0063f397  752a                 jne 0x63f3c3
// 0063f399  53                   push ebx
// 0063f39a  56                   push esi
// 0063f39b  6a01                 push 1
// 0063f39d  51                   push ecx
// 0063f39e  8bcf                 mov ecx, edi
// 0063f3a0  e87b590b00           call 0x6f4d20
// 0063f3a5  5f                   pop edi
// 0063f3a6  8bc8                 mov ecx, eax
// 0063f3a8  8b11                 mov edx, dword ptr [ecx]
// 0063f3aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063f3ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063f3b1  5e                   pop esi
// 0063f3b2  5d                   pop ebp
// 0063f3b3  894804               mov dword ptr [eax + 4], ecx
// 0063f3b6  c6400801             mov byte ptr [eax + 8], 1
// 0063f3ba  8910                 mov dword ptr [eax], edx
// 0063f3bc  5b                   pop ebx
// 0063f3bd  83c40c               add esp, 0xc
// 0063f3c0  c20800               ret 8
// 0063f3c3  e828670600           call 0x6a5af0
// 0063f3c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0063f3cc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0063f3d0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0063f3d3  3b03                 cmp eax, dword ptr [ebx]
// 0063f3d5  7d31                 jge 0x63f408
// 0063f3d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063f3db  53                   push ebx
// 0063f3dc  56                   push esi
// 0063f3dd  51                   push ecx
// 0063f3de  8d542420             lea edx, [esp + 0x20]
// 0063f3e2  52                   push edx
// 0063f3e3  8bcf                 mov ecx, edi
// 0063f3e5  e836590b00           call 0x6f4d20
// 0063f3ea  5f                   pop edi
// 0063f3eb  8bc8                 mov ecx, eax
// 0063f3ed  8b11                 mov edx, dword ptr [ecx]
// 0063f3ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063f3f3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063f3f6  5e                   pop esi
// 0063f3f7  5d                   pop ebp
// 0063f3f8  894804               mov dword ptr [eax + 4], ecx
// 0063f3fb  c6400801             mov byte ptr [eax + 8], 1
// 0063f3ff  8910                 mov dword ptr [eax], edx
// 0063f401  5b                   pop ebx
// 0063f402  83c40c               add esp, 0xc
// 0063f405  c20800               ret 8
// 0063f408  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063f40c  5f                   pop edi
// 0063f40d  5e                   pop esi
// 0063f40e  896804               mov dword ptr [eax + 4], ebp
// 0063f411  5d                   pop ebp
// 0063f412  c6400800             mov byte ptr [eax + 8], 0
// 0063f416  8910                 mov dword ptr [eax], edx
// 0063f418  5b                   pop ebx
// 0063f419  83c40c               add esp, 0xc
// 0063f41c  c20800               ret 8
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

// from server: 100% by auto
// roc 2010-06 006e7f00  unit: RBX::VInstance::?$NonFactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e7f00
//
// 006e7f00  83ec0c               sub esp, 0xc
// 006e7f03  53                   push ebx
// 006e7f04  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006e7f08  55                   push ebp
// 006e7f09  56                   push esi
// 006e7f0a  57                   push edi
// 006e7f0b  8bf9                 mov edi, ecx
// 006e7f0d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006e7f10  8b4604               mov eax, dword ptr [esi + 4]
// 006e7f13  80781500             cmp byte ptr [eax + 0x15], 0
// 006e7f17  b101                 mov cl, 1
// 006e7f19  884c2410             mov byte ptr [esp + 0x10], cl
// 006e7f1d  751f                 jne 0x6e7f3e
// 006e7f1f  8b13                 mov edx, dword ptr [ebx]
// 006e7f21  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006e7f24  8bf0                 mov esi, eax
// 006e7f26  0f9cc1               setl cl
// 006e7f29  884c2410             mov byte ptr [esp + 0x10], cl
// 006e7f2d  84c9                 test cl, cl
// 006e7f2f  7404                 je 0x6e7f35
// 006e7f31  8b00                 mov eax, dword ptr [eax]
// 006e7f33  eb03                 jmp 0x6e7f38
// 006e7f35  8b4008               mov eax, dword ptr [eax + 8]
// 006e7f38  80781500             cmp byte ptr [eax + 0x15], 0
// 006e7f3c  74e3                 je 0x6e7f21
// 006e7f3e  8b17                 mov edx, dword ptr [edi]
// 006e7f40  8bee                 mov ebp, esi
// 006e7f42  896c2418             mov dword ptr [esp + 0x18], ebp
// 006e7f46  89542414             mov dword ptr [esp + 0x14], edx
// 006e7f4a  84c9                 test cl, cl
// 006e7f4c  7452                 je 0x6e7fa0
// 006e7f4e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e7f51  8b28                 mov ebp, dword ptr [eax]
// 006e7f53  85d2                 test edx, edx
// 006e7f55  7404                 je 0x6e7f5b
// 006e7f57  3bd2                 cmp edx, edx
// 006e7f59  7406                 je 0x6e7f61
// 006e7f5b  ff150ca99e00         call dword ptr [0x9ea90c]
// 006e7f61  8d4c2414             lea ecx, [esp + 0x14]
// 006e7f65  3bf5                 cmp esi, ebp
// 006e7f67  752a                 jne 0x6e7f93
// 006e7f69  53                   push ebx
// 006e7f6a  56                   push esi
// 006e7f6b  6a01                 push 1
// 006e7f6d  51                   push ecx
// 006e7f6e  8bcf                 mov ecx, edi
// 006e7f70  e8bb300a00           call 0x78b030
// 006e7f75  5f                   pop edi
// 006e7f76  8bc8                 mov ecx, eax
// 006e7f78  8b11                 mov edx, dword ptr [ecx]
// 006e7f7a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e7f7e  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e7f81  5e                   pop esi
// 006e7f82  5d                   pop ebp
// 006e7f83  894804               mov dword ptr [eax + 4], ecx
// 006e7f86  c6400801             mov byte ptr [eax + 8], 1
// 006e7f8a  8910                 mov dword ptr [eax], edx
// 006e7f8c  5b                   pop ebx
// 006e7f8d  83c40c               add esp, 0xc
// 006e7f90  c20800               ret 8
// 006e7f93  e8a81c0200           call 0x709c40
// 006e7f98  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006e7f9c  8b542414             mov edx, dword ptr [esp + 0x14]
// 006e7fa0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006e7fa3  3b03                 cmp eax, dword ptr [ebx]
// 006e7fa5  7d31                 jge 0x6e7fd8
// 006e7fa7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006e7fab  53                   push ebx
// 006e7fac  56                   push esi
// 006e7fad  51                   push ecx
// 006e7fae  8d542420             lea edx, [esp + 0x20]
// 006e7fb2  52                   push edx
// 006e7fb3  8bcf                 mov ecx, edi
// 006e7fb5  e876300a00           call 0x78b030
// 006e7fba  5f                   pop edi
// 006e7fbb  8bc8                 mov ecx, eax
// 006e7fbd  8b11                 mov edx, dword ptr [ecx]
// 006e7fbf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e7fc3  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e7fc6  5e                   pop esi
// 006e7fc7  5d                   pop ebp
// 006e7fc8  894804               mov dword ptr [eax + 4], ecx
// 006e7fcb  c6400801             mov byte ptr [eax + 8], 1
// 006e7fcf  8910                 mov dword ptr [eax], edx
// 006e7fd1  5b                   pop ebx
// 006e7fd2  83c40c               add esp, 0xc
// 006e7fd5  c20800               ret 8
// 006e7fd8  8b442420             mov eax, dword ptr [esp + 0x20]
// 006e7fdc  5f                   pop edi
// 006e7fdd  5e                   pop esi
// 006e7fde  896804               mov dword ptr [eax + 4], ebp
// 006e7fe1  5d                   pop ebp
// 006e7fe2  c6400800             mov byte ptr [eax + 8], 0
// 006e7fe6  8910                 mov dword ptr [eax], edx
// 006e7fe8  5b                   pop ebx
// 006e7fe9  83c40c               add esp, 0xc
// 006e7fec  c20800               ret 8
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

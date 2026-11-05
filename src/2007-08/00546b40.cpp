// from server: 100% by auto
// roc 2007-08 00546b40  unit: RBX::MD5HasherImpl  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00546b40
//
// 00546b40  64a100000000         mov eax, dword ptr fs:[0]
// 00546b46  6aff                 push -1
// 00546b48  68b2417500           push 0x7541b2
// 00546b4d  50                   push eax
// 00546b4e  64892500000000       mov dword ptr fs:[0], esp
// 00546b55  83ec44               sub esp, 0x44
// 00546b58  57                   push edi
// 00546b59  8bf9                 mov edi, ecx
// 00546b5b  817f0854555505       cmp dword ptr [edi + 8], 0x5555554
// 00546b62  7259                 jb 0x546bbd
// 00546b64  68904f7800           push 0x784f90
// 00546b69  8d4c2408             lea ecx, [esp + 8]
// 00546b6d  ff1598e67700         call dword ptr [0x77e698]
// 00546b73  8d4c2420             lea ecx, [esp + 0x20]
// 00546b77  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00546b7f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00546b85  8d442404             lea eax, [esp + 4]
// 00546b89  50                   push eax
// 00546b8a  8d4c2430             lea ecx, [esp + 0x30]
// 00546b8e  c644245401           mov byte ptr [esp + 0x54], 1
// 00546b93  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 00546b9b  ff159ce67700         call dword ptr [0x77e69c]
// 00546ba1  6878f78300           push 0x83f778
// 00546ba6  8d4c2424             lea ecx, [esp + 0x24]
// 00546baa  51                   push ecx
// 00546bab  c644245800           mov byte ptr [esp + 0x58], 0
// 00546bb0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 00546bb8  e8e19f0e00           call 0x630b9e
// 00546bbd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00546bc1  8b4704               mov eax, dword ptr [edi + 4]
// 00546bc4  53                   push ebx
// 00546bc5  55                   push ebp
// 00546bc6  56                   push esi
// 00546bc7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00546bcb  6a00                 push 0
// 00546bcd  52                   push edx
// 00546bce  50                   push eax
// 00546bcf  56                   push esi
// 00546bd0  50                   push eax
// 00546bd1  e81afaffff           call 0x5465f0
// 00546bd6  8be8                 mov ebp, eax
// 00546bd8  8b4704               mov eax, dword ptr [edi + 4]
// 00546bdb  bb01000000           mov ebx, 1
// 00546be0  015f08               add dword ptr [edi + 8], ebx
// 00546be3  3bf0                 cmp esi, eax
// 00546be5  7510                 jne 0x546bf7
// 00546be7  896804               mov dword ptr [eax + 4], ebp
// 00546bea  8b4704               mov eax, dword ptr [edi + 4]
// 00546bed  8928                 mov dword ptr [eax], ebp
// 00546bef  8b4f04               mov ecx, dword ptr [edi + 4]
// 00546bf2  896908               mov dword ptr [ecx + 8], ebp
// 00546bf5  eb22                 jmp 0x546c19
// 00546bf7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00546bfc  740d                 je 0x546c0b
// 00546bfe  892e                 mov dword ptr [esi], ebp
// 00546c00  8b4704               mov eax, dword ptr [edi + 4]
// 00546c03  3b30                 cmp esi, dword ptr [eax]
// 00546c05  7512                 jne 0x546c19
// 00546c07  8928                 mov dword ptr [eax], ebp
// 00546c09  eb0e                 jmp 0x546c19
// 00546c0b  896e08               mov dword ptr [esi + 8], ebp
// 00546c0e  8b4704               mov eax, dword ptr [edi + 4]
// 00546c11  3b7008               cmp esi, dword ptr [eax + 8]
// 00546c14  7503                 jne 0x546c19
// 00546c16  896808               mov dword ptr [eax + 8], ebp
// 00546c19  8b5504               mov edx, dword ptr [ebp + 4]
// 00546c1c  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 00546c20  8d4504               lea eax, [ebp + 4]
// 00546c23  8bf5                 mov esi, ebp
// 00546c25  0f85ea000000         jne 0x546d15
// 00546c2b  eb03                 jmp 0x546c30
// 00546c2d  8d4900               lea ecx, [ecx]
// 00546c30  8b08                 mov ecx, dword ptr [eax]
// 00546c32  8b5104               mov edx, dword ptr [ecx + 4]
// 00546c35  3b0a                 cmp ecx, dword ptr [edx]
// 00546c37  7551                 jne 0x546c8a
// 00546c39  8b5208               mov edx, dword ptr [edx + 8]
// 00546c3c  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 00546c40  7519                 jne 0x546c5b
// 00546c42  88593c               mov byte ptr [ecx + 0x3c], bl
// 00546c45  885a3c               mov byte ptr [edx + 0x3c], bl
// 00546c48  8b10                 mov edx, dword ptr [eax]
// 00546c4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00546c4d  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 00546c51  8b10                 mov edx, dword ptr [eax]
// 00546c53  8b7204               mov esi, dword ptr [edx + 4]
// 00546c56  e9aa000000           jmp 0x546d05
// 00546c5b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00546c5e  750a                 jne 0x546c6a
// 00546c60  8bf1                 mov esi, ecx
// 00546c62  56                   push esi
// 00546c63  8bcf                 mov ecx, edi
// 00546c65  e826edffff           call 0x545990
// 00546c6a  8b4604               mov eax, dword ptr [esi + 4]
// 00546c6d  88583c               mov byte ptr [eax + 0x3c], bl
// 00546c70  8b4e04               mov ecx, dword ptr [esi + 4]
// 00546c73  8b5104               mov edx, dword ptr [ecx + 4]
// 00546c76  c6423c00             mov byte ptr [edx + 0x3c], 0
// 00546c7a  8b4604               mov eax, dword ptr [esi + 4]
// 00546c7d  8b4804               mov ecx, dword ptr [eax + 4]
// 00546c80  51                   push ecx
// 00546c81  8bcf                 mov ecx, edi
// 00546c83  e858edffff           call 0x5459e0
// 00546c88  eb7b                 jmp 0x546d05
// 00546c8a  8b12                 mov edx, dword ptr [edx]
// 00546c8c  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 00546c90  7516                 jne 0x546ca8
// 00546c92  88593c               mov byte ptr [ecx + 0x3c], bl
// 00546c95  885a3c               mov byte ptr [edx + 0x3c], bl
// 00546c98  8b10                 mov edx, dword ptr [eax]
// 00546c9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00546c9d  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 00546ca1  8b10                 mov edx, dword ptr [eax]
// 00546ca3  8b7204               mov esi, dword ptr [edx + 4]
// 00546ca6  eb5d                 jmp 0x546d05
// 00546ca8  3b31                 cmp esi, dword ptr [ecx]
// 00546caa  750a                 jne 0x546cb6
// 00546cac  8bf1                 mov esi, ecx
// 00546cae  56                   push esi
// 00546caf  8bcf                 mov ecx, edi
// 00546cb1  e82aedffff           call 0x5459e0
// 00546cb6  8b4604               mov eax, dword ptr [esi + 4]
// 00546cb9  88583c               mov byte ptr [eax + 0x3c], bl
// 00546cbc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00546cbf  8b5104               mov edx, dword ptr [ecx + 4]
// 00546cc2  c6423c00             mov byte ptr [edx + 0x3c], 0
// 00546cc6  8b4604               mov eax, dword ptr [esi + 4]
// 00546cc9  8b4004               mov eax, dword ptr [eax + 4]
// 00546ccc  8b4808               mov ecx, dword ptr [eax + 8]
// 00546ccf  8b11                 mov edx, dword ptr [ecx]
// 00546cd1  895008               mov dword ptr [eax + 8], edx
// 00546cd4  8b11                 mov edx, dword ptr [ecx]
// 00546cd6  807a3d00             cmp byte ptr [edx + 0x3d], 0
// 00546cda  7503                 jne 0x546cdf
// 00546cdc  894204               mov dword ptr [edx + 4], eax
// 00546cdf  8b5004               mov edx, dword ptr [eax + 4]
// 00546ce2  895104               mov dword ptr [ecx + 4], edx
// 00546ce5  8b5704               mov edx, dword ptr [edi + 4]
// 00546ce8  3b4204               cmp eax, dword ptr [edx + 4]
// 00546ceb  7505                 jne 0x546cf2
// 00546ced  894a04               mov dword ptr [edx + 4], ecx
// 00546cf0  eb0e                 jmp 0x546d00
// 00546cf2  8b5004               mov edx, dword ptr [eax + 4]
// 00546cf5  3b02                 cmp eax, dword ptr [edx]
// 00546cf7  7504                 jne 0x546cfd
// 00546cf9  890a                 mov dword ptr [edx], ecx
// 00546cfb  eb03                 jmp 0x546d00
// 00546cfd  894a08               mov dword ptr [edx + 8], ecx
// 00546d00  8901                 mov dword ptr [ecx], eax
// 00546d02  894804               mov dword ptr [eax + 4], ecx
// 00546d05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00546d08  80793c00             cmp byte ptr [ecx + 0x3c], 0
// 00546d0c  8d4604               lea eax, [esi + 4]
// 00546d0f  0f841bffffff         je 0x546c30
// 00546d15  8b5704               mov edx, dword ptr [edi + 4]
// 00546d18  8b4204               mov eax, dword ptr [edx + 4]
// 00546d1b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00546d1f  88583c               mov byte ptr [eax + 0x3c], bl
// 00546d22  8b442464             mov eax, dword ptr [esp + 0x64]
// 00546d26  5e                   pop esi
// 00546d27  896804               mov dword ptr [eax + 4], ebp
// 00546d2a  5d                   pop ebp
// 00546d2b  8938                 mov dword ptr [eax], edi
// 00546d2d  5b                   pop ebx
// 00546d2e  5f                   pop edi
// 00546d2f  64890d00000000       mov dword ptr fs:[0], ecx
// 00546d36  83c450               add esp, 0x50
// 00546d39  c21000               ret 0x10
// standard library map_str<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

// from server: 100% by auto
// roc 2009-12 0048f3d0  unit: RBX::RbxTextureProxy  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f3d0
//
// 0048f3d0  83ec0c               sub esp, 0xc
// 0048f3d3  53                   push ebx
// 0048f3d4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0048f3d8  55                   push ebp
// 0048f3d9  56                   push esi
// 0048f3da  57                   push edi
// 0048f3db  8bf9                 mov edi, ecx
// 0048f3dd  8b7718               mov esi, dword ptr [edi + 0x18]
// 0048f3e0  8b4604               mov eax, dword ptr [esi + 4]
// 0048f3e3  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f3e7  b101                 mov cl, 1
// 0048f3e9  884c2410             mov byte ptr [esp + 0x10], cl
// 0048f3ed  751f                 jne 0x48f40e
// 0048f3ef  8b13                 mov edx, dword ptr [ebx]
// 0048f3f1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0048f3f4  8bf0                 mov esi, eax
// 0048f3f6  0f92c1               setb cl
// 0048f3f9  884c2410             mov byte ptr [esp + 0x10], cl
// 0048f3fd  84c9                 test cl, cl
// 0048f3ff  7404                 je 0x48f405
// 0048f401  8b00                 mov eax, dword ptr [eax]
// 0048f403  eb03                 jmp 0x48f408
// 0048f405  8b4008               mov eax, dword ptr [eax + 8]
// 0048f408  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f40c  74e3                 je 0x48f3f1
// 0048f40e  8b17                 mov edx, dword ptr [edi]
// 0048f410  8bee                 mov ebp, esi
// 0048f412  896c2418             mov dword ptr [esp + 0x18], ebp
// 0048f416  89542414             mov dword ptr [esp + 0x14], edx
// 0048f41a  84c9                 test cl, cl
// 0048f41c  7452                 je 0x48f470
// 0048f41e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048f421  8b28                 mov ebp, dword ptr [eax]
// 0048f423  85d2                 test edx, edx
// 0048f425  7404                 je 0x48f42b
// 0048f427  3bd2                 cmp edx, edx
// 0048f429  7406                 je 0x48f431
// 0048f42b  ff1560b79800         call dword ptr [0x98b760]
// 0048f431  8d4c2414             lea ecx, [esp + 0x14]
// 0048f435  3bf5                 cmp esi, ebp
// 0048f437  752a                 jne 0x48f463
// 0048f439  53                   push ebx
// 0048f43a  56                   push esi
// 0048f43b  6a01                 push 1
// 0048f43d  51                   push ecx
// 0048f43e  8bcf                 mov ecx, edi
// 0048f440  e88bfdffff           call 0x48f1d0
// 0048f445  5f                   pop edi
// 0048f446  8bc8                 mov ecx, eax
// 0048f448  8b11                 mov edx, dword ptr [ecx]
// 0048f44a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048f44e  8b4904               mov ecx, dword ptr [ecx + 4]
// 0048f451  5e                   pop esi
// 0048f452  5d                   pop ebp
// 0048f453  894804               mov dword ptr [eax + 4], ecx
// 0048f456  c6400801             mov byte ptr [eax + 8], 1
// 0048f45a  8910                 mov dword ptr [eax], edx
// 0048f45c  5b                   pop ebx
// 0048f45d  83c40c               add esp, 0xc
// 0048f460  c20800               ret 8
// 0048f463  e868de1300           call 0x5cd2d0
// 0048f468  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0048f46c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048f470  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0048f473  3b03                 cmp eax, dword ptr [ebx]
// 0048f475  7331                 jae 0x48f4a8
// 0048f477  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048f47b  53                   push ebx
// 0048f47c  56                   push esi
// 0048f47d  51                   push ecx
// 0048f47e  8d542420             lea edx, [esp + 0x20]
// 0048f482  52                   push edx
// 0048f483  8bcf                 mov ecx, edi
// 0048f485  e846fdffff           call 0x48f1d0
// 0048f48a  5f                   pop edi
// 0048f48b  8bc8                 mov ecx, eax
// 0048f48d  8b11                 mov edx, dword ptr [ecx]
// 0048f48f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048f493  8b4904               mov ecx, dword ptr [ecx + 4]
// 0048f496  5e                   pop esi
// 0048f497  5d                   pop ebp
// 0048f498  894804               mov dword ptr [eax + 4], ecx
// 0048f49b  c6400801             mov byte ptr [eax + 8], 1
// 0048f49f  8910                 mov dword ptr [eax], edx
// 0048f4a1  5b                   pop ebx
// 0048f4a2  83c40c               add esp, 0xc
// 0048f4a5  c20800               ret 8
// 0048f4a8  8b442420             mov eax, dword ptr [esp + 0x20]
// 0048f4ac  5f                   pop edi
// 0048f4ad  5e                   pop esi
// 0048f4ae  896804               mov dword ptr [eax + 4], ebp
// 0048f4b1  5d                   pop ebp
// 0048f4b2  c6400800             mov byte ptr [eax + 8], 0
// 0048f4b6  8910                 mov dword ptr [eax], edx
// 0048f4b8  5b                   pop ebx
// 0048f4b9  83c40c               add esp, 0xc
// 0048f4bc  c20800               ret 8
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;

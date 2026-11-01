// from server: 100% by auto
// roc 2009-12 00763db0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00763db0
//
// 00763db0  83ec0c               sub esp, 0xc
// 00763db3  53                   push ebx
// 00763db4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00763db8  55                   push ebp
// 00763db9  56                   push esi
// 00763dba  57                   push edi
// 00763dbb  8bf9                 mov edi, ecx
// 00763dbd  8b7718               mov esi, dword ptr [edi + 0x18]
// 00763dc0  8b4604               mov eax, dword ptr [esi + 4]
// 00763dc3  80783100             cmp byte ptr [eax + 0x31], 0
// 00763dc7  b101                 mov cl, 1
// 00763dc9  884c2410             mov byte ptr [esp + 0x10], cl
// 00763dcd  751f                 jne 0x763dee
// 00763dcf  8b13                 mov edx, dword ptr [ebx]
// 00763dd1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00763dd4  8bf0                 mov esi, eax
// 00763dd6  0f9cc1               setl cl
// 00763dd9  884c2410             mov byte ptr [esp + 0x10], cl
// 00763ddd  84c9                 test cl, cl
// 00763ddf  7404                 je 0x763de5
// 00763de1  8b00                 mov eax, dword ptr [eax]
// 00763de3  eb03                 jmp 0x763de8
// 00763de5  8b4008               mov eax, dword ptr [eax + 8]
// 00763de8  80783100             cmp byte ptr [eax + 0x31], 0
// 00763dec  74e3                 je 0x763dd1
// 00763dee  8b17                 mov edx, dword ptr [edi]
// 00763df0  8bee                 mov ebp, esi
// 00763df2  896c2418             mov dword ptr [esp + 0x18], ebp
// 00763df6  89542414             mov dword ptr [esp + 0x14], edx
// 00763dfa  84c9                 test cl, cl
// 00763dfc  7452                 je 0x763e50
// 00763dfe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00763e01  8b28                 mov ebp, dword ptr [eax]
// 00763e03  85d2                 test edx, edx
// 00763e05  7404                 je 0x763e0b
// 00763e07  3bd2                 cmp edx, edx
// 00763e09  7406                 je 0x763e11
// 00763e0b  ff1560b79800         call dword ptr [0x98b760]
// 00763e11  8d4c2414             lea ecx, [esp + 0x14]
// 00763e15  3bf5                 cmp esi, ebp
// 00763e17  752a                 jne 0x763e43
// 00763e19  53                   push ebx
// 00763e1a  56                   push esi
// 00763e1b  6a01                 push 1
// 00763e1d  51                   push ecx
// 00763e1e  8bcf                 mov ecx, edi
// 00763e20  e83bf0ffff           call 0x762e60
// 00763e25  5f                   pop edi
// 00763e26  8bc8                 mov ecx, eax
// 00763e28  8b11                 mov edx, dword ptr [ecx]
// 00763e2a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00763e2e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00763e31  5e                   pop esi
// 00763e32  5d                   pop ebp
// 00763e33  894804               mov dword ptr [eax + 4], ecx
// 00763e36  c6400801             mov byte ptr [eax + 8], 1
// 00763e3a  8910                 mov dword ptr [eax], edx
// 00763e3c  5b                   pop ebx
// 00763e3d  83c40c               add esp, 0xc
// 00763e40  c20800               ret 8
// 00763e43  e818fadaff           call 0x513860
// 00763e48  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00763e4c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00763e50  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00763e53  3b03                 cmp eax, dword ptr [ebx]
// 00763e55  7d31                 jge 0x763e88
// 00763e57  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00763e5b  53                   push ebx
// 00763e5c  56                   push esi
// 00763e5d  51                   push ecx
// 00763e5e  8d542420             lea edx, [esp + 0x20]
// 00763e62  52                   push edx
// 00763e63  8bcf                 mov ecx, edi
// 00763e65  e8f6efffff           call 0x762e60
// 00763e6a  5f                   pop edi
// 00763e6b  8bc8                 mov ecx, eax
// 00763e6d  8b11                 mov edx, dword ptr [ecx]
// 00763e6f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00763e73  8b4904               mov ecx, dword ptr [ecx + 4]
// 00763e76  5e                   pop esi
// 00763e77  5d                   pop ebp
// 00763e78  894804               mov dword ptr [eax + 4], ecx
// 00763e7b  c6400801             mov byte ptr [eax + 8], 1
// 00763e7f  8910                 mov dword ptr [eax], edx
// 00763e81  5b                   pop ebx
// 00763e82  83c40c               add esp, 0xc
// 00763e85  c20800               ret 8
// 00763e88  8b442420             mov eax, dword ptr [esp + 0x20]
// 00763e8c  5f                   pop edi
// 00763e8d  5e                   pop esi
// 00763e8e  896804               mov dword ptr [eax + 4], ebp
// 00763e91  5d                   pop ebp
// 00763e92  c6400800             mov byte ptr [eax + 8], 0
// 00763e96  8910                 mov dword ptr [eax], edx
// 00763e98  5b                   pop ebx
// 00763e99  83c40c               add esp, 0xc
// 00763e9c  c20800               ret 8
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;

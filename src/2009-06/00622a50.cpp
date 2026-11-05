// from server: 100% by auto
// roc 2009-06 00622a50  unit: RBX::RootInstance  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622a50
//
// 00622a50  83ec0c               sub esp, 0xc
// 00622a53  53                   push ebx
// 00622a54  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00622a58  55                   push ebp
// 00622a59  56                   push esi
// 00622a5a  57                   push edi
// 00622a5b  8bf9                 mov edi, ecx
// 00622a5d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00622a60  8b4604               mov eax, dword ptr [esi + 4]
// 00622a63  80781900             cmp byte ptr [eax + 0x19], 0
// 00622a67  b101                 mov cl, 1
// 00622a69  884c2410             mov byte ptr [esp + 0x10], cl
// 00622a6d  751f                 jne 0x622a8e
// 00622a6f  8b13                 mov edx, dword ptr [ebx]
// 00622a71  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00622a74  8bf0                 mov esi, eax
// 00622a76  0f92c1               setb cl
// 00622a79  884c2410             mov byte ptr [esp + 0x10], cl
// 00622a7d  84c9                 test cl, cl
// 00622a7f  7404                 je 0x622a85
// 00622a81  8b00                 mov eax, dword ptr [eax]
// 00622a83  eb03                 jmp 0x622a88
// 00622a85  8b4008               mov eax, dword ptr [eax + 8]
// 00622a88  80781900             cmp byte ptr [eax + 0x19], 0
// 00622a8c  74e3                 je 0x622a71
// 00622a8e  8b17                 mov edx, dword ptr [edi]
// 00622a90  8bee                 mov ebp, esi
// 00622a92  896c2418             mov dword ptr [esp + 0x18], ebp
// 00622a96  89542414             mov dword ptr [esp + 0x14], edx
// 00622a9a  84c9                 test cl, cl
// 00622a9c  7452                 je 0x622af0
// 00622a9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00622aa1  8b28                 mov ebp, dword ptr [eax]
// 00622aa3  85d2                 test edx, edx
// 00622aa5  7404                 je 0x622aab
// 00622aa7  3bd2                 cmp edx, edx
// 00622aa9  7406                 je 0x622ab1
// 00622aab  ff15ace98900         call dword ptr [0x89e9ac]
// 00622ab1  8d4c2414             lea ecx, [esp + 0x14]
// 00622ab5  3bf5                 cmp esi, ebp
// 00622ab7  752a                 jne 0x622ae3
// 00622ab9  53                   push ebx
// 00622aba  56                   push esi
// 00622abb  6a01                 push 1
// 00622abd  51                   push ecx
// 00622abe  8bcf                 mov ecx, edi
// 00622ac0  e88b1e0200           call 0x644950
// 00622ac5  5f                   pop edi
// 00622ac6  8bc8                 mov ecx, eax
// 00622ac8  8b11                 mov edx, dword ptr [ecx]
// 00622aca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00622ace  8b4904               mov ecx, dword ptr [ecx + 4]
// 00622ad1  5e                   pop esi
// 00622ad2  5d                   pop ebp
// 00622ad3  894804               mov dword ptr [eax + 4], ecx
// 00622ad6  c6400801             mov byte ptr [eax + 8], 1
// 00622ada  8910                 mov dword ptr [eax], edx
// 00622adc  5b                   pop ebx
// 00622add  83c40c               add esp, 0xc
// 00622ae0  c20800               ret 8
// 00622ae3  e8c813ecff           call 0x4e3eb0
// 00622ae8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00622aec  8b542414             mov edx, dword ptr [esp + 0x14]
// 00622af0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00622af3  3b03                 cmp eax, dword ptr [ebx]
// 00622af5  7331                 jae 0x622b28
// 00622af7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00622afb  53                   push ebx
// 00622afc  56                   push esi
// 00622afd  51                   push ecx
// 00622afe  8d542420             lea edx, [esp + 0x20]
// 00622b02  52                   push edx
// 00622b03  8bcf                 mov ecx, edi
// 00622b05  e8461e0200           call 0x644950
// 00622b0a  5f                   pop edi
// 00622b0b  8bc8                 mov ecx, eax
// 00622b0d  8b11                 mov edx, dword ptr [ecx]
// 00622b0f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00622b13  8b4904               mov ecx, dword ptr [ecx + 4]
// 00622b16  5e                   pop esi
// 00622b17  5d                   pop ebp
// 00622b18  894804               mov dword ptr [eax + 4], ecx
// 00622b1b  c6400801             mov byte ptr [eax + 8], 1
// 00622b1f  8910                 mov dword ptr [eax], edx
// 00622b21  5b                   pop ebx
// 00622b22  83c40c               add esp, 0xc
// 00622b25  c20800               ret 8
// 00622b28  8b442420             mov eax, dword ptr [esp + 0x20]
// 00622b2c  5f                   pop edi
// 00622b2d  5e                   pop esi
// 00622b2e  896804               mov dword ptr [eax + 4], ebp
// 00622b31  5d                   pop ebp
// 00622b32  c6400800             mov byte ptr [eax + 8], 0
// 00622b36  8910                 mov dword ptr [eax], edx
// 00622b38  5b                   pop ebx
// 00622b39  83c40c               add esp, 0xc
// 00622b3c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;

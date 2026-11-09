// from server: 100% by auto
// roc 2009-06 004e6d60  unit: RBX::Network::DirectPhysicsReceiver  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e6d60
//
// 004e6d60  83ec0c               sub esp, 0xc
// 004e6d63  53                   push ebx
// 004e6d64  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004e6d68  55                   push ebp
// 004e6d69  56                   push esi
// 004e6d6a  57                   push edi
// 004e6d6b  8bf9                 mov edi, ecx
// 004e6d6d  8b7718               mov esi, dword ptr [edi + 0x18]
// 004e6d70  8b4604               mov eax, dword ptr [esi + 4]
// 004e6d73  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004e6d77  b101                 mov cl, 1
// 004e6d79  884c2410             mov byte ptr [esp + 0x10], cl
// 004e6d7d  751f                 jne 0x4e6d9e
// 004e6d7f  8b13                 mov edx, dword ptr [ebx]
// 004e6d81  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004e6d84  8bf0                 mov esi, eax
// 004e6d86  0f92c1               setb cl
// 004e6d89  884c2410             mov byte ptr [esp + 0x10], cl
// 004e6d8d  84c9                 test cl, cl
// 004e6d8f  7404                 je 0x4e6d95
// 004e6d91  8b00                 mov eax, dword ptr [eax]
// 004e6d93  eb03                 jmp 0x4e6d98
// 004e6d95  8b4008               mov eax, dword ptr [eax + 8]
// 004e6d98  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004e6d9c  74e3                 je 0x4e6d81
// 004e6d9e  8b17                 mov edx, dword ptr [edi]
// 004e6da0  8bee                 mov ebp, esi
// 004e6da2  896c2418             mov dword ptr [esp + 0x18], ebp
// 004e6da6  89542414             mov dword ptr [esp + 0x14], edx
// 004e6daa  84c9                 test cl, cl
// 004e6dac  7452                 je 0x4e6e00
// 004e6dae  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e6db1  8b28                 mov ebp, dword ptr [eax]
// 004e6db3  85d2                 test edx, edx
// 004e6db5  7404                 je 0x4e6dbb
// 004e6db7  3bd2                 cmp edx, edx
// 004e6db9  7406                 je 0x4e6dc1
// 004e6dbb  ff15ace98900         call dword ptr [0x89e9ac]
// 004e6dc1  8d4c2414             lea ecx, [esp + 0x14]
// 004e6dc5  3bf5                 cmp esi, ebp
// 004e6dc7  752a                 jne 0x4e6df3
// 004e6dc9  53                   push ebx
// 004e6dca  56                   push esi
// 004e6dcb  6a01                 push 1
// 004e6dcd  51                   push ecx
// 004e6dce  8bcf                 mov ecx, edi
// 004e6dd0  e8ebf4ffff           call 0x4e62c0
// 004e6dd5  5f                   pop edi
// 004e6dd6  8bc8                 mov ecx, eax
// 004e6dd8  8b11                 mov edx, dword ptr [ecx]
// 004e6dda  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e6dde  8b4904               mov ecx, dword ptr [ecx + 4]
// 004e6de1  5e                   pop esi
// 004e6de2  5d                   pop ebp
// 004e6de3  894804               mov dword ptr [eax + 4], ecx
// 004e6de6  c6400801             mov byte ptr [eax + 8], 1
// 004e6dea  8910                 mov dword ptr [eax], edx
// 004e6dec  5b                   pop ebx
// 004e6ded  83c40c               add esp, 0xc
// 004e6df0  c20800               ret 8
// 004e6df3  e858471100           call 0x5fb550
// 004e6df8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004e6dfc  8b542414             mov edx, dword ptr [esp + 0x14]
// 004e6e00  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004e6e03  3b03                 cmp eax, dword ptr [ebx]
// 004e6e05  7331                 jae 0x4e6e38
// 004e6e07  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e6e0b  53                   push ebx
// 004e6e0c  56                   push esi
// 004e6e0d  51                   push ecx
// 004e6e0e  8d542420             lea edx, [esp + 0x20]
// 004e6e12  52                   push edx
// 004e6e13  8bcf                 mov ecx, edi
// 004e6e15  e8a6f4ffff           call 0x4e62c0
// 004e6e1a  5f                   pop edi
// 004e6e1b  8bc8                 mov ecx, eax
// 004e6e1d  8b11                 mov edx, dword ptr [ecx]
// 004e6e1f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e6e23  8b4904               mov ecx, dword ptr [ecx + 4]
// 004e6e26  5e                   pop esi
// 004e6e27  5d                   pop ebp
// 004e6e28  894804               mov dword ptr [eax + 4], ecx
// 004e6e2b  c6400801             mov byte ptr [eax + 8], 1
// 004e6e2f  8910                 mov dword ptr [eax], edx
// 004e6e31  5b                   pop ebx
// 004e6e32  83c40c               add esp, 0xc
// 004e6e35  c20800               ret 8
// 004e6e38  8b442420             mov eax, dword ptr [esp + 0x20]
// 004e6e3c  5f                   pop edi
// 004e6e3d  5e                   pop esi
// 004e6e3e  896804               mov dword ptr [eax + 4], ebp
// 004e6e41  5d                   pop ebp
// 004e6e42  c6400800             mov byte ptr [eax + 8], 0
// 004e6e46  8910                 mov dword ptr [eax], edx
// 004e6e48  5b                   pop ebx
// 004e6e49  83c40c               add esp, 0xc
// 004e6e4c  c20800               ret 8
// standard library map_ptr<string> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@PAUK@@@3@V?$allocator@U?$pair@QAUK@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@PAUK@@@3@V?$allocator@U?$pair@QAUK@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_ptr<string>
#include <string>
typedef std::string E;
#include <map>
struct K; template class std::map<K*, E>;

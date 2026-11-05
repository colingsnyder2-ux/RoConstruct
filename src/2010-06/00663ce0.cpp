// from server: 100% by auto
// roc 2010-06 00663ce0  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00663ce0
//
// 00663ce0  83ec0c               sub esp, 0xc
// 00663ce3  53                   push ebx
// 00663ce4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00663ce8  55                   push ebp
// 00663ce9  56                   push esi
// 00663cea  57                   push edi
// 00663ceb  8bf9                 mov edi, ecx
// 00663ced  8b7718               mov esi, dword ptr [edi + 0x18]
// 00663cf0  8b4604               mov eax, dword ptr [esi + 4]
// 00663cf3  80783100             cmp byte ptr [eax + 0x31], 0
// 00663cf7  b101                 mov cl, 1
// 00663cf9  884c2410             mov byte ptr [esp + 0x10], cl
// 00663cfd  751f                 jne 0x663d1e
// 00663cff  8b13                 mov edx, dword ptr [ebx]
// 00663d01  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00663d04  8bf0                 mov esi, eax
// 00663d06  0f9cc1               setl cl
// 00663d09  884c2410             mov byte ptr [esp + 0x10], cl
// 00663d0d  84c9                 test cl, cl
// 00663d0f  7404                 je 0x663d15
// 00663d11  8b00                 mov eax, dword ptr [eax]
// 00663d13  eb03                 jmp 0x663d18
// 00663d15  8b4008               mov eax, dword ptr [eax + 8]
// 00663d18  80783100             cmp byte ptr [eax + 0x31], 0
// 00663d1c  74e3                 je 0x663d01
// 00663d1e  8b17                 mov edx, dword ptr [edi]
// 00663d20  8bee                 mov ebp, esi
// 00663d22  896c2418             mov dword ptr [esp + 0x18], ebp
// 00663d26  89542414             mov dword ptr [esp + 0x14], edx
// 00663d2a  84c9                 test cl, cl
// 00663d2c  7452                 je 0x663d80
// 00663d2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00663d31  8b28                 mov ebp, dword ptr [eax]
// 00663d33  85d2                 test edx, edx
// 00663d35  7404                 je 0x663d3b
// 00663d37  3bd2                 cmp edx, edx
// 00663d39  7406                 je 0x663d41
// 00663d3b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00663d41  8d4c2414             lea ecx, [esp + 0x14]
// 00663d45  3bf5                 cmp esi, ebp
// 00663d47  752a                 jne 0x663d73
// 00663d49  53                   push ebx
// 00663d4a  56                   push esi
// 00663d4b  6a01                 push 1
// 00663d4d  51                   push ecx
// 00663d4e  8bcf                 mov ecx, edi
// 00663d50  e88bf7ffff           call 0x6634e0
// 00663d55  5f                   pop edi
// 00663d56  8bc8                 mov ecx, eax
// 00663d58  8b11                 mov edx, dword ptr [ecx]
// 00663d5a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00663d5e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00663d61  5e                   pop esi
// 00663d62  5d                   pop ebp
// 00663d63  894804               mov dword ptr [eax + 4], ecx
// 00663d66  c6400801             mov byte ptr [eax + 8], 1
// 00663d6a  8910                 mov dword ptr [eax], edx
// 00663d6c  5b                   pop ebx
// 00663d6d  83c40c               add esp, 0xc
// 00663d70  c20800               ret 8
// 00663d73  e868f7e0ff           call 0x4734e0
// 00663d78  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00663d7c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00663d80  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00663d83  3b03                 cmp eax, dword ptr [ebx]
// 00663d85  7d31                 jge 0x663db8
// 00663d87  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00663d8b  53                   push ebx
// 00663d8c  56                   push esi
// 00663d8d  51                   push ecx
// 00663d8e  8d542420             lea edx, [esp + 0x20]
// 00663d92  52                   push edx
// 00663d93  8bcf                 mov ecx, edi
// 00663d95  e846f7ffff           call 0x6634e0
// 00663d9a  5f                   pop edi
// 00663d9b  8bc8                 mov ecx, eax
// 00663d9d  8b11                 mov edx, dword ptr [ecx]
// 00663d9f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00663da3  8b4904               mov ecx, dword ptr [ecx + 4]
// 00663da6  5e                   pop esi
// 00663da7  5d                   pop ebp
// 00663da8  894804               mov dword ptr [eax + 4], ecx
// 00663dab  c6400801             mov byte ptr [eax + 8], 1
// 00663daf  8910                 mov dword ptr [eax], edx
// 00663db1  5b                   pop ebx
// 00663db2  83c40c               add esp, 0xc
// 00663db5  c20800               ret 8
// 00663db8  8b442420             mov eax, dword ptr [esp + 0x20]
// 00663dbc  5f                   pop edi
// 00663dbd  5e                   pop esi
// 00663dbe  896804               mov dword ptr [eax + 4], ebp
// 00663dc1  5d                   pop ebp
// 00663dc2  c6400800             mov byte ptr [eax + 8], 0
// 00663dc6  8910                 mov dword ptr [eax], edx
// 00663dc8  5b                   pop ebx
// 00663dc9  83c40c               add esp, 0xc
// 00663dcc  c20800               ret 8
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;

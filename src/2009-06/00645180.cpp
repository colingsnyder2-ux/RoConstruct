// from server: 100% by auto
// roc 2009-06 00645180  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00645180
//
// 00645180  83ec0c               sub esp, 0xc
// 00645183  53                   push ebx
// 00645184  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00645188  55                   push ebp
// 00645189  56                   push esi
// 0064518a  57                   push edi
// 0064518b  8bf9                 mov edi, ecx
// 0064518d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00645190  8b4604               mov eax, dword ptr [esi + 4]
// 00645193  80781900             cmp byte ptr [eax + 0x19], 0
// 00645197  b101                 mov cl, 1
// 00645199  884c2410             mov byte ptr [esp + 0x10], cl
// 0064519d  751f                 jne 0x6451be
// 0064519f  8b13                 mov edx, dword ptr [ebx]
// 006451a1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006451a4  8bf0                 mov esi, eax
// 006451a6  0f9cc1               setl cl
// 006451a9  884c2410             mov byte ptr [esp + 0x10], cl
// 006451ad  84c9                 test cl, cl
// 006451af  7404                 je 0x6451b5
// 006451b1  8b00                 mov eax, dword ptr [eax]
// 006451b3  eb03                 jmp 0x6451b8
// 006451b5  8b4008               mov eax, dword ptr [eax + 8]
// 006451b8  80781900             cmp byte ptr [eax + 0x19], 0
// 006451bc  74e3                 je 0x6451a1
// 006451be  8b17                 mov edx, dword ptr [edi]
// 006451c0  8bee                 mov ebp, esi
// 006451c2  896c2418             mov dword ptr [esp + 0x18], ebp
// 006451c6  89542414             mov dword ptr [esp + 0x14], edx
// 006451ca  84c9                 test cl, cl
// 006451cc  7452                 je 0x645220
// 006451ce  8b4718               mov eax, dword ptr [edi + 0x18]
// 006451d1  8b28                 mov ebp, dword ptr [eax]
// 006451d3  85d2                 test edx, edx
// 006451d5  7404                 je 0x6451db
// 006451d7  3bd2                 cmp edx, edx
// 006451d9  7406                 je 0x6451e1
// 006451db  ff15ace98900         call dword ptr [0x89e9ac]
// 006451e1  8d4c2414             lea ecx, [esp + 0x14]
// 006451e5  3bf5                 cmp esi, ebp
// 006451e7  752a                 jne 0x645213
// 006451e9  53                   push ebx
// 006451ea  56                   push esi
// 006451eb  6a01                 push 1
// 006451ed  51                   push ecx
// 006451ee  8bcf                 mov ecx, edi
// 006451f0  e85bf7ffff           call 0x644950
// 006451f5  5f                   pop edi
// 006451f6  8bc8                 mov ecx, eax
// 006451f8  8b11                 mov edx, dword ptr [ecx]
// 006451fa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006451fe  8b4904               mov ecx, dword ptr [ecx + 4]
// 00645201  5e                   pop esi
// 00645202  5d                   pop ebp
// 00645203  894804               mov dword ptr [eax + 4], ecx
// 00645206  c6400801             mov byte ptr [eax + 8], 1
// 0064520a  8910                 mov dword ptr [eax], edx
// 0064520c  5b                   pop ebx
// 0064520d  83c40c               add esp, 0xc
// 00645210  c20800               ret 8
// 00645213  e898ece9ff           call 0x4e3eb0
// 00645218  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0064521c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00645220  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00645223  3b03                 cmp eax, dword ptr [ebx]
// 00645225  7d31                 jge 0x645258
// 00645227  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064522b  53                   push ebx
// 0064522c  56                   push esi
// 0064522d  51                   push ecx
// 0064522e  8d542420             lea edx, [esp + 0x20]
// 00645232  52                   push edx
// 00645233  8bcf                 mov ecx, edi
// 00645235  e816f7ffff           call 0x644950
// 0064523a  5f                   pop edi
// 0064523b  8bc8                 mov ecx, eax
// 0064523d  8b11                 mov edx, dword ptr [ecx]
// 0064523f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00645243  8b4904               mov ecx, dword ptr [ecx + 4]
// 00645246  5e                   pop esi
// 00645247  5d                   pop ebp
// 00645248  894804               mov dword ptr [eax + 4], ecx
// 0064524b  c6400801             mov byte ptr [eax + 8], 1
// 0064524f  8910                 mov dword ptr [eax], edx
// 00645251  5b                   pop ebx
// 00645252  83c40c               add esp, 0xc
// 00645255  c20800               ret 8
// 00645258  8b442420             mov eax, dword ptr [esp + 0x20]
// 0064525c  5f                   pop edi
// 0064525d  5e                   pop esi
// 0064525e  896804               mov dword ptr [eax + 4], ebp
// 00645261  5d                   pop ebp
// 00645262  c6400800             mov byte ptr [eax + 8], 0
// 00645266  8910                 mov dword ptr [eax], edx
// 00645268  5b                   pop ebx
// 00645269  83c40c               add esp, 0xc
// 0064526c  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

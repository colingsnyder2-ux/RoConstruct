// from server: 100% by auto
// roc 2010-06 00660970  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00660970
//
// 00660970  83ec0c               sub esp, 0xc
// 00660973  53                   push ebx
// 00660974  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00660978  55                   push ebp
// 00660979  56                   push esi
// 0066097a  57                   push edi
// 0066097b  8bf9                 mov edi, ecx
// 0066097d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00660980  8b4604               mov eax, dword ptr [esi + 4]
// 00660983  80781900             cmp byte ptr [eax + 0x19], 0
// 00660987  b101                 mov cl, 1
// 00660989  884c2410             mov byte ptr [esp + 0x10], cl
// 0066098d  751f                 jne 0x6609ae
// 0066098f  8b13                 mov edx, dword ptr [ebx]
// 00660991  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00660994  8bf0                 mov esi, eax
// 00660996  0f9cc1               setl cl
// 00660999  884c2410             mov byte ptr [esp + 0x10], cl
// 0066099d  84c9                 test cl, cl
// 0066099f  7404                 je 0x6609a5
// 006609a1  8b00                 mov eax, dword ptr [eax]
// 006609a3  eb03                 jmp 0x6609a8
// 006609a5  8b4008               mov eax, dword ptr [eax + 8]
// 006609a8  80781900             cmp byte ptr [eax + 0x19], 0
// 006609ac  74e3                 je 0x660991
// 006609ae  8b17                 mov edx, dword ptr [edi]
// 006609b0  8bee                 mov ebp, esi
// 006609b2  896c2418             mov dword ptr [esp + 0x18], ebp
// 006609b6  89542414             mov dword ptr [esp + 0x14], edx
// 006609ba  84c9                 test cl, cl
// 006609bc  7452                 je 0x660a10
// 006609be  8b4718               mov eax, dword ptr [edi + 0x18]
// 006609c1  8b28                 mov ebp, dword ptr [eax]
// 006609c3  85d2                 test edx, edx
// 006609c5  7404                 je 0x6609cb
// 006609c7  3bd2                 cmp edx, edx
// 006609c9  7406                 je 0x6609d1
// 006609cb  ff150ca99e00         call dword ptr [0x9ea90c]
// 006609d1  8d4c2414             lea ecx, [esp + 0x14]
// 006609d5  3bf5                 cmp esi, ebp
// 006609d7  752a                 jne 0x660a03
// 006609d9  53                   push ebx
// 006609da  56                   push esi
// 006609db  6a01                 push 1
// 006609dd  51                   push ecx
// 006609de  8bcf                 mov ecx, edi
// 006609e0  e86b4addff           call 0x435450
// 006609e5  5f                   pop edi
// 006609e6  8bc8                 mov ecx, eax
// 006609e8  8b11                 mov edx, dword ptr [ecx]
// 006609ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006609ee  8b4904               mov ecx, dword ptr [ecx + 4]
// 006609f1  5e                   pop esi
// 006609f2  5d                   pop ebp
// 006609f3  894804               mov dword ptr [eax + 4], ecx
// 006609f6  c6400801             mov byte ptr [eax + 8], 1
// 006609fa  8910                 mov dword ptr [eax], edx
// 006609fc  5b                   pop ebx
// 006609fd  83c40c               add esp, 0xc
// 00660a00  c20800               ret 8
// 00660a03  e8b838ddff           call 0x4342c0
// 00660a08  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00660a0c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00660a10  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00660a13  3b03                 cmp eax, dword ptr [ebx]
// 00660a15  7d31                 jge 0x660a48
// 00660a17  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00660a1b  53                   push ebx
// 00660a1c  56                   push esi
// 00660a1d  51                   push ecx
// 00660a1e  8d542420             lea edx, [esp + 0x20]
// 00660a22  52                   push edx
// 00660a23  8bcf                 mov ecx, edi
// 00660a25  e8264addff           call 0x435450
// 00660a2a  5f                   pop edi
// 00660a2b  8bc8                 mov ecx, eax
// 00660a2d  8b11                 mov edx, dword ptr [ecx]
// 00660a2f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00660a33  8b4904               mov ecx, dword ptr [ecx + 4]
// 00660a36  5e                   pop esi
// 00660a37  5d                   pop ebp
// 00660a38  894804               mov dword ptr [eax + 4], ecx
// 00660a3b  c6400801             mov byte ptr [eax + 8], 1
// 00660a3f  8910                 mov dword ptr [eax], edx
// 00660a41  5b                   pop ebx
// 00660a42  83c40c               add esp, 0xc
// 00660a45  c20800               ret 8
// 00660a48  8b442420             mov eax, dword ptr [esp + 0x20]
// 00660a4c  5f                   pop edi
// 00660a4d  5e                   pop esi
// 00660a4e  896804               mov dword ptr [eax + 4], ebp
// 00660a51  5d                   pop ebp
// 00660a52  c6400800             mov byte ptr [eax + 8], 0
// 00660a56  8910                 mov dword ptr [eax], edx
// 00660a58  5b                   pop ebx
// 00660a59  83c40c               add esp, 0xc
// 00660a5c  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

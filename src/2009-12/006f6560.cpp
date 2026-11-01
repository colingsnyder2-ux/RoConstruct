// from server: 100% by auto
// roc 2009-12 006f6560  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f6560
//
// 006f6560  83ec0c               sub esp, 0xc
// 006f6563  53                   push ebx
// 006f6564  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006f6568  55                   push ebp
// 006f6569  56                   push esi
// 006f656a  57                   push edi
// 006f656b  8bf9                 mov edi, ecx
// 006f656d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006f6570  8b4604               mov eax, dword ptr [esi + 4]
// 006f6573  80781900             cmp byte ptr [eax + 0x19], 0
// 006f6577  b101                 mov cl, 1
// 006f6579  884c2410             mov byte ptr [esp + 0x10], cl
// 006f657d  751f                 jne 0x6f659e
// 006f657f  8b13                 mov edx, dword ptr [ebx]
// 006f6581  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006f6584  8bf0                 mov esi, eax
// 006f6586  0f9cc1               setl cl
// 006f6589  884c2410             mov byte ptr [esp + 0x10], cl
// 006f658d  84c9                 test cl, cl
// 006f658f  7404                 je 0x6f6595
// 006f6591  8b00                 mov eax, dword ptr [eax]
// 006f6593  eb03                 jmp 0x6f6598
// 006f6595  8b4008               mov eax, dword ptr [eax + 8]
// 006f6598  80781900             cmp byte ptr [eax + 0x19], 0
// 006f659c  74e3                 je 0x6f6581
// 006f659e  8b17                 mov edx, dword ptr [edi]
// 006f65a0  8bee                 mov ebp, esi
// 006f65a2  896c2418             mov dword ptr [esp + 0x18], ebp
// 006f65a6  89542414             mov dword ptr [esp + 0x14], edx
// 006f65aa  84c9                 test cl, cl
// 006f65ac  7452                 je 0x6f6600
// 006f65ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f65b1  8b28                 mov ebp, dword ptr [eax]
// 006f65b3  85d2                 test edx, edx
// 006f65b5  7404                 je 0x6f65bb
// 006f65b7  3bd2                 cmp edx, edx
// 006f65b9  7406                 je 0x6f65c1
// 006f65bb  ff1560b79800         call dword ptr [0x98b760]
// 006f65c1  8d4c2414             lea ecx, [esp + 0x14]
// 006f65c5  3bf5                 cmp esi, ebp
// 006f65c7  752a                 jne 0x6f65f3
// 006f65c9  53                   push ebx
// 006f65ca  56                   push esi
// 006f65cb  6a01                 push 1
// 006f65cd  51                   push ecx
// 006f65ce  8bcf                 mov ecx, edi
// 006f65d0  e8dbf7ffff           call 0x6f5db0
// 006f65d5  5f                   pop edi
// 006f65d6  8bc8                 mov ecx, eax
// 006f65d8  8b11                 mov edx, dword ptr [ecx]
// 006f65da  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f65de  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f65e1  5e                   pop esi
// 006f65e2  5d                   pop ebp
// 006f65e3  894804               mov dword ptr [eax + 4], ecx
// 006f65e6  c6400801             mov byte ptr [eax + 8], 1
// 006f65ea  8910                 mov dword ptr [eax], edx
// 006f65ec  5b                   pop ebx
// 006f65ed  83c40c               add esp, 0xc
// 006f65f0  c20800               ret 8
// 006f65f3  e8b808f8ff           call 0x676eb0
// 006f65f8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006f65fc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006f6600  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006f6603  3b03                 cmp eax, dword ptr [ebx]
// 006f6605  7d31                 jge 0x6f6638
// 006f6607  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006f660b  53                   push ebx
// 006f660c  56                   push esi
// 006f660d  51                   push ecx
// 006f660e  8d542420             lea edx, [esp + 0x20]
// 006f6612  52                   push edx
// 006f6613  8bcf                 mov ecx, edi
// 006f6615  e896f7ffff           call 0x6f5db0
// 006f661a  5f                   pop edi
// 006f661b  8bc8                 mov ecx, eax
// 006f661d  8b11                 mov edx, dword ptr [ecx]
// 006f661f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f6623  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f6626  5e                   pop esi
// 006f6627  5d                   pop ebp
// 006f6628  894804               mov dword ptr [eax + 4], ecx
// 006f662b  c6400801             mov byte ptr [eax + 8], 1
// 006f662f  8910                 mov dword ptr [eax], edx
// 006f6631  5b                   pop ebx
// 006f6632  83c40c               add esp, 0xc
// 006f6635  c20800               ret 8
// 006f6638  8b442420             mov eax, dword ptr [esp + 0x20]
// 006f663c  5f                   pop edi
// 006f663d  5e                   pop esi
// 006f663e  896804               mov dword ptr [eax + 4], ebp
// 006f6641  5d                   pop ebp
// 006f6642  c6400800             mov byte ptr [eax + 8], 0
// 006f6646  8910                 mov dword ptr [eax], edx
// 006f6648  5b                   pop ebx
// 006f6649  83c40c               add esp, 0xc
// 006f664c  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

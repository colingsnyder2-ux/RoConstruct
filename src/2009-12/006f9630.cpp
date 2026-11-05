// from server: 100% by auto
// roc 2009-12 006f9630  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f9630
//
// 006f9630  83ec0c               sub esp, 0xc
// 006f9633  53                   push ebx
// 006f9634  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006f9638  55                   push ebp
// 006f9639  56                   push esi
// 006f963a  57                   push edi
// 006f963b  8bf9                 mov edi, ecx
// 006f963d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006f9640  8b4604               mov eax, dword ptr [esi + 4]
// 006f9643  80783100             cmp byte ptr [eax + 0x31], 0
// 006f9647  b101                 mov cl, 1
// 006f9649  884c2410             mov byte ptr [esp + 0x10], cl
// 006f964d  751f                 jne 0x6f966e
// 006f964f  8b13                 mov edx, dword ptr [ebx]
// 006f9651  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006f9654  8bf0                 mov esi, eax
// 006f9656  0f9cc1               setl cl
// 006f9659  884c2410             mov byte ptr [esp + 0x10], cl
// 006f965d  84c9                 test cl, cl
// 006f965f  7404                 je 0x6f9665
// 006f9661  8b00                 mov eax, dword ptr [eax]
// 006f9663  eb03                 jmp 0x6f9668
// 006f9665  8b4008               mov eax, dword ptr [eax + 8]
// 006f9668  80783100             cmp byte ptr [eax + 0x31], 0
// 006f966c  74e3                 je 0x6f9651
// 006f966e  8b17                 mov edx, dword ptr [edi]
// 006f9670  8bee                 mov ebp, esi
// 006f9672  896c2418             mov dword ptr [esp + 0x18], ebp
// 006f9676  89542414             mov dword ptr [esp + 0x14], edx
// 006f967a  84c9                 test cl, cl
// 006f967c  7452                 je 0x6f96d0
// 006f967e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f9681  8b28                 mov ebp, dword ptr [eax]
// 006f9683  85d2                 test edx, edx
// 006f9685  7404                 je 0x6f968b
// 006f9687  3bd2                 cmp edx, edx
// 006f9689  7406                 je 0x6f9691
// 006f968b  ff1560b79800         call dword ptr [0x98b760]
// 006f9691  8d4c2414             lea ecx, [esp + 0x14]
// 006f9695  3bf5                 cmp esi, ebp
// 006f9697  752a                 jne 0x6f96c3
// 006f9699  53                   push ebx
// 006f969a  56                   push esi
// 006f969b  6a01                 push 1
// 006f969d  51                   push ecx
// 006f969e  8bcf                 mov ecx, edi
// 006f96a0  e88bf7ffff           call 0x6f8e30
// 006f96a5  5f                   pop edi
// 006f96a6  8bc8                 mov ecx, eax
// 006f96a8  8b11                 mov edx, dword ptr [ecx]
// 006f96aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f96ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f96b1  5e                   pop esi
// 006f96b2  5d                   pop ebp
// 006f96b3  894804               mov dword ptr [eax + 4], ecx
// 006f96b6  c6400801             mov byte ptr [eax + 8], 1
// 006f96ba  8910                 mov dword ptr [eax], edx
// 006f96bc  5b                   pop ebx
// 006f96bd  83c40c               add esp, 0xc
// 006f96c0  c20800               ret 8
// 006f96c3  e898a1e1ff           call 0x513860
// 006f96c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006f96cc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006f96d0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006f96d3  3b03                 cmp eax, dword ptr [ebx]
// 006f96d5  7d31                 jge 0x6f9708
// 006f96d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006f96db  53                   push ebx
// 006f96dc  56                   push esi
// 006f96dd  51                   push ecx
// 006f96de  8d542420             lea edx, [esp + 0x20]
// 006f96e2  52                   push edx
// 006f96e3  8bcf                 mov ecx, edi
// 006f96e5  e846f7ffff           call 0x6f8e30
// 006f96ea  5f                   pop edi
// 006f96eb  8bc8                 mov ecx, eax
// 006f96ed  8b11                 mov edx, dword ptr [ecx]
// 006f96ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f96f3  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f96f6  5e                   pop esi
// 006f96f7  5d                   pop ebp
// 006f96f8  894804               mov dword ptr [eax + 4], ecx
// 006f96fb  c6400801             mov byte ptr [eax + 8], 1
// 006f96ff  8910                 mov dword ptr [eax], edx
// 006f9701  5b                   pop ebx
// 006f9702  83c40c               add esp, 0xc
// 006f9705  c20800               ret 8
// 006f9708  8b442420             mov eax, dword ptr [esp + 0x20]
// 006f970c  5f                   pop edi
// 006f970d  5e                   pop esi
// 006f970e  896804               mov dword ptr [eax + 4], ebp
// 006f9711  5d                   pop ebp
// 006f9712  c6400800             mov byte ptr [eax + 8], 0
// 006f9716  8910                 mov dword ptr [eax], edx
// 006f9718  5b                   pop ebx
// 006f9719  83c40c               add esp, 0xc
// 006f971c  c20800               ret 8
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;

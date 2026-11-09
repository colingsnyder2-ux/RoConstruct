// from server: 100% by auto
// roc 2009-06 00838630  unit: RBX::RenderNew::TextureProxy  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00838630
//
// 00838630  83ec0c               sub esp, 0xc
// 00838633  53                   push ebx
// 00838634  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00838638  55                   push ebp
// 00838639  56                   push esi
// 0083863a  57                   push edi
// 0083863b  8bf9                 mov edi, ecx
// 0083863d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00838640  8b4604               mov eax, dword ptr [esi + 4]
// 00838643  80782100             cmp byte ptr [eax + 0x21], 0
// 00838647  b101                 mov cl, 1
// 00838649  884c2410             mov byte ptr [esp + 0x10], cl
// 0083864d  751f                 jne 0x83866e
// 0083864f  8b13                 mov edx, dword ptr [ebx]
// 00838651  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00838654  8bf0                 mov esi, eax
// 00838656  0f92c1               setb cl
// 00838659  884c2410             mov byte ptr [esp + 0x10], cl
// 0083865d  84c9                 test cl, cl
// 0083865f  7404                 je 0x838665
// 00838661  8b00                 mov eax, dword ptr [eax]
// 00838663  eb03                 jmp 0x838668
// 00838665  8b4008               mov eax, dword ptr [eax + 8]
// 00838668  80782100             cmp byte ptr [eax + 0x21], 0
// 0083866c  74e3                 je 0x838651
// 0083866e  8b17                 mov edx, dword ptr [edi]
// 00838670  8bee                 mov ebp, esi
// 00838672  896c2418             mov dword ptr [esp + 0x18], ebp
// 00838676  89542414             mov dword ptr [esp + 0x14], edx
// 0083867a  84c9                 test cl, cl
// 0083867c  7452                 je 0x8386d0
// 0083867e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00838681  8b28                 mov ebp, dword ptr [eax]
// 00838683  85d2                 test edx, edx
// 00838685  7404                 je 0x83868b
// 00838687  3bd2                 cmp edx, edx
// 00838689  7406                 je 0x838691
// 0083868b  ff15ace98900         call dword ptr [0x89e9ac]
// 00838691  8d4c2414             lea ecx, [esp + 0x14]
// 00838695  3bf5                 cmp esi, ebp
// 00838697  752a                 jne 0x8386c3
// 00838699  53                   push ebx
// 0083869a  56                   push esi
// 0083869b  6a01                 push 1
// 0083869d  51                   push ecx
// 0083869e  8bcf                 mov ecx, edi
// 008386a0  e88bfdffff           call 0x838430
// 008386a5  5f                   pop edi
// 008386a6  8bc8                 mov ecx, eax
// 008386a8  8b11                 mov edx, dword ptr [ecx]
// 008386aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008386ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 008386b1  5e                   pop esi
// 008386b2  5d                   pop ebp
// 008386b3  894804               mov dword ptr [eax + 4], ecx
// 008386b6  c6400801             mov byte ptr [eax + 8], 1
// 008386ba  8910                 mov dword ptr [eax], edx
// 008386bc  5b                   pop ebx
// 008386bd  83c40c               add esp, 0xc
// 008386c0  c20800               ret 8
// 008386c3  e8c8f0cdff           call 0x517790
// 008386c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 008386cc  8b542414             mov edx, dword ptr [esp + 0x14]
// 008386d0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008386d3  3b03                 cmp eax, dword ptr [ebx]
// 008386d5  7331                 jae 0x838708
// 008386d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008386db  53                   push ebx
// 008386dc  56                   push esi
// 008386dd  51                   push ecx
// 008386de  8d542420             lea edx, [esp + 0x20]
// 008386e2  52                   push edx
// 008386e3  8bcf                 mov ecx, edi
// 008386e5  e846fdffff           call 0x838430
// 008386ea  5f                   pop edi
// 008386eb  8bc8                 mov ecx, eax
// 008386ed  8b11                 mov edx, dword ptr [ecx]
// 008386ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008386f3  8b4904               mov ecx, dword ptr [ecx + 4]
// 008386f6  5e                   pop esi
// 008386f7  5d                   pop ebp
// 008386f8  894804               mov dword ptr [eax + 4], ecx
// 008386fb  c6400801             mov byte ptr [eax + 8], 1
// 008386ff  8910                 mov dword ptr [eax], edx
// 00838701  5b                   pop ebx
// 00838702  83c40c               add esp, 0xc
// 00838705  c20800               ret 8
// 00838708  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083870c  5f                   pop edi
// 0083870d  5e                   pop esi
// 0083870e  896804               mov dword ptr [eax + 4], ebp
// 00838711  5d                   pop ebp
// 00838712  c6400800             mov byte ptr [eax + 8], 0
// 00838716  8910                 mov dword ptr [eax], edx
// 00838718  5b                   pop ebx
// 00838719  83c40c               add esp, 0xc
// 0083871c  c20800               ret 8
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;

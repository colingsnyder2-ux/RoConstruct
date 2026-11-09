// from server: 100% by auto
// roc 2009-06 0043c030  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c030
//
// 0043c030  83ec0c               sub esp, 0xc
// 0043c033  53                   push ebx
// 0043c034  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0043c038  55                   push ebp
// 0043c039  56                   push esi
// 0043c03a  57                   push edi
// 0043c03b  8bf9                 mov edi, ecx
// 0043c03d  8b7718               mov esi, dword ptr [edi + 0x18]
// 0043c040  8b4604               mov eax, dword ptr [esi + 4]
// 0043c043  80782900             cmp byte ptr [eax + 0x29], 0
// 0043c047  b101                 mov cl, 1
// 0043c049  884c2410             mov byte ptr [esp + 0x10], cl
// 0043c04d  751f                 jne 0x43c06e
// 0043c04f  8b13                 mov edx, dword ptr [ebx]
// 0043c051  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0043c054  8bf0                 mov esi, eax
// 0043c056  0f92c1               setb cl
// 0043c059  884c2410             mov byte ptr [esp + 0x10], cl
// 0043c05d  84c9                 test cl, cl
// 0043c05f  7404                 je 0x43c065
// 0043c061  8b00                 mov eax, dword ptr [eax]
// 0043c063  eb03                 jmp 0x43c068
// 0043c065  8b4008               mov eax, dword ptr [eax + 8]
// 0043c068  80782900             cmp byte ptr [eax + 0x29], 0
// 0043c06c  74e3                 je 0x43c051
// 0043c06e  8b17                 mov edx, dword ptr [edi]
// 0043c070  8bee                 mov ebp, esi
// 0043c072  896c2418             mov dword ptr [esp + 0x18], ebp
// 0043c076  89542414             mov dword ptr [esp + 0x14], edx
// 0043c07a  84c9                 test cl, cl
// 0043c07c  7452                 je 0x43c0d0
// 0043c07e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043c081  8b28                 mov ebp, dword ptr [eax]
// 0043c083  85d2                 test edx, edx
// 0043c085  7404                 je 0x43c08b
// 0043c087  3bd2                 cmp edx, edx
// 0043c089  7406                 je 0x43c091
// 0043c08b  ff15ace98900         call dword ptr [0x89e9ac]
// 0043c091  8d4c2414             lea ecx, [esp + 0x14]
// 0043c095  3bf5                 cmp esi, ebp
// 0043c097  752a                 jne 0x43c0c3
// 0043c099  53                   push ebx
// 0043c09a  56                   push esi
// 0043c09b  6a01                 push 1
// 0043c09d  51                   push ecx
// 0043c09e  8bcf                 mov ecx, edi
// 0043c0a0  e85beeffff           call 0x43af00
// 0043c0a5  5f                   pop edi
// 0043c0a6  8bc8                 mov ecx, eax
// 0043c0a8  8b11                 mov edx, dword ptr [ecx]
// 0043c0aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043c0ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043c0b1  5e                   pop esi
// 0043c0b2  5d                   pop ebp
// 0043c0b3  894804               mov dword ptr [eax + 4], ecx
// 0043c0b6  c6400801             mov byte ptr [eax + 8], 1
// 0043c0ba  8910                 mov dword ptr [eax], edx
// 0043c0bc  5b                   pop ebx
// 0043c0bd  83c40c               add esp, 0xc
// 0043c0c0  c20800               ret 8
// 0043c0c3  e838b60d00           call 0x517700
// 0043c0c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0043c0cc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0043c0d0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0043c0d3  3b03                 cmp eax, dword ptr [ebx]
// 0043c0d5  7331                 jae 0x43c108
// 0043c0d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043c0db  53                   push ebx
// 0043c0dc  56                   push esi
// 0043c0dd  51                   push ecx
// 0043c0de  8d542420             lea edx, [esp + 0x20]
// 0043c0e2  52                   push edx
// 0043c0e3  8bcf                 mov ecx, edi
// 0043c0e5  e816eeffff           call 0x43af00
// 0043c0ea  5f                   pop edi
// 0043c0eb  8bc8                 mov ecx, eax
// 0043c0ed  8b11                 mov edx, dword ptr [ecx]
// 0043c0ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043c0f3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043c0f6  5e                   pop esi
// 0043c0f7  5d                   pop ebp
// 0043c0f8  894804               mov dword ptr [eax + 4], ecx
// 0043c0fb  c6400801             mov byte ptr [eax + 8], 1
// 0043c0ff  8910                 mov dword ptr [eax], edx
// 0043c101  5b                   pop ebx
// 0043c102  83c40c               add esp, 0xc
// 0043c105  c20800               ret 8
// 0043c108  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043c10c  5f                   pop edi
// 0043c10d  5e                   pop esi
// 0043c10e  896804               mov dword ptr [eax + 4], ebp
// 0043c111  5d                   pop ebp
// 0043c112  c6400800             mov byte ptr [eax + 8], 0
// 0043c116  8910                 mov dword ptr [eax], edx
// 0043c118  5b                   pop ebx
// 0043c119  83c40c               add esp, 0xc
// 0043c11c  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;

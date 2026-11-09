// from server: 100% by auto
// roc 2010-06 00771900  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00771900
//
// 00771900  83ec0c               sub esp, 0xc
// 00771903  53                   push ebx
// 00771904  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00771908  55                   push ebp
// 00771909  56                   push esi
// 0077190a  57                   push edi
// 0077190b  8bf9                 mov edi, ecx
// 0077190d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00771910  8b4604               mov eax, dword ptr [esi + 4]
// 00771913  80783100             cmp byte ptr [eax + 0x31], 0
// 00771917  b101                 mov cl, 1
// 00771919  884c2410             mov byte ptr [esp + 0x10], cl
// 0077191d  751f                 jne 0x77193e
// 0077191f  8b13                 mov edx, dword ptr [ebx]
// 00771921  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00771924  8bf0                 mov esi, eax
// 00771926  0f92c1               setb cl
// 00771929  884c2410             mov byte ptr [esp + 0x10], cl
// 0077192d  84c9                 test cl, cl
// 0077192f  7404                 je 0x771935
// 00771931  8b00                 mov eax, dword ptr [eax]
// 00771933  eb03                 jmp 0x771938
// 00771935  8b4008               mov eax, dword ptr [eax + 8]
// 00771938  80783100             cmp byte ptr [eax + 0x31], 0
// 0077193c  74e3                 je 0x771921
// 0077193e  8b17                 mov edx, dword ptr [edi]
// 00771940  8bee                 mov ebp, esi
// 00771942  896c2418             mov dword ptr [esp + 0x18], ebp
// 00771946  89542414             mov dword ptr [esp + 0x14], edx
// 0077194a  84c9                 test cl, cl
// 0077194c  7452                 je 0x7719a0
// 0077194e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00771951  8b28                 mov ebp, dword ptr [eax]
// 00771953  85d2                 test edx, edx
// 00771955  7404                 je 0x77195b
// 00771957  3bd2                 cmp edx, edx
// 00771959  7406                 je 0x771961
// 0077195b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00771961  8d4c2414             lea ecx, [esp + 0x14]
// 00771965  3bf5                 cmp esi, ebp
// 00771967  752a                 jne 0x771993
// 00771969  53                   push ebx
// 0077196a  56                   push esi
// 0077196b  6a01                 push 1
// 0077196d  51                   push ecx
// 0077196e  8bcf                 mov ecx, edi
// 00771970  e88bf4ffff           call 0x770e00
// 00771975  5f                   pop edi
// 00771976  8bc8                 mov ecx, eax
// 00771978  8b11                 mov edx, dword ptr [ecx]
// 0077197a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0077197e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00771981  5e                   pop esi
// 00771982  5d                   pop ebp
// 00771983  894804               mov dword ptr [eax + 4], ecx
// 00771986  c6400801             mov byte ptr [eax + 8], 1
// 0077198a  8910                 mov dword ptr [eax], edx
// 0077198c  5b                   pop ebx
// 0077198d  83c40c               add esp, 0xc
// 00771990  c20800               ret 8
// 00771993  e8481bd0ff           call 0x4734e0
// 00771998  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0077199c  8b542414             mov edx, dword ptr [esp + 0x14]
// 007719a0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007719a3  3b03                 cmp eax, dword ptr [ebx]
// 007719a5  7331                 jae 0x7719d8
// 007719a7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007719ab  53                   push ebx
// 007719ac  56                   push esi
// 007719ad  51                   push ecx
// 007719ae  8d542420             lea edx, [esp + 0x20]
// 007719b2  52                   push edx
// 007719b3  8bcf                 mov ecx, edi
// 007719b5  e846f4ffff           call 0x770e00
// 007719ba  5f                   pop edi
// 007719bb  8bc8                 mov ecx, eax
// 007719bd  8b11                 mov edx, dword ptr [ecx]
// 007719bf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007719c3  8b4904               mov ecx, dword ptr [ecx + 4]
// 007719c6  5e                   pop esi
// 007719c7  5d                   pop ebp
// 007719c8  894804               mov dword ptr [eax + 4], ecx
// 007719cb  c6400801             mov byte ptr [eax + 8], 1
// 007719cf  8910                 mov dword ptr [eax], edx
// 007719d1  5b                   pop ebx
// 007719d2  83c40c               add esp, 0xc
// 007719d5  c20800               ret 8
// 007719d8  8b442420             mov eax, dword ptr [esp + 0x20]
// 007719dc  5f                   pop edi
// 007719dd  5e                   pop esi
// 007719de  896804               mov dword ptr [eax + 4], ebp
// 007719e1  5d                   pop ebp
// 007719e2  c6400800             mov byte ptr [eax + 8], 0
// 007719e6  8910                 mov dword ptr [eax], edx
// 007719e8  5b                   pop ebx
// 007719e9  83c40c               add esp, 0xc
// 007719ec  c20800               ret 8
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;

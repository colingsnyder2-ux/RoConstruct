// from server: 100% by auto
// roc 2009-12 00440470  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00440470
//
// 00440470  83ec0c               sub esp, 0xc
// 00440473  53                   push ebx
// 00440474  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00440478  55                   push ebp
// 00440479  56                   push esi
// 0044047a  57                   push edi
// 0044047b  8bf9                 mov edi, ecx
// 0044047d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00440480  8b4604               mov eax, dword ptr [esi + 4]
// 00440483  80782900             cmp byte ptr [eax + 0x29], 0
// 00440487  b101                 mov cl, 1
// 00440489  884c2410             mov byte ptr [esp + 0x10], cl
// 0044048d  751f                 jne 0x4404ae
// 0044048f  8b13                 mov edx, dword ptr [ebx]
// 00440491  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00440494  8bf0                 mov esi, eax
// 00440496  0f92c1               setb cl
// 00440499  884c2410             mov byte ptr [esp + 0x10], cl
// 0044049d  84c9                 test cl, cl
// 0044049f  7404                 je 0x4404a5
// 004404a1  8b00                 mov eax, dword ptr [eax]
// 004404a3  eb03                 jmp 0x4404a8
// 004404a5  8b4008               mov eax, dword ptr [eax + 8]
// 004404a8  80782900             cmp byte ptr [eax + 0x29], 0
// 004404ac  74e3                 je 0x440491
// 004404ae  8b17                 mov edx, dword ptr [edi]
// 004404b0  8bee                 mov ebp, esi
// 004404b2  896c2418             mov dword ptr [esp + 0x18], ebp
// 004404b6  89542414             mov dword ptr [esp + 0x14], edx
// 004404ba  84c9                 test cl, cl
// 004404bc  7452                 je 0x440510
// 004404be  8b4718               mov eax, dword ptr [edi + 0x18]
// 004404c1  8b28                 mov ebp, dword ptr [eax]
// 004404c3  85d2                 test edx, edx
// 004404c5  7404                 je 0x4404cb
// 004404c7  3bd2                 cmp edx, edx
// 004404c9  7406                 je 0x4404d1
// 004404cb  ff1560b79800         call dword ptr [0x98b760]
// 004404d1  8d4c2414             lea ecx, [esp + 0x14]
// 004404d5  3bf5                 cmp esi, ebp
// 004404d7  752a                 jne 0x440503
// 004404d9  53                   push ebx
// 004404da  56                   push esi
// 004404db  6a01                 push 1
// 004404dd  51                   push ecx
// 004404de  8bcf                 mov ecx, edi
// 004404e0  e8abeaffff           call 0x43ef90
// 004404e5  5f                   pop edi
// 004404e6  8bc8                 mov ecx, eax
// 004404e8  8b11                 mov edx, dword ptr [ecx]
// 004404ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004404ee  8b4904               mov ecx, dword ptr [ecx + 4]
// 004404f1  5e                   pop esi
// 004404f2  5d                   pop ebp
// 004404f3  894804               mov dword ptr [eax + 4], ecx
// 004404f6  c6400801             mov byte ptr [eax + 8], 1
// 004404fa  8910                 mov dword ptr [eax], edx
// 004404fc  5b                   pop ebx
// 004404fd  83c40c               add esp, 0xc
// 00440500  c20800               ret 8
// 00440503  e8c8cc1800           call 0x5cd1d0
// 00440508  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044050c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00440510  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00440513  3b03                 cmp eax, dword ptr [ebx]
// 00440515  7331                 jae 0x440548
// 00440517  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044051b  53                   push ebx
// 0044051c  56                   push esi
// 0044051d  51                   push ecx
// 0044051e  8d542420             lea edx, [esp + 0x20]
// 00440522  52                   push edx
// 00440523  8bcf                 mov ecx, edi
// 00440525  e866eaffff           call 0x43ef90
// 0044052a  5f                   pop edi
// 0044052b  8bc8                 mov ecx, eax
// 0044052d  8b11                 mov edx, dword ptr [ecx]
// 0044052f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00440533  8b4904               mov ecx, dword ptr [ecx + 4]
// 00440536  5e                   pop esi
// 00440537  5d                   pop ebp
// 00440538  894804               mov dword ptr [eax + 4], ecx
// 0044053b  c6400801             mov byte ptr [eax + 8], 1
// 0044053f  8910                 mov dword ptr [eax], edx
// 00440541  5b                   pop ebx
// 00440542  83c40c               add esp, 0xc
// 00440545  c20800               ret 8
// 00440548  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044054c  5f                   pop edi
// 0044054d  5e                   pop esi
// 0044054e  896804               mov dword ptr [eax + 4], ebp
// 00440551  5d                   pop ebp
// 00440552  c6400800             mov byte ptr [eax + 8], 0
// 00440556  8910                 mov dword ptr [eax], edx
// 00440558  5b                   pop ebx
// 00440559  83c40c               add esp, 0xc
// 0044055c  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;

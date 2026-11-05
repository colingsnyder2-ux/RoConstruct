// from server: 100% by auto
// roc 2008-06 004417f0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004417f0
//
// 004417f0  83ec0c               sub esp, 0xc
// 004417f3  53                   push ebx
// 004417f4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004417f8  55                   push ebp
// 004417f9  56                   push esi
// 004417fa  57                   push edi
// 004417fb  8bf9                 mov edi, ecx
// 004417fd  8b7718               mov esi, dword ptr [edi + 0x18]
// 00441800  8b4604               mov eax, dword ptr [esi + 4]
// 00441803  80782900             cmp byte ptr [eax + 0x29], 0
// 00441807  b101                 mov cl, 1
// 00441809  884c2410             mov byte ptr [esp + 0x10], cl
// 0044180d  751f                 jne 0x44182e
// 0044180f  8b13                 mov edx, dword ptr [ebx]
// 00441811  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00441814  8bf0                 mov esi, eax
// 00441816  0f92c1               setb cl
// 00441819  884c2410             mov byte ptr [esp + 0x10], cl
// 0044181d  84c9                 test cl, cl
// 0044181f  7404                 je 0x441825
// 00441821  8b00                 mov eax, dword ptr [eax]
// 00441823  eb03                 jmp 0x441828
// 00441825  8b4008               mov eax, dword ptr [eax + 8]
// 00441828  80782900             cmp byte ptr [eax + 0x29], 0
// 0044182c  74e3                 je 0x441811
// 0044182e  8b17                 mov edx, dword ptr [edi]
// 00441830  8bee                 mov ebp, esi
// 00441832  896c2418             mov dword ptr [esp + 0x18], ebp
// 00441836  89542414             mov dword ptr [esp + 0x14], edx
// 0044183a  84c9                 test cl, cl
// 0044183c  7452                 je 0x441890
// 0044183e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00441841  8b28                 mov ebp, dword ptr [eax]
// 00441843  85d2                 test edx, edx
// 00441845  7404                 je 0x44184b
// 00441847  3bd2                 cmp edx, edx
// 00441849  7406                 je 0x441851
// 0044184b  ff1590288000         call dword ptr [0x802890]
// 00441851  8d4c2414             lea ecx, [esp + 0x14]
// 00441855  3bf5                 cmp esi, ebp
// 00441857  752a                 jne 0x441883
// 00441859  53                   push ebx
// 0044185a  56                   push esi
// 0044185b  6a01                 push 1
// 0044185d  51                   push ecx
// 0044185e  8bcf                 mov ecx, edi
// 00441860  e8dbedffff           call 0x440640
// 00441865  5f                   pop edi
// 00441866  8bc8                 mov ecx, eax
// 00441868  8b11                 mov edx, dword ptr [ecx]
// 0044186a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044186e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00441871  5e                   pop esi
// 00441872  5d                   pop ebp
// 00441873  894804               mov dword ptr [eax + 4], ecx
// 00441876  c6400801             mov byte ptr [eax + 8], 1
// 0044187a  8910                 mov dword ptr [eax], edx
// 0044187c  5b                   pop ebx
// 0044187d  83c40c               add esp, 0xc
// 00441880  c20800               ret 8
// 00441883  e8586effff           call 0x4386e0
// 00441888  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044188c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00441890  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00441893  3b03                 cmp eax, dword ptr [ebx]
// 00441895  7331                 jae 0x4418c8
// 00441897  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044189b  53                   push ebx
// 0044189c  56                   push esi
// 0044189d  51                   push ecx
// 0044189e  8d542420             lea edx, [esp + 0x20]
// 004418a2  52                   push edx
// 004418a3  8bcf                 mov ecx, edi
// 004418a5  e896edffff           call 0x440640
// 004418aa  5f                   pop edi
// 004418ab  8bc8                 mov ecx, eax
// 004418ad  8b11                 mov edx, dword ptr [ecx]
// 004418af  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004418b3  8b4904               mov ecx, dword ptr [ecx + 4]
// 004418b6  5e                   pop esi
// 004418b7  5d                   pop ebp
// 004418b8  894804               mov dword ptr [eax + 4], ecx
// 004418bb  c6400801             mov byte ptr [eax + 8], 1
// 004418bf  8910                 mov dword ptr [eax], edx
// 004418c1  5b                   pop ebx
// 004418c2  83c40c               add esp, 0xc
// 004418c5  c20800               ret 8
// 004418c8  8b442420             mov eax, dword ptr [esp + 0x20]
// 004418cc  5f                   pop edi
// 004418cd  5e                   pop esi
// 004418ce  896804               mov dword ptr [eax + 4], ebp
// 004418d1  5d                   pop ebp
// 004418d2  c6400800             mov byte ptr [eax + 8], 0
// 004418d6  8910                 mov dword ptr [eax], edx
// 004418d8  5b                   pop ebx
// 004418d9  83c40c               add esp, 0xc
// 004418dc  c20800               ret 8
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;

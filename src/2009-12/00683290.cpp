// from server: 100% by auto
// roc 2009-12 00683290  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00683290
//
// 00683290  83ec0c               sub esp, 0xc
// 00683293  53                   push ebx
// 00683294  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00683298  55                   push ebp
// 00683299  56                   push esi
// 0068329a  57                   push edi
// 0068329b  8bf9                 mov edi, ecx
// 0068329d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006832a0  8b4604               mov eax, dword ptr [esi + 4]
// 006832a3  80781900             cmp byte ptr [eax + 0x19], 0
// 006832a7  b101                 mov cl, 1
// 006832a9  884c2410             mov byte ptr [esp + 0x10], cl
// 006832ad  751f                 jne 0x6832ce
// 006832af  8b13                 mov edx, dword ptr [ebx]
// 006832b1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006832b4  8bf0                 mov esi, eax
// 006832b6  0f92c1               setb cl
// 006832b9  884c2410             mov byte ptr [esp + 0x10], cl
// 006832bd  84c9                 test cl, cl
// 006832bf  7404                 je 0x6832c5
// 006832c1  8b00                 mov eax, dword ptr [eax]
// 006832c3  eb03                 jmp 0x6832c8
// 006832c5  8b4008               mov eax, dword ptr [eax + 8]
// 006832c8  80781900             cmp byte ptr [eax + 0x19], 0
// 006832cc  74e3                 je 0x6832b1
// 006832ce  8b17                 mov edx, dword ptr [edi]
// 006832d0  8bee                 mov ebp, esi
// 006832d2  896c2418             mov dword ptr [esp + 0x18], ebp
// 006832d6  89542414             mov dword ptr [esp + 0x14], edx
// 006832da  84c9                 test cl, cl
// 006832dc  7452                 je 0x683330
// 006832de  8b4718               mov eax, dword ptr [edi + 0x18]
// 006832e1  8b28                 mov ebp, dword ptr [eax]
// 006832e3  85d2                 test edx, edx
// 006832e5  7404                 je 0x6832eb
// 006832e7  3bd2                 cmp edx, edx
// 006832e9  7406                 je 0x6832f1
// 006832eb  ff1560b79800         call dword ptr [0x98b760]
// 006832f1  8d4c2414             lea ecx, [esp + 0x14]
// 006832f5  3bf5                 cmp esi, ebp
// 006832f7  752a                 jne 0x683323
// 006832f9  53                   push ebx
// 006832fa  56                   push esi
// 006832fb  6a01                 push 1
// 006832fd  51                   push ecx
// 006832fe  8bcf                 mov ecx, edi
// 00683300  e88bf9ffff           call 0x682c90
// 00683305  5f                   pop edi
// 00683306  8bc8                 mov ecx, eax
// 00683308  8b11                 mov edx, dword ptr [ecx]
// 0068330a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0068330e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00683311  5e                   pop esi
// 00683312  5d                   pop ebp
// 00683313  894804               mov dword ptr [eax + 4], ecx
// 00683316  c6400801             mov byte ptr [eax + 8], 1
// 0068331a  8910                 mov dword ptr [eax], edx
// 0068331c  5b                   pop ebx
// 0068331d  83c40c               add esp, 0xc
// 00683320  c20800               ret 8
// 00683323  e8883bffff           call 0x676eb0
// 00683328  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0068332c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00683330  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00683333  3b03                 cmp eax, dword ptr [ebx]
// 00683335  7331                 jae 0x683368
// 00683337  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068333b  53                   push ebx
// 0068333c  56                   push esi
// 0068333d  51                   push ecx
// 0068333e  8d542420             lea edx, [esp + 0x20]
// 00683342  52                   push edx
// 00683343  8bcf                 mov ecx, edi
// 00683345  e846f9ffff           call 0x682c90
// 0068334a  5f                   pop edi
// 0068334b  8bc8                 mov ecx, eax
// 0068334d  8b11                 mov edx, dword ptr [ecx]
// 0068334f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00683353  8b4904               mov ecx, dword ptr [ecx + 4]
// 00683356  5e                   pop esi
// 00683357  5d                   pop ebp
// 00683358  894804               mov dword ptr [eax + 4], ecx
// 0068335b  c6400801             mov byte ptr [eax + 8], 1
// 0068335f  8910                 mov dword ptr [eax], edx
// 00683361  5b                   pop ebx
// 00683362  83c40c               add esp, 0xc
// 00683365  c20800               ret 8
// 00683368  8b442420             mov eax, dword ptr [esp + 0x20]
// 0068336c  5f                   pop edi
// 0068336d  5e                   pop esi
// 0068336e  896804               mov dword ptr [eax + 4], ebp
// 00683371  5d                   pop ebp
// 00683372  c6400800             mov byte ptr [eax + 8], 0
// 00683376  8910                 mov dword ptr [eax], edx
// 00683378  5b                   pop ebx
// 00683379  83c40c               add esp, 0xc
// 0068337c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;

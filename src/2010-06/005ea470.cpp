// from server: 100% by auto
// roc 2010-06 005ea470  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ea470
//
// 005ea470  83ec0c               sub esp, 0xc
// 005ea473  53                   push ebx
// 005ea474  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005ea478  55                   push ebp
// 005ea479  56                   push esi
// 005ea47a  57                   push edi
// 005ea47b  8bf9                 mov edi, ecx
// 005ea47d  8b7718               mov esi, dword ptr [edi + 0x18]
// 005ea480  8b4604               mov eax, dword ptr [esi + 4]
// 005ea483  80781900             cmp byte ptr [eax + 0x19], 0
// 005ea487  b101                 mov cl, 1
// 005ea489  884c2410             mov byte ptr [esp + 0x10], cl
// 005ea48d  751f                 jne 0x5ea4ae
// 005ea48f  8b13                 mov edx, dword ptr [ebx]
// 005ea491  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005ea494  8bf0                 mov esi, eax
// 005ea496  0f92c1               setb cl
// 005ea499  884c2410             mov byte ptr [esp + 0x10], cl
// 005ea49d  84c9                 test cl, cl
// 005ea49f  7404                 je 0x5ea4a5
// 005ea4a1  8b00                 mov eax, dword ptr [eax]
// 005ea4a3  eb03                 jmp 0x5ea4a8
// 005ea4a5  8b4008               mov eax, dword ptr [eax + 8]
// 005ea4a8  80781900             cmp byte ptr [eax + 0x19], 0
// 005ea4ac  74e3                 je 0x5ea491
// 005ea4ae  8b17                 mov edx, dword ptr [edi]
// 005ea4b0  8bee                 mov ebp, esi
// 005ea4b2  896c2418             mov dword ptr [esp + 0x18], ebp
// 005ea4b6  89542414             mov dword ptr [esp + 0x14], edx
// 005ea4ba  84c9                 test cl, cl
// 005ea4bc  7452                 je 0x5ea510
// 005ea4be  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ea4c1  8b28                 mov ebp, dword ptr [eax]
// 005ea4c3  85d2                 test edx, edx
// 005ea4c5  7404                 je 0x5ea4cb
// 005ea4c7  3bd2                 cmp edx, edx
// 005ea4c9  7406                 je 0x5ea4d1
// 005ea4cb  ff150ca99e00         call dword ptr [0x9ea90c]
// 005ea4d1  8d4c2414             lea ecx, [esp + 0x14]
// 005ea4d5  3bf5                 cmp esi, ebp
// 005ea4d7  752a                 jne 0x5ea503
// 005ea4d9  53                   push ebx
// 005ea4da  56                   push esi
// 005ea4db  6a01                 push 1
// 005ea4dd  51                   push ecx
// 005ea4de  8bcf                 mov ecx, edi
// 005ea4e0  e8ebf8ffff           call 0x5e9dd0
// 005ea4e5  5f                   pop edi
// 005ea4e6  8bc8                 mov ecx, eax
// 005ea4e8  8b11                 mov edx, dword ptr [ecx]
// 005ea4ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ea4ee  8b4904               mov ecx, dword ptr [ecx + 4]
// 005ea4f1  5e                   pop esi
// 005ea4f2  5d                   pop ebp
// 005ea4f3  894804               mov dword ptr [eax + 4], ecx
// 005ea4f6  c6400801             mov byte ptr [eax + 8], 1
// 005ea4fa  8910                 mov dword ptr [eax], edx
// 005ea4fc  5b                   pop ebx
// 005ea4fd  83c40c               add esp, 0xc
// 005ea500  c20800               ret 8
// 005ea503  e8b89de4ff           call 0x4342c0
// 005ea508  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005ea50c  8b542414             mov edx, dword ptr [esp + 0x14]
// 005ea510  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005ea513  3b03                 cmp eax, dword ptr [ebx]
// 005ea515  7331                 jae 0x5ea548
// 005ea517  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ea51b  53                   push ebx
// 005ea51c  56                   push esi
// 005ea51d  51                   push ecx
// 005ea51e  8d542420             lea edx, [esp + 0x20]
// 005ea522  52                   push edx
// 005ea523  8bcf                 mov ecx, edi
// 005ea525  e8a6f8ffff           call 0x5e9dd0
// 005ea52a  5f                   pop edi
// 005ea52b  8bc8                 mov ecx, eax
// 005ea52d  8b11                 mov edx, dword ptr [ecx]
// 005ea52f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ea533  8b4904               mov ecx, dword ptr [ecx + 4]
// 005ea536  5e                   pop esi
// 005ea537  5d                   pop ebp
// 005ea538  894804               mov dword ptr [eax + 4], ecx
// 005ea53b  c6400801             mov byte ptr [eax + 8], 1
// 005ea53f  8910                 mov dword ptr [eax], edx
// 005ea541  5b                   pop ebx
// 005ea542  83c40c               add esp, 0xc
// 005ea545  c20800               ret 8
// 005ea548  8b442420             mov eax, dword ptr [esp + 0x20]
// 005ea54c  5f                   pop edi
// 005ea54d  5e                   pop esi
// 005ea54e  896804               mov dword ptr [eax + 4], ebp
// 005ea551  5d                   pop ebp
// 005ea552  c6400800             mov byte ptr [eax + 8], 0
// 005ea556  8910                 mov dword ptr [eax], edx
// 005ea558  5b                   pop ebx
// 005ea559  83c40c               add esp, 0xc
// 005ea55c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;

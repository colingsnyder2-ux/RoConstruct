// from server: 100% by auto
// roc 2008-06 004af270  unit: RBX::Network::Replicator::MarkerItem  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004af270
//
// 004af270  83ec0c               sub esp, 0xc
// 004af273  53                   push ebx
// 004af274  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004af278  55                   push ebp
// 004af279  56                   push esi
// 004af27a  57                   push edi
// 004af27b  8bf9                 mov edi, ecx
// 004af27d  8b7718               mov esi, dword ptr [edi + 0x18]
// 004af280  8b4604               mov eax, dword ptr [esi + 4]
// 004af283  80781900             cmp byte ptr [eax + 0x19], 0
// 004af287  b101                 mov cl, 1
// 004af289  884c2410             mov byte ptr [esp + 0x10], cl
// 004af28d  751f                 jne 0x4af2ae
// 004af28f  8b13                 mov edx, dword ptr [ebx]
// 004af291  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004af294  8bf0                 mov esi, eax
// 004af296  0f92c1               setb cl
// 004af299  884c2410             mov byte ptr [esp + 0x10], cl
// 004af29d  84c9                 test cl, cl
// 004af29f  7404                 je 0x4af2a5
// 004af2a1  8b00                 mov eax, dword ptr [eax]
// 004af2a3  eb03                 jmp 0x4af2a8
// 004af2a5  8b4008               mov eax, dword ptr [eax + 8]
// 004af2a8  80781900             cmp byte ptr [eax + 0x19], 0
// 004af2ac  74e3                 je 0x4af291
// 004af2ae  8b17                 mov edx, dword ptr [edi]
// 004af2b0  8bee                 mov ebp, esi
// 004af2b2  896c2418             mov dword ptr [esp + 0x18], ebp
// 004af2b6  89542414             mov dword ptr [esp + 0x14], edx
// 004af2ba  84c9                 test cl, cl
// 004af2bc  7452                 je 0x4af310
// 004af2be  8b4718               mov eax, dword ptr [edi + 0x18]
// 004af2c1  8b28                 mov ebp, dword ptr [eax]
// 004af2c3  85d2                 test edx, edx
// 004af2c5  7404                 je 0x4af2cb
// 004af2c7  3bd2                 cmp edx, edx
// 004af2c9  7406                 je 0x4af2d1
// 004af2cb  ff1590288000         call dword ptr [0x802890]
// 004af2d1  8d4c2414             lea ecx, [esp + 0x14]
// 004af2d5  3bf5                 cmp esi, ebp
// 004af2d7  752a                 jne 0x4af303
// 004af2d9  53                   push ebx
// 004af2da  56                   push esi
// 004af2db  6a01                 push 1
// 004af2dd  51                   push ecx
// 004af2de  8bcf                 mov ecx, edi
// 004af2e0  e88bf0ffff           call 0x4ae370
// 004af2e5  5f                   pop edi
// 004af2e6  8bc8                 mov ecx, eax
// 004af2e8  8b11                 mov edx, dword ptr [ecx]
// 004af2ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004af2ee  8b4904               mov ecx, dword ptr [ecx + 4]
// 004af2f1  5e                   pop esi
// 004af2f2  5d                   pop ebp
// 004af2f3  894804               mov dword ptr [eax + 4], ecx
// 004af2f6  c6400801             mov byte ptr [eax + 8], 1
// 004af2fa  8910                 mov dword ptr [eax], edx
// 004af2fc  5b                   pop ebx
// 004af2fd  83c40c               add esp, 0xc
// 004af300  c20800               ret 8
// 004af303  e838ccffff           call 0x4abf40
// 004af308  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004af30c  8b542414             mov edx, dword ptr [esp + 0x14]
// 004af310  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004af313  3b03                 cmp eax, dword ptr [ebx]
// 004af315  7331                 jae 0x4af348
// 004af317  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004af31b  53                   push ebx
// 004af31c  56                   push esi
// 004af31d  51                   push ecx
// 004af31e  8d542420             lea edx, [esp + 0x20]
// 004af322  52                   push edx
// 004af323  8bcf                 mov ecx, edi
// 004af325  e846f0ffff           call 0x4ae370
// 004af32a  5f                   pop edi
// 004af32b  8bc8                 mov ecx, eax
// 004af32d  8b11                 mov edx, dword ptr [ecx]
// 004af32f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004af333  8b4904               mov ecx, dword ptr [ecx + 4]
// 004af336  5e                   pop esi
// 004af337  5d                   pop ebp
// 004af338  894804               mov dword ptr [eax + 4], ecx
// 004af33b  c6400801             mov byte ptr [eax + 8], 1
// 004af33f  8910                 mov dword ptr [eax], edx
// 004af341  5b                   pop ebx
// 004af342  83c40c               add esp, 0xc
// 004af345  c20800               ret 8
// 004af348  8b442420             mov eax, dword ptr [esp + 0x20]
// 004af34c  5f                   pop edi
// 004af34d  5e                   pop esi
// 004af34e  896804               mov dword ptr [eax + 4], ebp
// 004af351  5d                   pop ebp
// 004af352  c6400800             mov byte ptr [eax + 8], 0
// 004af356  8910                 mov dword ptr [eax], edx
// 004af358  5b                   pop ebx
// 004af359  83c40c               add esp, 0xc
// 004af35c  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;

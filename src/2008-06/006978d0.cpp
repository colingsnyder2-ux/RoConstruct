// from server: 100% by auto
// roc 2008-06 006978d0  unit: Ogre::RbxSceneManager  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006978d0
//
// 006978d0  53                   push ebx
// 006978d1  55                   push ebp
// 006978d2  8b2d90288000         mov ebp, dword ptr [0x802890]
// 006978d8  56                   push esi
// 006978d9  57                   push edi
// 006978da  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006978de  8bf1                 mov esi, ecx
// 006978e0  c70700000000         mov dword ptr [edi], 0
// 006978e6  85f6                 test esi, esi
// 006978e8  740e                 je 0x6978f8
// 006978ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006978ee  39460c               cmp dword ptr [esi + 0xc], eax
// 006978f1  7705                 ja 0x6978f8
// 006978f3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 006978f6  7606                 jbe 0x6978fe
// 006978f8  ffd5                 call ebp
// 006978fa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006978fe  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00697902  8b0e                 mov ecx, dword ptr [esi]
// 00697904  890f                 mov dword ptr [edi], ecx
// 00697906  894704               mov dword ptr [edi + 4], eax
// 00697909  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0069790c  7705                 ja 0x697913
// 0069790e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00697911  7606                 jbe 0x697919
// 00697913  ffd5                 call ebp
// 00697915  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00697919  8b07                 mov eax, dword ptr [edi]
// 0069791b  8b0e                 mov ecx, dword ptr [esi]
// 0069791d  85c0                 test eax, eax
// 0069791f  7404                 je 0x697925
// 00697921  3bc1                 cmp eax, ecx
// 00697923  7402                 je 0x697927
// 00697925  ffd5                 call ebp
// 00697927  8b4f04               mov ecx, dword ptr [edi + 4]
// 0069792a  3bcb                 cmp ecx, ebx
// 0069792c  7425                 je 0x697953
// 0069792e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00697931  c644241400           mov byte ptr [esp + 0x14], 0
// 00697936  8b542414             mov edx, dword ptr [esp + 0x14]
// 0069793a  52                   push edx
// 0069793b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069793f  52                   push edx
// 00697940  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00697944  52                   push edx
// 00697945  51                   push ecx
// 00697946  50                   push eax
// 00697947  53                   push ebx
// 00697948  e8b367ffff           call 0x68e100
// 0069794d  83c418               add esp, 0x18
// 00697950  894610               mov dword ptr [esi + 0x10], eax
// 00697953  8bc7                 mov eax, edi
// 00697955  5f                   pop edi
// 00697956  5e                   pop esi
// 00697957  5d                   pop ebp
// 00697958  5b                   pop ebx
// 00697959  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

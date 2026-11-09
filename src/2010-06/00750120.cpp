// from server: 100% by auto
// roc 2010-06 00750120  unit: RBX::Humanoid  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00750120
//
// 00750120  53                   push ebx
// 00750121  55                   push ebp
// 00750122  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00750128  56                   push esi
// 00750129  57                   push edi
// 0075012a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0075012e  8bf1                 mov esi, ecx
// 00750130  c70700000000         mov dword ptr [edi], 0
// 00750136  85f6                 test esi, esi
// 00750138  740e                 je 0x750148
// 0075013a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075013e  39460c               cmp dword ptr [esi + 0xc], eax
// 00750141  7705                 ja 0x750148
// 00750143  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00750146  7606                 jbe 0x75014e
// 00750148  ffd5                 call ebp
// 0075014a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075014e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00750152  8b0e                 mov ecx, dword ptr [esi]
// 00750154  890f                 mov dword ptr [edi], ecx
// 00750156  894704               mov dword ptr [edi + 4], eax
// 00750159  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0075015c  7705                 ja 0x750163
// 0075015e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00750161  7606                 jbe 0x750169
// 00750163  ffd5                 call ebp
// 00750165  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00750169  8b07                 mov eax, dword ptr [edi]
// 0075016b  8b0e                 mov ecx, dword ptr [esi]
// 0075016d  85c0                 test eax, eax
// 0075016f  7404                 je 0x750175
// 00750171  3bc1                 cmp eax, ecx
// 00750173  7402                 je 0x750177
// 00750175  ffd5                 call ebp
// 00750177  8b4f04               mov ecx, dword ptr [edi + 4]
// 0075017a  3bcb                 cmp ecx, ebx
// 0075017c  7425                 je 0x7501a3
// 0075017e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00750181  c644241400           mov byte ptr [esp + 0x14], 0
// 00750186  8b542414             mov edx, dword ptr [esp + 0x14]
// 0075018a  52                   push edx
// 0075018b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0075018f  52                   push edx
// 00750190  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00750194  52                   push edx
// 00750195  51                   push ecx
// 00750196  50                   push eax
// 00750197  53                   push ebx
// 00750198  e883f9ffff           call 0x74fb20
// 0075019d  83c418               add esp, 0x18
// 007501a0  894610               mov dword ptr [esi + 0x10], eax
// 007501a3  8bc7                 mov eax, edi
// 007501a5  5f                   pop edi
// 007501a6  5e                   pop esi
// 007501a7  5d                   pop ebp
// 007501a8  5b                   pop ebx
// 007501a9  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

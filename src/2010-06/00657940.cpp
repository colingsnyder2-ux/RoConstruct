// from server: 100% by auto
// roc 2010-06 00657940  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00657940
//
// 00657940  53                   push ebx
// 00657941  55                   push ebp
// 00657942  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00657948  56                   push esi
// 00657949  57                   push edi
// 0065794a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0065794e  8bf1                 mov esi, ecx
// 00657950  c70700000000         mov dword ptr [edi], 0
// 00657956  85f6                 test esi, esi
// 00657958  740e                 je 0x657968
// 0065795a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065795e  39460c               cmp dword ptr [esi + 0xc], eax
// 00657961  7705                 ja 0x657968
// 00657963  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00657966  7606                 jbe 0x65796e
// 00657968  ffd5                 call ebp
// 0065796a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065796e  8b0e                 mov ecx, dword ptr [esi]
// 00657970  894704               mov dword ptr [edi + 4], eax
// 00657973  8b442424             mov eax, dword ptr [esp + 0x24]
// 00657977  890f                 mov dword ptr [edi], ecx
// 00657979  39460c               cmp dword ptr [esi + 0xc], eax
// 0065797c  7705                 ja 0x657983
// 0065797e  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00657981  7606                 jbe 0x657989
// 00657983  ffd5                 call ebp
// 00657985  8b442424             mov eax, dword ptr [esp + 0x24]
// 00657989  8b0e                 mov ecx, dword ptr [esi]
// 0065798b  8bd8                 mov ebx, eax
// 0065798d  8b07                 mov eax, dword ptr [edi]
// 0065798f  85c0                 test eax, eax
// 00657991  7404                 je 0x657997
// 00657993  3bc1                 cmp eax, ecx
// 00657995  7402                 je 0x657999
// 00657997  ffd5                 call ebp
// 00657999  8b4704               mov eax, dword ptr [edi + 4]
// 0065799c  3bc3                 cmp eax, ebx
// 0065799e  7411                 je 0x6579b1
// 006579a0  8b5610               mov edx, dword ptr [esi + 0x10]
// 006579a3  50                   push eax
// 006579a4  52                   push edx
// 006579a5  53                   push ebx
// 006579a6  e835fcffff           call 0x6575e0
// 006579ab  83c40c               add esp, 0xc
// 006579ae  894610               mov dword ptr [esi + 0x10], eax
// 006579b1  8bc7                 mov eax, edi
// 006579b3  5f                   pop edi
// 006579b4  5e                   pop esi
// 006579b5  5d                   pop ebp
// 006579b6  5b                   pop ebx
// 006579b7  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;

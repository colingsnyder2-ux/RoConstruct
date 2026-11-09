// from server: 100% by auto
// roc 2010-06 00704880  unit: RBX::VInstance::?$NonFactoryProduct  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704880
//
// 00704880  53                   push ebx
// 00704881  55                   push ebp
// 00704882  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00704888  56                   push esi
// 00704889  57                   push edi
// 0070488a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0070488e  8bf1                 mov esi, ecx
// 00704890  c70700000000         mov dword ptr [edi], 0
// 00704896  85f6                 test esi, esi
// 00704898  740e                 je 0x7048a8
// 0070489a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070489e  39460c               cmp dword ptr [esi + 0xc], eax
// 007048a1  7705                 ja 0x7048a8
// 007048a3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 007048a6  7606                 jbe 0x7048ae
// 007048a8  ffd5                 call ebp
// 007048aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007048ae  8b0e                 mov ecx, dword ptr [esi]
// 007048b0  894704               mov dword ptr [edi + 4], eax
// 007048b3  8b442424             mov eax, dword ptr [esp + 0x24]
// 007048b7  890f                 mov dword ptr [edi], ecx
// 007048b9  39460c               cmp dword ptr [esi + 0xc], eax
// 007048bc  7705                 ja 0x7048c3
// 007048be  3b4610               cmp eax, dword ptr [esi + 0x10]
// 007048c1  7606                 jbe 0x7048c9
// 007048c3  ffd5                 call ebp
// 007048c5  8b442424             mov eax, dword ptr [esp + 0x24]
// 007048c9  8b0e                 mov ecx, dword ptr [esi]
// 007048cb  8bd8                 mov ebx, eax
// 007048cd  8b07                 mov eax, dword ptr [edi]
// 007048cf  85c0                 test eax, eax
// 007048d1  7404                 je 0x7048d7
// 007048d3  3bc1                 cmp eax, ecx
// 007048d5  7402                 je 0x7048d9
// 007048d7  ffd5                 call ebp
// 007048d9  8b4704               mov eax, dword ptr [edi + 4]
// 007048dc  3bc3                 cmp eax, ebx
// 007048de  7411                 je 0x7048f1
// 007048e0  8b5610               mov edx, dword ptr [esi + 0x10]
// 007048e3  50                   push eax
// 007048e4  52                   push edx
// 007048e5  53                   push ebx
// 007048e6  e8c5f8ffff           call 0x7041b0
// 007048eb  83c40c               add esp, 0xc
// 007048ee  894610               mov dword ptr [esi + 0x10], eax
// 007048f1  8bc7                 mov eax, edi
// 007048f3  5f                   pop edi
// 007048f4  5e                   pop esi
// 007048f5  5d                   pop ebp
// 007048f6  5b                   pop ebx
// 007048f7  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;

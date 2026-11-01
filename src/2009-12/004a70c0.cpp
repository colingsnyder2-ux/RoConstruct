// from server: 100% by auto
// roc 2009-12 004a70c0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a70c0
//
// 004a70c0  83ec08               sub esp, 8
// 004a70c3  56                   push esi
// 004a70c4  8bf1                 mov esi, ecx
// 004a70c6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a70c9  57                   push edi
// 004a70ca  85c9                 test ecx, ecx
// 004a70cc  7504                 jne 0x4a70d2
// 004a70ce  33c0                 xor eax, eax
// 004a70d0  eb08                 jmp 0x4a70da
// 004a70d2  8b4614               mov eax, dword ptr [esi + 0x14]
// 004a70d5  2bc1                 sub eax, ecx
// 004a70d7  c1f805               sar eax, 5
// 004a70da  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004a70dd  8bd7                 mov edx, edi
// 004a70df  2bd1                 sub edx, ecx
// 004a70e1  c1fa05               sar edx, 5
// 004a70e4  3bd0                 cmp edx, eax
// 004a70e6  7331                 jae 0x4a7119
// 004a70e8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a70ec  c644240800           mov byte ptr [esp + 8], 0
// 004a70f1  8b442408             mov eax, dword ptr [esp + 8]
// 004a70f5  50                   push eax
// 004a70f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a70fa  51                   push ecx
// 004a70fb  8d5608               lea edx, [esi + 8]
// 004a70fe  52                   push edx
// 004a70ff  50                   push eax
// 004a7100  6a01                 push 1
// 004a7102  57                   push edi
// 004a7103  e818adffff           call 0x4a1e20
// 004a7108  83c418               add esp, 0x18
// 004a710b  83c720               add edi, 0x20
// 004a710e  897e10               mov dword ptr [esi + 0x10], edi
// 004a7111  5f                   pop edi
// 004a7112  5e                   pop esi
// 004a7113  83c408               add esp, 8
// 004a7116  c20400               ret 4
// 004a7119  3bcf                 cmp ecx, edi
// 004a711b  7606                 jbe 0x4a7123
// 004a711d  ff1560b79800         call dword ptr [0x98b760]
// 004a7123  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a7127  8b06                 mov eax, dword ptr [esi]
// 004a7129  51                   push ecx
// 004a712a  57                   push edi
// 004a712b  50                   push eax
// 004a712c  8d542414             lea edx, [esp + 0x14]
// 004a7130  52                   push edx
// 004a7131  8bce                 mov ecx, esi
// 004a7133  e8d8c7ffff           call 0x4a3910
// 004a7138  5f                   pop edi
// 004a7139  5e                   pop esi
// 004a713a  83c408               add esp, 8
// 004a713d  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;

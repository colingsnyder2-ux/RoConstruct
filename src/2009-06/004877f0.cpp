// from server: 100% by auto
// roc 2009-06 004877f0  unit: Ogre::RbxMeshPartAdapter  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004877f0
//
// 004877f0  83ec08               sub esp, 8
// 004877f3  56                   push esi
// 004877f4  8bf1                 mov esi, ecx
// 004877f6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004877f9  57                   push edi
// 004877fa  85c9                 test ecx, ecx
// 004877fc  7504                 jne 0x487802
// 004877fe  33c0                 xor eax, eax
// 00487800  eb08                 jmp 0x48780a
// 00487802  8b4614               mov eax, dword ptr [esi + 0x14]
// 00487805  2bc1                 sub eax, ecx
// 00487807  c1f804               sar eax, 4
// 0048780a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048780d  8bd7                 mov edx, edi
// 0048780f  2bd1                 sub edx, ecx
// 00487811  c1fa04               sar edx, 4
// 00487814  3bd0                 cmp edx, eax
// 00487816  7331                 jae 0x487849
// 00487818  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048781c  c644240800           mov byte ptr [esp + 8], 0
// 00487821  8b442408             mov eax, dword ptr [esp + 8]
// 00487825  50                   push eax
// 00487826  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048782a  51                   push ecx
// 0048782b  8d5608               lea edx, [esi + 8]
// 0048782e  52                   push edx
// 0048782f  50                   push eax
// 00487830  6a01                 push 1
// 00487832  57                   push edi
// 00487833  e828ecffff           call 0x486460
// 00487838  83c418               add esp, 0x18
// 0048783b  83c710               add edi, 0x10
// 0048783e  897e10               mov dword ptr [esi + 0x10], edi
// 00487841  5f                   pop edi
// 00487842  5e                   pop esi
// 00487843  83c408               add esp, 8
// 00487846  c20400               ret 4
// 00487849  3bcf                 cmp ecx, edi
// 0048784b  7606                 jbe 0x487853
// 0048784d  ff15ace98900         call dword ptr [0x89e9ac]
// 00487853  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00487857  8b06                 mov eax, dword ptr [esi]
// 00487859  51                   push ecx
// 0048785a  57                   push edi
// 0048785b  50                   push eax
// 0048785c  8d542414             lea edx, [esp + 0x14]
// 00487860  52                   push edx
// 00487861  8bce                 mov ecx, esi
// 00487863  e8b8fcffff           call 0x487520
// 00487868  5f                   pop edi
// 00487869  5e                   pop esi
// 0048786a  83c408               add esp, 8
// 0048786d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;

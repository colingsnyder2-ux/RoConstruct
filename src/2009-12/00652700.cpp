// from server: 100% by nuck16
// roc 2009-12 00652700  unit: RBX::DataModelMesh::W4LODType::?$EnumDesc  size: 88 bytes
//
// 00652700  8b442404             mov eax, dword ptr [esp + 4]
// 00652704  56                   push esi
// 00652705  57                   push edi
// 00652706  50                   push eax
// 00652707  8bf1                 mov esi, ecx
// 00652709  e8528fffff           call 0x64b660
// 0065270e  8b38                 mov edi, dword ptr [eax]
// 00652710  83c404               add esp, 4
// 00652713  85ff                 test edi, edi
// 00652715  7d07                 jge 0x65271e
// 00652717  5f                   pop edi
// 00652718  33c0                 xor eax, eax
// 0065271a  5e                   pop esi
// 0065271b  c20400               ret 4
// 0065271e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652724  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065272a  c1f902               sar ecx, 2
// 0065272d  3bf9                 cmp edi, ecx
// 0065272f  73e6                 jae 0x652717
// 00652731  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652737  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065273d  c1fa02               sar edx, 2
// 00652740  3bfa                 cmp edi, edx
// 00652742  7206                 jb 0x65274a
// 00652744  ff1560b79800         call dword ptr [0x98b760]
// 0065274a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652750  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652753  5f                   pop edi
// 00652754  5e                   pop esi
// 00652755  c20400               ret 4

#include <vector>

struct Key;
struct Item;

int *lookupIndex(const Key &key);

struct S
{
    char pad[0xa4];
    std::vector<Item *> items;
    Item *f(const Key &key);
};

Item *S::f(const Key &key)
{
    int index = *lookupIndex(key);
    if (index < 0)
        return 0;
    if ((size_t)index >= items.size())
        return 0;
    return items[index];
}

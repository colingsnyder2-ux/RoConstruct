// from server: 100% by nuck16
// roc 2009-12 00447960  unit: RBX::CRenderSettings::W4AASamples::?$EnumDesc  size: 88 bytes
//
// 00447960  8b442404             mov eax, dword ptr [esp + 4]
// 00447964  56                   push esi
// 00447965  57                   push edi
// 00447966  50                   push eax
// 00447967  8bf1                 mov esi, ecx
// 00447969  e822f8ffff           call 0x447190
// 0044796e  8b38                 mov edi, dword ptr [eax]
// 00447970  83c404               add esp, 4
// 00447973  85ff                 test edi, edi
// 00447975  7d07                 jge 0x44797e
// 00447977  5f                   pop edi
// 00447978  33c0                 xor eax, eax
// 0044797a  5e                   pop esi
// 0044797b  c20400               ret 4
// 0044797e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447984  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0044798a  c1f902               sar ecx, 2
// 0044798d  3bf9                 cmp edi, ecx
// 0044798f  73e6                 jae 0x447977
// 00447991  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447997  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0044799d  c1fa02               sar edx, 2
// 004479a0  3bfa                 cmp edi, edx
// 004479a2  7206                 jb 0x4479aa
// 004479a4  ff1560b79800         call dword ptr [0x98b760]
// 004479aa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 004479b0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 004479b3  5f                   pop edi
// 004479b4  5e                   pop esi
// 004479b5  c20400               ret 4

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

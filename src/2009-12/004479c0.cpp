// from server: 100% by nuck16
// roc 2009-12 004479c0  unit: RBX::CRenderSettings::W4GraphicsMode::?$EnumDesc  size: 88 bytes
//
// 004479c0  8b442404             mov eax, dword ptr [esp + 4]
// 004479c4  56                   push esi
// 004479c5  57                   push edi
// 004479c6  50                   push eax
// 004479c7  8bf1                 mov esi, ecx
// 004479c9  e852f8ffff           call 0x447220
// 004479ce  8b38                 mov edi, dword ptr [eax]
// 004479d0  83c404               add esp, 4
// 004479d3  85ff                 test edi, edi
// 004479d5  7d07                 jge 0x4479de
// 004479d7  5f                   pop edi
// 004479d8  33c0                 xor eax, eax
// 004479da  5e                   pop esi
// 004479db  c20400               ret 4
// 004479de  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 004479e4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 004479ea  c1f902               sar ecx, 2
// 004479ed  3bf9                 cmp edi, ecx
// 004479ef  73e6                 jae 0x4479d7
// 004479f1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 004479f7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 004479fd  c1fa02               sar edx, 2
// 00447a00  3bfa                 cmp edi, edx
// 00447a02  7206                 jb 0x447a0a
// 00447a04  ff1560b79800         call dword ptr [0x98b760]
// 00447a0a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447a10  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447a13  5f                   pop edi
// 00447a14  5e                   pop esi
// 00447a15  c20400               ret 4

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

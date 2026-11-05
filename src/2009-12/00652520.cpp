// from server: 100% by nuck16
// roc 2009-12 00652520  unit: RBX::GuiObject::W4SizeConstraint::?$EnumDesc  size: 88 bytes
//
// 00652520  8b442404             mov eax, dword ptr [esp + 4]
// 00652524  56                   push esi
// 00652525  57                   push edi
// 00652526  50                   push eax
// 00652527  8bf1                 mov esi, ecx
// 00652529  e86282ffff           call 0x64a790
// 0065252e  8b38                 mov edi, dword ptr [eax]
// 00652530  83c404               add esp, 4
// 00652533  85ff                 test edi, edi
// 00652535  7d07                 jge 0x65253e
// 00652537  5f                   pop edi
// 00652538  33c0                 xor eax, eax
// 0065253a  5e                   pop esi
// 0065253b  c20400               ret 4
// 0065253e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652544  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065254a  c1f902               sar ecx, 2
// 0065254d  3bf9                 cmp edi, ecx
// 0065254f  73e6                 jae 0x652537
// 00652551  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652557  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065255d  c1fa02               sar edx, 2
// 00652560  3bfa                 cmp edi, edx
// 00652562  7206                 jb 0x65256a
// 00652564  ff1560b79800         call dword ptr [0x98b760]
// 0065256a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652570  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652573  5f                   pop edi
// 00652574  5e                   pop esi
// 00652575  c20400               ret 4

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

// from server: 100% by nuck16
// roc 2009-12 00652400  unit: RBX::Action::W4ActionType::?$EnumDesc  size: 88 bytes
//
// 00652400  8b442404             mov eax, dword ptr [esp + 4]
// 00652404  56                   push esi
// 00652405  57                   push edi
// 00652406  50                   push eax
// 00652407  8bf1                 mov esi, ecx
// 00652409  e8727affff           call 0x649e80
// 0065240e  8b38                 mov edi, dword ptr [eax]
// 00652410  83c404               add esp, 4
// 00652413  85ff                 test edi, edi
// 00652415  7d07                 jge 0x65241e
// 00652417  5f                   pop edi
// 00652418  33c0                 xor eax, eax
// 0065241a  5e                   pop esi
// 0065241b  c20400               ret 4
// 0065241e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652424  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065242a  c1f902               sar ecx, 2
// 0065242d  3bf9                 cmp edi, ecx
// 0065242f  73e6                 jae 0x652417
// 00652431  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652437  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065243d  c1fa02               sar edx, 2
// 00652440  3bfa                 cmp edi, edx
// 00652442  7206                 jb 0x65244a
// 00652444  ff1560b79800         call dword ptr [0x98b760]
// 0065244a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652450  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652453  5f                   pop edi
// 00652454  5e                   pop esi
// 00652455  c20400               ret 4

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

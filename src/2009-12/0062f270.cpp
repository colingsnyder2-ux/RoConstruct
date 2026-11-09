// from server: 100% by nuck16
// roc 2009-12 0062f270  unit: RBX::DataModelArbiter::W4ConcurrencyModel::?$EnumDesc  size: 88 bytes
//
// 0062f270  8b442404             mov eax, dword ptr [esp + 4]
// 0062f274  56                   push esi
// 0062f275  57                   push edi
// 0062f276  50                   push eax
// 0062f277  8bf1                 mov esi, ecx
// 0062f279  e852faffff           call 0x62ecd0
// 0062f27e  8b38                 mov edi, dword ptr [eax]
// 0062f280  83c404               add esp, 4
// 0062f283  85ff                 test edi, edi
// 0062f285  7d07                 jge 0x62f28e
// 0062f287  5f                   pop edi
// 0062f288  33c0                 xor eax, eax
// 0062f28a  5e                   pop esi
// 0062f28b  c20400               ret 4
// 0062f28e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0062f294  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0062f29a  c1f902               sar ecx, 2
// 0062f29d  3bf9                 cmp edi, ecx
// 0062f29f  73e6                 jae 0x62f287
// 0062f2a1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0062f2a7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0062f2ad  c1fa02               sar edx, 2
// 0062f2b0  3bfa                 cmp edi, edx
// 0062f2b2  7206                 jb 0x62f2ba
// 0062f2b4  ff1560b79800         call dword ptr [0x98b760]
// 0062f2ba  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0062f2c0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0062f2c3  5f                   pop edi
// 0062f2c4  5e                   pop esi
// 0062f2c5  c20400               ret 4

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

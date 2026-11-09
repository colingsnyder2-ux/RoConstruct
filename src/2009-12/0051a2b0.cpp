// from server: 100% by nuck16
// roc 2009-12 0051a2b0  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 88 bytes
//
// 0051a2b0  8b442404             mov eax, dword ptr [esp + 4]
// 0051a2b4  56                   push esi
// 0051a2b5  57                   push edi
// 0051a2b6  50                   push eax
// 0051a2b7  8bf1                 mov esi, ecx
// 0051a2b9  e862edffff           call 0x519020
// 0051a2be  8b38                 mov edi, dword ptr [eax]
// 0051a2c0  83c404               add esp, 4
// 0051a2c3  85ff                 test edi, edi
// 0051a2c5  7d07                 jge 0x51a2ce
// 0051a2c7  5f                   pop edi
// 0051a2c8  33c0                 xor eax, eax
// 0051a2ca  5e                   pop esi
// 0051a2cb  c20400               ret 4
// 0051a2ce  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0051a2d4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0051a2da  c1f902               sar ecx, 2
// 0051a2dd  3bf9                 cmp edi, ecx
// 0051a2df  73e6                 jae 0x51a2c7
// 0051a2e1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0051a2e7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0051a2ed  c1fa02               sar edx, 2
// 0051a2f0  3bfa                 cmp edi, edx
// 0051a2f2  7206                 jb 0x51a2fa
// 0051a2f4  ff1560b79800         call dword ptr [0x98b760]
// 0051a2fa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0051a300  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0051a303  5f                   pop edi
// 0051a304  5e                   pop esi
// 0051a305  c20400               ret 4

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

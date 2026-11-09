// from server: 100% by nuck16
// roc 2009-12 00630600  unit: RBX::EThrottle::W4EThrottleType::?$EnumDesc  size: 88 bytes
//
// 00630600  8b442404             mov eax, dword ptr [esp + 4]
// 00630604  56                   push esi
// 00630605  57                   push edi
// 00630606  50                   push eax
// 00630607  8bf1                 mov esi, ecx
// 00630609  e842ffffff           call 0x630550
// 0063060e  8b38                 mov edi, dword ptr [eax]
// 00630610  83c404               add esp, 4
// 00630613  85ff                 test edi, edi
// 00630615  7d07                 jge 0x63061e
// 00630617  5f                   pop edi
// 00630618  33c0                 xor eax, eax
// 0063061a  5e                   pop esi
// 0063061b  c20400               ret 4
// 0063061e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00630624  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0063062a  c1f902               sar ecx, 2
// 0063062d  3bf9                 cmp edi, ecx
// 0063062f  73e6                 jae 0x630617
// 00630631  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00630637  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0063063d  c1fa02               sar edx, 2
// 00630640  3bfa                 cmp edi, edx
// 00630642  7206                 jb 0x63064a
// 00630644  ff1560b79800         call dword ptr [0x98b760]
// 0063064a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00630650  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00630653  5f                   pop edi
// 00630654  5e                   pop esi
// 00630655  c20400               ret 4

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

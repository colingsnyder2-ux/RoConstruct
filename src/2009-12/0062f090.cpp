// from server: 100% by nuck16
// roc 2009-12 0062f090  unit: RBX::TaskScheduler::W4ThreadConfig::?$EnumDesc  size: 88 bytes
//
// 0062f090  8b442404             mov eax, dword ptr [esp + 4]
// 0062f094  56                   push esi
// 0062f095  57                   push edi
// 0062f096  50                   push eax
// 0062f097  8bf1                 mov esi, ecx
// 0062f099  e802f5ffff           call 0x62e5a0
// 0062f09e  8b38                 mov edi, dword ptr [eax]
// 0062f0a0  83c404               add esp, 4
// 0062f0a3  85ff                 test edi, edi
// 0062f0a5  7d07                 jge 0x62f0ae
// 0062f0a7  5f                   pop edi
// 0062f0a8  33c0                 xor eax, eax
// 0062f0aa  5e                   pop esi
// 0062f0ab  c20400               ret 4
// 0062f0ae  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0062f0b4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0062f0ba  c1f902               sar ecx, 2
// 0062f0bd  3bf9                 cmp edi, ecx
// 0062f0bf  73e6                 jae 0x62f0a7
// 0062f0c1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0062f0c7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0062f0cd  c1fa02               sar edx, 2
// 0062f0d0  3bfa                 cmp edi, edx
// 0062f0d2  7206                 jb 0x62f0da
// 0062f0d4  ff1560b79800         call dword ptr [0x98b760]
// 0062f0da  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0062f0e0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0062f0e3  5f                   pop edi
// 0062f0e4  5e                   pop esi
// 0062f0e5  c20400               ret 4

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

// from server: 100% by nuck16
// roc 2009-12 0062f150  unit: RBX::TaskScheduler::Job::W4SleepAdjustMethod::?$EnumDesc  size: 88 bytes
//
// 0062f150  8b442404             mov eax, dword ptr [esp + 4]
// 0062f154  56                   push esi
// 0062f155  57                   push edi
// 0062f156  50                   push eax
// 0062f157  8bf1                 mov esi, ecx
// 0062f159  e862f5ffff           call 0x62e6c0
// 0062f15e  8b38                 mov edi, dword ptr [eax]
// 0062f160  83c404               add esp, 4
// 0062f163  85ff                 test edi, edi
// 0062f165  7d07                 jge 0x62f16e
// 0062f167  5f                   pop edi
// 0062f168  33c0                 xor eax, eax
// 0062f16a  5e                   pop esi
// 0062f16b  c20400               ret 4
// 0062f16e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0062f174  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0062f17a  c1f902               sar ecx, 2
// 0062f17d  3bf9                 cmp edi, ecx
// 0062f17f  73e6                 jae 0x62f167
// 0062f181  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0062f187  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0062f18d  c1fa02               sar edx, 2
// 0062f190  3bfa                 cmp edi, edx
// 0062f192  7206                 jb 0x62f19a
// 0062f194  ff1560b79800         call dword ptr [0x98b760]
// 0062f19a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0062f1a0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0062f1a3  5f                   pop edi
// 0062f1a4  5e                   pop esi
// 0062f1a5  c20400               ret 4

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

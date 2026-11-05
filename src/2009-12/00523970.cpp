// from server: 100% by nuck16
// roc 2009-12 00523970  unit: W4PacketReliability::?$EnumDesc  size: 88 bytes
//
// 00523970  8b442404             mov eax, dword ptr [esp + 4]
// 00523974  56                   push esi
// 00523975  57                   push edi
// 00523976  50                   push eax
// 00523977  8bf1                 mov esi, ecx
// 00523979  e832f5ffff           call 0x522eb0
// 0052397e  8b38                 mov edi, dword ptr [eax]
// 00523980  83c404               add esp, 4
// 00523983  85ff                 test edi, edi
// 00523985  7d07                 jge 0x52398e
// 00523987  5f                   pop edi
// 00523988  33c0                 xor eax, eax
// 0052398a  5e                   pop esi
// 0052398b  c20400               ret 4
// 0052398e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00523994  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0052399a  c1f902               sar ecx, 2
// 0052399d  3bf9                 cmp edi, ecx
// 0052399f  73e6                 jae 0x523987
// 005239a1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 005239a7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 005239ad  c1fa02               sar edx, 2
// 005239b0  3bfa                 cmp edi, edx
// 005239b2  7206                 jb 0x5239ba
// 005239b4  ff1560b79800         call dword ptr [0x98b760]
// 005239ba  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 005239c0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 005239c3  5f                   pop edi
// 005239c4  5e                   pop esi
// 005239c5  c20400               ret 4

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

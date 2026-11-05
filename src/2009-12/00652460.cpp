// from server: 100% by nuck16
// roc 2009-12 00652460  unit: W4AffectType::?$EnumDesc  size: 88 bytes
//
// 00652460  8b442404             mov eax, dword ptr [esp + 4]
// 00652464  56                   push esi
// 00652465  57                   push edi
// 00652466  50                   push eax
// 00652467  8bf1                 mov esi, ecx
// 00652469  e8027dffff           call 0x64a170
// 0065246e  8b38                 mov edi, dword ptr [eax]
// 00652470  83c404               add esp, 4
// 00652473  85ff                 test edi, edi
// 00652475  7d07                 jge 0x65247e
// 00652477  5f                   pop edi
// 00652478  33c0                 xor eax, eax
// 0065247a  5e                   pop esi
// 0065247b  c20400               ret 4
// 0065247e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652484  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065248a  c1f902               sar ecx, 2
// 0065248d  3bf9                 cmp edi, ecx
// 0065248f  73e6                 jae 0x652477
// 00652491  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652497  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065249d  c1fa02               sar edx, 2
// 006524a0  3bfa                 cmp edi, edx
// 006524a2  7206                 jb 0x6524aa
// 006524a4  ff1560b79800         call dword ptr [0x98b760]
// 006524aa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006524b0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006524b3  5f                   pop edi
// 006524b4  5e                   pop esi
// 006524b5  c20400               ret 4

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

// from server: 100% by nuck16
// roc 2009-12 00652760  unit: RBX::Feature::W4InOut::?$EnumDesc  size: 88 bytes
//
// 00652760  8b442404             mov eax, dword ptr [esp + 4]
// 00652764  56                   push esi
// 00652765  57                   push edi
// 00652766  50                   push eax
// 00652767  8bf1                 mov esi, ecx
// 00652769  e8e291ffff           call 0x64b950
// 0065276e  8b38                 mov edi, dword ptr [eax]
// 00652770  83c404               add esp, 4
// 00652773  85ff                 test edi, edi
// 00652775  7d07                 jge 0x65277e
// 00652777  5f                   pop edi
// 00652778  33c0                 xor eax, eax
// 0065277a  5e                   pop esi
// 0065277b  c20400               ret 4
// 0065277e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652784  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065278a  c1f902               sar ecx, 2
// 0065278d  3bf9                 cmp edi, ecx
// 0065278f  73e6                 jae 0x652777
// 00652791  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652797  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065279d  c1fa02               sar edx, 2
// 006527a0  3bfa                 cmp edi, edx
// 006527a2  7206                 jb 0x6527aa
// 006527a4  ff1560b79800         call dword ptr [0x98b760]
// 006527aa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006527b0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006527b3  5f                   pop edi
// 006527b4  5e                   pop esi
// 006527b5  c20400               ret 4

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

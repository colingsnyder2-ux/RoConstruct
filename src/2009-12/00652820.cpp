// from server: 100% by nuck16
// roc 2009-12 00652820  unit: RBX::Feature::W4TopBottom::?$EnumDesc  size: 88 bytes
//
// 00652820  8b442404             mov eax, dword ptr [esp + 4]
// 00652824  56                   push esi
// 00652825  57                   push edi
// 00652826  50                   push eax
// 00652827  8bf1                 mov esi, ecx
// 00652829  e80297ffff           call 0x64bf30
// 0065282e  8b38                 mov edi, dword ptr [eax]
// 00652830  83c404               add esp, 4
// 00652833  85ff                 test edi, edi
// 00652835  7d07                 jge 0x65283e
// 00652837  5f                   pop edi
// 00652838  33c0                 xor eax, eax
// 0065283a  5e                   pop esi
// 0065283b  c20400               ret 4
// 0065283e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652844  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065284a  c1f902               sar ecx, 2
// 0065284d  3bf9                 cmp edi, ecx
// 0065284f  73e6                 jae 0x652837
// 00652851  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652857  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065285d  c1fa02               sar edx, 2
// 00652860  3bfa                 cmp edi, edx
// 00652862  7206                 jb 0x65286a
// 00652864  ff1560b79800         call dword ptr [0x98b760]
// 0065286a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652870  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652873  5f                   pop edi
// 00652874  5e                   pop esi
// 00652875  c20400               ret 4

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

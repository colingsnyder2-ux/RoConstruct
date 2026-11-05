// from server: 100% by nuck16
// roc 2009-12 00447c00  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 88 bytes
//
// 00447c00  8b442404             mov eax, dword ptr [esp + 4]
// 00447c04  56                   push esi
// 00447c05  57                   push edi
// 00447c06  50                   push eax
// 00447c07  8bf1                 mov esi, ecx
// 00447c09  e872f9ffff           call 0x447580
// 00447c0e  8b38                 mov edi, dword ptr [eax]
// 00447c10  83c404               add esp, 4
// 00447c13  85ff                 test edi, edi
// 00447c15  7d07                 jge 0x447c1e
// 00447c17  5f                   pop edi
// 00447c18  33c0                 xor eax, eax
// 00447c1a  5e                   pop esi
// 00447c1b  c20400               ret 4
// 00447c1e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447c24  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00447c2a  c1f902               sar ecx, 2
// 00447c2d  3bf9                 cmp edi, ecx
// 00447c2f  73e6                 jae 0x447c17
// 00447c31  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447c37  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00447c3d  c1fa02               sar edx, 2
// 00447c40  3bfa                 cmp edi, edx
// 00447c42  7206                 jb 0x447c4a
// 00447c44  ff1560b79800         call dword ptr [0x98b760]
// 00447c4a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447c50  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447c53  5f                   pop edi
// 00447c54  5e                   pop esi
// 00447c55  c20400               ret 4

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

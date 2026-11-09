// from server: 100% by nuck16
// roc 2009-12 00652d00  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 88 bytes
//
// 00652d00  8b442404             mov eax, dword ptr [esp + 4]
// 00652d04  56                   push esi
// 00652d05  57                   push edi
// 00652d06  50                   push eax
// 00652d07  8bf1                 mov esi, ecx
// 00652d09  e862baffff           call 0x64e770
// 00652d0e  8b38                 mov edi, dword ptr [eax]
// 00652d10  83c404               add esp, 4
// 00652d13  85ff                 test edi, edi
// 00652d15  7d07                 jge 0x652d1e
// 00652d17  5f                   pop edi
// 00652d18  33c0                 xor eax, eax
// 00652d1a  5e                   pop esi
// 00652d1b  c20400               ret 4
// 00652d1e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652d24  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652d2a  c1f902               sar ecx, 2
// 00652d2d  3bf9                 cmp edi, ecx
// 00652d2f  73e6                 jae 0x652d17
// 00652d31  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652d37  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652d3d  c1fa02               sar edx, 2
// 00652d40  3bfa                 cmp edi, edx
// 00652d42  7206                 jb 0x652d4a
// 00652d44  ff1560b79800         call dword ptr [0x98b760]
// 00652d4a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652d50  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652d53  5f                   pop edi
// 00652d54  5e                   pop esi
// 00652d55  c20400               ret 4

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

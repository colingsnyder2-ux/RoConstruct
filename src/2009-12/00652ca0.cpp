// from server: 100% by nuck16
// roc 2009-12 00652ca0  unit: RBX::PartInstance::W4FormFactor::?$EnumDesc  size: 88 bytes
//
// 00652ca0  8b442404             mov eax, dword ptr [esp + 4]
// 00652ca4  56                   push esi
// 00652ca5  57                   push edi
// 00652ca6  50                   push eax
// 00652ca7  8bf1                 mov esi, ecx
// 00652ca9  e8d2b7ffff           call 0x64e480
// 00652cae  8b38                 mov edi, dword ptr [eax]
// 00652cb0  83c404               add esp, 4
// 00652cb3  85ff                 test edi, edi
// 00652cb5  7d07                 jge 0x652cbe
// 00652cb7  5f                   pop edi
// 00652cb8  33c0                 xor eax, eax
// 00652cba  5e                   pop esi
// 00652cbb  c20400               ret 4
// 00652cbe  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652cc4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652cca  c1f902               sar ecx, 2
// 00652ccd  3bf9                 cmp edi, ecx
// 00652ccf  73e6                 jae 0x652cb7
// 00652cd1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652cd7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652cdd  c1fa02               sar edx, 2
// 00652ce0  3bfa                 cmp edi, edx
// 00652ce2  7206                 jb 0x652cea
// 00652ce4  ff1560b79800         call dword ptr [0x98b760]
// 00652cea  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652cf0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652cf3  5f                   pop edi
// 00652cf4  5e                   pop esi
// 00652cf5  c20400               ret 4

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

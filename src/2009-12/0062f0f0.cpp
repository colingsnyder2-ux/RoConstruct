// from server: 100% by nuck16
// roc 2009-12 0062f0f0  unit: RBX::TaskScheduler::W4PriorityMethod::?$EnumDesc  size: 88 bytes
//
// 0062f0f0  8b442404             mov eax, dword ptr [esp + 4]
// 0062f0f4  56                   push esi
// 0062f0f5  57                   push edi
// 0062f0f6  50                   push eax
// 0062f0f7  8bf1                 mov esi, ecx
// 0062f0f9  e832f5ffff           call 0x62e630
// 0062f0fe  8b38                 mov edi, dword ptr [eax]
// 0062f100  83c404               add esp, 4
// 0062f103  85ff                 test edi, edi
// 0062f105  7d07                 jge 0x62f10e
// 0062f107  5f                   pop edi
// 0062f108  33c0                 xor eax, eax
// 0062f10a  5e                   pop esi
// 0062f10b  c20400               ret 4
// 0062f10e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0062f114  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0062f11a  c1f902               sar ecx, 2
// 0062f11d  3bf9                 cmp edi, ecx
// 0062f11f  73e6                 jae 0x62f107
// 0062f121  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0062f127  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0062f12d  c1fa02               sar edx, 2
// 0062f130  3bfa                 cmp edi, edx
// 0062f132  7206                 jb 0x62f13a
// 0062f134  ff1560b79800         call dword ptr [0x98b760]
// 0062f13a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0062f140  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0062f143  5f                   pop edi
// 0062f144  5e                   pop esi
// 0062f145  c20400               ret 4

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

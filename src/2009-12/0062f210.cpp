// from server: 100% by nuck16
// roc 2009-12 0062f210  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 88 bytes
//
// 0062f210  8b442404             mov eax, dword ptr [esp + 4]
// 0062f214  56                   push esi
// 0062f215  57                   push edi
// 0062f216  50                   push eax
// 0062f217  8bf1                 mov esi, ecx
// 0062f219  e8c2f5ffff           call 0x62e7e0
// 0062f21e  8b38                 mov edi, dword ptr [eax]
// 0062f220  83c404               add esp, 4
// 0062f223  85ff                 test edi, edi
// 0062f225  7d07                 jge 0x62f22e
// 0062f227  5f                   pop edi
// 0062f228  33c0                 xor eax, eax
// 0062f22a  5e                   pop esi
// 0062f22b  c20400               ret 4
// 0062f22e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0062f234  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0062f23a  c1f902               sar ecx, 2
// 0062f23d  3bf9                 cmp edi, ecx
// 0062f23f  73e6                 jae 0x62f227
// 0062f241  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0062f247  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0062f24d  c1fa02               sar edx, 2
// 0062f250  3bfa                 cmp edi, edx
// 0062f252  7206                 jb 0x62f25a
// 0062f254  ff1560b79800         call dword ptr [0x98b760]
// 0062f25a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0062f260  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0062f263  5f                   pop edi
// 0062f264  5e                   pop esi
// 0062f265  c20400               ret 4

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

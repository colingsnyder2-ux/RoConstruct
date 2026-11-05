// from server: 100% by nuck16
// roc 2009-12 00652ac0  unit: RBX::ExtrudedPartInstance::W4VisualTrussStyle::?$EnumDesc  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00652ac0
//
// 00652ac0  8b442404             mov eax, dword ptr [esp + 4]
// 00652ac4  56                   push esi
// 00652ac5  57                   push edi
// 00652ac6  50                   push eax
// 00652ac7  8bf1                 mov esi, ecx
// 00652ac9  e802abffff           call 0x64d5d0
// 00652ace  8b38                 mov edi, dword ptr [eax]
// 00652ad0  83c404               add esp, 4
// 00652ad3  85ff                 test edi, edi
// 00652ad5  7d07                 jge 0x652ade
// 00652ad7  5f                   pop edi
// 00652ad8  33c0                 xor eax, eax
// 00652ada  5e                   pop esi
// 00652adb  c20400               ret 4
// 00652ade  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652ae4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652aea  c1f902               sar ecx, 2
// 00652aed  3bf9                 cmp edi, ecx
// 00652aef  73e6                 jae 0x652ad7
// 00652af1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652af7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652afd  c1fa02               sar edx, 2
// 00652b00  3bfa                 cmp edi, edx
// 00652b02  7206                 jb 0x652b0a
// 00652b04  ff1560b79800         call dword ptr [0x98b760]
// 00652b0a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652b10  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652b13  5f                   pop edi
// 00652b14  5e                   pop esi
// 00652b15  c20400               ret 4

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

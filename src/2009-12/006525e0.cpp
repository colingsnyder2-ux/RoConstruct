// from server: 100% by nuck16
// roc 2009-12 006525e0  unit: RBX::GuiText::W4YAlignment::?$EnumDesc  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006525e0
//
// 006525e0  8b442404             mov eax, dword ptr [esp + 4]
// 006525e4  56                   push esi
// 006525e5  57                   push edi
// 006525e6  50                   push eax
// 006525e7  8bf1                 mov esi, ecx
// 006525e9  e88287ffff           call 0x64ad70
// 006525ee  8b38                 mov edi, dword ptr [eax]
// 006525f0  83c404               add esp, 4
// 006525f3  85ff                 test edi, edi
// 006525f5  7d07                 jge 0x6525fe
// 006525f7  5f                   pop edi
// 006525f8  33c0                 xor eax, eax
// 006525fa  5e                   pop esi
// 006525fb  c20400               ret 4
// 006525fe  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652604  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065260a  c1f902               sar ecx, 2
// 0065260d  3bf9                 cmp edi, ecx
// 0065260f  73e6                 jae 0x6525f7
// 00652611  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652617  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065261d  c1fa02               sar edx, 2
// 00652620  3bfa                 cmp edi, edx
// 00652622  7206                 jb 0x65262a
// 00652624  ff1560b79800         call dword ptr [0x98b760]
// 0065262a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652630  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652633  5f                   pop edi
// 00652634  5e                   pop esi
// 00652635  c20400               ret 4

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

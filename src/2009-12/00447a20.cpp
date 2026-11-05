// from server: 100% by nuck16
// roc 2009-12 00447a20  unit: RBX::CRenderSettings::W4FrameRateManagerMode::?$EnumDesc  size: 88 bytes
//
// 00447a20  8b442404             mov eax, dword ptr [esp + 4]
// 00447a24  56                   push esi
// 00447a25  57                   push edi
// 00447a26  50                   push eax
// 00447a27  8bf1                 mov esi, ecx
// 00447a29  e882f8ffff           call 0x4472b0
// 00447a2e  8b38                 mov edi, dword ptr [eax]
// 00447a30  83c404               add esp, 4
// 00447a33  85ff                 test edi, edi
// 00447a35  7d07                 jge 0x447a3e
// 00447a37  5f                   pop edi
// 00447a38  33c0                 xor eax, eax
// 00447a3a  5e                   pop esi
// 00447a3b  c20400               ret 4
// 00447a3e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447a44  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00447a4a  c1f902               sar ecx, 2
// 00447a4d  3bf9                 cmp edi, ecx
// 00447a4f  73e6                 jae 0x447a37
// 00447a51  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447a57  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00447a5d  c1fa02               sar edx, 2
// 00447a60  3bfa                 cmp edi, edx
// 00447a62  7206                 jb 0x447a6a
// 00447a64  ff1560b79800         call dword ptr [0x98b760]
// 00447a6a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447a70  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447a73  5f                   pop edi
// 00447a74  5e                   pop esi
// 00447a75  c20400               ret 4

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

// from server: 100% by EspClaude
// from server: 55% by colin
// roc 2007-08 0055f580  unit: RBX::ClearBackpack  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f580
//
// 0055f580  83ec08               sub esp, 8
// 0055f583  53                   push ebx
// 0055f584  8b99fc000000         mov ebx, dword ptr [ecx + 0xfc]
// 0055f58a  3999f8000000         cmp dword ptr [ecx + 0xf8], ebx
// 0055f590  55                   push ebp
// 0055f591  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 0055f597  56                   push esi
// 0055f598  57                   push edi
// 0055f599  8db9f4000000         lea edi, [ecx + 0xf4]
// 0055f59f  7602                 jbe 0x55f5a3
// 0055f5a1  ffd5                 call ebp
// 0055f5a3  8b7704               mov esi, dword ptr [edi + 4]
// 0055f5a6  3b7708               cmp esi, dword ptr [edi + 8]
// 0055f5a9  7602                 jbe 0x55f5ad
// 0055f5ab  ffd5                 call ebp
// 0055f5ad  3bf3                 cmp esi, ebx
// 0055f5af  89742414             mov dword ptr [esp + 0x14], esi
// 0055f5b3  741c                 je 0x55f5d1
// 0055f5b5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055f5b9  8da42400000000       lea esp, [esp]
// 0055f5c0  8b0e                 mov ecx, dword ptr [esi]
// 0055f5c2  39814c010000         cmp dword ptr [ecx + 0x14c], eax
// 0055f5c8  7507                 jne 0x55f5d1
// 0055f5ca  83c604               add esi, 4
// 0055f5cd  3bf3                 cmp esi, ebx
// 0055f5cf  75ef                 jne 0x55f5c0
// 0055f5d1  8b5f08               mov ebx, dword ptr [edi + 8]
// 0055f5d4  395f04               cmp dword ptr [edi + 4], ebx
// 0055f5d7  7602                 jbe 0x55f5db
// 0055f5d9  ffd5                 call ebp
// 0055f5db  85ff                 test edi, edi
// 0055f5dd  7404                 je 0x55f5e3
// 0055f5df  3bff                 cmp edi, edi
// 0055f5e1  7402                 je 0x55f5e5
// 0055f5e3  ffd5                 call ebp
// 0055f5e5  3bf3                 cmp esi, ebx
// 0055f5e7  7419                 je 0x55f602
// 0055f5e9  85ff                 test edi, edi
// 0055f5eb  7502                 jne 0x55f5ef
// 0055f5ed  ffd5                 call ebp
// 0055f5ef  3b7708               cmp esi, dword ptr [edi + 8]
// 0055f5f2  7202                 jb 0x55f5f6
// 0055f5f4  ffd5                 call ebp
// 0055f5f6  8b06                 mov eax, dword ptr [esi]
// 0055f5f8  5f                   pop edi
// 0055f5f9  5e                   pop esi
// 0055f5fa  5d                   pop ebp
// 0055f5fb  5b                   pop ebx
// 0055f5fc  83c408               add esp, 8
// 0055f5ff  c20400               ret 4
// 0055f602  5f                   pop edi
// 0055f603  5e                   pop esi
// 0055f604  5d                   pop ebp
// 0055f605  33c0                 xor eax, eax
// 0055f607  5b                   pop ebx

#include <vector>
#include <algorithm>

struct Item {
    char pad[0x14c];
    int value;
};

struct DiffersFrom {
    int v;
    DiffersFrom(int v_) : v(v_) {}
    bool operator()(Item* p) const { return p->value != v; }
};

struct ClearBackpack {
    char pad[0xf4];
    std::vector<Item*> items;
    Item* find(int arg);
};

Item* ClearBackpack::find(int arg)
{
    std::vector<Item*>::iterator it = std::find_if(items.begin(), items.end(), DiffersFrom(arg));
    if (it != items.end())
        return *it;
    return 0;
}

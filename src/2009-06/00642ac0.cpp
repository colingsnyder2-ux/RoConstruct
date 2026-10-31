// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b6120  unit: RBX::VHat::?$FactoryProduct  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6120
//
// 005b6120  83ec08               sub esp, 8
// 005b6123  56                   push esi
// 005b6124  57                   push edi
// 005b6125  51                   push ecx
// 005b6126  8d44240c             lea eax, [esp + 0xc]
// 005b612a  50                   push eax
// 005b612b  e8f0faffff           call 0x5b5c20
// 005b6130  8bc8                 mov ecx, eax
// 005b6132  83c130               add ecx, 0x30
// 005b6135  e856d8ffff           call 0x5b3990
// 005b613a  8b3d90288000         mov edi, dword ptr [0x802890]
// 005b6140  8bf0                 mov esi, eax
// 005b6142  8b06                 mov eax, dword ptr [esi]
// 005b6144  85c0                 test eax, eax
// 005b6146  7508                 jne 0x5b6150
// 005b6148  ffd7                 call edi
// 005b614a  8b06                 mov eax, dword ptr [esi]
// 005b614c  85c0                 test eax, eax
// 005b614e  7404                 je 0x5b6154
// 005b6150  8b00                 mov eax, dword ptr [eax]
// 005b6152  eb02                 jmp 0x5b6156
// 005b6154  33c0                 xor eax, eax
// 005b6156  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b6159  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 005b615c  7502                 jne 0x5b6160
// 005b615e  ffd7                 call edi
// 005b6160  8b5604               mov edx, dword ptr [esi + 4]
// 005b6163  8b4a10               mov ecx, dword ptr [edx + 0x10]
// 005b6166  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b616a  5f                   pop edi
// 005b616b  8908                 mov dword ptr [eax], ecx
// 005b616d  5e                   pop esi
// 005b616e  83c408               add esp, 8
// 005b6171  c20400               ret 4

struct S;
struct Node;

struct Tree {
    char padding[0x18];
    Node* end;
};

struct Node {
    char padding[0x10];
    void* value;
};

struct Iterator {
    Tree** owner;
    Node* node;
};

struct Map {
    Iterator* find(Iterator* result, const S* key);
};

struct Registry {
    char padding[0x30];
    Map map;
};

extern Registry* __cdecl getRegistry();
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct S {
    void** f(void** result);
};

void** S::f(void** result)
{
    Iterator storage;
    Iterator* it = getRegistry()->map.find(&storage, this);

    void (__cdecl* invalid)() = invalid_parameter_noinfo;
    if (!it->owner)
        invalid();

    Tree* tree = it->owner ? *it->owner : 0;
    if (it->node == tree->end)
        invalid();

    *result = it->node->value;
    return result;
}

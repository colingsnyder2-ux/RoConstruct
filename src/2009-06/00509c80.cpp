// from server: 77% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004cbea0  unit: RBX::VInstance::?$NonFactoryProduct  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cbea0
//
// 004cbea0  83ec08               sub esp, 8
// 004cbea3  56                   push esi
// 004cbea4  57                   push edi
// 004cbea5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004cbea9  c644240800           mov byte ptr [esp + 8], 0
// 004cbeae  8b442408             mov eax, dword ptr [esp + 8]
// 004cbeb2  8bf1                 mov esi, ecx
// 004cbeb4  50                   push eax
// 004cbeb5  8d4c240c             lea ecx, [esp + 0xc]
// 004cbeb9  51                   push ecx
// 004cbeba  8d5708               lea edx, [edi + 8]
// 004cbebd  52                   push edx
// 004cbebe  8bce                 mov ecx, esi
// 004cbec0  e83bf3ffff           call 0x4cb200
// 004cbec5  84c0                 test al, al
// 004cbec7  751d                 jne 0x4cbee6
// 004cbec9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cbecd  85c0                 test eax, eax
// 004cbecf  740b                 je 0x4cbedc
// 004cbed1  5f                   pop edi
// 004cbed2  83c0a0               add eax, -0x60
// 004cbed5  5e                   pop esi
// 004cbed6  83c408               add esp, 8
// 004cbed9  c20800               ret 8
// 004cbedc  5f                   pop edi
// 004cbedd  33c0                 xor eax, eax
// 004cbedf  5e                   pop esi
// 004cbee0  83c408               add esp, 8
// 004cbee3  c20800               ret 8
// 004cbee6  53                   push ebx
// 004cbee7  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004cbeeb  53                   push ebx
// 004cbeec  57                   push edi
// 004cbeed  8bce                 mov ecx, esi
// 004cbeef  e8bcf8ffff           call 0x4cb7b0
// 004cbef4  8bf8                 mov edi, eax
// 004cbef6  3bfb                 cmp edi, ebx
// 004cbef8  7538                 jne 0x4cbf32
// 004cbefa  85f6                 test esi, esi
// 004cbefc  7405                 je 0x4cbf03
// 004cbefe  8d46f4               lea eax, [esi - 0xc]
// 004cbf01  eb02                 jmp 0x4cbf05
// 004cbf03  33c0                 xor eax, eax
// 004cbf05  8b4004               mov eax, dword ptr [eax + 4]
// 004cbf08  85c0                 test eax, eax
// 004cbf0a  7405                 je 0x4cbf11
// 004cbf0c  8d4860               lea ecx, [eax + 0x60]
// 004cbf0f  eb02                 jmp 0x4cbf13
// 004cbf11  33c9                 xor ecx, ecx
// 004cbf13  85db                 test ebx, ebx
// 004cbf15  7405                 je 0x4cbf1c
// 004cbf17  8d4360               lea eax, [ebx + 0x60]
// 004cbf1a  eb02                 jmp 0x4cbf1e
// 004cbf1c  33c0                 xor eax, eax
// 004cbf1e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004cbf22  51                   push ecx
// 004cbf23  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cbf27  51                   push ecx
// 004cbf28  52                   push edx
// 004cbf29  50                   push eax
// 004cbf2a  e851aaffff           call 0x4c6980
// 004cbf2f  83c410               add esp, 0x10
// 004cbf32  5b                   pop ebx
// 004cbf33  8bc7                 mov eax, edi
// 004cbf35  5f                   pop edi
// 004cbf36  5e                   pop esi
// 004cbf37  83c408               add esp, 8
// 004cbf3a  c20800               ret 8

struct Link {
    unsigned int tagged;
    Link* left;
    Link* right;
};

struct Tag {
    bool value;
};

struct Position {
    Tag tag;
    Link* link;
};

struct Node {
    char padding0[8];
    double key;
    char padding1[80];
    Link link;
};

struct Context {
    long reserved;
    Node* object;
};

extern "C" void __cdecl attach(Link*, Position, Link*);

struct S {
    bool find(double*, Position*, Tag);
    Node* insert(Node*, Node*);
    Node* f(Node*, Node*);
};

Node* S::f(Node* source, Node* candidate)
{
    Position position;
    position.tag.value = false;

    if (!find(&source->key, &position, position.tag))
        return position.link
            ? reinterpret_cast<Node*>(
                reinterpret_cast<char*>(position.link) - 0x60)
            : 0;

    Node* result = insert(source, candidate);
    if (result == candidate) {
        Node* parent = (this
            ? reinterpret_cast<Context*>(
                reinterpret_cast<char*>(this) - 12)
            : 0)->object;

        attach(candidate ? &candidate->link : 0,
               position,
               parent ? &parent->link : 0);
    }
    return result;
}

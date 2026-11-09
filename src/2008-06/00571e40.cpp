// from server: 56% by king_originala
// roc 2008-06 00571e40  unit: RBX::Reflection::ClassDescriptor  size: 230 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00571e40
//
// 00571e40  8964244c             mov dword ptr [esp + 0x4c], esp
// 00571e44  52                   push edx
// 00571e45  e8c6eeffff           call 0x570d10
// 00571e4a  8bcb                 mov ecx, ebx
// 00571e4c  e84ff0ffff           call 0x570ea0
// 00571e51  84c0                 test al, al
// 00571e53  0f84a6000000         je 0x571eff
// 00571e59  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00571e5d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00571e61  8b5640               mov edx, dword ptr [esi + 0x40]
// 00571e64  89442410             mov dword ptr [esp + 0x10], eax
// 00571e68  8b06                 mov eax, dword ptr [esi]
// 00571e6a  894c2414             mov dword ptr [esp + 0x14], ecx
// 00571e6e  8d4c2410             lea ecx, [esp + 0x10]
// 00571e72  8954241c             mov dword ptr [esp + 0x1c], edx
// 00571e76  89442418             mov dword ptr [esp + 0x18], eax
// 00571e7a  e8e180e9ff           call 0x409f60
// 00571e7f  8d4c2418             lea ecx, [esp + 0x18]
// 00571e83  51                   push ecx
// 00571e84  8d4c2414             lea ecx, [esp + 0x14]
// 00571e88  e813ae0700           call 0x5ecca0
// 00571e8d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00571e91  84c0                 test al, al
// 00571e93  752c                 jne 0x571ec1
// 00571e95  83ec0c               sub esp, 0xc
// 00571e98  8d550c               lea edx, [ebp + 0xc]
// 00571e9b  8bcc                 mov ecx, esp
// 00571e9d  89642440             mov dword ptr [esp + 0x40], esp
// 00571ea1  52                   push edx
// 00571ea2  e869eeffff           call 0x570d10
// 00571ea7  83ec0c               sub esp, 0xc
// 00571eaa  8bcc                 mov ecx, esp
// 00571eac  8964244c             mov dword ptr [esp + 0x4c], esp
// 00571eb0  57                   push edi
// 00571eb1  e85aeeffff           call 0x570d10
// 00571eb6  8bcb                 mov ecx, ebx
// 00571eb8  e8e3efffff           call 0x570ea0
// 00571ebd  84c0                 test al, al
// 00571ebf  743e                 je 0x571eff
// 00571ec1  8b442430             mov eax, dword ptr [esp + 0x30]
// 00571ec5  8b4808               mov ecx, dword ptr [eax + 8]
// 00571ec8  80793500             cmp byte ptr [ecx + 0x35], 0
// 00571ecc  57                   push edi
// 00571ecd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00571ed1  8bce                 mov ecx, esi
// 00571ed3  7415                 je 0x571eea
// 00571ed5  50                   push eax
// 00571ed6  6a00                 push 0
// 00571ed8  57                   push edi
// 00571ed9  e892f9ffff           call 0x571870
// 00571ede  8bc7                 mov eax, edi
// 00571ee0  5f                   pop edi
// 00571ee1  5e                   pop esi
// 00571ee2  5d                   pop ebp
// 00571ee3  5b                   pop ebx
// 00571ee4  83c414               add esp, 0x14
// 00571ee7  c21000               ret 0x10
// 00571eea  55                   push ebp
// 00571eeb  6a01                 push 1
// 00571eed  57                   push edi
// 00571eee  e87df9ffff           call 0x571870
// 00571ef3  8bc7                 mov eax, edi
// 00571ef5  5f                   pop edi
// 00571ef6  5e                   pop esi
// 00571ef7  5d                   pop ebp
// 00571ef8  5b                   pop ebx
// 00571ef9  83c414               add esp, 0x14
// 00571efc  c21000               ret 0x10
// 00571eff  57                   push edi
// 00571f00  8d54241c             lea edx, [esp + 0x1c]
// 00571f04  52                   push edx
// 00571f05  8bce                 mov ecx, esi
// 00571f07  e864fbffff           call 0x571a70
// 00571f0c  8b10                 mov edx, dword ptr [eax]
// 00571f0e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00571f12  5f                   pop edi
// 00571f13  5e                   pop esi
// 00571f14  8911                 mov dword ptr [ecx], edx
// 00571f16  8b4004               mov eax, dword ptr [eax + 4]
// 00571f19  5d                   pop ebp
// 00571f1a  894104               mov dword ptr [ecx + 4], eax
// 00571f1d  8bc1                 mov eax, ecx
// 00571f1f  5b                   pop ebx
// 00571f20  83c414               add esp, 0x14
// 00571f23  c21000               ret 0x10

struct Key {
    unsigned long data[3];
    Key(const Key&);
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    unsigned char padding[29];
    unsigned char nil;
};

struct Iterator {
    void* owner;
    Node* node;

    void previous();
    bool equal(const Iterator&) const;
};

struct Compare {
    unsigned char storage[36];
    bool operator()(Key, Key) const;
};

struct InsertResult {
    Iterator position;
    bool inserted;
};

struct Tree {
    void* owner;
    Compare compare;
    Node* head;

    Iterator* insertAt(Iterator*, int, Node*, const Key&);
    InsertResult* insertOrdinary(InsertResult*, const Key&);
    Iterator* insertHint(Iterator*, Iterator, const Key&);
};

Iterator* Tree::insertHint(Iterator* result, Iterator hint, const Key& key)
{
    if (compare(key, *reinterpret_cast<const Key*>(
                         reinterpret_cast<const char*>(hint.node) + 12))) {
        Iterator previous = hint;
        Iterator end;
        end.owner = owner;
        end.node = head;
        previous.previous();

        bool atEnd = previous.equal(end);
        Node* node = previous.node;

        if (atEnd ||
            compare(key, *reinterpret_cast<const Key*>(
                             reinterpret_cast<const char*>(node) + 12))) {
            if (hint.node->right->nil)
                insertAt(result, 0, hint.node, key);
            else
                insertAt(result, 1, node, key);
            return result;
        }
    }

    InsertResult temporary;
    InsertResult* inserted = insertOrdinary(&temporary, key);
    *result = inserted->position;
    return result;
}

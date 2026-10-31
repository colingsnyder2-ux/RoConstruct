// from server: 77% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004cb7b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cb7b0
//
// 004cb7b0  83ec08               sub esp, 8
// 004cb7b3  56                   push esi
// 004cb7b4  57                   push edi
// 004cb7b5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004cb7b9  8b5744               mov edx, dword ptr [edi + 0x44]
// 004cb7bc  c644240800           mov byte ptr [esp + 8], 0
// 004cb7c1  8b442408             mov eax, dword ptr [esp + 8]
// 004cb7c5  8bf1                 mov esi, ecx
// 004cb7c7  50                   push eax
// 004cb7c8  8d4c240c             lea ecx, [esp + 0xc]
// 004cb7cc  51                   push ecx
// 004cb7cd  52                   push edx
// 004cb7ce  8bce                 mov ecx, esi
// 004cb7d0  e8abfaffff           call 0x4cb280
// 004cb7d5  84c0                 test al, al
// 004cb7d7  751d                 jne 0x4cb7f6
// 004cb7d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cb7dd  85c0                 test eax, eax
// 004cb7df  740b                 je 0x4cb7ec
// 004cb7e1  5f                   pop edi
// 004cb7e2  83c0b0               add eax, -0x50
// 004cb7e5  5e                   pop esi
// 004cb7e6  83c408               add esp, 8
// 004cb7e9  c20800               ret 8
// 004cb7ec  5f                   pop edi
// 004cb7ed  33c0                 xor eax, eax
// 004cb7ef  5e                   pop esi
// 004cb7f0  83c408               add esp, 8
// 004cb7f3  c20800               ret 8
// 004cb7f6  53                   push ebx
// 004cb7f7  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004cb7fb  53                   push ebx
// 004cb7fc  57                   push edi
// 004cb7fd  8bce                 mov ecx, esi
// 004cb7ff  e80cf8ffff           call 0x4cb010
// 004cb804  8bf8                 mov edi, eax
// 004cb806  3bfb                 cmp edi, ebx
// 004cb808  7538                 jne 0x4cb842
// 004cb80a  85f6                 test esi, esi
// 004cb80c  7405                 je 0x4cb813
// 004cb80e  8d46f4               lea eax, [esi - 0xc]
// 004cb811  eb02                 jmp 0x4cb815
// 004cb813  33c0                 xor eax, eax
// 004cb815  8b4004               mov eax, dword ptr [eax + 4]
// 004cb818  85c0                 test eax, eax
// 004cb81a  7405                 je 0x4cb821
// 004cb81c  8d4850               lea ecx, [eax + 0x50]
// 004cb81f  eb02                 jmp 0x4cb823
// 004cb821  33c9                 xor ecx, ecx
// 004cb823  85db                 test ebx, ebx
// 004cb825  7405                 je 0x4cb82c
// 004cb827  8d4350               lea eax, [ebx + 0x50]
// 004cb82a  eb02                 jmp 0x4cb82e
// 004cb82c  33c0                 xor eax, eax
// 004cb82e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004cb832  51                   push ecx
// 004cb833  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cb837  51                   push ecx
// 004cb838  52                   push edx
// 004cb839  50                   push eax
// 004cb83a  e841b1ffff           call 0x4c6980
// 004cb83f  83c410               add esp, 0x10
// 004cb842  5b                   pop ebx
// 004cb843  8bc7                 mov eax, edi
// 004cb845  5f                   pop edi
// 004cb846  5e                   pop esi
// 004cb847  83c408               add esp, 8
// 004cb84a  c20800               ret 8

struct Link;

struct Tag {
    bool value;
};

struct Position {
    Tag tag;
    Link *link;
};

struct Object {
    char reserved[0x44];
    void *key;
};

struct Product;

extern "C" void __cdecl insert(Link *node, Position position, Link *owner);

struct Factory {
    bool find(void *key, Position *position, Tag tag);
    Product *construct(void *argument, void *storage);
    Product *create(Object *argument, Product *storage);
};

Product *Factory::create(Object *argument, Product *storage)
{
    Position position;
    position.tag.value = false;

    if (!find(argument->key, &position, position.tag)) {
        if (position.link)
            return reinterpret_cast<Product *>(
                reinterpret_cast<char *>(position.link) - 0x50);
        return 0;
    }

    Product *result = construct(argument, storage);
    if (result == storage) {
        char *base = this ? reinterpret_cast<char *>(this) - 0x0C : 0;
        Product *owner = *reinterpret_cast<Product **>(base + 4);
        Link *ownerLink = owner
            ? reinterpret_cast<Link *>(reinterpret_cast<char *>(owner) + 0x50)
            : 0;
        Link *storageLink = storage
            ? reinterpret_cast<Link *>(reinterpret_cast<char *>(storage) + 0x50)
            : 0;
        insert(storageLink, position, ownerLink);
    }

    return result;
}

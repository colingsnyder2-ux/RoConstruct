// from server: 100% by Espeon
// from server: 98% by colin
// roc 2008-06 005e3a80  unit: RBX::JointInstance  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e3a80
//
// 005e3a80  8b442404             mov eax, dword ptr [esp + 4]
// 005e3a84  53                   push ebx
// 005e3a85  56                   push esi
// 005e3a86  57                   push edi
// 005e3a87  50                   push eax
// 005e3a88  8bf9                 mov edi, ecx
// 005e3a8a  e83172f7ff           call 0x55acc0
// 005e3a8f  8bb750010000         mov esi, dword ptr [edi + 0x150]
// 005e3a95  837e0400             cmp dword ptr [esi + 4], 0
// 005e3a99  7504                 jne 0x5e3a9f
// 005e3a9b  33db                 xor ebx, ebx
// 005e3a9d  eb1d                 jmp 0x5e3abc
// 005e3a9f  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e3aa2  8b11                 mov edx, dword ptr [ecx]
// 005e3aa4  8b4204               mov eax, dword ptr [edx + 4]
// 005e3aa7  ffd0                 call eax
// 005e3aa9  83f807               cmp eax, 7
// 005e3aac  7405                 je 0x5e3ab3
// 005e3aae  8b7604               mov esi, dword ptr [esi + 4]
// 005e3ab1  eb06                 jmp 0x5e3ab9
// 005e3ab3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e3ab6  8b7104               mov esi, dword ptr [ecx + 4]
// 005e3ab9  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005e3abc  8b8704010000         mov eax, dword ptr [edi + 0x104]
// 005e3ac2  85c0                 test eax, eax
// 005e3ac4  742d                 je 0x5e3af3
// 005e3ac6  8b701c               mov esi, dword ptr [eax + 0x1c]
// 005e3ac9  e8b272e2ff           call 0x40ad80
// 005e3ace  50                   push eax
// 005e3acf  8bce                 mov ecx, esi
// 005e3ad1  e83ac3f8ff           call 0x56fe10
// 005e3ad6  84c0                 test al, al
// 005e3ad8  7419                 je 0x5e3af3
// 005e3ada  57                   push edi
// 005e3adb  e870e3eaff           call 0x491e50
// 005e3ae0  83c404               add esp, 4
// 005e3ae3  85c0                 test eax, eax
// 005e3ae5  7408                 je 0x5e3aef
// 005e3ae7  8bb0e4020000         mov esi, dword ptr [eax + 0x2e4]
// 005e3aed  eb0f                 jmp 0x5e3afe
// 005e3aef  33f6                 xor esi, esi
// 005e3af1  eb0b                 jmp 0x5e3afe
// 005e3af3  57                   push edi
// 005e3af4  e897f8fbff           call 0x5a3390
// 005e3af9  83c404               add esp, 4
// 005e3afc  8bf0                 mov esi, eax
// 005e3afe  3bde                 cmp ebx, esi
// 005e3b00  7424                 je 0x5e3b26
// 005e3b02  85db                 test ebx, ebx
// 005e3b04  740e                 je 0x5e3b14
// 005e3b06  8b9750010000         mov edx, dword ptr [edi + 0x150]
// 005e3b0c  52                   push edx
// 005e3b0d  8bcb                 mov ecx, ebx
// 005e3b0f  e88c680000           call 0x5ea3a0
// 005e3b14  85f6                 test esi, esi
// 005e3b16  740e                 je 0x5e3b26
// 005e3b18  8b8750010000         mov eax, dword ptr [edi + 0x150]
// 005e3b1e  50                   push eax
// 005e3b1f  8bce                 mov ecx, esi
// 005e3b21  e8fa670000           call 0x5ea320
// 005e3b26  5f                   pop edi
// 005e3b27  5e                   pop esi
// 005e3b28  5b                   pop ebx
// 005e3b29  c20400               ret 4

struct Node;
struct Joint;
struct World;

struct Category {
    bool equals(const Category& other) const;
};

extern const Category& __cdecl categoryInstance();

struct Parent {
    char pad0[0x1c];
    Category* category;
};

struct Node {
    virtual void reserved();
    virtual int kind();
    Node* link;
    char pad0[4];
    World* world;
};

struct World {
    void detach(Node* node);
    void attach(Node* node);
};

struct Provider {
    char pad0[0x2e4];
    World* world;
};

struct Joint {
    char pad[0x104];
    Parent* parent;
    char pad1[0x48];
    Node* node;
    void update(void* argument);
    void f(void* argument);
};

extern Provider* __cdecl findProvider(Joint* joint);
extern World* __cdecl findWorld(Joint* joint);

inline bool categoryMatches(Category* category) { return category->equals(categoryInstance()); }

void Joint::f(void* argument)
{
    update(argument);

    Node* n = node;
    World* oldWorld;
    if (!n->link) {
        oldWorld = 0;
    } else {
        if (n->link->kind() != 7)
            n = n->link;
        else
            n = n->link->link;
        oldWorld = n->world;
    }

    World* newWorld;
    Parent* p = parent;
    if (p && categoryMatches(p->category)) {
        Provider* provider = findProvider(this);
        newWorld = provider ? provider->world : 0;
    } else {
        newWorld = findWorld(this);
    }

    if (oldWorld != newWorld) {
        if (oldWorld)
            oldWorld->detach(node);
        if (newWorld)
            newWorld->attach(node);
    }
}

// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 008f6a80  unit: RBX::Scale9Frame  size: 177 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008f6a80
//
// 008f6a80  64a100000000         mov eax, dword ptr fs:[0]
// 008f6a86  6aff                 push -1
// 008f6a88  6890c9aa00           push 0xaac990
// 008f6a8d  50                   push eax
// 008f6a8e  64892500000000       mov dword ptr fs:[0], esp
// 008f6a95  56                   push esi
// 008f6a96  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 008f6a9e  8d711c               lea esi, [ecx + 0x1c]
// 008f6aa1  e8fa27e1ff           call 0x7092a0
// 008f6aa6  8906                 mov dword ptr [esi], eax
// 008f6aa8  e823a9dcff           call 0x6c13d0
// 008f6aad  8d4c2418             lea ecx, [esp + 0x18]
// 008f6ab1  51                   push ecx
// 008f6ab2  50                   push eax
// 008f6ab3  8d54241c             lea edx, [esp + 0x1c]
// 008f6ab7  52                   push edx
// 008f6ab8  e82388d8ff           call 0x67f2e0
// 008f6abd  83c404               add esp, 4
// 008f6ac0  50                   push eax
// 008f6ac1  8bce                 mov ecx, esi
// 008f6ac3  e8b829e1ff           call 0x709480
// 008f6ac8  e803a9dcff           call 0x6c13d0
// 008f6acd  8d4c2460             lea ecx, [esp + 0x60]
// 008f6ad1  51                   push ecx
// 008f6ad2  50                   push eax
// 008f6ad3  8d542464             lea edx, [esp + 0x64]
// 008f6ad7  52                   push edx
// 008f6ad8  e80388d8ff           call 0x67f2e0
// 008f6add  83c404               add esp, 4
// 008f6ae0  50                   push eax
// 008f6ae1  8bce                 mov ecx, esi
// 008f6ae3  e89829e1ff           call 0x709480
// 008f6ae8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f6aec  c644240c00           mov byte ptr [esp + 0xc], 0
// 008f6af1  85c0                 test eax, eax
// 008f6af3  740d                 je 0x8f6b02
// 008f6af5  8b5004               mov edx, dword ptr [eax + 4]
// 008f6af8  8d4c2420             lea ecx, [esp + 0x20]
// 008f6afc  51                   push ecx
// 008f6afd  ffd2                 call edx
// 008f6aff  83c404               add esp, 4
// 008f6b02  8b442464             mov eax, dword ptr [esp + 0x64]
// 008f6b06  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 008f6b0e  85c0                 test eax, eax
// 008f6b10  740d                 je 0x8f6b1f
// 008f6b12  8b5004               mov edx, dword ptr [eax + 4]
// 008f6b15  8d4c2468             lea ecx, [esp + 0x68]
// 008f6b19  51                   push ecx
// 008f6b1a  ffd2                 call edx
// 008f6b1c  83c404               add esp, 4
// 008f6b1f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008f6b23  64890d00000000       mov dword ptr fs:[0], ecx
// 008f6b2a  5e                   pop esi
// 008f6b2b  83c40c               add esp, 0xc
// 008f6b2e  c29000               ret 0x90

struct Manager
{
    int pad0;
    void (*destroy)(void*);
};

struct Functor
{
    int head;
    char tag[4];
    Manager* manager;
    char buffer[0x3c];

    ~Functor()
    {
        if (manager)
            manager->destroy(buffer);
    }
};

struct Container
{
    void* node;
    void insert(void* key, void* where, void* value);
};

extern void* buyNode();
extern void* endNode();
extern void* keyOf(Functor* item);

struct Scale9FrameData
{
    char pad0[0x1c];
    Container items;

    void init(Functor first, Functor second);
};

void Scale9FrameData::init(Functor first, Functor second)
{
    items.node = buyNode();
    void* where = endNode();
    items.insert(keyOf(&first), where, first.tag);
    where = endNode();
    items.insert(keyOf(&second), where, second.tag);
}

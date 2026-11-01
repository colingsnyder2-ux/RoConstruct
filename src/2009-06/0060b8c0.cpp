// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0057e140  unit: RBX::ClearBackpack  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057e140
//
// 0057e140  64a100000000         mov eax, dword ptr fs:[0]
// 0057e146  6aff                 push -1
// 0057e148  6818047c00           push 0x7c0418
// 0057e14d  50                   push eax
// 0057e14e  64892500000000       mov dword ptr fs:[0], esp
// 0057e155  56                   push esi
// 0057e156  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e15a  8b01                 mov eax, dword ptr [ecx]
// 0057e15c  8b5038               mov edx, dword ptr [eax + 0x38]
// 0057e15f  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0057e167  ffd2                 call edx
// 0057e169  85c0                 test eax, eax
// 0057e16b  7415                 je 0x57e182
// 0057e16d  8b542414             mov edx, dword ptr [esp + 0x14]
// 0057e171  8b4a08               mov ecx, dword ptr [edx + 8]
// 0057e174  85c9                 test ecx, ecx
// 0057e176  7505                 jne 0x57e17d
// 0057e178  894204               mov dword ptr [edx + 4], eax
// 0057e17b  eb02                 jmp 0x57e17f
// 0057e17d  8901                 mov dword ptr [ecx], eax
// 0057e17f  894208               mov dword ptr [edx + 8], eax
// 0057e182  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0057e186  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0057e18e  85f6                 test esi, esi
// 0057e190  742a                 je 0x57e1bc
// 0057e192  8d4604               lea eax, [esi + 4]
// 0057e195  83c9ff               or ecx, 0xffffffff
// 0057e198  f00fc108             lock xadd dword ptr [eax], ecx
// 0057e19c  751e                 jne 0x57e1bc
// 0057e19e  8b16                 mov edx, dword ptr [esi]
// 0057e1a0  8b4204               mov eax, dword ptr [edx + 4]
// 0057e1a3  8bce                 mov ecx, esi
// 0057e1a5  ffd0                 call eax
// 0057e1a7  8d4e08               lea ecx, [esi + 8]
// 0057e1aa  83caff               or edx, 0xffffffff
// 0057e1ad  f00fc111             lock xadd dword ptr [ecx], edx
// 0057e1b1  7509                 jne 0x57e1bc
// 0057e1b3  8b06                 mov eax, dword ptr [esi]
// 0057e1b5  8b5008               mov edx, dword ptr [eax + 8]
// 0057e1b8  8bce                 mov ecx, esi
// 0057e1ba  ffd2                 call edx
// 0057e1bc  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0057e1c0  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e1c7  5e                   pop esi
// 0057e1c8  83c40c               add esp, 0xc
// 0057e1cb  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Node {
    Node* next;
};

struct Object;

struct ObjectVTable {
    void* reserved[4];
    Node* (__thiscall* getNode)(Object*);
};

struct Object {
    ObjectVTable* vtable;
};

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct List {
    unsigned int reserved;
    Node* first;
    Node* last;
};

void __cdecl clearBackpack(List* list, Shared value)
{
    Node* node = value.object->vtable->getNode(value.object);
    if (node) {
        if (!list->last)
            list->first = node;
        else
            list->last->next = node;
        list->last = node;
    }
}

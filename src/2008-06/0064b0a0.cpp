// from server: 100% by coldek
// from server: 98% by Espeon
// roc 2008-06 0064b0a0  unit: RBX::SleepStage  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064b0a0
//
// 0064b0a0  83ec10               sub esp, 0x10
// 0064b0a3  53                   push ebx
// 0064b0a4  55                   push ebp
// 0064b0a5  56                   push esi
// 0064b0a6  8b742420             mov esi, dword ptr [esp + 0x20]
// 0064b0aa  837e0400             cmp dword ptr [esi + 4], 0
// 0064b0ae  57                   push edi
// 0064b0af  8bf9                 mov edi, ecx
// 0064b0b1  89742410             mov dword ptr [esp + 0x10], esi
// 0064b0b5  7420                 je 0x64b0d7
// 0064b0b7  8b07                 mov eax, dword ptr [edi]
// 0064b0b9  8b5004               mov edx, dword ptr [eax + 4]
// 0064b0bc  8b5e04               mov ebx, dword ptr [esi + 4]
// 0064b0bf  ffd2                 call edx
// 0064b0c1  8be8                 mov ebp, eax
// 0064b0c3  8b03                 mov eax, dword ptr [ebx]
// 0064b0c5  8b5004               mov edx, dword ptr [eax + 4]
// 0064b0c8  8bcb                 mov ecx, ebx
// 0064b0ca  ffd2                 call edx
// 0064b0cc  3bc5                 cmp eax, ebp
// 0064b0ce  7c07                 jl 0x64b0d7
// 0064b0d0  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064b0d3  8b18                 mov ebx, dword ptr [eax]
// 0064b0d5  eb02                 jmp 0x64b0d9
// 0064b0d7  33db                 xor ebx, ebx
// 0064b0d9  53                   push ebx
// 0064b0da  8bcf                 mov ecx, edi
// 0064b0dc  e86ff4ffff           call 0x64a550
// 0064b0e1  8d4c2410             lea ecx, [esp + 0x10]
// 0064b0e5  51                   push ecx
// 0064b0e6  8bc8                 mov ecx, eax
// 0064b0e8  8daf80010000         lea ebp, [edi + 0x180]
// 0064b0ee  e86deef9ff           call 0x5e9f60
// 0064b0f3  8d542410             lea edx, [esp + 0x10]
// 0064b0f7  52                   push edx
// 0064b0f8  8d442418             lea eax, [esp + 0x18]
// 0064b0fc  50                   push eax
// 0064b0fd  8bcd                 mov ecx, ebp
// 0064b0ff  e83cdbf9ff           call 0x5e8c40
// 0064b104  83fb04               cmp ebx, 4
// 0064b107  7405                 je 0x64b10e
// 0064b109  83fb05               cmp ebx, 5
// 0064b10c  751b                 jne 0x64b129
// 0064b10e  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0064b111  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 0064b114  8b82a0000000         mov eax, dword ptr [edx + 0xa0]
// 0064b11a  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0064b11d  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 0064b120  85c9                 test ecx, ecx
// 0064b122  7405                 je 0x64b129
// 0064b124  e8578dfcff           call 0x613e80
// 0064b129  8b4e04               mov ecx, dword ptr [esi + 4]
// 0064b12c  8b11                 mov edx, dword ptr [ecx]
// 0064b12e  8b4204               mov eax, dword ptr [edx + 4]
// 0064b131  ffd0                 call eax
// 0064b133  8b17                 mov edx, dword ptr [edi]
// 0064b135  8bd8                 mov ebx, eax
// 0064b137  8b4204               mov eax, dword ptr [edx + 4]
// 0064b13a  8bcf                 mov ecx, edi
// 0064b13c  ffd0                 call eax
// 0064b13e  3bd8                 cmp ebx, eax
// 0064b140  7e09                 jle 0x64b14b
// 0064b142  8b4f08               mov ecx, dword ptr [edi + 8]
// 0064b145  56                   push esi
// 0064b146  e855210000           call 0x64d2a0
// 0064b14b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0064b14e  c7410400000000       mov dword ptr [ecx + 4], 0
// 0064b155  8b5618               mov edx, dword ptr [esi + 0x18]
// 0064b158  6a00                 push 0
// 0064b15a  c70206000000         mov dword ptr [edx], 6
// 0064b160  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0064b163  56                   push esi
// 0064b164  e817eaf9ff           call 0x5e9b80
// 0064b169  8d442424             lea eax, [esp + 0x24]
// 0064b16d  50                   push eax
// 0064b16e  8bcd                 mov ecx, ebp
// 0064b170  e8ebedf9ff           call 0x5e9f60
// 0064b175  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0064b178  85db                 test ebx, ebx
// 0064b17a  7410                 je 0x64b18c
// 0064b17c  8bcb                 mov ecx, ebx
// 0064b17e  e88d22e3ff           call 0x47d410
// 0064b183  53                   push ebx
// 0064b184  e8f1540500           call 0x6a067a
// 0064b189  83c404               add esp, 4
// 0064b18c  6a00                 push 0
// 0064b18e  8bce                 mov ecx, esi
// 0064b190  e84baef9ff           call 0x5e5fe0
// 0064b195  57                   push edi
// 0064b196  8bce                 mov ecx, esi
// 0064b198  e8a3a6ffff           call 0x645840
// 0064b19d  5f                   pop edi
// 0064b19e  5e                   pop esi
// 0064b19f  5d                   pop ebp
// 0064b1a0  5b                   pop ebx
// 0064b1a1  83c410               add esp, 0x10
// 0064b1a4  c20400               ret 4


#include <intrin.h>

struct Stage;
struct Primitive;

struct State {
    int value;
    int auxiliary;
    void cleanup();
};

struct Action {
    void invoke();
};

struct Link3 {
    char padding[0x2c];
    Action* action;
};

struct Link2 {
    char padding[0x10];
    Link3* next;
};

struct Link1 {
    char padding[0xa0];
    Link2* next;
};

struct Link {
    char padding[0x1c];
    Link1* next;
};

struct Primitive {
    char padding0[4];
    Stage* owner;
    char padding1[0x10];
    State* state;
    char padding2[8];
    Link* link;

    bool inOrDownstream(Stage*) const;
    void setState(int value);
    void setOwner(Stage* owner);
};

struct InsertResult {
    char data[12];
};

struct Container {
    char data[1];
    void erase(Primitive* const* key);
    void insert(InsertResult* result, Primitive* const* key);
};

struct Manager {
    void remove(Primitive* primitive);
};

struct Collection {
    void remove(Primitive* primitive, int flag);
};

struct Stage {
    virtual void slot0();
    virtual int rank();

    int reserved;
    Manager* manager;
    Collection* collection;
    char padding[0x170];
    Container container;

    Container* select(int state);
    void f(Primitive* primitive);
};

extern "C" void __cdecl releaseMemory(void* memory);

inline bool Primitive::inOrDownstream(Stage*s)const {_ReadWriteBarrier();Stage* current=owner;int requested=s->rank();return current->rank() >= requested;}

void Stage::f(Primitive* volatile primitive)
{
    Primitive* p = primitive;
    Primitive* key;
    int state;

    if (p->owner) {
        key = p;
        if (p->inOrDownstream(this)) state = p->state->value;
        else state = 0;
    } else {
        key = p;
        state = 0;
    }

    Container* selected = select(state);
    Container* destination = &container;
    selected->erase(&key);

    InsertResult result;
    destination->insert(&result, &key);

    if (state == 4 || state == 5) {
        Action* action = p->link->next->next->next->action;
        if (action)
            action->invoke();
    }

    if (p->owner->rank() > rank())
        manager->remove(p);

    p->state->auxiliary = 0;
    p->state->value = 6;
    collection->remove(p, 0);
    destination->erase((Primitive* const*)&primitive);

    State* oldState = p->state;
    if (oldState) {
        oldState->cleanup();
        releaseMemory(oldState);
    }

    p->setState(0);
    p->setOwner(this);
}
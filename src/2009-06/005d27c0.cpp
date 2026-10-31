// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0055b5a0  unit: RBX::VInstance::?$SignalDesc  size: 255 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055b5a0
//
// 0055b5a0  6aff                 push -1
// 0055b5a2  6868917d00           push 0x7d9168
// 0055b5a7  64a100000000         mov eax, dword ptr fs:[0]
// 0055b5ad  50                   push eax
// 0055b5ae  64892500000000       mov dword ptr fs:[0], esp
// 0055b5b5  83ec0c               sub esp, 0xc
// 0055b5b8  a178539700           mov eax, dword ptr [0x975378]
// 0055b5bd  56                   push esi
// 0055b5be  57                   push edi
// 0055b5bf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0055b5c3  8bf1                 mov esi, ecx
// 0055b5c5  50                   push eax
// 0055b5c6  8bcf                 mov ecx, edi
// 0055b5c8  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0055b5d0  e8db0c0200           call 0x57c2b0
// 0055b5d5  85c0                 test eax, eax
// 0055b5d7  0f84af000000         je 0x55b68c
// 0055b5dd  8d4c2408             lea ecx, [esp + 8]
// 0055b5e1  51                   push ecx
// 0055b5e2  8d4808               lea ecx, [eax + 8]
// 0055b5e5  e8760d0200           call 0x57c360
// 0055b5ea  84c0                 test al, al
// 0055b5ec  0f849a000000         je 0x55b68c
// 0055b5f2  8b442408             mov eax, dword ptr [esp + 8]
// 0055b5f6  8b16                 mov edx, dword ptr [esi]
// 0055b5f8  8b5234               mov edx, dword ptr [edx + 0x34]
// 0055b5fb  50                   push eax
// 0055b5fc  8d4c2410             lea ecx, [esp + 0x10]
// 0055b600  51                   push ecx
// 0055b601  8bce                 mov ecx, esi
// 0055b603  ffd2                 call edx
// 0055b605  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055b609  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0055b611  85c9                 test ecx, ecx
// 0055b613  741b                 je 0x55b630
// 0055b615  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055b619  50                   push eax
// 0055b61a  57                   push edi
// 0055b61b  e8d0000000           call 0x55b6f0
// 0055b620  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055b624  85c9                 test ecx, ecx
// 0055b626  742a                 je 0x55b652
// 0055b628  56                   push esi
// 0055b629  e8c2f2ffff           call 0x55a8f0
// 0055b62e  eb22                 jmp 0x55b652
// 0055b630  8b0d10539700         mov ecx, dword ptr [0x975310]
// 0055b636  51                   push ecx
// 0055b637  8bcf                 mov ecx, edi
// 0055b639  e8720c0200           call 0x57c2b0
// 0055b63e  85c0                 test eax, eax
// 0055b640  7410                 je 0x55b652
// 0055b642  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055b646  8b11                 mov edx, dword ptr [ecx]
// 0055b648  83c008               add eax, 8
// 0055b64b  6a00                 push 0
// 0055b64d  50                   push eax
// 0055b64e  8b02                 mov eax, dword ptr [edx]
// 0055b650  ffd0                 call eax
// 0055b652  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055b656  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0055b65e  85f6                 test esi, esi
// 0055b660  742a                 je 0x55b68c
// 0055b662  8d4e04               lea ecx, [esi + 4]
// 0055b665  83caff               or edx, 0xffffffff
// 0055b668  f00fc111             lock xadd dword ptr [ecx], edx
// 0055b66c  751e                 jne 0x55b68c
// 0055b66e  8b06                 mov eax, dword ptr [esi]
// 0055b670  8b5004               mov edx, dword ptr [eax + 4]
// 0055b673  8bce                 mov ecx, esi
// 0055b675  ffd2                 call edx
// 0055b677  8d4608               lea eax, [esi + 8]
// 0055b67a  83c9ff               or ecx, 0xffffffff
// 0055b67d  f00fc108             lock xadd dword ptr [eax], ecx
// 0055b681  7509                 jne 0x55b68c
// 0055b683  8b16                 mov edx, dword ptr [esi]
// 0055b685  8b4208               mov eax, dword ptr [edx + 8]
// 0055b688  8bce                 mov ecx, esi
// 0055b68a  ffd0                 call eax
// 0055b68c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0055b690  5f                   pop edi
// 0055b691  5e                   pop esi
// 0055b692  64890d00000000       mov dword ptr fs:[0], ecx
// 0055b699  83c418               add esp, 0x18
// 0055b69c  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct S;
struct Document;
struct Sink;

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Connection {
    void send(Document*, Sink*);
    void remove(S*);
};

struct Shared {
    Connection* pointer;
    Control* control;
    __forceinline ~Shared();
};

__forceinline Shared::~Shared()
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

struct Value {
    bool extract(int*);
};

struct Node {
    unsigned char prefix[8];
    Value value;
};

struct Document {
    Node* find(int);
};

struct Sink {
    virtual void write(Value*, int);
};

extern int connectionKey;
extern int fallbackKey;

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Shared getConnection(int);
    void process(Document*, Sink*);
};

void S::process(Document* document, Sink* sink)
{
    int id = 0;
    Node* node = document->find(connectionKey);
    if (node && node->value.extract(&id)) {
        Shared connection = getConnection(id);
        if (connection.pointer) {
            connection.pointer->send(document, sink);
            if (connection.pointer)
                connection.pointer->remove(this);
        } else {
            Node* fallback = document->find(fallbackKey);
            if (fallback)
                sink->write(&fallback->value, 0);
        }
    }
}

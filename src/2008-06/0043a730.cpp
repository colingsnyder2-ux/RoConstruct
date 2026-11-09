// from server: 100% by colin
// from server: 94% by colin
// roc 2008-06 0043a730  unit: MVCXTPPropertyGridItem::?$XItem  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043a730
//
// 0043a730  6aff                 push -1
// 0043a732  6800057c00           push 0x7c0500
// 0043a737  64a100000000         mov eax, dword ptr fs:[0]
// 0043a73d  50                   push eax
// 0043a73e  64892500000000       mov dword ptr fs:[0], esp
// 0043a745  83ec0c               sub esp, 0xc
// 0043a748  56                   push esi
// 0043a749  8bf1                 mov esi, ecx
// 0043a74b  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 0043a751  8b8098010000         mov eax, dword ptr [eax + 0x198]
// 0043a757  57                   push edi
// 0043a758  33ff                 xor edi, edi
// 0043a75a  897c2408             mov dword ptr [esp + 8], edi
// 0043a75e  897c240c             mov dword ptr [esp + 0xc], edi
// 0043a762  50                   push eax
// 0043a763  8d4c240c             lea ecx, [esp + 0xc]
// 0043a767  897c2420             mov dword ptr [esp + 0x20], edi
// 0043a76b  897c2414             mov dword ptr [esp + 0x14], edi
// 0043a76f  e88cc71300           call 0x576f00
// 0043a774  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043a778  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0043a780  3bc7                 cmp eax, edi
// 0043a782  7405                 je 0x43a789
// 0043a784  83c014               add eax, 0x14
// 0043a787  eb02                 jmp 0x43a78b
// 0043a789  33c0                 xor eax, eax
// 0043a78b  8bb62c010000         mov esi, dword ptr [esi + 0x12c]
// 0043a791  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043a794  8b11                 mov edx, dword ptr [ecx]
// 0043a796  50                   push eax
// 0043a797  8b4208               mov eax, dword ptr [edx + 8]
// 0043a79a  ffd0                 call eax
// 0043a79c  d95c2424             fstp dword ptr [esp + 0x24]
// 0043a7a0  8d4c2408             lea ecx, [esp + 8]
// 0043a7a4  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043a7ac  e80fcc1300           call 0x5773c0
// 0043a7b1  d9442424             fld dword ptr [esp + 0x24]
// 0043a7b5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043a7b9  5f                   pop edi
// 0043a7ba  5e                   pop esi
// 0043a7bb  64890d00000000       mov dword ptr fs:[0], ecx
// 0043a7c2  83c418               add esp, 0x18
// 0043a7c5  c20400               ret 4

//

struct GuardData {
    int first;
    int second;
    int third;

    GuardData();
    void acquire(void*);
    ~GuardData();
};

inline GuardData::GuardData()
{
    first = 0;
    second = 0;
}

struct Guard {
    GuardData data;
    Guard(void*);
};

inline Guard::Guard(void* value)
{
    data.third = 0;
    data.acquire(value);
}

struct Argument {
    char padding[0x14];
    int value;
};

struct Interface {
    virtual void first();
    virtual void second();
    virtual float invoke(int*);
};

struct Context {
    char padding[0x198];
    void* value;
};

struct Owner {
    char padding[0x18];
    Interface* object;
};

struct Item {
    char padding[0x128];
    Context* context;
    Owner* owner;

    float f(Argument*);
};

float Item::f(Argument* argument)
{
    Guard guard(context->value);
    int* value = argument ? &argument->value : 0;
    Owner* currentOwner = owner;
    return currentOwner->object->invoke(value);
}

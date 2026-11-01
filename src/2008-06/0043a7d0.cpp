// from server: 100% by Espeon
// from server: 98% by colin
// roc 2008-06 0043a7d0  unit: MVCXTPPropertyGridItem::?$XItem  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043a7d0
//
// 0043a7d0  6aff                 push -1
// 0043a7d2  6800057c00           push 0x7c0500
// 0043a7d7  64a100000000         mov eax, dword ptr fs:[0]
// 0043a7dd  50                   push eax
// 0043a7de  64892500000000       mov dword ptr fs:[0], esp
// 0043a7e5  83ec0c               sub esp, 0xc
// 0043a7e8  56                   push esi
// 0043a7e9  8bf1                 mov esi, ecx
// 0043a7eb  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 0043a7f1  8b8098010000         mov eax, dword ptr [eax + 0x198]
// 0043a7f7  57                   push edi
// 0043a7f8  33ff                 xor edi, edi
// 0043a7fa  897c2408             mov dword ptr [esp + 8], edi
// 0043a7fe  897c240c             mov dword ptr [esp + 0xc], edi
// 0043a802  50                   push eax
// 0043a803  8d4c240c             lea ecx, [esp + 0xc]
// 0043a807  897c2420             mov dword ptr [esp + 0x20], edi
// 0043a80b  897c2414             mov dword ptr [esp + 0x14], edi
// 0043a80f  e8ecc61300           call 0x576f00
// 0043a814  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043a818  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0043a820  3bc7                 cmp eax, edi
// 0043a822  7405                 je 0x43a829
// 0043a824  83c014               add eax, 0x14
// 0043a827  eb02                 jmp 0x43a82b
// 0043a829  33c0                 xor eax, eax
// 0043a82b  8bb62c010000         mov esi, dword ptr [esi + 0x12c]
// 0043a831  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043a834  8b742428             mov esi, dword ptr [esp + 0x28]
// 0043a838  8b11                 mov edx, dword ptr [ecx]
// 0043a83a  56                   push esi
// 0043a83b  50                   push eax
// 0043a83c  8b420c               mov eax, dword ptr [edx + 0xc]
// 0043a83f  ffd0                 call eax
// 0043a841  8d4c2408             lea ecx, [esp + 8]
// 0043a845  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043a84d  e86ecb1300           call 0x5773c0
// 0043a852  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043a856  5f                   pop edi
// 0043a857  5e                   pop esi
// 0043a858  64890d00000000       mov dword ptr fs:[0], ecx
// 0043a85f  83c418               add esp, 0x18
// 0043a862  c20800               ret 8

//

struct Handle {
    int first;
    int second;
    Handle() : first(0), second(0) {}
    ~Handle();
};

struct Temporary {
    Handle handle;
    int third;
    void init(int value);
    Temporary(int value) : third(0) { init(value); }
    ~Temporary();
};

struct Source {
    char padding[0x198];
    int value;
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void invoke(void* value, int argument);
};

struct Destination {
    char padding[0x18];
    Receiver* receiver;
};

struct S {
    char padding[0x128];
    Source* source;
    Destination* destination;
    void f(void* value, int argument);
};

void S::f(void* value, int argument)
{
    Temporary temporary(source->value);
    char* p = static_cast<char*>(value);
    if (p != 0)
        p += 0x14;
    else
        p = 0;
    Destination* d = destination;
    Receiver* r = d->receiver;
    r->invoke(p, argument);
}


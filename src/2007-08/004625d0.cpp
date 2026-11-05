// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00466510  unit: RBX::VSelection::?$MarshaledListener  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00466510
//
// 00466510  6aff                 push -1
// 00466512  68e8347c00           push 0x7c34e8
// 00466517  64a100000000         mov eax, dword ptr fs:[0]
// 0046651d  50                   push eax
// 0046651e  64892500000000       mov dword ptr fs:[0], esp
// 00466525  83ec14               sub esp, 0x14
// 00466528  53                   push ebx
// 00466529  55                   push ebp
// 0046652a  56                   push esi
// 0046652b  8bf1                 mov esi, ecx
// 0046652d  8d9e90010000         lea ebx, [esi + 0x190]
// 00466533  8dae94010000         lea ebp, [esi + 0x194]
// 00466539  57                   push edi
// 0046653a  89742410             mov dword ptr [esp + 0x10], esi
// 0046653e  c706c4bb8100         mov dword ptr [esi], 0x81bbc4
// 00466544  c74654b0bb8100       mov dword ptr [esi + 0x54], 0x81bbb0
// 0046654b  c703a8bb8100         mov dword ptr [ebx], 0x81bba8
// 00466551  c7450090bb8100       mov dword ptr [ebp], 0x81bb90
// 00466558  8b86b8010000         mov eax, dword ptr [esi + 0x1b8]
// 0046655e  83ec08               sub esp, 8
// 00466561  8bcc                 mov ecx, esp
// 00466563  8901                 mov dword ptr [ecx], eax
// 00466565  8b86bc010000         mov eax, dword ptr [esi + 0x1bc]
// 0046656b  c744243404000000     mov dword ptr [esp + 0x34], 4
// 00466573  8964241c             mov dword ptr [esp + 0x1c], esp
// 00466577  894104               mov dword ptr [ecx + 4], eax
// 0046657a  85c0                 test eax, eax
// 0046657c  740c                 je 0x46658a
// 0046657e  83c004               add eax, 4
// 00466581  b901000000           mov ecx, 1
// 00466586  f00fc108             lock xadd dword ptr [eax], ecx
// 0046658a  8d4c2420             lea ecx, [esp + 0x20]
// 0046658e  e8adb5faff           call 0x411b40
// 00466593  8b86c0010000         mov eax, dword ptr [esi + 0x1c0]
// 00466599  c644242c05           mov byte ptr [esp + 0x2c], 5
// 0046659e  85c0                 test eax, eax
// 004665a0  740c                 je 0x4665ae
// 004665a2  55                   push ebp
// 004665a3  8d8830010000         lea ecx, [eax + 0x130]
// 004665a9  e8d2f41700           call 0x5e5a80
// 004665ae  8d4c2418             lea ecx, [esp + 0x18]
// 004665b2  c644242c04           mov byte ptr [esp + 0x2c], 4
// 004665b7  e8040e1100           call 0x5773c0
// 004665bc  8bbec4010000         mov edi, dword ptr [esi + 0x1c4]
// 004665c2  c644242c03           mov byte ptr [esp + 0x2c], 3
// 004665c7  85ff                 test edi, edi
// 004665c9  742a                 je 0x4665f5
// 004665cb  8d5704               lea edx, [edi + 4]
// 004665ce  83c8ff               or eax, 0xffffffff
// 004665d1  f00fc102             lock xadd dword ptr [edx], eax
// 004665d5  751e                 jne 0x4665f5
// 004665d7  8b17                 mov edx, dword ptr [edi]
// 004665d9  8b4204               mov eax, dword ptr [edx + 4]
// 004665dc  8bcf                 mov ecx, edi
// 004665de  ffd0                 call eax
// 004665e0  8d4f08               lea ecx, [edi + 8]
// 004665e3  83caff               or edx, 0xffffffff
// 004665e6  f00fc111             lock xadd dword ptr [ecx], edx
// 004665ea  7509                 jne 0x4665f5
// 004665ec  8b07                 mov eax, dword ptr [edi]
// 004665ee  8b5008               mov edx, dword ptr [eax + 8]
// 004665f1  8bcf                 mov ecx, edi
// 004665f3  ffd2                 call edx
// 004665f5  8bbebc010000         mov edi, dword ptr [esi + 0x1bc]
// 004665fb  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00466600  85ff                 test edi, edi
// 00466602  742a                 je 0x46662e
// 00466604  8d4704               lea eax, [edi + 4]
// 00466607  83c9ff               or ecx, 0xffffffff
// 0046660a  f00fc108             lock xadd dword ptr [eax], ecx
// 0046660e  751e                 jne 0x46662e
// 00466610  8b17                 mov edx, dword ptr [edi]
// 00466612  8b4204               mov eax, dword ptr [edx + 4]
// 00466615  8bcf                 mov ecx, edi
// 00466617  ffd0                 call eax
// 00466619  8d4f08               lea ecx, [edi + 8]
// 0046661c  83caff               or edx, 0xffffffff
// 0046661f  f00fc111             lock xadd dword ptr [ecx], edx
// 00466623  7509                 jne 0x46662e
// 00466625  8b07                 mov eax, dword ptr [edi]
// 00466627  8b5008               mov edx, dword ptr [eax + 8]
// 0046662a  8bcf                 mov ecx, edi
// 0046662c  ffd2                 call edx
// 0046662e  8bcd                 mov ecx, ebp
// 00466630  c644242c01           mov byte ptr [esp + 0x2c], 1
// 00466635  e886fdffff           call 0x4663c0
// 0046663a  8bcb                 mov ecx, ebx
// 0046663c  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00466641  e83af7f9ff           call 0x405d80
// 00466646  8bce                 mov ecx, esi
// 00466648  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00466650  e8cb232b00           call 0x718a20
// 00466655  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00466659  5f                   pop edi
// 0046665a  5e                   pop esi
// 0046665b  5d                   pop ebp
// 0046665c  64890d00000000       mov dword ptr fs:[0], ecx
// 00466663  5b                   pop ebx
// 00466664  83c420               add esp, 0x20
// 00466667  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Primary {
    virtual ~Primary();
    unsigned char padding[0x50];
};

struct Secondary {
    virtual ~Secondary();
    unsigned char padding[0x138];
};

struct Base : Primary, Secondary {
    virtual ~Base();
};

struct First {
    virtual ~First();
};

struct Storage {
    virtual ~Storage();
    void* allocation;
    unsigned int reserved[2];
    void* begin;
    void* end;
    void* capacity;
    unsigned int reserved2;
    void* object;
};

struct Registry {
    void remove(Storage*);
};

struct Object {
    unsigned char padding[0x130];
    Registry registry;
};

struct Guard {
    unsigned long data[3];
    Guard(Shared);
    ~Guard();
};

struct S : Base, First, Storage {
    Shared shared;
    Shared owner;
    virtual ~S();
};

S::~S()
{
    Guard guard(shared);
    if (owner.object)
        static_cast<Object*>(owner.object)->registry.remove(
            static_cast<Storage*>(this));
}

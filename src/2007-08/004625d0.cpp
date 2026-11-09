// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 004625d0  unit: RBX::VSelection::?$MarshaledListener  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004625d0
//
// 004625d0  6aff                 push -1
// 004625d2  683e2c7400           push 0x742c3e
// 004625d7  64a100000000         mov eax, dword ptr fs:[0]
// 004625dd  50                   push eax
// 004625de  83ec1c               sub esp, 0x1c
// 004625e1  53                   push ebx
// 004625e2  55                   push ebp
// 004625e3  56                   push esi
// 004625e4  57                   push edi
// 004625e5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004625ea  33c4                 xor eax, esp
// 004625ec  50                   push eax
// 004625ed  8d442430             lea eax, [esp + 0x30]
// 004625f1  64a300000000         mov dword ptr fs:[0], eax
// 004625f7  8bf1                 mov esi, ecx
// 004625f9  8974241c             mov dword ptr [esp + 0x1c], esi
// 004625fd  8d9e90010000         lea ebx, [esi + 0x190]
// 00462603  8dae94010000         lea ebp, [esi + 0x194]
// 00462609  c70674537900         mov dword ptr [esi], 0x795374
// 0046260f  c7465460537900       mov dword ptr [esi + 0x54], 0x795360
// 00462616  c70358537900         mov dword ptr [ebx], 0x795358
// 0046261c  c7450040537900       mov dword ptr [ebp], 0x795340
// 00462623  8b86b0010000         mov eax, dword ptr [esi + 0x1b0]
// 00462629  83ec08               sub esp, 8
// 0046262c  8bcc                 mov ecx, esp
// 0046262e  8901                 mov dword ptr [ecx], eax
// 00462630  8b86b4010000         mov eax, dword ptr [esi + 0x1b4]
// 00462636  85c0                 test eax, eax
// 00462638  c744244004000000     mov dword ptr [esp + 0x40], 4
// 00462640  89642428             mov dword ptr [esp + 0x28], esp
// 00462644  894104               mov dword ptr [ecx + 4], eax
// 00462647  740c                 je 0x462655
// 00462649  83c004               add eax, 4
// 0046264c  b901000000           mov ecx, 1
// 00462651  f00fc108             lock xadd dword ptr [eax], ecx
// 00462655  8d4c242c             lea ecx, [esp + 0x2c]
// 00462659  e8f2aefaff           call 0x40d550
// 0046265e  8b86b8010000         mov eax, dword ptr [esi + 0x1b8]
// 00462664  85c0                 test eax, eax
// 00462666  c644243805           mov byte ptr [esp + 0x38], 5
// 0046266b  740c                 je 0x462679
// 0046266d  55                   push ebp
// 0046266e  8d88e8000000         lea ecx, [eax + 0xe8]
// 00462674  e8b7fefcff           call 0x432530
// 00462679  8d4c2424             lea ecx, [esp + 0x24]
// 0046267d  c644243804           mov byte ptr [esp + 0x38], 4
// 00462682  e8196f0f00           call 0x5595a0
// 00462687  8bbebc010000         mov edi, dword ptr [esi + 0x1bc]
// 0046268d  85ff                 test edi, edi
// 0046268f  c644243803           mov byte ptr [esp + 0x38], 3
// 00462694  742a                 je 0x4626c0
// 00462696  8d5704               lea edx, [edi + 4]
// 00462699  83c8ff               or eax, 0xffffffff
// 0046269c  f00fc102             lock xadd dword ptr [edx], eax
// 004626a0  751e                 jne 0x4626c0
// 004626a2  8b17                 mov edx, dword ptr [edi]
// 004626a4  8b4204               mov eax, dword ptr [edx + 4]
// 004626a7  8bcf                 mov ecx, edi
// 004626a9  ffd0                 call eax
// 004626ab  8d4f08               lea ecx, [edi + 8]
// 004626ae  83caff               or edx, 0xffffffff
// 004626b1  f00fc111             lock xadd dword ptr [ecx], edx
// 004626b5  7509                 jne 0x4626c0
// 004626b7  8b07                 mov eax, dword ptr [edi]
// 004626b9  8b5008               mov edx, dword ptr [eax + 8]
// 004626bc  8bcf                 mov ecx, edi
// 004626be  ffd2                 call edx
// 004626c0  8bbeb4010000         mov edi, dword ptr [esi + 0x1b4]
// 004626c6  85ff                 test edi, edi
// 004626c8  c644243802           mov byte ptr [esp + 0x38], 2
// 004626cd  742a                 je 0x4626f9
// 004626cf  8d4704               lea eax, [edi + 4]
// 004626d2  83c9ff               or ecx, 0xffffffff
// 004626d5  f00fc108             lock xadd dword ptr [eax], ecx
// 004626d9  751e                 jne 0x4626f9
// 004626db  8b17                 mov edx, dword ptr [edi]
// 004626dd  8b4204               mov eax, dword ptr [edx + 4]
// 004626e0  8bcf                 mov ecx, edi
// 004626e2  ffd0                 call eax
// 004626e4  8d4f08               lea ecx, [edi + 8]
// 004626e7  83caff               or edx, 0xffffffff
// 004626ea  f00fc111             lock xadd dword ptr [ecx], edx
// 004626ee  7509                 jne 0x4626f9
// 004626f0  8b07                 mov eax, dword ptr [edi]
// 004626f2  8b5008               mov edx, dword ptr [eax + 8]
// 004626f5  8bcf                 mov ecx, edi
// 004626f7  ffd2                 call edx
// 004626f9  8bcd                 mov ecx, ebp
// 004626fb  c644243801           mov byte ptr [esp + 0x38], 1
// 00462700  e80bfeffff           call 0x462510
// 00462705  8bcb                 mov ecx, ebx
// 00462707  c644243800           mov byte ptr [esp + 0x38], 0
// 0046270c  e8df4cfaff           call 0x4073f0
// 00462711  8bce                 mov ecx, esi
// 00462713  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0046271b  e8d0ca2300           call 0x69f1f0
// 00462720  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00462724  64890d00000000       mov dword ptr fs:[0], ecx
// 0046272b  59                   pop ecx
// 0046272c  5f                   pop edi
// 0046272d  5e                   pop esi
// 0046272e  5d                   pop ebp
// 0046272f  5b                   pop ebx
// 00462730  83c428               add esp, 0x28
// 00462733  c3                   ret 

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
    unsigned char padding[0xe8];
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

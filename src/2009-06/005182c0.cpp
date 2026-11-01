// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 005182c0  unit: RBX::PartChunk  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005182c0
//
// 005182c0  6aff                 push -1
// 005182c2  6808dd8500           push 0x85dd08
// 005182c7  64a100000000         mov eax, dword ptr fs:[0]
// 005182cd  50                   push eax
// 005182ce  64892500000000       mov dword ptr fs:[0], esp
// 005182d5  51                   push ecx
// 005182d6  56                   push esi
// 005182d7  8bf1                 mov esi, ecx
// 005182d9  837e7800             cmp dword ptr [esi + 0x78], 0
// 005182dd  0f8433010000         je 0x518416
// 005182e3  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 005182e9  53                   push ebx
// 005182ea  8b1da4e18900         mov ebx, dword ptr [0x89e1a4]
// 005182f0  85c0                 test eax, eax
// 005182f2  7431                 je 0x518325
// 005182f4  83c004               add eax, 4
// 005182f7  50                   push eax
// 005182f8  ffd3                 call ebx
// 005182fa  85c0                 test eax, eax
// 005182fc  751d                 jne 0x51831b
// 005182fe  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 00518304  e877caf2ff           call 0x444d80
// 00518309  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 0051830f  85c9                 test ecx, ecx
// 00518311  7408                 je 0x51831b
// 00518313  8b01                 mov eax, dword ptr [ecx]
// 00518315  8b10                 mov edx, dword ptr [eax]
// 00518317  6a01                 push 1
// 00518319  ffd2                 call edx
// 0051831b  c7868000000000000000 mov dword ptr [esi + 0x80], 0
// 00518325  8d4604               lea eax, [esi + 4]
// 00518328  50                   push eax
// 00518329  c6868400000001       mov byte ptr [esi + 0x84], 1
// 00518330  8974240c             mov dword ptr [esp + 0xc], esi
// 00518334  ff15d0e18900         call dword ptr [0x89e1d0]
// 0051833a  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00518340  8b4804               mov ecx, dword ptr [eax + 4]
// 00518343  8b4678               mov eax, dword ptr [esi + 0x78]
// 00518346  83b8a400000000       cmp dword ptr [eax + 0xa4], 0
// 0051834d  8b11                 mov edx, dword ptr [ecx]
// 0051834f  8b12                 mov edx, dword ptr [edx]
// 00518351  0f94c0               sete al
// 00518354  0fb6c0               movzx eax, al
// 00518357  50                   push eax
// 00518358  8d44240c             lea eax, [esp + 0xc]
// 0051835c  50                   push eax
// 0051835d  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00518365  ffd2                 call edx
// 00518367  8b442408             mov eax, dword ptr [esp + 8]
// 0051836b  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00518373  85c0                 test eax, eax
// 00518375  742b                 je 0x5183a2
// 00518377  83c004               add eax, 4
// 0051837a  50                   push eax
// 0051837b  ffd3                 call ebx
// 0051837d  85c0                 test eax, eax
// 0051837f  7519                 jne 0x51839a
// 00518381  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00518385  e8f6c9f2ff           call 0x444d80
// 0051838a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051838e  85c9                 test ecx, ecx
// 00518390  7408                 je 0x51839a
// 00518392  8b01                 mov eax, dword ptr [ecx]
// 00518394  8b10                 mov edx, dword ptr [eax]
// 00518396  6a01                 push 1
// 00518398  ffd2                 call edx
// 0051839a  c744240800000000     mov dword ptr [esp + 8], 0
// 005183a2  8b4678               mov eax, dword ptr [esi + 0x78]
// 005183a5  8b16                 mov edx, dword ptr [esi]
// 005183a7  83b8a400000000       cmp dword ptr [eax + 0xa4], 0
// 005183ae  8b4224               mov eax, dword ptr [edx + 0x24]
// 005183b1  5b                   pop ebx
// 005183b2  8bce                 mov ecx, esi
// 005183b4  7430                 je 0x5183e6
// 005183b6  ffd0                 call eax
// 005183b8  d9054cad8b00         fld dword ptr [0x8bad4c]
// 005183be  d8d1                 fcom st(1)
// 005183c0  dfe0                 fnstsw ax
// 005183c2  ddd9                 fstp st(1)
// 005183c4  f6c441               test ah, 0x41
// 005183c7  754b                 jne 0x518414
// 005183c9  8b16                 mov edx, dword ptr [esi]
// 005183cb  8b4220               mov eax, dword ptr [edx + 0x20]
// 005183ce  51                   push ecx
// 005183cf  8bce                 mov ecx, esi
// 005183d1  d91c24               fstp dword ptr [esp]
// 005183d4  ffd0                 call eax
// 005183d6  5e                   pop esi
// 005183d7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005183db  64890d00000000       mov dword ptr fs:[0], ecx
// 005183e2  83c410               add esp, 0x10
// 005183e5  c3                   ret 
// 005183e6  ffd0                 call eax
// 005183e8  d81d00a58b00         fcomp dword ptr [0x8ba500]
// 005183ee  dfe0                 fnstsw ax
// 005183f0  f6c405               test ah, 5
// 005183f3  7a21                 jp 0x518416
// 005183f5  8b16                 mov edx, dword ptr [esi]
// 005183f7  d9ee                 fldz 
// 005183f9  8b4220               mov eax, dword ptr [edx + 0x20]
// 005183fc  51                   push ecx
// 005183fd  8bce                 mov ecx, esi
// 005183ff  d91c24               fstp dword ptr [esp]
// 00518402  ffd0                 call eax
// 00518404  5e                   pop esi
// 00518405  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00518409  64890d00000000       mov dword ptr fs:[0], ecx
// 00518410  83c410               add esp, 0x10
// 00518413  c3                   ret 
// 00518414  ddd8                 fstp st(0)
// 00518416  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051841a  5e                   pop esi
// 0051841b  64890d00000000       mov dword ptr fs:[0], ecx
// 00518422  83c410               add esp, 0x10
// 00518425  c3                   ret 

// from server: 100% by colin
// roc 2008-06 004e68b0  unit: RBX::ViewNew::Part  size: 367 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e68b0
//
// 004e68b0  6aff                 push -1
// 004e68b2  68e8a47c00           push 0x7ca4e8
// 004e68b7  64a100000000         mov eax, dword ptr fs:[0]
// 004e68bd  50                   push eax
// 004e68be  64892500000000       mov dword ptr fs:[0], esp
// 004e68c5  51                   push ecx
// 004e68c6  56                   push esi
// 004e68c7  8bf1                 mov esi, ecx
// 004e68c9  83bebc00000000       cmp dword ptr [esi + 0xbc], 0
// 004e68d0  0f8439010000         je 0x4e6a0f
// 004e68d6  8b86c4000000         mov eax, dword ptr [esi + 0xc4]
// 004e68dc  53                   push ebx
// 004e68dd  8b1dac218000         mov ebx, dword ptr [0x8021ac]
// 004e68e3  85c0                 test eax, eax
// 004e68e5  7431                 je 0x4e6918
// 004e68e7  83c004               add eax, 4
// 004e68ea  50                   push eax
// 004e68eb  ffd3                 call ebx
// 004e68ed  85c0                 test eax, eax
// 004e68ef  751d                 jne 0x4e690e
// 004e68f1  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 004e68f7  e89444f7ff           call 0x45ad90
// 004e68fc  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 004e6902  85c9                 test ecx, ecx
// 004e6904  7408                 je 0x4e690e
// 004e6906  8b01                 mov eax, dword ptr [ecx]
// 004e6908  8b10                 mov edx, dword ptr [eax]
// 004e690a  6a01                 push 1
// 004e690c  ffd2                 call edx
// 004e690e  c786c400000000000000 mov dword ptr [esi + 0xc4], 0
// 004e6918  8d4604               lea eax, [esi + 4]
// 004e691b  50                   push eax
// 004e691c  c686c800000001       mov byte ptr [esi + 0xc8], 1
// 004e6923  8974240c             mov dword ptr [esp + 0xc], esi
// 004e6927  ff15b0218000         call dword ptr [0x8021b0]
// 004e692d  8b86d0000000         mov eax, dword ptr [esi + 0xd0]
// 004e6933  8b4804               mov ecx, dword ptr [eax + 4]
// 004e6936  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 004e693c  83b8c801000000       cmp dword ptr [eax + 0x1c8], 0
// 004e6943  8b11                 mov edx, dword ptr [ecx]
// 004e6945  8b12                 mov edx, dword ptr [edx]
// 004e6947  0f94c0               sete al
// 004e694a  0fb6c0               movzx eax, al
// 004e694d  50                   push eax
// 004e694e  8d44240c             lea eax, [esp + 0xc]
// 004e6952  50                   push eax
// 004e6953  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004e695b  ffd2                 call edx
// 004e695d  8b442408             mov eax, dword ptr [esp + 8]
// 004e6961  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004e6969  85c0                 test eax, eax
// 004e696b  742b                 je 0x4e6998
// 004e696d  83c004               add eax, 4
// 004e6970  50                   push eax
// 004e6971  ffd3                 call ebx
// 004e6973  85c0                 test eax, eax
// 004e6975  7519                 jne 0x4e6990
// 004e6977  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e697b  e81044f7ff           call 0x45ad90
// 004e6980  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e6984  85c9                 test ecx, ecx
// 004e6986  7408                 je 0x4e6990
// 004e6988  8b01                 mov eax, dword ptr [ecx]
// 004e698a  8b10                 mov edx, dword ptr [eax]
// 004e698c  6a01                 push 1
// 004e698e  ffd2                 call edx
// 004e6990  c744240800000000     mov dword ptr [esp + 8], 0
// 004e6998  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 004e699e  8b16                 mov edx, dword ptr [esi]
// 004e69a0  83b8c801000000       cmp dword ptr [eax + 0x1c8], 0
// 004e69a7  8b4224               mov eax, dword ptr [edx + 0x24]
// 004e69aa  5b                   pop ebx
// 004e69ab  8bce                 mov ecx, esi
// 004e69ad  7430                 je 0x4e69df
// 004e69af  ffd0                 call eax
// 004e69b1  d905ac9b8100         fld dword ptr [0x819bac]
// 004e69b7  d8d1                 fcom st(1)
// 004e69b9  dfe0                 fnstsw ax
// 004e69bb  ddd9                 fstp st(1)
// 004e69bd  f6c441               test ah, 0x41
// 004e69c0  754b                 jne 0x4e6a0d
// 004e69c2  8b16                 mov edx, dword ptr [esi]
// 004e69c4  8b4220               mov eax, dword ptr [edx + 0x20]
// 004e69c7  51                   push ecx
// 004e69c8  8bce                 mov ecx, esi
// 004e69ca  d91c24               fstp dword ptr [esp]
// 004e69cd  ffd0                 call eax
// 004e69cf  5e                   pop esi
// 004e69d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004e69d4  64890d00000000       mov dword ptr fs:[0], ecx
// 004e69db  83c410               add esp, 0x10
// 004e69de  c3                   ret 
// 004e69df  ffd0                 call eax
// 004e69e1  d81d94748200         fcomp dword ptr [0x827494]
// 004e69e7  dfe0                 fnstsw ax
// 004e69e9  f6c405               test ah, 5
// 004e69ec  7a21                 jp 0x4e6a0f
// 004e69ee  8b16                 mov edx, dword ptr [esi]
// 004e69f0  d9ee                 fldz 
// 004e69f2  8b4220               mov eax, dword ptr [edx + 0x20]
// 004e69f5  51                   push ecx
// 004e69f6  8bce                 mov ecx, esi
// 004e69f8  d91c24               fstp dword ptr [esp]
// 004e69fb  ffd0                 call eax
// 004e69fd  5e                   pop esi
// 004e69fe  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004e6a02  64890d00000000       mov dword ptr fs:[0], ecx
// 004e6a09  83c410               add esp, 0x10
// 004e6a0c  c3                   ret 
// 004e6a0d  ddd8                 fstp st(0)
// 004e6a0f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e6a13  5e                   pop esi
// 004e6a14  64890d00000000       mov dword ptr fs:[0], ecx
// 004e6a1b  83c410               add esp, 0x10
// 004e6a1e  c3                   ret 

// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern const float upperLimit;
extern const float lowerLimit;

struct Ref {
    virtual ~Ref();
    volatile long references;
    void release();
};

struct Ptr {
    Ref* p;
    Ptr(Ref* value);
    ~Ptr();
    void clear();
};

inline Ptr::Ptr(Ref* value) : p(value)
{
    if (p)
        InterlockedIncrement(&p->references);
}

inline void Ptr::clear()
{
    if (p) {
        if (InterlockedDecrement(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
        p = 0;
    }
}

inline Ptr::~Ptr()
{
    clear();
}

struct Model {
    char padding[0xa4];
    int state;
};

struct Handler {
    virtual void update(const Ptr&, bool);
};

struct Holder {
    int padding;
    Handler* handler;
};

struct S : Ref {
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void setValue(float);
    virtual float getValue();

    char padding[0x70];
    Model* model;
    int unused;
    Ptr pending;
    bool active;
    char tailPadding[7];
    Holder* holder;

    void f();
};

void S::f()
{
    if (!model)
        return;

    pending.clear();
    active = true;

    {
        Ptr self(this);
        Holder* h = holder;
        Handler* handler = h->handler;
        handler->update(self, model->state == 0);
    }

    if (model->state != 0) {
        if (getValue() < upperLimit)
            setValue(upperLimit);
    } else {
        if (getValue() < lowerLimit)
            setValue(0.0f);
    }
}

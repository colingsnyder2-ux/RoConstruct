// from server: 84% by EspClaude
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
    char padding[0x1c8];
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

    char padding[0xb4];
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

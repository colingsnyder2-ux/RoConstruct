// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00665bd0  unit: RBX::PartDragTool  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00665bd0
//
// 00665bd0  6aff                 push -1
// 00665bd2  689ec07d00           push 0x7dc09e
// 00665bd7  64a100000000         mov eax, dword ptr fs:[0]
// 00665bdd  50                   push eax
// 00665bde  64892500000000       mov dword ptr fs:[0], esp
// 00665be5  51                   push ecx
// 00665be6  56                   push esi
// 00665be7  8bf1                 mov esi, ecx
// 00665be9  57                   push edi
// 00665bea  89742408             mov dword ptr [esp + 8], esi
// 00665bee  c706b4cb8400         mov dword ptr [esi], 0x84cbb4
// 00665bf4  c746049ccb8400       mov dword ptr [esi + 4], 0x84cb9c
// 00665bfb  8b7e28               mov edi, dword ptr [esi + 0x28]
// 00665bfe  c744241402000000     mov dword ptr [esp + 0x14], 2
// 00665c06  85ff                 test edi, edi
// 00665c08  742a                 je 0x665c34
// 00665c0a  8d4704               lea eax, [edi + 4]
// 00665c0d  83c9ff               or ecx, 0xffffffff
// 00665c10  f00fc108             lock xadd dword ptr [eax], ecx
// 00665c14  751e                 jne 0x665c34
// 00665c16  8b17                 mov edx, dword ptr [edi]
// 00665c18  8b4204               mov eax, dword ptr [edx + 4]
// 00665c1b  8bcf                 mov ecx, edi
// 00665c1d  ffd0                 call eax
// 00665c1f  8d4f08               lea ecx, [edi + 8]
// 00665c22  83caff               or edx, 0xffffffff
// 00665c25  f00fc111             lock xadd dword ptr [ecx], edx
// 00665c29  7509                 jne 0x665c34
// 00665c2b  8b07                 mov eax, dword ptr [edi]
// 00665c2d  8b5008               mov edx, dword ptr [eax + 8]
// 00665c30  8bcf                 mov ecx, edi
// 00665c32  ffd2                 call edx
// 00665c34  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00665c37  c644241401           mov byte ptr [esp + 0x14], 1
// 00665c3c  85ff                 test edi, edi
// 00665c3e  7410                 je 0x665c50
// 00665c40  8bcf                 mov ecx, edi
// 00665c42  e8b98afaff           call 0x60e700
// 00665c47  57                   push edi
// 00665c48  e82daa0300           call 0x6a067a
// 00665c4d  83c404               add esp, 4
// 00665c50  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 00665c53  c644241400           mov byte ptr [esp + 0x14], 0
// 00665c58  85ff                 test edi, edi
// 00665c5a  7410                 je 0x665c6c
// 00665c5c  8bcf                 mov ecx, edi
// 00665c5e  e89d670000           call 0x66c400
// 00665c63  57                   push edi
// 00665c64  e811aa0300           call 0x6a067a
// 00665c69  83c404               add esp, 4
// 00665c6c  8bce                 mov ecx, esi
// 00665c6e  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00665c76  e805fbfaff           call 0x615780
// 00665c7b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00665c7f  5f                   pop edi
// 00665c80  5e                   pop esi
// 00665c81  64890d00000000       mov dword ptr fs:[0], ecx
// 00665c88  83c410               add esp, 0x10
// 00665c8b  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl operator delete(void*);

struct Control {
    virtual void dispose();
    virtual void release();
    virtual void destroy();
    volatile long strongCount;
    volatile long weakCount;
};

struct Weak {
    ~Weak();
};

struct Thing {
    ~Thing();
};

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char data[20];
    virtual ~Base();
};

struct ThingOwner {
    Thing* pointer;
    ~ThingOwner();
};

struct WeakOwner {
    Weak* pointer;
    ~WeakOwner();
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

struct S : Base {
    ThingOwner thing;
    WeakOwner weak;
    Shared shared;
    virtual ~S();
};

inline ThingOwner::~ThingOwner()
{
    Thing* p = pointer;
    if (p) {
        p->~Thing();
        operator delete(p);
    }
}

inline WeakOwner::~WeakOwner()
{
    Weak* p = pointer;
    if (p) {
        p->~Weak();
        operator delete(p);
    }
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strongCount) == 0) {
            p->release();
            if (_InterlockedDecrement(&p->weakCount) == 0)
                p->destroy();
        }
    }
}

S::~S()
{
}

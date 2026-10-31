// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006214e0  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006214e0
//
// 006214e0  64a100000000         mov eax, dword ptr fs:[0]
// 006214e6  6aff                 push -1
// 006214e8  6838ea7b00           push 0x7bea38
// 006214ed  50                   push eax
// 006214ee  64892500000000       mov dword ptr fs:[0], esp
// 006214f5  83ec18               sub esp, 0x18
// 006214f8  56                   push esi
// 006214f9  8bf1                 mov esi, ecx
// 006214fb  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006214ff  85c9                 test ecx, ecx
// 00621501  7405                 je 0x621508
// 00621503  8d41f4               lea eax, [ecx - 0xc]
// 00621506  eb02                 jmp 0x62150a
// 00621508  33c0                 xor eax, eax
// 0062150a  dd442430             fld qword ptr [esp + 0x30]
// 0062150e  83ec08               sub esp, 8
// 00621511  dd1c24               fstp qword ptr [esp]
// 00621514  51                   push ecx
// 00621515  8d4c2410             lea ecx, [esp + 0x10]
// 00621519  c6400801             mov byte ptr [eax + 8], 1
// 0062151d  e8aef7ffff           call 0x620cd0
// 00621522  50                   push eax
// 00621523  8d4e04               lea ecx, [esi + 4]
// 00621526  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0062152e  e80dffffff           call 0x621440
// 00621533  8b442408             mov eax, dword ptr [esp + 8]
// 00621537  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0062153f  85c0                 test eax, eax
// 00621541  742c                 je 0x62156f
// 00621543  8bf0                 mov esi, eax
// 00621545  83c004               add eax, 4
// 00621548  83c9ff               or ecx, 0xffffffff
// 0062154b  f00fc108             lock xadd dword ptr [eax], ecx
// 0062154f  751e                 jne 0x62156f
// 00621551  8b16                 mov edx, dword ptr [esi]
// 00621553  8b4204               mov eax, dword ptr [edx + 4]
// 00621556  8bce                 mov ecx, esi
// 00621558  ffd0                 call eax
// 0062155a  8d4e08               lea ecx, [esi + 8]
// 0062155d  83caff               or edx, 0xffffffff
// 00621560  f00fc111             lock xadd dword ptr [ecx], edx
// 00621564  7509                 jne 0x62156f
// 00621566  8b06                 mov eax, dword ptr [esi]
// 00621568  8b5008               mov edx, dword ptr [eax + 8]
// 0062156b  8bce                 mov ecx, esi
// 0062156d  ffd2                 call edx
// 0062156f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00621573  5e                   pop esi
// 00621574  64890d00000000       mov dword ptr fs:[0], ecx
// 0062157b  83c424               add esp, 0x24
// 0062157e  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Ref {
    void* pointer;
    Control* control;
    unsigned char value[16];

    Ref(void*, double);
    ~Ref();
    Ref& operator=(const Ref&);
};

struct S {
    unsigned long first;
    Ref reference;

    void f(void*, double);
};

inline Ref::~Ref()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void S::f(void* p, double value)
{
    unsigned char* base = p ? static_cast<unsigned char*>(p) - 12 : 0;
    base[8] = 1;
    reference = Ref(p, value);
}

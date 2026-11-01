// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004b3870  unit: RBX::Network::VMarker::?$SignalDesc  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b3870
//
// 004b3870  64a100000000         mov eax, dword ptr fs:[0]
// 004b3876  6aff                 push -1
// 004b3878  6868917d00           push 0x7d9168
// 004b387d  50                   push eax
// 004b387e  64892500000000       mov dword ptr fs:[0], esp
// 004b3885  83ec08               sub esp, 8
// 004b3888  56                   push esi
// 004b3889  8bf1                 mov esi, ecx
// 004b388b  e8f0faffff           call 0x4b3380
// 004b3890  85c0                 test eax, eax
// 004b3892  0f85ac000000         jne 0x4b3944
// 004b3898  53                   push ebx
// 004b3899  8d442408             lea eax, [esp + 8]
// 004b389d  57                   push edi
// 004b389e  50                   push eax
// 004b389f  e8bca2ffff           call 0x4adb60
// 004b38a4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b38a8  6890149700           push 0x971490
// 004b38ad  6800c64a00           push 0x4ac600
// 004b38b2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004b38ba  e8713a0a00           call 0x557330
// 004b38bf  83c40c               add esp, 0xc
// 004b38c2  e8a97bffff           call 0x4ab470
// 004b38c7  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 004b38cd  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 004b38d3  8bf8                 mov edi, eax
// 004b38d5  c1f903               sar ecx, 3
// 004b38d8  3bf9                 cmp edi, ecx
// 004b38da  7206                 jb 0x4b38e2
// 004b38dc  ff1590288000         call dword ptr [0x802890]
// 004b38e2  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 004b38e8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b38ec  8d04fa               lea eax, [edx + edi*8]
// 004b38ef  8d542410             lea edx, [esp + 0x10]
// 004b38f3  8908                 mov dword ptr [eax], ecx
// 004b38f5  52                   push edx
// 004b38f6  8d4804               lea ecx, [eax + 4]
// 004b38f9  e8b2ecf4ff           call 0x4025b0
// 004b38fe  56                   push esi
// 004b38ff  8bcb                 mov ecx, ebx
// 004b3901  e8ea6f0a00           call 0x55a8f0
// 004b3906  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b390a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004b3912  85f6                 test esi, esi
// 004b3914  742a                 je 0x4b3940
// 004b3916  8d4604               lea eax, [esi + 4]
// 004b3919  83c9ff               or ecx, 0xffffffff
// 004b391c  f00fc108             lock xadd dword ptr [eax], ecx
// 004b3920  751e                 jne 0x4b3940
// 004b3922  8b16                 mov edx, dword ptr [esi]
// 004b3924  8b4204               mov eax, dword ptr [edx + 4]
// 004b3927  8bce                 mov ecx, esi
// 004b3929  ffd0                 call eax
// 004b392b  8d4e08               lea ecx, [esi + 8]
// 004b392e  83caff               or edx, 0xffffffff
// 004b3931  f00fc111             lock xadd dword ptr [ecx], edx
// 004b3935  7509                 jne 0x4b3940
// 004b3937  8b06                 mov eax, dword ptr [esi]
// 004b3939  8b5008               mov edx, dword ptr [eax + 8]
// 004b393c  8bce                 mov ecx, esi
// 004b393e  ffd2                 call edx
// 004b3940  5f                   pop edi
// 004b3941  8bc3                 mov eax, ebx
// 004b3943  5b                   pop ebx
// 004b3944  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b3948  5e                   pop esi
// 004b3949  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3950  83c414               add esp, 0x14
// 004b3953  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct S;

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Reference {
    Control* control;
    Reference& operator=(const Reference&);
};

struct Object {
    void attach(S*);
};

struct Pair {
    Object* object;
    Reference reference;
    ~Pair();
};

inline Pair::~Pair()
{
    if (reference.control)
        reference.control->release();
}

Pair __cdecl make_pair();
unsigned int __cdecl get_index();
void __cdecl cleanup();
extern unsigned int cleanup_data;
void __cdecl register_cleanup(void (__cdecl*)(), unsigned int*);

struct S {
    unsigned char padding[0x19c];
    Pair* begin;
    Pair* end;

    Object* lookup();
    Object* get();
};

Object* S::get()
{
    Object* result = lookup();
    if (!result) {
        Pair value = make_pair();
        result = value.object;
        register_cleanup(cleanup, &cleanup_data);
        unsigned int index = get_index();
        if (index >= static_cast<unsigned int>(end - begin))
            _invalid_parameter_noinfo();
        Pair* slot = begin + index;
        slot->object = value.object;
        slot->reference = value.reference;
        result->attach(this);
    }
    return result;
}

// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 004eb020  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004eb020
//
// 004eb020  64a100000000         mov eax, dword ptr fs:[0]
// 004eb026  6aff                 push -1
// 004eb028  68e8a68600           push 0x86a6e8
// 004eb02d  50                   push eax
// 004eb02e  64892500000000       mov dword ptr fs:[0], esp
// 004eb035  83ec08               sub esp, 8
// 004eb038  56                   push esi
// 004eb039  8bf1                 mov esi, ecx
// 004eb03b  e8b0f3ffff           call 0x4ea3f0
// 004eb040  85c0                 test eax, eax
// 004eb042  0f85ac000000         jne 0x4eb0f4
// 004eb048  53                   push ebx
// 004eb049  8d442408             lea eax, [esp + 8]
// 004eb04d  57                   push edi
// 004eb04e  50                   push eax
// 004eb04f  e87caaffff           call 0x4e5ad0
// 004eb054  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004eb058  6880464e00           push 0x4e4680
// 004eb05d  68c8f2a300           push 0xa3f2c8
// 004eb062  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004eb06a  e8a166f1ff           call 0x401710
// 004eb06f  83c40c               add esp, 0xc
// 004eb072  e87986ffff           call 0x4e36f0
// 004eb077  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 004eb07d  2b8e98000000         sub ecx, dword ptr [esi + 0x98]
// 004eb083  8bf8                 mov edi, eax
// 004eb085  c1f903               sar ecx, 3
// 004eb088  3bf9                 cmp edi, ecx
// 004eb08a  7206                 jb 0x4eb092
// 004eb08c  ff15ace98900         call dword ptr [0x89e9ac]
// 004eb092  8b9698000000         mov edx, dword ptr [esi + 0x98]
// 004eb098  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004eb09c  8d04fa               lea eax, [edx + edi*8]
// 004eb09f  8d542410             lea edx, [esp + 0x10]
// 004eb0a3  8908                 mov dword ptr [eax], ecx
// 004eb0a5  52                   push edx
// 004eb0a6  8d4804               lea ecx, [eax + 4]
// 004eb0a9  e85274f1ff           call 0x402500
// 004eb0ae  56                   push esi
// 004eb0af  8bcb                 mov ecx, ebx
// 004eb0b1  e89a6d0e00           call 0x5d1e50
// 004eb0b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004eb0ba  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004eb0c2  85f6                 test esi, esi
// 004eb0c4  742a                 je 0x4eb0f0
// 004eb0c6  8d4604               lea eax, [esi + 4]
// 004eb0c9  83c9ff               or ecx, 0xffffffff
// 004eb0cc  f00fc108             lock xadd dword ptr [eax], ecx
// 004eb0d0  751e                 jne 0x4eb0f0
// 004eb0d2  8b16                 mov edx, dword ptr [esi]
// 004eb0d4  8b4204               mov eax, dword ptr [edx + 4]
// 004eb0d7  8bce                 mov ecx, esi
// 004eb0d9  ffd0                 call eax
// 004eb0db  8d4e08               lea ecx, [esi + 8]
// 004eb0de  83caff               or edx, 0xffffffff
// 004eb0e1  f00fc111             lock xadd dword ptr [ecx], edx
// 004eb0e5  7509                 jne 0x4eb0f0
// 004eb0e7  8b06                 mov eax, dword ptr [esi]
// 004eb0e9  8b5008               mov edx, dword ptr [eax + 8]
// 004eb0ec  8bce                 mov ecx, esi
// 004eb0ee  ffd2                 call edx
// 004eb0f0  5f                   pop edi
// 004eb0f1  8bc3                 mov eax, ebx
// 004eb0f3  5b                   pop ebx
// 004eb0f4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004eb0f8  5e                   pop esi
// 004eb0f9  64890d00000000       mov dword ptr fs:[0], ecx
// 004eb100  83c414               add esp, 0x14
// 004eb103  c3                   ret 

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
    unsigned char padding[0x98];
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

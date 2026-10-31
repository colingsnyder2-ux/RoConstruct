// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063e180  unit: RBX::LockTool  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063e180
//
// 0063e180  64a100000000         mov eax, dword ptr fs:[0]
// 0063e186  6aff                 push -1
// 0063e188  6868917d00           push 0x7d9168
// 0063e18d  50                   push eax
// 0063e18e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0063e192  64892500000000       mov dword ptr fs:[0], esp
// 0063e199  83ec08               sub esp, 8
// 0063e19c  56                   push esi
// 0063e19d  68e0be9700           push 0x97bee0
// 0063e1a2  6a00                 push 0
// 0063e1a4  50                   push eax
// 0063e1a5  8bf1                 mov esi, ecx
// 0063e1a7  e8e47bfdff           call 0x615d90
// 0063e1ac  85c0                 test eax, eax
// 0063e1ae  747b                 je 0x63e22b
// 0063e1b0  50                   push eax
// 0063e1b1  e8da2bf6ff           call 0x5a0d90
// 0063e1b6  50                   push eax
// 0063e1b7  8d4c240c             lea ecx, [esp + 0xc]
// 0063e1bb  51                   push ecx
// 0063e1bc  e87fa8fdff           call 0x618a40
// 0063e1c1  83c40c               add esp, 0xc
// 0063e1c4  8b10                 mov edx, dword ptr [eax]
// 0063e1c6  83c004               add eax, 4
// 0063e1c9  50                   push eax
// 0063e1ca  8d4e20               lea ecx, [esi + 0x20]
// 0063e1cd  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0063e1d5  89561c               mov dword ptr [esi + 0x1c], edx
// 0063e1d8  e8d343dcff           call 0x4025b0
// 0063e1dd  8b442408             mov eax, dword ptr [esp + 8]
// 0063e1e1  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0063e1e9  85c0                 test eax, eax
// 0063e1eb  7446                 je 0x63e233
// 0063e1ed  8bf0                 mov esi, eax
// 0063e1ef  83c004               add eax, 4
// 0063e1f2  83c9ff               or ecx, 0xffffffff
// 0063e1f5  f00fc108             lock xadd dword ptr [eax], ecx
// 0063e1f9  7538                 jne 0x63e233
// 0063e1fb  8b16                 mov edx, dword ptr [esi]
// 0063e1fd  8b4204               mov eax, dword ptr [edx + 4]
// 0063e200  8bce                 mov ecx, esi
// 0063e202  ffd0                 call eax
// 0063e204  8d4e08               lea ecx, [esi + 8]
// 0063e207  83caff               or edx, 0xffffffff
// 0063e20a  f00fc111             lock xadd dword ptr [ecx], edx
// 0063e20e  7523                 jne 0x63e233
// 0063e210  8b06                 mov eax, dword ptr [esi]
// 0063e212  8b5008               mov edx, dword ptr [eax + 8]
// 0063e215  8bce                 mov ecx, esi
// 0063e217  ffd2                 call edx
// 0063e219  5e                   pop esi
// 0063e21a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0063e21e  64890d00000000       mov dword ptr fs:[0], ecx
// 0063e225  83c414               add esp, 0x14
// 0063e228  c20400               ret 4
// 0063e22b  8d4e1c               lea ecx, [esi + 0x1c]
// 0063e22e  e84d8ce1ff           call 0x456e80
// 0063e233  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0063e237  5e                   pop esi
// 0063e238  64890d00000000       mov dword ptr fs:[0], ecx
// 0063e23f  83c414               add esp, 0x14
// 0063e242  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Handle
{
    Control* value;
    void assign(const Handle&);
};

struct Shared
{
    void* value;
    Handle handle;

    ~Shared();
    Shared& operator=(const Shared&);
    void reset();
};

inline Shared::~Shared()
{
    if (handle.value)
    {
        Control* p = handle.value;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

inline Shared& Shared::operator=(const Shared& other)
{
    value = other.value;
    handle.assign(other.handle);
    return *this;
}

extern unsigned char descriptor;
extern "C" void* __stdcall lookup(void*, int, const void*);
extern "C" void* __cdecl convert(void*);
Shared __cdecl makeShared(void*);

struct S
{
    unsigned char padding[28];
    Shared selected;
    void f(void*);
};

void S::f(void* argument)
{
    void* p = lookup(argument, 0, &descriptor);
    if (p)
        selected = makeShared(convert(p));
    else
        selected.reset();
}

// from server: 100% by Yeetserama
// roc 2007-08 004aa1d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 372 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aa1d0
//
// 004aa1d0  6aff                 push -1
// 004aa1d2  682be47300           push 0x73e42b
// 004aa1d7  64a100000000         mov eax, dword ptr fs:[0]
// 004aa1dd  50                   push eax
// 004aa1de  83ec18               sub esp, 0x18
// 004aa1e1  53                   push ebx
// 004aa1e2  56                   push esi
// 004aa1e3  57                   push edi
// 004aa1e4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004aa1e9  33c4                 xor eax, esp
// 004aa1eb  50                   push eax
// 004aa1ec  8d442428             lea eax, [esp + 0x28]
// 004aa1f0  64a300000000         mov dword ptr fs:[0], eax
// 004aa1f6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004aa1fa  85c9                 test ecx, ecx
// 004aa1fc  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004aa204  742b                 je 0x4aa231
// 004aa206  8d442420             lea eax, [esp + 0x20]
// 004aa20a  50                   push eax
// 004aa20b  e8e03ef7ff           call 0x41e0f0
// 004aa210  50                   push eax
// 004aa211  8d4c241c             lea ecx, [esp + 0x1c]
// 004aa215  51                   push ecx
// 004aa216  e82587feff           call 0x492940
// 004aa21b  83c408               add esp, 8
// 004aa21e  8b742414             mov esi, dword ptr [esp + 0x14]
// 004aa222  c744243002000000     mov dword ptr [esp + 0x30], 2
// 004aa22a  bb03000000           mov ebx, 3
// 004aa22f  eb17                 jmp 0x4aa248
// 004aa231  33f6                 xor esi, esi
// 004aa233  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004aa23b  89742414             mov dword ptr [esp + 0x14], esi
// 004aa23f  8d442410             lea eax, [esp + 0x10]
// 004aa243  bb04000000           mov ebx, 4
// 004aa248  8b10                 mov edx, dword ptr [eax]
// 004aa24a  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 004aa24e  8917                 mov dword ptr [edi], edx
// 004aa250  8b4004               mov eax, dword ptr [eax + 4]
// 004aa253  85c0                 test eax, eax
// 004aa255  894704               mov dword ptr [edi + 4], eax
// 004aa258  740c                 je 0x4aa266
// 004aa25a  83c004               add eax, 4
// 004aa25d  b901000000           mov ecx, 1
// 004aa262  f00fc108             lock xadd dword ptr [eax], ecx
// 004aa266  83cb08               or ebx, 8
// 004aa269  f6c304               test bl, 4
// 004aa26c  7435                 je 0x4aa2a3
// 004aa26e  83e3fb               and ebx, 0xfffffffb
// 004aa271  85f6                 test esi, esi
// 004aa273  895c2410             mov dword ptr [esp + 0x10], ebx
// 004aa277  742a                 je 0x4aa2a3
// 004aa279  8d5604               lea edx, [esi + 4]
// 004aa27c  83c8ff               or eax, 0xffffffff
// 004aa27f  f00fc102             lock xadd dword ptr [edx], eax
// 004aa283  751e                 jne 0x4aa2a3
// 004aa285  8b16                 mov edx, dword ptr [esi]
// 004aa287  8b4204               mov eax, dword ptr [edx + 4]
// 004aa28a  8bce                 mov ecx, esi
// 004aa28c  ffd0                 call eax
// 004aa28e  8d4e08               lea ecx, [esi + 8]
// 004aa291  83caff               or edx, 0xffffffff
// 004aa294  f00fc111             lock xadd dword ptr [ecx], edx
// 004aa298  7509                 jne 0x4aa2a3
// 004aa29a  8b06                 mov eax, dword ptr [esi]
// 004aa29c  8b5008               mov edx, dword ptr [eax + 8]
// 004aa29f  8bce                 mov ecx, esi
// 004aa2a1  ffd2                 call edx
// 004aa2a3  f6c302               test bl, 2
// 004aa2a6  c744243001000000     mov dword ptr [esp + 0x30], 1
// 004aa2ae  7439                 je 0x4aa2e9
// 004aa2b0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004aa2b4  83e3fd               and ebx, 0xfffffffd
// 004aa2b7  85f6                 test esi, esi
// 004aa2b9  895c2410             mov dword ptr [esp + 0x10], ebx
// 004aa2bd  742a                 je 0x4aa2e9
// 004aa2bf  8d4604               lea eax, [esi + 4]
// 004aa2c2  83c9ff               or ecx, 0xffffffff
// 004aa2c5  f00fc108             lock xadd dword ptr [eax], ecx
// 004aa2c9  751e                 jne 0x4aa2e9
// 004aa2cb  8b16                 mov edx, dword ptr [esi]
// 004aa2cd  8b4204               mov eax, dword ptr [edx + 4]
// 004aa2d0  8bce                 mov ecx, esi
// 004aa2d2  ffd0                 call eax
// 004aa2d4  8d4e08               lea ecx, [esi + 8]
// 004aa2d7  83caff               or edx, 0xffffffff
// 004aa2da  f00fc111             lock xadd dword ptr [ecx], edx
// 004aa2de  7509                 jne 0x4aa2e9
// 004aa2e0  8b06                 mov eax, dword ptr [esi]
// 004aa2e2  8b5008               mov edx, dword ptr [eax + 8]
// 004aa2e5  8bce                 mov ecx, esi
// 004aa2e7  ffd2                 call edx
// 004aa2e9  f6c301               test bl, 1
// 004aa2ec  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004aa2f4  7439                 je 0x4aa32f
// 004aa2f6  8b742424             mov esi, dword ptr [esp + 0x24]
// 004aa2fa  83e3fe               and ebx, 0xfffffffe
// 004aa2fd  85f6                 test esi, esi
// 004aa2ff  895c2410             mov dword ptr [esp + 0x10], ebx
// 004aa303  742a                 je 0x4aa32f
// 004aa305  8d4604               lea eax, [esi + 4]
// 004aa308  83c9ff               or ecx, 0xffffffff
// 004aa30b  f00fc108             lock xadd dword ptr [eax], ecx
// 004aa30f  751e                 jne 0x4aa32f
// 004aa311  8b16                 mov edx, dword ptr [esi]
// 004aa313  8b4204               mov eax, dword ptr [edx + 4]
// 004aa316  8bce                 mov ecx, esi
// 004aa318  ffd0                 call eax
// 004aa31a  8d4e08               lea ecx, [esi + 8]
// 004aa31d  83caff               or edx, 0xffffffff
// 004aa320  f00fc111             lock xadd dword ptr [ecx], edx
// 004aa324  7509                 jne 0x4aa32f
// 004aa326  8b06                 mov eax, dword ptr [esi]
// 004aa328  8b5008               mov edx, dword ptr [eax + 8]
// 004aa32b  8bce                 mov ecx, esi
// 004aa32d  ffd2                 call edx
// 004aa32f  8bc7                 mov eax, edi
// 004aa331  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004aa335  64890d00000000       mov dword ptr fs:[0], ecx
// 004aa33c  59                   pop ecx
// 004aa33d  5f                   pop edi
// 004aa33e  5e                   pop esi
// 004aa33f  5b                   pop ebx
// 004aa340  83c424               add esp, 0x24
// 004aa343  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX00000d@@YA?AUPtr@1@PAUSource@1@@Z)

namespace ns_ROCX00000d {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct SourcePtr
{
    void* object;
    Control* control;
    ~SourcePtr();
};

struct Ptr
{
    void* object;
    Control* control;

    Ptr();
    Ptr(const Ptr&);
    ~Ptr();
};

__forceinline SourcePtr::~SourcePtr()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

__forceinline Ptr::Ptr() : object(0), control(0)
{
}

__forceinline Ptr::Ptr(const Ptr& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Ptr::~Ptr()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Source
{
    SourcePtr get() throw();
};

Ptr __cdecl convert(const SourcePtr&) throw();

Ptr __cdecl f(Source* source)
{
    return source ? convert(source->get()) : Ptr();
}
}

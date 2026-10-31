// from server: 100% by EspClaude
// roc 2009-06 004c4ba0  unit: RBX::Network::Players::Plugin  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c4ba0
//
// 004c4ba0  6aff                 push -1
// 004c4ba2  68f39b8500           push 0x859bf3
// 004c4ba7  64a100000000         mov eax, dword ptr fs:[0]
// 004c4bad  50                   push eax
// 004c4bae  64892500000000       mov dword ptr fs:[0], esp
// 004c4bb5  51                   push ecx
// 004c4bb6  56                   push esi
// 004c4bb7  8bf1                 mov esi, ecx
// 004c4bb9  57                   push edi
// 004c4bba  89742408             mov dword ptr [esp + 8], esi
// 004c4bbe  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004c4bc6  ff15c0e48900         call dword ptr [0x89e4c0]
// 004c4bcc  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c4bd0  50                   push eax
// 004c4bd1  8d4e1c               lea ecx, [esi + 0x1c]
// 004c4bd4  c644241801           mov byte ptr [esp + 0x18], 1
// 004c4bd9  ff15b4e48900         call dword ptr [0x89e4b4]
// 004c4bdf  8b442424             mov eax, dword ptr [esp + 0x24]
// 004c4be3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c4be7  894e38               mov dword ptr [esi + 0x38], ecx
// 004c4bea  89463c               mov dword ptr [esi + 0x3c], eax
// 004c4bed  85c0                 test eax, eax
// 004c4bef  740c                 je 0x4c4bfd
// 004c4bf1  83c004               add eax, 4
// 004c4bf4  ba01000000           mov edx, 1
// 004c4bf9  f00fc110             lock xadd dword ptr [eax], edx
// 004c4bfd  c7464000000000       mov dword ptr [esi + 0x40], 0
// 004c4c04  c7464400000000       mov dword ptr [esi + 0x44], 0
// 004c4c0b  56                   push esi
// 004c4c0c  c644241804           mov byte ptr [esp + 0x18], 4
// 004c4c11  e8dade1600           call 0x632af0
// 004c4c16  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004c4c1a  83c404               add esp, 4
// 004c4c1d  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004c4c25  85ff                 test edi, edi
// 004c4c27  742a                 je 0x4c4c53
// 004c4c29  8d4704               lea eax, [edi + 4]
// 004c4c2c  83c9ff               or ecx, 0xffffffff
// 004c4c2f  f00fc108             lock xadd dword ptr [eax], ecx
// 004c4c33  751e                 jne 0x4c4c53
// 004c4c35  8b17                 mov edx, dword ptr [edi]
// 004c4c37  8b4204               mov eax, dword ptr [edx + 4]
// 004c4c3a  8bcf                 mov ecx, edi
// 004c4c3c  ffd0                 call eax
// 004c4c3e  8d4f08               lea ecx, [edi + 8]
// 004c4c41  83caff               or edx, 0xffffffff
// 004c4c44  f00fc111             lock xadd dword ptr [ecx], edx
// 004c4c48  7509                 jne 0x4c4c53
// 004c4c4a  8b07                 mov eax, dword ptr [edi]
// 004c4c4c  8b5008               mov edx, dword ptr [eax + 8]
// 004c4c4f  8bcf                 mov ecx, edi
// 004c4c51  ffd2                 call edx
// 004c4c53  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c4c57  5f                   pop edi
// 004c4c58  8bc6                 mov eax, esi
// 004c4c5a  5e                   pop esi
// 004c4c5b  64890d00000000       mov dword ptr fs:[0], ecx
// 004c4c62  83c410               add esp, 0x10
// 004c4c65  c20c00               ret 0xc
// copied from an identical function in another client (function ??0S@ns_ROCX00000d@@QAE@PBDUShared@1@@Z)

namespace ns_ROCX00000d {
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string();
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void (__thiscall *const constructText)(std::string*, const char*);




struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    Shared();
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared() : object(0), control(0) {
}

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared() {
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct S {
    std::string first;
    std::string second;
    Shared owner;
    Shared empty;
    S(const char*, Shared);
};

extern void __cdecl initialize(S*);

S::S(const char* text, Shared value)
    : first(), second(text), owner(value), empty() {
    initialize(this);
}
}

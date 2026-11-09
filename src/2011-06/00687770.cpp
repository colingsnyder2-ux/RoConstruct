// from server: 100% by Yeetserama
// roc 2011-06 00687770  unit: RBX::VHumanoid::?$EventDesc  size: 204 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00687770
//
// 00687770  6aff                 push -1
// 00687772  6831f69e00           push 0x9ef631
// 00687777  64a100000000         mov eax, dword ptr fs:[0]
// 0068777d  50                   push eax
// 0068777e  64892500000000       mov dword ptr fs:[0], esp
// 00687785  83ec44               sub esp, 0x44
// 00687788  56                   push esi
// 00687789  8bf1                 mov esi, ecx
// 0068778b  8b442464             mov eax, dword ptr [esp + 0x64]
// 0068778f  6a00                 push 0
// 00687791  68ecbec000           push 0xc0beec
// 00687796  68f871c000           push 0xc071f8
// 0068779b  6a00                 push 0
// 0068779d  50                   push eax
// 0068779e  c744246400000000     mov dword ptr [esp + 0x64], 0
// 006877a6  e83f3b1800           call 0x80b2ea
// 006877ab  83c414               add esp, 0x14
// 006877ae  85c0                 test eax, eax
// 006877b0  7531                 jne 0x6877e3
// 006877b2  68e8eda900           push 0xa9ede8
// 006877b7  8d4c2408             lea ecx, [esp + 8]
// 006877bb  ff15c404a400         call dword ptr [0xa404c4]
// 006877c1  8d4c2404             lea ecx, [esp + 4]
// 006877c5  51                   push ecx
// 006877c6  8d4c2424             lea ecx, [esp + 0x24]
// 006877ca  c644245401           mov byte ptr [esp + 0x54], 1
// 006877cf  e87c31d8ff           call 0x40a950
// 006877d4  682091b800           push 0xb89120
// 006877d9  8d542424             lea edx, [esp + 0x24]
// 006877dd  52                   push edx
// 006877de  e8c9381800           call 0x80b0ac
// 006877e3  50                   push eax
// 006877e4  8d44245c             lea eax, [esp + 0x5c]
// 006877e8  50                   push eax
// 006877e9  8bce                 mov ecx, esi
// 006877eb  e8e0f2ffff           call 0x686ad0
// 006877f0  8b742468             mov esi, dword ptr [esp + 0x68]
// 006877f4  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 006877fc  85f6                 test esi, esi
// 006877fe  742a                 je 0x68782a
// 00687800  8d4e04               lea ecx, [esi + 4]
// 00687803  83caff               or edx, 0xffffffff
// 00687806  f00fc111             lock xadd dword ptr [ecx], edx
// 0068780a  751e                 jne 0x68782a
// 0068780c  8b06                 mov eax, dword ptr [esi]
// 0068780e  8b5004               mov edx, dword ptr [eax + 4]
// 00687811  8bce                 mov ecx, esi
// 00687813  ffd2                 call edx
// 00687815  8d4608               lea eax, [esi + 8]
// 00687818  83c9ff               or ecx, 0xffffffff
// 0068781b  f00fc108             lock xadd dword ptr [eax], ecx
// 0068781f  7509                 jne 0x68782a
// 00687821  8b16                 mov edx, dword ptr [esi]
// 00687823  8b4208               mov eax, dword ptr [edx + 8]
// 00687826  8bce                 mov ecx, esi
// 00687828  ffd0                 call eax
// 0068782a  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0068782e  5e                   pop esi
// 0068782f  64890d00000000       mov dword ptr fs:[0], ecx
// 00687836  83c450               add esp, 0x50
// 00687839  c21400               ret 0x14
// copied from an identical function in another client (function ?invoke@S@ns_ROCX000002@@QAEXUFirst@2@UShared@2@@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
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

struct Shared {
    void* object;
    Control* control;

    ~Shared()
    {
        if (control)
            control->release();
    }
};

struct First {
    unsigned int data[3];
};

namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        char allocatorStorage[4];
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;
    public:
        __declspec(dllimport) basic_string(const T*);
        __declspec(dllimport) ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct ArgumentError {
    char storage[40];
    ArgumentError(const String&);
    ~ArgumentError();
};

extern unsigned char instanceType;
extern unsigned char partType;
extern unsigned char exceptionType;

extern "C" void* __cdecl castObject(void*, int, const void*, const void*, int);
extern "C" __declspec(noreturn) void __cdecl throwObject(void*, const void*);

struct S {
    void invoke(First first, Shared part);
    void dispatch(First*, void*);
};

void S::invoke(First first, Shared part)
{
    void* value = castObject(part.object, 0, &instanceType, &partType, 0);
    if (!value) {
        String message("Argument error: A Part is required");
        ArgumentError error(message);
        throwObject(&error, &exceptionType);
    }
    dispatch(&first, value);
}
}

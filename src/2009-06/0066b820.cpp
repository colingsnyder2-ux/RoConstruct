// from server: 100% by EspClaude
// roc 2009-06 0066b820  unit: RBX::VPartInstance::?$FilteredSelection  size: 204 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066b820
//
// 0066b820  6aff                 push -1
// 0066b822  68f1c58600           push 0x86c5f1
// 0066b827  64a100000000         mov eax, dword ptr fs:[0]
// 0066b82d  50                   push eax
// 0066b82e  64892500000000       mov dword ptr fs:[0], esp
// 0066b835  83ec44               sub esp, 0x44
// 0066b838  56                   push esi
// 0066b839  8bf1                 mov esi, ecx
// 0066b83b  8b442464             mov eax, dword ptr [esp + 0x64]
// 0066b83f  6a00                 push 0
// 0066b841  6850f99d00           push 0x9df950
// 0066b846  6840be9d00           push 0x9dbe40
// 0066b84b  6a00                 push 0
// 0066b84d  50                   push eax
// 0066b84e  c744246400000000     mov dword ptr [esp + 0x64], 0
// 0066b856  e81fe40a00           call 0x719c7a
// 0066b85b  83c414               add esp, 0x14
// 0066b85e  85c0                 test eax, eax
// 0066b860  7531                 jne 0x66b893
// 0066b862  6860308e00           push 0x8e3060
// 0066b867  8d4c2408             lea ecx, [esp + 8]
// 0066b86b  ff15b4e48900         call dword ptr [0x89e4b4]
// 0066b871  8d4c2404             lea ecx, [esp + 4]
// 0066b875  51                   push ecx
// 0066b876  8d4c2424             lea ecx, [esp + 0x24]
// 0066b87a  c644245401           mov byte ptr [esp + 0x54], 1
// 0066b87f  e88cdbd9ff           call 0x409410
// 0066b884  6850a79700           push 0x97a750
// 0066b889  8d542424             lea edx, [esp + 0x24]
// 0066b88d  52                   push edx
// 0066b88e  e8b7e10a00           call 0x719a4a
// 0066b893  50                   push eax
// 0066b894  8d44245c             lea eax, [esp + 0x5c]
// 0066b898  50                   push eax
// 0066b899  8bce                 mov ecx, esi
// 0066b89b  e8b0f5ffff           call 0x66ae50
// 0066b8a0  8b742468             mov esi, dword ptr [esp + 0x68]
// 0066b8a4  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0066b8ac  85f6                 test esi, esi
// 0066b8ae  742a                 je 0x66b8da
// 0066b8b0  8d4e04               lea ecx, [esi + 4]
// 0066b8b3  83caff               or edx, 0xffffffff
// 0066b8b6  f00fc111             lock xadd dword ptr [ecx], edx
// 0066b8ba  751e                 jne 0x66b8da
// 0066b8bc  8b06                 mov eax, dword ptr [esi]
// 0066b8be  8b5004               mov edx, dword ptr [eax + 4]
// 0066b8c1  8bce                 mov ecx, esi
// 0066b8c3  ffd2                 call edx
// 0066b8c5  8d4608               lea eax, [esi + 8]
// 0066b8c8  83c9ff               or ecx, 0xffffffff
// 0066b8cb  f00fc108             lock xadd dword ptr [eax], ecx
// 0066b8cf  7509                 jne 0x66b8da
// 0066b8d1  8b16                 mov edx, dword ptr [esi]
// 0066b8d3  8b4208               mov eax, dword ptr [edx + 8]
// 0066b8d6  8bce                 mov ecx, esi
// 0066b8d8  ffd0                 call eax
// 0066b8da  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0066b8de  5e                   pop esi
// 0066b8df  64890d00000000       mov dword ptr fs:[0], ecx
// 0066b8e6  83c450               add esp, 0x50
// 0066b8e9  c21400               ret 0x14
// copied from an identical function in another client (function ?invoke@S@ns_ROCX00001e@@QAEXUFirst@2@UShared@2@@Z)

namespace ns_ROCX00001e {
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

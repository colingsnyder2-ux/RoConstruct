// from server: 100% by EspClaude
// roc 2009-06 00663520  unit: RBX::$00::?$SurfaceDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663520
//
// 00663520  6aff                 push -1
// 00663522  68b2db8500           push 0x85dbb2
// 00663527  64a100000000         mov eax, dword ptr fs:[0]
// 0066352d  50                   push eax
// 0066352e  64892500000000       mov dword ptr fs:[0], esp
// 00663535  83ec44               sub esp, 0x44
// 00663538  68941d8e00           push 0x8e1d94
// 0066353d  8d4c2404             lea ecx, [esp + 4]
// 00663541  ff15b4e48900         call dword ptr [0x89e4b4]
// 00663547  8d4c241c             lea ecx, [esp + 0x1c]
// 0066354b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00663553  ff15b8e98900         call dword ptr [0x89e9b8]
// 00663559  8d0424               lea eax, [esp]
// 0066355c  50                   push eax
// 0066355d  8d4c242c             lea ecx, [esp + 0x2c]
// 00663561  c644245001           mov byte ptr [esp + 0x50], 1
// 00663566  c74424205cd28a00     mov dword ptr [esp + 0x20], 0x8ad25c
// 0066356e  ff15b8e48900         call dword ptr [0x89e4b8]
// 00663574  6850a79700           push 0x97a750
// 00663579  8d4c2420             lea ecx, [esp + 0x20]
// 0066357d  51                   push ecx
// 0066357e  c644245400           mov byte ptr [esp + 0x54], 0
// 00663583  e8c2640b00           call 0x719a4a
// copied from an identical function in another client (function ?f@S_func_005eed50@ns_ROCX000007@@QAEXXZ)

namespace ns_ROCX000007 {
typedef void (__thiscall *ExceptionCtor)(void *);
typedef void (__thiscall *StringCtor)(void *, const char *);
typedef void (__thiscall *StringCopyCtor)(void *, const void *);

extern ExceptionCtor exceptionCtor;
extern StringCtor stringCtor;
extern StringCopyCtor stringCopyCtor;
extern const char runtimeErrorVtable[];

namespace std {
    class exception {
    protected:
        const void *vtable;
        char *message;
        int owned;
    public:
        exception();
        ~exception();
        const char *what() const;
    };

    class string {
        char storage[28];
    public:
        string(const char *);
        string(const string &);
        ~string();
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string &);
        ~runtime_error();
        const char *what() const;
    };

    __forceinline exception::exception()
    {
        exceptionCtor(this);
    }

    __forceinline string::string(const char *text)
    {
        stringCtor(this, text);
    }

    __forceinline string::string(const string &other)
    {
        stringCopyCtor(this, &other);
    }

    __forceinline runtime_error::runtime_error(const string &text)
        : exception(), message((vtable = runtimeErrorVtable, text))
    {
    }
}

struct S_func_005eed50 {
    void f();
};

void S_func_005eed50::f()
{
    throw std::runtime_error(
        std::string("SurfaceDescriptor::get not implemented"));
}
}

// from server: 100% by Yeetserama
// roc 2011-06 0071f850  unit: RBX::$00::?$SurfaceDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0071f850
//
// 0071f850  6aff                 push -1
// 0071f852  68221b9d00           push 0x9d1b22
// 0071f857  64a100000000         mov eax, dword ptr fs:[0]
// 0071f85d  50                   push eax
// 0071f85e  64892500000000       mov dword ptr fs:[0], esp
// 0071f865  83ec44               sub esp, 0x44
// 0071f868  68741cab00           push 0xab1c74
// 0071f86d  8d4c2404             lea ecx, [esp + 4]
// 0071f871  ff15c404a400         call dword ptr [0xa404c4]
// 0071f877  8d4c241c             lea ecx, [esp + 0x1c]
// 0071f87b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0071f883  ff15600aa400         call dword ptr [0xa40a60]
// 0071f889  8d0424               lea eax, [esp]
// 0071f88c  50                   push eax
// 0071f88d  8d4c242c             lea ecx, [esp + 0x2c]
// 0071f891  c644245001           mov byte ptr [esp + 0x50], 1
// 0071f896  c744242000bfa500     mov dword ptr [esp + 0x20], 0xa5bf00
// 0071f89e  ff15c804a400         call dword ptr [0xa404c8]
// 0071f8a4  682091b800           push 0xb89120
// 0071f8a9  8d4c2420             lea ecx, [esp + 0x20]
// 0071f8ad  51                   push ecx
// 0071f8ae  c644245400           mov byte ptr [esp + 0x54], 0
// 0071f8b3  e8f4b70e00           call 0x80b0ac
// copied from an identical function in another client (function ?f@S_func_005eed50@ns_ROCX000010@@QAEXXZ)

namespace ns_ROCX000010 {
// from server: 100% by tester
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

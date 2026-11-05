// from server: 100% by Yeetserama
// roc 2011-06 0071f8f0  unit: RBX::$00::?$SurfaceDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0071f8f0
//
// 0071f8f0  6aff                 push -1
// 0071f8f2  68221b9d00           push 0x9d1b22
// 0071f8f7  64a100000000         mov eax, dword ptr fs:[0]
// 0071f8fd  50                   push eax
// 0071f8fe  64892500000000       mov dword ptr fs:[0], esp
// 0071f905  83ec44               sub esp, 0x44
// 0071f908  684c1cab00           push 0xab1c4c
// 0071f90d  8d4c2404             lea ecx, [esp + 4]
// 0071f911  ff15c404a400         call dword ptr [0xa404c4]
// 0071f917  8d4c241c             lea ecx, [esp + 0x1c]
// 0071f91b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0071f923  ff15600aa400         call dword ptr [0xa40a60]
// 0071f929  8d0424               lea eax, [esp]
// 0071f92c  50                   push eax
// 0071f92d  8d4c242c             lea ecx, [esp + 0x2c]
// 0071f931  c644245001           mov byte ptr [esp + 0x50], 1
// 0071f936  c744242000bfa500     mov dword ptr [esp + 0x20], 0xa5bf00
// 0071f93e  ff15c804a400         call dword ptr [0xa404c8]
// 0071f944  682091b800           push 0xb89120
// 0071f949  8d4c2420             lea ecx, [esp + 0x20]
// 0071f94d  51                   push ecx
// 0071f94e  c644245400           mov byte ptr [esp + 0x54], 0
// 0071f953  e854b70e00           call 0x80b0ac
// copied from an identical function in another client (function ?f@S_func_005eed50@ns_ROCX00000e@@QAEXXZ)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
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
        std::string("SurfaceDescriptor::set not implemented"));
}
}

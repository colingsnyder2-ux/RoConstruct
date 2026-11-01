// from server: 100% by Yeetserama
// roc 2010-06 0069dbf0  unit: RBX::$00::?$SurfaceDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069dbf0
//
// 0069dbf0  6aff                 push -1
// 0069dbf2  68e22f9a00           push 0x9a2fe2
// 0069dbf7  64a100000000         mov eax, dword ptr fs:[0]
// 0069dbfd  50                   push eax
// 0069dbfe  64892500000000       mov dword ptr fs:[0], esp
// 0069dc05  83ec44               sub esp, 0x44
// 0069dc08  68c8fda300           push 0xa3fdc8
// 0069dc0d  8d4c2404             lea ecx, [esp + 4]
// 0069dc11  ff1510a49e00         call dword ptr [0x9ea410]
// 0069dc17  8d4c241c             lea ecx, [esp + 0x1c]
// 0069dc1b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0069dc23  ff1518a99e00         call dword ptr [0x9ea918]
// 0069dc29  8d0424               lea eax, [esp]
// 0069dc2c  50                   push eax
// 0069dc2d  8d4c242c             lea ecx, [esp + 0x2c]
// 0069dc31  c644245001           mov byte ptr [esp + 0x50], 1
// 0069dc36  c74424203009a000     mov dword ptr [esp + 0x20], 0xa00930
// 0069dc3e  ff150ca49e00         call dword ptr [0x9ea40c]
// 0069dc44  687430b000           push 0xb03074
// 0069dc49  8d4c2420             lea ecx, [esp + 0x20]
// 0069dc4d  51                   push ecx
// 0069dc4e  c644245400           mov byte ptr [esp + 0x54], 0
// 0069dc53  e85aad1000           call 0x7a89b2
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

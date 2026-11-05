// from server: 100% by Yeetserama
// roc 2010-06 0069dc60  unit: RBX::$00::?$SurfaceDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069dc60
//
// 0069dc60  6aff                 push -1
// 0069dc62  68e22f9a00           push 0x9a2fe2
// 0069dc67  64a100000000         mov eax, dword ptr fs:[0]
// 0069dc6d  50                   push eax
// 0069dc6e  64892500000000       mov dword ptr fs:[0], esp
// 0069dc75  83ec44               sub esp, 0x44
// 0069dc78  68f0fda300           push 0xa3fdf0
// 0069dc7d  8d4c2404             lea ecx, [esp + 4]
// 0069dc81  ff1510a49e00         call dword ptr [0x9ea410]
// 0069dc87  8d4c241c             lea ecx, [esp + 0x1c]
// 0069dc8b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0069dc93  ff1518a99e00         call dword ptr [0x9ea918]
// 0069dc99  8d0424               lea eax, [esp]
// 0069dc9c  50                   push eax
// 0069dc9d  8d4c242c             lea ecx, [esp + 0x2c]
// 0069dca1  c644245001           mov byte ptr [esp + 0x50], 1
// 0069dca6  c74424203009a000     mov dword ptr [esp + 0x20], 0xa00930
// 0069dcae  ff150ca49e00         call dword ptr [0x9ea40c]
// 0069dcb4  687430b000           push 0xb03074
// 0069dcb9  8d4c2420             lea ecx, [esp + 0x20]
// 0069dcbd  51                   push ecx
// 0069dcbe  c644245400           mov byte ptr [esp + 0x54], 0
// 0069dcc3  e8eaac1000           call 0x7a89b2
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

// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 004eb590  unit: Ogre::RbxSubEntity  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004eb590
//
// 004eb590  6aff                 push -1
// 004eb592  684269aa00           push 0xaa6942
// 004eb597  64a100000000         mov eax, dword ptr fs:[0]
// 004eb59d  50                   push eax
// 004eb59e  64892500000000       mov dword ptr fs:[0], esp
// 004eb5a5  83ec44               sub esp, 0x44
// 004eb5a8  68589fb600           push 0xb69f58
// 004eb5ad  8d4c2404             lea ecx, [esp + 4]
// 004eb5b1  ff154826b200         call dword ptr [0xb22648]
// 004eb5b7  8d4c241c             lea ecx, [esp + 0x1c]
// 004eb5bb  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 004eb5c3  ff15dc29b200         call dword ptr [0xb229dc]
// 004eb5c9  8d0424               lea eax, [esp]
// 004eb5cc  50                   push eax
// 004eb5cd  8d4c242c             lea ecx, [esp + 0x2c]
// 004eb5d1  c644245001           mov byte ptr [esp + 0x50], 1
// 004eb5d6  c74424204c3cb400     mov dword ptr [esp + 0x20], 0xb43c4c
// 004eb5de  ff154426b200         call dword ptr [0xb22644]
// 004eb5e4  686c80cd00           push 0xcd806c
// 004eb5e9  8d4c2420             lea ecx, [esp + 0x20]
// 004eb5ed  51                   push ecx
// 004eb5ee  c644245400           mov byte ptr [esp + 0x54], 0
// 004eb5f3  e84c7b4900           call 0x983144

// from server: 100% by Xemicl
// roc 2012-06 008255b0  unit: RBX::$00::?$SurfaceDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008255b0
//
// 008255b0  6aff                 push -1
// 008255b2  684269aa00           push 0xaa6942
// 008255b7  64a100000000         mov eax, dword ptr fs:[0]
// 008255bd  50                   push eax
// 008255be  64892500000000       mov dword ptr fs:[0], esp
// 008255c5  83ec44               sub esp, 0x44
// 008255c8  6884cfbc00           push 0xbccf84
// 008255cd  8d4c2404             lea ecx, [esp + 4]
// 008255d1  ff154826b200         call dword ptr [0xb22648]
// 008255d7  8d4c241c             lea ecx, [esp + 0x1c]
// 008255db  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 008255e3  ff15dc29b200         call dword ptr [0xb229dc]
// 008255e9  8d0424               lea eax, [esp]
// 008255ec  50                   push eax
// 008255ed  8d4c242c             lea ecx, [esp + 0x2c]
// 008255f1  c644245001           mov byte ptr [esp + 0x50], 1
// 008255f6  c74424204c3cb400     mov dword ptr [esp + 0x20], 0xb43c4c
// 008255fe  ff154426b200         call dword ptr [0xb22644]
// 00825604  686c80cd00           push 0xcd806c
// 00825609  8d4c2420             lea ecx, [esp + 0x20]
// 0082560d  51                   push ecx
// 0082560e  c644245400           mov byte ptr [esp + 0x54], 0
// 00825613  e82cdb1500           call 0x983144
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
        std::string("can't modify this library"));
}
}
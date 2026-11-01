// from server: 94% by EspClaude
// from server: 100% by tester
// roc 2008-06 00414960  unit: CopyVerb  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00414960
//
// 00414960  6aff                 push -1
// 00414962  683b467d00           push 0x7d463b
// 00414967  64a100000000         mov eax, dword ptr fs:[0]
// 0041496d  50                   push eax
// 0041496e  64892500000000       mov dword ptr fs:[0], esp
// 00414975  83ec08               sub esp, 8
// 00414978  c7042400000000       mov dword ptr [esp], 0
// 0041497f  68a4020000           push 0x2a4
// 00414984  c644240400           mov byte ptr [esp + 4], 0
// 00414989  ff15b0288000         call dword ptr [0x8028b0]
// 0041498f  83c404               add esp, 4
// 00414992  89442404             mov dword ptr [esp + 4], eax
// 00414996  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041499e  85c0                 test eax, eax
// 004149a0  740b                 je 0x4149ad
// 004149a2  6a01                 push 1
// 004149a4  8bc8                 mov ecx, eax
// 004149a6  e8850c1700           call 0x585630
// 004149ab  eb02                 jmp 0x4149af
// 004149ad  33c0                 xor eax, eax
// 004149af  8b0c24               mov ecx, dword ptr [esp]
// 004149b2  56                   push esi
// 004149b3  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004149b7  51                   push ecx
// 004149b8  50                   push eax
// 004149b9  8bce                 mov ecx, esi
// 004149bb  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004149c3  e8e8feffff           call 0x4148b0
// 004149c8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004149cc  8bc6                 mov eax, esi
// 004149ce  5e                   pop esi
// 004149cf  64890d00000000       mov dword ptr fs:[0], ecx
// 004149d6  83c414               add esp, 0x14
// 004149d9  c3                   ret 

#include <stdlib.h>

namespace boost {
template<class T>
class shared_ptr
{
    T* px;
    void* pn;
public:
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}

namespace RBX {
template<class T>
class Creatable
{
public:
    class Deleter
    {
    public:
        void operator()(T* instance);
    };

    template<class U>
    static boost::shared_ptr<U> create()
    {
        return boost::shared_ptr<U>(new U(), Deleter());
    }

protected:
    static void* operator new(size_t size) { return malloc(size); }
};

class Instance : public Creatable<Instance>
{
public:
    virtual ~Instance();
};

class IModelModifier { public: virtual ~IModelModifier(); };

class ModelInstance : public Instance, public virtual IModelModifier
{
    char data[0x2a4 - 12];
public:
    ModelInstance();
};

template boost::shared_ptr<ModelInstance> Creatable<Instance>::create<ModelInstance>();
}

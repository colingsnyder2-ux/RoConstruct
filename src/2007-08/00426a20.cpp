// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00426a20  unit: RBX::Reflection::Metadata::Item  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426a20
// 00426a20  6aff                 push -1
// 00426a22  682ba57400           push 0x74a52b
// 00426a27  64a100000000         mov eax, dword ptr fs:[0]
// 00426a2d  50                   push eax
// 00426a2e  83ec08               sub esp, 8
// 00426a31  56                   push esi
// 00426a32  a188518b00           mov eax, dword ptr [0x8b5188]
// 00426a37  33c4                 xor eax, esp
// 00426a39  50                   push eax
// 00426a3a  8d442410             lea eax, [esp + 0x10]
// 00426a3e  64a300000000         mov dword ptr fs:[0], eax
// 00426a44  c744240800000000     mov dword ptr [esp + 8], 0
// 00426a4c  68e8000000           push 0xe8
// 00426a51  c644240c00           mov byte ptr [esp + 0xc], 0
// 00426a56  ff15d0e67700         call dword ptr [0x77e6d0]
// 00426a5c  83c404               add esp, 4
// 00426a5f  8944240c             mov dword ptr [esp + 0xc], eax
// 00426a63  85c0                 test eax, eax
// 00426a65  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00426a6d  7409                 je 0x426a78
// 00426a6f  8bc8                 mov ecx, eax
// 00426a71  e8fafbffff           call 0x426670
// 00426a76  eb02                 jmp 0x426a7a
// 00426a78  33c0                 xor eax, eax
// 00426a7a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00426a7e  8b742420             mov esi, dword ptr [esp + 0x20]
// 00426a82  51                   push ecx
// 00426a83  50                   push eax
// 00426a84  8bce                 mov ecx, esi
// 00426a86  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00426a8e  e8ddddffff           call 0x424870
// 00426a93  8bc6                 mov eax, esi
// 00426a95  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00426a99  64890d00000000       mov dword ptr fs:[0], ecx
// 00426aa0  59                   pop ecx
// 00426aa1  5e                   pop esi
// 00426aa2  83c414               add esp, 0x14
// 00426aa5  c3                   ret 

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
namespace Reflection {
class Item : public Instance
{
    char data[0xe8 - 4];
public:
    Item();
};
}
template boost::shared_ptr<Reflection::Item> Creatable<Instance>::create<Reflection::Item>();
}

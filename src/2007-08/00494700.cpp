// from server: 100% by Yeetserama
// roc 2007-08 00407620  unit: boost::detail::sp_counted_base  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00407620
//
// 00407620  6aff                 push -1
// 00407622  682ba57400           push 0x74a52b
// 00407627  64a100000000         mov eax, dword ptr fs:[0]
// 0040762d  50                   push eax
// 0040762e  83ec08               sub esp, 8
// 00407631  56                   push esi
// 00407632  a188518b00           mov eax, dword ptr [0x8b5188]
// 00407637  33c4                 xor eax, esp
// 00407639  50                   push eax
// 0040763a  8d442410             lea eax, [esp + 0x10]
// 0040763e  64a300000000         mov dword ptr fs:[0], eax
// 00407644  c744240800000000     mov dword ptr [esp + 8], 0
// 0040764c  68b0010000           push 0x128
// 00407651  c644240c00           mov byte ptr [esp + 0xc], 0
// 00407656  ff15d0e67700         call dword ptr [0x77e6d0]
// 0040765c  83c404               add esp, 4
// 0040765f  8944240c             mov dword ptr [esp + 0xc], eax
// 00407663  85c0                 test eax, eax
// 00407665  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040766d  7409                 je 0x407678
// 0040766f  8bc8                 mov ecx, eax
// 00407671  e8aa7e1200           call 0x52f520
// 00407676  eb02                 jmp 0x40767a
// 00407678  33c0                 xor eax, eax
// 0040767a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040767e  8b742420             mov esi, dword ptr [esp + 0x20]
// 00407682  51                   push ecx
// 00407683  50                   push eax
// 00407684  8bce                 mov ecx, esi
// 00407686  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0040768e  e8ddfeffff           call 0x407570
// 00407693  8bc6                 mov eax, esi
// 00407695  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00407699  64890d00000000       mov dword ptr fs:[0], ecx
// 004076a0  59                   pop ecx
// 004076a1  5e                   pop esi
// 004076a2  83c414               add esp, 0x14
// 004076a5  c3                   ret 
// copied from an identical function in another client (function ??$create@VPlayers@Network@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VPlayers@Network@RBX@@@boost@@XZ)

// from server: 100% by tester
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
namespace Network {
class Players : public Instance
{
    char data[0x128 - 4];
public:
    Players();
};
}
template boost::shared_ptr<Network::Players> Creatable<Instance>::create<Network::Players>();
}
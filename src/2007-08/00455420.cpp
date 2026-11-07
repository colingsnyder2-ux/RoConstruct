// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 00455420  unit: RBX::NullController  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00455420
//
// 00455420  6aff                 push -1
// 00455422  682ba57400           push 0x74a52b
// 00455427  64a100000000         mov eax, dword ptr fs:[0]
// 0045542d  50                   push eax
// 0045542e  83ec08               sub esp, 8
// 00455431  56                   push esi
// 00455432  a188518b00           mov eax, dword ptr [0x8b5188]
// 00455437  33c4                 xor eax, esp
// 00455439  50                   push eax
// 0045543a  8d442410             lea eax, [esp + 0x10]
// 0045543e  64a300000000         mov dword ptr fs:[0], eax
// 00455444  c744240800000000     mov dword ptr [esp + 8], 0
// 0045544c  68e8000000           push 0xe8
// 00455451  c644240c00           mov byte ptr [esp + 0xc], 0
// 00455456  ff15d0e67700         call dword ptr [0x77e6d0]
// 0045545c  83c404               add esp, 4
// 0045545f  8944240c             mov dword ptr [esp + 0xc], eax
// 00455463  85c0                 test eax, eax
// 00455465  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045546d  7409                 je 0x455478
// 0045546f  8bc8                 mov ecx, eax
// 00455471  e83affffff           call 0x4553b0
// 00455476  eb02                 jmp 0x45547a
// 00455478  33c0                 xor eax, eax
// 0045547a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045547e  8b742420             mov esi, dword ptr [esp + 0x20]
// 00455482  51                   push ecx
// 00455483  50                   push eax
// 00455484  8bce                 mov ecx, esi
// 00455486  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0045548e  e80deaffff           call 0x453ea0
// 00455493  8bc6                 mov eax, esi
// 00455495  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00455499  64890d00000000       mov dword ptr fs:[0], ecx
// 004554a0  59                   pop ecx
// 004554a1  5e                   pop esi
// 004554a2  83c414               add esp, 0x14
// 004554a5  c3                   ret 

// from server: 100% by tester
// roc 2008-06 00458590  unit: RBX::VInstance::?$NonFactoryProduct  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00458590
//
// 00458590  6aff                 push -1
// 00458592  683b467d00           push 0x7d463b
// 00458597  64a100000000         mov eax, dword ptr fs:[0]
// 0045859d  50                   push eax
// 0045859e  64892500000000       mov dword ptr fs:[0], esp
// 004585a5  83ec08               sub esp, 8
// 004585a8  c7042400000000       mov dword ptr [esp], 0
// 004585af  6830010000           push 0x130
// 004585b4  c644240400           mov byte ptr [esp + 4], 0
// 004585b9  ff15b0288000         call dword ptr [0x8028b0]
// 004585bf  83c404               add esp, 4
// 004585c2  89442404             mov dword ptr [esp + 4], eax
// 004585c6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004585ce  85c0                 test eax, eax
// 004585d0  7409                 je 0x4585db
// 004585d2  8bc8                 mov ecx, eax
// 004585d4  e847ffffff           call 0x458520
// 004585d9  eb02                 jmp 0x4585dd
// 004585db  33c0                 xor eax, eax
// 004585dd  8b0c24               mov ecx, dword ptr [esp]
// 004585e0  56                   push esi
// 004585e1  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004585e5  51                   push ecx
// 004585e6  50                   push eax
// 004585e7  8bce                 mov ecx, esi
// 004585e9  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004585f1  e81ae9ffff           call 0x456f10
// 004585f6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004585fa  8bc6                 mov eax, esi
// 004585fc  5e                   pop esi
// 004585fd  64890d00000000       mov dword ptr fs:[0], ecx
// 00458604  83c414               add esp, 0x14
// 00458607  c3                   ret 

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

class GlobalSettings : public Instance
{
    char data[0xe8 - 4];
public:
    GlobalSettings();
};

template boost::shared_ptr<GlobalSettings> Creatable<Instance>::create<GlobalSettings>();
}

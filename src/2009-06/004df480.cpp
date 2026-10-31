// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a83e0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a83e0
//
// 004a83e0  64a100000000         mov eax, dword ptr fs:[0]
// 004a83e6  6aff                 push -1
// 004a83e8  6809e77c00           push 0x7ce709
// 004a83ed  50                   push eax
// 004a83ee  64892500000000       mov dword ptr fs:[0], esp
// 004a83f5  83ec1c               sub esp, 0x1c
// 004a83f8  56                   push esi
// 004a83f9  8bf1                 mov esi, ecx
// 004a83fb  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004a83ff  8b4104               mov eax, dword ptr [ecx + 4]
// 004a8402  85c0                 test eax, eax
// 004a8404  7405                 je 0x4a840b
// 004a8406  83c0ec               add eax, -0x14
// 004a8409  eb02                 jmp 0x4a840d
// 004a840b  33c0                 xor eax, eax
// 004a840d  8b09                 mov ecx, dword ptr [ecx]
// 004a840f  85c0                 test eax, eax
// 004a8411  7405                 je 0x4a8418
// 004a8413  83c014               add eax, 0x14
// 004a8416  eb02                 jmp 0x4a841a
// 004a8418  33c0                 xor eax, eax
// 004a841a  8b11                 mov edx, dword ptr [ecx]
// 004a841c  8b521c               mov edx, dword ptr [edx + 0x1c]
// 004a841f  50                   push eax
// 004a8420  8d442408             lea eax, [esp + 8]
// 004a8424  50                   push eax
// 004a8425  ffd2                 call edx
// 004a8427  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004a842b  8d442404             lea eax, [esp + 4]
// 004a842f  50                   push eax
// 004a8430  51                   push ecx
// 004a8431  8bce                 mov ecx, esi
// 004a8433  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004a843b  e8e0f9ffff           call 0x4a7e20
// 004a8440  8d4c2404             lea ecx, [esp + 4]
// 004a8444  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004a844c  ff1568248000         call dword ptr [0x802468]
// 004a8452  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a8456  5e                   pop esi
// 004a8457  64890d00000000       mov dword ptr fs:[0], ecx
// 004a845e  83c428               add esp, 0x28
// 004a8461  c20800               ret 8

extern "C" void (__thiscall *destroy_string)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> struct allocator;

    template<class C, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::~basic_string()
    {
        destroy_string(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Prefix {
    char storage[20];
};

struct Base {
    int storage;
};

struct Derived : Prefix, Base {
};

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual String get(Base*);
};

struct Argument {
    Object* object;
    Base* value;
};

struct S {
    void apply(int, const String&);
    void f(const Argument*, int);
};

void S::f(const Argument* argument, int value)
{
    Derived* derived = static_cast<Derived*>(argument->value);
    Object* object = reinterpret_cast<const volatile Argument*>(argument)->object;
    String text = object->get(static_cast<Base*>(derived));
    apply(value, text);
}

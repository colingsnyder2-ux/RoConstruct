// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Constructor analog for 00551b30: base ctor 00551bf0, 4-byte smart-pointer
// members (default ctor 004f0810) at 0x30/0x40/0x44, trivial member (007188c0)
// at 0x48, and std::string::operator= on the base's string at +0xc.
#include <string>

template<class T>
class Ref {
    T* pointer;
public:
    Ref();
    ~Ref();
};

class Empty {
public:
    Empty();
};

class Base {
public:
    Base();
    virtual ~Base();
    char header[8];
    std::string name;
    char tail[0x30 - 0x0c - sizeof(std::string)];
};

class A;
class B;
class C;

class Derived : public Base {
public:
    Derived(int value, const std::string& label, bool flag);
    virtual ~Derived();
    Ref<A> first;
    bool dirty;
    int value;
    bool flag;
    Ref<B> second;
    Ref<C> third;
    Empty empty;
};

Derived::Derived(int value, const std::string& label, bool flag)
    : dirty(false), value(value), flag(flag)
{
    name = label;
}

// from server: 100% by king_originala
extern "C" void (__thiscall* string_destroy)(void*);

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Allocator>
class basic_string {
    unsigned char storage[32];
public:
    ~basic_string();
};

template<class T, class Traits, class Allocator>
__forceinline basic_string<T, Traits, Allocator>::~basic_string()
{
    string_destroy(this);
}

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};

class ServiceProvider : public Instance {
public:
    ServiceProvider* finish();
};
}

RBX::ServiceProvider* __cdecl func_005a3330(RBX::Instance*);

struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual std::string get();
};

struct Destination {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void set(int, const std::string&);
};

struct S : RBX::Instance {
    unsigned char padding[0x2a8];
    Source* source;
    void f(int);
};

void S::f(int value)
{
    RBX::ServiceProvider* provider = func_005a3330(this);
    Destination* destination =
        *(Destination**)((unsigned char*)provider + 0x130);

    if (destination)
        destination->set(value, source->get());
}

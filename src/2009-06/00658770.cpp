// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
class P0 { public: virtual ~P0(); char p[0x10]; };
class P1 { public: virtual ~P1(); };
class P2 { public: virtual ~P2(); int p; };
class P3 { public: virtual ~P3(); char p[0x68]; };
class Base : public P0, public P1, public P2, public P3 {
public:
    Base();
    virtual ~Base();
};
class Item {
public:
    static long count;
    void* a;
    void* b;
    Item() { InterlockedIncrement(&count); a = 0; b = 0; }
    virtual ~Item();
};
class Derived : public Base, public Item {
public:
    Derived();
    virtual ~Derived();
};
Derived::Derived()
{
}

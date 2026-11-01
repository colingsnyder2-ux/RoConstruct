// from server: 100% by king_originala
struct Triple {
    unsigned int a, b, c;
};

struct Token {
    void *p;
};

void __cdecl operator delete(void *);

struct Owner {
    void *p;

    ~Owner() { if (p) operator delete(p); }

    void *release() {
        void *value = p;
        p = 0;
        return value;
    }
};

extern Token __cdecl getModel();
extern Token __cdecl getSettings();
extern Owner __cdecl makeOwner(Triple, Triple);

struct Base {
    unsigned int data[5];

    Base(Token, Token, unsigned int, unsigned int, unsigned int);
    virtual ~Base();
};

struct __declspec(novtable) Interface {
    virtual void invoke();
};

struct SignalDesc : Base, Interface {
    void *owner;

    SignalDesc(unsigned int, unsigned int, Triple, Triple, unsigned int);
    virtual ~SignalDesc();
    virtual void invoke();
};

SignalDesc::SignalDesc(unsigned int a, unsigned int b,
                       Triple first, Triple second, unsigned int flags)
    : Base(getSettings(), getModel(), a, b, flags),
      owner(makeOwner(first, second).release())
{
}

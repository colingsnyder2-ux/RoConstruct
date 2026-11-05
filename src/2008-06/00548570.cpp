// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Constructor analog for 00548570: base ctor 00472990, members constructed by
// 0054bec0 (+0xc), 0054a9f0 (+0x18), 0054b2a0 (+0x50), 0054c050 (+0x68), a
// once-only static initializer (flag 00973980, call 00547f60), then zeroed fields.
class Base {
public:
    Base();
    virtual ~Base();
    char data[8];
};

class MemberA { public: MemberA(); ~MemberA(); char data[0x0c]; };
class MemberB { public: MemberB(); ~MemberB(); char data[0x34]; };
class MemberC { public: MemberC(); ~MemberC(); char data[0x18]; };
class MemberD { public: MemberD(); ~MemberD(); char data[0x18]; };

extern bool staticsInitialized;
void initStatics();

class Object : public Base {
public:
    Object();
    virtual ~Object();
    MemberA a;
    MemberB b;
    float scale;
    MemberC c;
    MemberD d;
    int first;
    int second;
};

Object::Object()
{
    if (!staticsInitialized) {
        initStatics();
        staticsInitialized = true;
    }
    scale = 0.0f;
    first = 0;
    second = 0;
}

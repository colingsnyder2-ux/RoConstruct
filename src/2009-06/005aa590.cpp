// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
// Constructor analog for 00548570: base ctor 00472990, members constructed by
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
    second = 6;
    if (!staticsInitialized) {
        initStatics();
        staticsInitialized = true;
    }
    scale = 0.0f;
    first = 0;

}

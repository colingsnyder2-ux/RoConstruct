// from server: 100% by king_originala
typedef unsigned int uint;

void* __cdecl operator new(uint);
extern void* __stdcall getBaseType(uint, uint);
extern void* __cdecl getHolderType();
extern void* __cdecl getMemberType();
extern void* __cdecl makeValue(uint, int);

struct Member {
    void* type;
    void set(void*, void*, void*);
};

struct Base {
    unsigned char reserved0[16];
    Member member;
    unsigned char reserved1[32];

    Base(void*);
    virtual ~Base();
};

struct Callback {
    uint value;

    Callback(uint);
    virtual ~Callback();
};

inline Callback::Callback(uint v) : value(v) {}

struct Holder {
    void* type;
    Callback* callback;

    Holder(uint);
    ~Holder();
};

inline Holder::Holder(uint v)
    : type(getHolderType()), callback(new Callback(v)) {}

struct S : Base {
    uint first;
    uint second;
    Holder holder;

    S(uint, uint, uint, uint, uint, uint);
    virtual ~S();
};

S::S(uint a, uint b, uint c, uint d, uint e, uint f)
    : Base(getBaseType(c, f)), first(a), second(b), holder(e)
{
    member.type = getMemberType();
    member.set(makeValue(d, -1), getHolderType(), &holder);
}

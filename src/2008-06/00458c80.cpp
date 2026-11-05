// from server: 100% by king_originala
struct Base {
    char data[0x374];
    Base();
    virtual ~Base();
};

struct ListenerA {
    char data[0x20];
    ListenerA();
    virtual ~ListenerA();
};

struct ListenerB {
    char data[0x20];
    ListenerB();
    virtual ~ListenerB();
};

struct View : Base, ListenerA, ListenerB {
    char data[0x14];
    View();
    virtual ~View();
};

struct MemberBase {
    MemberBase();
    virtual ~MemberBase();
};

struct Member : MemberBase {
    Member();
    virtual ~Member();
};

inline Member::Member() : MemberBase()
{
}

struct MemberHolder {
    Member member;
};

struct S : View, MemberHolder {
    S();
    virtual ~S();
};

S::S() : View(), MemberHolder()
{
}

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

struct S : Base, ListenerA, ListenerB {
    unsigned int first;
    volatile unsigned int second;
    volatile unsigned int third;
    volatile unsigned int fourth;
    volatile unsigned int fifth;

    S();
    virtual ~S();
};

S::S() : first(0)
{
    second = 0;
    third = 0;
    fourth = 0;
    fifth = 0;
}

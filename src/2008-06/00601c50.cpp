// from server: 100% by king_originala
struct Base
{
    unsigned long words[82];
    Base();
    ~Base();
};

struct Member
{
    unsigned long storage;
    void initialize(int, int);
};

struct S : Base
{
    Member member;
    S(int, int);
};

S::S(int a, int b)
{
    words[0] = 0x0084222c;
    words[4] = 0x0084221c;
    words[5] = 0x00842214;
    words[8] = 0x0084220c;
    words[9] = 0x008421fc;
    words[17] = 0x008421ec;
    words[25] = 0x008421dc;
    words[33] = 0x008421cc;
    words[41] = 0x008421bc;
    words[49] = 0x008421ac;
    words[76] = 0x008421a4;
    member.initialize(a, b);
}

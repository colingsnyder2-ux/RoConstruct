// from server: 100% by king_originala
struct Base
{
    unsigned char storage[32];
    ~Base();
};

struct Member
{
    unsigned long vptr;
    void clear();
};

struct S : Base
{
    Member member;
    ~S();
};

S::~S()
{
    member.vptr = 0x0081378CUL;
    member.clear();
}

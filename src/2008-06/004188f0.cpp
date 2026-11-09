// from server: 100% by king_originala
struct Global
{
    virtual void first();
    virtual void second();
    virtual unsigned long release();
};

extern Global* global;

struct Member
{
    ~Member();
};

struct S
{
    virtual ~S();
    unsigned long references;
    Member member;
};

S::~S()
{
    references = 0xC0000001UL;
    global->release();
}

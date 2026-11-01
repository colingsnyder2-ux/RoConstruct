// from server: 100% by king_originala
struct Module {
    virtual void slot0();
    virtual void slot1();
    virtual void release();
};

extern Module* module;

struct Member {
    ~Member();
};

struct S {
    virtual ~S();
    unsigned long state;
    unsigned long reserved[2];
    Member member;
};

S::~S()
{
    state = 0xC0000001UL;
    module->release();
}

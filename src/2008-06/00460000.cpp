// from server: 100% by king_originala
struct Base {
    virtual ~Base();
    void cleanup();
};

struct S : Base {
    virtual ~S();
};

S::~S()
{
    cleanup();
}

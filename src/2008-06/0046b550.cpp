// from server: 100% by king_originala
struct Base
{
    Base(int value);
    virtual ~Base();
    char data[36];
};

struct Member
{
    Member(const int* first, const int* last);
    ~Member();
    char data[32];
};

struct S : Base
{
    Member member;
    int value;

    S(int value, int initial);
    virtual ~S();
};

S::S(int value, int initial)
    : Base(initial), member(&value + 1, &initial), value(value)
{
}

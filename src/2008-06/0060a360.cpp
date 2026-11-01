// from server: 100% by colin
template<int Tag, int Size>
struct Part {
    virtual void f();
    char padding[Size - 4];
};

template<int Tag>
struct Part<Tag, 4> {
    virtual void f();
};

struct Base :
    Part<0, 16>,
    Part<1, 4>,
    Part<2, 12>,
    Part<3, 4>,
    Part<4, 32>,
    Part<5, 32>,
    Part<6, 32>,
    Part<7, 32>,
    Part<8, 32> {
    ~Base();
};

struct Member {
    virtual void f();
    ~Member();
};

struct S : Base, Part<9, 108>, Member {
    virtual void f();
    ~S();
};

S::~S()
{
}

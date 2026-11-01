// from server: 100% by king_originala
struct B0
{
    virtual void f();
    char padding[12];
};

struct B1
{
    virtual void f();
};

struct B2
{
    virtual void f();
    char padding[8];
};

struct B3
{
    virtual void f();
};

struct B4
{
    virtual void f();
    char padding[28];
};

struct B5
{
    virtual void f();
    char padding[28];
};

struct B6
{
    virtual void f();
    char padding[28];
};

struct B7
{
    virtual void f();
    char padding[28];
};

struct B8
{
    virtual void f();
    char padding[28];
};

struct B9
{
    virtual void f();
    char padding[104];
};

struct B10
{
    virtual void f();
};

struct Base : B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10
{
    ~Base();
};

struct Member
{
    virtual void f();
    ~Member();
};

struct S : Base, Member
{
    virtual void f();
    ~S();
};

S::~S()
{
}

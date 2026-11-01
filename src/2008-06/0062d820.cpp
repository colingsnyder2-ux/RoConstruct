// from server: 100% by king_originala
struct Base
{
    virtual void f();
    unsigned char padding[12];
    ~Base();
};

struct Part4
{
    virtual void f();
};

struct Part12
{
    virtual void f();
    unsigned char padding[8];
};

struct Part32A
{
    virtual void f();
    unsigned char padding[28];
};

struct Part32B
{
    virtual void f();
    unsigned char padding[28];
};

struct Part32C
{
    virtual void f();
    unsigned char padding[28];
};

struct Part32D
{
    virtual void f();
    unsigned char padding[28];
};

struct Part32E
{
    virtual void f();
    unsigned char padding[28];
};

struct Part108
{
    virtual void f();
    unsigned char padding[104];
};

struct Part4B
{
    virtual void f();
};

struct Member
{
    virtual void f();
    ~Member();
};

struct ForceField :
    Base, Part4, Part12, Part4B,
    Part32A, Part32B, Part32C, Part32D, Part32E,
    Part108, Member
{
    virtual void f();
    ~ForceField();
};

ForceField::~ForceField()
{
}

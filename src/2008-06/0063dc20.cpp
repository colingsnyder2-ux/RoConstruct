// from server: 100% by king_originala
struct Part0
{
    virtual ~Part0();
    char padding[12];
};

struct Part10
{
    virtual ~Part10();
};

struct Part14
{
    virtual ~Part14();
    char padding[8];
};

struct Part20
{
    virtual ~Part20();
};

struct Part24
{
    virtual ~Part24();
    char padding[28];
};

struct Part44
{
    virtual ~Part44();
    char padding[28];
};

struct Part64
{
    virtual ~Part64();
    char padding[28];
};

struct Part84
{
    virtual ~Part84();
    char padding[28];
};

struct PartA4
{
    virtual ~PartA4();
    char padding[28];
};

struct PartC4
{
    virtual ~PartC4();
    char padding[104];
};

struct Base : Part0, Part10, Part14, Part20, Part24,
              Part44, Part64, Part84, PartA4, PartC4
{
    virtual ~Base();
};

struct Member130
{
    virtual ~Member130();
    char padding[12];
};

struct Member140
{
    virtual ~Member140();
};

struct S : Base, Member130, Member140
{
    virtual ~S();
};

S::~S()
{
}

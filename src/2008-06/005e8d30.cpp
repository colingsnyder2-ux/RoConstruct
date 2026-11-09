// from server: 100% by king_originala
struct B0 {
    virtual ~B0();
    char padding[0x0c];
};

struct B1 {
    virtual ~B1();
};

struct B2 {
    virtual ~B2();
    char padding[0x08];
};

struct B3 {
    virtual ~B3();
};

struct B4 {
    virtual ~B4();
    char padding[0x1c];
};

struct B5 {
    virtual ~B5();
    char padding[0x1c];
};

struct B6 {
    virtual ~B6();
    char padding[0x1c];
};

struct B7 {
    virtual ~B7();
    char padding[0x1c];
};

struct B8 {
    virtual ~B8();
    char padding[0x1c];
};

struct B9 {
    virtual ~B9();
    char padding[0x68];
};

struct B10 {
    virtual ~B10();
};

struct B11 {
    virtual ~B11();
};

struct Base : B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10, B11 {
    virtual ~Base();
};

struct SleepStage {
    char storage[1];
    ~SleepStage();
};

struct Primitive : Base {
    SleepStage sleepStage;
    virtual ~Primitive();
};

Primitive::~Primitive()
{
}

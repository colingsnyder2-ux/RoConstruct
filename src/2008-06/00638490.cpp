// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern const std::string initialValue;

struct P0 {
    virtual void f();
    unsigned char padding[12];
};

struct P1 {
    virtual void f();
};

struct P2 {
    virtual void f();
    unsigned char padding[8];
};

struct P3 {
    virtual void f();
};

struct P4 {
    virtual void f();
    unsigned char padding[28];
};

struct P5 {
    virtual void f();
    unsigned char padding[28];
};

struct P6 {
    virtual void f();
    unsigned char padding[28];
};

struct P7 {
    virtual void f();
    unsigned char padding[28];
};

struct P8 {
    virtual void f();
    unsigned char padding[28];
};

struct P9 {
    virtual void f();
    unsigned char padding[104];
};

struct Base : P0, P1, P2, P3, P4, P5, P6, P7, P8, P9 {
    Base();
    ~Base();
    void setName(const std::string&);
};

struct S : Base {
    std::string value;
    S();
    virtual void f();
};

S::S() : Base(), value(initialValue)
{
    std::string name("Value");
    setName(name);
}

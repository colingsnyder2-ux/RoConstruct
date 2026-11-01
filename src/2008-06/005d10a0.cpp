// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringConstructor)(String*, const char*);
typedef void (__thiscall *StringDestructor)(String*);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;

struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

__forceinline String::String(const char* text)
{
    stringConstructor(this, text);
}

__forceinline String::~String()
{
    stringDestructor(this);
}

struct P0 {
    virtual void f0();
    unsigned char padding[12];
};
struct P1 {
    virtual void f1();
};
struct P2 {
    virtual void f2();
    unsigned char padding[8];
};
struct P3 {
    virtual void f3();
};
struct P4 {
    virtual void f4();
    unsigned char padding[28];
};
struct P5 {
    virtual void f5();
    unsigned char padding[28];
};
struct P6 {
    virtual void f6();
    unsigned char padding[28];
};
struct P7 {
    virtual void f7();
    unsigned char padding[28];
};
struct P8 {
    virtual void f8();
    unsigned char padding[28];
};
struct P9 {
    virtual void f9();
    unsigned char padding[104];
};
struct P10 {
    virtual void f10();
};

struct Base : P0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10 {
    Base();
    ~Base();
    void setName(const String&);
};

struct S : Base {
    S();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};

S::S()
{
    String name((const char*)0x83a758);
    setName(name);
}

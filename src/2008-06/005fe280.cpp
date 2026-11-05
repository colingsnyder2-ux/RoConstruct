// from server: 100% by king_originala
struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char padding[28];
    Base(void*);
    ~Base();
};

extern void __cdecl initialize(void*, const void*);

struct S : Base {
    char value[8];
    S(void*, const void*);
    ~S();
};

S::S(void* first, const void* second)
    : Base(first)
{
    initialize(value, second);
}

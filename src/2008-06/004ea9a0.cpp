// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Pair
{
    int first;
    int second;
};

struct Base
{
    int value;

    Base();
    ~Base();
};

Base::Base() : value(0)
{
}

struct Member
{
    Member(int, int, int);
    ~Member();
};

struct Object
{
    char storage[40];

    Object();
};

struct S
{
    int first;
    Base second;
    Member member;

    S(const Pair&);
    void set(Object*);
    void finish();
};

S::S(const Pair& value)
    : first(0), second(), member(value.first, value.second, 0)
{
    set(new Object);
    finish();
}

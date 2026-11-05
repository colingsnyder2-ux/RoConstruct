// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    char storage[40];
    Object();
};

struct Counter {
    int value;
    Counter();
    ~Counter();
};

inline Counter::Counter() : value(0) {}

struct Member {
    Member(int, int, int);
    ~Member();
};

struct S {
    int first;
    Counter second;
    Member member;

    S(const int*);
    void attach(Object*);
    void finish();
};

S::S(const int* p)
    : first(0), second(), member(p[0], p[1], 0)
{
    attach(new Object);
    finish();
}

// from server: 100% by colin
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Pair {
    int a;
    int b;
};

struct Object {
    char storage[40];
    Object();
};

struct Count {
    int value;
    Count();
};

inline Count::Count() : value(0) {}

struct Owner {
    int a;
    Count b;
    Owner();
    ~Owner();
    void attach(Object*);
};

inline Owner::Owner() : a(0) {}

struct Member {
    int storage[3];
    Member(int, int, int);
    ~Member();
};

struct S : Owner {
    Member member;
    S(const Pair&);
    void finish();
};

S::S(const Pair& p) : Owner(), member(p.a, p.b, 0)
{
    attach(new Object);
    finish();
}

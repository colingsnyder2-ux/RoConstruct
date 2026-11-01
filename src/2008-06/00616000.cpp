// from server: 100% by king_originala
struct Base
{
    int data[4];

    Base(void*);
    virtual ~Base();
};

struct Unlocked : Base
{
    Unlocked(void* p) : Base(p) {}
    virtual ~Unlocked();
};

struct S
{
    char padding[24];
    void* lock;

    int invoke(int, Unlocked*, int);
    int f(int, int);
};

int S::f(int a, int b)
{
    Unlocked unlocked(lock);
    return invoke(a, &unlocked, b);
}

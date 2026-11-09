// from server: 100% by king_originala
struct Receiver {
    virtual void set(int);
};

struct S {
    char storage[0x1f4];

    void notify(void*);
    void f(void*);
};

void S::f(void* p)
{
    notify(p);
    reinterpret_cast<Receiver*>(storage + 0x1f0)->set(1);
}

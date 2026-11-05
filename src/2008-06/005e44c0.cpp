// from server: 100% by king_originala
extern char event;

struct Target {
    void set(int mode, int value);
};

struct S {
    char padding[0x150];
    Target* target;

    void notify(const void* descriptor);
    void f(int value);
};

void S::f(int value)
{
    target->set(1, value);
    notify(&event);
}

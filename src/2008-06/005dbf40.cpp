// from server: 100% by king_originala
extern bool __cdecl check(void *);

struct S {
    char padding[0x1A8];
    float value;

    void *get();
    void set(float);
    void f(float);
};

#pragma float_control(precise, off, push)
void S::f(float amount)
{
    if (get() && !check(get()))
        set(value - amount);
}
#pragma float_control(pop)

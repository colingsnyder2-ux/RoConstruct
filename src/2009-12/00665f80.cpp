// from server: 42% by atomic.potato
extern "C" void __stdcall sub_77afd0(void *, void *, void *);

struct S
{
    char padding[0xa90];
    int field_a90;
    void f();
};

void S::f()
{
    sub_77afd0((char *)&field_a90 + 12, this, (char *)&field_a90 + 20);
}

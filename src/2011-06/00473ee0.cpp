// from server: 48% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall sub_472580(void *, void *, int);

void S::f()
{
    int value = 0;
    void *object = 0;
    sub_472580((char *)object + 8, &object, value);
}

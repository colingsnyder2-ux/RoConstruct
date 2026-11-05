// from server: 48% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    void f();
};

void S::f()
{
    int value = c ? b + 28 : 0;
    ((void (__thiscall *)(int, int))0x006ab170)(b, value);
}

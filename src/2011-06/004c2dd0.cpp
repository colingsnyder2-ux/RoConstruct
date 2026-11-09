// from server: 35% by atomic.potato
extern "C" void __cdecl sub_419680(void *, void *);
extern "C" void sub_4c0e30(void *);

struct EventDesc
{
    int a;
    int b;
    int c;
    void f(int, int);
};

void EventDesc::f(int x, int y)
{
    a = x;
    b = ((int *)y)[1];
    c = ((int *)y)[2];

    {
        char buffer[28];
        sub_419680(buffer, buffer);
    }

    sub_4c0e30(this);
}

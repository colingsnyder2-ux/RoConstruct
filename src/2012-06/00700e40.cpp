// from server: 83% by atomic.potato
typedef unsigned char byte;

extern "C" void sub_006ff870(void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *first, void *last)
{
    byte *p = (byte *)first;
    byte *end = (byte *)last;
    while (p != end)
    {
        sub_006ff870(p);
        p += 0x24;
    }
}

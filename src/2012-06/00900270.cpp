// from server: 65% by atomic.potato
extern "C" unsigned char __fastcall Function7991C0(void *);

struct S
{
    void *field08;
    float field0c;
    float field10;

    unsigned char f();
};

unsigned char S::f()
{
    if (Function7991C0(field08))
    {
        field10 = 0.0f;
        return 1;
    }
    return 0;
}

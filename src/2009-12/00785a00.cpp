// from server: 74% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int e;
    unsigned char f;
    int g;
};

void __stdcall S_f(S* p, int value)
{
    p->c = -1;
    p->d = -1;
    p->e = 0;
    p->f = 0;
    p->a = 0x9e9a24;
    p->b = 0x9e9a0c;
    p->g = value;
}
